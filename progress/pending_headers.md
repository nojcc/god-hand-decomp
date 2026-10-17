# Pending header additions

Types and signatures pinned down during single-agent matching, declared locally in the
working source file for now. Moved into `include/` at each 10-batch checkpoint.


> **2026-10-17 rebase onto upstream:** rows whose working file left this tree were dropped (34 rows). In most cases upstream matched those functions in its own TUs, and the duplicate copies were removed. Every row below names a file that exists on this branch.

| item | declared in | evidence |
| --- | --- | --- |
| `Sfd35BDD0` / `Cond35BDD0` | src/cod/sa_0035bdd0.c | func_0035BDD0; matched |
| `Slot37FE78` | src/cod/sa_0037fe78.c | func_0037FE78; matched |
| `Res305A68` / `GW305A68` / `Esp305A68` | src/cod/sa_00305a68.c | func_00305A68; matched |
| `Sub355130` / `Ctx355130` | src/cod/sa_00355130.c | func_00355130; matched |
| `Tm360B18` | src/cod/sa_00360b18.c | func_00360B18; matched |
| `Snd37A4C8` | src/cod/sa_0037a4c8.c | func_0037A4C8; matched |
| `Vt3443E0` / `Obj3443E0` / `Mwsf3443E0` | src/cod/sa_003443e0.c | func_003443E0; matched |
| `SndSys76A790` fields: frame@0x10, time@0x8C, timeMax@0x90 | src/cod/sa_00375380.c | func_00375380; matched (NM closer handoff, batch 83) |
| `Mode2D0D70` (mode@0x48, busy@0xEE8) / `Ovr2D0D70` (flags, bgm u16@8) / `Req2D0D70` (kind@0x13C) | src/cod/sa_nm_csnd_getstagebgmreq.c | cSnd_GetStageBgmReq; NM |
| `Adxt32A018` | src/cod/sa_0032a018.c | func_0032A018; matched |
| `Adxt32B1C8` / `Sj32B1C8` / `SjIf32B1C8` | src/cod/sa_0032b1c8.c | func_0032B1C8; matched |
| `IDBase143BE8` / `IDObj143BE8` | src/cod/sa_00143be8.c | func_00143BE8; matched |
| `Vec1EC928` | src/cod/sa_001ec928.c | func_001EC928; matched |
| `Ps2Work336BA8` / `Ps2Obj336BA8` / `Adxt336BA8` | src/cod/sa_00336ba8.c | func_00336BA8; matched |
| `Rng34BA88` / `Hdr34BA88` / `BufPtr34BA88` | src/cod/sa_0034ba88.c | func_0034BA88; matched |
| `Slider37AD88` / `Menu37AD88` | src/cod/sa_0037ad88.c | func_0037AD88; matched |
| `Pad1B48E0` (view of D_007474A0, frameRate@0x574) / `Mdl1B48E0` / `Em1B48E0` | src/cod/sa_001b48e0.c | func_001B48E0; matched |
| `IDWork13D400` / `CustomIDWork13D400` (0x7C) / `Obj13D400` (cw[5]@0x120) | src/cod/sa_0013d400.c | func_0013D400; matched |
| `MWSFSVM_Error` is variadic (`mwsfHn.h` declares 1 param) | src/cod/sa_00345f48.c | func_00345F48; matched in batch 83 (was NM); fix at checkpoint 90 |
| `Rec308DA8` / `Ent308DA8`; `func_0012ED60` takes 14 params | src/cod/sa_00308da8.c | func_00308DA8; matched |
| `Object321E08` / `FdeVector321E08` / `FdeAccu321E08` (libgcc frame.c) | src/cod/sa_00321e08.c | func_00321E08; matched |
| `SjCk327568` / `SjIf327568` / `Sj327568` / `Dec327568` | src/cod/sa_00327568.c | func_00327568; matched |
| `Src35F288` / `Inf35F288` (void* y/u/v plane pointers) | src/cod/sa_0035f288.c | func_0035F288; matched |
| `Req386FA0` / `Node386FA0` (req@0xE) | src/cod/sa_00386fa0.c | func_00386FA0; matched |
| `DevStat36C790` / `DevObj36C790` | src/cod/sa_0036c790.c | func_0036C790; matched |
| `Menu140718` / `Item140718` / `IDWork140718` (item[8], count@0x340) | src/cod/sa_00140718.c | func_00140718; matched |
| `BankHdr374B70` / `Bank374B70` / `Ext374B70` / `Cmd374B70`; `func_003758E8` returns int | src/cod/sa_00374b70.c | func_00374B70; matched |
| `BankHdr375988`; `func_003758E8` returns int | src/cod/sa_00375988.c | func_00375988; matched |
| `func_001C28A0` returns int | (batch 83 upgrades) | header item |
| `GetField0OrZero_346828`, `MWSFD_GetPauseBdr`, `SFD_GetCond`, `func_00356F48`, `func_00345750` return int | src/cod/sa_00345f48.c | func_00345F48; matched |
| `func_00366960` returns int | src/cod/sa_00352f40.c | func_00352F40; matched |
| `func_0036A300`, `GetArrayElemA0C_35A1C8` return int | src/cod/sa_003533a8.c | func_003533A8; matched |
| `func_0039AA38`, `viBufAddDMA`, `sfmpvp_PutVibuf` return int | src/cod/sa_nm_003566e8.c | func_003566E8; NM (1 diff) |
| `Vec2F2898` / `Vec4F2898` / `Prm2F2898` / `Act2F2898` | src/cod/sa_002f2898.c | func_002F2898; matched |
| `__eh_info` / `exception_table` / `exception_descriptor` (libgcc2) | src/cod/sa_00320800.c | func_00320800; matched |
| `Sys2CAF28` (mode@0xEE8 on D_003BD930); `cSnd` mix levels cur/target/step[5]@0x60/0x74/0x88 | src/cod/sa_nm_002caf28.c | func_002CAF28; NM |
| `SjIf32D720` / `Sj32D720` / `Adxt32D720` | src/cod/sa_0032d720.c | func_0032D720; matched (NM closer handoff, batch 84) |

