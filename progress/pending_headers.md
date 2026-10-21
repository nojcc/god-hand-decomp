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

## Batch 85 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `cp_eh_info.caught` is a word at 0x14 (`int`, sw) and `handlers` is a `long` at 0x20 | src/cod/sa_00321288.c | __start_cp_handler; matched. 00321240.cc still says `bool caught`; do not merge until that TU is rechecked |
| `Mwsf3448B0` stat at 0x2D4; `MWSFSVM_Error` noreturn | src/cod/sa_003448b0.c | func_003448B0; matched. mwsfHn.h declares it with one const char * and not noreturn |
| `Obj341EC0` kind short at 0x9C | src/cod/sa_nm_00341ec0.c | func_00341EC0; NM (bne vs bnel) |
| `Work353348` kind at 0x74 / `Hn353348` work at 0x1FC0 | src/cod/sa_nm_00353348.c | func_00353348; NM |
| `Ent3769B0` (id u16, key at 4, flags at 8, stride 0x40) over D_0076F050 | src/cod/sa_nm_003769b0.c | func_003769B0; NM. 00377e28.c uses a different StructB view of the same block |
| `Slot3B9F60` (word at 0, stride 0x3C) over D_003FC7B8 | src/cod/sa_nm_003b9f60.c | func_003B9F60; NM |

## Batch 86 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `cMovie_Start(char *, int, int)`, `cMovie_GetStatus(char *, int)`, `cMovie_Stop(char *, int)`; movie name `D_005E79D0` | src/cod/sa_0030da08.c | func_0030DA08; matched. `D_00752C00` viewed as `cTaskManager` (sa_nm_0030d1f8.c views it as `cTaskWorkRef`) |

## Batch 87 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `SinCos378` `{float s, c}` over `D_0045A610` | src/cod/sa_003780f8.c | func_003780F8; matched handoff |
| `Dec327418` pending at 0xA0, sj[] at 0x0C, nch at 0x02 | src/cod/sa_00327418.c | func_00327418; matched. Sibling func_00327568 has pending at 0xA4 |
| `Obj32D868` unk1CC at 0x1CC; dead volatile load of `D_00451AC0` | src/cod/sa_nm_0032d868.c | func_0032D868; NM (beql vs beq) |
| `Work47498` sj at 0x17C, buf at 0x180, copy at 0x188, rec at 0x194 | src/cod/sa_nm_00347498.c | func_00347498; NM |
| `Slot48670` stride 0x20 at 0x284; `Obj48670.unk3C` at 0x3C | src/cod/sa_00348670.c | func_00348670; matched |
| `Slot4C3A8` stride 0x74 at 0x1310; on at 0x04, obj at 0x14, totals at 0x30/0x34 | src/cod/sa_nm_0034c3a8.c | func_0034C3A8; NM |
| damage-take pointer at 0x60C (not EM_DMG_TAKE 0x600); child model via byte 0x2B4 and pointer 0x278 | src/cod/sa_nm_0017ac90.c | func_0017AC90; NM |
| state byte at 0x2F6; resource base at 0x304; countdown at 0x5F0 | src/cod/sa_nm_0028a780.c | func_0028A780; NM |

## Batch 92 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `Obj12F600` entries (stride 0x14, flags at 0x10) at 0x14, u16 index array at 0x1C; `Grp12F600` start at 0, three u8 run lengths at 4 | src/cod/sa_0012f600.c | func_0012F600; matched. Caller func_0012F4C8 (0012f4c8.c) passes `void *` |
| `Dtx33A730` spare list at 0x14, `list[4]` at 0x18, cb/cbobj at 0x28/0x2C; node chunk at +8 | src/cod/sa_nm_0033a730.c | func_0033A730; NM. Same object as `DtxObj` in sa_nm_0033abd0.c; `Ck33A730` is the 8-byte chunk that criAix.h passes to func_0033ACA0 as `SjChunk` |
| the 0x2B4 child-model getter keeps an `int[3]` local (a dead stack store in retail) | src/cod/sa_nm_0017ac90.c | func_0017AC90; matched as an NM closer handoff in batch 93 (sa_0017ac90.c) |

## Batch 93-94 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `Vec1DCEF0 {x, y, z, w}` with an inline 4-float setter; globals D_00568150, D_00568160, D_00568170[5], D_005681C0[2] | src/cod/sa_001dcef0.c | func_001DCEF0; matched. Same shape as `Vec1EC928` in sa_001ec928.c (two registered users of one vec4 + setter; candidate for a shared header at the next checkpoint) |
| `Vt173258` g++ vtable entry `{short delta; short index; fn}`; entries at 0x214 + 0x70 (set position) and + 0x80 (get position); timer short at 0xDA0, height float at 0xDA4 | src/cod/sa_00173258.c | func_00173258; matched. Other units carry their own VtEntry copy |
| inline setter for 0x548 / 0x54A / 0x5EC (COL_A, COL_B, then 0x5EC from one value) | src/cod/sa_0016fa80.c | func_0016FA80; matched. The twin sa_nm_0016f790.c should use it too |
| `Hn34AC60` rec at 0x2004, callback table pointer at 0x2114, rec at 0x35A8, ADXT create info at 0x35B0, callback table at 0x365C | src/cod/sa_nm_0034ac60.c | func_0034AC60; NM |
| `Adx33D720` ADX handle: stat 0x04, decoder 0x08, header out 0x68/0x6C/0x70, header cb/obj 0x78/0x7C, end cb/obj 0x80/0x84, end args 0x90/0x94, replay flag 0xE8; `Dec33D720` n 0x10, tables 0x20/0x24 | src/cod/sa_nm_0033d720.c | func_0033D720; NM |
| `SfRing3511F8 {p0, n0, p1, n1}` Sofdec two-part ring view | src/cod/sa_nm_003511f8.c | sfmpv_SearchDelim; NM |
| `Tm360950` = `Tm360B18 {u64 count; u16 last}` tick snapshot at D_00766CA8/CB8; timer globals D_003EEA78..80, D_0045A260/270 | src/cod/sa_00360950.c | func_00360950; matched. Same struct and globals as sa_00360b18.c and sa_00360aa8.c (candidate shared header) |

## Batch 95 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `Vt1AEF40` = `Vt173258` g++ vtable entry; timer short at 0x986, z float at 0x988 | src/cod/sa_001aef40.c | func_001AEF40; matched. Third copy of the VtEntry shape (with sa_00173258.c) |
| `SlotObj1DC980` / `SlotObj1DCAD8` = `SlotObj` (slot[5] at 0x3004) with `SlotRec.card` -> rank at 0x604; `flags` must be `int` (the -5 mask) | src/cod/sa_001dc980.c, src/cod/sa_001dcad8.c | func_001DC980, func_001DCAD8; matched. Same shape as SlotObj in 0015a040.c (whose flags is unsigned; check before merging) |
| `StepObj2B3D70` mode 0xC, state 0xD, flags 0x14 (int), hold 0x2E, wait 0x34, count 0xB2 | src/cod/sa_nm_002b3d70.c | func_002B3D70; NM. Overlaps StepObj in 002b3240.c |
| `Req386DE0` 0x60-byte request (bank 0x0, idx 0x2, sub 0x4, kind 0x6, flags 0xE, sub-record 0x40); `Bank386DE0` 32-byte bank at D_0076E510 | src/cod/sa_nm_00386de0.c | func_00386DE0; NM. Same request as Req386FA0 in sa_00386fa0.c |

