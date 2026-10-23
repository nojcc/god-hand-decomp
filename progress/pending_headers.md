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

## Batch 131

Proposed for vu0.h at checkpoint 140:
- `VU0_SQC2_MEM(reg, v, off)` and `VU0_LQC2_MEM(reg, v, off)`: `sqc2`/`lqc2 $vf<reg>` with a memory operand (`"=m"` / `"m"` on `*(vu0_q128_t *)((char *)(v) + (off))`), the general-register twins of `VU0_SQC2_VF0_MEM`. Retail stores stack copies of vectors at their sp offset (`sqc2 $vf4, 0x30($sp)`); the register-operand `VU0_SQC2` makes ours build the address first. With a scratch copy of `VU0_SQC2_MEM`, the prologue and vector part of func_001C20D8 match (drafts/cod/001c20d8.c). Also needed by func_0017F6C0 and func_0017F828.

Fields seen (local views or offsets until the merge):
- cOmSub.h: vibration record at 0x140 (count, period, x, y, z floats) and flag `unk03` bit 3 = vibrating (drafts/cod/001c7d50.c, cOmSub_setVibration).
- cOmBase 0x100..0x108 is a rotation (pitch, yaw, roll) on the flying piece in drafts/cod/001c8930.c and its child; cOmBase.h names it `posPrev`. Same conflict as the batch 127-129 note on 0x104.
- 001aab10.c: local `cOmBreakable` (cOmBase base, `cDamageUnit *dmgA` 0x604, `dmgB` 0x608, `BreakVol *vol[3]` 0x60C with live bit 0 of flags at +8, flags 0x9D0 bit 31 = broken). unkObj.h also names 0x9D0 `flags`.
- 001b1c78.c: local `cOmGimmick` (cOmBase base, `checks` 0x600: bit 4 floor, bit 5 walls, bit 6 solids).
- cEm00.h: byte 0x676 sight flags (bit 0 needs a clear line, bit 2 far range), used through an offset macro in drafts/cod/001c20d8.c.
- cGameObj.h `cGameObjVt.lockOn` (0x84) returns `cVec *`; cEm00.h already declares the same slot as `getPos` returning `cVec *`. Callers cast today (00146f18.c, 0019b4d0.c).

## Batch 132
- cEm00/cGameObj.objFlags (0x250): func_00276478 builds `~0x10` as lui/ori, i.e. an unsigned constant or an unsigned field. Candidate: make objFlags `unsigned int` (check all users rebuild).
- D_00747A84: declared `unsigned int` in 001496c0.c and `int` in 002c3c10.c; needs one shared extern (cSaveLoad.h already documents it). Bit 6 is read with dsrl in func_00276478, so it may be a bitfield word.
- cOm4f base -> cGameObj; cGameObjVt 0x88/0x8C getRot slot.
- cSnd.h: `extern cSnd D_005FEE00;` and the cSnd_SeCall_2CB8A0 prototype (used by 001a7f58.c).
- cEmWrap.unk00 -> `unsigned char entryNo` + pad; cEmSetParam_updateSetDataPos(cEmSetParam *self, unsigned int no, ...) (drafts/cod/00295380.c still uses the old signature).
- cOmDamaged into a header; a cOmBase_hasChild bool helper.
- ChkLine (13 args) prototype into a shared header; used by 00273c38.c and drafts 0026f328.c.
- Turn_dest(void*, void*, float, float), MtxInitRotY(void*, float), capVu0Atan2(float, float), capVu0MagnitudeSqXZ(void*, void*): declared locally in several TUs, should move to a header.
- seqNode.h SeqLink: `char unk0C[4]` -> `unsigned int age; /* 0x0C frames alive, saturates at 0xFFFFFFFF */`. Held for the checkpoint: build/scratch/0037ca98_ckpt.c (func_0037CA98 matches with this field; retail compares against an unsigned 0xFFFFFFFF).
- cGameObj 0x2AC: a short read by func_001C2408 as the point-display kind (draft drafts/cod/001c2408.c).
- cCockGetPoint_setData: its definition in src/cod/casino/cCockGetPoint.c is `void (void)` but func_001C2408 passes (void *self, cVec *pos, unsigned short point, short kind). The body is empty, so the definition can take these parameters (not read) and get a header prototype.
- vu0.h: proposed `VU0_ZERO_VSUB_XYZ_TO(v, off, a, b)`, the same five instructions as VU0_ZERO_VSUB_XYZ_MEM but as a plain (non-volatile) asm with `"=m"` output for (v+off), inputs a and b, and a "memory" clobber. Retail lets the scheduler hoist independent address arithmetic above this sequence; the volatile form pins it. Measured: func_00249770 matches exactly with it (held as build/scratch/00249770_ckpt.c). func_001569A0 moves from 9 to 4 differing words with it, so it isn't a fix-all; keep the volatile macro for existing users.
- D_005850B0 (the arena centre vector, reset to (0,0,0,1) by 00137cb8.c): declared `int` in 002426a0.c and `char[]` in 00137cb8.c; it is a cVec. Needs one extern in a header (`extern cVec D_005850B0;`), which 00249770 uses.
- func_002BCF28 returns func_002BC0F8's int (the caller at 0x2B9868 reads v0); src/cod/002ba878.c declares it `void (void *, float, float, void *, float, float)`. Real signature: `int func_002BCF28(float *mtxA, float *mtxB, float lowA, float highA, float lowB, float highB)` (draft drafts/cod/002bcf28.c). Check 002ba878.c still matches with the corrected prototype before merging.
- ForwardVec3At30_147C60(void *, float *): declared in 001733b0.c and drafts; move to a header.
- Finding on the VU0 copy macros: an asm with no outputs is always volatile in gcc, so a non-volatile VU0_LQC2/VU0_SQC2 is impossible as written. The address-hoist near misses (func_001299F0, func_002BCF28, func_001569A0, func_0014E818) all need retail's quadword copy to let `addiu reg, sp, N` move above it. An "=m"-output form works for the subtract (func_00249770). A copy form with a memory output (`VU0_COPYQ(dst, off, src)`: lqc2 from src, sqc2 to an "=m" operand) is the next thing to measure at the checkpoint; a scratch probe of it on func_002BCF28 did not close it alone.
- cGameObj 0x550..0x558: three floats both objects zero when one grabs the other (func_001299F0); a velocity triple. Draft drafts/cod/001299f0.c.
- cEm00 0x17D0: an int whose low 3 bits are compared with D_007474A0.frame (func_0024BDA0, draft).
- cOmWeapon.h: `float life; /* 0x660 frames left before a dropped weapon breaks */` (split unk650 into unk650[0x10] + life + unk664 bytes) and `float fallVel; /* 0x674 vertical speed while dropping */` (split unk674). Held for the checkpoint: build/scratch/001cd800_ckpt.c (func_001CD800) matches exactly with these fields and VU0_SQC2_MEM.
- cE3.h: `cursor` (0x02) is `signed char` (the E3 time limit in minutes, 0 = unlimited). With it, build/scratch/cE3_menu_ckpt.c (cE3_menu, replaces the INCLUDE_ASM in src/cod/cE3.c) matches exactly; the menu prints D_0042C7A0 "TIME LIMIT = %d [min]" with the cursor or D_0042C7B8 "TIME LIMIT = unlimited". Re-check 001a7ec0.c and 001f7900.c after the change.
- cScenario.h: unk00 holds a check-point position (float x, y, z at 0x00), a heading (float at 0x10) and a short at 0x16 cleared by cScenario_beginCasinoBattle. That function also calls the player's vtable entries 0x80 and 0x88 as `cVec *f(void *)` (cEm00Vt names them getPos/getScale; cGameObjVt names 0x80 lockOn returning void and puts getPos at 0x68). Reconcile before matching it.
- New shared type for the checkpoint: `cNodeDrawState` (0x80 bytes: unit scale cVec 0x00, zero cVecs 0x10/0x20, unit scale cVec 0x30, float 0x40, ints 0x44/0x48, bytes 0x4C (-1) .. 0x4F (0xFF), int 0x50, cVec 0x60, shorts 0x70/0x72, byte 0x74, int 0x78) with `cVec_zero(cVec *)` (VU0_SQC2_VF0_MEM) and `cNodeDrawState_init(cNodeDrawState *)` (store order 0x00, 0x10, 0x20, 0x30, 0x40, 0x4C, 0x4F, 0x44, 0x48, 0x4D, 0x4E, 0x50, 0x60; it does not touch 0x70..0x7C). Defined locally in src/cod/00302790.c for now (cDrawNode embeds it at 0x1A0 and clears 0x70..0x78 after init). Move it to a header (cNode.h or a new cNodeDrawState.h), include it from 00302790.c, and register build/scratch/002f4290_ckpt.c (func_002F4290 passes one on the stack to SetEffect; matches exactly with this init).
- func_0017F6C0 (draft drafts/cod/0017f6c0.c, 9 words): a scratch probe with the proposed non-volatile VU0_ZERO_VSUB_XYZ_TO hoists the work vector address as retail does, but the copy into the temporary (sp+0x20) still pins `addiu a0, sp, 0x20` below it; a non-volatile "=m" copy form did not fix it either. The twin func_0017F828 has the same shape.
- cOmBase.h (or sceVu0.h): `static __inline__ void cVec_unitOf(cVec *out, cVec *v)` (VU0_SQC2_VF0_MEM(out, 0); len = Tramp_001F7DF8_00101E28(v); if (len > 0) out = v / len component by component, out->w = v->w) and the `float Tramp_001F7DF8_00101E28(cVec *v)` prototype. Defined locally in src/cod/0018f618.c; build/scratch/001a6310_ckpt.c (func_001A6310, the same rocking body on a class whose fields sit 0x50 lower) matches exactly and needs it from the header. Give the twin's view its own name (the class at 0x1A6310 is not the one at 0x18F618), and consider sharing the swing body between the two files.

## func_00302918 prototype (batch 136)
Declared five different ways (`int *`, `void *`) across 003039e8, 001612c8, 002fab88, 00300d20, 00304c48 and defined as `void func_00302918(int *a0)`. Move one `void func_00302918(void *p);` into a cNode-area header at the checkpoint and include it everywhere.

## cAreaFx (batch 137)
src/cod/00305c20.c defines cAreaFx (0x400 fx data, 0x404 zone list, 0x408 enable, 0x40C zoneMask, 0x410 inside, 0x414 started, 0x418 triggered) with cAreaZone/cAreaZoneList/cAreaFxTable. src/cod/00305e88.c views the same object as cFxOnce (0x414 started). Merge into one header (cAreaFx.h) with the prototypes of func_00305E88 and func_00305F58, and include it from both TUs.
The cGameObjVt.lockOn entry returns the lock-on position (cVec *); 0019b4d0 and 00305c20 both cast it. Change its type to `cVec *(*lockOn)(void *self)` if cgameobj_getlockonpos.c still matches.

