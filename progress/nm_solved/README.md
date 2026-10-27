# NM closer handoffs

One folder per solved function, named exactly as the symbol (e.g. `func_00164238/`):

- `solved.c`: the complete function as real C, plus any typedefs/externs it needs.
  The only function it may define besides the target is a `static` helper. Any other
  non-static definition is rejected, because it would duplicate a symbol at link time.
  No `#ifdef NON_MATCHING` guard and no `INCLUDE_ASM`. A section attribute is optional.
  A handoff for a function whose registered tu already defines it in C is rejected: the NM block
  it came from is stale.
  The NM source can be a `#ifdef NON_MATCHING` file or an older `*_nm*.c` batch file that lists
  bare `INCLUDE_ASM` lines; that line is cut and the file is deleted once it holds no more.
  The new file is named `sa_<addr>.c`, the address coming from the NM file name, a `_XXXXXXXX`
  symbol suffix, the carved vaddr, or `config/symbol_addrs.txt`, in that order.
- `meta.json` (optional):

  ```json
  {"compiler": "sn-2.95.3-136", "as": "sn",
   "c_flags_add": ["-f=-fno-gcse"], "c_flags_drop": ["-f=-freorder-blocks"],
   "call_loop_pad": true}
  ```

  A function whose switch compiles to a jump table also lists the retail table symbols, one per
  switch in the order cc1 emits them (the same `extern_jtbl` key the build uses; find them with
  `python3 scripts/sa/jtbl_syms.py <function>`):

  ```json
  {"compiler": "sn-2.95.3-136", "extern_jtbl": ["D_0041B8A0", "D_0041B8C0", "D_0041B8E0"]}
  ```

  Registration then lists the table entries that jump into the function in
  `config/jtbl_extern_words.txt`, so they stay raw retail words once the function's labels leave
  the monolith; the full build that follows checks the link.

  - `compiler` is required when the NM file has no `(compiler…)` in its first-line header. It must be a
    compiler that some unit in compile_config.json already uses. New compilers are never added.
  - `as`, `c_flags_add`, `c_flags_drop`, `fp_hazard_rules` (e.g. `"mtc1"`), `call_loop_pad` (bool;
    the existing compile_config.json unit key) and `extern_jtbl` (list of symbols) are per-file settings. They're allowed only for standalone
    drafts (`drafts/cod/<addr>.c`), which become a new `src/cod/<addr>.c` unit. Flags must be in compile.py's per-file
    lists (`SUPPORTED_C_FLAG_ADDS`, `SUPPORTED_C_FLAG_DROPS`); anything else is rejected. Without
    meta.json these are read from the NM header (`as=sn`, `-O0`, `drop-reorder`, `fp_hazard_rules mtc1`,
    `call_loop_pad`).
  - Other compiler-wrapper arguments (`--wrap-arg=...`) are not accepted. The solved C must match with
    the settings above alone. `call_loop_pad: true` is verified as `--wrap-arg=--call-loop-pad`, which
    is exactly what the build passes for units with that key.
  - For functions inside an already-registered TU, the unit's own settings (compiler included) are used.
    A meta.json that asks for different ones is rejected, because registered units are never changed.
- `header_changes.md` (optional): declaration changes in shared headers that the solved function
  needs. Use one section per change, with the exact text to replace and its replacement:

  ````markdown
  ## include/godhand/cCoreSave.h
  ### old
  ```c
  void cCoreSave_addGold(cCoreSave *self, int amount, int clearLog);
  ```
  ### new
  ```c
  void cCoreSave_addGold(cCoreSave *self, int gold, int clearLog);
  ```
  ````

  The old text must appear exactly once in that header (include/ or src/). For a field inside a
  struct, the whole struct counts as the changed declaration.

The main agent checks this folder once per batch with `scripts/sa/nm_handoff.py`:

1. Header changes are applied first, and the solved C is checked with match_check (instruction words
   and relocation targets).
2. It is registered. A handoff that changed a header is then verified with one full build: the ELF and
   r207.rel must stay identical to retail. Handoffs without header changes share one full build at the
   end of the run.
3. Every file is journaled before its first write. A rejected handoff is rolled back to its own
   snapshot; an error, Ctrl-C or SIGTERM rolls the whole run back, and a run that was killed outright
   is rolled back when the next one starts. Nothing moves and nothing is logged until the final
   build passes.

Processed folders move to `done/`. Failures move to `rejected/` with the reason in `REJECTED.txt`.
`handoff_log.tsv` has one row per handoff.

- nm_handoff.py holds a lock (build/sa/handoff/.lock) for the whole run. "another nm_handoff run is in progress" means the other agent is applying handoffs; wait and run it again. Two runs at once used to undo each other (batch 187).
