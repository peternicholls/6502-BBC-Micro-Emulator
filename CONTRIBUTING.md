# Contributing and Repository Structure

This repository is the C++ core wrapper used by the BBC Model B app. It is designed to keep the 6502/BBC Micro emulator a clean, reusable C++ project while exposing a small C ABI for consumers (e.g., Swift).

Recommended layout (no Swift code here):

- `include/` — Public C API headers (e.g., `core_api.h`) and `module.modulemap` for consumers
- `src/` — Wrapper sources and integration glue
- `src/6502Emulator/` — The emulator repository as a Git submodule (your fork or the original upstream)
- `BeebCore.xcodeproj/` — Xcode static library target for local iteration (optional if you use CMake)
- `.gitignore` — Exclude `Build/`, `DerivedData/`, and user/workspace files

Why a nested submodule?

- Keeps the emulator as its own independent repo (clean history, upstream-friendly PRs)
- Avoids copying sources or using symlinks (symlinks complicate Windows builds and packaging)
- Lets this wrapper add build scaffolding and C ABI without polluting the emulator repo

Registering the submodule (run inside this repo):

```bash
# If `src/6502Emulator` already contains a clone, capture its remote
cd src/6502Emulator
origin_url=$(git remote get-url origin)
cd -

# Replace ad-hoc nested clone with a proper submodule entry
git rm -r --cached src/6502Emulator || true
rm -rf src/6502Emulator/.git

git submodule add "$origin_url" src/6502Emulator

git commit -m "chore: register 6502Emulator as a submodule under src/"
```

Working on the emulator

- Make changes inside `src/6502Emulator` on a feature branch
- Push to your fork and open a PR against the upstream
- Update this wrapper to the merged commit and bump the submodule pointer

Working on the wrapper

- Add or adjust C API in `include/core_api.h`
- Implement the wrappers in `src/` (call into emulator code)
- Update `BeebCore.xcodeproj` (or CMake) to build the static library

Coding constraints

- Keep the ABI surface C-only (`extern "C"` in C++ source if needed)
- Avoid leaking C++ types or STL across the API boundary
- Use hidden visibility by default and export only ABI symbols

CI/testing

- Prefer unit tests in a separate test target that links the static lib
- Keep emulator-specific tests in the emulator repo (upstream suite)