## cCollisionSolidManage_ChkHit returns int (batch 137)
Retail cCollisionSolidManage_ChkHit (0x1348E8) loads $v0 from its frame before `jr $ra`, so it returns int. src/cod/00277568.c needs `int` to match (the caller's register choice depends on it). 00185bd0, 00171d20 and 001b1c78 declare it `void`; at the checkpoint put `int cCollisionSolidManage_ChkHit(void *mgr, void *obj);` in a header (with cCollisionSolidManage_SetActive and D_00462FC0) and confirm those three still match.

## cEm00 fall view (batch 137)
src/cod/00277568.c lays cEmFallWork {unsigned flags; float gravity; float fallVel;} over cEm00.unk1560..0x1568 (the header has int unk1560 / float turnRate / int turnArg there). The derived enemy class (constructor EnemyBase_constructTriVec, 002772.c) needs its own header type; until then the view stays local.

## cOmHitVolume record pointer at 0x5E0 (batch 137)
func_00198D40 (draft) reads a placement record pointer at cOmHitVolume+0x5E0 (byte variant at +0x2C). Add `struct cOmPlaceRec *rec; /* 0x5E0 */` in place of unk5E0[4] and drop the cast macro in drafts/cod/00198d40.c.

## cEffectParam_init and cVec_zero (batch 138)
cNodeDrawState (src/cod/00302790.c, build/scratch/002f4290_ckpt.c) is the same 0x80-byte record as cObjBase.h's cEffectParam. SetEffectPos (src/cod/00306838.c) matches only with the init as an inline: put `cVec_zero` (VU0_SQC2_VF0_MEM) and `cEffectParam_init` in cObjBase.h, switch 00302790, 00306838 and 002f4290 to cEffectParam and the shared inline, and confirm all three match.
Callers 001e2eb8, 0016acd0, 0017d488 declare SetEffectPos(int, int, int, void *, int, float); its definition is (int kind, int id, void *owner, cVec *pos, int handle, float size). Put that prototype and SetEffect's in cObjBase.h.

## cCamManager follow fields, PathHost/PathRec fields (batch 138)
func_00137F38 (draft, 2 diffs) writes cCamManager 0x444 dist, 0x450 turn, 0x460 height (split unk000), and reads PathHost 0x14 turn, 0x18 rate, 0x1C dist and PathRec 0x34 rate, 0x5C dist. Add them to cCamManager.h and pathRec.h; the draft's macros and local cCamManager view then go away.

## Checkpoint 140 merge

Merged:
- vu0.h: `VU0_SQC2_MEM` (with the three handoffs) and `VU0_ZERO_VSUB_XYZ_TO`, the non-volatile "=m" form of VU0_ZERO_VSUB_XYZ_MEM (func_00249770 matches with it; the volatile macro stays for its users).
- sceVu0.h: `cVec_zero` and `cVec_unitOf` with the `Tramp_001F7DF8_00101E28` prototype. 0018f618.c uses the shared helper; func_001A6310 is registered with its own view (cOmRockerLow).
- cGameObj.h: `vel` at 0x550. cOmWeapon.h: `life` 0x660, `fallVel` 0x674 (func_001CD800). seqNode.h: `SeqLink.age` 0x0C (func_0037CA98).
- cE3.h: `cursor` is signed (the time limit in minutes) and cE3World names `menuReady` at 0x90; cE3_menu is matched in cE3.c, reaching the game work as D_00747A2C - 0x58C the way 001f7900.c does.
- cCollisionSolid.h: `int cCollisionSolidManage_ChkHit(void *mgr, void *obj)`; the six files that declared it include the header (the three `void` declarations still match as `int`).

Still open:
- cEffectParam_init / cNodeDrawState (func_002F4290 held in .review/held, 00302790.c, 00306838.c).
- cAreaFx header (00305c20.c, 00305e88.c), the cCamManager follow and PathHost/PathRec fields (func_00137F38 draft), cOmHitVolume 0x5E0 (func_00198D40 draft).
- Shared prototypes: ChkLine (31 files, all `int` with 13 arguments, pointer types differ), Turn_dest, MtxInitRotY, capVu0Atan2, capVu0MagnitudeSqXZ, ForwardVec3At30_147C60, SetEffectPos/SetEffect, func_002BCF28.
- D_005850B0 (cVec) and D_00747A84 (one shared extern), D_005FEE00 in cSnd.h.
- objFlags signedness, cGameObjVt.lockOn returning cVec *, cEmWrap.entryNo, cCockGetPoint_setData parameters, cScenario check-point fields, cOmBase 0x100 naming.

## Batch 140: line drawing, debug print, sound debug pages
- New `include/godhand/drawLine.h`: `Draw_Line2`, `Draw_Line_sc`, `Draw_Poly_sc` prototypes plus `LineAttr` (flags 0x0, tex1 0x30, size 0x50) and `void *Gp_draw_line(float (*pts)[4], unsigned int color, int a2, int a3, int a4, LineAttr *attr)`. Local declarations in 0014b9a0.c, 0031ca88.c, 0031c950.c, 0031cb80.c and drafts/cod/0015ef10.c switch to the header.
- `func_002E0DE8(int x, int y, int color, const char *fmt, ...)` (debug text printer) needs one shared prototype; upstream files declare it inconsistently. Used by src/cod/00381478.c and 00382898.c.
- sceVu0.h: `void sceVu0DivVector(void *dst, void *src, float q)` (drafts/cod/0015ef10.c).
- menuCtl.h: SndOptLevels extends to the stream-test slot record in src/cod/00382898.c (`SndStrmSlots`: kind, err, slot, level[5] 0x4, index[5] 0xE, pan[5] 0x18, pitch[5] 0x22, state 0x2C). Merge the two and drop the local view.
- seqNode.h candidate: `SeqTrk` (src/cod/00372cb0.c; stream 0x0, fade union 0x14, handle 0x48, flags 0x4C, wait 0x50, mode 0x54, count 0x58, entry 0x78).
- cSnd.h for func_002CCD80 (cSndBgmNode update, not yet attempted in C): cSndBgmNode.unkCC becomes `float target[2]` (0xCC) and `float step[2]` (0xD4); cSnd.unk124 is a float; `entry` (0xA8) points to a BGM entry {int 0x0; int 0x8; float 0xC}; `func_002D05B8` returns `short *` (defined as `int` in 002cf258.c).
- cIDBase.h: `cIDBaseEnt.jit[5]` (0xA0) holds per-channel frame counters that retail compares unsigned (func_002AC378 `lim < (unsigned short)`, func_0013D7B0 lhu + sltiu 0x10) and only reads signed when passing them to Curve_sample. Make it `unsigned short`; the users by name (002ab2a0.c, 002abc18.c, 002abce8.c) only store to it. Then register func_0013D7B0 from build/scratch/0013d7b0_ckpt.c (continue prompt, matches with `--as sn` once the field is unsigned; it matches today only through an `(unsigned short)` cast).
- tim2.h (new): `GsTex0` (64-bit TEX0 bitfields, now in 003092e0.c and src/cod/0015e0a0.c), `Tim2FileHdr` and `Tim2PicHdr` (src/cod/0015e0a0.c; 003092e0.c's `TexHdr` is the same picture header with the mip fields). drafts/cod/00151990.c expects `godhand/tim2.h` with `Tim2File`/`Tim2Pic`/`GsTex0`.
- espSlot.h (new): the effect slot pool `D_0061B7C0` (0x400 slots of 0x400 bytes) and the three bit masks `D_0071B7C0`/`D_0071B840`/`D_0071B8C0`, declared locally with different types in 001aad88.c, 001b0f70.c, 001632e8.c, 001855a8.c and src/cod/002fbb78.c (slot view with vt at 0xF0, group 0x23A, subGroup 0x23C).
- cOmHitVolumeSetup.h: add `cDamageUnit_AddDamageCollCylinder(void *unit, void *mtx, float *ofs, float *rot, float r, float h)`; it is declared locally in 00178618.c, src/cod/001a3e10.c and seven other files.
- cOl0e.h: COL0E_FLAG2_FAKE (0x100) is cleared when the object goes fake and set when it comes back (cOl0e_setFake retail), the opposite of its comment.
- 0025b9f0.c calls func_0026F120 and func_0026F1D8 with no prototype in scope.

## Batch 142
- `D_0061B280` has two conflicting types: `FileBuf` in src/cod/00140c88.c and `signed char[]` in src/cod/002e13d8.c. It is the debug font state read by func_002E0F18: width u8 at 0x8, height u8 at 0x9, cursor x/y u16 at 0xC/0xE, line start x u16 at 0x10, glyph count u16 at 0x12 (limit 0x800). Needs one header type before func_002E0F18 can be carved.
- cOmBase.h: 0x110 is the model scale x/y/z (`float scale[3]`), read through local macros in 001b0de8.c; add the field when the cOmBase PR merges.
- `D_007474A0` has two views: `GameWork` (gameWork.h) and `cDoorWorld` (cDoor.h, used by cDoor.c and the func_002000F8 draft). cDoorWorld names 0x5B8..0x5BB (nextArg, kindA/B/C), 0x5D8 (flags5D8 = D_00747A78), 0x5E0 and 0x5E4; merge them into GameWork and drop cDoorWorld.
- `SavePointWork` (local to src/cod/002006b8.c) is a view of `cDoor`: cur = point[0] at 0x04, save = point[1] at 0x1C, step 0x39 = cDoor.phase, busy 0x3A = cDoor.unk3A. func_002006B8 should take `cDoor *`.
- func_00200638 (src/cod/001b5160.c) and InitSlotParams_200658 (src/cod/001ff540.c) are defined `(void)` but func_002000F8 passes the door in a0; give them an unread `cDoor *self` parameter when that function lands.
- `D_005CAC90` has three types: `ContinueCount` (0013d7b0 hold), `unsigned char` (002a5998.c), and a 4-byte game-mode record written by func_002000F8 (byte 0 = 5 for a room jump, bytes 1..3 cleared).
- MtxMulRotVec (src/cod/00134880.c) is defined with four int parameters but takes (dst matrix, src matrix, rotation vector, order byte).
- func_001E6910 (src/cod/001dee20.c) is defined `(void)` but Slot2_Execute passes self; Slot2_Execute is declared `(void)` in 001e4920.c but takes `Slot2 *`. Both belong in Slot2.h.
- Slot2.h: `layer` at 0x400 is a `SlotUi` (customId at 0x450 is its first mark entry).
- `SetCustomIDDispOneOrAll_1F4778(void *self, int id, int on)` is declared locally in ~10 TUs (0015a590, 001f50a0, 0017b010, 0016ee10, 002c7f88, 00103760, 001c2c40, 001b0b70, 001ecaf0, 001f4ca8, now 001f5650); move to CustomIDPanel.h. Same for `func_002D69A8(CustomIDWork*, unsigned short, float, float)` and `func_002D65F8(CustomIDWork*, float, float, float, float)`. 001f5650.c also has a local `CustomIDOwner` view (CustomIDWork ent[] at 0x60).
- mwsfd.h: `void func_0032B488(void *adxt, int db, int frac);` (the ADXT output-volume entry; an empty stub in this build). Change src/cod/0032b488.c's definition from `(void *a0)` to that signature, with one line saying db and frac are not read, and include mwsfd.h there. Then register build/scratch/00349c28_ckpt.c (func_00349C28, the SfdHn volume setter; matches exactly with cygnus-2.96 and c_flags_drop -freorder-blocks; uses logf func_003A1DF0, whose prototype also belongs in a shared libm header).
- cGameObj.h cGameObjVt (off limits now, for the maintainer): the cOm49 table D_00427148 has cGameObj_getLockOnPos at 0x6C and cGameObj_getPos at 0x84, so `getPos` (0x68/0x6C) and `lockOn` (0x80/0x84) look swapped; the header comment's "getLockOnPos and getHitCheckPos both call it" fits 0x84 being getPos. drafts/cod/001a4010.c and src/cod/00149378.c (EffObj) use local views of the 0x80/0x84 pair.
- cScenario.h: name the byte at 0x14 (split unk00 into unk00[0x14], `unsigned char unk14; /* 0x14 nonzero (1) while an event runs; the action-button checks skip then */`, unk15[0x7]). Readers through raw offsets: src/cod/001633a0.c, src/cod/00162b18.c, drafts/cod/0028e580.c.
- D_003EE338 (the SFXLIB handle pool) has three types: `char[]` (0035f8b8.c), `int` (00325360.c, the live count at 0 that func_0035FB88 decrements), `unsigned char[]` with a Root3EE338 view (0035fa88.c, and func_0035F970 from the handoff increments it as an int). Give it one struct type in sfxlib.h (count at 0x00, 8 at 0x04, entries after; 0x4C8 bytes). func_0035FB88's definition takes `int a0` but its callers pass the handle pointer; retype it to the handle type when sfxlib.h gets the struct.

## Batch 143
- New header (spring mesh): `SpringNode` (0x50), `SpringLink` (0x18), `SpringMesh` (cols 0x0, rows 0x4, nodes 0x10, links 0x14), plus `SpringNodeDef`/`SpringLinkDef`, from drafts/cod/002ad2b8.c. src/cod/002ad590.c reads the same records through raw offsets.
- `void func_002AD2B8(SpringMesh *self, unsigned int count, SpringNodeDef *nodeDefs, int nodeCount, SpringLinkDef *linkDefs, int linkCount, float total)`: retail never sets v0, but src/cod/00182ff8.c declares it `int` and returns its result (001717c0.c has `void`). Fix the caller when the prototype moves to the header.
- `float capVu0Length(void *a0)` (defined in 001f7df8.c) is declared locally in about 20 files; move it to sceVu0.h.
- New ADXT header: `signed char D_003C7420[]` (16 handles of 0xC8; src/cod/00323a00.c declares it `int`), `Forward33B658_33E678`/`Forward33B670_33E690` (ADXCRS lock/unlock, declared locally in 6+ files), `void func_0032CFC8(signed char *adxt)` and `void ADXT_ExecHndl(signed char *adxt)` (changed from `int` in 00322f58.c in batch 143; still matches), `volatile int D_003D140C` (server stage guard, src/cod/0032afb0.c), `int D_003D1414`.
- mwPly.h: add `int span` at 0x118 and `float rate` at 0x1E4 to MwPly (split unk094 and the tail; 0032de38.c writes rate through a raw offset). Then register build/scratch/0032dd70_ckpt.c (func_0032DD70, cygnus-2.96, fp_hazard_rules cmpfull; matches against a scratch view with the same offsets).
- `func_00328C80(void *h, int a, int b)`: 00335f20.c and 0032dd70 pass the handle pointer, but the definition in 002c54e8.c takes `int a0`. Correct the definition and move the prototype to a header.
- func_003452D8 (MWSFD init, cygnus) is blocked on callee signatures: func_00345490 is defined `void (void)` but called with the init record; func_00335D18(int, int) receives a function pointer; Forward348BE0_3452C0/Forward346450_3462A8 are int-typed thunks; MWSFSVM_Error is declared two ways (mwsfd.h variadic, mwsfHn.h single arg). Fix those, then retry.

## Batch 144

- `cOmBase_canCarry` (src/cod/0013c618.c, cOmBase family, off limits while its PR is open) is defined as
  `long long cOmBase_canCarry(void *)`. SN cc1 rejects a long long return ("unsupported wide integer
  operation"), so SN callers can't use it. The real signature is `int cOmBase_canCarry(cOmBase *self)`,
  returning bit 3 of 0x5B0. Once the PR merges, fix the definition, put the prototype in cOmBase.h, then
  revisit drafts/cod/0012b328.c.
- `ChkLine` is declared locally with different parameter types in 00275888.c, 0017d488.c and others.
  It needs one prototype in a header (13 args: from, to, a2 ptr, then 10 ints).
- `D_00754C58` (the game object list) is `cMcObjList *` in cMc.c and `char *` in 002aa480.c; move the
  `cMcObjList *` extern into cMc.h.
- cEm00/cOmBase `posB` (cVec at 0x5D0): 0010c300.c and func_0010C5A8 read 0x5D8 as an int and compare it
  with 4, so 0x5D0..0x5DF probably isn't one cVec (maybe posB is 3 floats then an int, or a union).
  Settle the layout, then do func_0010C5A8 (sibling of 0010c300; also needs fields 0x630 cVec,
  0x674 float, 0x6A0 ptr, 0x15F0 float, 0x15FC float, 0x1602 byte).
- func_00115310 (player catch state) needs a cVec at 0x580 inside cGameObj's range (cGameObj is off limits); after the PR merges add it, then draft the function with pl00.
- ADXF globals: D_003EB838 (the ADXF handle being loaded; its stat byte is at +1) and D_003C5298 (the
  partition read buffer) are declared int in 00322c68.c, 00322f80.c and 00320388.c. func_00324500's
  definition takes signed char *. Give them one pointer type in adxf.h (with D_003EB834/83C/840 and
  D_003C529C), then revisit drafts/cod/00323050.c.
- libgraph: sceGsDispEnv/sceGsGParam are defined separately in 00396158.c and 00396440.c (00396440 as
  u_long r[5]). They need one libgraph.h header. func_00396560 (syscall 0x80 stub in 00396560.c) is
  declared void(void) but takes (int mode, int *dx, int *dy, int *dw, int *dh); see
  drafts/cod/00396570.c.

## Batch 145

- cDvd.h: `cDvdJob.arg6C` is an unsigned queue priority (func_00201290 sorts on it with sltu; every
  other use is a plain store from a parameter). Rename it `unsigned int priority`, update the three
  ReadAlloc stores, and declare `void cDvd_startJobHeap(cDvd *self, cDvdJob *job)` (defined in
  001aa478.c) in cDvd.h. Then drop the casts in drafts/cod/00201290.c.
- ADX stream (func_003284B8): `Obj3290_Tramp_0033E678_9028` (lock) is declared three ways (K&R in
  003288e0.c, `(void)` in 00327230.c, `(void *)` in 00328300.c), and `func_00330BB0`/`func_00330C18`
  are defined in 00328300.c as one-parameter forwarders while 003288e0.c and func_003284B8 pass three
  (handle, offset/count, buffer) that the vtable target reads. Fix the forwarder signatures and give
  them one header (with the stream handle struct, 0x60 bytes) before func_003284B8.
- Tooling, not a header: func_003AD348 (fmod, drafts/cod/003ad348.c) is blocked by the assembler.
  Retail expands `dli $r,0xffffffff` as addiu -1/dsrl32 (needs as: sn) and also pads call-free
  short loops, which ps2eeas does not; neither assembler route gives both today.
- cCoreSave.h: `cCoreSave_getReelSlot`'s slot parameter is `unsigned char` (every caller masks it
  with andi 0xFF; the definition in 0015fd68.c masks an int by hand). Also declare
  `void cIDBase_move(cIDBaseObj *self)` in cIDBase.h (0013da98.c and 001f28f0.c each declare it
  locally as void(void *)). Then revisit drafts/cod/00161d08.c.
- Matrix helpers for cCamera_update (drafts/cod/00138740.c), each declared locally (some K&R) in a
  dozen files: MtxCopy(float *dst, float *src), MtxMultiply(float *dst, float *a, float *b),
  sceVu0UnitMatrix(float *m), func_0030A2E0 (sceVu0MulMatrix: dst, a, b), func_0030AA40
  (sceVu0ViewScreenMatrix: m, then 9 floats), capVu0Sin(float), func_003A1AE8 (tanf) and
  cCamera_calcViewMatrix(struct cCamera *). They belong in sceVu0.h / cCamera.h. Tooling: retail's
  div.s pad depth in this function varies 0/1/2 by site, which no fp_hazard_rules set models.
- Sound sequencer (blocks func_002CCD80, BGM node switching): the sequence object's methods are
  defined with clashing parameter types: func_00373B30(int *) in 001abd40.c,
  GetSequenceBlendWeight_373938(void *, int) and SetSequenceFlags_373810(void *, int) in 00373158.c,
  func_003738A0(S3738A0 *, int, float) in 003738a0.c, func_00373A58(int *) in 00327e18.c,
  ClearFlagBits_373858(void *, unsigned int) in 002b5bb8.c; cSnd_GetBgmAttr and func_002CCB58 have no
  C definition yet. One sequence type and one header (cSndSeq.h) first.

## Batch 146

- cRoomSave.h: declare `void func_002BEDC8(cRoomSave *self, int num)` (sets data->emNum; defined in
  002af638.c). 0014a038.c declares it and func_002BEDE8 against cEmSetTable/cEmSetEntry; func_002BEDE8
  really takes (cRoomSave *, unsigned int num, cRoomSaveSrc *src). Declare
  `void func_002BEDE8(cRoomSave *self, unsigned int num, cRoomSaveSrc *src)` there too and switch
  0014a038.c to it (check its unit still matches). Draft: drafts/cod/002bede8.c.
- seqNode.h: split `unk40[0x4A - 0x40]` into `unk40[0x44 - 0x40]`, `short pan; /* 0x44 */`,
  `unk46[0x4A - 0x46]`. Declare `void func_003780F8(unsigned short angle, float *l, float *r)`
  (pan-gain table lookup, matched in src/cod/003780f8.c) and `void func_0037D558(SeqNode *self)` (now
  declared locally as void(void *) in 0037bf10.c and void(SeqNode *) in 0037cce0.c).
- `int Obj0000_Get_D_0076A7A4_3756F0(void)` (sound output mode: 0 mono, 1 stereo, 2 surround) is
  declared locally in six files, once as (int) in 002cf258.c. Give it one header (seqNode.h or the
  sound header) and fix 002cf258.c.
- HELD for checkpoint: func_0037D558 matches (build/scratch/0037d558_ckpt.c) with
  fp_hazard_rules "mtc1" once the three items above land; register it as new TU src/cod/0037d558.c.
  The switch keeps an explicit empty `case 0:` (mono) because retail's compare tree tests all three modes.
- RecDecode (new recDecode.h): move RecIn/RecOut out of 001599b0.c and give RecOut its curve keys
  `float next; /* 0x14 */ float tanA; /* 0x18 */ float tanB; /* 0x1C */`. Declare
  `void RecDecode_readHeader(RecOut *out, char *blob, RecIn *in)` there (0014b9a0.c declares it as
  void(void *, void *, void *)), plus func_00159DA0(RecOut *) and
  `float func_00159AD0(RecOut *self, char *blob, RecIn *in, float t)`. drafts/cod/00159ad0.c then
  switches from its RecCurve/RecCurveIn views to the header types.
- func_002FE8A0 (drafts/cod/002fe8a0.c) needs `float *func_002B6328(cNode *node)` (defined in
  00126770.c as int(int)) and `void MtxCopy(float *dst, float *src)` (K&R in many files) in shared
  headers, plus the screen globals D_003C1180 / D_003C118C / D_00586B80 (declared locally in five files).
- gameWork.h: retail reaches GameWork 0x584 / 0x58C / 0x5E4 through one symbol at 0x747A24 (one lui,
  offsets 0, 8, 0x60), so that block is its own global, today declared `extern int D_00747A24`.
  Give it a struct (flags unsigned at 0x00, GameSys.unk00 at 0x08, flags5E4 at 0x60; see the GameFlags
  view in drafts/cod/0013e970.c) and move the users of `D_00747A24` over. Also declare
  `void cIDBase_move(cIDBaseObj *self)` (already listed under batch 145).
- Tooling: func_0013E970 pads its two div.s sites 0 and 2 nops (same per-site variation as
  cCamera_update); no fp_hazard_rules set models it.
- HELD for checkpoint: func_0012F288 matches (build/scratch/0012f288_ckpt.c, fp_hazard_rules "fdiv",
  new TU src/cod/0012f288.c). Needs a header (cGrid.h) holding the cGrid type from that file and
  prototypes for its callees, defined in legacy files without headers:
  `void func_00133948(void *self, void *a, void *b)` (00133948.c, VU0 min/max sort; self unused) and
  `int func_00133408(void *self, float *min, float *max, float *boxMin, float *boxMax)` (00133408.c).
- func_002956F0 (draft drafts/cod/002956f0.c): when headers land, replace its views with
  - cEmWrap.h `cEmActorVt`: split unk80 into posDelta/getPos (0x80/0x84) and rotDelta/getRot (0x88/0x8C);
  - cEmSetParam.h: `cEmSetEntry saved[2]` at 0x10; func_00295660 prototype (legacy `char *(char *)` in 001fe1e0.c) as `cEmSetEntry *(cEmSetParam *)`;
  - cScenario.h: byte at 0x14 (split unk00);
  - shared enemy-kind inline (0x200..0x2FF) for 002d0b88.c `SndIsEnemyKind` and this draft.
  Blocker: retail cvt.w.s for the float->short casts.
- func_002C45A8 (draft drafts/cod/002c45a8.c, s0/s1 swap only): replace its views when headers land:
  - cScenario.h: `cVec pos` 0x00, `float angle` 0x10, `unsigned char jumping` 0x14, `unsigned short fromRoom` 0x16 (split unk00; needs cOmBase.h for cVec);
  - player getters: cGameObjVt entries 16/17 (0x80/0x88) return the position/rotation (cGameObj.h is off limits: its 0x80 pair is named lockOn and returns void);
  - one shared prototype each for cSaveManager_setCheckPoint (5 local copies), cScenario_beginRoomJump_2C4548, D_003C264C (typed void*, int, ... across files).
- cCoreSave.h: func_002C0038 and func_002BFC80 copy combo[] (0x1B0, 0xD8 bytes) and skill[] (0xB0, 0x80 bytes) as whole blocks with lq/sq, so retail's types for those two members are 16-byte aligned aggregates (wrapping structs or aligned arrays). The current char/cCoreSaveCombo members are 4-aligned. Both functions also copy flags+unk18 (0x14, 8 bytes, ldl/ldr), fightingRingClear (0xB98, 2x ld), reelSlot (0x98, ld + lhu) as units.
- Tooling: lwu + dsra + andi single-bit tests (func_001BC300 0x620, func_00123160 0x528, func_002C02E8 D_00568240) have no clean C form found (unsigned/signed int bitfields give lw+srl, u_long bitfields give ld). Legacy cOmDoor_setOpen reaches lwu through `long` locals.
- cOmDoor_setClose: func_001BC300 passes a second argument (0) in a1; check the definition in 001bd120.c before matching it.
- adxt.h (new): the 0xC8-byte ADXT handle (AdxtObj, local in 003298f0.c and in the draft drafts/cod/00329490.c = ADXT_Create) with sjf 0x10, sji 0x14, sjo[2] 0x18, ibuf 0x20, ibufbsize 0x24, ibufxlen 0x28, obuf 0x2C, obufsize 0x30, obufdist 0x34, svrfreq 0x38, maxsct/minsct 0x3C/0x3E, outvol 0x40, outpan[2] 0x42, lsc 0x94, ibufend 0xB0; D_003C7420 as `AdxtObj[16]` (00324040.c, 00323a00.c, 00324ac8.c declare it as char/int); func_003298F0, func_0032B6A0 (two definitions disagree: void* vs int), func_0032AB20, func_003395A0 (SJRBF create, `int` in 002c54e8.c) prototypes. The draft needs drop-reorder.
- func_0032A1B0 (draft drafts/cod/0032a1b0.c, ADXT_GetTime on the vsync clock, 3 diffs): needs cmpfull,libm-mtc1 and drop-reorder. Its AdxtTimeHn view belongs in the adxt.h above: stat 0x01 (also AdxDecHn.stat in 0032a018.c), vsyncFrozen 0x72, ofs 0x88, baseCount 0x9C (unsigned), baseVsync 0xA0. Globals D_003C7418, D_003D1408, D_003D142C, D_003D1454, D_003D1458 (float) want one declaration each; func_0032A018's definition takes AdxDecHn, a second local view of the same handle.
- cSnd.h: listenPos (0xC0) is a cVec (retail copies the camera target into it with lq/sq; draft drafts/cod/002cc150.c = cSnd_UpdateListener). sceVu0.h wants sceVu0CameraMatrix, sceVu0AddVector, sceVu0ScaleVectorXYZ and func_0030A548 (matrix copy, also MtxCopy's callee) prototypes; D_00747A84 (= D_007474A0 + 0x5E4) wants one declaration next to D_00747A24 in gameWork.h.

## Checkpoint after batch 149 (applied)
- APPLIED through header_merge (12 units rebuilt identical): seqNode.h `short pan` at 0x44 plus func_0037D558, func_003780F8 and Obj0000_Get_D_0076A7A4_3756F0 prototypes (0037cce0.c's local copy dropped); new cGrid.h (cGrid, func_00133948, func_00133408); mwPly.h `span` 0x118, `rate` 0x1E4 and `int func_00328C80(void *h, int a, int b)`; mwsfd.h `void func_0032B488(void *adxt, int db, int frac)` with src/cod/0032b488.c corrected to it. Registered func_0037D558, func_0012F288, func_00349C28, func_0032DD70.
- STILL OPEN: func_00328C80's definition in 002c54e8.c takes `int a0`, and 0032e620.c / 000000.c declare it void-returning; move them to the mwPly.h prototype. Obj0000_Get_D_0076A7A4_3756F0 is still declared locally in six files (as `(int)` in 002cf258.c).
- STILL HELD: func_0013D7B0 (build/scratch/0013d7b0_ckpt.c) needs cIDBaseEnt.jit unsigned, one shared type for D_005CAC90 (three today: 0013d7b0 hold, 002a5998.c, 002a72c8.c/JukeBox.c), and header prototypes for cSnd_SeCall_2CB8A0, cIDBase_move, func_002AC9B8 and D_005FEE00.
- NM handoff not applied: progress/nm_solved/ holds func_0032A1B0, cSnd_UpdateListener, func_00365EC0, MoveEmitter, MoveEsp, Turn_dest. An apply run was interrupted mid-transaction and left the cSnd_UpdateListener header requests applied (cVecQuad typedef in cOmBase.h, cOmBase.h include and `cVecQuad listenPos` in cSnd.h); all three were reverted by hand to the prior text, and nothing was registered. cOmBase.h is off limits while its PR is open, so that folder waits. func_0032A1B0's solved form uses `*ncount += (int)(adxt->baseCount + 1);` (baseCount is really unsigned; the plain form is 6 insns off), which the reviewer should confirm.

## Batch 150 (local, not merged)
- ComboHolder (src/cod/0012c000.c) and ComboObj (00126918.c) are the same combo state: `unsigned short slot` 0x5E0, `unsigned short set` 0x5E2. Merge into one header type (owner object not identified yet; cCoreSave.h is the nearest header).
- libgraph IMR: `u_long GsGetIMR(void)` / `u_long GsPutIMR(u_long)` (the eekernel.h signatures). Applied in 00150078.c and 00396008.c by the func_0030E660 handoff; 003958d8.c still declares `u_int GsGetIMR(void)`. Tramp_GsGetIMR_3964A0 and func_00396008 (now u_long) want one prototype each in a libgraph header, used by 0030e660.c.
- sceGsStoreImage packet: 003958d8.c (bitfield form) and 0030e660.c (GsStoreImageWords, whole register words) describe the same packet; one header type once both forms are confirmed to build the same code.
- func_002B21F0: one shared prototype `void func_002B21F0(void *self, unsigned short id)` (definition in 00143598.c; draft drafts/cod/002b4228.c).
- gameWork.h: `unsigned int flags5D8` 0x5D8 and `unsigned int flags5E0` 0x5E0 (requested by the cSubScr_SubScrOn handoff, held in progress/nm_solved/ for the checkpoint); D_00747A84 (GameWork 0x5E4) one declaration.
- SetMotionStep: callers disagree (void vs float return); one prototype in a header.
- cEmSetParam_setEm `(cEmSetParam *param, int entry)` and cEmWrap_StartAction `(void *wrap)`: declared locally in 0010a2c8.c, 0012c7d0.c, 001a4430.c (char[] / void* variants) and drafts/cod/001f0a28.c; ColiseumBattle_DefeatAllEnemies likewise. Move to cEmSetParam.h / cEmWrap.h.
- cEm00.h: `cDamageTake *damageTake` at 0x670 (split unk649; cDamageTake is in cOmBase.h). Used by drafts/cod/00285c58.c through a raw-offset macro and by 00278570 in 00178980.c.
- cSnd_SeCall_2CBA48: definition (002cba48.c) takes `void *t0`; most callers declare `int e`. One prototype in cSnd.h.
- cScenario_beginRoomJump_2C4548: its definition in 00150830.c is `(int, unsigned short, int, unsigned char, int, unsigned char)` and forwards to a K&R cDoor_aimJump, but callers pass a float angle in f12 (0017d6b0.c, 001ef180.c, and func_001F3DF0 in retail), which cDoor_aimJump reads. Correct the definition (float angle, cVec *pos) and cDoor_aimJump's prototype, then share it in cScenario.h. Blocks func_001F3DF0.
- D_00568240 (coliseum/world state at 0x568240) is typed int, short[] and a struct across 001f20f8.c, 001df890.c, 00150608.c, 001dddb0.c; func_001F3DF0 writes shorts at 0x10/0x12 and a 0x28-byte block at 0x18 copied from ColiseumEmSelect 0x37A8. One header type.
- Retail "bool" tests: several functions compute a 0/1 range result into a register and test it with andi 0xFF (cOmWeapon_SetBreak's child lookup at a variable index, the 0x200..0x2FF actor test in func_00285C58, the coliseum kind tests in 001ef8b8.c). This is the code g++ makes for a bool-returning inline; cc1 folds the same C into one compare or drops the andi. cOmBase_childAt (cOmBase.h, off limits) cannot reproduce it. Needs a maintainer decision on how to express it.

## Batch 151 (local, not merged)

- cEm00.h: name 0x690 as the attack volume (`cDamageGive *damageGive`), 0x6C0 as a goal cVec (walk target, FindNodeByHit_2C2490 output), 0x1734 as an int cleared when the walk ends, and retype 0x698 `unk698` as `cDamageTake *` (func_00271518 reads its kind at 0x46 and a hit position at 0x20). Drafts 00262750.c, 00245538.c and 00271518.c use local raw macros until then.
- cDamageGive / cDamageTake: 0x20 hit position (cVec), 0x40 int reset to -1, 0x44 short reset to 0 (drafts 00262750.c; also 001b90d0.c `unk40/unk44`). cDamageTake lives in cOmBase.h (off-limits), so this waits for the maintainer.
- cGameObj_SetTgtTurn: definition corrected in src/cod/001351d8.c to `void cGameObj_SetTgtTurn(char *self, void *target, float rate)`; retail passes a1 through to Turn_dest as the target. Turn_dest is `float Turn_dest(void *pos, void *target, float angle, float rate)`. About 68 callers declare their own copy (void *a0, int/void *a1, float); one shared prototype belongs in cGameObj.h.
- func_00397550 (sceDmaSync): definition now takes `(sceDmaChan *chan, int mode, int timeout)`, timeout unread; callers pass three args. sceDmaChan and this prototype plus func_003973E8 (`void (int *chan, int tag)`) want a shared DMA header.
- func_002A8578: callers declare at least three different parameter orders; the definition is `(int a0, int a1, int a2, int a3, int t0, int t1, float f12)`. One shared prototype in cEm00.h.
- Held NM handoffs for the checkpoint: cSubScr_SubScrOn (gameWork.h flags5D8/5E0) and func_001F0A28 (cEmWrap.h `unsigned char entryNo` at 0x00; ColiseumBattle_DefeatAllEnemies takes an unread `ColiseumBattle *self`).
- The retail "0/1 then andi 0xFF" index test appears again in func_0026B240 (cOmBase_childAt-style lookup). Same maintainer question as batch 150.

## Batch 152 (local, not merged)
- HELD for checkpoint: Set_bg_mode matches (build/scratch/0030e5c0_ckpt.c, goes in place of its INCLUDE_ASM in src/cod/0030e0.c, already SN). It uses a local view of D_007474A0; needs gameWork.h fields `unsigned long bgA : 15` at 0x270 and `unsigned long bgB : 15` at 0x3E0 (64-bit words, rest of each word untouched) and `int bgColor` at 0x60C (r | g << 8 | b << 16). Then switch the file to GameWork.
- cEm00.h: 0x738 is the held weapon/effect object (`void *`), released with func_001D0408 and cleared (cEm00_setGoto in 0026e988.c, 002705d8.c, 0024c0f0.c, 00246698.c all use the raw offset). Split unk734[0xC].
- func_00241908 (drafts/cod/00241908.c): the level switch 1..5 only builds retail's table with identical arms; question for the maintainer.
- D_003C3BC8, D_003C2380 / D_003C23A4 (int vs FontWork * / MenuObj *), D_003C2384 (int * vs char **): conflicting declarations across files.
- IconScreen (drafts/cod/0013db50.c local view: state 0x92, panel[5] CustomIDWork at 0x120, flashStep 0x38C, flashTimer 0x390); caller 0013d540.c uses raw offsets.
- cSceAtUnit is defined twice with different fields (cSceAtUnit.h and cSceAtManager.h); merge into one type.
- HELD for checkpoint: cMovie_Start matches (build/scratch/002b4be8_ckpt.c, SN; needs a new TU src/cod/002b4be8.c since src/cod/cMovie.c builds with Cygnus and holds only this INCLUDE_ASM, so that file would be left empty). Retail reads D_00747A80 and D_00747A84 as records, not scalars: declared as plain ints, cc1's fixed-scalar alias rule moves their loads above the busyMask / player stores. D_00747A84 works as the existing cSaveLoadTail (`unk58` is the movie-playing word, bit 0x2000: name it, e.g. `sysState`). D_00747A80 (the pad-lock bit word, GameWork 0x5E0) needs one header record type; today 001004c8.c, 002c3c10.c, 00107f20.c, 00113f68.c, 00319848.c declare it `int` and 001f6b78.c `unsigned int`. Check those still match after the change. The ckpt file uses a local `FlagWord` placeholder for it.
- cSaveLoadTail's comment says D_00747A84 = D_00747A2C + 0x58, while gameWork.h calls D_00747A84 GameWork 0x5E4 `flags5E4`; same word, two names. Merge.
- Held NM handoff for the checkpoint: func_001A4010 (vu0.h `VU0_VSCALE_XYZ_TO`, in-out form of VU0_VSCALE_XYZ_MEM; new TU src/cod/001a4010.c with fp_hazard_rules "fdiv").
- 64-bit field idiom note for reviewers: cc1 2.95's fixed-scalar alias rule matters. A global declared as a plain scalar never aliases a struct field reached through a pointer, so loads of it move above such stores. Retail code that keeps those loads in place (cMovie_Start: D_00747A80, D_00747A84) had the global as a record or array member.

## Batch 153 (local, not merged)
- Dest_ck (src/cod/002da2d0.c, registered): 001b7ee0.c's local prototype now matches the definition, `int Dest_ck(float *from, float *to, float cur, float max)`. It sits next to Turn_dest (002da038.c, same `float *` arguments); a shared header for the 0x2DA000 yaw helpers would hold both.
- HELD for checkpoint: SetEffect matches (build/scratch/00306528_ckpt.c, SN, plain flags; new TU src/cod/00306528.c). Signature `int SetEffect(int kind, int id, void *owner, cEffectParam *param, int handle, void *owner2)`; owner2 == (void *)-1 means "same as owner". 65 files call it, through about 60 local prototypes that disagree with each other (void vs int return, K&R `int SetEffect();` in 0016acd0.c, param as int/void*, owner2 as unsigned). It needs one prototype in cObjBase.h (next to cEffectParam), and each caller fixed to it, with every caller rechecked.
- SetEffect builds its default cEffectParam in field order (unk44, flags, unk4C, unk4D, unk4E, unk4F), unlike cEffectParam_init, which stores unk4C/unk4F first; the ckpt file has it as a local inline `SetEffect_defaultParam`. Move it to cObjBase.h beside cEffectParam_init under a descriptive name. The tail (unk70, unk72, unk74, unk78 = 0) matches cNodeDrawState_initAll in 00302790.c, whose cNodeDrawState is another view of cEffectParam (merge the two types).
- func_003066D0 (asm, SetEffect's callee) is declared in the ckpt file from what SetEffect passes: `int (int type, void *data, void *owner, void *owner2, cEffectParam *param, int kind, int handle, unsigned short id)`.
- HELD for checkpoint: func_0028D138 matches (build/scratch/0028d138_ckpt.c, SN, `extern_jtbl D_0044A120`; new TU src/cod/0028d138.c). It hands a weapon to an enemy and stores it in one of two cEm00 slots that cEm00.h keeps as padding: 0x1634 (the held weapon) and 0x1648 (the second weapon, kind 0x369). Add `cOmWeapon *weapon` at 0x1634 (split unk1624[0x20]) and `cOmWeapon *weapon2` at 0x1648 (split unk1648[0x8]) and drop the ckpt file's EM_WEAPON/EM_WEAPON2 offset macros. Its switch lists 0x361, 0x362 and 0x3B7 with `default:`: retail's table spans 0x361..0x3B7, and cc1 only builds it with at least nine case values, so one more default-group weapon kind is needed. 0x362 is a guess from the weapon list in 0026aa30.c; any listed kind in range gives the same bytes.
- cOmWeapon_setParent (cOmWeapon.c) and Obj1D00_ClearState_8 (001d00.c) have no header prototype. Several callers declare them K&R (`int cOmWeapon_setParent();` in 0028d500.c, 0027b810.c, 001867e8.c, 0028d3d8.c) or with other types (`Obj1D00_ClearState_8(char *)` in 0027b810.c). Put both in cOmWeapon.h / objField.h and fix the callers.
- HELD for checkpoint: func_0026AB20 matches (build/scratch/0026ab20_ckpt.c, SN, `extern_jtbl D_00445440 D_004455A0`; new TU src/cod/0026ab20.c). It is the same grip pick as func_0028D138 (same table of offsets, rotations and hands; the mirror test reads cEm00.unk17C3 instead of unk434 & 2), then stores the weapon in a slot chosen by kind: 0x6EC (default), 0x6F0 (0x366), 0x6F4 (0x36D), 0x704 (0x375/0x377/0x378), 0x734 (0x369). cEm00.h calls 0x6EC `int unk6EC` (a handle) and 0x6F0/0x704 `int fx0`/`fx5` (effect handles); here they hold cOmWeapon pointers. Retype and rename those slots, drop the ckpt file's EM_WEAPON_SLOT offset macro, and check 00254450.c / 00255eb0.c (which test unk6EC) still match. The grip pick repeated in both files should become one shared macro in a header (it only differs in the mirror condition).
- HELD for checkpoint: func_0027CB58 matches (build/scratch/0027cb58_ckpt.c, SN, `extern_jtbl D_00448150`; new TU src/cod/0027cb58.c). It writes the float at cEm00 0x15D4 (a turn angle: 0027bb78.c steps it with Turn_dest_dir and copies it to a part's rot.y; 0027ce70.c and 0027b810.c clear it through `*(int *)` raw offsets). Add `float turn` at 0x15D4 to cEm00.h (split unk15C8[0x2C]) and switch all four files to it; the ckpt file's EM_TURN macro goes away. cEma2.h already pads 0x15D4.
- func_002A8578 (the enemy motion start, asm) is declared locally in many files with the int and float arguments in different orders (0027ce70.c: int a3, float a4; 0025c1d0.c / 00243fa0.c: float, int). Both orders give the same registers; pick one prototype for cEm00.h. Same for moveMotion (void * vs cObjBase *), SetEffectPos, fRand0_1/fRand1_1 and cHeatSys_AddHeatGage (no header prototype; cHeatSys.c defines it with cHeatSys *).
- cEmSetParam_setEmAll (src/cod/enemy/cEmSetParam.c) is blocked on one type per record: the room enemy entry is cEmSetEntry in cEmSetParam.h and cRoomSaveEm in cRoomSave.h (same 0x18 bytes, different field names: entryNo/id, done/dead), and D_005E8658 is a cEmSetTable in cEmSetParam.h while cRoomSave_getEm / func_002BEDD8 (which setEmAll calls on it) take a cRoomSave *. Merge the two entry types and give D_005E8658 the cRoomSave type, then setEmAll can be written against cRoomSave_getEm / func_002BEDD8 / cEmManage_EntryEm with SET_EM_DATA (its stack record is exactly SET_EM_DATA). cEmSetParam_setEm's K&R `cRoomSave_findEm()` prototype goes with it.
- func_002C1D68 (scene hit unit -> check volume) needs header work first: cSceAtUnit fields at 0x04 (a 0x30-byte shape record, copied whole into the caller's volume as a 4-byte-aligned struct assignment; its byte 1 is the kind, 1 = four corner points, 2 = one point), 0x47 (signed char yaw offset in 2-degree steps), 0x48 (the object the unit is attached to) and 0x4C (short child index, < 0 for the object itself); flags bits 0x10 (no yaw) and 0x20 (add the object's yaw). The shape record should be shared with the AreaVol view in drafts/cod/002c1ae0.c and cArea_HitCheck_1F83E8's argument.

## Batch 154 (local, not merged)
- HELD for checkpoint: func_0012BC00 matches (build/scratch/0012bc00_ckpt.c, SN, `extern_jtbl D_0041D180`; new TU src/cod/0012bc00.c). It launches a cOmbe (actor 0x3BE) from the player. It needs two player.h changes: (1) `cObjInitVt.init` returns `int`. The cOmbe entry at vt+0x44 is func_001BBB28, `int` in 001551c0.c, and it returns 1. With `void`, the function pointer and the table swap v0/v1 at the call. func_0031C4E0 (the other user) still matches with `int`, checked by match_check. (2) A shared prototype `void func_0012BC00(cGameObj *self, int kind, unsigned int spread);`. 00111a20.c, 001120a8.c and 00111dd8.c declare it locally as `(void *, int, int)`. `spread` is unsigned: retail tests the below-1 leaf of the 0/1/2 switch with `beqz`, which is only valid for an unsigned compare. A signed int gives a range test or a longer tree.
- CreateObj: the definition in src/cod/00306200.c is `int CreateObj(int a0)` and calls func_0030FAC8/func_0030FB20 with no prototype in scope. Retail forwards a1 untouched to func_0030FAC8, which reads it, so the definition drops a real argument. player.h already has `cGameObj *CreateObj(int kind, int id)`. 16 files declare it locally with 5 different return types (char *, void *, cGameObj *, FxObj *, BlackJackCardObj *); casino/Poker.c is off-limits until the objects/minigames PR merges.
- pl00.h: 0x640 is the locked-on target (`cGameObj *lockOn`). func_0012B618 reads it (draft drafts/cod/0012b618.c, local view pl00ThrowView), and 00124c30.c, 00124e68.c and 0012cc70.c use raw offsets for it.
- HELD for checkpoint: func_00133DA0 matches (build/scratch/00133da0_ckpt.c, SN, plain flags; new TU src/cod/00133da0.c). It is the box solid's debug draw (vtable D_0041D790): the twelve edges of the eight corners at 0xF0. Two header changes: (1) `cCollisionSolidBox` (cCollisionSolidObj base, `cVec corner[8]` at 0xF0) goes into cCollisionSolid.h. (2) Draw_Line2 has no definition and no header prototype. Retail compares n with sltu and sets no return value, so `void Draw_Line2(void *pts, unsigned int n, unsigned int color, int flag);` goes in a shared header, and 0014b9a0.c (which declares it `(void *, int, unsigned, int)`) includes that header.
- func_0037FAC8 (skipped): a twin of func_00385138 over a 0x48-byte entry array at MenuCtl+0x48, indexed by byte 5, with the stream info at entry+0x10. It calls func_00380EB0, whose definition in 0014ea28.c is `void func_00380EB0(int, int, int)` with raw offsets, while menuCtl.h declares `(MenuCtl *, MenuInfo *, MenuList *)`. Fix the definition to the typed form (it reads info+0x30/0x34 and list byte 0), add the entry type to menuCtl.h, and then this one is straightforward.
- cModel.h: cParts 0x150 is a float twist angle (`unk150[4]` today), applied when partFlags bit 0x800 is set. The enemy upper-body turn func_00269B50 writes both (draft drafts/cod/00269b50.c, local view EmTwistPart). Name the field and the bit (e.g. `float twist;`, `CPARTS_TWIST 0x800`). cEm00.h `unk16F4` is the accumulated body turn angle, not the motion-start argument its comment says; rename it.
- func_00275978 (draft drafts/cod/00275978.c, one branch target from a match with `cmppad`): the enemy aim point. It needs (1) cEm00.h: `cVec aimPoint` at 0x1680 (the function returns its address) and 0x744 retyped from `int unk744` to `cEm00 *partner` (00214298.c and 002580b8.c test it and pass it on); (2) a child getter that keeps the result in a local (`c = children[idx]` / `c = 0`, then `return c`). The shared cOmBase_childAt form loads the child straight into its final register; cOmBase.h is off-limits, so it would go in cEm00.h as a cEm00 helper; (3) a wrapper hazard rule that pads a bc1* whose previous line is a label (retail's cc1 pads at the label, after the cross-jumped compare tail). That's a tool change in scripts/ee-cc-wrap.py for Jon to approve.
- HELD for checkpoint: cModel_calcParts (NM handoff, verified MATCH with `as: "sn"`; new TU src/cod/00149eb8.c). Before registering it, Adjust_theta_vec and func_001501D0 need one shared prototype in cModel.h. Today 001aa188.c, 00173ec0.c, 0019ca58.c and 002fd530.c declare `Adjust_theta_vec(float *)` while 0013b9b8.c has `(cVec *)`, and 001733b0.c / 00182ff8.c declare `func_001501D0(int, int)` where the part argument is a `cParts *`. func_00156D70 (`cParts *dst, cParts *src, float *mtx, float blend`) goes in cModel.h with them. Recheck the callers after the change.

## Batch 155 (local, not merged)
- HELD for checkpoint: KeyStop matches (build/scratch/0031afa0_ckpt.c, SN, plain flags; carve from src/cod/000000.c into a new TU src/cod/0031afa0.c). It ORs 0x2000000 into the word at GameWork 0x5D8, then calls func_0031B410(D_005E8140, &GameWork+0x178). The two addresses must come from one global (retail derives 0x178 from 0x5D8 with -0x460), so both have to be GameWork fields, not separate symbols. Header work: (1) gameWork.h: GameWork 0x178 starts the key state record that func_0031B410 clears (it masks +0x00/+0x18/+0x28/+0x30/+0x38/+0x40, so `trg` 0x1A0, `unk1A8` and `rep` 0x1B0 sit inside it); give it a record type (e.g. `KeyState key;` from 0x178 with trg/rep as its fields) or at least name 0x178. (2) GameWork 0x5D8 is the lock word (bit 0x2000000 = keys stopped) and is the same word as GameSys.unk4C (D_00747A2C + 0x4C, "bit 0x04000000 pauses pad vibration"); one name for it. 00149488.c (`unsigned int`), 0030eee8.c / 001004c8.c / 002c3c10.c (`int`) declare it as the scalar D_00747A78. (3) D_005E8140 (the pad work, classPAD_WORK) is declared `char []` locally in 001a4430.c, 0030b298.c and 002bdc00.c; it needs one header declaration. func_0031B410 (`void (int arg0, void *a1)`, cygnus TU 0031b410.c) has no header prototype.
- cIDBase_getIDWork (draft drafts/cod/002aa410.c): callers disagree on its return type. 001627d8.c declares `int cIDBase_getIDWork(void *, int)`; 00140718.c, 00143be8.c and cIDBase.c use `cIDBaseEnt *` (with `void *` or `cIDBaseObj *` self). When it matches, put one prototype in cIDBase.h (`cIDBaseEnt *cIDBase_getIDWork(cIDBaseObj *self, int id)`) and check 001627d8.c still matches with it. D_005CB300 is the dummy cIDBaseEnt (002acbe8.c declares it `char []`).
- func_00244398 (registered, src/cod/00244398.c): cEm00 0x730 (`int unk730`, "effect handle") is the weapon the enemy holds: it is passed to func_001D0108(cOmWeapon *) (definition in 00148f28.c). Retype it `struct cOmWeapon *weapon` and drop the cast in 00244398.c; 0024c0f0.c and 0025e600.c read it as `*(void **)(self + 0x730)` and declare func_001D0108(void *). ChkLine (no C definition; 13 args, a6 is a pointer in 0017d488.c and an int in 00275888.c / 00280be0.c / 0025adc0.c) needs one prototype in a header. cCollisionSolidManage_SetActive is defined (int, int, int) in 001351d8.c; 0025c1d0.c and 00243fa0.c declare (void *, void *, int).
- ChkLine's fourth argument (a3) is a pointer too: func_0024BB68 (draft drafts/cod/0024bb68.c) passes a cVec for the hit normal there and a HitPoly ** in a6. Shared prototype: `int ChkLine(void *from, void *to, void *hit, void *normal, int a4, int a5, void *poly, int a7, int a8, int a9, int a10, int a11, int a12)`; 00244398.c and 00248d00.c already declare it that way. HitPoly {int; unsigned int surface @0x4} is also local in 0017d488.c (as HitRec).

## Batch 156 (local, not merged)
- HELD for checkpoint: cCollisionSolidManage_ChkHit matches (build/scratch/001348e8_ckpt.c, SN, plain flags; new TU src/cod/001348e8.c). It refreshes the bounds of obj's collision unit, tests each active solid against the active solids of every other unit (sphere/sphere func_00134CB0, sphere/box func_00134E18 with a swapped flag, box/box func_00135040), sets bit 1 on both solids of a touching pair, lists up to 32 owners hit and returns 1 on any hit. Header work in cCollisionSolid.h:
  (1) cCollisionSolidObj: 0x00 is the next solid in the unit (`struct cCollisionSolidObj *next`, today `int unk00`), 0x10/0x20 are the solid's bounds min/max (today unk10/unk20), 0x30 is a vtable whose entry at 0x18 is a (short this-delta, function) pair that refreshes the bounds. Flag bits: 0x1 active, 0x2 hit this check.
  (2) A unit type (`cCollisionSolidUnit`: 0x00 cGameObj *owner, 0x04 first solid, 0x10 next unit, 0x20/0x30 cVec min/max of all its solids) and a manager type (`cCollisionSolidManage`: 0x00 first unit, 0x08 cGameObj *hits[32], 0x88 unsigned int hitNum; hitNum is compared with sltiu).
  (3) The header's `int cCollisionSolidManage_ChkHit(void *mgr, void *obj)` becomes `(cCollisionSolidManage *self, cGameObj *obj)`; check its callers still match. func_001346C8 (unit of obj), func_00135250 (box overlap of two min/max pairs), func_00134CB0, func_00134E18, func_00135040 are asm; their prototypes come from what ChkHit passes and belong in the same header.
  (4) The solid flag word is read with lwu + andi 1, written in the 64-bit idiom at bit 0 (`long active = (unsigned int)a->flags; if ((active & 1) == 0)`); scrFlags bit 2 (tested before suspend bit 3) has no GAMEOBJ_SCR_ name yet.
- func_0016AE38 (registered, src/cod/0016ae38.c; per-file settings `as: sn` and `extern_jtbl D_0041FD90`): the menu panel object (state byte 0x5A, timer 0x60, cursor 0x1B4, 0x1D0/0x1D2, toggle 0x1D4, the 0x202/0x204 shorts Obj0000_Set_Short_202/204 read) is a local `MenuPanel` view; 001680d8.c reads the same record with raw offsets. It belongs in a header shared by both. D_003BD930 (the option/save record whose byte 0xEDD picks the four- or two-row menu) is `char *` in 0016ae38.c / 001680d8.c and `void *` in 0030eee8.c / 0030b728.c; one declaration in a header. The pad masks 0x0008000004000000 (down) and 0x0004000008000000 (up) are also literals in 001d2888.c; name them once in gameWork.h next to trg/rep.
- HELD for checkpoint: func_00146A18 matches (build/scratch/00146a18_ckpt.c, SN, `extern_jtbl D_0041E8A0`; new TU src/cod/00146a18.c). It is IdPair's banner step (IdPair_init's object): slides entry 0 down, grows entry 1, shows the queued message for 90 frames, shrinks and lifts it, then pops the two short queues and re-inits. Header work: (1) IdPair moves out of 001468b0.c into a header (e.g. idPair.h) with the full layout: cIDBaseObj base 0x00, signed char state 0x79 (IdPair_init clears 0x79..0x7C; this step reads 0x79 with lb), cIDBaseEnt *work[4] 0x90, cIDBaseObj part2 0xA0, unsigned short msgQueue[4] 0xF0, altQueue[4] 0xF8, short count 0x100, short timer 0x102, unsigned char flags 0x104; both files include it. (2) cIDBase_getIDWork's entry is a cIDBaseEnt here (src 0x1C, posX/posY 0x38/0x3C, flags 0x2C, sclX 0x40, rotSpeed 0x48, msg 0x90). 001468b0.c reads the same entry as CustomIDWork (offsAmp[0] at 0x3C = posY), so CustomIDWork and cIDBaseEnt describe one record; merge them or pick one per the one-type-per-record rule, then the single prototype `cIDBaseEnt *cIDBase_getIDWork(cIDBaseObj *self, int id)` in cIDBase.h. cIDBase_move (`void (cIDBaseObj *)` in cIDBase.c) also has no header prototype; 7 files declare it with void *. (3) D_003C23A4 is `int` in cMessDrawFontCode.h and `void *` in 0030eee8.c / 001169d8.c; the step writes the short at +0xBEE (the message id the banner shows). Give it a pointer type and name the field.
- func_001D7560 (draft drafts/cod/001d7560.c, poker bet step, 11 register-only diffs): two callee definitions disagree with what retail callers pass. SetBlendField1D4_1DDB10 (001c2c00.c, with its siblings SetBlendField348_1DDBB8 etc.) is defined `(void *a0, int a1, int a2)`, but a2 only feeds bytes that are all overwritten (the colours are constant 0x50606060 / 0x80A0A0A0) and callers pass two arguments; the definition should be `(void *self, int on)` with the colour built some other way, rechecking 001c2c00.c. NoOp_1DCE60 (000000.c) is defined `(void)` but callers pass self; make it `void NoOp_1DCE60(void *self)` with a "not read" line. A shared `Poker_setState` inline (phase = 0, then state) belongs in Poker.h after the minigames PR merges (same idiom as PanelOwner_setStep in 001468b0.c).
- Note on func_0016AE38's MenuPanel: 001680d8.c is in the open objects/minigames PR, so moving the panel type into a header shared with it waits until that PR merges.
- func_00167908 (registered, src/cod/00167908.c; per-file settings `as: sn`, `extern_jtbl D_0041FBD0`): the options panel step. func_00167EB0's definition (00167eb0.c, its only caller is this function) now takes `void *self` (not read), as retail passes it; still matches. D_005E8140 byte 0x4B8 is pad vibration on/off (read with lbu: `unsigned char`); joins the D_005E8140 header item from batch 155. OptionPanel (0x5A state, 0x60 timer, 0x110 row) is another view of the menu panel record (see MenuPanel in 0016ae38.c). SetGlobalToggle_375700 (`void (int)`, 00137aa0.c) sets the sound output mode Obj0000_Get_D_0076A7A4_3756F0 returns; its prototype belongs in seqNode.h next to the getter.

## Batch 157
- func_002BC950 (segment walk; also func_001646C0, a Hermite spline returning a vector by value, callers 002bd078.c/002bc6c8.c) and func_002FDE60 (world-to-screen projection): retail is SN C++ with a VU0 vector class: zeroing constructor (sqc2 $vf0), copy through $vf4 (lqc2/sqc2), operator= that checks `this != &rhs` and copies x/y/z, operators returning by value (sub, unit, scale, add) whose temporaries share stack slots. Needs a shared C++ vector header and an SN C++ unit setup before these can be matched; skipped for now.
- func_002D8C60 (registered, src/cod/002d8c60.c): declares `extern cWorldLight D_00604700;` locally; 0012e990.c and others declare D_00604700 as `char []`. One declaration in cWorldLight.h (`extern cWorldLight D_00604700;`), with the char users switched to it. The preset table D_0061A400 is D_00604700.preset; the fade reaches it through the object, and the build's two %hi relocations against D_00604700 link to retail's bytes (both hashes OK).
- EspAnim: 001496c0.c (EspAnim2), 0011a820.c (EspAnim) and drafts/cod/002fbfb0.c each define a local view of the same effect object (data 0x110, lock byte 0x11D, vtable 0xF0, pos/vel 0x124/0x134, frame fields 0x224..0x230 and 0x23F..0x2A0, 0x24C..0x250), and EspData twice. One header (e.g. espAnim.h) with the merged layout and the shared prototypes (EspAnim_step, UpdateObjByIndexedOp_2FBE50, func_002FA350, func_002FC1A0).
- func_0037C720 (held, build/scratch/0037c720_ckpt.c, not matching yet): needs sndTiming.h `int unk14` at 0x14 (split unk14[8]; zero = the output mode that pans every voice hard to one side) and seqNode.h SeqNode `short unk40` (pan source, divided by 4) and `short unk42` (pan angle in degrees) at 0x40/0x42 (split unk40[4]). Then it becomes a draft. Retail reuses the D_0076A600 base and the 0x84 stride registers from before the loop; this build hoists fresh copies into two more saved registers.
- cSescr (drafts/cod/002c8cf8.c): the sound-script trigger record (flags 0x0C, shape 0x0D, dist 0x10, state 0x13, voice 0x14, area 0x20 with sizes 0x24/0x26, pos 0x30, dir 0x40) is read with raw offsets in 002c8b68.c; cSescr_At_ck belongs in that unit (it starts where func_002C8B68 ends). When it matches, the type goes in a header or at the top of 002c8b68.c, and func_002C8B68's local `cSescr_At_ck(void *, int, void *, float)` becomes the real `int (cSescr *, cVec *, cVec *, float)`.
- cOmBase 0x154 (child body flags; bits 8 and 0x10 set at setup by func_0018F218, draft drafts/cod/0018f218.c) has no name in cOmBase.h (off-limits until the objects/minigames PR merges); 001799f8.c also uses the raw offset.
- GoldScreen (drafts/cod/00143670.c) and IDSlotScreen (00143998.c) are one record, the gold counter display (cIDBaseObj at 0, base2 0xB0, gold 0x90, entries 0x94..0xA0, popup arrays 0x100..0x1B0, mode bits 0x1C0); S143598 in 00143598.c is a third view. One header type. cScenario 0x14 (a running flag the gold label waits on) has no name in cScenario.h.

## Batch 158
- libgraph GS store image: 003958d8.c (sceGsExecStoreImage, bitfield sceGsStoreImage), 00395618.c (func_00395618 = sceGsSetDefStoreImage, sceGifTag-based sceGsStoreImage) and 0030e660.c (GsStoreImageWords) each define the same packet differently, and drafts/cod/002f1758.c adds a fourth (word view). One header (e.g. sceGs.h) with one sceGsStoreImage layout, the prototypes `int func_00395618(sceGsStoreImage *, short, short, short, short, short, short, short)`, `int sceGsExecStoreImage(sceGsStoreImage *, qword *)`, `unsigned long Tramp_GsGetIMR_3964A0(void)` and `unsigned long func_00396008(unsigned long)` (sceGsPutIMR wrapper returning the old mask), included by all four.
- Lens flare state (0x2F1200..0x2F1AA0): D_0061B660 is the flare's screen position (cVec: x, y, depth z; z = -1 means no test this frame); 002f1aa0.c declares it as a 16-byte `QWord`. D_0061B670 (visible byte), D_0061B672 (reference depth, u16), D_0061B674 (sample count), D_0061B680 (u16 Z row, 16 entries), D_003C3BB0 (visible byte), D_003C3BB4 (fade float), D_0044EC60 (six signed tap offsets). One header declaring them with these types.
- objScroll (vtable D_00450CE8, init func_003187D8, draft drafts/cod/003187d8.c): a cObj subclass. cObj.h needs the flag word at 0x2F0 named (split unk2E4[0x10] into unk2E4[0xC] + int at 0x2F0; 0012ce20.c, 00276808.c, 00100378.c, 00347968.c, 00292e80.c write it with raw offsets). The object adds unk310 (cVec, from D_003BD890), set 0x320 (setup record), uvSpeed[2] 0x324, bytes 0x32C..0x32E, short 0x330, startRot 0x340 (cVec, radians), bit array 0x350 (func_0031A088/func_0031A0B8 set/clear bits). The setup record's flag word at 0x34 uses the CMODEL_MESH_* bits (0x10 hidden, 0x100000, 0x200000 special, 0x1000000 back), so it may be cMeshInfo (cModel.h, flags `unsigned int` there but read with lw + dsrl here); its 0x3E/0x40/0x48 are F16 values, 0x44 the life in seconds, 0x4C..0x54 the start rotation in degrees. func_00319CC0/func_00319E00/func_0031A088/func_0031A0B8/func_0031D2F8 take `void *`/`char *` today; they are objScroll methods and want an objScroll header with their prototypes. D_003BD890 is `float []` in 0014b9a0.c, a cVec here.
- HELD for checkpoint: func_0026B600 matches (build/scratch/0026b600_ckpt.c, SN, `extern_jtbl D_00445620`; new TU src/cod/0026b600.c). Enemy 0x211 throws out eight rocks (actors 0x3B8..0x3BA). Header work: (1) cGameObj.h cGameObjVt: name the pair at 0x40 `short initDelta; short pad42; int (*init)(void *self);` (objScroll's vtable has its init, func_003187D8, there; 0026b9e8.c calls it through raw offsets). (2) cEm00.h: split unk70C[0x24] into unk70C[0x4] + `struct cGameObj *rock[8]` at 0x710. (3) The CreateObj definition fix already listed (`cGameObj *CreateObj(int kind, int id)` in 00306200.c including player.h, forwarding id to func_0030FAC8); the ckpt file uses player.h's prototype. irand (int, 001004c8.c), fRand1_1 (00292f50.c), cSnd_SeCall_2CBA48 (002cba48.c) and D_005FEE00 are declared locally in many files; a shared header for each would be the follow-up.

### HELD func_0010F720 (player rush punch; build/scratch/0010f720_ckpt.c, proven by build/scratch/0010f720_vE.c)
- extern_jtbl: D_0041BD40 D_0041BD60 D_0041BD80 D_0041BDA0 D_0041BDC0.
- cGameObj.h: split unk308 into unk308[0x330-0x308], `cVec nullSpeed; /* 0x330 speed of the null part, as in cObjBase */`, unk340[0x3AC-0x340].
- cGameObj.h: move `motionBlock_at(char *block, int ofs)` from 002897f0.c into the header (two users now).
- pl00.h: split unk5AC: unk5E0/unk5E2 (short), unk600 (float, times 5 or 10 is the hit damage), unk608 (float, angle; compared to pi/2), unk61F (uchar), `cGameObj *lockTarget` 0x640, `unsigned char lockHold` 0x648; split unk6AC: `float stateMove` 0x1588, `int stateWork[4]` 0x15B0 (scratch the current state owns); after comboTimer: `char unk1684` 0x1684.
- gameWork.h: `int padBtn; /* 0x08 face-button bits, 0x10-0x80 */` (retail reaches it as D_007474A8; 12 files declare `extern int D_007474A8`, convert later).
- 00134880.c: func_002A8578's definition becomes `(int a0, int a1, int a2, int a3, float f12, int t0, int t1)` (the caller's argument order only matches with the float fifth; the callee's code is the same). 0010cd38.c, 00244398.c and 00248d00.c already declare it that way; no caller copies the old order.

### HELD func_00112CB8 (player god-hand roulette finisher; build/scratch/00112cb8_ckpt.c, proven by build/scratch/00112cb8_t.c)
- extern_jtbl: D_0041C1D0 D_0041C1F0.
- Needs the func_0010F720 header work (pl00 fields, cGameObj nullSpeed, motionBlock_at) plus pl00.h: `unsigned char godUsed` 0x649 (set once the god item is spent for the move), `float unk674` 0x674, `int unk15F4` 0x15F4.

### HELD func_002FD078 (effect node scale update; build/scratch/002fd078_ckpt.c; per-unit as=sn, fp_hazard_rules fdiv)
- Its local espScaleNode/espScaleRec describe the same effect node as StepObj/StepRec in src/cod/002fc9a8.c (rec 0x110, flags 0x11C, frame 0x22E, time 0x234, limit 0x238). Merge into one header type (e.g. include/godhand/espNode.h: espNode with rec, flags, scaleMode 0x140, the 0x144 scale union, frame, prevFrame 0x230, time, life) and use it in both files.
- D_00747A84 (unsigned int) and D_00747A14 (float, GameWork.timeScale under its own symbol) are declared locally like the other users; gameWork.h could carry them next to D_00747A24.

## Batch 159
- TIM2 picture header: 003092e0.c (TexHdr, GsTex0) and drafts/cod/00309568.c (Tim2Pic, the same GsTex0) describe the same 0x30-byte record (totalSize 0x00, clutSize 0x04, imageSize 0x08, headerSize 0x0C, clutColors 0x0E, picFormat 0x10, mipmaps 0x11, clutType 0x12, imageType 0x13, w/h 0x14/0x16, tex0 0x18). One header (e.g. include/godhand/tim2.h) with GsTex0 and the picture header; drafts/cod/0030d258.c also defines sceGsLoadImage as a 0x60-byte blob next to libgraph's own definition in 00395430.c.
- D_00747B00 is a zero cVec (compared component by component in drafts/cod/002f7e30.c); 00171020.c, 001ad5c8.c, 00170050.c and merged_orphans_e.c declare it as int/char/float arrays. One `extern cVec D_00747B00;` in a header.
- func_0030AC38 and func_00306D10 (src/cod/0030ac38.c, 00306d10.c) are empty and defined `(void *a0)`, but their only callers (func_0030AC40, the main loop, and func_0030B728) pass nothing; both definitions should be `(void)`, and 0030b728.c's local prototype of func_00306D10 then agrees.
- GameWork (gameWork.h) fields the main loop func_0030AC40 uses (scratch build/scratch/0030ac40_t.c): 0x214 int (sceGsSyncV result), 0x55C float (frame time, 1.0 or 0.5), 0x560 int (2 or 4), 0x568 byte (30 or 60, frames per second; today pad568), 0x570 int (frame wait), 0x5D9 byte (bit 7), 0x604 float (fRand1_1 each frame). The loop itself needs a backward goto (retail hoists the invariants only before the inner loop), so it stays unmatched.

## Batch 160
- espModel (src/cod/002f2250.c, local type): link 0x120, color 0x188, frameNum/frameNo 0x24C, model 0x2B0, uv speed/amp/wave/phase 0x2BC..0x2D4, uvMode 0x2E9, uvScale 0x2EC, uvRot/uvRotSpeed 0x2F4/0x2F8. Wants an esp effect header with the shared esp node base (link at 0x120, objFlags).
- espPtcl / espPtclData / espPtclParent (src/cod/00302f68.c, local types): particle data 0x100 (life 0x1A0, accel/drag/wind/gust curves 0x1D0..0x224), parent 0x104 (pos 0xB0), offset 0x134, base 0x140, vel 0x14C, wind 0x164, time 0x180, delay 0x186, attached 0x18A, scale 0x1A0. Same esp header.
- espRibbon (drafts/cod/002f5788.c) and CamSphere (drafts/cod/001067b8.c) are draft-local types for the same header pass.
- Shared prototypes still declared locally: capVu0Sin, capVu0Cos, MtxMultiply, MtxCopy, capVu0ApplyMatrixXYZ, capVu0Length, ChkLine (callers disagree on a6: `int` in 00275888.c/00280be0.c, `void *` in 0017d488.c/0012c7d0.c; retail passes it straight to func_0012ED60's eighth argument, a pointer) and func_0012ED60 (14 arguments; the collision grid line probe, `(cGrid-like *db, cVec *from, cVec *to, void *hit, int, int, int, void *, int, int, int, int, int, unsigned char step)`). One collision header for ChkLine/func_0012ED60 next to cGrid.h.
- cOmWeapon_setThrowPL needs a prototype in cOmWeapon.h.
- Collision grid: drafts/cod/001321d8.c defines cCollGrid/cCollCell locally; func_0012ED60 (line probe) walks the same cells (cells 0x18, index 0x1C, dims 0x64/0x68, cell range 0x6C..0x80, probe state 0xB0..0x18C). cGrid.h (0x30..0xAF) is the same record's first part; one header type.

## Batch 161

- cEmWrap.h: cEmWrap is 0x10 bytes (unk08[8]); three files had private 16-byte copies (EmHandle in 001f1038.c and 001b0d30.c), now merged into cEmWrap. Shared prototypes for cEmWrap_isDead, cEmWrap_GetVital, cEmWrap_GetVitalMax, cEmWrap_setSuspend. cEmWrap_GetVital/GetVitalMax definitions dropped an `int a1` no caller passes (bytes unchanged). Verified by full build (reseed elf=OK overlay=OK).
- ColiseumBattle.h: unkBAC is `unsigned int deadMask` (func_001F1148 reads it with lwu); 00134650.c updated.
- Still to share: ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self) has 20 local declarations (void *, ArenaEm *, void, ColiseumBattle *). ArenaEm in several files is a view of ColiseumBattle; moving the prototype into ColiseumBattle.h needs those files merged onto ColiseumBattle first. cEmWrap_SetVital/SetVitalMax definitions take void *; give them cEmWrap * and share them too. cModel_setMeshDisplay has ~10 local declarations (void *model) against the definition's cModel *; two include cModel.h, so moving it into cModel.h means fixing 001b2708.c and 001e3858.c.
- Slot1.h: endFlag (0x54), atId (0x48C), markSel (0x48E) and `SlotUi ui` (0x4D0); includes SlotUi.h. SlotUi.h: idBase split into idBase[0x50] + `CustomIDWork mark[10]` (0x50) + unk528; includes CustomIDWork.h. func_001E3388 (001dee20.c) takes `void *self` (not read), which its caller passes. Dependents re-checked: 001dee20.c, Slot1.c, 001e2008.c, 0018f488.c, 00138fc8.c, 0013e6e0.c all match. CustomIDPanel.h declares CustomIDWork_SetNumber(void *, int) against the definition's (CustomIDWork *, int); Slot2Marks has four private copies (001a4430.c, 001673d0.c, 001e3c08.c, 00166638.c) that belong in Slot2.h.
- cWorldLight.h (func_002D6F40): cWorldLightBlob4 and cWorldLightExtra.b are unsigned char (retail copies use lbu); new fields lightDataHdr (0x15CF0, the 4-byte header LightData_Load copies in front of the presets), presetOrder[8] (0x16171), unk16194, unk1619C; lightDir offset check; shared prototype for cWorldLight_savePreset (002d82a0.c includes the header). Verified by full build (reseed elf=OK overlay=OK).
- Set_bg_mode: definition (0030e0.c) takes (int, unsigned char, unsigned char, unsigned char); six callers (002bf2d0.c, 00297038.c, 001f7900.c, 00297128.c, JukeBox.c, func_002D6F40) declare it locally, five with int parameters. Needs a home header and a per-caller check that the unsigned char form keeps their bytes.
- func_002D6F40: retail's .s symbolizes two plain immediates as %lo(D_10080) and %lo(D_16171) (splat false symbols from undefined_syms_auto.txt). Words are identical and the full ELF matches, but match_check reports the two lines as missing relocations. Dropping D_10080/D_16171 from undefined_syms_auto (D_10080 also appears as a data word at 0x3F271C) would clear it.
- cFont.h (cMessDrawFont_draw draft): state fields glyphW (0x2A068), glyphH (0x2A06C), unk20 (0x2A070); `extern cFont *D_003C2380` (other files declare it as int, char * or void *: 00113768.c, 001d0fd8.c, 002a5bb8.c, 002b0208.c, 002b0908.c, 002b0d68.c, cMessDrawFontCode.h); CFONT_STATE_RAW for the stores retail makes through a plain pointer; shared prototype of cFont_setDrawState, whose t0 is now unsigned int (it goes to func_002A58D8's unsigned int; 0013e908.c still matches).
- cMessDrawFont.h: flags is int (retail tests bit 2 with sra), cursor is unsigned short *, new cMessDrawFrame (the 12-byte draw settings func_002B0480 fills). No unit read either field by name; every includer re-checked and matches.

## Batch 162
- seqNode.h (func_0037C720): SeqNode 0x40 is `short unk40` (pan source, read with lh) and 0x42 `short angle` (degrees); shared prototype `func_0037C720(SeqNode *self)` (0037cce0.c dropped its local copy). 0037bf10.c still declares it locally as `(void *)` and redeclares D_0076A600 as `char[]` with raw 0x84-byte offsets; it should include seqNode.h and use SndVoiceNode. Verified by full build (reseed elf=OK overlay=OK).
- sndTiming.h: unk14[8] split into `int unk14` (0x14, nonzero selects positional panning in func_0037C720) and unk18[4].
- Sound callees declared locally in 0037c720.c: func_00373A68 (defined `(int *)` in 0031f218.c although it takes a voice node), GetSequenceHandle_373B68, UpdateSequenceState_373708, ForwardSequenceItems_373690 (all `void *` in 00373158.c). A sound sequence header should carry them with SndVoiceNode * parameters. func_003A18F0/func_003A19F8 (cos/sin) are declared in six files; a math header should own them.
- Slot2.h (Slot2_StopReels draft): Slot2Reel gains stopLine (0xC4), stopMode (0xC8), unkCC[3], unkD8[3]; Slot2 gains lineWeight[4] (0x384). Layout unchanged; verified by full build.
- 001e5268.c keeps a file-local `tick` inline for the Slot2 frame timer; the same countdown is open-coded in 001e5d08.c, 001e6498.c and drafts/cod/001e5448.c. One shared form in Slot2.h.
- cOmSetParam_setOmData (skipped): cOmItem_setFixPos is defined `(void *a0)` in object/cOmItem.c but this caller passes the set record in a1; func_001331B8's first argument is declared as char *, int and (via D_005CAE50) char[] / int in 0019fd50.c, 0018b6a0.c, 001b6f38.c; func_002BED08 takes cRoomSave * while cEmSetParam.h types D_005E8658 as cEmSetTable. Needs one prototype each before the function can be written cleanly.

## Batch 163
- cIDBase.h: cIDBaseEnt.flags (0x2C) is now `int` (retail clears IDENT_FLAG_CHILD with addiu -9, the signed form; 002abc18.c already read it through an int local). About 40 includers; verified by full build (reseed elf=OK overlay=OK).
- idSet.h (new): IdSet (0xE8), the id display set func_0013BC28/func_0013BD40 drive; 0013bc28.c dropped its private IdWork/IdSet copies.
- cIDBase_move is declared locally in five files with `void *`; it belongs in cIDBase.h as `void cIDBase_move(cIDBaseObj *self)`.
- gsLoadImage.h (new): GsLoadImagePacket (0xB0) and func_0015E510's prototype. 0015e0a0.c still declares func_0015E510 locally with `void *`.
- Slot1.h: endFlag is `int` (retail clears bit 0x10 with addiu -17).
- newlib: func_003A7D08 is _mbtowc_r; rename after this reseed. strlen/strcmp (func_003A5678) have no shared prototype, and each newlib file defines its own struct _reent view (003a7d08.c uses ReentLocale with _current_locale at 0x34); one newlib reent header.
- cSndSeVoice_Setup / cSndSeVoice_IsActive: callers call them without prototypes and their arguments are local types; needs a sound SE voice header first.
- drafts/cod/00276478.c: matches with `OBJFLAG_SEE_THROUGH 0x10u` (retail's ~0x10 mask on objFlags is lui/ori). Waiting on decisions_needed. D_00747A84 (system flags word) is declared `int` there; other files differ.

## Batch 164

- cRecordIndex.h: record entry fields (flags 0x0C, stage 0x12, needSkill 0x1A) and the index/combo arrays of cRecordIndex; 00143b70.c and 0012b2e0.c still match. Used by the drafts/cod/002c90a0.c draft.
- cModel.h: CPARTS_FIELDS splits unk0D4 into `cVec trans` at 0x0E0 (local position from the part table; drafts/cod/00158198.c copies it).
- cEm00.h: `float hitWait` at 0x15D0 and `cVec hitPos` at 0x15E0 (drafts/cod/0012cae0.c).
- cSceAtManager.h: now declares `extern cSceAtManager D_005FEA60` and FindNodeByHit_2C2490's prototype (as its definition in 002c2138.c). The drafts 001dfde0.c and 00245538.c dropped their local copies. About 20 registered files still declare D_005FEA60 locally as `char[]` or `int`; they don't include the header, so they compile, but they should move to it.
- EntList (00149378.c) and List150418 (00150418.c) gained the size/capacity/count fields at 0x18..0x24 for func_00149400 / func_001504B0.
- EnsureInitThenForward_2A9538_30EE08: the definition (00306200.c) is `void *(int, int, int)`, but files declare it with at least four other signatures (`(void *, int)`, `(int size, int align, void *region)`, returning int). It needs one prototype in heapArena.h; this batch's files declare it exactly as defined.
- func_002A9860 was called with no prototype in scope in 00149378.c and 00150418.c; both now declare it as defined (`int (int, int)`) and pass the list as int.
- cHeap_free: the definition (001b7300.c) takes `(int, struct node *)`; 00150418.c declares `(int, int *)` and others `(void *, void *)`. New code here declares it as defined.
- SetEffect: about ten local prototypes with different parameter types; no header yet.
- cGameObj: cGameObj.h has a typedef named cGameObj, so the constructor `cGameObj()` can't be declared next to it (the factories at 0x313150.. need it). cModel.h solves the same clash with CMODEL_NO_TYPEDEF.
- capVu0Sin has no header (drafts/cod/002d5de0.c declares it).
- Poker.h needs 0x25B0/0x3045 named (frozen until the objects/minigames PR merges).

## Batch 165

- cDoor.h: cRoomJumpGroup (id 0x00, count 0x02, first 0x03) and cRoomJumpTbl (groupNum 0x00, recOfs 0x08, groups from 0x10) moved out of 00193050.c (were RecGroup/RecTable), plus func_002BEAA8's prototype; cRoomJump_getRecord called it with no prototype in scope before.
- seqNode.h: SeqCmd is the full 0x50-byte sound request (used 0x00, id 0x02, flags 0x0C, link 0x12) with `extern SeqCmd D_0076B9C0[SEQCMD_NUM]`; 00377ed0.c dropped its SfxPoolA copy. 00376978.c still declares D_0076B9C0 as `char[]` (doesn't include the header). New: SndCore (two SPU2 cores at D_0076A7D4), func_00374AE0, func_00377CB8, func_0037BE98 and func_0037C330 prototypes; 0037b808.c, 00375f68.c, 00150048.c, 00376e00.c and 00377bc8.c include it instead of declaring them. 00321208.c still views D_0076A7D4 as `char[]`.
- The 0x70-byte channel request at D_0076E590 has three local types (Rq in 00376f18.c, ChanCmd in 003772d8.c, E1 in 00377d80.c), and the channel at D_0076E910 is `Ch` in 00376f18.c but SndCh in seqNode.h. One header type each would unblock func_00376EA0.
- menuCtl.h: MenuList.f84 is `MenuDir *dir` (the loaded file table, count at 0x04); 00385078.c and 00384ec8.c pass it to func_0032BDC0 as `(int)`, as its definition takes an int. func_0032BDC0 itself is declared with four different signatures across the tree. func_0037FC28 and func_0037FF98 prototypes added; 0037e368.c includes menuCtl.h and casts its byte-pointer self at those two calls.
- cGameObj.h: func_002831C8 prototype; 0022af90.c includes cGameObj.h instead of its `(void *, int, int)` copy.
- espSys.h: func_00305858 and FindAndForwardEntry_3059A8 prototypes; FindAndForwardEntry's third parameter is the int `force` it forwards (was `void *`), and 001dd218.c includes espSys.h. 0012cc00.c still calls getEffTypeString through an `int sp[4]` buffer and has other implicit declarations.
- func_0032A4A8/func_0032A530/func_0032A5B8/func_0032A648 (ADXT format getters) are declared `(void *)` in the CRI files and `(int handle)` in 00385078.c; definitions in 002b62f8.c take int.
- cMessDrawFontCode.h declares func_002A4B20/func_002A4B88/func_002A4BA0 as `(int font, unsigned short code)`, but the definitions in 002a4b20.c and 002a4b88.c take `char *`/`void *` and `int`.

## Batch 166

- cOmSub.h: the eight vectors at 0x70..0xE0 (posA/posB base points, moveA/moveB travel, startA/startB, goalA/goalB) split out of unk2C; cOmSub.h now includes cOmBase.h for cVec. cOmSub.c, 001bd780.c, 001a9588.c and 00129430.c still match. 001c6a90.c views the same record as a local SubInit (posA 0x90, posB 0xA0, sizes 0x130..0x13C); it should move to cOmSub.
- cEm00.h: unk698 is the cDamageTake the enemy was last hit with (kind at 0x46, attacker at 0x34). Typing it `cDamageTake *` needs 00255eb0.c's local cEmLink view and 00254450.c's raw 0x34 reads moved to cDamageTake.attacker; drafts/cod/0020ef08.c casts until then.
- D_0076A880 (sound RPC buffer: send area 0x00, receive 0x40, client data 0xDC, done flag 0x100) is SndBankCmd in sndBank.h but `char[]` in 001fab28.c and 0031a718.c; func_00375318 stores pointers into words 4 and 8, which SndBankCmd types as int. One record type would unblock it.
- cRoomSave: 002c32f0.c declares func_002BEBC8 as `(void *, int)` and keeps a local copy of the room/page table row; drafts/cod/002bebc8.c uses cRoomSave/cRoomSaveRow.
- Turn_dest is declared locally in about 15 files with two different parameter orders; it needs one prototype.
- vu0.h proposal: a non-volatile `"+m"` twin of VU0_VADD_XYZ_IP (like VU0_ZERO_VSUB_XYZ_TO) moves func_001C7138 from 20 to 12 differing words.
- drawPrim.h (new, needs review): Gp_draw_poly4 and Draw_Poly_sc prototypes; 001de7c8.c includes it instead of its local Gp_draw_poly4 copy. src/cod/0015f0.c now has a compile_units entry for sn-2.95.3-136 (cygnus turns Draw_Poly_sc's call into a sibcall); Draw_Line_sc there stays INCLUDE_ASM and the reseed still reproduces both hashes.
- cSceAtUnit is defined twice: cSceAtUnit.h (area at 0x04 as `char[0x30]`) and cSceAtManager.h (link/state/pos view) use the same tag for the same 0x9C record. The area should be typed cArea, and func_001F88A8's prototype (00169258.c) belongs in cArea.h; 002c12c8.c and drafts/cod/00123908.c declare it and cSceAtUnit_AreaSet locally.
