# Matching progress

## Batch 35 — 2026-10-14T21:03:58Z

- **% fully linked:** 44.7959% (1270584 / 2836384 code bytes)
- **% decompiled:** 45.1129% (1279576 / 2836384); 8992 B NON_MATCHING (from NM sources; `score_nm.sh` failed on missing build-nm object)
- **Data %:** 83.0150%
- **Since last entry:** +2412 B, +25 functions; 1378 B/h over 1.75 h (batches 26–35)
- **Permuter:** 70 queued; 2 promoted to matching since last entry (`func_00374CB8` / `func_00375AB0`)
- **Notes:** Incremental carve live (typical reseed ~10–17 units rebuilt). Cold at batch 35: both retail hashes OK. `batch_log` now rejects <0.25s finish.

## Batch 45 — 2026-10-14T22:13:17Z

- **% fully linked:** 44.9319% (1274440 / 2836384 code bytes)
- **% decompiled:** 45.3449% (1286156 / 2836384); 11716 B NON_MATCHING (NM source sizes; score_nm deferred)
- **Data %:** 83.0150%
- **Since last entry:** +3856 B, +31 functions; 1542 B/h over 2.50 h (batches 36–45)
- **Permuter:** 91 queued; 0 promoted since last entry (active: `func_002D4248`)
- **Notes:** Per-TU hash gates after batch38 incident. Batch38 kept 2/4; batch39 kept 1/3. Batches 40–45 all hash-OK.

## Batch 50 — 2026-10-14T23:47:09Z

- **% fully linked:** 44.9933% (1276184 / 2836384 code bytes)
- **% decompiled:** 44.9933% (1276184 / 2836384); 0 B NON_MATCHING
- **Data %:** 83.0150%
- **Since last entry:** +1744 B, +11 functions; 1118 B/h over 1.56 h
- **Permuter:** 0 queued; 1 promoted since last entry

- **Notes (halt):** Stopped matching. Permuters killed; bests kept (`func_00170338` best=715, `func_002BEB00` best≈50 base, `func_002D4248` no score artifact). `score_nm.sh` did **not** finish a NON_MATCHING rebuild (log stopped at seed step); `report.nm.json` fuzzy equals matching (0 B NON_MATCHING credited) — decompiled % above is **not** a trusted NM measurement. batch51 removed from `compile_units` (never linked). Retail ELF+overlay hashes OK. No compile/reseed/permuter running.
- **Unfinished:** see halt inventory in chat / below.

### Unfinished at halt
- Scratch-matched, **not registered:** `func_00144B50` (184; `build/b50_try*.c`), `func_002E8318`+`func_001ED3C0` (`src/cod/phase_a_sn_batch51.c`), `func_0037FC28`+`func_00313030` (`src/cod/phase_a_sn_batch52.c`), `func_001B5430` (180; `build/b53_try*.c`).
- **NON_MATCHING files since Batch 45:** `src/cod/batch46_nm.c` … `batch52_nm.c` (plus touch on `batch27_nm.c` for `001B8030` extract).
- **score_nm:** fix/re-run needed for measured decompiled % (`scripts/score_nm.sh` seed+NM-rebuild path incomplete this session).

## Batch 51 — 2026-10-15T00:20:53Z (integrator setup)

- **% fully linked:** 45.0254% (1277092 / 2836384 code bytes)
- **% decompiled:** score_nm rebuild in progress (prior summary stale); linked 45.0254%
- **Data %:** 83.0150%
- **Since last entry:** +908 B, +5 functions; 1615 B/h over 0.56 h
- **Permuter:** daemon on (2×-j3); 0 promotions this entry
- **Integrated:** `func_001B5430`, `func_002E8318`, `func_001ED3C0`, `func_0037FC28`, `func_00313030` (reloc+hash OK). `func_00144B50` scratch PASS / link-false → `batch50_nm.c`.
- **Workers:** 8 launched on slices (~2010 funcs / ~1.49 MB). Inbox → `integrate_inbox.py`. 
- **Hashes:** ELF `1742f95b…` OK · overlay `ea599323…` OK

## Halt — 2026-10-15T03:43:00Z

- **% fully linked:** 45.0349% (1277364 / 2836384 code bytes)
- **% decompiled:** score_nm not run at halt; linked figure above. ~1000 inbox_nm_*.c NON_MATCHING files on disk (not retail-linked)
- **Data %:** 83.0150%
- **Since Batch 51:** +272 B, functions now 8314
- **Permuter:** daemon STOPPED; bests kept under progress/permuter/; queue notes preserved
- **Inbox drain:** near-misses filed under NON_MATCHING + permuter queue (no reseed). Large asm-wrap match batch failed link (empty ELF) → demoted to NM without carve. Final small batch kept 2 matches (`func_003062A8`, `func_00306330`) with retail hashes OK.
- **Workers:** halted; no relaunches. Containers stopped.
- **Hashes:** ELF `OK` · overlay `OK`
- **Stopped:** integrate_inbox, integrator_loop, permuter_daemon, all worker batches. Safe stop.


## Checkpoint (single-agent, batches 1-10) — 2026-10-16T15:45:00Z