## Batch 96 (local, not merged)

| item | declared in | evidence |
| --- | --- | --- |
| `Pack1FF858` pack loader (ents 0x0, count 0xC, data 0x10, name[0x20] 0x19) and 12-byte `PackEnt1FF858`; tolower macro on D_0045F039 | src/cod/sa_nm_001ff858.c | func_001FF858; NM |
| `SfRing354478` = Sofdec ring view, 0x18 bytes (p0, n0, p1, n1 + 8 more); `Sf354478` totals at 0x9A8/0x9B0 (long), SJ at 0x1FC8 | src/cod/sa_00354478.c | func_00354478; matched. sa_nm_003511f8.c declares the same ring as 0x10 bytes |
| `Sf354650` mode 0x38, decoder pointer 0x1FC0, MPV handle 0x23A8 | src/cod/sa_nm_00354650.c | func_00354650; NM |
| `Adxt3B9998` obj->work at 0x4 (work dec 0xC0), nch 0x10, sfreq 0x18 | src/cod/sa_003b9998.c | func_003B9998; matched. Sibling of Adxt336BA8 in sa_00336ba8.c |

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

## Batch 97 (local types)
- File-read history record types (sa_00334f90.c)
- Plane35F418 / Pic35F418 / Buf35F418 / Out35F418 / Src35F418 / Opt35F418 / Sfx35F418 (sa_nm_0035f418.c): SFX picture/output records
- Voice37CF00 (0x20, D_0076C8C0) / Req37CF00 (sa_nm_0037cf00.c): same table as SeqLink in sa_0037c330.c; merge candidate

## Batch 98 (local types)
- SeqCtl37C930 (8 bytes, D_0076B1C0) (sa_0037c930.c): node control flags/owner; D_0076B1C0 is char[] in sa_00375500.c / sa_00377bc8.c; candidate for godhand/seqNode.h
- Menu37E200 / Pad37E200 (sa_0037e200.c): debug menu state and pad trigger/repeat words
- Cre3431D8 (sa_nm_003431d8.c), Work359848 / Info359848 / Aud359848 / Sfd359848 (sa_nm_00359848.c), SfRing351350 (sa_nm_00351350.c, same as SfRing3511F8)
- Ent3066D0 / Own3066D0 / Hnd3066D0 / Vt3066D0 / VtEntry3066D0 (sa_nm_003066d0.c): VtEntry is another copy of the {short delta; fn} vtable slot

## Batch 99 (local types)
- Obj2F40C0 / Sub2F40C0 / Glob2F40C0 (sa_002f40c0.c): reach slot latch; D_005CAFF0 destination floats are written through char* on purpose (keeps the reloads)
- newlib malloc types and struct mallinfo (sa_003acd20.c): same as 003ac090.c / 003aca28.c; candidate for a shared newlib malloc header
- Info36DE80 (sa_nm_0036de80.c)
- sa_001bcfb0.c uses godhand/cOmDoor.h; declares Adjust_theta locally (prototype is in godhand/cCamera.h)

## Batch 100 (local types)
- Xfer332398 / Dma332398 / Hdr332398 (sa_00332398.c): IOP transfer pump; Dma332398 is the sceSifDmaData layout
- Sj36EE90 / SjVt36EE90 / Ck36EE90 / Ch36EE90 / Sfd36EE90 (sa_0036ee90.c): another SJ vtable copy (GetChunk 0x18, PutChunk 0x20)
- Tm34EB98 / Ch34EB98 / Sfd34EB98 (sa_0034eb98.c): SfdChIds +0x8 pointer is unnamed in godhand/sftim.h; candidate field
- Mgr2B4A50 / Ent2B4A50 (sa_nm_002b4a50.c)

## Checkpoint 100 merge
- newlib malloc chunk types + __malloc_av_ -> new `include/godhand/newlibMalloc.h`, included by 003ac090.c, 003aca28.c, sa_003acd20.c (header_merge OK, 3 units identical). D_003FAE00 stays local: 003ac090.c declares it int, sa_003acd20.c as struct mallinfo.

Kept local on purpose:
- `cEmActor *cEmSetParam_setEm(cEmSetParam *, unsigned char)`: cEmSetParam.c defines it with a different signature (the merge attempt broke it and was rolled back).
- ArenaEm `cleared` @0xB88 (sa_001f07c0.c): 001f20.c, 001b0d30.c and 0010a2c8.c each define their own ArenaEm.

## Batch 101

Declared locally (single user each; candidates once a second unit needs them):
- `File332C00` / `FileInfo332C00` (sa_00332c00.c) and `File334520` / `FileInfo334520` / `FileInfoBuf334520` (sa_00334520.c): CRI file handles of two devices; same field roles (used 0x00, sized 0x01, size, sectors) but different layouts, so no shared type yet.
- `Tone376B80`, `Bank376B80`, `Trk376B80`, `Note376B80`, `Voice376B80` (sa_00376b80.c): sequencer tone table D_0076EA50 (0x20 banks of 0x30 tones) and the voice node from func_0037D170; fold into a seq header with the 0x37Cxxx voice code when a second user lands.
- NM-only types (sa_nm_001dcc30.c, sa_nm_001fc810.c, sa_nm_001fff80.c, sa_nm_0028e858.c, sa_nm_0034e9b0.c, sa_nm_00353630.c): stay local until those functions match.

## Batch 102

Declared locally (single user each):
- `Data148420` / `Obj148420` (sa_00148420.c): data header (count u16 at 0x08) and the object that owns the work buffer at 0x408 (flags 0x380, count byte 0x386, data 0x388). Fold in once the 0x1489xx/0x1490xx callers are matched.
- sa_00178618.c reuses `godhand/emDamageVol.h`; no new types. The give-sphere fields 0x46 (short) and 0x4C (int) of the damage unit are raw offsets; name them in the cDamageUnit header when a second user lands.
- NM-only types (sa_nm_00300458.c `PoolObj300458`, sa_nm_0015ada0.c `Quat15ADA0`, sa_nm_002d4c20.c, sa_nm_002d0938.c uses `godhand/cSnd.h`, plus the batch 102 cygnus NM files): stay local until those functions match.

## Batch 103