## Reviewed at the batch-80 checkpoint

Merged with scripts/sa/header_merge.py (both units rebuilt with identical objects):
- `State76A790` (sa_00377bc8.c) and `Perf76A790` (sa_00375500.c), two views of the 0xC4-byte block at D_0076A790 -> new `include/godhand/sndSys76A790.h` (`SndSys76A790`, size-checked).

Kept local. Each of these has one registered user, or overlaps another view at different offsets or only in NM files. Shared objects to revisit together: `Sel37A0F0` with `SelObj` (sa_0037a020.c) and the D_0076DF10 tables (also in sa_nm_00379f00.c); `Ring339F00` with `Stream38` (sa_003397c8.c); `SjMem3391F8` extending `SjMem` (sa_00339108.c); `Sys12CAE0` as a third view of D_00747A2C next to cE3.h and cSaveLoad.h.

| item | declared in | evidence |
| --- | --- | --- |
| MenuList fields: `short unk04/unk08/unk0A`, second `MenuInfo` at 0x14 (`MenuList384EC8`) | src/cod/sa_00384ec8.c | func_00384EC8 copies list->info (0x4C) into the 0x14 MenuInfo and passes it to func_00380AE8; matched |
| `CamSave2B4428` (camera save block copied as qwords) | src/cod/sa_002b4428.c | func_002B4428 copies it through int w[N] (sn long long is 16 bytes); matched |
| `Sj` / `SjIf` / `SjObj` (CRI stream joint: vtable interface pointer at 0, methods called through it) | src/cod/sa_0036b798.c | func_0036B798; matched |
| `IDWork143998` / `IDObj143998` (cIDBase work: src ptr 0x1C, z 0x3C, layer 0x4F, color 0x84; owner with second ID base at 0xB0 and 16-slot z/color/layer/on arrays at 0x100/0x140/0x1A0/0x1B0) | src/cod/sa_00143998.c | func_00143998; matched |
| `Stream334998` (char state 0x02, pos 0x28, req 0x2C) | src/cod/sa_00334998.c | func_00334998 polls state 2 down; matched |
| `ChList3821D8` / `Ch3821D8` (channel list header at +0x30 with count 0x08 and mixer 0x20; 1-based short vol[] at +4 and u8 mute[] at +0x48) | src/cod/sa_003821d8.c | func_003821D8; matched |
| `Req33FB78` (request: state 0x0C, result 0x10, simple 0x14, args 0x18..0x38) | src/cod/sa_nm_0033fb78.c | func_0033FB78; NM (bne vs bnel) |
| `Img363528` (picture: data 0x04, w 0x08, h 0x0C) | src/cod/sa_nm_00363528.c | func_00363528; NM |
| `PadSlot3977C8` / `PadState3977C8` / `PadRpcBuf3977C8` (libpad: D_0077C110 slot[2][4] of 0x1C bytes from +0x10; D_0077C300 rpc buffer cmd/result/arg) | src/cod/sa_nm_003977c8.c | func_003977C8; NM (store scheduling) |
| `Stream3B9BF0` (CRI stream state machine fields) | src/cod/sa_003b9bf0.c | func_003B9BF0; matched |
| `Adxt32BB98` (ADXT handle: stat 0x01, unk02, sj 0x08, unkAC, dir 0xB0, unkB4, ofst 0xB8, nsct 0xBC) | src/cod/sa_0032bb98.c | func_0032BB98 stores stat, unkAC, unk02 in that order; matched |
| `Slot32F330` (D_003D1E70[4], 0x1964 bytes each) | src/cod/sa_0032f330.c | func_0032F330; matched |
| `Ring339F00` (SJ ring: open 0x04, data 0x0C, free 0x10, freePos 0x14, dataPos 0x18, size 0x20, extra 0x24, err cb 0x38, errArg 0x3C) | src/cod/sa_00339f00.c | func_00339F00; matched. Same object family as `Stream38` in sa_003397c8.c |
| `SjMem3391F8` (SJ memory stream: used 0x04, data 0x0C, free 0x10, base 0x14, size 0x18, cb 0x1C, cbobj 0x20) | src/cod/sa_003391f8.c | func_003391F8; matched. Extends `SjMem` in sa_00339108.c |
| `Adx32CB90` / `Sj32CB90` / `SjIf32CB90` (ADX handle: stat 0x01, sji 0x04, sjo[4] 0x18, eos 0x6C, endOfs 0xC4; SJ vtable getNumData at 0x24) | src/cod/sa_0032cb90.c | func_0032CB90; matched |
| `Cb33BA80` / D_00758620[8][6] (callback table: func, obj, name) | src/cod/sa_0033ba80.c | func_0033BA80; matched |
| `Vec3127B0` (pointer vector: allocator byte, begin, end, cap) | src/cod/sa_003127b0.c | func_003127B0; matched |
| `Sel37A0F0`, `SelEnt37A0F0`, `SelEnt37A0F0b` (column counts at 0x10; 0x20-byte entry tables D_0076DF10/D_0076E510/D_0076EA50) | src/cod/sa_0037a0f0.c | func_0037A0F0; matched. Same object as `SelObj` in sa_0037a020.c |
| `Scr1F5F70`, `StateFn1F5F70` (menu screen state bytes, delay 0x08, bgm 0x24; handler table D_003BF0F8) | src/cod/sa_001f5f70.c | func_001F5F70; matched |
| `Fde322030`, `Cie322030`, `CieInfo322030` (libgcc frame.c fde/cie/cie_info) | src/cod/sa_00322030.c | func_00322030; matched |
| `Ring336110`, `Req336110` (16-entry request ring at 0x38, idx/count/active at 0x20..0x28) | src/cod/sa_00336110.c | func_00336110; matched |
| `Obj304830`, `RotPrm304830` (prm 0x100, angular velocity 0x128; damp/acc at 0x1C0) | src/cod/sa_00304830.c | func_00304830; matched |
| `Mgr331AD8` (stream manager mode byte at 0x01; flags D_003D844C..D_003D8488) | src/cod/sa_00331ad8.c | func_00331AD8; matched |
| `Mwsf3447A8`, `HdrInf3447A8` (0x90-byte Sofdec header info) | src/cod/sa_003447a8.c | func_003447A8; matched |
| `Dec366FE0` (user-data callback at 0xF4/0xF8, data 0xA8, kind 0xB8) | src/cod/sa_00366fe0.c | func_00366FE0; matched |
| `Cmd387328`, `Ch387328` (voice-parameter command, 4 channels at 0x20, mask 0x40) | src/cod/sa_00387328.c | func_00387328; matched |
| `Dmg1FDFD8` (0x60), `Fl1FDFD8` (0x70), `Mgr1FDFD8` (160 + 256 slots, wait at 0xACD0) | src/cod/sa_001fdfd8.c | func_001FDFD8; matched |
| `Mgr331458`, `Req331458` (stream manager mode, request state at 0x02) | src/cod/sa_00331458.c | func_00331458; matched |
| `Ent37B808` (20-byte option entry), `Act37B808` (row/col at 0x27, slots at 0x16C) | src/cod/sa_0037b808.c | func_0037B808; matched |
| `Order1E6ED8` (5-int order), `Scr1E6ED8` (layers at 0x3A0, sel 0x3D8, flags 0x3E8) | src/cod/sa_001e6ed8.c | func_001E6ED8; matched |
| `Ent2BE708` (type at 0x10) | src/cod/sa_002be708.c | func_002BE708; matched |
| `Arena30ECF8` (16-byte arena) | src/cod/sa_0030ecf8.c | func_0030ECF8; matched |
| `Sub35CE60` (entries at 0x8, state at 0x10; at obj+0x2150) | src/cod/sa_0035ce60.c | func_0035CE60; matched |
| `Pl319848`, `Sub319848`, `W319848`, `Bits319848` (7:1 bitfield) | src/cod/sa_00319848.c | func_00319848; matched |
| `Adx32A720` (nch 0x3, sj 0x4, rna 0xC, pan[] 0x42, mode 0xAD) | src/cod/sa_0032a720.c | func_0032A720; matched |
| `Elem` / `Node_003943D0` (list node: elem 0xC, next 0x30; list head at D_003F852C) | src/cod/sa_003943d0.c | func_003943D0; matched |
| `PadVib31BB80`, `PadWork31BB80`, `PadSys31BB80` (pad vibration work and system block) | src/cod/sa_0031bb80.c | func_0031BB80; matched |
| `Dec32ED70` (CRI decoder with buf[] written per branch) | src/cod/sa_0032ed70.c | func_0032ED70; matched |
| `VolEnt3812B0` / `VolSel3812B0` (volume menu entries and selection) | src/cod/sa_003812b0.c | func_003812B0; matched |
| `Name381BC8` {long a; ushort b; uchar c;}, `Sel381BC8`, `Work381BC8` | src/cod/sa_00381bc8.c | func_00381BC8; matched (8-byte field must be `long`, sn long long is 16 bytes) |
| `Sys1F9C98` (cCoreSave system block) | src/cod/sa_001f9cb0.c | cCoreSave_loadStageState; matched |
| `Ent33C7F8` (CRI entry cleared with memset) | src/cod/sa_0033c7f8.c | func_0033C7F8; matched |
| `Blk366EC0` (32-byte block), `Dec366EC0` (cur at 0x28, slot[3] at 0x48) | src/cod/sa_00366ec0.c | func_00366EC0; matched |
| `Mpv36BA50` (MPV header fields 0x360/0x364/0x368 and 0x398) | src/cod/sa_0036ba50.c | func_0036BA50; matched |
| `Sys12CAE0` (D_00747A2C flags word at 0, stage byte at 0x25), `Obj12CAE0` (cGameObj + hitWait 0x15D0, hit work 0x15E0) | src/cod/sa_0012cae0.c | func_0012CAE0; matched. D_00747A2C is also viewed by cE3.h and cSaveLoad.h |