- **% fully linked:** 45.3916% (1287480 / 2836384 code bytes); 8371 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (Halt, 2026-10-15T03:43Z):** +10116 B, +57 functions
- **Bytes per hour:** ~7700 B/h (10116 B over 1.31 h, first logged function 14:26Z to this checkpoint; setup time not counted)
- **Areas worked:** clone clusters (exhausted), 0035e8.c, CustomID panels 0x1DE4F8 / 0x1ECE30, cIDBase 0x2ABCE8, 0x30D190 (exhausted: 1 hard-tail, 2 NM, 1 jump table left), 0x31A300 (done), 0x31C350 (done; C5C0 NM, VU0 copy macro), ADX 0x324C90 (done), Sofdec 0x347008 (done), Sofdec 0x34F7A0 (F8D0 NM). Next area: 0x3525F0.
- **Headers:** pending_headers.md moved into include/godhand/ (new: adxm.h, mwsfd.h, gameWork.h, player.h, sfxlib.h, flagList.h, eh.h, cIDBaseAnim.h, CustomIDPanel.h, cMessDrawFontCode.h, cDamageVec.h); local duplicates removed; every affected TU re-checked with match_check.
- **Cold build:** PASSED (compile.py --cold, 252 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **Permuter:** single run at a time; found func_0031A538 and pointed at func_00324D18 (both real fixes were int-returning callee prototypes). func_001DEB08 run ended at 290. Idle at checkpoint.

## Checkpoint (single-agent, batches 11-20) — 2026-10-16T17:27:00Z

- **% fully linked:** 45.5597% (1292248 / 2836384 code bytes); 8392 / 10573 functions
- **Data %:** 83.0150% (unchanged; no data work this stretch)
- **Since last entry (checkpoint batches 1-10, 15:45Z):** +4768 B, +21 functions
- **Bytes per hour:** ~2800 B/h (4768 B over 1.70 h)
- **Areas worked:** Sofdec 0x3525F0 / 0x353928 (done), cObj 0x14E5D0, pack 0x152340, texture/packet 0x151688..0x155AE8 (mostly blocked on SN-assembler dli expansion, NM), 0x1573C8 (NM), Motion 0x1594A0 (done), 0x1ABB58 (done), 0x1B19E0 (done), blackjack 0x1D4720 (done), poker 0x1DBEB0 (3 matched, 3 NM). Current area: next from areas.py (0x1E8EB8).
- **Headers:** pending_headers.md moved into include/godhand/ (new: sftim.h, pack.h, tim2.h, mdlPkt.h, motion.h, unkObj.h; extended: BlackJack.h card suit/rank/unk104, Poker.h straight table, cDataManager.h isLoaded/resetKind + instances, cObj.h cObj_setId, player.h PlSub). Local duplicates removed; every affected registered TU re-checked with match_check, NM files compile-checked. `int Rnd(void)` kept local (other TUs declare it unsigned).
- **Cold build:** PASSED (compile.py --cold, 260 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **Flagged matches:** func_001D4720 / func_001D47E8 need `score++` wrapped in `do { } while (0)` (permuter hint; changes register priority). Reported for review.
- **Permuter:** single runs; func_00155AE8 (best 335, junk-only, rejected), func_001D4720 (found the do/while(0) form). Idle at checkpoint.

## Checkpoint (single-agent, batches 21-30) — 2026-10-16T18:43:00Z

- **% fully linked:** 45.7198% (1296788 / 2836384 code bytes); 8420 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 11-20, 17:27Z):** +4540 B, +28 functions
- **Bytes per hour:** ~3580 B/h (4540 B over 1.27 h)
- **Areas worked:** 0x1E8EB8, Coliseum 0x1F08B8, CustomID 0x1F32A0, cActionButton 0x1F70C8, cMessage 0x2AEE40 / 0x2B1090 / 0x2B4228, 0x2C0B38 (NM), cSnd 0x2CA558 / 0x2CA910 / 0x2D0B88 (NM), 0x2FA350 (NM: cvt.w.s), espSys 0x306030 / 0x307060, stage set data 0x31D2B8, libgcc2 ctors/dtors 0x31DA48, exception.cc 0x321308 (into 00321240.cc as C++). Next area: 0x324EB0.
- **Headers:** pending_headers.md moved into include/godhand/ (new: DirSel.h, espSys.h, stageSet.h, stlAlloc.h; extended: ColiseumBattle.h enemy list/IsEntryActive, CustomIDPanel.h disp setters, cActionButton.h entry next/unk0C/unk2C/unk32/unk36 + manager layout + ActBtnGame + protos, cMessage.h prio/prev/free/serial + protos, cMessDrawFontCode.h message protos, cSnd.h fA4, unsigned unk5F, cSndKindEnt). Kept local because other TUs declare them differently: func_001F0498, ColiseumBattle_DefeatAllEnemies, cMessageWin_close, the CustomIDWork by-value colour setters, the cSnd method prototypes; MsgWinAnim fields stay in the NM file because cMessageWin is embedded at offset 0 in other structs. Every affected registered TU re-checked with match_check (only pre-existing .rodata-reloc cases unresolved in isolation), NM files compile-checked.
- **Cold build:** PASSED (compile.py --cold, 277 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **Permuter:** func_001F3488 run ended at base 320, no improvement; stopped for the cold build, no permuter processes left in godhand-nix.

## Checkpoint (single-agent, batches 31-40) — 2026-10-16T20:15:00Z

- **% fully linked:** 46.0701% (1306724 / 2836384 code bytes); 8479 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 21-30, 18:43Z):** +9936 B, +59 functions (18 NON_MATCHING, 2 hard-tail)
- **Bytes per hour:** ~7550 B/h (9936 B over 1.32 h, 18:43Z to the last logged function at 20:02Z)
- **Areas worked:** CRI/Sofdec cygnus band: AIX demux 0x32F988, CRI stream pool 0x336E88, MWSF handle 0x346848 / 0x347F20, SFD ring buffer 0x34F200, SFX 0x35F698, singletons 0x347908 / 0x338788 / 0x354D80 / 0x36C080 / 0x34CCB0; sn band: sequence nodes 0x37C330 / 0x37D760, file select 0x3835A0, menu list 0x385078, 0x2BA7B8; current area: remaining singletons (areas.py top)
- **Headers:** pending_headers.md moved into include/godhand/ (new: criSj.h, criAix.h, criStm.h, criFs.h, mwsfHn.h, adxmThread.h, seqNode.h, menuCtl.h, cutCmd.h; extended: sftim.h SfdFrm state word/f58, SfdWork f7C/nfrm/16-frame pool/channel ids @0x1F74/ViBuf, SJ interface moved to criSj.h; stageSet.h cBoundingBox returns BoundingBox*; sfxlib.h SfxStm/SfxInf/SfxTbl). Local duplicates removed; every affected TU re-checked (23 includers MATCH). Kept local on purpose: adxm_ResumeThread/WakeupThread int returns in sa_00324eb0.c (adxm.h callers use char/void), the unprototyped func_00323E80/func_003A6A20 in sa_003835a0.c, and the Obj35E8 setter prototypes in sa_0035f698.c (0035e8.c defines them with char* parameters). One new pending row (sa_00347908 views) for the next checkpoint.
- **Cold build:** PASSED (compile.py --cold, 253 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **Blocked:** func_003BAFD0 matches as C but carving it zeroes the relocated data words at D_003BAFE4/EC; moved to build/sa/blocked_003bafd0.c and blocklisted.
- **Permuter:** func_00337240 solved (memset-like callee needed its real `void *` return); func_00347FE0 only via a `mw++; mw--;` no-op (rejected); func_0032BE10 no improvement. Stopped for the cold build; no permuter processes left in godhand-nix.

## Checkpoint (single-agent, batches 41-50) — 2026-10-17T01:02:00Z

- **% fully linked:** 47.1859% (1338372 / 2836384 code bytes); 8637 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 31-40, 20:15Z):** +31648 B, +158 functions (117 own matches, 41 NM closer handoffs); 35 parked NON_MATCHING
- **Bytes per hour:** ~7280 B/h (31648 B over 4.35 h, 20:15Z to the last logged function at 00:36Z)
- **Areas worked:** enemy damage-volume family 0x1932D8 (30 units via fam_build), Poker 0x1DC798, pad input 0x161990, classFADE (-O0 units under the per-file approval), cMessage 0x2AFED0 / 0x2B0908, FP motion helpers 0x270D00 / 0x271148 / 0x2DB7E0 (NM: copy-then-abs FP register pattern), MWSF views 0x347908 / 0x356E98, small singletons by size from the decomp queue (sn band 0x31B2E0-0x37CCE0, as sn per file)
- **Headers:** pending_headers.md moved into include/godhand/ (new: emDamageVol.h, padState.h, mwsfViews.h; extended: Poker.h PokerStraightTbl10, classFADE.h full struct and prototypes). Applied with scripts/sa/header_merge.py: 39 registered units rebuilt with identical objects; 7 NM files compile-checked with unchanged results. Kept local: cEmSetParam_setEm (conflicts with cEmSetParam.c, merge rolled back) and ArenaEm (three TUs define their own).
- **Cold build:** PASSED (compile.py --cold, 295 s, includes the as=sn and -O0 units) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **Per-file settings (standing approval):** as "sn" on 8 new units, fp_hazard_rules "mtc1" on sa_002b0908.c, -O0 on classFADE.c / sa_classfade_start.c; each noted in the batch log.
- **NM closer handoffs received, registered, rejected:** 41 received, 41 registered, 0 rejected (batches 48-50; the closer started at batch 48). One handoff needed a duplicate func_003077E8 removed after reseed 48f failed to link; nm_handoff.py now rejects solved files that define other non-static functions.
- **Tools added:** scripts/sa/nm_handoff.py (verify, splice, register handoffs; meta.json per-file settings incl. c_flags_add/c_flags_drop/fp_hazard_rules; header_changes.md applied transactionally with every dependent registered unit rebuilt and compared, rolled back on any break), scripts/sa/nm_prune.py, scripts/sa/header_merge.py (checkpoint header moves with the same rebuild-and-compare transaction). Permuter stopped per instruction.

## Checkpoint (single-agent, batches 51-60) — 2026-10-17T03:15:00Z

- **% fully linked:** 47.8081% (1356020 / 2836384 code bytes); 8735 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 41-50, 01:02Z):** +17648 B, +98 functions in the objdiff report (59 own matches and 25 NM closer handoffs in the batch log; the remainder are functions in multi-function handoff units); 33 parked NON_MATCHING
- **Bytes per hour:** ~8610 B/h (17648 B over 2.05 h, 01:02Z to the last logged function at 03:05Z)
- **Areas worked:** never-carved singletons by size from the decomp queue (136-152 B): Sofdec/MWSF handle helpers 0x33B5C8-0x3592xx (cygnus-2.96, mostly -freorder-blocks dropped + as sn), SFX library 0x3603xx-0x37xxxx, cDvd job allocation 0x2017A8, room item helpers 0x260650 / 0x26BAD8, memory card hook 0x2AE8A8, g++ runtime __si_type_info_dcast (ee-2.9-991111)
- **Headers:** nothing to merge; the batch 51-60 types each have a single user and stay local (listed in pending_headers.md under the batch-60 review).
- **Cold build:** PASSED (container_run.sh compile.py --cold, 273 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK. A first attempt from the host shell failed before linking (mipsel-linux-gnu-as is only inside the container) and touched no outputs.
- **Per-file settings (standing approval):** as "sn" and/or -freorder-blocks dropped on new units only, each listed in the batch log; compiler ee-2.9-991111 (already used by src/cod/00376978.c) on sa_0031ef18.c. -fno-gcse and ee-2.9-991111 were tried on func_00376370 / func_003234D0 and not kept.
- **NM closer handoffs received, registered, rejected:** 26 received, 25 registered, 1 rejected (func_002CA5D8: matches only with the wrapper arg --call-loop-pad, which is not a per-file setting). No handoff used header_changes.md or c_flags_add/c_flags_drop yet.
- **Tools:** nm_handoff.py and progress/nm_solved/README.md handle header_changes.md and meta.json c_flags_add / c_flags_drop (verified transactionally, rolled back on any break); README states that wrapper args are not accepted.

## Checkpoint (single-agent, batches 61-70) — 2026-10-17T06:04:00Z

- **% fully linked:** 48.3407% (1371128 / 2836384 code bytes); 8818 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 51-60, 03:15Z):** +15108 B, +83 functions in the objdiff report (60 own matches and 23 NM closer handoffs in the batch log); 43 parked NON_MATCHING
- **Bytes per hour:** ~5770 B/h (15108 B over 2.62 h, 03:15Z to the last logged function at 05:52Z)
- **Areas worked:** never-carved singletons by size from the decomp queue (184-208 B): Sofdec/MWSF and DTX helpers 0x3307xx-0x35DBxx (cygnus-2.96, mostly -freorder-blocks dropped), SFX/sound 0x36xxxx-0x37xxxx, movie manager 0x2B4960 / 0x2D3BA8, event lookup getEventObjPtr, BGM table 0x2D0658, IOP/SIF library 0x3A92E0 / 0x3B2080 (sn and ee-2.9-991111)
- **Headers:** nothing to merge; the batch 61-70 types each have one registered user and stay local (listed in pending_headers.md under the batch-70 review).
- **Cold build:** PASSED (container_run.sh compile.py --cold, 461 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached build.
- **Per-file settings (standing approval):** on new units only, each listed in the batch log: -freorder-blocks dropped (cygnus), as "sn" (sa_002c7e30.c and others), -f=-fno-gcse on sa_00340130.c. Compiler choice for new files was limited to compilers already in compile_config.json (sn-2.95.3-136, cygnus-2.96, ee-2.9-991111). call_loop_pad is now accepted from handoffs as an existing per-file key.
- **NM closer handoffs received, registered, rejected:** 23 received, 23 registered, 0 rejected (batches 61-70). func_002CA5D8 was reprocessed and registered after call_loop_pad was accepted.
- **Tools:** nm_handoff.py and progress/nm_solved/README.md accept call_loop_pad in meta.json. Open tooling note: in func_002BE028 (sa_nm_002be028.c), the call-loop pad nops appear in the stage-s asm but disappear from the ee-as object when cc1 has already filled the jal delay slot inside .set noreorder.

## Checkpoint (single-agent, batches 71-80) — 2026-10-17T13:05:00Z

- **% fully linked:** 49.7040% (1409796 / 2836384 code bytes); 8995 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 61-70, 06:04Z):** +38668 B, +177 functions in the objdiff report (114 own matches and 63 NM closer handoffs in the batch log); 67 parked NON_MATCHING
- **Bytes per hour:** ~5650 B/h (38668 B over 6.84 h, 06:04Z to the last logged function at 12:54Z)
- **Areas worked:** never-carved singletons from the decomp queue (212-280 B): CRI ADX/SJ/Sofdec/MPV helpers 0x32xxxx-0x36xxxx (cygnus-2.96, -freorder-blocks dropped), AC-3 header parse 0x3BA3D8, menu and option screens 0x37xxxx-0x38xxxx (menuCtl.h), game objects and the cModel constructor 0x1495A0, player hit check 0x12CAE0, cCoreSave_loadStageState, IOP/SIF retry loops 0x2C9D58, libgcc frame.c (ee-2.9-991111)
- **Headers:** merged `State76A790` (sa_00377bc8.c) and `Perf76A790` (sa_00375500.c), two views of D_0076A790, into new `include/godhand/sndSys76A790.h` with scripts/sa/header_merge.py; both units rebuilt with identical objects. The other batch 71-80 types stay local (one registered user each, or overlapping views only in NM files); the shared objects to revisit together are listed in pending_headers.md under the batch-80 review.
- **Cold build:** PASSED (container_run.sh compile.py --cold, 308 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached build.
- **Per-file settings (standing approval):** on new units only, each listed in the batch log: -freorder-blocks dropped (cygnus), c_flags_add -f=-fno-gcse on sa_001fdfd8.c, compiler ee-2.9-991111 (already in compile_config.json) on sa_0039eaa8.c and sa_00322030.c. No compiler was added and no existing file changed compiler.
- **NM closer handoffs received, registered, rejected:** 64 received, 63 registered, 1 rejected (batches 71-80; per batch 7/7/0, 2/2/0, 3/3/0, 0/0/0, 6/6/0, 25/24/1, 20/20/0, 1/1/0, 0/0/0, 0/0/0). The rejection was func_001ECFE8, a stale NON_MATCHING block for a function matched since batch 6.
- **Tools:** nm_handoff.py now accepts *_nm*.c files with bare INCLUDE_ASM lines and falls back to config/symbol_addrs.txt for addresses (batch 77). Order sweeps were plain loops over hand-written statement orders; no permuter. Note for reseeds: the anchor must be a matched (carved) function; a parked anchor exits rc=1 without touching the hashes.

## Halt (batches 81-84, plus one handoff) — 2026-10-17T17:46:59Z

- **% fully linked:** 50.3193% (1427248 / 2836384 code bytes); 9053 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint batches 71-80, 13:05Z):** +17452 B, +58 functions (49 own matches, 9 NM closer handoffs); 30 parked NON_MATCHING
- **Bytes per hour:** ~3730 B/h (17452 B over 4.70 h, 13:05Z to this halt)
- **Own matches:** 45 logged in batches 81-84 (39 new units, 6 NM upgrades: func_001B0838, func_00345F48, func_00352F40, func_003533A8, func_00374B70, func_00375988) plus 4 carved units that are in the verified link but have no batch-log row (func_00345090, func_00394DD8, func_001DDF08, func_0030B728)
- **Cold build:** not run. Cached reseed after the last handoff matches retail: ELF `1742f95bef65bdb2aa57b7a77df4ac7619a092e9646e1ea325bc32ec8a64f3cd`, overlay `ea59932301345e48add7a3eff029b7d0d0138fff1abc67569467880678c653c1` (build/sa/reseed85.log, anchor func_00103760)
- **Per-file settings (standing approval, new units only):** sn default; cygnus-2.96 with -freorder-blocks dropped; cygnus-2.96 default on sa_00327568.c; ee-2.9-991111 default on sa_00321e08.c and sa_00320800.c; call_loop_pad on sa_0013d400.c; -ffast-math plus fp_hazard_rules probed on func_002AC878 and func_0015AF30 and not kept. No existing file changed compiler.
- **NM closer handoffs received, registered, rejected:** 11 received, 9 registered, 2 rejected. Registered: func_002D40F8, func_0031C238, func_00379F00, func_002BB2D8, func_00335F20, func_00375380, func_002E2800, func_0032D720, func_00103760. Rejected: func_002E2800 on the first submission (a union member named `word`; resubmitted and registered in batch 84) and func_00375988 (already matched). Inbox empty.
- **Stopped:** no live compile.py, reseed, or permuter in godhand-nix. 1451 unreaped zombie python/qemu/mipsel processes remain, parented to pid 1 (`sleep infinity`), which does not reap them. Nothing is registered in compile_config.json beyond this verified link.

