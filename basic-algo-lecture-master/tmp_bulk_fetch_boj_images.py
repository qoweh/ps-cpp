from __future__ import annotations

from pathlib import Path
from urllib.parse import urljoin, urlparse
import json
import re
import time

import requests

ROOT = Path(__file__).resolve().parent
JSON_GLOB = "**/problems/*.json"

SECTION_IDS = [
    "problem_description",
    "problem_input",
    "problem_output",
    "problem_hint",
    "problem_source",
]

KNOWN_EXTS = {
    ".png",
    ".jpg",
    ".jpeg",
    ".gif",
    ".bmp",
    ".svg",
    ".webp",
    ".tif",
    ".tiff",
}

CTYPE_TO_EXT = {
    "image/png": ".png",
    "image/jpeg": ".jpg",
    "image/jpg": ".jpg",
    "image/gif": ".gif",
    "image/bmp": ".bmp",
    "image/webp": ".webp",
    "image/svg+xml": ".svg",
    "image/tiff": ".tiff",
    "image/x-icon": ".ico",
}

IMG_TAG_RE = re.compile(r"<img\\b[^>]*>", flags=re.I)
SRC_RE = re.compile(r"\\bsrc\\s*=\\s*['\"]([^'\"]+)['\"]", flags=re.I)
ALT_RE = re.compile(r"\\balt\\s*=\\s*['\"]([^'\"]*)['\"]", flags=re.I)
A_TAG_RE = re.compile(r"<a\\b[^>]*>", flags=re.I)
HREF_RE = re.compile(r"\\bhref\\s*=\\s*['\"]([^'\"]+)['\"]", flags=re.I)
URL_LIKE_RE = re.compile(r"(https?://[^\s'\"<>]+|/upload/[^\s'\"<>]+)", flags=re.I)


session = requests.Session()
session.headers.update(
    {
        "User-Agent": "Mozilla/5.0 (compatible; BOJ-image-archiver/1.0)",
        "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8",
    }
)


def extract_section_html(page: str, section_id: str) -> str:
    pattern = rf'id="{re.escape(section_id)}"[^>]*>(.*?)</div>\\s*</section>'
    m = re.search(pattern, page, flags=re.S)
    if m:
        return m.group(1)

    anchor = f'id="{section_id}"'
    start = page.find(anchor)
    if start == -1:
        return ""
    gt = page.find(">", start)
    if gt == -1:
        return ""
    end = page.find("</section>", gt)
    if end == -1:
        return page[gt + 1 :]
    return page[gt + 1 : end]


def infer_extension(img_url: str, content_type: str) -> str:
    path = urlparse(img_url).path
    suffix = Path(path).suffix.lower()
    if suffix in KNOWN_EXTS:
        if suffix == ".jpeg":
            return ".jpg"
        return suffix

    if content_type:
        ctype = content_type.split(";")[0].strip().lower()
        ext = CTYPE_TO_EXT.get(ctype)
        if ext:
            return ext

    return ".img"


def fetch_problem_page(url: str) -> str:
    last_error: Exception | None = None
    for attempt in range(1, 4):
        try:
            res = session.get(url, timeout=25)
            res.raise_for_status()
            return res.text
        except Exception as e:  # noqa: BLE001
            last_error = e
            if attempt < 3:
                time.sleep(0.6 * attempt)
    raise RuntimeError(str(last_error))


def parse_images_from_problem_page(page_url: str, page: str) -> list[dict]:
    found: list[dict] = []
    seen_urls: set[str] = set()

    for sid in SECTION_IDS:
        chunk = extract_section_html(page, sid)
        if not chunk:
            continue

        for tag in IMG_TAG_RE.findall(chunk):
            src_m = SRC_RE.search(tag)
            if not src_m:
                continue

            raw_src = src_m.group(1).strip()
            abs_url = urljoin(page_url, raw_src)
            if abs_url in seen_urls:
                continue
            seen_urls.add(abs_url)

            alt = ""
            alt_m = ALT_RE.search(tag)
            if alt_m:
                alt = alt_m.group(1).strip()

            found.append(
                {
                    "section": sid,
                    "source_url": abs_url,
                    "alt": alt,
                }
            )

        # Some statements include image links rather than inline <img> tags.
        for tag in A_TAG_RE.findall(chunk):
            href_m = HREF_RE.search(tag)
            if not href_m:
                continue
            raw_href = href_m.group(1).strip()
            abs_url = urljoin(page_url, raw_href)
            if abs_url in seen_urls:
                continue

            lower_url = abs_url.lower()
            has_image_ext = any(lower_url.endswith(ext) for ext in KNOWN_EXTS)
            if not has_image_ext and "/upload/" not in lower_url:
                continue

            seen_urls.add(abs_url)
            found.append(
                {
                    "section": sid,
                    "source_url": abs_url,
                    "alt": "",
                }
            )

        # Last fallback for raw image URLs embedded in text/HTML.
        for raw_url in URL_LIKE_RE.findall(chunk):
            abs_url = urljoin(page_url, raw_url.strip())
            if abs_url in seen_urls:
                continue

            lower_url = abs_url.lower()
            has_image_ext = any(ext in lower_url for ext in KNOWN_EXTS)
            if not has_image_ext and "/upload/" not in lower_url:
                continue

            seen_urls.add(abs_url)
            found.append(
                {
                    "section": sid,
                    "source_url": abs_url,
                    "alt": "",
                }
            )

    return found


