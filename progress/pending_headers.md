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
- DONE in batch 198: func_0012BC00 registered (src/cod/0012bc00.c, extern_jtbl D_0041D180; cGameObjVt.unk44 already returns int, so the cObjInitVt change is not needed; vec3_set clears the rotation; prototype in player.h). Still open for checkpoint 207: 00111a20.c, 001120a8.c and 00111dd8.c keep their local `(void *, int, int)` declarations; switching them to player.h needs their `char *s1 = (char *)a0;` aliases retyped first. Original note: (build/scratch/0012bc00_ckpt.c, SN, `extern_jtbl D_0041D180`; new TU src/cod/0012bc00.c). It launches a cOmbe (actor 0x3BE) from the player. It needs two player.h changes: (1) `cObjInitVt.init` returns `int`. The cOmbe entry at vt+0x44 is func_001BBB28, `int` in 001551c0.c, and it returns 1. With `void`, the function pointer and the table swap v0/v1 at the call. func_0031C4E0 (the other user) still matches with `int`, checked by match_check. (2) A shared prototype `void func_0012BC00(cGameObj *self, int kind, unsigned int spread);`. 00111a20.c, 001120a8.c and 00111dd8.c declare it locally as `(void *, int, int)`. `spread` is unsigned: retail tests the below-1 leaf of the 0/1/2 switch with `beqz`, which is only valid for an unsigned compare. A signed int gives a range test or a longer tree.
- CreateObj: the definition in src/cod/00306200.c is `int CreateObj(int a0)` and calls func_0030FAC8/func_0030FB20 with no prototype in scope. Retail forwards a1 untouched to func_0030FAC8, which reads it, so the definition drops a real argument. player.h already has `cGameObj *CreateObj(int kind, int id)`. 16 files declare it locally with 5 different return types (char *, void *, cGameObj *, FxObj *, BlackJackCardObj *); casino/Poker.c is off-limits until the objects/minigames PR merges.
- pl00.h: 0x640 is the locked-on target (`cGameObj *lockOn`). func_0012B618 reads it (draft drafts/cod/0012b618.c, local view pl00ThrowView), and 00124c30.c, 00124e68.c and 0012cc70.c use raw offsets for it.
- DONE in batch 199: func_00133DA0 registered (src/cod/00133da0.c): cCollisionSolidBox is in cCollisionSolid.h, Draw_Line2 `(void *, unsigned int, unsigned int, int)` in drawPrim.h and 0014b9a0.c includes it (its three functions still match); the array-constructor loop now walks a cVec * with cVec_zero. Original note: (build/scratch/00133da0_ckpt.c, SN, plain flags; new TU src/cod/00133da0.c). It is the box solid's debug draw (vtable D_0041D790): the twelve edges of the eight corners at 0xF0. Two header changes: (1) `cCollisionSolidBox` (cCollisionSolidObj base, `cVec corner[8]` at 0xF0) goes into cCollisionSolid.h. (2) Draw_Line2 has no definition and no header prototype. Retail compares n with sltu and sets no return value, so `void Draw_Line2(void *pts, unsigned int n, unsigned int color, int flag);` goes in a shared header, and 0014b9a0.c (which declares it `(void *, int, unsigned, int)`) includes that header.
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
- HELD for checkpoint: cCollisionSolidManage_ChkHit matches (rebuilt in batch 198 as progress/held/001348e8.c after the scratch wipe, -Wall clean; its local cCollisionSolidBody/Unit/Manage/Vt types are the planned header types below, and cCollisionSolidBody is cCollisionSolidObj under its new names; SN, plain flags; new TU src/cod/001348e8.c). It refreshes the bounds of obj's collision unit, tests each active solid against the active solids of every other unit (sphere/sphere func_00134CB0, sphere/box func_00134E18 with a swapped flag, box/box func_00135040), sets bit 1 on both solids of a touching pair, lists up to 32 owners hit and returns 1 on any hit. Header work in cCollisionSolid.h:
  (1) cCollisionSolidObj: 0x00 is the next solid in the unit (`struct cCollisionSolidObj *next`, today `int unk00`), 0x10/0x20 are the solid's bounds min/max (today unk10/unk20), 0x30 is a vtable whose entry at 0x18 is a (short this-delta, function) pair that refreshes the bounds. Flag bits: 0x1 active, 0x2 hit this check.
  (2) A unit type (`cCollisionSolidUnit`: 0x00 cGameObj *owner, 0x04 first solid, 0x10 next unit, 0x20/0x30 cVec min/max of all its solids) and a manager type (`cCollisionSolidManage`: 0x00 first unit, 0x08 cGameObj *hits[32], 0x88 unsigned int hitNum; hitNum is compared with sltiu).
  (3) The header's `int cCollisionSolidManage_ChkHit(void *mgr, void *obj)` becomes `(cCollisionSolidManage *self, cGameObj *obj)`; check its callers still match. func_001346C8 (unit of obj), func_00135250 (box overlap of two min/max pairs), func_00134CB0, func_00134E18, func_00135040 are asm; their prototypes come from what ChkHit passes and belong in the same header.
  (4) The solid flag word is read with lwu + andi 1, written in the 64-bit idiom at bit 0 (`long active = (unsigned int)a->flags; if ((active & 1) == 0)`); scrFlags bit 2 (tested before suspend bit 3) has no GAMEOBJ_SCR_ name yet.