## Reviewed at the batch-70 checkpoint

Nothing merged. The types declared in batches 61-70 each have one registered user:
- `Queue` / `QItem` (16-byte ring queue): sa_00359590.c, plus NM files sa_nm_00359480.c and sa_nm_00359628.c. Wait for the closer before introducing a header.
- `MovMgr` / `MovNode` (sa_002b4960.c) and `MovTrack` (sa_nm_002d3ba8.c) overlap `include/godhand/cMovie.h`, but sa_002b4960.c needs the 0x10/0x14/0x18 fields that cMovie.h keeps as padding. Revisit together with the cMovie methods.
- `DmaEnt` (sa_nm_003b2080.c), `ActObj` / `ActEnt` (sa_0037a740.c), `PicFrm` / `PicReq` (sa_00346ed0.c, overlaps the MwsfdFrm/SfxReq view in sa_00346c58.c at different offsets) all stay local.

## Reviewed at the batch-60 checkpoint

Nothing merged. Every type declared in batches 51-60 has a single user, so each stays local to its file:
- `CamVec3` / `CamQ` / `CamBlock` (camera state copy, 16-byte-aligned 0x360-byte block): sa_00138ca8.c
- g++ 2.x vtable entry `VtEntry {short delta; short index; fn}`: sa_0031ef18.c and sa_nm_0012ec58.c. Every shared header already carries its own copy of this struct (cModel.h, cDamageUnit.h, cPlCamera.h, ...), so no common one was introduced.
- NM-only shapes (`Queue`/`QItem` in sa_nm_00359480.c, `IVec3` in sa_nm_0033b978.c, `Name32` in sa_nm_0035daa0.c, `SpdData` in sa_nm_002c7d20.c): wait for the closer.