Declared locally (single user each):
- `Seq377150` / `Voice377150` (sa_nm_00377150.c, NM-only): sequencer channel and voice slots; stay local until the function matches.
- `PathNode1FFA68` / `PathTbl1FFA68` (sa_001ffa68.c): path lookup table nodes (name and child links). Fold in when the other 0x1FFxxx path users are matched.
- `TaskMgr2A5BB8` (sa_002a5bb8.c): system task manager with the resource result at 0x550.
- `CdFile3336F8` / `CdRMode3336F8` (sa_003336f8.c): local copies of libcdvd `sceCdlFILE` (0x24 bytes, `flag` at 0x20) and `sceCdRMode`. Replace with the libcdvd header types once one exists in include/.
- `MfRd3367F8` (sa_003367f8.c): CRI memory-file read handle (stat at 0x01, sector size 0x04, file sectors 0x0C, position 0x10, map 0x1C, request offset/size 0x30/0x34). It parallels `struct HTCI_RD` from 00330318.c; merge the two into one CRI handle header.
- `Sub2F3F30` / `Obj2F3F30` / `Glob2F3F30` (sa_002f3f30.c): the same layout as the `*2F40C0` types in sa_002f40c0.c, plus reach (0x15C / 0x2B8) and slot index bytes (0x18C/0x18D). Merge both into one ReachObj header.
- `FlagCmd2C21A0` / `StageNode2C21A0` (sa_nm_002c21a0.c, NM-only), `Sys30B298` (sa_nm_0030b298.c, NM-only).
- sa_00183650.c and sa_00178368.c reuse `godhand/emDamageVol.h`; no new types.

## Batch 104

Declared locally (single user each):
- `Rd323CF0` / `Sj323CF0` (sa_00323cf0.c): CRI reader with an SJ stream whose vtable destroy slot is at 0xC. Merge with the other CRI SJ users into one header.
- `AdxfPt324640` (sa_00324640.c): ADXF partition table.
- `Req354BD8` / `Req354BD8A` / `Req354BD8B` / `Req354BD8C` (sa_00354bd8.c).
- `GameWork1BF8C8` (sa_001bf8c8.c) and `GameWork2BF568` (sa_002bf568.c): more `D_007474A0` fields beyond `godhand/gameWork.h`: 0x5B4 effect id (u16), 0x5E4/0x5E8 flag words. Move into gameWork.h; sa_002bf568.c also needs `D_007474A0` itself (not a member pointer) so the 0x5E4 anchor stays.
- `Alarm3B6C28` / `TimerCtl3B6C28` (sa_003b6c28.c): libkernel alarm node and timer control. 003b6a30.c already has `TimerCounter` / `TimerCtl` for the same objects with fewer fields (no head 0x18 / handling 0x1C). Merge into one libkernel timer header.
- `SplHdr2AC6E0` / `Spl2AC6E0` (sa_002ac6e0.c): Catmull-Rom path (points 0x00, header 0x1C with point count 0x6E, length 0x9C). It is shared with the NM sibling sa_nm_002ac878.c.
- `Obj30F090` / `VEnt30F090` / `ObjVec30F090` (sa_0030f090.c): the object list `D_00754C30` (vector begin/end at 0x4/0x8) and the gcc-2.95 vtable entry (delta, index, fn). 001d0090.c reads the same vector through raw offsets.
- `Strm32E488` (sa_0032e488.c): CRI stream frame state (mode 0x1AC, loop/seek 0x1B0/0x1B1, frame 0x1BC, loop range 0x1C4/0x1C8, next callback 0x270/0x274).
- `LineTab333560` (sa_00333560.c): the text line table `D_003D9DC0`.
- `Voice37CAE0` / `Seq37CAE0` / `SndStat37CAE0` (sa_0037cae0.c): the sound voice array `D_0076CF20` (51 x 0x50), the sequence array `D_0076A600` (stride 0x84) and the counters at `D_0076A790`+0x24. Fold into the 0x37Cxxx voice header together with `Voice376B80` (batch 101).
- sa_0017e4c8.c and sa_0019dfb8.c add no new types (sa_0019dfb8.c uses `godhand/emDamageVol.h`).
- NM-only types (sa_nm_00159300.c `Key159300` / `Curve159300`, sa_nm_00325638.c `TPrm` / `TCur` / `ThreadStat325638`, sa_nm_00333880.c `CdCfg333880`, sa_nm_0037d3c8.c `SndGlob` / `Voice37D3C8`, sa_nm_00382660.c `Sel` / `Mix382660`): stay local until those functions match.

## Batch 105

Declared locally (single user each):
- `Body135040` / `Push135040` (sa_00135040.c): collision body and push-out result.
- `PhaseEnt181118` / `PhaseTable181118` / `Hit181118` (sa_00181118.c) and `PhaseEnt1AF098` / `PhaseTable1AF098` (sa_001af098.c): the same enemy phase table (PMF entries) in two enemies. Merge into one enemy phase header.
- `Vec30FCC0` / `List30FCC0` (sa_0030fcc0.c): cScrArray vector (begin/end/cap).
- `SjCk3398F8` / `SjRbf3398F8` (sa_003398f8.c): CRI SJRBF ring buffer object and chunk. Merge with the other SJ chunk/vtable copies (`SjCk32B888`/`Sj32B888`/`SjIf32B888` in sa_nm_0032b888.c, `SjCk327568` family, `Rd323CF0`/`Sj323CF0`) into one CRI SJ header.
- `Strm34A818` (sa_0034a818.c): MPV handle (sub-block at 0x1020).
- `Part1617C8` / `Obj1617C8` (sa_001617c8.c): model part list (15 part pointers at 0x80, selected index at 0xBC, hide bit 0x08000000 in part flags 0x2C).
- `Hn332EA0` (sa_00332ea0.c): CRI CD file handle (stat 0x02, file size/offset 0x08/0x0C, request/read sectors 0x10/0x14, buf 0x18, srd 0x1C, top lsn 0x20, read mode 0x44). Same object as `MfRd3367F8` and `struct HTCI_RD`; merge into the CRI handle header.
- `Snd381F18` / `Obj381F18` / `Pad381F18` (sa_00381f18.c) and `Snd383878` / `Obj383878` / `Pad383878` (sa_00383878.c): sound option blocks (slot byte, level and index arrays) at 0x318 and 0x370 with differently placed slot fields, and the pad state (hold 0x2C, trigger 0x38). The pad struct should become one shared pad header.
- sa_00178b20.c and sa_00187a78.c reuse `godhand/emDamageVol.h`; sa_001b67d0.c and sa_0033b218.c add no shared types.
- NM-only types (sa_nm_00332178.c `DtxRmt332178`, sa_nm_003356b0.c `Req3356B0` / `ReqQ3356B0`, sa_nm_00373ba8.c `Strm373BA8`, sa_nm_00150dc8.c `TI150DC8` / `u64_150DC8`, sa_nm_0032b888.c `Enc32B888` and SJ copies): stay local until those functions match.

## Batch 106