def download_image(url: str) -> tuple[bytes, str, str]:
    last_error: Exception | None = None
    for attempt in range(1, 4):
        try:
            res = session.get(url, timeout=30)
            res.raise_for_status()
            content_type = res.headers.get("Content-Type", "")
            ext = infer_extension(url, content_type)
            return res.content, content_type, ext
        except Exception as e:  # noqa: BLE001
            last_error = e
            if attempt < 3:
                time.sleep(0.6 * attempt)
    raise RuntimeError(str(last_error))


def load_targets() -> list[tuple[str, str, Path]]:
    targets: list[tuple[str, str, Path]] = []
    for p in sorted(ROOT.glob(JSON_GLOB)):
        try:
            data = json.loads(p.read_text(encoding="utf-8"))
        except Exception:  # noqa: BLE001
            continue

        pid = str(data.get("problem_id") or p.stem)
        source_url = data.get("source_url") or f"https://www.acmicpc.net/problem/{pid}"
        targets.append((pid, source_url, p))

    return targets


def main() -> None:
    targets = load_targets()
    grouped: dict[str, dict] = {}
    for pid, source_url, path in targets:
        if pid not in grouped:
            grouped[pid] = {"source_url": source_url, "paths": []}
        grouped[pid]["paths"].append(path)

    print(f"json_targets={len(targets)}")
    print(f"unique_problem_ids={len(grouped)}")

    page_cache: dict[str, dict] = {}
    failures: list[dict] = []
    with_images = 0

    for idx, (pid, meta) in enumerate(sorted(grouped.items(), key=lambda x: int(x[0])), start=1):
        source_url: str = meta["source_url"]
        json_paths: list[Path] = meta["paths"]

        try:
            page = fetch_problem_page(source_url)
            parsed_images = parse_images_from_problem_page(source_url, page)
        except Exception as e:  # noqa: BLE001
            parsed_images = []
            failures.append({"problem_id": int(pid), "stage": "fetch_page", "error": str(e)})

        downloaded: list[dict] = []
        for img in parsed_images:
            try:
                content, ctype, ext = download_image(img["source_url"])
                downloaded.append(
                    {
                        "section": img["section"],
                        "source_url": img["source_url"],
                        "alt": img["alt"],
                        "content_type": ctype,
                        "ext": ext,
                        "content": content,
                    }
                )
            except Exception as e:  # noqa: BLE001
                failures.append(
                    {
                        "problem_id": int(pid),
                        "stage": "download_image",
                        "image_url": img["source_url"],
                        "error": str(e),
                    }
                )

        if downloaded:
            with_images += 1

        page_cache[pid] = {"images": downloaded}

        for path in json_paths:
            try:
                data = json.loads(path.read_text(encoding="utf-8"))
            except Exception:  # noqa: BLE001
                failures.append(
                    {
                        "problem_id": int(pid),
                        "stage": "read_json",
                        "path": str(path),
                        "error": "invalid json",
                    }
                )
                continue

            image_meta = []
            out_dir = path.parent
            for i, img in enumerate(downloaded, start=1):
                filename = f"{pid}-{i}{img['ext']}"
                out_path = out_dir / filename
                out_path.write_bytes(img["content"])
                image_meta.append(
                    {
                        "index": i,
                        "file": filename,
                        "source_url": img["source_url"],
                        "section": img["section"],
                        "content_type": img["content_type"],
                        "alt": img["alt"],
                    }
                )

            data["images"] = image_meta
            path.write_text(json.dumps(data, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

        if idx % 50 == 0 or idx == len(grouped):
            print(
                f"progress={idx}/{len(grouped)} problems_with_images={with_images} failures={len(failures)}"
            )

    report = {
        "json_targets": len(targets),
        "unique_problem_ids": len(grouped),
        "problems_with_images": with_images,
        "failures": failures,
    }

    report_path = ROOT / "tmp_boj_image_fetch_report.json"
    report_path.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print("done")
    print(f"report={report_path}")


if __name__ == "__main__":
    main()