## Merged at the batch-50 checkpoint

- MWSF views -> new `include/godhand/mwsfViews.h` (sa_00347908.c, sa_00356e98.c, sa_00345250.c, sa_nm_00345250.c)
- PokerStraightTbl10 / D_0042B4D0 -> `include/godhand/Poker.h`
- EM_* damage-volume constants and `int func_001C28A0(char *p)` -> new `include/godhand/emDamageVol.h`, included by the 30 sa_001932d8 family units and the 5 family NM files. Kept out of the shared enemy headers because phase_a_sn_288.c and phase_a_sn_300.c call func_001C28A0 with 4 arguments.
- PadState / D_007474A0 -> new `include/godhand/padState.h` (sa_00161990.c, sa_nm_00164238.c)
- classFADE struct and prototypes -> existing `include/godhand/classFADE.h` extended (fields named state/otMin/otMax there); classFADE.c and sa_classfade_start.c now include it

Kept local on purpose:
- `cEmActor *cEmSetParam_setEm(cEmSetParam *, unsigned char)`: cEmSetParam.c defines it with a different signature (the merge attempt broke it and was rolled back).
- ArenaEm `cleared` @0xB88 (sa_001f07c0.c): 001f20.c, 001b0d30.c and 0010a2c8.c each define their own ArenaEm.