Declared locally (single user each):
- `Quat15A3E8` / `Euler15A3E8` (sa_0015a3e8.c): quaternion (x, y, z, w) and XYZ Euler triple. Move next to the other Quaternion_* helpers once they share a header.
- `Model2988A8` (sa_002988a8.c): model id at 0x2FE.
- `GameWork2A4970` (sa_002a4970.c): more `D_007474A0` fields beyond `godhand/gameWork.h`: 0x558 data pack, 0x56C language. `Font2A4970`: font pending count at 0x2A08C. Move the game work fields into gameWork.h.
- `Move` (sa_0030eee8.c): declares its globals as char arrays and void pointers only; no types.
- sa_001a47f8.c uses raw `char *` offsets like its sibling sa_0017e4c8.c; no new types.
- sa_0033c548.c and sa_0036cf30.c: globals only (`D_00456080` key tables, the `D_003F1FF0` M2V interface table typed as `Fn36CF30`).
- NM-only types (sa_nm_001fb330.c `Item1FB330` / `SaveData1FB330` / `CoreSave1FB330` / `ItemObj1FB330` / `VtEnt1FB330`, sa_nm_0013e0b0.c `Obj13E0B0` / `Sub13E0B0` / `Work13E0B0`, sa_nm_001aa510.c `PhaseEnt1AA510` / `PhaseTable1AA510`, sa_nm_002fb310.c `Obj2FB310` / `VEnt2FB310` / `GameWork2FB310`, sa_nm_0037e4c0.c `Menu37E4C0` / `List37E4C0` / `Pad37E4C0`): stay local until those functions match.

## Batch 107

Declared locally (single user each):
- `Em28AC58` (sa_0028ac58.c): enemy model fields (flags 0x254, id 0x2FE, data pack 0x304, kind 0x564, texture-variant flags 0x155C). Fold into the cEm00 header with the other enemy offsets.
- `Info34ADB8` / `Req34ADB8` (sa_0034adb8.c): SFD stream info block (`D_00760D90`, 7 ints) and stream request; same info type as `Info34B198` in sa_0034b198.c. Merge into the SFD header.
- `Size353098` / `Cfg353098` / `Mgr353098` / `Hn353098` (sa_00353098.c): M2V frame config and frame-buffer manager (handle +0x1FC0, mode +0x38).
- `SJ338` / `SJVt338` / `Ck338` / `Ch338` / `Obj338` (sa_00338478.c): another CRI SJ interface copy (getChunk 0x18, putChunk 0x20, getNum 0x24) plus the ADX channel object. Merge with the SJ copies listed in batch 105.
- NM-only types (sa_nm_00291b90.c `AngerEm` / `AngerEmNode` / `AngerVtEnt`, sa_nm_002a6ff8.c `LinkTbl2A6` / `LinkEnt2A6` / `Obj2A6`, sa_nm_00334310.c `FileInfo334`, sa_nm_00350f48.c `Ring350` / `Code350`): stay local until those functions match.

## Batch 108

Declared locally (single user each):
- `EfPart145FC8` / `EfSlot145FC8` / `Ef145FC8` (sa_00145fc8.c): effect part/slot fade-scale records. Merge into the effect header.
- `Elem394668` / `Node394668` (sa_00394668.c): symbol table element and node used by the resolver. Merge with the other symbol-table copies near 0x393xxx.
- `Ck36B888` / `Sj36B888` / `SjVt36B888` / `Ch36B888` / `Sfd36B888` (sa_0036b888.c): another CRI SJ interface copy plus the SFD channel table (cur 0x3B8, ch[4] 0x3BC, capture 0x3EC..0x3F4). Same layout as the `Sj36EE90` copy in sa_0036ee90.c; merge into the SFD header.
- sa_001a49a8.c and sa_001ab730.c use raw offsets only (gimmick object 0x2F4..0x2F7 step bytes, 0x304 pack, 0x608 damage unit, 0x9D0 flags).
- NM-only types (sa_nm_0039b960.c `Ch3` / `cbp`): stay local until that function matches.

## Batch 109

Declared locally (single user each):
- `PhaseEnt1AC980` / `PhaseTable1AC980` / `Hit1AC980` (sa_001ac980.c): the same phase-table and hit-record layouts as `PhaseEnt181118` / `Hit181118` in sa_00181118.c. Merge into one gimmick/enemy phase header.
- sa_001680d8.c, sa_0017e2f8.c, sa_00382d30.c use raw offsets (menu panel 0x5A..0x91; gimmick 0x2F4..0x610; menu page 0x370 work).
- sa_0030f348.c: `D_00754250` (mt[624]), `D_003C3D08` (mti), `D_003C3D10` (mag01[2]) are the Mersenne Twister state; give them names in a small mt19937 header with func_0030F2B0 (init_genrand).
- NM-only (sa_nm_00141b18.c, sa_nm_00148d30.c, sa_nm_0029fde0.c): no new types (0029fde0 reuses the GS_SET_* macros from 002a02d0.c locally).

## Batch 110

Declared locally (single user each):
- `Adxt3298F0` / `Sj3298F0` / `SjVt3298F0` (sa_003298f0.c, cygnus): the ADXT handle and the SJ stream object with its method table. They belong with the other CRI ADX/SJ layouts in the 0x31DA48-0x36F048 band.
- `FdeFS` / `CieInfoFS` / `FrameStateFS` (aligned 8, size 0x2F0, retaddr_column at 0x29A) / `FrameStateInternalFS` (sa_00322570.c, ee-2.9): libgcc frame.c `struct frame_state` and its helpers. The other frame.c TUs near 0x3220xx-0x3226xx should share one header.
- MERGED at checkpoint 110: `PhaseEnt281968` / `PhaseEnt278390` / `PhaseEnt1AF098` / `PhaseEnt1AC980` / `PhaseEnt181118` (and their `PhaseTable*` wrappers) are now `EmPhaseEnt` / `EmPhaseTable` in `include/godhand/emPhaseTable.h` (sa_00181118.c, sa_001ac980.c, sa_001af098.c, sa_00278390.c, sa_00281968.c; header_merge OK, 5 units identical).
- `EmList2DB0D0` (sa_002db0d0.c): the enemy list at `D_00754C30` (begin at 0x04, end at 0x08). It probably matches the enemy manager vector in enemy/cEmManage.c.
- `sceDmaEnv` (sa_00397208.c): the SDK libdma environment struct (0x14 bytes). It should come from the SDK `libdma.h` in include/sce if one is added.
- sa_00192d20.c uses `godhand/emDamageVol.h` (no new types). The new installs sa_00281968.c and sa_00278390.c use raw enemy work offsets.
- NM-only: `File38F200` (sa_nm_0038f200.c), `SndChan3090F8` (sa_nm_003090f8.c, 0xB0 sound channel record at `D_00747BA0`), `LineAttrSc` (sa_nm_0015f0b8.c, Gp_draw_line attribute block); sa_nm_0035cc80.c and sa_nm_003b0ef8.c use raw offsets.

## Batch 111

