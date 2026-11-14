#!/usr/bin/env bash
# Prepare the Linux environment used by the original i386 PS2 compiler, then
# run the requested command. The caller has already sourced the dev environment.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

if [[ "$(uname -m)" == "aarch64" ]]; then
    SYSROOT="$ROOT/.i386-sysroot"
    LIBDIR="$SYSROOT/lib/i386-linux-gnu"
    if [[ ! -f "$LIBDIR/libc.so.6" || ! -f "$LIBDIR/ld-linux.so.2" ]]; then
        echo "container_env: missing i386 runtime under $SYSROOT" >&2
        exit 1
    fi
    export QEMU_LD_PREFIX="$SYSROOT"
    # qemu-i386's default CPU model (max) misruns ee-as 2.10 here: the first
    # `lw/sw rt,sym(base)` macro in a file gets its lui encoded as the final
    # op (StreamReadBlock, 0x34EAC4). Native x86 and these older models emit
    # the lui. Both qemu routes read it: the flake's wrappers (cc1, cpp0) and
    # the kernel's binfmt handler (ee-as).
    export QEMU_CPU="${QEMU_CPU:-pentium3}"
    # The persistent container keeps /lib. Copy the i386 loader once so later
    # calls, including parallel scratch compiles, do not rewrite it.
    if [[ ! -f /lib/i386-linux-gnu/libc.so.6 || ! -e /lib/ld-linux.so.2 ]]; then
        mkdir -p /lib/i386-linux-gnu
        cp -a "$LIBDIR/." /lib/i386-linux-gnu/
        ln -sfn i386-linux-gnu/ld-linux.so.2 /lib/ld-linux.so.2
    fi
fi

if [[ $# -eq 0 ]]; then
    exec bash
fi
exec "$@"
