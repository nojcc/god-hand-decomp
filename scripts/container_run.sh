#!/usr/bin/env bash
# Run a project command in the reproducible Linux/Nix environment required by
# the original PS2 compiler.
#
# One named container stays up. The dev environment is resolved once with
# `nix print-dev-env` and reused until flake.nix, flake.lock, or patches/ee-as
# changes. Arguments, the command's own stdout/stderr, and its exit status
# are passed through.
#
# compile.py (full link, --setup, --clean, --reseed-*, and --single-file)
# takes an exclusive host lock. Scratch compiles and the permuter do not:
# they must not call compile.py.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
IMAGE="${GODHAND_NIX_IMAGE:-nixos/nix}"
VOLUME="${GODHAND_NIX_VOLUME:-godhand-nix-store}"
NAME="${GODHAND_NIX_CONTAINER:-godhand-nix}"

if ! command -v docker >/dev/null 2>&1; then
    echo "container_run: docker is required" >&2
    exit 1
fi

mkdir -p "$ROOT/build"

dev_env_hash() {
    {
        shasum -a 256 "$ROOT/flake.nix" "$ROOT/flake.lock"
        find "$ROOT/patches/ee-as" -type f -print | LC_ALL=C sort | while IFS= read -r f; do
            shasum -a 256 "$f"
        done
    } | shasum -a 256 | awk '{print $1}'
}

DEVENV_HASH="$(dev_env_hash)"

needs_build_lock() {
    python3 - "$@" << 'PY'
import re, sys
text = " ".join(sys.argv[1:])
sys.exit(0 if re.search(r"(^|[\s/])compile\.py($|[\s])", text) else 1)
PY
}

ensure_container() {
    GODHAND_NAME="$NAME" GODHAND_IMAGE="$IMAGE" GODHAND_VOLUME="$VOLUME" GODHAND_ROOT="$ROOT" \
        python3 - << 'PY'
import os, subprocess, sys

name = os.environ["GODHAND_NAME"]
image = os.environ["GODHAND_IMAGE"]
volume = os.environ["GODHAND_VOLUME"]
root = os.environ["GODHAND_ROOT"]

def inspect(fmt: str) -> str:
    result = subprocess.run(
        ["docker", "inspect", "-f", fmt, name],
        capture_output=True, text=True,
    )
    if result.returncode != 0:
        return ""
    return result.stdout.strip()

running = inspect("{{.State.Running}}") == "true"
mounted = inspect('{{range .Mounts}}{{if eq .Destination "/src"}}{{.Source}}{{end}}{{end}}')
if running and mounted == root:
    sys.exit(0)
subprocess.run(
    ["docker", "rm", "-f", name],
    stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
)
subprocess.check_call(
    [
        "docker", "run", "-d", "--name", name,
        "--platform", "linux/arm64",
        "-v", f"{volume}:/nix",
        "-v", f"{root}:/src",
        "-w", "/src",
        image,
        "sleep", "infinity",
    ],
    stdout=subprocess.DEVNULL,
)
PY
}

run_locked() {
    python3 - "$1" "${@:2}" << 'PY'
import fcntl, os, subprocess, sys
fd = os.open(sys.argv[1], os.O_CREAT | os.O_RDWR, 0o644)
fcntl.flock(fd, fcntl.LOCK_EX)
raise SystemExit(subprocess.call(sys.argv[2:]))
PY
}

export -f ensure_container
export NAME IMAGE VOLUME ROOT
run_locked "$ROOT/build/container-start.lock" bash -c 'ensure_container'

# A host-side skip must reach compile.py. docker exec does not forward
# the environment on its own, and a matching build refuses this variable.
if [ -n "${GODHAND_SKIP_ELF_VERIFY:-}" ]; then
    DOCKER_EXEC=(docker exec -e "GODHAND_SKIP_ELF_VERIFY=${GODHAND_SKIP_ELF_VERIFY}")
else
    DOCKER_EXEC=(docker exec)
fi

if needs_build_lock "$@"; then
    run_locked "$ROOT/build/container-build.lock" \
        "${DOCKER_EXEC[@]}" -w /src "$NAME" \
        bash scripts/container_bootstrap.sh "$DEVENV_HASH" "$@"
else
    "${DOCKER_EXEC[@]}" -w /src "$NAME" \
        bash scripts/container_bootstrap.sh "$DEVENV_HASH" "$@"
fi