Declared locally (single user each):
- `Ck327048` / `OBJ` / `OVT` / `SJD` (sa_00327048.c, cygnus): the ADX SJ decoder handle (in SJ at 0x08, out SJs at 0x0C, chunks at 0x14 and 0x1C, counters 0x2C..0x44, callback 0x50/0x54). It extends the `struct SJD` in 00327230.c; merge both with the CRI SJ layouts in the 0x31DA48-0x36F048 band.
- sa_001643f8.c reuses `godhand/padState.h` and reads game work 0x584 / 0x5B0 through raw offsets from `D_007474A0` (same as func_00163F00 and func_00164238).
- NM-only: `ObjVec30F8B0` (sa_nm_0030f8b0.c, the object vector at `D_00754C30`, same layout as `EmList2DB0D0`), `Vec283C70` / `Ent283C70` (sa_nm_00283c70.c, 0x30 light entries at `D_00585660`), `Sel383F50` / `Mix383F50` (sa_nm_00383f50.c, the same mixer layout as `Mix382660`).

## Batch 112

Declared locally (single user each):
- sa_001c9860.c and sa_0027f1b0.c use `godhand/emPhaseTable.h` (`D_003BDE88`, `D_003BFE98`) with raw enemy/gimmick work offsets; no new types.
- sa_001da910.c uses `godhand/padState.h`; the two-choice panel work (step 0x3025, choice 0x3040/0x3044, PanelObj at 0x25B0) uses raw offsets.
- sa_00114ac0.c uses raw offsets only (walk target 0x580, last position 0x1590, stall counter 0x15B4).
- NM-only: `Part13C318` / `Obj13C318` (sa_nm_0013c318.c, part flags 0x2C and part[4] at 0x98); `struct sph` (sa_nm_00277348.c, the same 16-byte sphere as in 0027de60.c and 00278110.c).

## Batch 113

Declared locally (single user each):
- `Slot3547B0` / `Hn3547B0` / `Def24` / `Def8` / `Def40` (sa_003547b0.c, cygnus): a handle with 16 slots of 0xF0 at 0x180, a buffer at +0x54 and ent[16][8] at 0x109C. It belongs with the CRI layouts in the 0x31DA48-0x36F048 band.
- `ColiWave6` (sa_001f1918.c): the coliseum battle work (enemyNum 0xB8C, phase 0xB94, six waiting entries at 0xC64). It is the same object as `ColiseumBattle` in `godhand/ColiseumBattle.h`; fold the 0xC64 array into that header.
- sa_00151168.c uses raw offsets for the GS upload packet list (count at 0x3C, 0x180 slots double-buffered by 0xC0) and a local `u64_151168` typedef.
- NM-only: `Vec4` / `Plane12D1A8` (sa_nm_0012d1a8.c); sa_nm_00150f68.c uses the same raw packet layout as sa_00151168.c.

## Batch 114

Declared locally (single user each):
- `Pt2006B8` / `Obj2006B8` / `StartPt2006B8` (sa_002006b8.c): a saved stage point (cur at 0x04, save at 0x1C, 0x18 bytes each; step 0x39, busy 0x3A) and the 16-byte start-point table `D_00583F00` with its angle table `D_003BF198`. `D_00747A2C` is used as `int[]` with fields at [-2], [3] and +0x24; it is the same game-work block as `D_00747A24` / `D_00747A50`, which should become one struct in a header.
- `Ck32CC90` / `OVT` / `OBJ` / `Hn32CC90` (sa_0032cc90.c, cygnus) and `Ck36A3E8` / `Dec36A3E8` (sa_0036a3e8.c, cygnus): the CRI SJ chunk and the SJ interface table (getChunk 0x18, ungetChunk 0x1C, putChunk 0x20, getNum 0x24). They match `Ck327048` / `OVT` in sa_00327048.c; one shared SJ header for the 0x31DA48-0x36F048 band should replace all of them.
- sa_0017b0d8.c uses raw gimmick offsets, the same as sa_001a47f8.c / sa_001a49a8.c.
- NM-only: `RpcPkt3B3650` / `RpcReq3B3650` / `DmaT3B3650` (sa_nm_003b3650.c, SIF RPC packet and sceSifDmaData); `FsCd3B3F50` / `FsFd3B3F50` / `FsPoff3B3F50` / `FsBuf3B3F50` (sa_nm_003b3f50.c, fileio client data); `EmVt` / `EmVtEnt` / `Emitter` / `EmOwner` (sa_nm_00300628.c, emitter slot with its vtable at 0xF0); `Ent37BC90` (sa_nm_0037bc90.c); `Bound12DCB8` (sa_nm_0012dcb8.c, uses `godhand/cOmBase.h`); `Cnt36DFF0` (sa_nm_0036dff0.c); sa_nm_00354ec8.c uses raw offsets.

## Batch 115

Declared locally (single user each):
- `Cam1538F0` (sa_001538f0.c): camera view matrix at 0x40 and fov at 0x250; it is the camera block behind `D_005CAFF0` and belongs in the camera header once one exists.
- `struct _reent` (sa_003a9018.c): only `_errno` at 0; a libc header with the newlib `_reent` layout should replace it. `D_0045F039` is newlib `_ctype_ + 1`; it is also used by sa_002be240.c.
- `UvCh` / `Obj13EE58` (sa_0013ee58.c): two UV-scroll channels at 0x90 (16 bytes each), fade values at 0xB0/0xB4/0xB8 and an index at 0xBE.
- `PackEnt` / `PackHdr` / `DmaReq` / `Obj2BE240` (sa_002be240.c): the resident file archive (count at 8, 0x20-byte entries at 0x10 with name, offset, size) hung off 0x4C0, and the sceSifDmaData request. `DmaReq` duplicates `sceSifDmaData` from the SDK headers; switch to that once include/sce exposes it.
- sa_001b90d0.c uses raw enemy offsets (damage-give units at 0x600/0x608 and their results at 0x604/0x60C), the same as sa_0019bf10.c.
- NM-only: `MovSt` / `MovHdr` (sa_nm_003563b8.c and sa_nm_00356c68.c, Sofdec movie state at work + 0x1128); the `SWAP16` / `SWAP16B` / `GET32` macros and `Sint*` typedefs repeated in sa_nm_0033ee30.c (same as 0033e8a0.c; one ADX header should hold them); sa_nm_001c3988.c and sa_nm_0035a2b0.c use raw offsets.

## Batch 116

