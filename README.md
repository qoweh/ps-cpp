# ps-cpp

Personal C++ problem solving workspace consolidating various algorithm practice folders (arrays, lists, stacks, queues, BFS, etc.).

Originally included a nested repository `basic-algo-lecture`; its git metadata was removed to unify everything under this single repo. A safety copy exists locally at `basic-algo-lecture-backup/` (ignored) in case original history is ever needed.

## Layout
- `0x03 ...` etc: Practice by topic / chapter
- `basic-algo-lecture/`: Source files from lecture materials (now part of this repo)
- `bits/`: Convenience headers (e.g. `stdc++.h`)

## Build quick example
```bash
g++ -std=c++17 -O2 -Wall 0x05 스택/10828.cpp -o 10828
./10828 < input.txt
```

## Notes
Private repository for local study; not intended for redistribution.
