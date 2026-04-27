from __future__ import annotations

from datetime import datetime, timezone
from pathlib import Path
import html
import json
import re
import time

import requests

ROOT = Path(__file__).resolve().parent
PAT = re.compile(r"^(\d+)\.cpp$")

session = requests.Session()
session.headers.update(
    {
        "User-Agent": "Mozilla/5.0 (compatible; BOJ-archiver/1.0)",
        "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8",
    }
)


def clean_text(fragment: str) -> str:
    if not fragment:
        return ""
    fragment = re.sub(r"<br\s*/?>", "\n", fragment, flags=re.I)
    fragment = re.sub(r"</p\s*>", "\n\n", fragment, flags=re.I)
    fragment = re.sub(r"<li[^>]*>", "- ", fragment, flags=re.I)
    fragment = re.sub(r"</li\s*>", "\n", fragment, flags=re.I)
    fragment = re.sub(r"<[^>]+>", "", fragment)
    fragment = html.unescape(fragment)
    fragment = fragment.replace("\r", "").replace("\xa0", " ")
    lines = [line.strip() for line in fragment.split("\n")]
    out = "\n".join(lines)
    out = re.sub(r"[ \t]+", " ", out)
    out = re.sub(r"\n{3,}", "\n\n", out)
    return out.strip()


def pick(pattern: str, text: str, default: str = "") -> str:
    m = re.search(pattern, text, flags=re.S)
    return m.group(1) if m else default


def parse_problem(problem_id: str, page: str) -> dict:
    title = clean_text(pick(r'id="problem_title">(.*?)</span>', page))

    info_row = pick(r'<table class="table" id="problem-info".*?<tbody><tr>(.*?)</tr></tbody>', page)
    meta = {}
    if info_row:
        vals = [clean_text(x) for x in re.findall(r"<td[^>]*>(.*?)</td>", info_row, flags=re.S)]
        keys = ["time_limit", "memory_limit", "submitted", "accepted", "solved", "accept_rate"]
        meta = {k: v for k, v in zip(keys, vals)}

    sections = {
        "description": clean_text(pick(r'id="problem_description"[^>]*>(.*?)</section>', page)),
        "input": clean_text(pick(r'id="problem_input"[^>]*>(.*?)</section>', page)),
        "output": clean_text(pick(r'id="problem_output"[^>]*>(.*?)</section>', page)),
    }

    sample_inputs = {
        int(i): clean_text(v)
        for i, v in re.findall(r'id="sample-input-(\d+)"[^>]*>(.*?)</pre>', page, flags=re.S)
    }
    sample_outputs = {
        int(i): clean_text(v)
        for i, v in re.findall(r'id="sample-output-(\d+)"[^>]*>(.*?)</pre>', page, flags=re.S)
    }

    samples = []
    for idx in sorted(set(sample_inputs) | set(sample_outputs)):
        samples.append(
            {
                "index": idx,
                "input": sample_inputs.get(idx, ""),
                "output": sample_outputs.get(idx, ""),
            }
        )

    source_section = pick(r'<section id="source"[^>]*>(.*?)</section>', page)
    source = [clean_text(x) for x in re.findall(r"<li[^>]*>(.*?)</li>", source_section, flags=re.S)] if source_section else []

    return {
        "schema_version": "v0-preview",
        "source_url": f"https://www.acmicpc.net/problem/{problem_id}",
        "problem_id": int(problem_id),
        "title": title,
        "meta": meta,
        "sections": sections,
        "samples": samples,
        "source": source,
        "fetched_at_utc": datetime.now(timezone.utc).isoformat(),
    }


def fetch_problem(problem_id: str) -> dict:
    url = f"https://www.acmicpc.net/problem/{problem_id}"
    last_err = None
    for attempt in range(1, 4):
        try:
            r = session.get(url, timeout=25)
            if r.status_code == 404:
                raise RuntimeError("HTTP 404")
            r.raise_for_status()
            if 'id="problem_title"' not in r.text:
                raise RuntimeError("unexpected page format")
            return parse_problem(problem_id, r.text)
        except Exception as e:
            last_err = e
            if attempt < 3:
                time.sleep(0.7 * attempt)

    return {
        "schema_version": "v0-preview",
        "source_url": url,
        "problem_id": int(problem_id),
        "error": str(last_err),
        "fetched_at_utc": datetime.now(timezone.utc).isoformat(),
    }


def build_targets() -> list[tuple[str, Path]]:
    targets: list[tuple[str, Path]] = []
    for solutions_dir in sorted([p for p in ROOT.rglob("solutions") if p.is_dir()]):
        ids = sorted(
            {
                PAT.match(f.name).group(1)
                for f in solutions_dir.iterdir()
                if f.is_file() and PAT.match(f.name)
            }
        )
        if not ids:
            continue

        problems_dir = solutions_dir.parent / "problems"
        problems_dir.mkdir(parents=True, exist_ok=True)
        for pid in ids:
            targets.append((pid, problems_dir / f"{pid}.json"))
    return targets


def main() -> None:
    all_targets = build_targets()
    missing = [(pid, out) for pid, out in all_targets if not out.exists()]

    print(f"targets_total={len(all_targets)}")
    print(f"targets_missing={len(missing)}")

    cache: dict[str, dict] = {}
    failures: list[dict] = []

    for i, (pid, out_path) in enumerate(missing, start=1):
        if pid not in cache:
            data = fetch_problem(pid)
            cache[pid] = data
            if "error" in data:
                failures.append({"problem_id": pid, "error": data["error"]})
            time.sleep(0.05)

        out_path.write_text(json.dumps(cache[pid], ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

        if i % 50 == 0 or i == len(missing):
            print(f"progress={i}/{len(missing)} unique_fetched={len(cache)} failures={len(failures)}")

    report = {
        "root": str(ROOT),
        "target_json_files": len(all_targets),
        "missing_processed_now": len(missing),
        "unique_problem_ids_fetched_now": len(cache),
        "failures_now": failures,
        "generated_at_utc": datetime.now(timezone.utc).isoformat(),
    }

    report_path = ROOT / "tmp_boj_bulk_parse_report.json"
    report_path.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    print("done")
    print(f"report={report_path}")


if __name__ == "__main__":
    main()