Declared locally (single user each unless noted):
- `vec4_eq` / `vec4_ne` (sa_001c0450.c and sa_001b76d8.c): the 4-float compare `if (a[0] != b[0] || ...) return 0; return 1;` wrapped as `vec4_eq(a, b) ^ 1`. Both are the same object class (state bits at 0x5B0 / 0x5B8, position at 0x490 vs `*(0xF0)`, rotation at 0x5D0 vs 0x100). One shared inline header for this vector type should hold them, plus the guarded 3-float copy `vec3_copy` from sa_001b76d8.c.
- `VtEnt` (sa_001c0450.c): {short delta; short pad; fn} vtable entries off 0x214; it is the same layout as the `EmVtEnt` / `EspVtEnt` copies.
- `SndGroupEnt` / `SndSetting` (sa_nm_002cabe8.c, NM-only): the 0x18-byte sound-group table at `D_0044CCC0` (bank at 0, alt bank at 0xC) and the stage sound setting record (version float at 4 = 1.1, sub-heap size at 0xC, group at 0x10).
- sa_00384ca0.c uses raw offsets, the same as sa_00382d30.c (menu page work at 0x470 / 0x484); they are the same page family and should share a struct.
- sa_0017ef98.c uses raw offsets (state byte 0x2F5, timers 0x604 / 0x608, angle 0x100).
- NM-only: `Esp` / `EspVt` / `EspOwner` (sa_nm_002fb0e8.c), the effect-slot twin of MoveEmitter's `Emitter`; sa_nm_0019af80.c, sa_nm_002ac9b8.c and sa_nm_00159da0.c use raw offsets.

## Batch 117

Declared locally (single user each):
- sa_00294f70.c uses a `game()` accessor for `D_007474A0` (stage id at 0x5B0 as u16, area at 0x5B1) and a `load_se` helper over `cDataManager_loadWait` / `cDataManager_loadSeWait`; the same game-work block should become one struct in a header.
- sa_00276228.c uses a guarded `vec3_copy`, the same as sa_001b76d8.c (see batch 116).
- sa_002b8b50.c uses raw offsets.
- NM-only: `WavFmt` (sa_nm_0033dd78.c, RIFF fmt chunk); `SfCprm` / `SfHn` (sa_nm_00358368.c, Sofdec create parameters and handle); `CurveKey` / `CurveData` / `CurveHdr` (sa_nm_00158fc8.c, Hermite key curve); `MpvCur` (sa_nm_00350d08.c, Sofdec MPV ring cursor with two spans {top, len}); sa_nm_002d34a8.c uses raw stream-buffer offsets (slot state at 0x10, dma ids at 0x60, buffers at 0x84, busy 0x8C, size 0x90).

## Batch 118

Declared locally (single user each):
- sa_003808a0.c follows sa_00384ca0.c (menu page records of 0x48 bytes after a header byte at +5).
- sa_0037bf10.c uses raw offsets for the voice-slot table at D_0076CEC0 (stride 0x20).
- NM-only: `PVec` / `VEntry` (sa_nm_0030f650.c: an STL vector {pad, begin, end} for the object lists D_00754C30/38/50/58, and a GCC 2.x vtable entry {short delta; short idx; fn}); sa_nm_0027bb78.c uses `EmPhaseTable` from godhand/emPhaseTable.h like sa_0027f1b0.c; the other batch-118 NM files use raw offsets.

## Batch 119

Declared locally (single user each):
- sa_001a5208.c uses raw offsets and a `char buf[0x20]` stack area; `VEntry` (GCC 2.x vtable entry {short delta; short idx; fn}) is declared locally again here, so it should move to a shared header alongside the one in sa_nm_0030f650.c.
- sa_0017b2e0.c follows sa_0017b0d8.c (gimmick state bytes 0x2F4..0x2F7, timer 0x604, movers at 0x610/0x770).
- sa_001b57e8.c follows 0018a680.c (f[16] stack block, part flag loop) and uses an inline vtable slot-8 call typed `int (*)(char *)`.
- NM-only: `Sorter` / `Heap` / `Elem` (sa_nm_00321ad0.c, a heap sorter {ret, base, {arr, n}} over elements keyed at +8); `Spr` (sa_nm_002d4340.c, sprite DMA source: packets at 0xC/0x10, tex 0x18, h/w 0x1C/0x1E, rect 0x20..0x26, fmt 0x28); sa_nm_0033ebd0.c reuses the ADX SWAP16/SWAP32 macros from 0033ea98.c; sa_nm_001a5540.c and sa_nm_0034a0f0.c use raw offsets.

## Batch 120

Declared locally (single user each):
- sa_003092e0.c declares `TexHdr` (texture header: dataOfs 0xC, nlevels 0x11, fmt 0x13, w/h 0x14/0x16, tex0 0x18, mip1 0x30, mip2 0x38, mipOfs[] 0x40) with a GS TEX0 `unsigned long` bitfield (TBP0:14, TBW:6, PSM:6, TW:4, TH:4, TCC:1, ...); a shared GS register header would be the natural home.
- sa_002e6868.c declares `ObjFlags` (unsigned char bitfield at obj+0x2DC), `Vec3`, and the `F`/`MOT` macros and the `notGround`/`linkOn`/`vcopy` inlines, all duplicated from sa_nm_002f48a8.c; they should move to a shared object header once 2F48A8 is solved.
- NM-only: `WL` (sa_nm_00291d48.c, stage light list D_00754C38); `GameWork` plus the GFLAGS anchor macro (sa_nm_0030b420.c, D_007474A0 + 0x584/0x588/0x5A0); `MotReq` plus `MREQ_AB` (sa_nm_001034e0.c); `SifCmdData` / `SifCmdPkt` (sa_nm_003b21d0.c, should eventually come from the SDK sif headers); `Ent` {short key; unsigned short val;}[64] ring at +0x11E0 (sa_nm_00352298.c); sa_nm_0036ae70.c uses LOADW/GETBIT1 bit-reader macros like 00372590.c.

## Batch 121

Declared locally (single user each):
- sa_003b4220.c declares `OpenPkt` (SIF open packet at D_0077FFC0: sema, dst, size, flags, mode, name[0x400], unit) next to the `Iob` / `SemaParam` copies that 003b44b0.c, 003b52f0.c, 003b53b8.c and 003b5520.c each declare; one libio/iob header should hold `Iob`, `SemaParam` and the packet types.
- sa_00322c68.c declares `AdxfLd` (ADXF load record: f0, f8, fE/fF bytes, name[0x100] at 0x10, f110, f114; 0x11C bytes).
- sa_00160ff0.c reads game flags 0x5D8 / 0x5E0 through anchor macros on D_007474A0 (same idiom as sa_nm_0030b420.c).
- sa_00312b00.c uses raw object offsets (serial 0x2FC, data id 0x2FE, id 0x300, data 0x304, buffer 0x2C8, flags 0x250).
- NM-only: `DbgEnt` (sa_nm_00379910.c, debug menu entry {val ptr, type 8, kind 9, shorts A..10}, 0x14 bytes); `Hn32D430` (sa_nm_0032d430.c, CRI handle 0x278 bytes); sa_nm_00345848.c uses raw externs.

## Batch 122