- func_0016AE38 (registered, src/cod/0016ae38.c; per-file settings `as: sn` and `extern_jtbl D_0041FD90`): the menu panel object (state byte 0x5A, timer 0x60, cursor 0x1B4, 0x1D0/0x1D2, toggle 0x1D4, the 0x202/0x204 shorts Obj0000_Set_Short_202/204 read) is a local `MenuPanel` view; 001680d8.c reads the same record with raw offsets. It belongs in a header shared by both. D_003BD930 (the option/save record whose byte 0xEDD picks the four- or two-row menu) is `char *` in 0016ae38.c / 001680d8.c and `void *` in 0030eee8.c / 0030b728.c; one declaration in a header. The pad masks 0x0008000004000000 (down) and 0x0004000008000000 (up) are also literals in 001d2888.c; name them once in gameWork.h next to trg/rep.
- HELD for checkpoint: func_00146A18 matches (rebuilt in batch 198 as progress/held/00146a18.c after the scratch wipe, -Wall clean; it already uses cIDBase.h's cIDBaseEnt/getIDWork/cIDBase_move and keeps D_003C23A4 as char * behind MESS_BANNER_MSG until item (3); SN, `extern_jtbl D_0041E8A0`; new TU src/cod/00146a18.c). It is IdPair's banner step (IdPair_init's object): slides entry 0 down, grows entry 1, shows the queued message for 90 frames, shrinks and lifts it, then pops the two short queues and re-inits. Header work: (1) IdPair moves out of 001468b0.c into a header (e.g. idPair.h) with the full layout: cIDBaseObj base 0x00, signed char state 0x79 (IdPair_init clears 0x79..0x7C; this step reads 0x79 with lb), cIDBaseEnt *work[4] 0x90, cIDBaseObj part2 0xA0, unsigned short msgQueue[4] 0xF0, altQueue[4] 0xF8, short count 0x100, short timer 0x102, unsigned char flags 0x104; both files include it. (2) cIDBase_getIDWork's entry is a cIDBaseEnt here (src 0x1C, posX/posY 0x38/0x3C, flags 0x2C, sclX 0x40, rotSpeed 0x48, msg 0x90). 001468b0.c reads the same entry as CustomIDWork (offsAmp[0] at 0x3C = posY), so CustomIDWork and cIDBaseEnt describe one record; merge them or pick one per the one-type-per-record rule, then the single prototype `cIDBaseEnt *cIDBase_getIDWork(cIDBaseObj *self, int id)` in cIDBase.h. cIDBase_move (`void (cIDBaseObj *)` in cIDBase.c) also has no header prototype; 7 files declare it with void *. (3) D_003C23A4 is `int` in cMessDrawFontCode.h and `void *` in 0030eee8.c / 001169d8.c; the step writes the short at +0xBEE (the message id the banner shows). Give it a pointer type and name the field.
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

### HELD func_0010F720 (player rush punch; recovered in batch 199 to progress/held/0010f720.c from the batch-158 transcript; needs the header work below to compile)
- extern_jtbl: D_0041BD40 D_0041BD60 D_0041BD80 D_0041BDA0 D_0041BDC0.
- cGameObj.h: split unk308 into unk308[0x330-0x308], `cVec nullSpeed; /* 0x330 speed of the null part, as in cObjBase */`, unk340[0x3AC-0x340].
- cGameObj.h: move `motionBlock_at(char *block, int ofs)` from 002897f0.c into the header (two users now).
- pl00.h: split unk5AC: unk5E0/unk5E2 (short), unk600 (float, times 5 or 10 is the hit damage), unk608 (float, angle; compared to pi/2), unk61F (uchar), `cGameObj *lockTarget` 0x640, `unsigned char lockHold` 0x648; split unk6AC: `float stateMove` 0x1588, `int stateWork[4]` 0x15B0 (scratch the current state owns); after comboTimer: `char unk1684` 0x1684.
- gameWork.h: `int padBtn; /* 0x08 face-button bits, 0x10-0x80 */` (retail reaches it as D_007474A8; 12 files declare `extern int D_007474A8`, convert later).
- 00134880.c: func_002A8578's definition becomes `(int a0, int a1, int a2, int a3, float f12, int t0, int t1)` (the caller's argument order only matches with the float fifth; the callee's code is the same). 0010cd38.c, 00244398.c and 00248d00.c already declare it that way; no caller copies the old order.

### HELD func_00112CB8 (player god-hand roulette finisher; recovered in batch 199 to progress/held/00112cb8.c; needs the header work below to compile)
- extern_jtbl: D_0041C1D0 D_0041C1F0.
- Needs the func_0010F720 header work (pl00 fields, cGameObj nullSpeed, motionBlock_at) plus pl00.h: `unsigned char godUsed` 0x649 (set once the god item is spent for the move), `float unk674` 0x674, `int unk15F4` 0x15F4.

### HELD func_002FD078 (effect node scale update; recovered in batch 199 to progress/held/002fd078.c, MATCH against today's include with as=sn, fp_hazard_rules fdiv)
- Batch 199 finding: espSys.h's EspAnim is the same node too (data 0x110 = rec with flags 0x04 bit 0x2000, key 0x22E = frame, keyPrev 0x230 = prevFrame). EspAnim names byte 0x11D `lockFlags` (read with lbu by EspAnim_step), while 002fc9a8.c and this function read the word at 0x11C (bit 0x100 is that same lockFlags bit 0). The merge needs one name for that word that keeps both the lbu and the lw reads: e.g. the word `flags` at 0x11C plus an ESP_LOCK macro on the byte, decided at the checkpoint. The target is EspAnim, not a new espNode type.
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

## Batch 167

Overlay copies of every changed header are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit. Merge at the checkpoint, then make each defining file include its header.

- capVu0.h (new): capVu0MagnitudeSqXZ(cVec *, cVec *), capVu0Atan2(float y, float x), capVu0Acos(float). capVu0Atan2 is declared locally in 0011b3e8.c, 0026eb20.c, 0014b640.c and others.
- rand.h (new): `int irand(void);` (definition in 001004c8.c).
- angle.h (new): `float Turn_dest(float *from, float *to, float cur, float max);` (definition in 002da038.c). This is the one prototype batch 166 asked for; about 15 files declare it locally.
- cEm00.h: fields counterVital (0x17AC), unk17C4 int and unk17C8 short (were `char unk17C4[0x6]`), unk17D0 int (attack roll, 0 to 4), unk1866 byte (knockdown count). Prototypes: func_0026F1D8, Obj0000_Get_Byte_17C3_NZ_2_276468, StoreMotionParamsBoth_2609A8, func_00260B30, func_002705D8, func_002740D8 `(char *)`, func_0025FE30 `int (void *, int, int)`, func_00274FE8 `void (void *)`.
- cHeatSys.h: `extern cHeatSys D_005CB000;`.
- player.h: Obj0000_Get_Field_5FC_NE_Zero_12C748 `int (char *)`.
- motion.h: `int moveMotion(void *obj);` and `void func_002A8578(int obj, int motA, int motB, int mode, unsigned short sel, unsigned short keep, float start);`. Retail callers mask sel with `andi 0xFFFF` and treat the call as void. The definition in 00134880.c should become that signature: progress/held/00134880_def.c matches. Its current callers (0027c460.c, 00243fa0.c, 002816e0.c, 00227ca8.c, 001cb030.c, 0010c930.c, 002591f8.c) declare it locally with the float in the wrong slot; their code doesn't change when they include motion.h, but each needs a rebuild check.
- MotionParamFn / MotionGetParam gain `float t`: retail MotionGetParam (0x159510) leaves $f12 untouched, so func_00139180 passes it through.
- cObjBase.h: cObjBase_addNullSpeed and cObjBase_addNullSpeed_Rotation `(struct cObjBase *, float)`.
- cGameObj.h: `void cGameObj_SetTgtTurn(char *self, void *target, float rate);`.
- cSnd.h (new declarations only): `extern cSnd D_005FEE00;`, cSnd_SeCall_2CBA48 as defined in 002cba48.c, GetSeqSEBase `int (int *)`. D_005FEE00 is declared locally about 280 times with six different types.
- cCollisionSolid.h: `extern char D_00462FC0[];` and cCollisionSolidManage_SetActive `void (int, int, int)` as defined in 001351d8.c. Callers declare it with `void *` parameters in at least five files.
- cModel_setMeshDisplay `int (cModel *, char *, int)` needs a cModel.h prototype (new declaration; drafts/cod/002b6da0.c declares it locally).
- 0024c0f0.c declares `void func_00276478(void *)`; the held 00276478.c defines it with `cEm00 *`. Give it one prototype in cEm00.h.

## Batch 168

Overlay copies are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit.

- cEm00.h: `unsigned char counterChance` at 0x17B8 (split from unk17B2: 1 = a counter half the time, 2 = two times in three); `cDamageTake *atkHit` at 0x670 (split from unk649: the enemy's own attack hit record); unk510/weapon/unk1866 as noted in batch 167.
- cEm00.h prototypes: `int cEm00_startHitUnitAim(cEm00 *)`, `void ReleaseField6ECByTag564_26B1E8(void *)`, `void func_00262750(void *, int)`, `int func_00270DB0(cEm00 *)`, `char *func_0026AA30(char *, int)` (as defined in 0026aa30.c), `void func_0026B240(void *, int, int, int)` (0014a038.c and 0022a258.c declare it locally), `void ForwardAnimParamPairByIndex_27EA50(void *, int)`.
- cGameObj.h: `void InitRenderStruct_2A8608(cGameObj *, int kind, void *no, int a3, int mode, void *follow)` as defined in 002a8608.c; func_00275888, func_002A74E0, func_002A7CA0 prototypes.
- cObjBase.h: `int SetEffect(int kind, int id, void *owner, cEffectParam *param, int handle, unsigned int follow)`.
- player.h: `void func_00129718(cGameObj *player, void *em, int kind)`.
- cCollisionSolid.h: `int ChkLine(void *, void *, void *, int, int, int, void *, int, int, int, int, int, int)`. 00275888.c, 0017d488.c and 0012c7d0.c declare it locally, and 00275888.c gives the seventh parameter as `int` while 0017d488.c passes a pointer there; they should switch to the shared prototype.
- capVu0.h: capVu0Sin. cEmManage.h: the CkPlSorry/CkPlCatched near-checks.
- EmWeaponHolder views in the enemy files describe cEm00 memory and should become cEm00 field reads.
- Per-file settings to register: `as: sn` for 00224a28.c (retail's hazard nop sits after a label reorg threaded a branch to), and for the 00231300 draft.

## Batch 169

Overlay copies are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit.

- BlackJack.h overlay and the sibling-extern fixes from BlackJack_UpdateOpeningDeal (see the README row).
- cOmBase.h: `float scale[3]` as used by the path blade (func_001B4528).
- cPathMover.h (new): the path mover record func_001B4528 reads; drafts/cod/001b51b0.c should use it.
- rand.h: `int Rnd(void);` (definition in 001fd308.c).
- cSnd.h (new declaration): `void cSnd_SeStop(cSnd *self, int handle);`.
- D_00747A14 is D_007474A0.timeScale; read it through gameWork.h.
- mtx.h (new): func_00150710 `(void *dst, float x, float y, float z)`, MtxGetScaleVec `(void *scale, float *mtx)`, func_00147C88 `(void *rot, float *mtx, unsigned char order)`.
- libm.h (new): `float sqrtf(float x);` (unifies the local externs in 0015a190.c and 002adf50.c) and `float func_003A1B78(float x);` (asinf).
- capVu0.h: `float capVu0Cos(float x);` (local externs in 00160c48.c and 002f01b8.c).
- drawPrim.h (new declaration): `void Draw_Line_sc(void *v, int n, unsigned int color, int a3);`.
- cScrSpriteDraw.h: `unsigned int func_0031ED08(float f12);` (definition in 001c8f30.c; local externs in 002c5bd8.c, 0014ead8.c, 0023a300.c, 001027d8.c).
- motion.h: func_002A8578 becomes `void func_002A8578(int obj, int motA, int motB, int mode, float start, unsigned short sel, unsigned short keep);` (float fifth; supersedes the float-last line in the batch 166 section). 0025DE58 and 00243408 only match this way; every held user is rewritten and still matches; progress/held/00134880_def.c is the matching definition. Main's local declarations in 0010cd38.c, 00244398.c, 00248d00.c already use this order; 0027c460.c, 00243fa0.c, 002816e0.c, 00227ca8.c, 001cb030.c, 0010c930.c, 002591f8.c, 00134880.c need converting and rebuild checks.
- motion.h: `void SetMotionStep(void *obj, float step);` (definition 00147c40.c; local externs in 0025c1d0.c, 001cb030.c).
- rand.h: `float fRand0_1(void); float fRand1_1(void);` (definitions 00124f60.c, 00292f50.c; local externs in 0031d050.c, 001733b0.c, 00287090.c, 0014b640.c and others).
- cHeatSys.h: `void cHeatSys_AddHeatGage(cHeatSys *self, int a1, float heat);` (definition battle/cHeatSys.c; local extern in 0025c1d0.c with void *).
- cObjBase.h: `void SetEffectPos(int kind, int id, void *owner, cVec *pos, int handle, float size);` (definition 00306838.c, which includes cObjBase.h; local externs in 001e2eb8.c, 0016acd0.c).
- cEm00.h: split unk56C[0x14] into unk56C[0x2], `short followTimer; /* 0x56E */`, unk570[0x10]. Prototype `void func_00260890(cEm00 *self, int part);`.
- Adjust_theta lives in cCamera.h; angle.h is the better home (with Turn_dest).
- NM closer: drafts/cod/00217560.c, 0028e0e0.c, 00245538.c (and the other drafts calling func_002A8578) may close with the float-fifth prototype.
- Tooling gap: retail func_00147C88 pads a run of div.s once (two nops) and uses one nop where the divide reads the neg.s just before it; no fp_hazard_rules setting does that.
- Registration at the checkpoint: 0025de58.c (extern_jtbl D_00443A80) and 00243408.c (extern_jtbl D_0043C8B0), no per-file flags.

## Batch 170

Overlay copies are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit.

- Poker.h: the table UI prototypes `void func_001DEE40(void *ui, int n); void func_001DF528(char *ui, unsigned char idx, unsigned short mode); void func_001DF7D0(char *ui, int alt); void func_001DF820(char *ui, int enabled); void UiRecord_setDispSubs6to10(void *ui, int on);`. Correct the func_001DEE40 definition in src/cod/001dee20.c to `(void *ui, int n)` forwarding n (retail leaves a1 untouched, same bytes) and include Poker.h there.
- cSnd.h (new declarations): `int cSnd_SeCall_2CB8A0(cSnd *self, int slot, short key1, short idA, short idB, int a5, int a6); void cSnd_SetBgmState(cSnd *self, int state);`.
- gameWork.h: `extern long D_00747640;` (D_007474A0.trg under its own symbol) and `extern int D_007476B0;` (D_007474A0.frame under its own symbol).
- gsLoadImage.h: `void func_0015E708(GsLoadImagePacket *pkt, int psm, int tbp, int tbw, int w, int h, char *data);` (tbw not read). src/cod/0015e0a0.c then includes gsLoadImage.h and tim2.h and drops its local declarations.
- mdlPkt.h: PktQw gains an `ad { unsigned long data; unsigned long addr; }` view; MdlRec gains `unsigned char texNo` (0x16); MdlObj gains `PktQw *pkt[2][16]` (0x300) and `unsigned char texBank` (0x384, pad385[3]); `extern MdlPktBuf D_00747BB8[];`; `PktQw *func_00155800(MdlObj *self, PktQw *q, int idx, int buf);` (buf not read). drafts/cod/00155800.c and 00154da0.c should use the typed fields.
- tim2.h (new): GsTex0, Tim2FileHdr, Tim2PicHdr (unsigned totalSize/clutSize/imageSize), D_0041ED80, `int func_00309C30(unsigned int psm, int width);`.
- texWork.h (new): ImageUpList (moved from 00151168.c), TexWork, the func_00150F68 and func_00151168 prototypes.
- cEm00.h: `Obj0000_IsSet_Field_16D4_Bit_4_26F308(void *)`, `func_00273EE0(void *)`, `extern unsigned char D_005CB010;` (local declarations in 001169d8.c, 0024f050.c, 0020cac8.c, 002705d8.c then go).
- cObjSimple.h: StoreVecFromFieldB0_2B6160, CopyVec16From20_B62E0, `int CallThenReturnPlusB0_002B6420_2B61B0(int)`, UpdateObjByIndexedOp_2FBE50, func_002FBED0, `void *func_002B60D0(void *dst, void *self);`, `void cNode_setLocalScale(int self, int scale);` (as its definition in 00134880.c; 002e6868.c and 002f2250.c declare other types).
- cCamera.h: `void *cCamera_getScreenPos(cVec *out, void *camera, cVec *world);`. mtx.h: `void MtxCopy(void *dst, void *src);`.
- cObjGround.h (new): the ground effect object (esp04). cObjGround with ObjFlags/cObjLink moves out of src/cod/002e6868.c; adds cObjGroundParam and `int func_002E63C0(char *self);`. 002e6868.c and 002e63c0.c include it.
- espSys.h: `void *func_00306030(void *sys, int kind, int idx);`, `extern char D_007419A0[];` (effeventdatarelease.c declares it as a plain char), `void func_002D9F68(void *self, int fmt, ...);`.
- cModel.h: `void cObj_setMeshValue(cModel *self, int value);` (002f1d58.c declares the value as long).
- Proposed helpers, only if func_002EFD20 closes: `cVec_copy` (VU0_LQC2_SQC2_MEM through pointers) for sceVu0.h and `cEffectParam_initAll` for cObjBase.h.
- Registration at the checkpoint: 001daec0.c (extern_jtbl D_0042B3A0, fp_hazard_rules fdiv, as sn), 0015e708.c (as sn), 00155678.c (as sn), 00294488.c (extern_jtbl D_0044A830). Drafts to drafts/cod/: 00151cc0_nm.c, 002efd20_nm.c, 002e64b0_nm.c.

## Batch 171

Overlay copies are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit.

- cScrSpriteDraw.h, drawPrim.h (new prototypes only), cIDManager.h, drawQueue.h, sceVu0.h, tim2.h: the additions listed for func_002C5548 and the 002C5xxx/002C6xxx drafts in the held README. Register 002c5548.c (extern_jtbl D_0044C2E0, fp_hazard_rules mtc1); replace the local declarations in 002c6d48.c, 002c6550.c and 002c5bd8.c with the header ones. Drafts to drafts/cod/: 002c5ea8, 002c70a8, 002c6840, 0015bcf0.
- sceTimer.h (new): T2_COUNT/T2_MODE and their bits, KE_NO_TIMER, sceTimerCounter (0x40), sceTimerCtl, `extern volatile sceTimerCtl D_003FBE90;` (interrupt handler state), and the iAllocTimerCounter/iGetTimerSystemTime/GetTimerSystemTime prototypes. Every file with its own view of D_003FBE90 switches to it; src/cod/003b7270.c declares iAllocTimerCounter as returning `void *` and must return int.
- sif.h (new): sceSifDmaData, sceSifCmdHdr, sceSifRpcState, the SIF_DMA_*/SIF_CMD_* numbers, SIF_SYSREG_RPCINIT, the RPC tables D_0077E740/D_0077EF40/D_0077F740, D_0077E520, D_003FAE54, D_0077FF40, and prototypes for SifSetDma, isceSifSetDma, SifGetReg, SifSetReg, func_003B2850, func_003B21D0, func_003B2058, func_003B2488, the four RPC handlers `(void *pkt, void *data)`, _sceSifSendCmd, `void sceSifInitRpc(int mode)`, sceSifSendCmd. The local D_0077FF40 types in 003b34d0.c, 003b3400.c, 003b3368.c, 003b3568.c, 003b2f48.c and 003b3128.c become sceSifRpcState; the handler definitions take the header types.
- eeKernel.h: `int func_003B63A0(void); /* DIntr */`, `int EIntr(void);`.
- cOmSubGimmick.h: `void cOmSub_initMove1_pos(char *mv, char *obj, int idx, int frames, void *pos, float f12, float f13);`.
- cDamageUnit.h: `void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);`; drop the conflicting `void *` prototype in cOmHitVolumeSetup.h.
- mtx.h: `void MtxMultiply(void *dst, void *a, void *b);` (fix the definition in 001b5160.c to match). capVu0.h: `float capVu0LengthSq(void *v);`.
- cOmBase.h (proposed, 60 users): posPrev at 0x154 is the rotation and should be renamed rot; the texKey word at 0x304 is the resource blob.
- Registration at the checkpoint: 003b2900.c sceSifInitRpc (ee-2.9-991111). Drafts: 001a2e88_nm.c, 001af230_nm.c, 003b2550.c, 003b7130.c, 0039cf10_nm.c.
- Registered this batch, no header change: src/cod/0039d398.c (_doMC, ee-2.9-991111, local MpegMc* records; they move to a libmpeg header once _getRef0 or the macroblock caller func_0039C5B8 needs them in a second file).

## Batch 172

Overlay copies are in progress/held/inc/godhand/; progress/held/README.md lists which held file needs which edit.

- cEmLinked.h (new): the linked enemy (cEm00 base, link part offsets) for func_0027A320/func_0027AE10.
- cEm00.h: `struct cModelNode;` forward declaration; texSet at 0x284 (as in cOmBase); `struct cModelNode *hand[6]` at 0x1774 (hand meshes by pose); `signed char unk1869` (enemy 0x275: how many of four meshes stay shown); vt slot 0x58, parts 0x144, unk2F0, unk17D4, unk1865, and the CheckSlotsShort2FEAndSetByte1864_262A10 prototype. 00233738.c and 0022b790.c declare that prototype locally with other types: switch them to the header one and recheck.
- cOmBase.h: cOmBase_childAtIdx (the 0xFF-masked range flag as cGameObj_idInRange). cDamageTake: `unsigned int opts` at 0x00 (bit 0: take hits without the line-of-sight check), `cVec hitPos` 0x20, `struct cGameObj *victim` 0x30, `int unk40` 0x40, `short unk44` 0x44.
- cModel.h: the cTexTable typedef (moves out of 00149ad8.c), `int cModel_setTextureExchange(cModel *self, void *tex, cTexTable *tbl, int n);`, `cModelNode *cModel_getMeshPtr_14B730(cModel *self, char *name);`, the cModel_calcParts prototype.
- cVec.h, new macros in the #20 shape: CVEC_SET_MUL (d = *a * s), CVEC_SET_APPLY (d = m * *a) and CVEC_COPY (the copy constructor into a local, whole quadword). A plain operator= is cVec_copy3 (cOmBase.h), which matches when the source is a named vector or a returned pointer. None of the new macros merges until a function that uses it matches.
- fpu.h (new, the three approved macros): merge only with a function that matches byte for byte with it; none does yet (cCoreSave_translateSaveItem is 8 words off).
- keySlot.h (new): KeySlot (moves out of 0012bf50.c), KEYSLOT_NUM, `KeySlot *func_002BB068(KeySlot *tbl, int key);`, `KeySlot *func_002BB098(KeySlot *tbl);`, `int func_002BB138(KeySlot *tbl, int key);`. Definition fixes: 002bb068.c takes and returns `void *` (switch to KeySlot and include the header); 002bb138.c is defined `int func_002BB138(void)` and calls func_002BB068 with no prototype or arguments, but retail and both callers pass (tbl, key) straight through. Rewrite it as `int func_002BB138(KeySlot *tbl, int key) { KeySlot *h = func_002BB068(tbl, key); if (h == 0) return 0; return h->value; }` (ee-2.9-991111) and recheck. 0012bf50.c calls both lookups with no prototype; 001dece0.c passes `(char *)v + 0x14`.
- cDamageGive.h: owner 0x30 (`struct cGameObj *`), lastHit 0x34, ignore 0x38, nodes 0x3C (as cDamageUnit.nodes); includes cDamageUnit.h.
- cDamageUnit.h: includes cOmBase.h and keySlot.h; `cVec pos` at cDamageNode 0x00; `KeySlot keys[KEYSLOT_NUM]` at cDamageData 0x14 (key 1 holds the volume's cDamageTake); CDAMAGE_SHAPE_GETPOS 8, CDAMAGE_KEY_TAKE 1; `void func_001FC810(cDamageNode *node, cDamageData **out, unsigned short max);` (drafts/cod/001fc810.c and 001dece0.c switch to it; the draft's ChildOwner/ChildEnt are cDamageNode/cDamageData).
- cGameObj.h: cGameObjVt entry at 0x90/0x94, `getCenterDelta`/`getCenter` (the point line-of-sight checks between objects start from).
- cOmHitVolumeSetup.h: drop `extern void cDamageUnit_SetDamageCollActive(void *unit, int on);` (cDamageUnit.h has the typed one).
- 001f8488.c: its func_001573C8 declaration disagrees with the definition (recheck when the prototype is shared).
- Drafts to drafts/cod/ at the checkpoint: 0027a320_nm.c, 0027ae10_nm.c, 002294e0_nm.c, 001f85d0_nm.c, 00268dc8_nm.c, 001fb4d8_nm.c, 001fcf20_nm.c.
- cOmBase.h: `signed char unk531` at 0x531 (as cGameObj.unk531) and `short unk568` at 0x568 (a weapon's burst wait), both split from padding; func_001CA238 uses them.
- cOmWeapon.h: unk650[0x10] split into `struct cDamageGive *give` 0x650, `int giveNode` 0x654, `struct cDamageGive *give2` 0x658, `char unk65C[0x4]`. func_001CA238 is a cOmWeapon step (vel 0x640 and life 0x660 were already named), so it uses this type instead of a local record.
- cDamageUnit.h: `void func_001FD988(cDamageUnit *self, unsigned char active);` (its definition in 00155d60.c takes a local `Owner` view of the unit: switch it to cDamageUnit and recheck; 0013bc28.c declares `(void *, int)`), `void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius);` (as in 001f38a0.c; 00170050.c and 0010a2c8.c declare other types).
- cDamageGive.h: `void cDamageGive_SetDmgGiveHitVec(cDamageGive *self, cVec *dir);` (as in 001fd308.c; 00170050.c, 001b90d0.c and the 00262750/001efed0 drafts declare it locally).
- cEmManage.h: `void func_00292F70(cEmManage *self, cVec *pos);` (definition in 00288f00.c).
- cVec.h: CVEC_INIT_MUL (`cVec r = *a * s;` constructing r through the return slot; the scalar is not bound, since a float copy adds a mov.s). func_001CA238 matches with it and with CVEC_COPY.
- KillEffect: its definition is `void KillEffect(int, int, int)` (00306200.c); eight files on main declare it `(void *, int, int)`. One prototype in cObjBase.h, the definition typed `(void *owner, int handle, int mode)` if every caller still matches, otherwise `int` with casts.
- Registration at the checkpoint: progress/held/001ca238.c to src/cod/001ca238.c (sn, c_flags_add -f=-ffast-math, fp_hazard_rules sqrt; reasons in the held README).
- cOmWeapon.h: cOmWeaponPiece's `float rot[3]; float unk0C; float vel[3]; float unk1C;` become `cVec rot;` 0x00 and `cVec vel;` 0x10 (no unit reads them today; func_001CC668 moves each as a quadword).
- cModel.h: `void Adjust_theta_vec(cVec *v);` with a one-line comment (the held overlay has it), as the batch-153 note on cModel_calcParts asks; the `(float *)` callers (001aa188.c, 00173ec0.c, 0019ca58.c, 001a13e8.c, 002fd530.c) switch to it at the merge.
- cMovie.h: cMovieClip's `char unk00[0x2C]` split into name 0x00, w/h 0x04, unk08/unk0A, scrW/scrH 0x0C (the screen size), f34 0x10, f28 0x14, f2C 0x18, f30 0x1C, f38 0x20 (named for the cMovieTrack fields func_002D3C78 copies them to), level 0x24, level2 0x28, plus a size check; MOVIE_CLIP_NUM 6; `extern cMovie D_005E79D0;`, `extern cMovieClip D_005E7BF0[6], D_005E7D10[6];`, `extern cMovieTrack D_005E7E30[3];`; prototypes `cMovie *func_002B48F0(cMovie *self);` and `cMovieTrack *func_002D36E8(cMovieTrack *self);`. At the merge: 002b48a0.c and 002b48c8.c drop their `extern char D_005E79D0[]` (take &D_005E79D0), 002d36e8.c's `void *func_002D36E8(void *a0)` is retyped to the header form, and cMovieTrack_start (0011a820.c) can take `const cMovieClip *clip` (reads clip->name) if 002b4ec8's caller still matches.


## libmpeg motion-compensation records (from batch 172)
- `MpegMcArg`, `MpegMcSet`, `MpegMcState` (local in src/cod/0039d398.c and progress/held/0039cf10_nm.c) and `MpegRefImage` (0039cf10_nm.c) belong in one header (proposed `include/godhand/libmpeg.h`) with the `_getRef0` prototype, once 0039cf10 matches.
- MpegMcState fields form_predictions (held 0039c5b8_nm.c) reads: 0x130 second field flag, 0x160 picture coding type, 0x184 picture structure, 0x1C8/0x1CC forward/backward frame, 0x1D8/0x1DC and 0x1E8/0x1EC the forward/backward top and bottom fields; `mc[cur].num` (0x6CC) is cleared on entry. 0039b810.c's `Ctx` names 0x184/0x1CC/0x1DC/0x1EC as fNNN for the same record.

## soft-double helper names (from batch 172)
- SN cc1 emits `dpmul`, `litodp` and `dptoli` for C double multiply and int/double conversions. symbol_addrs.txt names them func_0031E348, func_0031E8C0 and func_0031E978; rename them (with their carves and the 003ad790.c externs) when held 003a96c0_nm.c matches.
- `dpcmp` is defined `void` in src/cod/0031e870.c, but its callers read the result; correct the definition to `int` when one of them lands.

## gameWork.h / ColiseumEmSelect.h fields added for func_002A5EC0 (held overlay, batch 172)
- GameWork: `int unk588` (0x588), `int unk590` (0x590), `short unk5D4` (0x5D4), `char unk5EC[8]` (0x5EC, cleared at stage set-up), `int unk5F8` (0x5F8); padding split, offsets checked against retail.
- EffDataHdr: `int unk10` (0x10), the offset of the effect bank func_002A5EC0 hands func_00150C10.
- ColiseumEmEntry: `char unk00[2]` becomes `short unk00` (0x00); the stage set-up reads it signed and adds 8 for the enemy set index.

## cMessDrawFont_draw (held 002af728.c, batch 172)
- cMessDrawFont.h: prototypes for cMessDrawFont_measurePage, _measureLineHeight, _measureText, _execCommand, _measureCode, _isListedCode, and func_002B0480/func_002B04C0/func_002AFC08 (each used by 2-4 files), with the parameter types of their definitions.
- cMessDrawFontCode.h: cMessCommon_isHighCodeEnd(unsigned short), func_002B12A0(unsigned short *), func_002AF218(unsigned short *) (asm, int return read by the callers).
- cFont.h: func_002A4FA0(char *), func_002A52E8(int, unsigned int), func_002A58A0(char *, int), func_002A58D8(char *, unsigned int), BuildGifPacket_2A5930(int).
- D_003C2380 is `cFont *` in cFont.h and `int` in cMessDrawFontCode.h: one type per global; pick cFont * and fix the metrics users (decision if their code changes).

## GetEm00CharIndex (registered src/cod/002ddea0.c, batch 173)
- cEm00.h: `int GetEm00CharIndex(int actorId, int emNo);`, included by src/cod/002ddea0.c, replacing the local externs in 00288da8.c, 0028ac58.c and 00208268.c (all `int (int, int)` already, so no caller code changes).

## func_00109928 (held draft progress/held/00109928_nm.c, batch 173)
- pl00.h: split padding into `int unk5F4` (0x5F4), `int unk5F8` (0x5F8), `cDamageTake *damage` (0x678), `int flags15F4` (0x15F4), `int unk160C` (0x160C), `int seHandle` (0x1620), with offset checks (overlay progress/held/inc/godhand/pl00.h).
- cOmBase.h: `typedef enum cDamageKind { DAMAGE_KIND_NONE = -1 } cDamageKind;` and `static __inline__ cDamageKind cDamageTake_kind(cDamageTake *take)` after cDamageTake (pending the cDamageKind naming decision).
- cEm00.h: 0x6EC and fx0..fx6 (0x6F0..0x708) as `struct cOmWeapon *` (answered decision; overlay already edited).

## func_001101A8 (held progress/held/001101a8.c, batch 173)
- pl00.h: `unsigned short comboSlot` (0x5E0) and `comboSet` (0x5E2), the same words as comboObj.h ComboObj.slot/set (ComboObj is a view of pl00; merge it into pl00 at the checkpoint); `cGameObj *unk640` (0x640), `unsigned char unk648` (0x648), `int unk15B0` (0x15B0), `unsigned char unk1684` (0x1684), with offset checks.
- pl00.h: prototypes `void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);` and `void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(...)` (same signature), replacing the local externs in 0011fd10.c and 0010f4b8.c.
- WeaponCarrier (0012b2e0.c) is pl00's view of the weapon slot at 0x698: give WeaponCarrier_damageHeldWeapon `(pl00 *self, int damage)` in pl00.h; cOmWeapon.h gets `int cOmWeapon_SetDamage(cOmWeapon *self, int dt);` (definition in 001d00.c) in place of 0012b2e0.c's local extern.
- func_0010B2E8 (draft drafts/cod/0010b2e8.c, BusyOwner) takes pl00 *: declare `int func_0010B2E8(pl00 *self, int flag);` in pl00.h when it lands.

## func_0010D3A8 (held draft progress/held/0010d3a8_nm.c, batch 173)
- pl00.h: `float unk5DC` (0x5DC, set with base.speedRate), `unsigned short comboTicks`/`comboStage` (0x5E4/0x5E6, ComboObj.ticks/stage), `unsigned int combo` (0x5E8; retail compares it unsigned), `unsigned int prevCombo` (0x5EC), `short unk5F0`, `unsigned char unk61F` (as in cEm00), `float unk1588`, `float unk1598`, `int unk15B4`, `int unk15B8`, `float unk15C0`, `float unk15C4`, `unsigned char unk1603`, `float unk1610`, `short unk1618`, `int unk1660`, `int unk1664`, `int moveA`/`moveB` (0x1668/0x166C, ComboObj.moveA/moveB), with offset checks.
- pl00.h: the `pl00_setSwing(self, a1, a2, a3, a5)` inline (both Obj0000_Set_Fields calls with a4 = 0), shared by 001101a8.c.
- cGameObj.h: split `unk568[8]` into `short unk568`, `short unk56A` (cEm00's names for the same words), `char unk56C[4]`.
- gameWork.h: `int unk000` at 0x00 (the combo attacks charge while bits 0xD0 are set), splitting pad000.
- D_003BC7D0 is `int [][5]` (retail indexes it [combo][tick] with a 0x14 multiply); 00126918.c's `int D_003BC7D0[]` with COMBO_ENTRY_WORDS must move to the same type in one header (check ComboObj_startNext still matches with `D_003BC7D0[combo][0]`).
- func_00123938 and func_00124540 return int (retail sets v0); fix the void externs in 0010ff80.c, 00102de8.c, 0010fe18.c, 0010f4b8.c when they move to pl00.h.

## func_00165638 (held draft progress/held/00165638_nm.c, batch 173)
- cIDBase.h: `cIDColor colorBase` at 0x50 in cIDBaseSrc (002aa1e0.c's raw reads move to `.word`); `int seed` (0x84, compared signed; see decisions_needed.md); prototypes `void cIDBase_move(cIDBaseObj *self);` and `void func_002AC9B8(cIDBaseObj *self, cIDBaseEnt *ent, unsigned short mode);` (0013d698.c passes `int`: check its caller still matches).
- cWorldTime.h: `extern cWorldTime D_0061A990;` and `cWorldTime_getGlobalHMS`/`cWorldTime_getStageHMS (cWorldTime *, unsigned int *, unsigned int *, unsigned int *)`.
- fileHolder.h (new): `FileHolder` (data at 0x298, jobId at 0x29C) and `void FileHolder_reload(FileHolder *self, const char *name);`; add its `.gitignore` allowlist line.
- cRecordIndex.h: `extern cRecordIndex D_005FEC58;`.
- The stage table is one array, `StatusStageRec D_0041F718[0x18]`; retail's `D_0041F6F4` reference is `D_0041F718[sel - 1]` folded into the address (no second symbol).


## DogRace_Load (held progress/held/001e97b0.c, batch 173)
- DogRace.h: `#define DOGRACE_STATS_NUM 5`; DogRaceStats `int msgNo` at 0x00 (replaces unk00: the dog list shows it); `DogRaceTime { int min; int max; }` and `DogRaceTimes { DogRaceTime place[DOGRACE_DOG_NUM]; }` (0x28); `extern DogRaceStats D_003BE1A0[DOGRACE_DOG_NUM][DOGRACE_STATS_NUM];`, `extern DogRaceTimes D_0042BC88;` and the camera eye/target `extern cVec D_00568200, D_00568210;` move there from the TU.
- rand.h: `float frand(float minimum, float maximum);` (definition in 0031d050.c).
- cIDManager.h: `void cIDManager_setIDData(cIDManager *self, int slot, void *data);` and `int cIDManager_getLocalFileName(void *a0, void *a1, void *a2, signed char a3);` (002acfa8.c's definition should include the header); `extern cIDManager *D_003C2388;` and `extern cIDManager **D_003C2384;` there too, replacing the int/void * locals in 0012e990.c, 002c6d48.c, 00114e28.c, 0014ea28.c, 001dddb0.c, 00124c30.c, 001627d8.c, 001673d0.c (check each still matches).
- cDvd.h: `extern cDvd D_00583F20;`, `int cDvd_ReadAlloc(cDvd *self, const char *name, void *out, struct HeapArena *heap, int a4, int a5, int a6, int a7);` (retail zeroes *out first), `void cDvd_CheckWait(cDvd *self, int id);`; replaces the local declarations in 00114e28.c, 0014ea28.c, 002d0220.c, 002ae4a8.c, 00296458.c, 001b9030.c, casino/cCockBossBar.c, 00166540.c.
- cVec.h: `CVEC_TEMP_COPY(p, t, s)` (see decisions_needed.md).
- IdCountScreen (local to 001b81a8.c) goes to a header so CustomID_setArrowDisp's callers use the type; DogRace_Load forward-declares it for now.
- Prototypes shared by DogRace_Load and their definitions' files: func_001EE780 (001ee780.c), func_001EBF50 (001ebf50.c), InitDogRace{Result,Ui,List}IdWorks (001ecaf0.c), func_001EB718 and func_001ED490 (001e7848.c; 001ecaf0.c and 00159fc8.c declare func_001ED490 too), func_001ED178/func_001ED050 (001ece30.c), CustomIDWork_setSlotMessNo (0013bcc0.c): into DogRace.h / CustomIDPanel.h.

## func_002CEA00 (held progress/held/002cea00_nm.c, NON_MATCHING, batch 173)

- cSnd.h: `cSndSeVoice` is `__attribute__((aligned(16)))` (retail merges its adjacent flag tests into one `ld`; the 7 held cSnd.h matches re-verified MATCH with it). Main's users of cSndSeVoice (0011a8f8.c, 002cd310.c, 002cf058.c and the rest) need the full-build check at the checkpoint.
- cSnd.h: cSndSeVoice 0x2C..0x35 named curVolL/curVolR/curPitch/curPan/dist; cSnd 0x64 `f64` and 0x70 `f70` (volume scales); `cSnd_CalcListenerPanDist` prototype (definition 002cf058.c; it should include cSnd.h and drop its local declaration).
- SndEntry.h: new `SndEntryParam` (0x30, the sound-driver entry parameters) and the AddSoundEntry_374F30/UpdateEntryVolume_3751B8/UpdateEntryParams_3752A0 prototypes (definitions in 003749d8.c, which should include SndEntry.h).
- cVec.h: `CVEC_ARG_COPY(t, s)` (see decisions_needed.md).
- func_0030A538 is a 16-byte copy (`lq`/`sq`): retail reads it as `(cVec *dst, cVec *src)`; 002cd310.c declares it `(float *pos, int mtx)`. One prototype needed, in cOmBase.h or vecInline.h.
- cSndSeVoice_Play (held 002ce588.c): cSnd.h `struct HitHost *seHit` at 0x20, f60/f68 floats; cSndSeVoice_ckHitSet prototype. 00137cb8.c's `HitHost` is a view of cSnd (unk00[0x20], set at 0x20): retype the definition to take `cSnd *` with cSnd.h naming 0x20 as the HitSet pointer (move HitSet/HitNode to a header), then drop the cast at the call. SndEntry.h: unk0C/unk28 words, BuildSoundNode_374DF8 prototype (0037a4c8.c declares it locally: switch to the header). D_00747A84 has 10 local externs with mixed int/unsigned types: one declaration in gameWork.h (it is D_00747A2C + 0x58).

## func_001601D8 (held progress/held/001601d8_nm.c, NON_MATCHING, batch 173)

- cSubScr.h: `SubScrEnt ent[9]` at 0x00 (kind + screen, func_0015FD18's lookup), `int nextKind` 0x4C, MenuScreen `busy` 0x58, `unk5A..unk5D`, `sel` 0x64, `cVtEnt *vtable` 0x70 (includes cModel.h for cVtEnt), the overlay fade fields fadeColor/fade/fadeTick at 0xED0..0xEDB, `stack[9]` + `stackSel[9]` (main's `stack[11]` overlaps the selection bytes at 0xF0C), `savedBg` union at 0xF18, `__attribute__((aligned(16)))` (retail tests unkEDC & 0x82 with one `ld` from 0xED8).
- One type per record: 00160c48.c `FadeOverlay`, 00160ff0.c `cEvMovie` (movieNo 0xB9C) and the char */void * definitions of func_0015FF10, func_00160E78 (00160e78.c), func_00160F38 (0013eba0.c), func_00160FF0, FadeOverlay_tick are all cSubScr: merge their fields into cSubScr.h and retype the definitions to `cSubScr *`, then re-verify. Obj0000_Call_func_0015FD18_Field_48_161288 (000000.c) is defined `void (unsigned char *)` but returns func_0015FD18's result: define it `MenuScreen *(cSubScr *self) { return func_0015FD18(self, self->kind); }` (0015ff10.c and 00160b90.c declare it locally).
- gameWork.h: `GAMEWORK_AT` moves here from 00160020.c (00160ff0.c's GW_SYSFLAGS/GW_LOCKFLAGS are the same idea); `unsigned int flags5DC` 0x5DC; flags5D8 becomes `int` (retail ANDs it with a sign-extended -0x4001; 00160ff0.c reads it as int) — see decisions_needed.md.
- Set_bg_mode is defined `(int mode, unsigned char r, g, b)` (0030e0.c); 002bf2d0.c and 001f7900.c declare it `(int, int, int, int)`: one prototype in a header. pl00_SubscreenMode (0010b888.c) and Gp_drawGreyScreenQuad (001de7c8.c) need header prototypes too.

## func_00153B00 (progress/held/00153b00_nm.c)
- cModel.h: new `cModelNodeDraw` (0xD0: mtx[4][4] at 0x10 with the fog terms in [0][3]/[1][3], eye 0x50, uv 0x70, color 0x80, world[4][4] 0x90); cModelNode's `unk160[0x220]` becomes `cModelNodeDraw draw[2]; char unk300[0x80];`.
- cModel.h: CPARTS/CMODEL `char unk2BD` becomes `unsigned char fogMode` (0 world fog, 1/2 fixed colours). Only writer on main: 001495a0.c (`self->unk2BD = 0`), rename there.
- `memcpy` has no shared prototype in include/ (rules name criStm.h, which lacks it); 002c8ef8.c declares it locally. Add one shared prototype.
- `cVecQuad` lives in cSnd.h; a model file needs it, so it belongs in cOmBase.h next to cVec.
- func_002D7E50 takes 7 arguments (reads 0, 2, 3, 5); func_002D81A0 3; both void. func_0030A548 is a 4x4 matrix copy: one prototype `(void *dst, void *src)` for its users (0014b9a0.c, 002cc150.c; 001b5160.c declares it `(void)`).

## func_0031B560 (progress/held/0031b560_nm.c, draft)
- PadState (0x7C: hold/prev/trg/rel as unsigned int masks, analog, mode, rep/repFast, repWait[32]/repWaitFast[32], stick[4], press[12], axis[4], angle, camAngle) and PadPort (data at 0x100, data2 at 0x480) want a pad header; 0031a808.c's view of the same record should use it.
- Prototypes from retail entry code: func_0031AF40(PadPort *, int mode) reads 0x154/0x4AC of the port; func_0031BDC8(PadPort *) reads port+0x100; func_0031AF70(int) narrows its argument to a byte itself.
- CVEC_INIT_SUB(r, a, b): cVec r = *a - *b, CVEC_INIT_MUL's shape. Only needed in cVec.h if a function using it matches.

## cEmManage_CreateItem (progress/held/002923e8_nm.c, draft)
- cEmManage.h overlay: `int dropMiss` at 0x534 (random drops missed since the last one), `int lastItem` at 0x5A8 (last random kind; unk5A6 is now 2 bytes).
- cGameObj.h overlay: cGameObjVt slots 0x40/0x44 (`unk44(self)`, called first on a new item) and 0x70/0x74 (`unk74(self, cVec *pos)`, given the drop position).
- cCoreSave.h: `static __inline__ int cCoreSave_isHard(cCoreSave *self) { return cCoreSave_getGameDifficulty(self) == 2; }`. Retail's `xori`/`beqz` difficulty tests only come out through a value-returning helper; a direct `!= 2` loads the 2 and uses beq.
- cEmManage_CreateItem's prototype goes in cEmManage.h as `cGameObj *cEmManage_CreateItem(cEmManage *self, cVec *pos, int kind, int mode)`. Callers to fix at registration: 0016acd0.c, 00285f78.c, 00241eb0.c (int return, `void *` first argument), 00273d30.c and 0014ff00.c (void return), with `(int)` casts on the position argument.
- func_00291010's prototype (five units declare it locally with `void *` placeholders) also belongs in cEmManage.h.

## func_0028D7E8 (progress/held/0028d7e8_nm.c, draft)
- EmMeshEnemy local view of the 0x28Bxxx enemy class: meshFlags at 0x1534, `cModelNode *mesh[2][4]` at 0x1550. cEm00.h names 0x155C..0x156C differently (other enemies' fields), so this stays a local view until the enemy classes are split. 0028bec8.c passes a cEm00 *.
- The view needs `aligned(16)`: retail's two-bit motion test is one 64-bit ld of 0x3A8, which fold only builds on a record aligned to at least 8.

## func_0023E6B0 (held/0023e6b0_nm.c)
- cEm00.h: prototypes `void StoreMotionParams_2609E0(char *a0, int a1, int a2, int a3, int t0, short t1);`, `void Set_Fields_1884_1894_2609F8(char *a0, int a1, int a2, int a3, int t0, short t1);` and `void func_0026EE40(char *a0, int a1, int a2);` (definitions in 00138528.c and 0026ee40.c; those files include cEm00.h at the checkpoint).
- cOmBase.h: `void Obj1D00_ClearState_6(cOmBase *self);` and `void Obj1D00_ClearState_7(cOmBase *self);` (definitions in 001d00.c). 0023d7d0.c and 0023c620.c declare them `(int)`; correct those callers when the prototype moves.
- cEm00.unk698 is a `cDamageTake *` (its 0x34 attacker is what the step aims at; held 00253de8.c and 0020cd00_nm.c read it the same way). 00255eb0.c has a local cEmLink view of the same word: merge it at the checkpoint.

## func_00224090 (held/00224090_nm.c)
- A shared `static __inline__ float absf(float x) { return x < 0.0f ? -x : x; }` for the enemy files (the inline gives retail's copy-then-neg shape; the bare expression negates in place). Candidate home: a small math header next to angle.h, or angle.h itself.
- `void func_0027DD10(void *a0, float f12);` (definition in 0027dd10.c, which clamps the float at 0x15B4 of its argument) belongs in cEm00.h with the other enemy helpers; cEm00.subA is passed to it, so subA may really be a pointer (the record whose 0x15B4 float it clamps).

## func_00231AC0 (held/00231ac0_nm.c)
- cEm00.h: `float unk75C;` at 0x75C, split from `unk754[0xC]` (now `unk754[0x8]`); func_00231AC0 tests it against 0 to pick the left or right turn. Already in the held overlay.

## D_005FEC58 has three types (blocks func_0016B1F8, the shop buy/sell screen)
- func_002C90A0 (draft) takes `cRecordIndex *`, func_002C9950 (src/cod/002c9950.c) takes `SortList *`, and func_002C9BB0/func_002C9B78/func_002C9BF8 (src/cod/002c9b78.c) take `int *`, all for the object at D_005FEC58. 002c8ef8.c declares func_002C90A0/func_002C9950 locally with `void *`. They need one type (cRecordIndex in cRecordIndex.h, with SortList's fields merged) and shared prototypes before func_0016B1F8 (which calls all five) can be written with real signatures. func_0016BC78 in 00150830.c also passes `D_005FEC68` (the `limit` word of that record) through a `void *` extern.

## func_002873B8 (held/002873b8.c)
- cEm00.h: `unsigned char unk1604;` at 0x1604, split from `unk1604[0x10]` (now `unk1605[0xF]`). In the held overlay.
- cEmManage.h: `struct cGameObj *func_00291010(cEmManage *self, cVec *pos, struct cGameObj *skip, int kind, int flag, float rotY, float range, float angle);` No C definition; the signature is from retail (a2 is compared with each listed enemy and skipped, t0 is a flag tested with the hit points, it returns the enemy found). The src callers 0014b640.c, 00285f78.c and 00286aa8.c declare it locally as returning int with void * arguments; drop those and recheck the three units at the checkpoint. held/002923e8_nm.c already uses the header.
- cGameObj.h: `void Add_nullspeed(char *a0);` (definition in 001ee1c0.c). cModel.h: `void cModel_calcNullPart(cModel *self);` (definition in 0014a2b0.c). Local copies to drop: drafts/cod/0028a780.c (both, as `char *`), and the src callers that declare them with `void *`.
- cEma2.h: `int cEma2_startHitCooldown(cEma2 *self);` (definition in 002894b8.c, which already includes cEma2.h). The overlay is a copy of include/godhand/cEma2.h with that line added.
- One type per record: func_002873B8 uses cEm00 fields (unk1590, gotoPos, gotoFlags, unk15BC) on the same object cEma2.h describes, and calls cEma2_startHitCooldown with a `(cEma2 *)` cast. cEma2.h puts `mesh[8]` over 0x15B4..0x15D3, while cEm00.h (and this function) have a float at 0x15BC, so one of the two layouts is wrong for this enemy. That needs a decision before cEma2 and cEm00 can share one header type.

## func_002269F0 (held/002269f0.c)
- cEm00.h: `void func_0026BEF0(cEm00 *self, int kind, int arg);` (no C definition; retail reads a0..a2 and sets no v0). src callers 00227ca8.c, 0024a768.c and 00225e30.c declare it locally as `(void *, int, int)`; drop those at the checkpoint.
- cEm00.h: `int func_00262AA8(cEm00 *self);` (no C definition; retail returns 0 or 1 in v0, and func_002269F0 tests it). src callers 00215d40.c, 0024f050.c and 002557f8.c, and drafts/cod/00217560.c, declare it `void`; fix them to the header and recheck those three units at the checkpoint.
- cGameObj.h: `int Obj0000_IsSet_Field_15F4_Bit_1000_12C530(char *a0);` (definition in 000000.c).
- cEm00.unk744 is passed to ForwardAnimParamPairByIndex_27EA50 as its object, so it is a pointer, not an int; the draft casts `(void *)self->unk744`. Retype it when the header is merged.

## func_00284AF8 (held/00284af8_nm.c)
- cModel.h: `void cModel_calcWorldParts(cModel *self);` (definition 0014a038.c), `void IK_InverseKinematics(void *ik, void *self);` (no C definition; about 20 files declare it locally the same way), `void cParts_setRotationOrder(char *arg0, int arg1);` (definition cParts.c). Drop the local copies at the checkpoint.
- cModel.h: inline `cModelNode_hide` / `cModelNode_show` (dispFlags bit CMODEL_NODE_HIDE, null-checked). src/cod/002897f0.c has local copies (`cMeshNode_hide/show` on cOmBase.h's cMeshNode, the same record); switch it to these together with retyping cEma2.mesh to `cModelNode *`, and check it still matches.
- cObjBase.h: `void cObjBase_KageInit(struct cObjBase *self, char *work, void *shadowData);` (definition 0014ea28.c). 002b6768.c and 002897f0.c declare `(void *, void *, void *)`.
- cOmWeapon.h: `void cOmWeapon_setParent(cOmWeapon *self, cOmBase *par, int idx, cVec *heldPos, cVec *heldOfs);` (definition cOmWeapon.c). This also answers the earlier entry about the K&R callers.
- cCollisionSolid.h: `void cCollisionSolidManage_CreateSphere(int mgr, int owner, int mtx, int centre, float radius);` (definition 00134880.c takes four ints). `void cCollisionSolidManage_CreateUnit(void *mgr, void *owner, int kind, float radius);`: its definition in 001346f8.c takes a file-local `Mgr *`, so the header can't name that type until Mgr moves into cCollisionSolid.h (decision).
- motion.h: `int setMotionInfo(struct cObjBase *self, char *motion, char *motionEnd, unsigned int start, float rate, float blend, int flags);` (no C definition; the typed form 0014ead8.c, 0014ec88.c, 00102938.c and 001027d8.c already use). 00134880.c (and held/00134880_def.c) declare it with ints, and 001582a0.c with `void *` self; those need casts at their calls when they switch to the header.
- cEmManage.h: inline `SET_EM_DATA_copy(d, s)` (the record's field-by-field operator=); 002897f0.c copies the same eight fields by hand and can use it. `int func_0028EBF0(void *self, SET_EM_DATA *data, int arg);`: callers disagree (002897f0.c `void *arg`, 0027b810.c/002816e0.c/0027ef10.c/0027de60.c `(char *, void *, int)`, 00279d88.c `(void *, void *, int)` returning int), and the NM draft drafts/cod/0028ebf0.c defines it with local PartModel/PartSrc types for the same records. The draft's PartSrc is SET_EM_DATA.
- cEm00.h: `int func_00288DA8(cEm00 *self);` (definition 00288da8.c, which includes cEm00.h). `int unk15B8` at 0x15B8, split from the unk15B8[4] pad.
- vecInline.h: `vec3_set(float *v, x, y, z)` beside vec4_set_point (the overlay is a copy of include's with it added).
- D_00747A50 has two types on main: `unsigned short` (0011ecb0.c, 00146f18.c, 001169d8.c, 0020fbb8.c, the stage word) and `unsigned char []` (0028fb88.c, 002920b0.c, 0014a038.c, 001633a0.c, 002bb1f0.c read byte 1, the difficulty). The draft follows the enemy files' `unsigned char []`. One type is needed (a struct with the stage and difficulty bytes would cover both).
- Layout conflict: see decisions_needed (func_00284AF8). The draft reaches 0x674-0x680, 0x690, 0x1530, 0x15CC-0x15E8 and 0x15EC through EMHAND_* offset macros because cEm00.h names those offsets for another enemy class.

## func_00232500 (held/00232500.c)
- cEm00.h prototypes, each with its definition's types: `StoreMotionParams_2609E0` and `Set_Fields_1884_1894_2609F8` (00138528.c: `(char *, int, int, int, int, short)`), `func_0027DD10(void *a0, float f12)` (0027dd10.c), `int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(cOmBase *self)` (001004c8.c), `void SetOrientByType_26AF20(void *a0, int a1, unsigned int a2)` (0026af20.c). Local copies to drop: 0022a8d0.c, 002266f0.c (`void *`/int t1 forms), 0021a538.c (four-argument K&R-style calls), 0023d7d0.c (`int a0`), 00233248.c (`void *a0`), held 0023e6b0_nm.c and 00224090_nm.c.
- cGameObj.h: `FX_KIND_NONE` (0x4E2, the "no effect picked" kind of the attack steps) and inline `fxKind_isSet(kind)`. Retail tests the kind with `xori`/`beqz`, which a plain `kind != 0x4E2` doesn't give (it loads the constant). main's 0023d7d0.c and 0020fbb8.c write `(x ^ 0x4E2) != 0` for the same test; they can use the helper.


## func_0028B190 (held/0028b190.c)
- cEm00.h prototypes, each as its definition declares it: `int func_0028C400(void *a0)` (0028c400.c), `void func_0028CED8(void *a0)` (0028ced8.c), `void func_0028CDD0(char *arg)` (0028cdd0.c), `char *func_0028D048(char *a0, int a1)` (0028d048.c), `void cOmBase_attachWeaponGrip(cOmBase *self, void *weapon, int left)` (0028d3d8.c), `void cOmWeapon_loadEffectParamsByType(void *a0, int a1, unsigned int a2)` (0028d500.c), `void cEm53_SetParent`, `void cEm57_SetParent`, `void func_00283BE8` (all `(char *p, char *q, int idx)`, 00276e90.c). From retail, no C definition yet: `void func_0028D138(char *a0, char *a1, int a2)` (reads a0..a2, sets no v0); `void Obj1D00_ClearState_6(cOmBase *)`/`_7(cOmBase *)`. Local copies to drop: 0023c620.c and 0023d7d0.c (`Obj1D00_ClearState_7(int)`), 00233248.c (`(void *)`), held 0023e6b0_nm.c.
- player.h: `void pl01__SetParent(void *a0, void *a1, int a2)` (00100ed8.c).
- cGameObj.h: `cGameObjVt.unk44` returns int (func_0028D048 and func_0028B190 test it; it was `void`); `int unk2D0` at 0x2D0 split from the padding (cleared bit 31 / set bit 30 by the carrying enemy).
- The base cEm00 stores its room entry at 0x1510, its shadow work at 0x670 (cEm00.h: atkHit), meshes at 0x1550..0x1584 (cEm00.h: unk155C..watchArg) and weapon/child objects at 0x1638..0x1658 (cEm00.h: flags1644, unk1650). The file uses named offset macros; see decisions_needed.md.

## func_00214DE0 (held/00214de0_nm.c)
- cEm00.h prototypes: `int func_00273960(cEm00 *self, float reach)` (definition drafts/cod/00273960.c; src 00229268.c and 002705d8.c declare `(void *, float)`), `void func_0026A638(void *a0, int a1)` (no C definition; retail reads a0/a1 and sets no v0; 0022ace0.c, 0022af90.c, 0022b358.c and 0023f5c8.c declare it the same way locally), `struct EmThrower; void EmThrower_throwHeld(struct EmThrower *self, int no, int fast);` (definition 001a6098.c, whose EmThrower record is file-local; the forward tag lets callers pass a cast pointer until the record moves to a header). Local `(void *, int, int)` copies to drop: 0022ace0.c, 0022b358.c, 0023f5c8.c, 0024c0f0.c, 0025e600.c.
- cEm00.h fields split from padding: `float unk1714` (tested `<= 0` before the throw), `float unk1728`, `int unk17A8`.
- D_00747A50 is read as `unsigned short` here, as 0023f5c8.c does (the stage word); see the func_00284AF8 entry for the type conflict.

## func_00299DE0 (held/00299de0_nm.c)
- No new types. Another local copy of the GS_SET_* macros (with GS_SET_XYOFFSET, GS_SET_ZBUF, GS_SET_CLAMP, GS_SET_TEXA, as drafts/cod/002a0c60.c has them); six src files and three drafts now carry copies. Proposal: one `gsReg.h` with the macros, `PushEntryAtField10000_299868(char *, long, long)` (definition 00200cb0.c), and the screen globals D_003C1180/D_003C1188/D_003C118C/D_003C1194 (int), D_003C11AC (u_int), D_003C11B8 (int), D_00586B80 (int).

## func_00175F38 (held/00175f38_nm.c)
- New record (file-local in the draft): `cOmBreak`, a cOmBase with two breakable parts. 0x5EC fxId / 0x5F0 fxKind (SetEffect arguments), 0x600 `cDamageUnit *partHit[2]`, 0x608 `cDamageUnit *bodyHit`, 0x610 `char debris[3][0x60]` (the objField.h records), 0xD30 `unsigned int broken[1]` (bit per part, high bit first), 0xD34 `short timer`, 0xD38 `short partHp[2]`, 0xD3C `signed char lastPart`. src/cod/001769e0.c and 001736a8.c (func_00176A50, func_00176CB8, func_00177488) reach the same fields by raw offset, and func_001775C0's class has the same layout, so it belongs in a header (`cOmBreak.h`) when one of them matches.
- D_00421290 is the per-piece layer range table, pairs of (first child, count) bytes; the draft types it `LayerRange D_00421290[]`, while 001736a8.c declares `unsigned char D_00421290[]`. One type is needed when the record moves to a header.
- `void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self)` (definition 001b7300.c) has no shared prototype; 0016acd0.c declares it `(int)`, 00173ec0.c `(void *)`. Put it in cOmBase.h.
- Children reached through cOmBase.children are cParts (cModel.h): the draft casts to read partFlags (CPARTS_NO_LOCAL/NO_PARENT) and mtxLocal/mtx.


## func_00169358 (held/00169358_nm.c)
- New header cShopPanel.h: the `ShopPanel` record of drafts/cod/00169df8.c (that draft keeps a file-local copy; switch it to the header) plus `cGameObj *player` 0x1D8, `short combo` 0x200, `short inputTimer[5]` 0x260, `int input[5]` 0x26C, `unsigned short prevMotion` 0x280, `unsigned short inputNum` 0x282, and the SHOP_ROW_* indexes with SHOP_ENT_HELP (30) and SHOP_ROW_NEW (31). Prototype `void func_0016BCE0(ShopPanel *self, unsigned short index)`: its definition in 0011ecb0.c takes a local `Owner` (part pointers from 0x80, the same panel); change it to ShopPanel (offsets are the same: parts[n + 0xF] is 0xBC + 4n).
- cRecordIndex.h: entry fields `unsigned int price` 0x00, `unsigned short name` 0x10, `short sortKey` 0x14, `short id` 0x18 (split from the pads). `limit` (0x10) becomes `unsigned int`: this function and func_002C9950 compare it unsigned and convert it to float as unsigned; func_002C9008 compares it signed. Prototypes `cRecordIndexEntry *func_002C9008(cRecordIndex *, int)`, `void func_002C90A0(cRecordIndex *, unsigned char)`, `void func_002C9950(cRecordIndex *)`, `int func_002C9A90(cRecordIndex *, int)`. Definition corrections: 002c9008.c (`char *a0`, returns `void *`), 002c9a90.c (`int *self`), 002c9950.c (local SortList view: items 0x00, count 0x10, order 0x14, key 0x14 of a 0x24 record) move to `cRecordIndex *`; local copies to drop in 002c8ef8.c (`void *` forms) and 0011ecb0.c.
- cCoreSave.h: `cCoreSave_ckClearStage(cCoreSave *self, unsigned short no)`. The definition (001004c8.c) takes `unsigned int no` and masks `no = no & 0xFFFF;` on entry; with `unsigned short` the mask line goes, and the callers' `(unsigned short)` casts (001627d8.c, 00162c98.c) can drop. Check 001004c8.c still matches.
- pl00.h: `void pl00_SubscreenMode(void *a0, int a1)` and `void pl00_SubscreenMotSet(void *a0, int a1)` (definitions 0010b888.c); local copies to drop in 0016c678.c, 001689e8.c and held 001601d8_nm.c.
- cVec.h: `CVEC_SET_XYZ(d, fx, fy, fz)`, `d = cVec(fx, fy, fz);` into a float[3] (the three-float constructor with w = 1, then operator= on xyz). Same shape as CVEC_SET_SUB: binds d_ then r_, copies by name.
- D_003BC7D0 is each technique's input list, `int [][5]` here (row stride 20 bytes, retail multiplies by 20 and adds the input index times 4); 00126918.c declares it `int []` and indexes `combo * COMBO_ENTRY_WORDS`. One type is needed.
- D_00747A80 (the input/event lock bits) has no header and five local types (int, unsigned int, unsigned int []); one header declaration is needed.
- cIDMenuPanel.h: `signed char step` at 0x5B in cIDPanelHead (split from unk5B); ShopPanel starts with `cIDPanelHead head`. 00169258.c's func_00169258 reads the same byte as `o[0x5B]` and sets `o[0x5A]` (head.state).

## func_001C3090 (held/001c3090_nm.c)
- File-local `cOmShatter` view: a cOmBase whose children fly off as pieces, `char *piece` at 0x608 (one 0x60-byte objField record per child) and `signed char shattered` at 0x60C (its caller at 0x1C36xx loops over the children while it is positive). Move to a header when the caller matches.
- cGameObj.h: vtable slot 16 (`lockOn`, 0x80/0x84) returns a `cVec *`: this function and 00124fd8.c read the vector it returns; the header declares it `void (*)(void *)`.

## func_00291010 (held/00291010_nm.c)
- cEmWrap.h (held copy): cEmActorVt gains `getPos` (0x68/0x6C, returns cVec *), `ckTarget` (0xC8/0xCC, as cGameObjVt names it) and `unkE4` (0xE0/0xE4, 0: a target search passes over the actor); cEmActor gains `unsigned char unk617` (nonzero: passed over), split from unk5AC, with offset checks.
- Prototype unification at the checkpoint: cEmManage.h's `cGameObj *func_00291010(cEmManage *, cVec *, cGameObj *skip, int kind, int flag, float rotY, float range, float angle)` replaces the local externs in 0014b640.c, 00285f78.c, 00286aa8.c, 002412a8.c (int returns, void * arguments) and 00101eb8.c (wrong argument order: it declares the floats before t0; the call passes the right registers by accident). Each caller then needs its first argument as `&D_005864F0` and its `== 0` tests on the pointer; rebuild all five.
- Retail quirk to keep: the "nearest" distance (1.0e16) is never lowered, so kinds 3 and 4 take the last enemy in range, not the nearest.

## func_00100FB8 (held/00100fb8.c, MATCH)
- New header cloth.h: `ClothSphere` (0x30 bytes: boneA 0x02, boneB 0x03, blend 0x04, radius 0x08, cVec ofs 0x10, cVec unk20 0x20), the externs `D_00460E00[12]`, `D_00461040[11]`, `D_00461250[7]`, `D_004613A0[12]` and the CLOTH_SPHERE_SET macro. Add its allowlist line. src/cod/00100870.c declares the four tables as `char[]`: switch it to the header (the casts it needs at the func_001038E0 call go away if func_001038E0's fourth argument becomes `ClothSphere *`; func_001038E0 is unmatched, so keep its prototype local until then).
- cVec.h: new CVEC_INIT_XYZ(v, fx, fy, fz), the three-float constructor in place (w = 1). It has to be a macro: as an inline function (cVec_set4, vec4_set_point) the arguments go through registers and the 0.0 components are stored from an FPU register instead of $zero.
- The bss sizes in asm/data/cod/00460E00.bss.s are splat's guesses (D_00460E00 says 0x224; the table is 12 x 0x30 = 0x240).

## func_002DF950 (held/002df950_nm.c, NON_MATCHING) and cloth.h
- CLOTH_SPHERE_SET now takes both vectors (ofs, then unk20): one entry of D_0061AD90 has an unk20 that differs from its ofs. 00100fb8.c was regenerated with the ten-argument form and still matches (923 insns).
- New externs in cloth.h for the enemy tables: `D_0061A9A0[2]`, `D_0061AA00[4]`, `D_0061AAC0[5]`, `D_0061ABB0[2]`, `D_0061AC10[4]`, `D_0061ACD0[4]`, `D_0061AD90[8]`, `D_0061AF10[6]`, `D_0061B030[6]`, `D_0061B150[6]` (sizes from the gaps between the bss symbols, which agree with the entry counts).

## EmClothInit (held/002de980_nm.c, NON_MATCHING) and cloth.h
- clothSphere.h is renamed cloth.h, and it now also holds the cloth record `EmCloth` (0x80 bytes: numJoints 0x00, joint 0x04, parent 0x18, child 0x1C, the float tables 0x28/0x2C/0x30, spheres 0x34, unk38 (the sphere count in the enemy set-ups), owner 0x58, drift 0x60, unk70) and the prototype `void func_001038E0(void *self, EmCloth *cloth, void *model, float arg3, float arg4)`. The joint, parent and child tables hold joint numbers (0xFF at the ends of the chain); the three float tables have one float per joint.
- src/cod/002df860.c (EmClothMove) keeps a local `EmCloth` view with only `drift`. Switch it to cloth.h at the checkpoint; the name and the 0x60 field are the same. Re-verify it.
- func_001038E0 is declared locally as `(char *, char *, char *, float, float)` in src/cod/00100870.c and src/cod/001ca040.c. Switch both to cloth.h; their `p + 0x2050` / `p + 0x2130` arguments become `(EmCloth *)(p + ...)` until the player records are typed. Re-verify both.
- EmClothInit has three local declarations that disagree: cObjSimple.c `(int, cObjSimple *, void *, void *)`, 0016ee10.c `(int, void *, void *, void *)` and 00271410.c `(int, char *, char *, char *)`. The definition is `void EmClothInit(int emNo, cEm00 *self, void *model, EmCloth *cloth)`, matching its sibling EmClothMove. Once it matches, put the prototype (and EmClothMove's) in cloth.h and cast at the three callers.


## func_002D22F0 (held/002d22f0_nm.c, NON_MATCHING): BGM hit areas
- cBgmData.h (held copy): `cBgmHitEnt` (0x6C bytes: pt[4][2], yLo 0x20, yHi 0x24, id, flags 0x29 (shape bits 1-2), prm[4] 0x2C as `cBgmHitPrm` unions, unk3C (stop the other BGM on entry), unk3D (group bit), unk3E (distance from: 0 camera, 1 player), unk3F (0: shape points, else segA/segB), segA 0x40, segB 0x4C, state 0x5C (CBGM_HIT_STATE_IN/ENTER/LEAVE), action 0x68), `cBgmHit.magic[4]` ("BMH"), and `int HitNode_dispatchByKind(cBgmHitEnt *, void *, int)`. No src file used the old unk2A padding. src/cod/001731b8.c's local `HitNode` (flags at 0x29) is a view of cBgmHitEnt: switch it to the header and re-verify.
- cSnd.h (held copy): fields bgmAttr 0x50, bgmAttrPrev 0x54, bgmDefAttr 0x58, f74, f88, fA0; prototypes for cSnd_AddBgmAttr/ClearBgmAttr/AddBgmDefAttr/ClearBgmDefAttr `(cSnd *, int)`, cSnd_AllocBgmNode, cSnd_BgmNodeStart, cSndBgmNode_FadeIn/FadeOut `(cSndBgmNode *, float)`, cSnd_BgmHitBeSet, cSnd_SetBgmLevel. Definition corrections to apply and re-verify: cSnd_SetBgmAttr and cSnd_SetBgmDefAttr are `void (cSnd *, int attr, float time)` (they read f12 and set no v0); cSnd_FindBgmNode returns `cSndBgmNode *` and takes `(cSnd *, int bank, int reqNo)` (main: `void *(int, int, int)`).
- cSnd.h (held copy): `cSndBgmNode.flags` (0x98) is now `int`. Retail clears bit 0x4000 with `addiu -0x4001`, which only a signed field gives (an unsigned one gives lui/ori 0xFFFFBFFF). The full build at the checkpoint must reproduce both hashes with it; every src/cod file that includes cSnd.h depends on it (002cc578.c, 002cc628.c, 002cc728.c, 002cc830.c, 002cca78.c, 002cd310.c, 002cf218.c, 002cf310.c, 002d14f8.c and others). If any unit changes, revert to `unsigned int` and note it here.
- criStm.h (held copy): `int func_003A5678(const char *a, const char *b); /* strcmp */`. src/cod/cSnd.c declares it locally: switch to the header.
- seqNode.h (held copy): UpdateSequenceNodeWeighted_373560 `(void *, int, float)`, SetSequenceBlendWeight_3739A0 `(void *, int, float)`, ClearFlagBits_373858 `(void *, unsigned int)`. Check them against their definitions' files before merging.
- cVec.h (held copy): CVEC_ASSIGN(d, s), operator= xyz only with the self-check, as in CVEC_SET_SUB.
- Local in the draft: `float GetDistCalcPointSegment(cVec *segA, cVec *segB, cVec *pt, cVec *nearest)` (0x157210; a3 is an optional out for the nearest point, written xyz). Move it to a header when its file matches.
- For the record: with the floats bound before the stores (`float x_ = fx, ...; v.x = x_; ...`) the a/b set-up matches retail, unlike CVEC_INIT_XYZ, which matches 00100FB8. The two retail shapes are probably the cVec(x, y, z) constructor and a set method; not split into two macros until a second function needs the other shape.

## After checkpoint 176
- 27 overlays in progress/held/inc still carry pending edits (the W-set prototypes, the cSnd BGM block and cSndMemHeap prototypes, cModel.h cTexTable/fogMode, BlackJack.h, cSubScr.h, regTbl.h, ...). They were cut from include/ because main's callers declare those helpers differently. Re-merge them with build/scratch/hmerge.py once the typing PRs land.
- func_0039C390 (_sceMpegError) has four signatures: sceMpeg.h `int (int m, int msg)`, 0039c2c8.c `void (void *, const char *)`, 0039acd8.c `void (Ctx *, char *)`, 00100248.c `void (int, int)`. Give sceMpeg.h `void func_0039C390(sceMpeg *m, const char *msg)` and fix the callers; 0039b3f0_nm and 0039b960_nm stay held until then. 0039c5b8_nm waits on the libmpeg header for `_getRef0`'s state type.
- Main cleanups still open: 001fab28.c and 0031a718.c should use the SndRpc fields (prototypes for func_003B3128/func_003B2F48 missing); 00376f18.c's `Rq` is SndChReq; cObjPtrArrayWrapper.c's local `cVec` tag clashes with the real cVec; raw D_00754C38 views; cDamageUnit_SetDamageCollActive has two signatures; cOmHitVolumeSetup's void * prototype; 0015bcf0_nm needs pack.h's func_00151630.
- cIDManager.h and criStm.h both declare func_003A52F0 (memset); keep criStm.h's and drop the other.
- `struct cSceAtUnit` has two different definitions on main, in cSceAtUnit.h (flags/type at 0x34/0x35 only) and cSceAtManager.h (flags, type, hitKind 0x3B, dataC 0x3C, ...). Merge them into one header type (cSceAtManager.h's is the fuller one) and give the flag word at 0x50 named bits (31 hit now, 30 hit last frame, 29 entered, 28 left, 27 button, 26 auto, 25 dispatched; from func_002C1618). func_002C1618 waits on it.
- D_007479F4 (the default id/data pack pointer) is declared `int` in 001c8f30.c and `VibHead *` in 001710f0.c; give it one header type (a pack of offsets). func_002B1F80 waits on it.
- menuKey.h: add `MENU_KEY_PAGE_PREV 0x1000000000L` and `MENU_KEY_PAGE_NEXT 0x10000000000L` (overlay progress/held/inc/godhand/menuKey.h). Used by held 00165eb8.c; 00137cb8.c defines the same bits locally as PAD_PAGE_PREV/PAD_PAGE_NEXT and should switch.
- cSubScr.h MenuScreen and cIDMenuPanel.h cIDPanelHead both describe the cIDBase menu head (0x5A, 0x60: unk5A/next vs state/result). Merge into one head type; held 00165eb8.c uses cIDPanelHead.
- cIDBase.h has no prototypes for the cIDBase methods (cIDBase_initialize, cIDBase_restartAnim, cIDBase_getIDWork, cIDBase_initIDWork, cIDBase_setPackedMessData; defined in src/cod/id/cIDBase.c, 00126770.c, 001d0fd8.c) and 26-38 files declare their own copies. Move them into cIDBase.h with the definitions' types and drop the local copies; func_00164F30 (idsubscrmenu set-up) waits on it, with func_00161500, cHeatSys_GetHeatRatio and Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0.
- cModel.h: cMeshInfo `unsigned short uvSpeed[2]` at 0x3E (half floats; split unk38[0xB] into unk38[6], uvSpeed, unk42) and `float F16toF32(unsigned short half);` (defined in 00156488.c, which should include cModel.h). In overlay progress/held/inc/godhand/cModel.h; used by held 00149220_nm.c.
- cMessDrawFontCode.h: `int func_002AF218(unsigned short *text);` (wait of the code at text; draft drafts/cod/002af218.c returns unsigned short, callers read int) and `int func_002B45F8(struct MessWin *self, unsigned short *text, unsigned short kind);`. Overlay progress/held/inc/godhand/cMessDrawFontCode.h; held 002b45f8.c.
- MessWin has three local definitions (00126820.c, 00124fd8.c, 001b9030.c) under one tag; merge them into one message-window header type.

## cMessDrawFontCode.h callers still on implicit declarations (after checkpoint 179)
- func_002AF218 and func_002B45F8 now have prototypes in cMessDrawFontCode.h (func_002B45F8 registered at checkpoint 179).
- Still calling them with no declaration in scope: 00126820.c and 00126770.c (func_002AF218, passing an int for the text pointer), and 001b7de8.c and 00124fd8.c (func_002B45F8). 001b7de8.c's func_002B3B70 also passes `char *a0` and reads an undeclared `a1`.
- Each needs `#include "godhand/cMessDrawFontCode.h"` and typed arguments (`(struct MessWin *)`, `unsigned short *` text). Each file must then be rechecked to still match. Left for a focused cleanup, because three different local `MessWin` definitions would meet the header's `struct MessWin` tag.

## EmThrower (0x6E4 held objects) and capVu0ApplyMatrixXYZ / cOm60_setThrow prototypes
- EmThrower is local in src/cod/001a6098.c (mtx 0x80, held[3] 0x6E4). drafts/cod/0026a838.c also needs it, plus playerDist at 0x618 (cEm00.h already names 0x618 `playerDist`). It goes to one header when the draft lands: cEm00.h's unk6E4[8] split into `struct cOm60 *held[2]` would clash with unk6EC (a cOmWeapon in cEm00.h; EmThrower reads it as held[2]). Ask which is right before merging.
- capVu0ApplyMatrixXYZ: the definition (src/cod/001f8350.c) takes `(void *, void *, void *)`; 001a6098.c and 00153808.c declare `(cVec *dst, float *mtx, cVec *v)`. Proposal: type the definition `(cVec *dst, float *mtx, cVec *v)`, add the prototype to capVu0.h, include capVu0.h in all three, and recheck their matches.
- cOm60_setThrow: defined in 001b1760.c `(cOm60 *self, cVec *dir, float speed)`; declared locally in 001a6098.c. Move to cOm60.h.

## Checkpoint 180 candidates (held)
- menuCtl.h (overlay rebuilt from include/ at batch 180, plus the func_00380F80 prototype): MenuRowEnt value/type/min/max/step/fastStep (waits on the decision); new MenuActSet0, MenuActSet1, MenuActSlot, MenuActObj; prototypes func_0037A8F8, func_0037A9C8, func_0037AAB0, func_0037AB00. Then 0037a740.c drops its local MenuActObj and 0037ab00.c its SndActor/SndSlot.
- seqNode.h (overlay rebuilt from include/ at batch 180; the old one had no additions): `int func_00387430(short idx);` for 00145410.c's func_0037AAB0. Follow-ups after it merges: 00387430.c should include seqNode.h and read `D_0076E910[idx].flags` instead of its own `unsigned short D_0076E910` (it also calls func_003779D0, defined in 002cbdc0.c, with no prototype); 003870e0.c declares it `(int a0)`, and 0037b3f0.c and 001b7de8.c call it with no prototype.
- 0037ab00.c's `BuildSoundEventCd0_375CD0(void *snd, SndSlot *slot)` extern disagrees with the definition in 003749d8.c `(int a0, void *a1)`; its sound-entry siblings live in SndEntry.h. 0037b518.c declares GetSoundEntryStatus_375EF8 K&R style (`()`).
- Removed the espSys.h and cOmHitVolumeSetup.h overlays at batch 180: include/ already has everything they held (copies in build/scratch/ck180/overlay_old/).
- SndEntry records (proposal, not started): 00375ef8.c (GetSoundEntryStatus_375EF8 .. ClearSlotRefs_376AE0) and 00376f18.c work on three untyped arrays: D_0076F050 (96 pending entries of 0x40 bytes: used 0x00, id 0x04, flags 0x08, sub-record at 0x10 that FindSlotEntry_376A10 reads at 0x08/0x09/0x0E), D_00770850 (slots of 0xE0 bytes) and D_0076CF20 (48 of 0x50 bytes; 001f6b78.c's func_00376D28 reads it too). 00376f18.c also keeps local copies `Ch`/`Rq` of seqNode.h's SndCh/SndChReq. Typing these in SndEntry.h would unblock func_00376080 and clean those TUs.

## newlib stdio batch (merged at checkpoint 181)
- Headers: include/godhand/newlibStdio.h and newlibStdlib.h from progress/held/inc/godhand/ (+ .gitignore lines).
- carved_funcs tu moves: Obj0000_Setup_Fields_00_04_08_0C_0E_10_18_1C_20_24_28_2C_54, func_003A61F0, func_003A6290, func_003A62B0 -> src/cod/003a6188.c; func_003A6A88 -> 003a6a88.c; func_003A7C28 -> 003a7c28.c; func_003A8FE0 -> 003a8fe0.c; func_003A9228 -> 003a9018.c; func_003AD0C0 -> 003ace90.c; func_003A6CE0 -> 003a6ce0.c (new sn unit; 003a6cd8.c stays cygnus-2.96 with eofread alone). New carve func_003ACE90 -> 003ace90.c (compile unit `as: sn`).
- Follow-ups not in this batch (pre-existing drift, logged so the next newlib pass can take them):
  - `D_003FA62C` (_impure_ptr) is declared `int`, `int *` and `void *` in 00292f38.c, 0014ea28.c, 00150048.c, 003a7b58.c, 00133810.c, 003a6c58.c, 00150830.c, 003a6a20.c, 00389548.cc, and defined `int *` in 000000.c; `__errno` (Obj0000_Get_D_003FA62C_3A4FB8) is defined returning `int` while its callers declare `int *`.
  - The reentrant syscalls take `int *errp` in their definitions (_read_r func_003AE068, _write_r func_003AE128, _lseek_r func_003AE008 in 00133810.c/003ae068.c, _fstat_r func_003ADFA8 in 002a7280.c, _close_r func_003ADF50 in 0039ade0.c) while the stdio callers declare `void *` and other parameter types; they should take `struct _reent *`.
  - `_localeconv_r` (Obj0000_Get_D_0045FB80_3AD118, 000000.c) is defined `(void)`, but localeconv (func_003AD130, 00150048.c) passes `_impure_ptr`.
  - malloc (func_003A7C70, 0014ea28.c) is defined `int (int)`; 003a7b88.c declares `void *(unsigned int)`.
  - strtoul/strtol callers 00333b40.c and 0031f4e0.c declare `long long (int, int *, int)`; 0038d2b8.c's local declarations equal the new header's and can include it.
  - memcpy func_003A62D8 is defined `void (unsigned char *, unsigned char *, unsigned int)` in 001fab28.c; 003a6308.c declares `void *(void *, const void *, unsigned int)`.
  - `RegTbl.handleA` is used as the relocation table (RegReloc *) passed to func_00394290; 003943d0.c declares func_00394290 `(int, int, int, int)`. Retyping the field needs a decision (main names it).
  - D_0045F039 (_ctype_ + 1) is declared locally in 0038d2b8.c, 00387b78.cc, 00150048.c, 003875a8.cc, 002be240.c and 001ffa68.c; newlibStdlib.h now owns it.

## cIDBaseScreen batch (merged at checkpoint 182)
- New include/godhand/cIDBaseScreen.h: the five-row ID screen (flags 0x90, tbl[5][5] 0x94, row[5] 0x100, pos 0x290, float unk2A4, tex[0x23] 0x2A8, texNum 0x334, scale 0x338, rowY/rowX 0x33C/0x350, color0/1 0x364/0x368, item[0x23] 0x36C, listNum 0x3B2, item2[0x23] 0x3B4, attr[0x23] 0x3FA, phase/step/cur 0x41E-0x422, extraA/extraB 0x430/0x480, timer 0x4D0), SCR_STORE (was local in 00126820.c), `const float D_0041E880[5]`/`D_0041E840[4]` (both in .rodata; const is what lets cc1 hoist their loads as retail does), `short D_003BD70C`, and the prototypes of every screen function. Replaces six local views: ScrObj (00126820.c), IdTblScreen/IdTblEnt/IdWorkView (00144c90.c), EffPartObj (00145fc8.c), BlendWork (001450a0.c, 0012bf50.c), BlendSetup (00126918.c), raw offsets (00144b50.c, 00145238.c, 00145410.c, 00146190.c, 001451a0.c, 00133900.c, 00100508.c).
- Definition fixes: func_001451A0 takes the `num` its caller passes (not read); SetFlagAfterCopy_145160 takes `const short *` and no longer stores memcpy's result in an unread local; AnimNode.blendA/B/C (001f50a0.c) are the three table pointers.
- cIDBase.h: `void cIDBase_move(cIDBaseObj *self);` merged alone. The nine files that include cIDBase.h now use it (0013d698, 001617c8, 00143be8, 001632e8, 0013d400, 001680d8 pass `&x->base`). Still declared locally in 20 files that do not include cIDBase.h (001edf80, 001f28f0, 0013da98, 001dd1a0, 001e73c0, 0016acd0, 001661a0, 001ed680, 0013d540, 001ecbf0, 0013f070, 0013e4f0, casino/BlackJackId, 001dedc8, 0013bcc0, 001f4700, 0013c950, 001471f0, ...).
- The held cIDBase.h overlay still carries `cIDColor colorBase` in cIDBaseSrc and the func_002AC9B8 prototype. When it merges, 00144c90.c line 41 must read `src->colorBase.word` (it reads the plain word today), and 0013d698.c's local func_002AC9B8 declaration conflicts with it.
- criStm.h: `void *func_003A5148(void *dst, const void *src, unsigned int n)` (memcpy). Used by 001451a0.c, 001450a0.c, 0012bf50.c (was implicit), 00133900.c (was implicit). About 60 files still declare memcpy locally in 15 spellings.
- 00126918.c: the held cSnd.h overlay declares cSnd_BgmEventFade; 00126918.c's local copy now uses the definition's exact signature so the overlay merges cleanly (before, the held overlay made this file fail to compile). 001f5c48.c and 00102150.c still declare it with `void *`.
- Naming follow-up (not done; the names are on main): BlendWork_copyShortTable, BlendWork_copyTable, func_001451A0, SetFlagAfterCopy_145160, BlendSetup_load, GetNextAnimIndex_1451E0 and ScrObj_reset all work on cIDBaseScreen (item ids, textures, attributes, second ids, list load, next item id, reset). Rename to cIDBaseScreen_* with their symbol entries in one change if the maintainer agrees.
- Unmatched users: func_00145810 (phase 2, 1976 B) and func_00146328 (draw, 1052 B, VU0 temporaries) can now be written against the header.

## func_00145810 (held draft progress/held/00145810_nm.c, batch 182)
- cIDBaseScreen.h: `extern const float D_0041E840[4][4];` (retail data is four r,g,b,a tints; [0] listed row, [1] picked row). When it merges, 00145460.c reads `D_0041E840[0][k]`.
- cIDBase.h: `void cIDBase_restartAnim(cIDBaseObj *self);` (002ABBE8 resets the animation, then sets `playing` at 0x1C). Local declarations to drop: 0013e010.c (`void *`, called with a char-pointer sum), 00143be8.c (`void *self`), 001627d8.c (K&R).
- The draft reads `src->colorBase.word`, so it needs the held `cIDColor colorBase` change in cIDBaseSrc.

## cIDBase prototypes and cIDManager globals (batch 182, merges at checkpoint 183)
- Merge progress/held/inc/godhand/cIDBase.h, cIDManager.h and cIDBaseScreen.h. The merge also removes the stray comment in include/godhand/cIDBase.h ("Refresh one entry...; the third argument is a 16-bit mode.") that has no prototype under it; the held copy puts func_002AC9B8's prototype there.
- func_002ACF30 (cIDManager buffer free, held draft) needs `func_002ACF30 = 0x002ACF30; // type:func` added to symbol_addrs (not there yet) and goes into src/cod/002ace48.c after cIDManager_allocBufRun if it matches.
- Still declaring cIDBase methods locally without including cIDBase.h: 82 files (list: `rg -l 'extern .*cIDBase_' src | xargs rg -L 'godhand/cIDBase.h'`). Take them by subsystem: id screens 0013*/0014*, casino, coliseum 001e*/001f*, menus 0016*.
- D_003C2384 is still declared in about 37 places with 7 types (int *, char **, void **, void *, SlotUiHost/PokerHost/IdPickHost/ColiseumHost **). The host views are cIDManager views whose 0x88/0x8C words are pair[17]; they should become cIDManager.h field reads.
- Old -Wall warnings in the batch 182 files (none new), for batch 183:
  - func_00161500 (defined `int (int, int)` in 0014ea28.c) is called without a prototype from 0015a040.c, 001616a8.c, 00166638.c, 001673d0.c, 00167fa8.c (and 001627d8.c) with object pointers; its definition should take the object and its table pointer, then a prototype in a header.
  - func_001BBF68 in 00166638.c and 001673d0.c: implicit on purpose (0017d488.c / 001816e8.c comment: an implicit int declaration keeps retail's jal slot store). Ask before touching.
  - 00126770.c: cActionButtonUnit_setExit, cSnd_SeStop (cSnd.h has it; the caller passes raw ints `s0`/`s1`), func_002AF218 and cMessCommon_getCodeSize (cMessDrawFontCode.h has both; cMessCommon_getCodeSize is defined `(unsigned int)` but the header says `(unsigned short)` and 00126820.c says `(int)`). These functions are raw-offset code merged into the file; they need typing first.
  - 00126820.c: cMessage_releaseWin (declared in two .c files, no header), func_002AF218.
  - 0012cc70.c: func_001F2428 (coliseum code with a `char *s0` alias and a `buf[0x10]` placeholder) calls ColiseumBattle_CountLiveEnemies without a prototype; ColiseumBattle.h should declare it (defined `(ColiseumBattle *self)` in 001ef8b8.c, declared `void *`/`ArenaEm *` in 001f20f8.c, 0018f488.c, 0010a2c8.c).
  - 0013d698.c: cEmSetParam_updateSetDataVital (defined in 00294b60.c, no header). 0015a040.c: cCollisionShape_construct (defined in 00144b50.c on a local ShapeObj; 001f60d8.c declares it on PoolObj).
  - 002ab2a0.c: func_002AED40 (cMessage window lookup; declared with `int` and `unsigned short` messNo in three files) and a pointer-from-integer assignment.
  - 0013ed28.c: POKER_UI defined twice. 00166638.c/001673d0.c: unused `rec`. `might be used uninitialized` in 00138358.c, 0013d698.c, 0013ed28.c, 001616a8.c, 0015a040.c (loop-carried; check each against retail before changing).

## id object head, arenas, disc reads (batch 183, merged at checkpoint 184)
- Remaining callers of the cIDObj methods with local declarations (`void *`, `int`, K&R), to type on the head or a derived record: ClearFields_1614D0 in 00167f70.c (func_00167F70 also writes 0x90, which 00167fa8.c's IdDispObj16 names unk90), 00164ef8.c (0x298), 00161688.c (its header comment is tooling text, "LANE K3, wave 18 ...": rewrite it when the file is touched), 0016ee10.c (func_0016C238, func_001627A0, func_00168528); func_00161590 / Obj0000_Set_D_007474A0_Fields_5D8_5E0 in 00166730.c (ResetObjAndReleaseIdsA/B: manager slot 8, displays at 0xE0/0xC0, `int a0`), 0016c678.c, 001689e8.c, 00168080.c, 00147bb0.c (three resets); func_00161500 / Obj0000_Set_Fields_68_6C in 001627d8.c (raw `s1` offsets, K&R declaration).
- Renaming the five cIDObj methods (cIDObj_clear, cIDObj_load, cIDObj_release, cIDObj_saveFlags, cIDObj_restoreFlags) needs their symbol entries and every asm reference changed together; not done.
- cIDManager_getLocalFileName (002acfa8.c) has `void *` parameters and `s1`/`s2` copies of them; 24 callers. Type it `(cIDManager *self, char *dst, char *name, signed char lang)` with its callers.
- cIDManager.h declares memset (func_003A52F0) a second time; criStm.h owns it. Drop it from cIDManager.h once its includers that use memset include criStm.h.
- EnsureInitThenForward_2A9538_30EE08 (the arena allocator: size, alignment, heap) is declared locally with an `int` heap in 00312e88.c (passes `(int)&D_00754C20`), 00313ad0.c, 001bfb80.c, and with `struct HeapArena *` in system/cDvd.c and 00200df8.c. Prototype for heapArena.h once those callers drop the casts.
- Arena_init: 001bfb80.c declares it `(void *, void *, int, int)` and passes D_00754C20 by value (its own declaration of that global disagrees with heapArena.h).
- cDvd_ReadAlloc callers with local declarations that do not include cDvd.h: 00114e28.c and casino/cCockItem.c (K&R), 002d0220.c, 002ae4a8.c, casino/cCockBossBar.c, cCockTutorial.c, cCockLastBossBar.c, 001b9030.c, 00296458.c. cDvd_ReadAllocSized: 0031cc48.c (`void *` parameters); a prototype for cDvd.h with it.
- func_0030A2E0 (matrix product) is declared locally in 0015af30.c, 00153808.c, 0014a038.c (float *), 0030aa40.c; sceVu0.h now has it. MtxCopy is declared K&R `int MtxCopy()` in 001aa188.c, 00173ec0.c, 0019ca58.c, 001a13e8.c; mtx.h has it.
- 0014a038.c does not compile against the held cGameObj.h overlay (cGameObj_SetTgtTurn conflicts): fix before cGameObj.h merges.
- Batch 184 (sub-screen menu): cSubScrMenu.h (new, .gitignore line) is the 11cSubScrMenu status screen; its 0x2A0..0x2A4 names come from func_00165638 (stageSel, stageShown, flags, wait, stageNum), and it carries the stage records (cSubScrMenuStage, D_0041F718) and the FileHolder_reload/func_001661A0 prototypes. fileHolder.h is a third view of the same memory and nothing includes it: delete it and its .gitignore line. cIDBase.h gains the inline cIDBase_play (restart + playing = 1); cCockItem.c and 00146878.c write the same pair on raw offsets and should use it once typed. cHeatSys.h gains cHeatSys_GetHeatRatio and cHeatSys_UpdateHeatLv prototypes. config/symbol_addrs.txt types D_0041F718 as a 0x1C-byte asciz; it is the 0x18 x 0x24 stage table (left as is: the symbol type drives splat's data output). cHeap_free has four disagreeing local declarations (001a4430, 00144b50, 002be4e8, 001496c0, 00166540) and no C definition: give it one prototype once its signature is read from retail.

## options panels (batch 185, merges at checkpoint 186)
- New include/godhand/cSubScrOption.h (needs `!include/godhand/cSubScrOption.h` in .gitignore after cSubScrMenu.h): cSubScrOption (14cSubScrOption, 0x134: ent[0x18] at 0x80, second display at 0xE0, row/answer at 0x130) and cSubScrOptionT (the variant, ent[0x10] at 0x80, second display at 0xC0, row/answer at 0x110), their prototypes, and `extern unsigned char D_003BD9E8;` (cSubScrOption's fade step).
- padWork.h: D_005E8140 becomes `unsigned char[]` and gains PAD_WORK_VIBRATION (0x4B8). Other declarations of the same word disagree: char[] in 001a4430.c, 0030b298.c, 002bdc00.c, 00126918.c; int in 0012c348.c; 001004c8.c names 0x5E85F8 D_005E85F8 (a second name for the byte; splat gives it its own bss label).
- D_003BD9E9: cSubScrOptionT's fade step. symbol_addrs has nothing at 0x3BD9E8/0x3BD9E9 (the data is one `.word` in 2BBF80.data.s). Adding `D_003BD9E9` would split that word; only worth doing when func_00167518 matches.
- SetGlobalToggle_375700 (void (int mode)) is declared locally in 00166bb8.c, 00167908.c, 001672f0.c, 00167eb0.c. A seqNode.h prototype first needs 00137aa0.c's seven implicit callees fixed (func_0032BA30 in the CRI range, func_00380E10, func_00381D38 whose definition takes 2 arguments while callers pass 3, UpdateChildAndFreeSoundHandle, func_00385A20, func_003A52F0 via criStm.h, MtxInitTransVec), and 001f9e68.c's include placed before its use.
- classFADE_start is declared locally with disagreeing types in about 15 files (`rg -l 'classFADE_start' src | xargs rg -L 'classFADE.h'`); classFADE.h owns it.

## item test (batch 186)
- MERGED at checkpoint 187: cGameObj.h (held overlay): `long func_001B8030(cGameObj *obj);` (the item id range test; it returns cGameObj_idInRange's long flag as is). Merges with held 001b8030.c (new unit: compile_units, carved_funcs, .gitignore line, add `func_001B8030 = 0x001B8030; // type:func` to symbol_addrs.txt in address order) and held 0013cf20.c (local extern dropped, cast at the call).
- MERGED at checkpoint 187: cSnd.h (held overlay): `int cSnd_IsEnemyAlive(cSnd *self, int kind);`. Merges with held 002d0c10.c (new unit; symbol entry exists; delete drafts/cod/002d0c10.c). 002cf310.c called it with no prototype.
- cOmDoor.h (held overlay): cObjCollision (the door's collision object, contact list touch[8] at 0x34, touchNum 0x54), and cOmDoor gains touchedNum (0x630), toucher (0x634); collision becomes `cObjCollision *`. Every unit including cOmDoor.h still matches (001bd120, comdoor_releaseobjcollision, 001678b8, 001bd178, 001bcfb0). Only drafts/cod/001bd430.c uses the new fields so far: merge it with the first matched unit that needs them.

## Batch 187 (enemies)
- cOmWeapon.h (new held overlay): prototypes of the weapon state setters defined in src/cod/001d00.c, `void Obj1D00_SetState6_Variant6_a1(cOmBase *self, int arg)`, `Obj1D00_SetState_6_2_a1`, `Obj1D00_SetState_6_C_a1`, `Obj1D00_SetState_6_E_a1` (same signature). 001d00.c should include cOmWeapon.h's prototypes (it already includes the header). 0012e670.c declares Obj1D00_SetState_6_E_a1 locally as `(void *, int)`: drop it when the overlay merges. Held 00233dd8.c passes `&self->fx0->base`.
- cEm00.h: the held overlay types `CheckSlotsShort2FEAndSetByte1864_262A10(cEm00 *self)`, but its definition in 0014a2b0.c takes `char *a0` (raw offsets 0x670..0x688 and 0x1864). At the merge, retype the definition to `cEm00 *self` (include cEm00.h there, cast to `char *` for the 0x670.. reads until those are typed, or read the cDamageTake pointers by name) and recheck 0014a2b0.c.
- func_0026B600 (held progress/held/0026b600.c, MATCH): cEm00.h's `void func_0026B600(void *self)` becomes `(cEm00 *self)`; drop the local `extern void func_0026B600(void *a0)` in src/cod/002439a0.c. New `#define EM_NO_WEAPON_HOLDER 0x211` in cEm00.h (held overlay has it); remove the two local copies in src/cod/001169d8.c and src/cod/001b1860.c. Still blocked on the CreateObj definition (00306200.c `int CreateObj(int a0)` vs player.h `cGameObj *CreateObj(int kind, int id)`), already answered 2026-10-24.
- func_0027CB58 registered (src/cod/0027cb58.c), no header change. The old note about adding `float turn` at 0x15D4 is obsolete: cEm00.h has `partYaw` there.
- func_0026AB20 / func_0028D138 (held, MATCH, rebuilt): new `CEM00_WEAPON_GRIP(self, kind, left, pos, rot, hand)` statement macro in cEm00.h (held overlay), the grip pick both share; an inline function adds 4-5 instructions in each, so it stays a macro (its comment says so). cEm00.h: `unk734` becomes `struct cOmWeapon *` (nobody on main reads it; answered 2026-10-24), split `unk1624[0x20]` into `unk1624[0x10]`, `struct cOmWeapon *unk1634`, `unk1638[0xC]`, and `unk1648[0x8]` into `struct cOmWeapon *unk1648` + `unk164C[0x4]`; `func_0028D138(char *, char *, int)` becomes `(cEm00 *self, struct cOmWeapon *weapon, int kind)`; add `void func_0026AB20(cEm00 *self, struct cOmWeapon *weapon, int kind);` and `void Obj1D00_ClearState_8(cOmBase *self);` (definition in 001d00.c; drop the `(char *)` local in 0027b810.c). Callers to fix at the merge: src/cod/00102de8.c (local `(void *, char *, int)`) and src/cod/002349f8.c (local `(void *, int, int)`, passes an int `h`) for func_0026AB20.
- func_002F4290: .review/held/002f4290_ckpt.c still matches (raw offsets, private cNodeDrawState copy). To register: add an `EspSlot` record (0x400 bytes, the slots at D_0061B7C0) to a header with flags 0x104, group 0x23A, subGroup 0x23C, model 0x2B0, modelNo 0x2B4, effect byte 0x2DC, effect size 0x2E0 (001855a8.c and 001a7940.c can drop their ESP_SLOT_* offset macros for it); use cObjBase.h's cEffectParam and cEffectParam_init; settle SetEffect, cModel_setupModel, func_00306C78, ReleaseObj and CreateObj signatures first.
- cEm00.h: `struct cGameObj *catchPl` at 0x694 (split unk67C[0x1C] into unk67C[0x18] + catchPl): the player the enemy holds during a catch (func_001191A0; the raw-offset siblings 00111210.c, 0011a060.c, 00119750.c, 00118b68.c, 0010c930.c, 00119bf0.c, 0011baf8.c, 0011de30.c, 0011da30.c, 0011f438.c read it as `s1 + 0x694`). `cVec vel` at 0x550 (was unk550[0x10]), as cGameObj.vel.
- cVec.h: CVEC_PUT(dp, v), `*dp = v` from a named vector into one reached through a pointer, the pointer read once. CVEC_ASSIGN (s bound, d named) and CVEC_PUT (d bound, s named) are the two directions gcc's inliner leaves when one side of operator= is a local's address. CVEC_SET_ADD(d, a, b), `d = *a + *b` in CVEC_SET_MUL's shape, finishing with CVEC_PUT(&d, ret_) (retail reads the destination pointer once, after the add). Both are used by func_001191A0 (held MATCH).
- cVec.h: CVEC_APPLY(m, a) (m * *a into ret_, CVEC_SUB's role for the matrix product). Only a draft uses it so far (0011f810_nm.c); merge only if a function using it matches. (CVEC_INIT_ADD is on work already, from the SphereTriangle handoff, with b unbound.)
- pl00.h: `float unk76C` at 0x76C, the scale an enemy catch multiplies its damage by (0011e1e0, 0011e748, 0011f810, and the raw `s0 + 0x76C` reads in 00102150.c, 0010fe18.c, 00111210.c, 0011baf8.c, 0011bf20.c, 0011c348.c).
- held cCollisionSolid.h overlay: include/ gained `void func_00135348(cVec *out, cVec *p, cVec *a, cVec *b, cVec *c);` from the SphereTriangle handoff (batch 187); rebase the overlay on include/ before the checkpoint merge.

## func_00124540 (batch 188, held/00124540_nm.c)

- cEmManage.h: func_00291010 takes its floats before `skip`, `kind` and `flag`: `struct cGameObj *func_00291010(cEmManage *self, cVec *pos, float rotY, float range, float angle, struct cGameObj *skip, int kind, int flag);`. The registers are the same either way under the EABI (separate int and float sequences); only the order the arguments are evaluated in changes. func_00124540 loads range and angle before skip/kind/flag in all 24 of its calls: with the old order it is 57 instructions off, with this order 6. The other callers (held/002873b8.c MATCH; src 0014b640.c, 00286aa8.c, 00101eb8.c MATCH; 00285f78.c and 002412a8.c fail standalone identically in both orders) compile the same in both orders. held/002873b8.c and the held cEmManage.h overlay already use it. At the checkpoint: replace the include/ prototype, reorder the five src callers' calls when their local externs are dropped (00101eb8.c's local order a2, a3, floats, t0 goes too), and tell the NM closer that drafts/cod/00291010.c's definition and held/002923e8_nm.c take the same order.
- cEmManage.h: new `struct cGameObj *cEmManage_GetTargetNear(cEmManage *self, cVec *pos, float rotY, float range, float angle, struct cGameObj *skip, int mode);` (0x290A08, no C definition: a1 pos, a2 skipped enemy, a3 compared with 1 and 2, f12..f14, returns the enemy or 0). Same float-first evidence as func_00291010.
- pl00.h: `int unk5D8; /* 0x5D8 4 limits the catch search to GetTargetNear */` split out of unk5AC (0010c300.c reads the same word as `*(int *)(s0 + 0x5D8) != 4`).
- pl00.h: `int func_00124540(pl00 *self, int kind);` returns 1 when unk640 is set. 0010ee80.c, 0010ebf8.c, 0010e5b8.c and 00102a80.c declare it `void (void *, int)` locally and ignore the result; drop those for the header prototype and rebuild.
- func_00124C30 is defined `void func_00124C30(char *s1, int flag)` in src/cod/00124c30.c; the draft declares it so and casts. Retype the definition to `pl00 *self` and give it a pl00.h prototype at the checkpoint, if 00124c30.c still matches.

## func_0010A438 (batch 188, held/0010a438_nm.c)

- pl00.h: `pl00Hit hit[5]` at 0x5B0 (a union of the volume's `cDamageGive *give` and `cDamageUnit *unit` views, then `int node`, the id cDamageUnit_AddDamageCollSphere returned; 00101eb8.c stores it to 0x5B4), and 0x1670..0x1682 named (unk1670/unk1674 hit kinds, unk1678/unk167C, unk1680/unk1682 shorts), as the two Obj0000_Set_Fields_* setters in 000000.c write them. The union stands for the C++ base conversion (cDamageGive is a cDamageUnit: both have nodes at 0x3C). Ask the maintainer whether he prefers it to casts at the ~60 calls, or a cDamageGive.h that starts with a `cDamageUnit unit;` member.
- cDamageUnit.h: `void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset);` (definition in src/cod/battle/cDamageUnit.c). cOmHitVolumeSetup.h's local `extern void cDamageUnit_SetDamageCollActive(void *unit, int on);` conflicts with the held cDamageUnit.h prototype; drop it when the header prototype moves to include/.
- cDamageGive.h: `void cDamageGive_SetDmgGiveHitVecDir(cDamageGive *self, cVec *dir);` (definition in 001fd338.c; 001b6a30.c declares it `(int, void *)` locally).
- cDamageGive.h: the inline `cDamageGive_setParams(cDamageGive *self, short a, int b)` (stores 0x44, then 0x40) from the draft, once a function that uses it matches; retail evaluates both arguments before the stores, which the inline function reproduces (separate statements reload the volume pointer between the stores).
- D_00747B00 is a cVec (a fixed hit vector; past GameWork's 0x620 bytes). 00129430.c, 0015a040.c and 00171020.c declare it char[]/int[]; one header extern as `cVec` at the checkpoint.
- compile_units: the function needs `as: sn` (or fp_hazard_rules mtc1) for the nop after `mtc1 $s3, $f0` before `cvt.s.w`; record the reason with the unit when it matches.

## func_00195068 (batch 189, held NM progress/held/00195068_nm.c)

- cOmBreakObj: 00194558.c has a local view (0x604 give, 0x608 trigger, 0xAF4 flash); func_00195068 adds 0x630 `cOmBreakPiece piece[9]`, 0xAF0 `short timer` (00194d10.c writes it raw), 0xB20 `int se`. One header (cOmBreak.h) for both views, plus 00194d10.c.
- cOmBreakPiece (0x60): pos 0x00, rot 0x10, vel 0x20, spin 0x30, scale 0x40, `float *mtx` 0x50, `unsigned char active` 0x54 (GetField_54_173900 / Obj0000_Set_Byte_54), `float gravity` 0x58. This is the untyped 0x60-byte slot objField.h describes; 001aa188.c, 00173ec0.c, 0019ca58.c and 00175220.c walk the same records through raw offsets. It belongs in objField.h.
- mtx.h (new declarations): `void MtxInitRotVec(float *mtx, cVec *rot, unsigned char order)` (retail masks a2 with 0xFF), `void MtxMulScaleVec(float *dst, float *src, cVec *scale)`, `void CopyVec3ToField30_147C40(float *mtx, cVec *pos)` (writes the translation row). About 30 files declare each locally with void* parameters.

## func_002937C0 (batch 189, held NM progress/held/002937c0_nm.c)

- cEm00.h: `int func_00273EB8(cEm00 *self);` (1 once unk1720 has run down to 0; the sibling of func_00273EE0). Declared locally in the held file.
- mtx.h: `void MtxInitRotY(float *mtx, float angle);` (0013da98.c declares it `(void *)` and drops the float; 00275888.c has `(void *, float)`).
- cEmManage.specialEm holds cEmActor *, but the pairing code reads cEm00 fields (hitFlash, mode, moveFlags, unk580, foe, unk1720) and casts. If cEmActor stays a view of cEm00, consider typing specialEm as `struct cEm00 *` (ask the maintainer).
- as sn reason: retail puts the mtc1 hazard nop on the switch's join label (all four cases branch to it); ee-as with fp_hazard_rules mtc1 doesn't pad across the label.
- Tramp_001F7DF8_00101E28: the monolith definition (000000.c) is `void (void)` with a `do { capVu0Length(); } while (0)` body, while sceVu0.h and every caller use `float (void *v)` and retail forwards $a0 and returns capVu0Length's $f0. Correct the definition to `float Tramp_001F7DF8_00101E28(void *v) { return capVu0Length(v); }` (including sceVu0.h) once capVu0Length has a prototype it can see; check 000000.o is unchanged.

## cVec.h: CVEC_ASSIGN_VEC (func_002937C0, batch 189)
- `CVEC_ASSIGN_VEC(d, s)`: operator= with `this` bound (`cVec *d_ = &(d)`), compared against `&(s)` for a named vector s, then copied by name. Retail compares this first (`beq this, &s`) and loads s straight off the stack; CVEC_ASSIGN binds the source pointer instead and gives the reversed compare and pointer loads (func_002937C0 goes from 52 to 43 differing insns with it).
- Steering for the PR: d_ exists because operator= reads through `this`.

## cVec.h: CVEC_SET_UNIT (func_001C6CB8, batch 189)
- `CVEC_SET_UNIT(d, a)`: d = a->unit(), built in tmp_ by cVec_unitOf (sceVu0.h), then the return slot and the operator= copy. It reads tmp_ by address, without a t_ pointer: binding t_ before the body forms &tmp_ before the Tramp call, retail forms it after (277 to 150 differing insns).

## cOmTwoVol.h (new, func_001B1070, batch 189)
- Held overlay progress/held/inc/godhand/cOmTwoVol.h: cOmTwoVol from 001b0de8.c moved to a header, with 0x640 `cVec vel`, 0x650 `cVec spin` (001b0de8's field650..658), 0x666 `bounced`. Merge with 001b0d30.c's cGiveOwner per decisions_needed "cOmTwoVol"; both TUs include it and rebuild byte-identical.
- Prototypes func_001B1070 declares locally until they get a header: `void func_001B19E0(void *self, float m[4][4], cObjSimpleVec3 *n);` (src/cod/001b19e0.c), `void InitDamageCollPair_1B18B8(unsigned char *a0);` (src/cod/0014fe08.c), KillEffect `(int, int, int)` as src/cod/00306200.c defines it.

## Inlined 4x4 matrix multiply (func_0014D0E8, batch 190)
- func_0014D0E8 inlines sceVu0MulMatrix four times (8 lqc2, vmulax/vmadday/vmaddaz/vmaddw per row, 4 sqc2). It can be written from existing vu0.h macros (VU0_LQC2, VU0_VMULAX_XYZW, VU0_VMADDAY_XYZW, VU0_VMADDAZ_XYZW, VU0_VMADDW_XYZW, VU0_SQC2), but four copies in one function need one shared form (a statement macro in sceVu0.h, `SCEVU0_MUL_MATRIX(dst, a, b)`), not new vu0.h entries. Not written: the function is skipped for its div.s pads (see batch_log).
- Its tail-packet matrices (tailPacket[parity] + 0x10 view, 0x50, 0x90 unit, 0x110) need a cModel.h record before anything there is written.

## cObjBase.h: moveMotion fields and cObjBase_childAt (batch 190)

- `unk350`, `unk370`, `unk380`, `unk390` become `cVec` (moveMotion reads them as vectors: unk350 is quat a frame ago, unk390 = unk370 - unk380, unk380 = unk370 a frame ago). Only `src/cod/00312e88.c` has its own local `char unk350[0x10]`, in an unrelated record.
- `0x43C float motionLen` (moveMotion divides motionStart by it for the blend-in), `0x444 float motionSpeed` (times motionRate and the game time scale gives the frame step), `char unk448[0x4]`.
- `cObjBase_childAt(cObjBase *, int *frame, int idx)`: cOmBase_childAt's idiom on the cObjBase model fields (partNum 0x2B4, children 0x278); cObjBase is cOmBase's base, so the cOmBase helper would need a downcast.
- `func_003A50B4` (memcmp-shaped, 4 callers with three different local prototypes: 0031f4e0.c, 00360878.c, 0034a5e0.c) wants one prototype `int func_003A50B4(const void *a, const void *b, int n);` in a shared header.

## Slot1.h and MarkPanel.h: the reel's rows and line symbols (batch 190)

- Slot1Reel 0xC4..0x103 splits into `int unkC4[3]` (0xC4, per row; func_001E0CA8 sets it to payMode when the reel is stopped), `int lineSym[8]` (0xD0, per line: the symbol the other two reels already show on it), `char unkF0[4]`, `int sym[3]` (0xF4, symbol on the top, middle, bottom row), `char unk100[4]`; stopMode stays at 0x104.
- Slot1.endFlag becomes `int` (already listed above; func_001E0CA8 clears bits 0x20/0x40/0x80 with addiu -0x21/-0x41/-0x81).
- MarkPanel.h gets `void MarkPanel_setMark(MarkPanel *self, unsigned short mark, int show, int startLit);` (retail masks a1 with 0xFFFF). Callers on main: 001e0310.c declares it `(char *, int, int, int)`; drafts/cod/001dfde0.c already uses the MarkPanel form. Slot1 is passed as a MarkPanel (layer 0x448, markFlag 0x49C sit in Slot1's padding): a second view of one record, to resolve when Slot1.h names 0x448/0x49C.

## cEm00.h: Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8 (batch 190)

- `void Obj0000_Set_Bytes_2F4_2F7_2F5_2F6_27DCB8(void *obj, int stepArg);` (retail: stores a1 to 0x2F7, 9 to 0x2F5, 0 to 0x2F4 and 0x2F6; no return value). Used by the held func_00256898 draft.
- func_00256898 stores `irand() % 3` into cEm00 0x600 (`timer`, a float elsewhere) as a raw word; the draft keeps it behind `EM_TIMER_WORD`. If a sibling shows 0x600 is a union of a float and an int, give the header the union instead.
- func_00256898 uses `home.y` (0x5C4) as the launch's vertical speed.
- include/godhand/cObj21C0.h declares `extern void cGameObj(void *self);`, which clashes with the `cGameObj` typedef when both headers are in one context (m2c_draft's full include context fails on it). Rename that prototype to the function's real symbol at the checkpoint.

## hudPanel.h: HudPanel moves out of 00141ce8.c (batch 190)

- New header `include/godhand/hudPanel.h` (held copy in progress/held/inc/godhand/hudPanel.h): the HudPanel record that src/cod/00141ce8.c defines locally, plus HUD_GOD_ITEM_NUM, HUD_LEVEL_ENT, IDENT_FLAG_400/1000 from that file.
- Fields added from func_00142060: flags (was unk090) with HUD_F_*, vital 0x094, reelItem[6] 0x14C (unk148 split), unk1E4 (cIDBaseEnt *, split from unk1D8), heatAlpha 0x26E, heatSe 0x270.
- At the checkpoint: 00141ce8.c includes hudPanel.h instead of its local copy (rename unk090 to flags there); check that it still matches, as it stays in its TU.
- func_00142060's static record at D_003BD6EC is {float shake; uchar flashTimer; uchar flashDown;} (retail addresses the bytes as D_003BD6F0 and D_003BD6F0 + 1). New prototypes: `int cHeatSys_GetHeatLv(cHeatSys *self);` and `float func_002A9D28(cHeatSys *self);` (returns floor) belong in cHeatSys.h.

## cDamageGive.h and cEm00.h: attack volumes (batch 191)

- cDamageGive.h gets `cDamageGiveVol` ({ union { cDamageGive *give; cDamageUnit *unit; } u; int node; }, a damage volume and its model node) and the inline `cDamageGive_setParams(self, short a, int b)` (stores unk40 then unk44 without reloading the pointer, as retail does in func_00260B30 and the 0010a438 draft). The draft 0010a438_nm.c drops its local copy of the inline.
- pl00.h: the local `pl00Hit` typedef goes; `hit[5]` at 0x5B0 becomes `cDamageGiveVol hit[5]`, and pl00.h includes cDamageGive.h.
- cEm00.h includes cDamageGive.h and names: 0x674 `int atkHitNode`, 0x67C `int unk678Node`, 0x680 `cDamageGiveVol atkVol[2]`, 0x690 pad; 0x76C `float atkTimeRate` (func_00260B30 scales the attack time by it).
- cEm00.h adds `cEmAtkParam` (0x14: kind, time, dmgKind, unk0C, short unk10, size check) and `cEmAtk` (cEm00 followed by `cEmAtkParam atk[2]` at 0x1870), the derived record func_00260B30 reads past 0x5E0.
- `void ForwardEventToList_1FD820(void *a0, void *a1);` needs a home header (func_00260B30 declares it locally for now).

## cOmWeapon.h: the thrower and the homing spin (batch 191)

- `throwArg` (0x670) becomes `cOmBase *throwArg` (the thrower): setThrow's only caller, src/cod/0026bdd0.c, passes `(int)self`, and func_001CE068 reads `throwArg->actionId` (0x564). Pending the decisions_needed question below; 001ad818.c's setThrow definitions and 0026bdd0.c's prototype change with it.
- `unk678[0x18]` splits: `float unk678` (0x678, a per-throw spin step of +/-0.0035), `float unk67C` (0x67C, the spin angle of a homing throw), `char unk680[0x10]`.

## cOmSub.h: the falling record (batch 191)

- `cVec *target` at 0x40 (ent's 0xD0 or 0xF0 vector, chosen in cOmSub.c), `cVec vel` at 0x50, `cVec accel` at 0xF0.
- `part[]` retyped `struct cGameObj *` (the fall step reads pos, actorId and the vtable through it; no C on main names the field).
- Flag bits COMSUB_HOLD 0x2 (the object is not moved) and COMSUB_LAND 0x10 (a fall stops at the start height).
- `cOmSubFall { cOmSub base; float bounce at 0x154; }`.
- `extern void func_001C7310(cOmSub *self);` — 001c6a90.c and object/cOmSub.c declare it locally (void * / cOmSub *); move both to the header at the checkpoint.

## Batch 191: joint attack setup (func_002937C0, func_00293C40)

- mtx.h: add `void MtxInitRotY(float *mtx, float angle);` (held overlay progress/held/inc/godhand/mtx.h). Drop the local prototypes in 00100378.c, 00115030.c, 001299f0.c, 00138358.c, 0013da98.c, 00275888.c when they can take the header without changing their bytes.
- cEm00.h: `int func_00273EB8(cEm00 *self);` (1 once unk1720 has run down to 0). Retype src/cod/00273eb8.c in place from `void *a0` to `cEm00 *self` and include cEm00.h; keep the TU.
- cVec.h: `CVEC_ADD(a, b)` (operator+ into ret_ for a caller that reads ret_), same shape as CVEC_SUB. First use func_00293C40. 001f85d0_nm.c's local macro was renamed CVEC_ADD_INTO.
- Registration: 002937c0.c (as sn, extern_jtbl D_0044A7D0), 00293c40.c (extern_jtbl D_0044A7F0 D_0044A810, no `as` override: it matches with the default assembler). Reason for 002937c0's `as = sn`: with the default assembler the function is 287 words against retail's 288 and the rest shifts. Check `-Wall` under cygnus-2.96 for both at registration.
- cEm00.h (batch 191, func_00242B68): `short unk56C` (0x56C, the floater's next spot), `float unk172C` (0x172C), `float unk1738` (0x1738, split from unk1734[0xC]), `int func_0026F328(cEm00 *self);` (0020fbb8.c declares it `void (void *)` locally; 001468b0.c `int (cEm00 *)`), `extern cVec D_00585040[7];` (00137cb8.c declares it `char []` and fills it through a local Vec4 view).
- cVec.h: `CVEC_UNIT(a)` (a->unit() into ret_, for a caller that copies ret_ on with cVec_copy3), same shape as CVEC_SUB/CVEC_ADD. First user func_00242B68 (held draft).

## Batch 192: collision grid segment test (func_00130700)

- `include/godhand/cGrid.h`: the probe fields after boxMax (dir 0xD0, from 0xE0, to 0xF0, hitPos 0x120, hitNormal 0x130, room 0x140, mask 0x174, exclude 0x178, hitCount 0x17C, hit 0x180, single 0x181, dist 0x184, best 0x188, hitFaces 0x18C, bodies 0x190), the `cCollFace` and `cCollBody` records with `CCOLLBODY_QUAD`/`CCOLLBODY_BOX`, and the corner order tables `D_0041D630[4]`, `D_0041D640[6][4]`. The cCollGrid record in drafts/cod/001321d8.c describes the same object from 0x64 on and should fold into cGrid at the same time (its dimX/dimZ at 0x64/0x68 conflict with cGrid.num[3] at 0x60: check which is right before merging).
- `include/godhand/sceVu0.h`: `void sceVu0Normalize(void *, void *)`, `float sceVu0InnerProduct(void *, void *)`, `void sceVu0OuterProduct(void *, void *, void *)`, the definitions' signatures (0030a370.c, 0030a348.c, 0030a328.c). The local externs in 00137cb8.c (declares sceVu0Normalize as float), 003033a8.c, 0030a978.c, 0030a8c8.c, 00157220.c, 00137e70.c then go; 00137cb8.c's float return must be checked against its bytes first.

## Batch 192: enemy walk toward the player (func_00211C08)

- cEm00.h: `char unk764[0x4]` becomes `float unk764` (0x764, tested above 0 to pick stepArg 1 before the close attack, phase 9).
- cEm00.h: `int func_0024BB68(cEm00 *self);`, `int func_0024BDA0(cEm00 *self);`, `int func_0026E7D8(cEm00 *self);` (each tested for nonzero at the end of the walk step). Check the definitions' signatures before moving them out of the held overlay.
- cOmBase.h (batch 193, func_001C9AF0): split `char unk56A[0x16]` into `short unk56A; /* 0x56A a second frame counter of the derived object (a dropped weapon's effect interval) */` and `char unk56C[0x14]`. The held overlay progress/held/inc/godhand/cOmBase.h carries it (a copy of include/godhand/cOmBase.h with only this split).
- LineObj (001bfb80.c local view, batch 193): its `owner` at 0xF0 is cOmBase.pos and the object is a cOmBase-derived weapon (func_001C9AF0 passes its cOmWeapon). Candidate: retype LineObj_checkWaterHit to take `cOmBase *` with the 0x490/0x688 words named in a header, if 001bfb80.c still matches; until then callers forward-declare `struct LineObj`.
- cObjSimple.h (batch 194, cObjSimple_MoveBust): include godhand/cOmBase.h; bustVel (0x2FB0), bustPos (0x2FD0), bustPrevPos (0x2FE0) become `cVec` (no .c file reads them as cObjSimpleVec); add `static __inline__ cObjSimpleChild *cObjSimple_childAt(cObjSimple *self, int *frame, int idx)`, the cOmBase_childAt idiom for the prop's child table (002b6fe8.c's COBJSIMPLE_RESET_* macros are the same idiom written out). The held overlay carries all three.
- cOmPiece (batch 194): the 0x60-byte loose-piece record (pos, rot, vel, rotVel, scale, float *mtx @0x50, active byte @0x54, gravity @0x58) is used by 001842b0_nm.c (cOl40, piece[20] at 0x670) and 001be198_nm.c (piece[8] at 0x600, one per child). One header type (cOmPiece in cOmBase.h or a new cOmPiece.h) once either matches.
- cGameObj.h cGameObjVt (batch 194, func_001BF5E0): name 0x78/0x7C `setRot(void *self, cVec *rot)` and 0x88/0x8C `cVec *getRot(void *self)` (unk78/unk88 padding split), and retype `lockOn` at 0x84 to return `cVec *` (0019b4d0.c and 00146f18.c already cast it to that). With the retype, src/cod/cgameobj_getlockonpos.c's `void (**new_var4)(void *)` must become `cVec *(**new_var4)(void *)` (-Wall: incompatible pointer assignment otherwise); retype it in place, it stays in its TU. Overlay: progress/held/inc/godhand/cGameObj.h.
- cVec.h (batch 194, func_001BF5E0): new operator `CVEC_SUB_LENGTH_SQ(len, a, b)`, `len = (*a - *b).lengthSq()`: binds a_, b_, then r_ = &ret_, subtracts through tmp_ into ret_ and passes r_ to capVu0LengthSq. The caller includes capVu0.h. Overlay: progress/held/inc/godhand/cVec.h.
- cOmShatter (batch 194): the breakable object of func_001C2DA0, func_001C3540 (held) and func_001C3090 (drafts/cod/001c3090.c) has damage-take 0x600, damage 0x604 (flash on break), piece array 0x608 (0x60 bytes each, the cOmPiece record), signed char piece count 0x60C (the draft names it `shattered`; both held users bound loops by it, so `pieceNum`), short timer 0x60E. One header type (cOmShatter) once one of them matches; ask the NM closer to rename `shattered` then.
- cOmBase.h cOmBase_childAtIdx (batch 194, func_00107C68): rewrite it on a new `cOmBase_idxInRange(idx, lo, hi)` inline called with lo = 0. With the literal 0 in the test gcc branches with bltz; retail (00107C68, 00175F38, 001C3540, 001BCD70) compares with slti/slt, which is what the parameter form gives. No registered unit uses cOmBase_childAtIdx; the held users are 0027a320_nm.c (stale: predates CVEC_TEMPS, needs `CVEC_TEMPS;`), 00175f38_nm.c (ratio 0.532 -> 0.536) and 00107c68_nm.c. Overlay: progress/held/inc/godhand/cOmBase.h.
- LinkObj (batch 195, func_002F5588): 001810a0.c has a local LinkObj (vt 0xF0, partner 0x114 typed LinkPartner with objFlags 0x250, flags 0x11C); 002f5588.c (held) needs rec 0x110 (LinkRec, signed char part at 0xBE), partner 0x114 and part 0x2B0. One header (linkObj.h) with partner typed cOmBase * (its 0x250 is cOmBase.objFlags); 001bfb80.c's LockOn_aimAtTarget/func_002F5588 prototypes take it.
- D_00747B00 (batch 195): a bss zero cVec (splat cut it into two 8-byte symbols, D_00747B00/D_00747B08; retail reads it as one quadword). Declared `char[]` in 001ad5c8.c and `int[]` in 00171020.c; declare it once as `extern cVec D_00747B00;` in cVec.h (or cOmBase.h) and drop the local externs (001ad5c8.c passes it where cOmSub_initMove3_y takes a vector).

## cOmPartBreak.h (new, batch 195)

- Overlay: progress/held/inc/godhand/cOmPartBreak.h. cOmPartBreakDebris, cOmPartBreak (moved out of 001a2e88_nm.c), cOmPartBreakRange and `extern cOmPartBreakRange D_00427040[];` (the child runs per piece kind; 001a2e88 used to read it as a desc with body at 4 and first/num at 0xA/0xB, which are runs 2 and 5), and `void func_001A3860(cOmPartBreak *self, unsigned int part, int kind);` (the definition shifts part with srl, so it is unsigned).
- Users: 001a2e88_nm.c, 001a3860_nm.c. Needs a `.gitignore` allowlist line when it lands.
- Also pending: cOmBase_setMeshDispFromLayer (`void (void *model, int layer, int show)`, defined in src/cod/object/cOmBase.c) and SetField380Bit2000ForTag_1B7300 (`void (void *model, int layer, int clear)`, src/cod/001b7300.c) are declared locally in 001799f8.c, 00185bd0.c (with `int a0`), 001c3540_nm.c, 001a3860_nm.c and drafts/cod/001ac370.c; they belong in cOmBase.h.

## cOmScripted.h, SysFlagWords, cTaskWork_exit, cCockGetPoint_setData (batch 195)

- New overlay progress/held/inc/godhand/cOmScripted.h: cOmScripted (seqState 0x604, rewarded 0x606), OMSCRIPTED_SEQ_DONE/RUN, `void func_001A6AF8(cOmScripted *self);`. src/cod/001a6a78.c should drop its local cOmScripted, OMSCRIPTED_SEQ_RUN and extern and include it (check it still matches).
- cOmBase.h overlay: `short unk2AC` at 0x2AC (from unk288[0x2C]); drafts/cod/001c2408.c's GOLD_KIND macro reads it.
- gameWork.h overlay: `extern void cTaskWork_exit(struct cTaskWork *task);` next to cTaskWork_sleep. Ten src files declare it locally with five different parameter types (void *, int, cTaskWork *); they should include the header.
- SysFlagWords (001496c0.c's local view of D_00747A78 with f80 at +8) is now needed by 001a6af8_nm.c too: move it to one header. The tree types D_00747A78 seven different ways (int, unsigned int, char[], int[], SysFlags, SysFlagWords, GAMEWORK_AT(flags5D8)); that needs a maintainer call, so only the two SysFlagWords users move for now.
- cCockGetPoint_setData: retype the empty definition in src/cod/casino/cCockGetPoint.c to `void cCockGetPoint_setData(void *self, cVec *pos, int point, short kind)` and give it a header (cCockGetPoint.h); users 001a6af8_nm.c and drafts/cod/001c2408.c (which declares `unsigned short point`; retail's callers pass the unmasked int).

## Batch 195: effect object model build (func_002F1B60)

- effModelObj.h: `int mode` (0x2DC) becomes `unsigned int mode` (retail tests `mode >= 3` with sltiu). Add `int func_002F1B60(EffModelObj *self);`; src/cod/002f1d58.c includes the header and calls `func_002F1B60((EffModelObj *)o)` (it has no prototype in scope now). Check 002f1d58's bytes after.
- EspDataBank.h: add `extern EspDataBank D_00741DC8;` (002f1b60.c declares it locally; 002f1d58.c declares it as `int`).
- `func_00306C78`, `espSys_getEffT32Addr`, `ReleaseObj` and `cModel_setupModel` have local externs in 002f1b60.c copied from their definitions (cModel_setupModel has no carve; four files declare it locally with differing parameter types). One header each: espSys.h for the first two, player.h for ReleaseObj, cModel.h (new) for cModel_setupModel.
- CreateObj: player.h declares `cGameObj *CreateObj(int kind, int id)`, its definition in 00306200.c is `int CreateObj(int a0)`. Callers pass 0xFFFF in $a1 (func_002F1B60 sets it in a delay slot), the definition doesn't read it. Fix the definition to `cGameObj *CreateObj(int kind, int id)` with "id is not read", check 00306200.c's bytes.

## Batch 195: cOl40 shake (func_00186398)

- New cOl40.h (overlay): cOl40Piece and cOl40 from held 001842b0_nm.c, plus shakePos 0xDF0, shakeRot 0xE00, shakeY/shakeRotX/shakeRotZ 0xE10..0xE18, shakePhase 0xE1C, OL40_SHAKE_PART, the func_00186398 prototype. src/cod/00186598.c (sets the amplitudes with raw offsets) can take the header: `void func_00186598(cOl40 *self, float strength)`, check its bytes; drafts/cod/001846d8.c's local extern then goes.
- cVec.h: new CVEC_ASSIGN_ARG(d, v) after CVEC_PUT. Steering for the PR: s_ exists only for the self-check and is bound before d_ (the other order swaps the two address computations).

## Batch 195: enemy held objects (func_0026A638, func_0026BBD0)

- cEm00.h: `char unk6E4[0x8]` becomes `struct cOm60 *held[2]` (0x6E4, made by func_0026A638). Prototypes `void func_0026A638(cEm00 *self, int no);` (was `void *`, int) and `void func_0026BBD0(cEm00 *self, struct cOmWeapon *w);`. Callers to update: 0022af90.c, 0022b358.c, 0022ace0.c (func_0026A638), 0022bd10.c (func_0026BBD0; func_0026AA30 returns the weapon as int there, check its definition first).
- func_001D0140 (001ad818.c, `void (cOmWeapon *self, cVec *pos, int arg)`) belongs in cOmWeapon.h; 0026bbd0.c has a local copy.

## Batch 195: bomb check (func_0012A108)

- cEm00.h: `char unk69C[0x18]` becomes unk69C[4], `int unk6A0` (0x6A0, nonzero skips func_0012A108's check), unk6A4[0x10].
- func_001B8720: the definition in 0012ca60.c is `int func_001B8720(char *a0)` and returns a cVec pointer (the layer object's or a0's 0xF0 pos); 0012a2e0.c declares it `cVec *func_001B8720(cEmActor *actor)`. Retype the definition to `cVec *func_001B8720(cGameObj *obj)`-style, put it in a header (cGameObj.h or cEmManage.h) and check 0012ca60.c's bytes.
- D_00754C58: ptrVec.h (main) declares `PtrVecRef D_00754C58`, the held cMc.h overlay `cMcObjList *D_00754C58`. One type: keep PtrVecRef and drop cMc.h's cMcObjList (its users read `D_00754C58.v->begin/end`).
- cOm60_ckParent (0013c618.c) and SetActionKickBomb (002dba00.c) need header prototypes (cOm60.h; a player action header with the other SetAction* functions).

## Batch 195: jump points (cSceAtManager_findJumpPoint)

- cSceAtManager.h: add cSceAtJumpPoint (0x14: landing x/y/z/heading 0x0..0x6, room 0x8, idx 0xA, unit x/y/z/heading 0xC..0x12) and cSceAtJumpPointTbl (num, ent[] at 4); 002c12c8.c's local Entry/Table become these. Prototypes for cSceAtManager_getUnitList/getNextUnit (`cSceAtUnit *`, the definitions take `void *` and return `void *`/`unsigned int`: retype them), func_002C1D68 (`cArea *out`), cSceAtManager_findJumpPoint (`int (cSceAtManager *self, cVec *pos, cVec *point, float *heading)`; 0012ca60.c and drafts/cod/0024bda0.c declare it locally).
- cArea.h: `int cArea_HitCheck_1F83E8(cArea *self, float *pt);` (002c2138.c declares it `(int *, void *)`).

## batch 196: cEm00.h unk480 and unk1758 (func_00275668)

- `char ik[0x48]` at 0x448 splits into `char ik[0x38]` and `cVec unk480` (0x480, normalized each frame by func_00275668; 1 - y is how far it tilts). The IK work may own this vector; `self->ik` callers pass the pointer only, so the split does not change their code.
- `unk1744[0x24]` splits into `unk1744[0x14]`, `float unk1758` (0x1758, eased amount child 0's anchor is lowered by), `unk175C[0xC]`.

## batch 196: cOmWeapon.h prototypes (func_002DDAB0)

- `int cOmWeapon_ckGetEnable(cOmWeapon *self);` (defined in src/cod/001d00.c) and `int func_001D0AE0(cOmWeapon *self);` (src/cod/001d0ae0.c, true while unk66C > 0) have no header prototype; add both to cOmWeapon.h, the definitions include it already.
- Finding for cGameObj.h: retail's range tests in func_00129CC8 and func_002DDAB0 compute `id >= lo` as a value (slti, xori 1, beqz). An idInRange whose body is `int ge = id >= lo; long in = 0; if (ge) in = id < hi; return in;` produces it. No matched function needs it yet; propose it with the first function that matches.

## batch 196: cObj21C0.h record fields (func_003132D0, draft)

- cObj21C0Ent gets its six vectors (0x00, 0x10, 0x30, 0x40, 0x50, 0x80) with a size check, and `tail` becomes `cVec unk2190` plus padding. Only for when a function using it matches; nothing in src uses the header now.

## batch 196: cGameObj constructor (cGameObj, held 002a7338.c)

- cGameObj.h: `struct cGameObj { ... };` then `#ifndef CGAMEOBJ_NO_TYPEDEF typedef struct cGameObj cGameObj; #endif` (the cObjBase.h/cModel.h pattern), and the header's prototypes and inlines write `struct cGameObj`. Fields: `int unk4D0` (0x4D0, 0xFFFF after construction), `int unk510` (0x510), `cVec unk580`, `cVec unk590` (these keep sizeof 0x5AC and go in at the checkpoint). `long name` (0x538) and `long modelHandle` (0x540) are ON HOLD: waiting on LucasPicoli (record layout question, decisions_needed.md); they are not in the overlay.
- Prototype `struct cGameObj *cGameObj(struct cGameObj *self);` in cGameObj.h. Callers to update: include/godhand/cObj21C0.h (`void cGameObj(void *)`), src/cod/00134650.c (local `void cGameObj(void *)`), and src/cod/00100280.c / src/cod/0012ac28.c, which call it with no prototype in scope (cPlBase and InitFields_1B6E90; check that including cGameObj.h there keeps both hashes; the return value is unused so the call code should not change).
- Prototype `struct cObjBase *cObjBase(struct cObjBase *self);` in cObjBase.h (definition in src/cod/00126770.c); callers 0014e598.c, 0013e380.c, 001030c8.c declare it `void (void *)` locally.
- ON HOLD (waiting on LucasPicoli): the 0x5B0 padding sweep. Taken back out of the overlays on 2026-10-26; do not apply it at the checkpoint. The constructor itself is not registered, so its prototype and caller fixes wait with it; the CGAMEOBJ_NO_TYPEDEF guard and `struct cGameObj` prototypes are only needed by the constructor's TU and wait too.

## batch 196: pathRec.h records and cArea_HitCheck (func_00137BB8, draft)

- pathRec.h: PathRec gets `cArea area` (0x00), `float holdScale` (0x30), `unsigned char priority` (0x3E), padding to 0x6C and a size check; PathHost gets `PathRec *recs` (0x00) and `unsigned int recNum` (0x0C); prototype `int func_00137BB8(PathHost *self, cVec *pos);` (drafts/cod/00137f38.c declares it the same way locally).
- cArea.h: `int cArea_HitCheck(cArea *self, float *pt, float scale);`. Its definition in src/cod/001dbd50.c is `int cArea_HitCheck(unsigned char *a0)` and calls func_001F85D0()/func_001F8810() with no arguments, but both callees read a0, a1 and f12 (func_001F85D0 scales the height band by f12). Correct the definition to pass (self, pt, scale) to typed prototypes of the two tests; the arguments are already in place, so the bytes should not change. Check that 001dbd50.c still matches.

## batch 196: delayed motion records (func_001EBC58 draft, NM closer's func_001EBB78 draft)

- MotionArgs (0x24: kind, delay, step, limitZ at 0x14) and DelayedMotion (0x40: obj, args at 0x08, flags at 0x30, bit 1 started, bit 3 tripped; five at owner + 0x5C) are written twice now (drafts/cod/001ebb78.c and progress/held/001ebc58_nm.c). They need one header once the owner object (the caller near 0x1EAB38, s1 with a word at 0x2A04) is identified.

## batch 196: func_00110B20 (held progress/held/00110b20.c, MATCH)

- Register at the checkpoint as src/cod/00110b20.c with `extern_jtbl D_0041C0A0` (retail's table; without it the build carries its own copy of the table) and a symbol entry `func_00110B20 = 0x00110B20; // type:func`.
- Needs: cObjBase.h overlay prototypes (cObjBase_addNullSpeed_Rotation, SetEffect), the CreateObj definition fix (src/cod/00306200.c to `cGameObj *CreateObj(int kind, int id)` including player.h).
- Local externs that want pl00.h at the checkpoint: func_00124540(pl00 *, int) returning int (its draft progress/held/00124540_nm.c), func_00123938 (int), func_0012AFE8(pl00 *, cOmWeapon *) (drafts/cod/0012afe8.c uses pl00ThrowView until 0x640 is named), func_0012AC98(pl00 *).
- MOTION_AT (file-local): the `*(int *)(data + off) + (int)data` motion address idiom that 00289610.c, 0010f4b8.c and others write by hand; a shared form in cGameObj.h (next to motionData) is the follow-up.

## batch 196: cOmPiece in objField.h (func_001B4A18 draft)

- New held overlay progress/held/inc/godhand/objField.h: `cOmPiece` (0x60: pos, rot, vel, spin, scale cVecs; `float *mtx` 0x50; `unsigned char active` 0x54; `float gravity` 0x58) with a size check; objField.h now includes cOmBase.h for cVec. This is the record pending_headers already calls cOmBreakPiece (00195068_nm.c) and cOmPiece (drafts/cod/001be498.c, 001842b0_nm.c, 001be198_nm.c); those drafts can drop their local copies for it. Merge only when one of its users matches.
- cOmBase.h names 0x24C `animRate` ("1.0 normal"); the breakable objects write their fade alpha (timer / 15) there, as cModel.tint.w is at the same offset. Ask before renaming (decisions_needed if a match depends on it).

## batch 196: cCoreSave block copies (func_002C02E8, skipped)

- func_002C02E8 (restore a checkpoint but keep the combo sets, skills, god reels, world toggles, paper count, state bits and the player's position/posA/rotation) copies cCoreSaveData.combo (0xD8 bytes), skill (0x80) and reelSlot (10 bytes) by value to the stack and back, with lq/sq loops and an ld + lhu pair. That is a struct assignment that knows the record is 16-byte aligned. With the current header (char/int arrays in an int-aligned cCoreSaveData) a wrapper-struct copy compiles to an alignment test plus ldl/ldr loops. To match it the header would need (a) cCoreSaveData 16-aligned and (b) the three blocks typed as structs (for example `cCoreSaveCombos combos` holding `combo[6]`), which renames fields main already has, so it needs the maintainer first. The function also reads D_00568240 as a flag word (lwu, bit 4), while ColiseumEmSelect.h types D_00568240 as ColiseumPick with unk00 padding there, and four src files declare it as int/short[]/unsigned int locally (one type per global).

## Checkpoint 197 merge (2026-10-27)

- Landed in include/: the field splits and names from the held overlays (cEm00, pl00, cModel, cObj21C0, cObjBase, cOmBase unk2AC/unk56A, cOmDoor, cOmSub, cOmWeapon, Slot1, pathRec, objField cOmPiece, menuCtl MenuRowEnt, cEmManage float-first func_00291010 and cEmManage_GetTargetNear, cOmScripted `rewarded` at 0x606), new cOl40.h, SetEffect in cObjBase.h, func_0026BBD0 in cEm00.h, func_001D0140 in cOmWeapon.h, func_002F1B60 in effModelObj.h, cDataManager_countReady/getReadyKind in cDataManager.h, and the object factory chain in cObj.h (func_0030FB70, func_0030FE68, func_0030FAC8, func_00312AB0, func_00312B00, func_0030FB20) with CreateObj's definition fixed to `cGameObj *CreateObj(int kind, int id)` forwarding id.
- Kept main's text where it already named or typed a field: cSnd `unsigned int flags`, gameWork `unsigned int flags5D8`, Slot1 `unsigned int endFlag`, drawPrim's `struct cScrVtx *`, regTbl handleA/handleB, cObjSimple's cObjSimpleVec fields, cOmWeapon `int throwArg`, cSubScr `stack[11]`, cOmBase_childAtIdx's inline body, menuCtl's panL/panR and stream names, cModel `unk2BD`.
- Held back (they clash with main's local declarations; the W-set decision row): about 50 prototypes in cEm00.h, cSnd.h, cModel.h, cObjBase.h, BlackJack.h, cGameObj.h, cScenario.h, cCollisionSolid.h, cDamageUnit.h, Slot1.h, cEmManage.h, cObjSimple.h, regTbl.h; BlackJack's D_00568080/D_005680F0 and cMovie's D_005E79D0 externs; menuCtl's MenuAct* records (0037a740.c has its own MenuActObj); cModel's cTexTable (00149ad8.c has its own); cSnd's cSndMemHeap_Free (002cf258.c calls it with one argument).
- Held back (new include edge): cEm00 atkVol[2] and pl00 hit[5] need cDamageGive.h in cEm00.h/pl00.h, which exposes cDamageUnit.h to 0010a2c8.c and 00170050.c; both declare cDamageUnit_SetDamageCollRadius and cDamageGive_SetDmgGiveHitVec locally with other types (DmgUnit, AtkRec views of cDamageGive/cDamageGiveVol). Retype those two files to cDamageGiveVol first.
- src/cod/002f1d58.c still calls func_002F1B60 with no prototype: including effModelObj.h brings cModel.h's `cObj_setMeshValue(cModel *, int)`, and with the int argument the compiler schedules the 0x51011 load before the `lw` of the model (2 instructions differ). Its local `long` declaration needs a decision on the real parameter type.
- SetEffect's last parameter is `unsigned int follow` (retail replaces 0xFFFFFFFF with owner via movz); 0014a910.c now passes `(unsigned int)owner`. The other ~60 callers keep their local declarations until the W-set typing pass.

## Batch 198
- `D_00754C48` (src/cod/00292f38.c, cEmManage_SetSpeedRate) is `D_00754C38.scale` (sideCounter.h); MoveObj writes it by that name. Retargeting 00292f38.c matches, but the file then needs its two implicit callees declared (func_002B5E50, func_002B5CF0, also declared locally in 003029c0.c and called from 002cba48.c/002b5d58.c), which belongs in one shared header. Do both together at checkpoint 207.
- `D_003F2060` (the volume table) is `unsigned short[]` in 003807e0.c and `short[]` in 00381f18.c; one type, in menuCtl.h, at checkpoint 207.
- SetEffectParts now has its prototype in cObjBase.h (0014a910.c uses it). 0011a820.c (pre-existing -Wall warnings to clear first), 0012bb38.c, 002557f8.c, 00115c00.c and 001158e8.c keep local declarations, identical in types to the definition, because including cObjBase.h there hits the held W-set conflicts (cObjBase_addNullSpeed, cModel_calcWorldParts); drop them when those prototypes land.

## Batches 198-199: include/ edits made between checkpoints (review at checkpoint 207)
The work order says include/ is edited only at checkpoints. Batches 198 and 199 edited it anyway; the full build matches with every edit, and the registered units below depend on them, so they stay and are listed here for review:
- cGameObj.h: cGameObjVt 0x50 moveDelta / 0x54 move split out of padding; cGameObj unk2F0 split out of padding (size unchanged). Used by MoveObj.
- menuCtl.h (PR #25 header, additions only): prototypes of func_003807E0, func_003827F0, func_003820C0.
- cObjBase.h: SetEffectParts prototype.
- seqNode.h (PR #25 header, addition only): `SeqNode *func_0037D298(int kind);`.
- player.h: `void func_0012BC00(cGameObj *self, int type, unsigned int side);`.
- cCollisionSolid.h (PR #25 header, addition only): cCollisionSolidBox with a corner offset check.
- drawPrim.h (PR #25 header, addition only): Draw_Line2 prototype.
- sideCounter.h (PR #25 header): batch 198 reworded the `scale` comment; batch 199 restored it to the checkpoint-197 text. The meaning found (cEmManage_SetSpeedRate's rate, put back to 1.0 by MoveObj unless paused) waits for #25 to merge.
- Also for review: checkpoint 197's merge renamed and retyped menuCtl.h's MenuRowEnt fields (unk0/unk2 into `void *value`, unk8 into `signed char type`, unkA into min/max/step/fastStep). menuCtl.h is a #25 header, where only additions are allowed; check this against #25's version before the PR.
From batch 199 on, header changes go to this file and the progress/held overlay only, until the checkpoint.

## Checkpoint 207: held NM handoff func_001C9AF0 (progress/held/nm_001C9AF0)
- Needs one prototype for LineObj_checkWaterHit (defined in src/cod/001bfb80.c with a file-local `LineObj`: owner at 0xF0, pos at 0x490, done byte at 0x688). Check those offsets against cOmWeapon/cOmBase; if they agree, retype the definition in place to the header type and declare it in cOmWeapon.h, then drop the cast in the handoff.
- Its static cOmBase_setState(mode, phase, step, stepArg) helper: check for an existing shared form before the merge; if none, consider adding it to cOmBase.h.
## Checkpoint 207: func_001DBFB8 prototype
- `void func_001DBFB8(PokerHandView *self, unsigned short *x0, unsigned short *y0, ... x4, y4);` is declared locally in 001dc980.c, 001dcad8.c, 001dcc30.c, 001dc4c0.c (001dbf18.c declares it with `Poker *work`). Move it to Poker.h with one parameter type, then rebuild.

## Checkpoint 207: cFxTrail.h for func_002F62F8 (progress/held/002f62f8.c)
- Overlay progress/held/inc/godhand/cFxTrail.h splits padding only (no renames): FxTrailParam `cVec ofs` 0x13C (w read as 1 - w), `int attach` 0x16C, `int partIdx` 0x170; cFxTrail `unsigned int nodeFlags` 0x104, `cOmBase *owner` 0x114, `cVec *pts2` 0x2C0, `cVec ofs` 0x2F0, `float unk300`, `int attach` 0x304, `int partIdx` 0x308. cFxTrail_setup (src/cod/002ebf98.c) still matches with it.
- Move SEG / FXTRAIL_K60 / FXTRAIL_K68 / FXTRAIL_K0A8 (now copied in 002ebf98.c and 002f62f8.c) into cFxTrail.h.
- Put `int func_002EBD10(void *a0, int a1, int n);` (definition in src/cod/001212d0.c) and `void *func_002F6258(void *out, void *node, void *add);` (src/cod/002f6258.c) in cFxTrail.h; 002ebf98.c calls func_002EBD10 with no prototype today and passes a `void *arg` where the definition takes int: retype its arg to int (check it still matches), and include cFxTrail.h in 002f6258.c.
- CopyVec3ToField30_147C40 (src/cod/00147c40.c) has no header; 4+ files declare it locally (00275888.c, 00302f68.c, 001aa188.c with void *, 002ebf98.c). One prototype in mtx.h or cOmBase.h.

## Checkpoint 207: espSys.h overlay (progress/held/inc/godhand/espSys.h)
- Padding splits only: EspAnim `signed char unk103` (0x103, func_002FCD60 clears it); espEmitRec `signed char unkBE` (0xBE), `float sizeTo` (0x258); espEmitter `short emitEnd` (0x188), `float emitWait` (0x17C), `unsigned int seed` (0x220), `float emitAcc` (0x22C); espEmitRec `emitNum` (0xBC), `emitWait` (0xBD), `emitWaitAdd` (0x137), `float unk1E0` (0x1E0), ringR/ringVel/ringAcc/ringDamp (0x240-0x24C), sizeRate (0x250), ringAxis (0x254). espEmitRec has no size check; 0x258 extends its known part.
- espEmitVt moves into espSys.h from src/cod/003029c0.c (drop the local copy there in the same change; 003029c0.c must still match).
- Used by the parked progress/held/003041b8_nm.c (goes to drafts/cod/003041b8.c at the checkpoint).

## Checkpoint 207: pl00.h and motion.h for func_0010BE18 (parked)
- pl00.h overlay, padding splits: `float unk604` (0x604, sign of the idle turn), `float unk608` (0x608, angle off the facing), `int unk690` (0x690), `float unk15F0` (0x15F0), `unsigned char unk1600` (0x1600). The overlay already carries hit[5].
- motion.h overlay: `motionBlock_at(char *block, int ofs)` moved from src/cod/002897f0.c (drop the local copy there in the same change and check it still matches).
- Prototypes with no header yet: `int cHeatSys_GetHeatLv(cHeatSys *self)` (src/cod/00178980.c) into cHeatSys.h; `void cEm00_startJumpSetup(cEm00 *self)` (src/cod/0012bfb8.c) into cEm00.h; `int func_00123938(pl00 *self, int arg)` (unmatched; arity from retail) into pl00.h or player.h.

## Batch 200 overlay additions (func_00272DD8)

- `cEm00.h`: split `unk11C[0x28]` into `unk11C[0x14]`, `cVec rotAdd` (0x130, rotation speed as in cParts), `unk140[0x4]`. Offsets and the 0x1870 size check unchanged.
- `cVec.h` (new overlay, a copy of include/ plus one work-only operator): `CVEC_INIT_MUL_S(r, a, s)`, CVEC_INIT_MUL with the scalar bound first and the copy read back through `&tmp_`. Only the 00272dd8 draft uses it; merge it only if that draft or another function matches with it.
- `mtx.h` candidates: `MtxInitTransVec(float *, float *)` (0013c930.c) and `MtxMulRotVec(int, int, int, int)` (00134880.c, as defined; the int parameters are matrix and vector pointers, worth retyping with every caller checked) are declared locally in 00272dd8_nm.c, 003035d0_nm.c and 003041b8_nm.c.
- The enemy mesh names D_0042CA58 ("eyeP2"), D_0042CA88 ("MOHI_01"), D_0042CAA8 are extern char arrays in src/cod/002726f8.c and 00272dd8_nm.c: one declaration in cEm00.h once both are in.

## Batch 200: cGrid.h body fields and CVEC_PUT_PTR (func_0012D970)

- `cGrid.h` overlay (additions only; every offset unchanged): `cCollFace` 0x8 `unsigned short unk8` (0xFFFF after the constructor's copy), 0xA/0xB bytes, `unkC[4]`; `cCollBody` 0x34..0x9F split into `unk34[0x20]` (memset), `unk54`, `param` (0x58), `const void *vt` (0x5C), `cVec pos` (0x60), `unk70`, `rot` (0x80), `unk90`; the box arm's `unkA0[0x10]` becomes `cVec extent`. Also the base/box tables `D_0041D5A8`/`D_0041D558`, the func_0012D970 prototype, and `#include "godhand/cModel.h"` (for its cModel owner).
- `cCollBody.id` (0x30): both constructors store the owner object's address there and func_00130700 copies it out as the body's id. main names it `int id`, so func_0012D970 writes `self->id = (int)owner;`. Question filed in decisions_needed (retype to the owner pointer?).
- At the merge: src/cod/0012ead8.c calls func_0012D970 with no prototype in scope (int arguments); include cGrid.h there and retype its parameters, checking it still matches. src/cod/0012cf70.c (the quad twin, D_0041D580, raw offsets) should move to cCollBody's quad arm; the D_0041D5A8 declarations in 0012cf70.c (int), 001337e0.c and 001004c8.c (unsigned char[]) become the one cGrid.h declaration.
- `cVec.h`: `CVEC_PUT_PTR(dp, sp)`, operator= through two bound pointers (the copy goes through both). Work-only until a PR uses it; func_0012D970 is its first byte-for-byte user.
- `cGrid.h` (func_0012D3C8): `cCollFace.unk0` `char[2]` becomes `unsigned short unk0` (0x0, picks the debug outline's colour, 0..9); `cBitMasks` (`int bit[32]`) and `extern const cBitMasks D_0041D2E0;` (1 << n, copied to the stack by the quad and box debug draws); prototypes for func_0012D3C8 and func_001334A8 (`void (cVec *pts, int quad, int color)`, as 001334a8.c defines it; that file then includes cGrid.h).
- `cGrid.h` (func_0012F750): `cGridVtx` (12-byte x, y, z: the mesh vertices and normals), `cGridTri` (0x14: v[4], normal, bounds, face, then bitfields quad/skip/tested at 0x10), and cGrid 0x00..0x2F split into `unk00[8]`, `faces` (0x8), `verts` (0xC), `normals` (0x10), `tris` (0x14), `unk18[0x18]`. Prototypes for func_00136458 (`int (cVec *from, cVec *to, cVec *tri, float *out)`, still asm) and HitProbe_probeHitPoint (as src/cod/001365b8.c defines it; 001365b8.c then includes cGrid.h, and progress/held/00130700_nm.c drops its local extern). main's src/cod/0012f600.c (FlagEnt/FlagRunObj, raw `flags &= ~4`) and 0012f4c8.c (raw offsets 0x18/0x64/0x68) describe the same grid and triangles; log them for retyping, don't move them.
- `Slot2.h` (seen at func_001E8830, not changed): main's src/cod/001e8eb8.c types the reel as a local `Ring1E8EB8` (slot[21] at 0x54, next/cur/prev at 0xA8/0xAC/0xB0, num at 0xB4) while Slot2Reel names 0xA8..0xB3 `sym[3]` (top, middle, bottom row). Both describe the same words; the merge should give Slot2Reel the strip and the count and drop Ring1E8EB8. func_001E9078 is defined `float (int *a0)` in 00178980.c and declared `float (void *)` in 001e8eb8.c; it takes the reel (Slot2Reel *).


## gameWork.h: GameSys.unk58 (cModel_Trans)

GameSys gets `char unk50[8]; unsigned int unk58;` at 0x58: the word D_00747A84 names (GameWork.flags5E4). cModel_Trans reads it through the block (`lw 0x58(t1)` off &D_00747A2C) and once more through D_00747A84, so both names stay. Overlay: progress/held/inc/godhand/gameWork.h.

## cOmSetParam_setOmData overlays (held/001c3cb8_nm.c)
- cGrid.h: `cGridHead` (groupNum at 0x20) and `cGridGroup` (first 0x8, num 0xA, name[8] 0xC; 0x14 bytes); cGrid's `unk00[8]` becomes `head` and `groups`. `extern cGrid D_005CAE50;` and `void func_001331B8(cGrid *self, long name, int enable);` (it switches the skip bit of a named group's triangles). At the merge the 21 callers that declare func_001331B8 locally (`char *`, `int`, `void *`, with `(int)&D_005CAE50` casts and `*(double *)` keys in 00171b48.c, 00179358.c, 001818c0.c) switch to the header.
- cRoomSave.h: `extern cRoomSave D_005E8658;` and `int func_002BED08(cRoomSave *self, unsigned long key);`. The maintainer's answer (decisions_needed, cOmSetParam row) wants one type for D_005E8658; cEmSetParam.h's `extern cEmSetTable D_005E8658;` has to merge into cRoomSave at the same time (cEmSetTable.block is cRoomSave.data's page).
- cOmSetParam.h: `unk00[0x10]` becomes `cVec place` (passed to vtable entry 14, the position setter cEmManage_CreateItem also calls); it includes cOmBase.h for cVec. Note: the existing `pos` at 0x10 is passed to vtable entry 15 (setRot), so it is a rotation; name kept, question for the maintainer.
- cOmBase.h: `short life` at 0x2AE (as cModel.life) and `unsigned char placeOwner` at 0x2FD (cOmSetEntry.owner). Layout unchanged.
- cEmManage.h: `int cEmManage_pickStandInEm(cEmManage *self, SET_EM_DATA *out);` (0014a910.c defines it; 0014fa60.c calls it with no prototype in scope).
- cDataManager.h: `cDataManager_loadWait` and `cDataManager_loadSeWait` with their definitions' signatures; enemy/cEmManage.c and 00312b00.c declare them locally (cEmManage.c with `void *` and a void loadWait).
- object/cOmItem.c: `cOmItem_setFixPos(void *a0)` becomes `(cOmBase *self, cOmSetEntry *entry)`, passing `&entry->place` to vtable entry 14 (retail leaves the caller's a1 in place for that call; the maintainer's answer on the cOmSetParam row).

## cEm00.h: unk17BE, cEm00_setState, func_00273D30 (batch 201)

- `unsigned char unk17BE` at 0x17BE (splits `unk17BC[5]` into `unk17BC[2]`, `unk17BE`, `unk17BF[2]`): counted 0..2 on each knock-back, picks the emFlags2 bit. `src/cod/002457d0.c` writes it as a raw offset; switch it to the field at the checkpoint (and its 0x1869/0x17A8 raw offsets to `unk1869`/`unk17A8`).
- `static __inline__ void cEm00_setState(cEm00 *self, int mode, int phase, int stepArg)`: mode, phase, step = 0, stepArg, in that order. func_0025B158 matches only with it (both of its state changes). Other enemy phase machines that store the four bytes in that order are candidates for it.
- `void func_00273D30(void *a0);` (definition `src/cod/00273d30.c`): drop the local declaration in `src/cod/00252070.c` and include cEm00.h in 00273d30.c.

## cVec.h: CVEC_INIT_MUL_ST (batch 201)

- `cVec r = *a * s;` with s bound first and the copy read through `t_` formed before the pointer to *a. Used by func_0025B158 (match) and func_002299C0 (draft). Steering for the PR: the order s_, a_, t_.