## Rebase onto upstream; new working folder — 2026-10-17

This tree now lives in `/Users/joncaceres/god-hand-decomp` on branch `work`. The old folder
(`god-hand-decompilation-main`) is retired. Start from the state below, not from the halt entry above.

- **% fully linked:** 50.7878% (1440536 / 2836384 code bytes); 9113 / 10573 functions (`scripts/progress.sh` with this branch's compile.py)
- **Data %:** 83.0150% (unchanged)
- **What changed:** the work was rebased onto upstream (138 upstream commits). Upstream had matched 419 of the same functions independently; its versions were kept and the duplicates here were removed. Many old names changed in upstream's rename sweep: use the names in `config/symbol_addrs.txt` and `compile_config.json`, not the old `func_` names in the log above.
- **Reverted to INCLUDE_ASM:** 14 matches that pasted retail instructions through `__asm__` (see `asm_fix_later.md`). They need real C.
- **Not on this branch:** the batch 84 NM drafts (func_00317FF0, func_00356B10, func_003B2708, func_002D8EB0, func_0030FB70, func_00376080) and the func_00103760 handoff, all made after the snapshot. Upstream matched func_00103760 as FollowObj_snapToPlayer. NM drafts whose functions are now matched were dropped (see `nm_closer_log.md`).
- **Cold build:** PASSED (container_run.sh compile.py --cold, 321 s, after a fresh split) — ELF `1742f95b…` OK · overlay `ea599323…` OK
- **session_check:** fails dual_compiler_regress and data_decls (both fail on unmodified upstream too) and section_owner (the NON_MATCHING drafts have bodies no carve owns; expected while they are drafts). Everything else passes or skips.
- **Rules:** agents never run git (see `.cursor/rules/no-git.mdc`). Leave changed files for the maintainer to commit. Real C only: a single `nop` or barrier is fine, no pasted listings, no forced registers.

## Checkpoint (single-agent, batches 85-91; due at batch 90, run after batch 91) — 2026-10-18T16:08:00Z

- **% fully linked:** 50.8392% (1441996 / 2836384 code bytes); 9120 / 10573 functions
- **Data %:** 83.0150% (unchanged)
- **Since last entry (rebase onto upstream):** +1460 B, +7 functions: 6 own matches (__start_cp_handler 56, func_003448B0 68, func_0030DA08 208, func_00327418 332, func_00195D08 332, func_00348670 332 = 1328 B) and 1 NM closer handoff (func_003780F8, 132 B); 15 parked NON_MATCHING (7, 3, 1, 1, 1, 1, 1 in batches 85-91)
- **Bytes per hour:** ~1170 B/h (1460 B over 1.25 h, batch 85 start at 13:31Z to the last batch 91 row at 14:46Z). Batches 89-91 matched nothing; the user reset the zero-match streak after batch 91.
- **Areas worked:** never-carved singletons from the untried-M2C queue, 56-336 B: CRI SJ/ADX/MWSF helpers 0x3247xx-0x34Cxxx (cygnus-2.96), damage-take enemy setups 0x17AC90 / 0x195D08 (sn), enemy state 0x28A780, IOP/SIF 0x3B9F60 / 0x3BBEC0
- **Headers:** nothing merged; every batch 85-91 type has one registered user or appears only in NM files (pending_headers.md, batch 85-87 sections). include/ unchanged.
- **Cold build:** PASSED (container_run.sh compile.py --cold, ~650 s wall, compile 558 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached reseeds. Log: build/cold_cp90.log.
- **Per-file settings (standing approval, new units only):** sn default (sa_0030da08.c, sa_00195d08.c, sa_003780f8.c); cygnus-2.96 default (sa_00327418.c); cygnus-2.96 with -freorder-blocks dropped (sa_00348670.c); ee-2.9-991111 default on one batch 85 unit. No compiler added, no existing file changed compiler.
- **NM closer handoffs received, registered, rejected:** 1 / 1 / 0 (func_003780F8, batch 87). Inbox empty.
- **Missed timing:** this checkpoint was due after batch 90 and ran after batch 91.

## Checkpoint (single-agent, batches 92-100) — 2026-10-18T17:37:00Z

- **% fully linked:** 51.1602% (1451100 / 2836384 code bytes); 9146 / 10573 functions (objdiff report regenerated through container_run.sh scripts/progress.sh; the host has no tools/objdiff-cli)
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint 90):** +9104 B, +26 functions: 25 own matches in batches 92-100 (func_0012F600 336 from the batch 92 retry window, then 24 in the 340-372 B bands, 8420 B) and 1 NM closer handoff (func_00354650, 348 B, batch 97); 20 functions parked NON_MATCHING with complete C (sa_nm_*.c)
- **Bytes per hour:** ~6070 B/h (9104 B over 1.5 h, first batch 92 row at 15:57Z to the last batch 100 row at 17:27Z)
- **Areas worked:** untried-M2C queue, 336-372 B bands: CRI SFD/MWSF/SJ code 0x324950-0x36EE90 (cygnus-2.96, mostly -freorder-blocks dropped), sequence/voice tables 0x37C930-0x37E200 (sn), newlib _malloc_trim_r 0x3ACD20, cOmDoor_setOpen, enemy/object helpers 0x1AEF40-0x2F40C0 (sn), ADX setup 0x3B9998
- **Headers:** merged the newlib malloc chunk types and __malloc_av_ into new `include/godhand/newlibMalloc.h` (003ac090.c, 003aca28.c, sa_003acd20.c; header_merge OK, 3 units rebuilt identical). Other batch 92-100 types stay local (single registered user or NM-only); see pending_headers.md, batch 92-100 sections.
- **Cold build:** PASSED (container_run.sh .venv/bin/python compile.py --cold, compile wall 296 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached reseeds after every batch. Log: build/cold_cp100.log.
- **Per-file settings (standing approval, new units only):** sn-2.95.3-136 default (sa_001aef40.c, sa_001d4df0.c, sa_001dc980.c, sa_001dcad8.c, sa_00288da8.c, sa_0037c930.c, sa_0037e200.c, sa_002f40c0.c, sa_003acd20.c and the batch 93 units); sn-2.95.3-136 with "as": "sn" (sa_001bcfb0.c); cygnus-2.96 with -freorder-blocks dropped (sa_00360950.c, sa_00354478.c, sa_003b9998.c, sa_00334f90.c, sa_00332398.c, sa_0036ee90.c, sa_0034eb98.c, sa_00324950.c, sa_00348e18.c). No compiler added, no existing file changed compiler.
- **NM closer handoffs received, registered, rejected:** 1 / 1 / 0 (func_00354650). Inbox empty.
- **Stop conditions:** none hit. Every reseed elf=OK overlay=OK; nm_prune 0 stale throughout; zero-match streak 0.

## Checkpoint (single-agent, batches 101-110) — 2026-10-18T22:45:00Z

- **% fully linked:** 52.3097% (1483704 / 2836384 code bytes); 9224 / 10573 functions (objdiff report regenerated through container_run.sh scripts/progress.sh)
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint 100):** +32604 B, +78 functions. batch_log has 70 own matched rows in batches 101-110 (29452 B) plus 5 NM closer handoffs (func_0030B298, func_00325638, func_00333CE0, func_00373BA8, func_0039B960). The other 8 functions and 3152 B are the 5 handoffs plus 3 functions I did not trace (probably carved entries); I did not break the bytes down further. 24 functions parked NON_MATCHING with complete C (sa_nm_*.c, unregistered), 18 skipped (HAND VU0, HAND MMI, cvt.w.s, jump tables).
- **Bytes per hour:** ~6650 B/h (32604 B over 4.9 h, first batch 101 row at 17:39Z to the last batch 110 row at 22:33Z)
- **Areas worked:** untried-M2C queue, 372-476 B bands: CRI ADXT/SJ/SFD code 0x3298F0-0x36B888 (cygnus-2.96, -freorder-blocks dropped), libgcc __frame_state_for, SDK libdma sceDmaPutEnv and libio/newlib (ee-2.9-991111), enemy setup/update families 0x178618-0x2DB0D0 (pointer-to-member phase dispatch, damage-take boxes), menu panels, the MT19937 generator 0x30F348 (sn)
- **Headers:** merged the shared enemy phase-table entry into new `include/godhand/emPhaseTable.h` (`EmPhaseEnt` / `EmPhaseTable`; sa_00181118.c, sa_001ac980.c, sa_001af098.c, sa_00278390.c, sa_00281968.c; header_merge OK, 5 units rebuilt identical). Other batch 101-110 types stay local (single registered user or NM-only); see pending_headers.md, batch 101-110 sections.
- **Cold build:** PASSED (container_run.sh .venv/bin/python compile.py --cold, compile wall 400 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached reseeds. Log: build/cold_cp110.log.
- **Per-file settings (standing approval, new units only):** compiler per address band (sn-2.95.3-136 for game code, cygnus-2.96 with -freorder-blocks dropped for the CRI band, ee-2.9-991111 for libgcc/libio/newlib/SDK); "as": "sn" on sa_002db0d0.c. No compiler added, no existing file changed compiler. Not used: the per-file `extern_double` key (needed by func_003B0EF8); it is not on the standing-approval list.
- **NM closer handoffs received, registered, rejected:** 5 / 5 / 0. Inbox holds one new solution (Draw_Line_sc), to be applied with the batch 111 handoff.
- **Process slips:** batch 109 registered three NM files by mistake (removed again before a reseed passed) and left three stale asm fragment objects that broke the link until deleted; func_00192D20's elapsed time is under-logged.
- **Stop conditions:** none hit. Every reseed ended elf=OK overlay=OK; nm_prune 0 stale throughout; zero-match streak 0.

## Checkpoint (single-agent, batches 111-120) — 2026-10-19T03:40:00Z

- **% fully linked:** 53.0358% (1504300 / 2836384 code bytes); 9262 / 10573 functions (objdiff report regenerated through container_run.sh scripts/progress.sh)
- **Data %:** 83.0150% (unchanged)
- **Since last entry (checkpoint 110):** +20596 B, +38 functions. batch_log has 32 own matched rows in batches 111-120 (17448 B) plus 6 NM closer handoffs (Draw_Line_sc, func_001AD5C8, func_0027BB78, func_001A5540, func_0033D720, func_0036DFF0); 32 + 6 = 38 functions, and the handoffs account for the other 3148 B. 52 functions parked NON_MATCHING with complete C (sa_nm_*.c, unregistered), 29 skipped (jump tables, cvt.w.s, HAND VU0/MMI, splitter artifacts like the raw `lui (0x780000 >> 16)` in func_003B4628/func_003B56A0/func_003B4868).
- **Bytes per hour:** ~4500 B/h (20596 B over 4.6 h, first batch 111 row at 22:44Z to the last batch 120 row at 03:18Z). The 588-652 B band parks far more often than the earlier 372-476 B bands.
- **Areas worked:** untried-M2C queue, 476-652 B bands: enemy/gimmick update and setup families (0x17B000-0x1B9000), object node sync (0x2E6868, 0x2F48A8), GS texture setup 0x3092E0, CRI ADX/SJ/Sofdec 0x327000-0x36B000 (cygnus-2.96, -freorder-blocks dropped), menu pages 0x3808A0/0x384CA0, SDK SIF/iob (ee-2.9-991111).
- **Headers:** merged the shared vector inlines into new `include/godhand/vecInline.h` (`vec4_eq` / `vec4_ne` / `vec3_copy`; sa_001b76d8.c, sa_001c0450.c, sa_00276228.c; header_merge OK, 3 units rebuilt identical). The other batch 111-120 types stay local (single registered user or NM-only). The SJ chunk/interface tables (sa_00327048.c, sa_0032cc90.c, sa_0036a3e8.c) are the next merge candidate, but their member names differ per file and need a careful unification pass; see pending_headers.md, batch 111-120 sections.
- **Cold build:** PASSED (container_run.sh .venv/bin/python compile.py --cold, compile wall 617 s) — ELF `1742f95b…` OK · overlay `ea599323…` OK; same as the cached reseeds. Log: build/cold_cp120.log.
- **Per-file settings (standing approval, new units only):** "as": "sn" on sa_0037bf10.c and sa_002e6868.c; c_flags_add -f=-fno-gcse on sa_001b57e8.c (same flag as its clone TU 0018a680.c); compiler per address band as before. No compiler added, no existing file changed settings.
- **NM closer handoffs received, registered, rejected:** 6 / 6 / 0.
- **Recurring NM blockers (permuter/closer candidates):** short-loop nop pads retail has but ee-as/call_loop_pad don't emit (291D48, 352298); s-reg anchor rebase (30B420); unfolded `xori`/`movn` that ours folds to `sllv` (36AE70); small regalloc/scheduling gaps at 13 diffs (2F48A8, 3B21D0).
- **Stop conditions:** none hit. Every reseed ended elf=OK overlay=OK; nm_prune 0 stale throughout; zero-match streak 0.

## Stop (single-agent, batches 121-130 plus a final handoff batch; checkpoint header merge not completed) — 2026-10-21T06:30:00Z

- **% fully linked:** 53.0540% (1504816 / 2836384 code bytes); 9212 / 10573 functions matched per progress/report.json (regenerated through container_run.sh scripts/progress.sh at 06:29Z). Data 83.0150% (unchanged).
- **Numbers that don't add up, not investigated:** code bytes are only +516 B over the batch 120 entry (1504300), and matched functions read 9212 against the 9262 quoted there. That is far less than the batch log and handoff log below account for. The batch 120 function count may have come from a different measure. Treat the deltas as unexplained until the report is compared against the batch 120 one.
- **Since last entry (batch log rows 2026-10-19T04:01Z to 2026-10-21T04:28Z):** 22 own matched rows (14260 B), 51 parked NON_MATCHING (31931 B, unregistered `#ifdef NON_MATCHING` files), 31 skipped (12940 B: jump tables, cvt.w.s, HAND VU0/MMI, splitter artifacts). NM closer handoffs: 18 registered, 1 rejected (func_002B1890, later re-handed and registered).
- **Bytes per hour:** not meaningful for this span. It covers two sessions with an idle gap, and late in batch 129/130 host load stretched single compiles to about 3 minutes and a reseed to 37 minutes.
- **Areas worked:** collision 0x130700-0x137FFF, camera 0x1399A0-0x13BFFF, GS packet 0x299xxx, enemy setup/link 0x26E000-0x283FFF, object/mesh 0x192xxx/0x1B7xxx, effect node 0x2F6xxx and 0x3033A8-0x305FFF, scenario 0x1EBxxx-0x1EFxxx.
- **Final batch (stop request):** nm_handoff --apply registered func_001334A8, func_00276DC8 and func_00283AA8. The last one brought its own vu0.h change (VU0_VADD_XYZ_IP/VU0_VSUB_XYZ_IP), verified with 95 dependent units rebuilt unchanged. The reseed (anchor func_00283AA8, 13043 units) gave main ELF `1742f95b…` matching retail and r207 `ea599323…` matching retail. nm_prune found 0 stale. Every path registered in compile_config.json exists and was in that build.
- **Checkpoint header merge:** interrupted. scripts/sa/header_merge.py (build/scratch/hm_cp130.json) applied both of its edits, then stopped before its compare finished. Its orphaned rebuild loop in the container ran to completion. After that:
  - The `func_002B6350` two-argument edit to 0028b148.c was reverted by hand.
  - The new `VU0_SQC2_VF0_MEM` macro (memory output operand, no "memory" clobber) is still in include/godhand/vu0.h. No registered unit uses it, and the full reseed above was built with it in place.
- **Cold build:** not run, per the stop instruction (start nothing new). The last cold build is still the batch 120 one.
- **Per-file settings (new units only):** none this span beyond the compiler line (sn-2.95.3-136). The 00154da0.c NM draft needs `as: sn` if it is ever registered.
- **Held, ready but not registered:**
  - The effect-node TU in build/scratch/003033a8_ckpt2.c matches func_003033A8, func_003034A8, func_00304830, func_00304940 and func_00304A48. It needs VU0_SQC2_VF0_MEM (now present) and, for func_00304A48, the two-argument func_002B6350, which header_merge has to apply again.
  - func_002F6CF8 is at 9 diffs (build/scratch/002f6cf8_best.c).
  - func_0017F6C0 and func_0017F828 need memory-operand LQC2/SQC2 copy macros.
- **Recurring NM blockers:**
  - Retail rebuilds a stack address (`addiu reg, sp, N`) at each use where ours keeps it in a saved register (00276DC8, 0026EB20, 00283AA8, 001EBA20).
  - The sqrt.s template.
  - Short-loop pad nops (cOmBase_setMeshAlphaFromLayer, 1 nop).
  - If/else constants hoisted before the branch (0013B5F0).
  - Store scheduling in duplicated arms (00192588).
- **Open header conflicts (pending_headers.md, batches 127-129):**
  - D_005CAFF0: reachObj.h types it as `PlayerReach *`, but the camera code and func_002F6CF8 use it as the camera.
  - cIDBaseEnt.flags signedness.
  - cMeshNode and cModelNode describe the same mesh node.
  - cOmBase 0x100 is named posPrev, but the enemy link code reads 0x104 as the heading.
- **Processes:** godhand-nix runs only its `sleep infinity` init. No compile.py, reseed or permuter process is running on the host or in the container.

## Checkpoint (single-agent, batches 131-139; called early, header merge skipped) — 2026-10-21T20:05:00Z

- **% fully linked:** 53.6008% (1520324 / 2836384 code bytes; report regenerated through container_run.sh scripts/progress.sh at 20:01Z). Data 83.0150% (unchanged). +15508 B over the last entry (1504816).
- **Since last entry (batch log rows 14:19Z to 19:09Z):** 23 own matched rows (7412 B), 31 parked NON_MATCHING (11448 B), 40 skipped (14864 B: cvt.w.s, VU0 address-hoist wall, cOmBase_childAt at a variable index, packet builders, CRI range). Some matched rows were held, not registered (see below). The rest of the byte gain comes from NM closer handoffs.
- **Bytes per hour:** about 1500 B/h of own matches (7412 B over 4.8 h). The remaining 350-700 B functions are mostly VU0-heavy.
- **Areas worked:** object/enemy spawners 0x1A7xxx-0x1D4xxx, enemy core 0x26Bxxx-0x277xxx, custom ID panel 0x1EDxxx, effect nodes and SetEffectPos 0x2F4xxx-0x306xxx, map objects 0x17Fxxx/0x18Fxxx/0x1A6xxx, area zones 0x305C20, camera path 0x137F38, cModel part list 0x149C20.
- **Registered this span (batches 136-139):** func_0018F618 (needs the per-file setting fp_hazard_rules "fdiv"), func_00305C20, func_00277568 (declares cCollisionSolidManage_ChkHit with its real int return), SetEffectPos (src/cod/00306838.c).
- **Header merge:** skipped. Every pending item either overlaps the waiting handoffs' header requests (cVec_zero in cOmBase.h, VU0_SQC2_MEM in vu0.h, the cGameObj vel field) or edits several registered units at once. All of them stay in pending_headers.md: cEffectParam_init and cVec_zero; cAreaFx; ChkHit returning int; the cCamManager follow fields; the PathHost/PathRec fields; cOmHitVolume rec at 0x5E0; the func_00302918 and SetEffectPos prototypes; the cEm00 fall view.
- **Cold build:** PASSED (container_run.sh .venv/bin/python compile.py --cold) with ELF `1742f95b…f3cd` and overlay `ea599323…53c1`, both matching retail and the cached reseeds. Log: build/scratch/cold140.log.
- **Per-file settings (new units only):** fp_hazard_rules "fdiv" on src/cod/0018f618.c. No others beyond the compiler line.
- **NM closer handoffs:** 14 received, 11 registered, 3 rejected (func_001299F0, func_0026F328, func_00275888). Those three need header edits and are left in progress/nm_solved/ for later. An apply attempt at this checkpoint was interrupted and then stopped. It had written VU0_SQC2_MEM into vu0.h and the vel field into cGameObj.h; both edits were reverted by hand to the verified text before the cold build. Nothing was registered from it.
- **Held, ready but not registered (need the header merge):** 002f4290, 001a6310, the 003033a8 group, 001cd800, cE3_menu, 0037ca98, 00249770 (build/scratch/*_ckpt*.c).
- **New drafts:** drafts/cod/00149c20.c, 00198d40.c, 00137f38.c (2 diffs, permuter candidate), 002a87e8.c (D_00747A84 bit test with dsrl needs a long temporary, which the rules ban).
- **Recurring NM blockers:** VU0 copies through precomputed sp addresses; cOmBase_childAt at a variable index (andi 0xFF bool and the frame slot); the switch compare tree ==1 / <2 / ==2; a parameter homed to the stack (00149C20).
- **Tooling note:** scripts/gen_decomp_queue.py has no --help. Calling it with --help ran it and rewrote the untracked progress/decomp_queue.json with an empty queue, because it filters the old `asm/cod/000000.part*` unit names. permuter_daemon.sh reads the file only for optional size metadata.
- **Stop conditions:** none hit. Every reseed gave elf=OK overlay=OK; nm_prune found 0 stale; session_check gave 18 pass and the known dual_compiler_regress failure in each batch.
- **Processes:** godhand-nix runs only its `sleep infinity` init (docker top). No compile.py, reseed, handoff, session_check or permuter process is running on the host.

Stopped for upstream sync

## Checkpoint (single-agent, batches 140-149; header merge applied for the held functions) — 2026-10-22T13:45:00Z

- **% fully linked:** 54.1041% (1534600 / 2836384 code bytes; report regenerated through container_run.sh scripts/progress.sh at 13:42Z). Data 83.0150% (unchanged). +14276 B over the last entry (1520324).
- **Since last entry (batch log rows after 2026-10-21T20:05Z):** 20 matched rows (11224 B, including the four checkpoint registrations), 39 parked NON_MATCHING (24892 B), 81 skipped (57808 B: cvt.w.s on sn, jump tables, handwritten VU0, lwu bit tests, the off-limits cObjSimple child-model code). Batches 147, 148 and 149 each registered nothing; the small sn queue is exhausted.
- **Areas worked:** debug print / sound debug pages 0x381xxx, sequencer 0x372xxx-0x37Dxxx, slot machine 0x1F5xxx, TIM2 loader 0x15Exxx, CRI ADXT / MWSFD / movie player 0x329xxx-0x34Axxx, sound listener 0x2CC150, scenario jumps 0x2C45A8, enemy pose 0x2956F0, SFX ramps 0x366xxx.
- **Header merge:** applied only the items the held functions needed (seqNode.h pan and prototypes, new cGrid.h, mwPly.h span/rate and the func_00328C80 prototype, mwsfd.h func_0032B488 with its definition corrected); header_merge rebuilt 12 units with identical objects. Everything else stays in pending_headers.md.
- **Registered at the checkpoint:** func_0037D558 (fp_hazard_rules "mtc1"), func_0012F288 (fp_hazard_rules "fdiv"), func_00349C28 (c_flags_drop -freorder-blocks), func_0032DD70 (fp_hazard_rules "cmpfull"). func_0013D7B0 stays held: it needs one shared type for D_005CAC90 and several shared prototypes (pending_headers.md).
- **NM closer handoffs:** not applied. progress/nm_solved/ holds six folders (func_0032A1B0, cSnd_UpdateListener, func_00365EC0, MoveEmitter, MoveEsp, Turn_dest). The apply run took over 30 minutes and was stopped; it had written cSnd_UpdateListener's header requests (a cVecQuad typedef in the off-limits cOmBase.h, and cSnd.h listenPos) without registering anything. Those edits were reverted by hand to the prior text before the full and cold builds.
- **New drafts (batches 140-149):** among them drafts/cod/002956f0.c, 00366110.c, 00366368.c, 002c45a8.c (same length, s0/s1 swap only), 00329490.c (ADXT_Create), 0032a1b0.c (ADXT_GetTime, solved by the NM closer), 002cc150.c (cSnd_UpdateListener).
- **Builds:** full build after the revert and cold build (container_run.sh .venv/bin/python compile.py --cold) both gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, matching retail; reseed func_003780F8 elf=OK overlay=OK. Logs: build/scratch/build_stop.log, build_stop_cold.log, reseed_stop.out.
- **Checks:** session_check through batch 149 gave 18 pass plus the known dual_compiler_regress rc=126 (argument list too long inside session_check). The standalone dual_compiler_regress last passed at batch 148 and was not rerun after the checkpoint registrations.
- **Tooling notes:** a killed nm_handoff --apply leaves its HeaderTxn edits in place (no undo on signal). Sn has no clean form for retail's cvt.w.s or lwu + dsra + andi bit tests.
- **Processes:** godhand-nix runs only its `sleep infinity` init (docker top). No compile.py, reseed, handoff, session_check, dual_compiler_regress or permuter process is running on the host.

Stopped for upstream sync

## Checkpoint (single-agent, batches 150-159; held functions and NM handoffs) — 2026-10-23T07:40:00Z

- **% fully linked:** 54.7192% (1552048 / 2836384 code bytes; scripts/progress.sh at 07:36Z). Data 83.0150% (unchanged). +17448 B over the last entry (1534600).
- **Registered at the checkpoint:** Set_bg_mode (spliced into src/cod/0030e0.c; gameWork.h gains padBtn 0x08, bgA 0x270, bgB 0x3E0, bgColor 0x60C, no offset changes). NM handoffs: cModel_calcParts (by hand, src/cod/00149eb8.c, as sn; nm_handoff left the INCLUDE_ASM in the multi-function src/cod/gfx/cModel.c and the link overflowed .text by 0x164), func_001A4010 (vu0.h VU0_VSCALE_XYZ_TO), func_002FBFB0 (espSys.h EspAnim; the handoff's second extern D_00747A84 was dropped for D_007474A0.flags5E4, same bytes), cSubScr_SubScrOn (gameWork.h flags5D8/flags5E0), func_001F0A28 (cEmWrap.h entryNo, ColiseumBattle_DefeatAllEnemies takes its unread self), func_00275978 (cEm00.h aimPos).
- **Held, not registered:** KeyStop (with gameWork.h fields retail addresses both words from &D_007474A0.0x5D8 as symbol+offset; the struct-field form shares the base register; 10 diffs). func_00133DA0 (array-ctor zeroing loop and an edge macro need review), func_00146A18 (needs IdPair header and the CustomIDWork/cIDBaseEnt merge), cMovie_Start (needs cMovie.h, off-limits), SetEffect (65 callers), and the rest listed in pending_headers.md.
- **Tooling notes:** a failed nm_handoff final build moves every folder to rejected/; a later run that finds the interrupted journal restores its snapshot, which can leave compile_units/carved_funcs entries for TUs that don't exist. Fixed by hand (3 phantom units removed) and the three re-applied cleanly. scripts/sa/header_merge.py fails to import HeaderTxn.
- **Builds:** reseed after Set_bg_mode and after cModel_calcParts elf=OK overlay=OK; each handoff verified by a full build; cold build (container_run.sh python3 compile.py --cold) ELF `1742f95bef65bdb2…`, overlay `ea59932301345e48…`, both retail.
- **Checks:** session_check 18 pass, 7 skip, known dual_compiler_regress rc=126.
- **Stop conditions:** none hit.

## Checkpoint (single-agent, batches 160-166; batch 166 cut short) — 2026-10-23T12:35:00Z

- **% fully linked:** 55.0394% (1561128 / 2836384 code bytes; scripts/progress.sh through container_run.sh). Data 83.0150% (unchanged). +9080 B over the last entry (1552048).
- **Batch 166:** stopped after 16 functions on request. One registered: Draw_Poly_sc (src/cod/0015f0.c now compiles with sn-2.95.3-136; new include/godhand/drawPrim.h, with a .gitignore allowlist line). New drafts: drafts/cod/002bebc8.c, 001c7138.c, 0020ef08.c. The rest are logged in batch_log.md as parked or skipped. Most of the remaining SN game code waits on the C++ VU0 vector temporaries decision in decisions_needed.md.
- **Headers:** cOmSub.h gains the eight vectors at 0x70..0xE0 (four users still match). Batch 166 notes were appended to pending_headers.md. The pending-header merge was not done: each item is a cross-file refactor, not a quick merge.
- **NM handoffs:** progress/nm_solved/ has nothing pending (only done/ and rejected/).
- **Builds:** reseed anchored on Draw_Poly_sc gave rc=0, elf=OK, overlay=OK, with no compile failures in build/sa_reseed.log. The cold build (container_run.sh python3 compile.py --cold) gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, both retail. Logs: build/scratch/reseed166.out, build_b166_cold.log.
- **Checks:** session_check through container_run.sh gave 18 pass, 7 skip and the known dual_compiler_regress rc=126. Run on the host instead, its build step fails in mipsel-as-wrap.py for every asm file, so it has to run in the container.
- **Stop conditions:** none hit.
- **Processes:** godhand-nix runs only its `sleep infinity` init (docker top). No compile.py, reseed, handoff, session_check or permuter process is running on the host.

Stopped for upstream sync

## Checkpoint (single-agent, batches 167-176; header merge and held registrations) — 2026-10-25T07:50:00Z

- **% fully linked:** 55.5297% (1575036 / 2836384 code bytes; scripts/progress.sh through container_run.sh). Data 83.0150% (unchanged). +13908 B over the last entry (1561128).
- **Headers:** the progress/held/inc overlays were 3-way merged into include/godhand (build/scratch/hmerge.py): 22 new headers with .gitignore allowlist lines (angle, cEmLinked, cObjGround, cPathMover, cShopPanel, capVu0, cloth, dbgText, drawQueue, eeKernel, fileHolder, keySlot, libm, mtx, padWork, rand, sceMpeg, sceTimer, scrollLayer, sif, texWork, tim2) and the padding splits. Where main already named a field (seqNode.h, menuCtl.h, regTbl.h, cSubScr.h, sideCounter.h) main's text was kept. 33 prototypes whose definitions disagree with main's local declarations were taken back out (they add -Wall warnings in 77 main files); they wait on a typing PR (decisions_needed.md). 23 local duplicate declarations in main were removed in favour of the headers, and the definitions of cCoreSave_ckClearStage, EmWeaponHolder_dropWeapons, func_002A9528 and func_002C53A8 now take their real types.
- **Registered:** 15 held matches (list and config reasons in batch_log.md). 25 drafts moved to drafts/cod/; 41 drafts and 29 other held files (matches and definition fixes) stay held on the header questions.
- **Builds:** full build and cold build (container_run.sh python3 compile.py --cold) both gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, matching retail; reseed anchored on func_002C5548 elf=OK overlay=OK. Logs: build/scratch/ck176_b5.log, ck176_cold.log.
- **Checks:** session_check through container_run.sh: 18 pass, 7 skip, known dual_compiler_regress rc=126. cygnus-2.96 -Wall shows no new warnings in the changed and added files (build/scratch/wallcmp.py). tools/strip_data_nonmatching.py rewrote 2 asm/data files for the new header externs.
- **Stop conditions:** none hit.

## Checkpoint (single-agent, batches 177-178; held registrations) — 2026-10-25T08:39:46Z

- **% fully linked:** 55.5638% (1576004 / 2836384 code bytes; scripts/progress.sh through container_run.sh). Data 83.0150% (unchanged). +968 B over the last entry (1575036).
- **Headers:** new include/godhand/sndCmd.h (func_00387328, func_00387270) and sndRamp.h (SndRamp, SndRampOwner, func_00378070, func_00377688), with .gitignore allowlist lines; tim2.h gains TexUpBlock/TexUpFile and func_0015DDF8 takes them. Main's 0037a4c8.c, 001fcde8.c and 0037cc78.c drop their local declarations for the header ones; 00387328.c and 00376e38.c include their headers (00376e38.c called func_00377688 without a prototype).
- **Registered:** func_0015DDF8 (sn, as sn), func_00377688, func_00387270; the definition of func_00378070 now takes SndRamp *. Held: func_00165EB8 (OK-lock test decision; menuKey.h page keys overlay). Drafts added: 0015db30, 002b45f8, 00155dc8.
- **Builds:** full build and cold build both gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, matching retail; reseed anchored on func_0015DDF8 elf=OK overlay=OK. Logs: build/scratch/ck178_b1.log, ck178_cold.log.
- **Checks:** session_check through container_run.sh: 18 pass, 7 skip, known dual_compiler_regress rc=126. cygnus-2.96 -Wall: no new warnings in the 9 changed and added files. strip_data_nonmatching: no changes.
- **Stop conditions:** none hit.

## Checkpoint (single-agent, batch 179; held registration) — 2026-10-25T11:40:00Z

- **% fully linked:** 55.5688% (1576144 / 2836384 code bytes; scripts/progress.sh through container_run.sh). Data 83.0150% (unchanged). +140 B over the last entry (1576004).
- **Headers:** cMessDrawFontCode.h gains the func_002AF218 and func_002B45F8 prototypes; 002afed0.c drops its duplicate func_002AF218 declaration. Four main callers still use implicit declarations (listed in pending_headers.md).
- **Registered:** func_002B45F8 (sn, default flags). Drafts added in batch 179: 001390b8 (cMotCamera_setMotion), 00270160, 0026a018, 00274d18, 002ba300 (create); held draft 00149220_nm.
- **Builds:** full build and cold build both gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, matching retail; reseed anchored on func_002B45F8 elf=OK overlay=OK. Logs: build/scratch/ck179_full.log, ck179_cold.log.
- **Checks:** session_check through container_run.sh: 18 pass, 7 skip, known dual_compiler_regress rc=126. cygnus-2.96 -Wall: no warnings in the 2 changed and added files. strip_data_nonmatching: no changes.
- **Stop conditions:** none hit.

## Checkpoint (single-agent, batch 186; id-range helper matches) — 2026-10-25T16:08:40Z

- **% fully linked:** 55.6294% (1577864 / 2836384 code bytes, progress/report.json). Data 83.0150% (unchanged). +220 B over checkpoint 186.
- **Headers:** cGameObj.h gains the func_001B8030 prototype (returns cGameObj_idInRange's long flag as is) and cSnd.h the cSnd_IsEnemyAlive prototype. The other changes in the held cGameObj.h, cSnd.h and cOmDoor.h overlays stay held (pending_headers.md).
- **Registered:** func_001B8030 (src/cod/001b8030.c) and cSnd_IsEnemyAlive (src/cod/002d0c10.c), sn, default flags. 0013cf20.c (getItemNumInRoom) now uses the header prototype; 002cf310.c had called cSnd_IsEnemyAlive undeclared. Draft rewritten: drafts/cod/001bd430.c.
- **NM handoffs:** func_00276478 and func_002B45F8 are stale (already matched in src). cMessDrawFont_draw byte-matches but declares about 20 callees locally with pointer-to-int casts, so it was left for a cleanup pass.
- **Builds:** full build and cold build (container_run.sh python3 compile.py --cold) both gave ELF `1742f95bef65bdb2…` and overlay `ea59932301345e48…`, matching retail; reseeds anchored on func_001B8030 and cSnd_IsEnemyAlive rc=0. Logs: build/scratch/cp187_full.log, cp187_cold.log.
- **Checks:** session_check through container_run.sh: 18 pass, 7 skip, known dual_compiler_regress rc=126. cygnus-2.96 -Wall: no new warnings in the changed and added files. strip_data_nonmatching: no changes.
- **Stop conditions:** none hit (the zero-match streak ended at 4).

Stopped for upstream sync