Declared locally (single user each):
- sa_003514b8.c declares `Sf3514Stm` (Sofdec stream state: mode 0x78, flag 0x170) and full prototypes for the sfmpv_/SFCON_ helpers it calls; a shared Sofdec header would collect these.
- sa_0017dcb8.c declares `cOl21S` (shape handles at 0x654/0x664/0x674) and a `vset` inline; the handles belong in godhand/cOl21.h once the TU merges.
- sa_00337728.c declares the DTX globals (D_003E0708..D_003E31B0) as raw externs.
- sa_002c0f90.c declares `AtUnit` (0x9C bytes, f36 u16, f39 type), `AtHdr` {ver 4, count 6}, `AtMgr` (four hdr/unit pairs, lists[16] at 0x20, 0x60..0x70) and the `worldPack` inline (D_007474A0 + 0x5AC, same field as WORLD_PACK in 001b81a8.c).
- sa_00275da8.c reuses `struct sph` from 0027ef10.c.
- NM-only: `WritePkt` (sa_nm_003b4ad8.c, SIF write packet, belongs with the libio header noted under batch 121); `Obj10B2`/`Slot10B2` (sa_nm_0010b2e8.c); `MpsWk` (sa_nm_0034e4b0.c, mps handle 0, pos 0x158); `Key158`/`Curve158`/`Hdr158` (sa_nm_00158cd0.c, Hermite key curve, shares `I4` with sa_nm_00159da0.c).

## Batch 123

Declared locally (single user each):
- sa_002b1c80.c declares `Mess2B1` (message draw state: flags 0x14, scale 0x54/0x58, offset 0x5C/0x5E, body/rubyTop/bodyEnd/ruby u16 pointers at 0x74..0x80, kind 0xA4, pos 0xAE/0xB0) and prototypes for the cMessDrawFont_* setters on D_005E7510; these belong in a cMessDrawFont header.
- sa_001e1d10.c declares `Ent1E1`/`Tbl1E1` (9-entry {a,b,c} combo table at D_0042B758) and `Obj1E1` (slot arrays at 0x100/0x208/0x310, kind u16 0x48E, result 0x494).
- sa_001ec088.c declares `Part1EC` (rot float 0x104, pos 0x100) and `Obj1EC` (flags 0x54, parts[10] at 0x1C4) plus flagGet/flagSet/flagClr inlines on the 0x54 word.
- NM-only: `Om180` (sa_nm_00180cd8.c, hp 0x54A / max 0x548); `PadSt`/`PadRaw`/`Mask64` (sa_nm_0031afe0.c, pad state; same module as 0031b410.c); sa_nm_00326890.c uses raw offsets on the CRI stream object (vtable 0x18/0x1C/0x20).

## Batch 124

Declared locally (single user each):
- sa_00355f88.c declares `IpuFifo` (IPU FIFO DMA state: base/phys/n/idx/count, cur 0x1C, tag); belongs with the libmpeg/IPU header.
- NM-only: `InitArg` (sa_nm_0028e0e0.c, object init args: pos 0x10, f20..f2C, c30/c31, copied to self+0x1510) uses godhand/cCoreSave.h for the D_00569B70 flags; `ComboBlk`/`SkillBlk`/`Reel10`/`Kill5` (sa_nm_002bf948.c, save snapshot blocks; belong in cCoreSave.h); `PadSt`/`PadEv` (sa_nm_00337400.c, CRI pad event queue, 0x64-byte state, id void* 0x20); sa_nm_00276f18.c `V4`/light entry table; sa_nm_002d6a60.c LightData records; sa_nm_001f20f8.c raw spawn buffers.

## Batch 125

Declared locally (single user each):
- sa_00144c90.c declares `Obj144`/`E144`/`IdW144` (ID work table: per-entry vec and tbl[i][0] pointers); belongs with the CustomID header.
- sa_00351cb0.c declares `MpvCb` (Sofdec MPV header callback/obj block, hdr[6], field 0x70); belongs with the Sofdec/MPV header.
- sa_0033fdc0.c declares `Buf33F` (addr char*, len), `Strm33F`/`StrmVt33F` (stream vtable: get 0x18, put 0x1C, reset 0x20) and `Xfer33F` (active/busy, src/dst streams, cur0/cur1, dma[5] 0x1C, unit 0x38, total 0x3C); belongs with the CRI stream header. Keep addr as a pointer type (it affects scheduling).
- NM-only: CidColor family in sa_nm_001f2d60.c (shares layout with sa_nm_001f3118.c).

## Batch 126

Declared locally (single user each):
- sa_002d3d88.c declares `Mv2D3`/`Img2D3`/`ImgHdr2D3` (movie player work and image header); belongs with the movie/Sofdec player header.
- sa_00141ce8.c uses WK/FL offset macros on the HUD panel work; no new struct.
- sa_00326cb8.c declares `Hn326C`/`OBJ326C`/`Ck326C` (CRI handle with chunk count at ck.f4); belongs with the CRI handle header. Leave the loop bound as a field read.
- NM-only: `Pg37B`/`Ent37B`/`Row37B`/`Quad37B` (sa_nm_0037b918.c, debug page), `Iob4D98`/`Pkt4D98` (sa_nm_003b4d98.c), `Bb149` (sa_nm_00149738.c, 0x20 bbox, used with godhand/cModel.h), `Cprm343`/`Ply343` (sa_nm_00343e28.c, Sofdec player 0x304 slots x8).

## Batch 127

Declared locally (single user each):
- 00137e70.c declares `PathRec` (cone angle float 0x60) and `PathHost` (rec pointer 0x30); the matched PathHost_calcTurn in 00137cb8.c declares the same two types (PathRec endY 0x38, kind 0x3F, dir 0x50; PathHost startY 0x10). Merge both into one path header with coneAngle at 0x60.
- NM-only: `cCollUnit` (00134cb0.c and 001346c8.c: owner cOmBase* 0x00, priority 0x08, share float 0x0C, next 0x10) and `cCollUnitList` (head, count). The matched cCollisionSolidManage_CreateUnit in 001346f8.c declares the same layout as `Unit`/`Mgr`, and func_00134430 stores the owner as int. These belong in a cCollisionSolidManage header with the owner typed as `cOmBase *`.
- NM-only: `CollOBB` (00137670.c, oriented box: center 0x00, axis[3] 0x10, halfLen[3] 0x50).

Conflicts to resolve at the checkpoint:
- D_005CAFF0: reachObj.h declares `extern PlayerReach *D_005CAFF0;`, while cCamManager.h and several TUs (001334a8.c's screen matrix use) treat it as the current camera. One declaration should win.
- cEm00.h types 0x640 as `unsigned short entryNo`, but the 0x10xxxx step code (0010cd38.c) reads it as a pointer.
- D_003BD880 is declared four ways (`float[]`, `const float[4]`, `char[]`, `cObjSimpleVec3`); it is a 16-byte vector.

## Batch 128

Declared locally (single user each):
- 001399a0.c declares `cFollowCamera` (cCamera base, view `CamView *` 0x360 with its matrix at 0x80, tgtSrc 0x364, eyeSrc 0x368) and `CamNode` (position 0x30, angle 0x104). Belongs in cCamera.h or a follow-camera header. It also declares `func_001F8080(cVec *out, float angle)` from the retail registers; the only C body of func_001F8080 is an unregistered m2c draft that takes just the float.
- NM-only: `cCollisionSolidPt` (00135040.c, point at 0x180 after the 0x74-byte solid and 0x10C padding), `cCollisionSolidBox` (00134e18.c, box at 0x180), `cCollisionBox` (00133bc8.c: flags int 0x00, min/max, parent matrix 0x40, pos 0x50, local[8] 0x70, world[8] 0xF0, radius 0x170, center 0x180, mtx 0x190), `cCollGrid`/`cCollCell` (001321d8.c: cells 0x18, index 0x1C, dims 0x64/0x68, cell range 0x6C..0x80, probe pos 0x100, radius 0x110, result 0x120, mask 0x174, hitInfo 0x17C, hit 0x180; cell = first index u32, count[3] u8). These belong in a collision header next to cCollisionSolid.h.
- NM-only: 0013b5f0.c reads the right stick at GameWork 0x1F2/0x1F3 (signed char) through a raw offset; add `signed char stickRX, stickRY` at 0x1F2 to GameWork in gameWork.h. It also uses `PlState` (64-bit state word at 0x2F0), the same view that 0012bb38.c declares as `FxObj.stateWord`.

Conflicts to resolve at the checkpoint:
- cIDBaseEnt.flags (0x2C) is `unsigned int`, but func_0013BD40 (skipped: jump table) builds `flags & ~IDENT_FLAG_CHILD` as `addiu -9`, which sn only emits for a signed int field. Check whether the field should be `int` before matching that function; the draft is build/scratch/0013bd40_best.c.
- 0013bc28.c declares the same id set object locally as `IdSet` (`IdWork *work[13]` at 0xB0, x/y 0xA0, unkE4); the elements are cIDBaseEnt. Use one type, with flags 0x94 and step 0x95.

## Batch 129

Declared locally (single user each):
- 002998a0.c declares `GsPktCtx` (packet buffer 0x10000, cur `GsAdFloat *` 0x10000, num 0x10010) and `GsAdFloat` (s, t floats, 64-bit address). Belongs with the GS packet header.
- 00305e88.c declares `cFxOnce` (started bit mask at 0x414) and a `cVec_set4` inline (x, y, z, w). The inline belongs in the cVec header next to `cVec_copy3`.
- 00279d88.c declares `EmPlace` (the 0x40 placement record func_0028EBF0 reads: pos 0x10, rot 0x20, unk31 0xFF) and uses offset macros on cEm00 for fields cEm00.h does not name: ik 0x448, signed char 0x531 (-1 for none, cGameObj.h names it unk531), unsigned char 0x616, float 0x1564, int 0x1568, int 0x1584 beside `target`. Add them to cEm00.h. The NM draft 0028ebf0.c declares the same record as `PartSrc`.
- NM-only: `cEmLinked` (00276dc8.c: cEm00 base, work 0x2130, mode 0x218C, push 0x2190, link `cGameObj *` 0x21B0), `PlTrail` (0012a578.c: base cVec at 0x630), the model record packet macros in 00154da0.c (MdlObj packet table 0x300, texture bank 0x384, MdlRec texNo 0x16), and `DamageTake`/`cOmSwitch` (00192588.c: hit position 0x10, flags word 0x60 with bits 2 hit, 3 random switch, 6 strong; take pointer at cOmBase 0x604). DamageTake belongs in cDamageUnit.h, which lacks the 0x10 vector and the 0x60 flags.
- cOmBase.h `cMeshNode` and cModel.h `cModelNode` describe the same mesh node (alpha 0x3AC, next 0x404, layer 0x40C). Use one type.

Header changes needed at the checkpoint (drafts ready in build/scratch/003033a8_ckpt.c):
- vu0.h: add `VU0_SQC2_VF0_MEM(v, off)`, a `sqc2 $vf0` with an `"=m"` operand, so a stack local is stored at its sp offset as retail does. `VU0_SQC2_VF0` takes the base in a register, so ours computes the address first. With it, func_003033A8, func_003034A8, func_00304830, func_00304940 and func_00304A48 all match (one TU, src/cod/003033a8.c, type `cFxDrift`: param `FxParam *` 0x100, holder 0x104, anchor 0x108, pos 0x11C, rot 0x128, vel 0x134, speed/spread/fall 0x170..0x178, delay short 0x18A).
- 0028b148.c defines `func_002B6350(void *a0)` as `MtxCopy(a0 + 0xB0)`, but it forwards a second argument (the source matrix); func_00304A48 passes it. Make it `func_002B6350(void *node, void *m)` calling `MtxCopy((char *)node + 0xB0, m)`. 001b5160.c defines `MtxCopy(void)` and `MtxMultiply(void)` as forwarding stubs; callers pass two and three pointers, so the new TU declares them without a prototype.

## Checkpoint 130 merge

Merged:
- vu0.h keeps `VU0_SQC2_VF0_MEM` (memory-operand `sqc2 $vf0`); src/cod/003033a8.c uses it. `VU0_VSUB_XYZ_IP` stays for 00283aa8.c.
- 0028b148.c: `func_002B6350(void *node, void *m)` forwards both arguments to `MtxCopy`, which is now prototyped there. func_00304A48 (src/cod/003033a8.c) passes the matrix.
- New `include/godhand/pathRec.h`: `PathRec` (endY 0x38, kind 0x3F, dir 0x50, coneAngle 0x60) and `PathHost` (startY 0x10, rec 0x30), used by 00137cb8.c and 00137e70.c.
- cOmBase.h: `cVec_set4` next to `cVec_copy3` (from 00305e88.c); the unused `cOmHitVolume_setVec` is gone from cOmHitVolumeSetup.h.
- cEm00.h: `ik` 0x448, `link` 0x531 (signed char, -1 for none), `active` 0x616, `turnRate` 0x1564, `turnArg` 0x1568, `watchArg` 0x1584; 00279d88.c uses them instead of offset macros.
- D_005CAFF0 is the current camera: `extern struct cCamera *D_005CAFF0` in cCamManager.h. reachObj.h's `PlayerReach` was a view of the camera's two `cCamVib` slots (0x254, 0x268, counts at 0x264/0x278); 002f40c0.c and 002f3f30.c use `vib[0].count`/`vib[1].count`; their float stores stay byte offsets, because retail reloads the camera pointer after each one. 0013b9b8.c keeps its own `int` declaration (only a raw store matches there) and does not include cCamManager.h.
- 003033a8.c holds func_003033A8, func_003034A8, func_00304940, func_00304A48. func_00304830 only matched with `prm = self->param` reassigned before each use, so it stays unmatched.

Still open:
- D_003BD880 is declared seven ways across 10 files (a 16-byte vector); the type changes the loads in several matched units, so it needs a per-file check.
- cOmBase.h `cMeshNode` and cModel.h `cModelNode` describe the same mesh node; merging them touches main's own files.
- cIDBaseEnt.flags signedness (only func_0013BD40, unmatched, depends on it) and cEm00 0x640 (`entryNo` vs the pointer the 0010cd38.c draft reads).
- The single-user local types listed in batches 101-129 stay local until a second unit needs them.
