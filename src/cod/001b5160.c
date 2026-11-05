/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDObj.h"
#include "godhand/cEvent.h"
#include "godhand/espSys.h"
#include "godhand/cEm00.h"
#include "godhand/cIDBase.h"
#include "godhand/cRelSys.h"
#include "godhand/cOmBase.h"
#include "godhand/cSnd.h"
#include "godhand/heapArena.h"
#include "godhand/regTbl.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/drawQueue.h"
#include "godhand/typeInfo.h"

extern int D_0077E6C0[];
extern void func_001FDEA8(void *);
extern void KeyStop(void);
extern void func_002B4560(void);
extern void func_00345610(void);
extern void func_002BB010(void);
extern void func_002BF170(void *a0);
extern void cMc_startLoadRunRelease(int a0);
extern void cMc_startLoadRunReleaseB(int a0);
extern int Forward325C98_325DC0(int a0);

__attribute__((section(".text.func_003B2058")))
int func_003B2058(int a0) { return D_0077E6C0[a0]; }

__attribute__((section(".text.Tramp_func_001B79B0_001B5160")))
void Tramp_func_001B79B0_001B5160(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001B6660")))
void Tramp_func_001B79B0_001B6660(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001B6E10")))
void Tramp_func_001B79B0_001B6E10(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001B8F88")))
void Tramp_func_001B79B0_001B8F88(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BBE48")))
void Tramp_func_001B79B0_001BBE48(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BCB18")))
void Tramp_func_001B79B0_001BCB18(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BD9E0")))
void Tramp_func_001B79B0_001BD9E0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BE478")))
void Tramp_func_001B79B0_001BE478(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BEA20")))
void Tramp_func_001B79B0_001BEA20(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BFA58")))
void Tramp_func_001B79B0_001BFA58(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001BFF48")))
void Tramp_func_001B79B0_001BFF48(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001C2260")))
void Tramp_func_001B79B0_001C2260(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001C3070")))
void Tramp_func_001B79B0_001C3070(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.cCoreSave_setGameLevel1_1F9AD0")))
void cCoreSave_setGameLevel1_1F9AD0(cCoreSave *self) { cCoreSave_setGameLevel(self, 1); }

__attribute__((section(".text.cCoreSave_setGameLevel5_1F9AF0")))
void cCoreSave_setGameLevel5_1F9AF0(cCoreSave *self) { cCoreSave_setGameLevel(self, 5); }

__attribute__((section(".text.func_001FDF88")))
void func_001FDF88(void *a0) { func_001FDEA8(a0); }

__attribute__((section(".text.func_00200638")))
void func_00200638(void)
{
	KeyStop();
}

__attribute__((section(".text.func_0028BEA8")))
void func_0028BEA8(cEm00 *self)
{
	func_0028CE70(self);
}

/* Forwards to cEmManage_reset. */
__attribute__((section(".text.func_00290230")))
void func_00290230(cEmManage *self)
{
	cEmManage_reset(self);
}

__attribute__((section(".text.func_00296350")))
void func_00296350(cEvent *self)
{
	func_00297660(self);
}

__attribute__((section(".text.func_002B4390")))
void func_002B4390(void)
{
	func_002B4560();
}

__attribute__((section(".text.func_002B4A30")))
void func_002B4A30(void)
{
	func_00345610();
}

__attribute__((section(".text.cObjSimple_Dtor")))
void cObjSimple_Dtor(struct cObjBase *self, int flags) {
    cObjBase__dtor(self, flags);
}

__attribute__((section(".text.func_002B8908")))
void func_002B8908(struct cObjBase *self, int flags) {
    cObjBase__dtor(self, flags);
}

__attribute__((section(".text.func_002BA4B0")))
void func_002BA4B0(void) {
    func_002BB010();
}

__attribute__((section(".text.func_002BE6C8")))
int func_002BE6C8(cRelSlot *slot) {
    return func_00394F20(slot->data);
}

__attribute__((section(".text.func_002BE6E8")))
void func_002BE6E8(cRelSlot *slots) {
    func_00394D58(0);
}

__attribute__((section(".text.func_002BE818")))
void func_002BE818(cRelSlot *slots) {
    func_002BE858(slots, 0);
}

__attribute__((section(".text.func_002BF130")))
void func_002BF130(void *a0) { func_002BF170(a0); }

__attribute__((section(".text.func_002BF150")))
void func_002BF150(void *a0) { func_002BF170(a0); }

__attribute__((section(".text.func_002C09E8")))
void func_002C09E8(void) { cMc_startLoadRunRelease(2); }

__attribute__((section(".text.func_002C0A08")))
void func_002C0A08(void) { cMc_startLoadRunReleaseB(2); }

__attribute__((section(".text.func_002CA690")))
/* self is not read. */
void func_002CA690(cSnd *self) { Forward325C98_325DC0(0); }

extern void func_003735E0(cSndBgmNode *node, int a1, float to, float time);
/* Fades a node with the given target and time; -1 selects the whole sequence. */
__attribute__((section(".text.cSndBgmNode_FadeTo")))
void cSndBgmNode_FadeTo(cSndBgmNode *node, float to, float time) { func_003735E0(node, -1, to, time); }


__attribute__((section(".text.func_002E1710")))
void func_002E1710(EspAnim *self)
{
    func_002FBED0(self);
}


__attribute__((section(".text.func_002E28D0")))
void func_002E28D0(EspAnim *self)
{
    LinkObj_callLockOn(self);
}


__attribute__((section(".text.func_002E82F8")))
void func_002E82F8(EspAnim *self)
{
    func_002FBED0(self);
}


__attribute__((section(".text.func_002EFB48")))
void func_002EFB48(EspAnim *self)
{
    func_002FBED0(self);
}


__attribute__((section(".text.func_002F29E0")))
void func_002F29E0(EspAnim *self)
{
    func_002FBED0(self);
}


__attribute__((section(".text.func_002F3070")))
void func_002F3070(EspAnim *self)
{
    func_002FBED0(self);
}


__attribute__((section(".text.func_002F4D28")))
void func_002F4D28(EspAnim *self) {
    func_002FBED0(self);
}


__attribute__((section(".text.func_002F5448")))
void func_002F5448(EspAnim *self) {
    func_002FBED0(self);
}


__attribute__((section(".text.Tramp_UpdateObjByIndexedOp_2FBE50_2FEBB8")))
void Tramp_UpdateObjByIndexedOp_2FBE50_2FEBB8(EspAnim *self) {
    UpdateObjByIndexedOp_2FBE50(self);
}


__attribute__((section(".text.func_003052E8")))
void func_003052E8(EspAnim *self) {
    func_002FBE88(self);
}

void func_00306AA8(void);

__attribute__((section(".text.func_00306A88")))
void func_00306A88(void) {
    func_00306AA8();
}


__attribute__((section(".text.func_00318338")))
void func_00318338(struct cObjBase *self, int flags) {
    cObjBase__dtor(self, flags);
}


__attribute__((section(".text.func_0031C8E0")))
void *func_0031C8E0(unsigned int size, unsigned int align, HeapArena *heap)
{
    return _MemoryAlloc(size, align, heap);
}


/* A derived type-info record's destructor: only type_info's. */
/* A derived type-info record's destructor: only type_info's. */
__attribute__((section(".text.func_0031F1F8")))
void func_0031F1F8(TypeInfo *self, int flags)
{
    func_0031EE10(self, flags);
}


/* A derived type-info record's destructor: only type_info's. */
/* A derived type-info record's destructor: only type_info's. */
__attribute__((section(".text.func_0031F288")))
void func_0031F288(TypeInfo *self, int flags)
{
    func_0031EE10(self, flags);
}


/* A derived type-info record's destructor: only type_info's. */
/* A derived type-info record's destructor: only type_info's. */
__attribute__((section(".text.func_0031F310")))
void func_0031F310(TypeInfo *self, int flags)
{
    func_0031EE10(self, flags);
}


/* A derived type-info record's destructor: only type_info's. */
/* A derived type-info record's destructor: only type_info's. */
__attribute__((section(".text.func_0031FFA0")))
void func_0031FFA0(TypeInfo *self, int flags)
{
    func_0031EE10(self, flags);
}

/* Trampolines relocated from src/cod/000000.c on 2026-08-31.  Each body carried a `do { } while (0);` barrier whose only
 * job was to defeat gcc's sibling-call optimisation under cygnus-2.96.  The
 * barrier is a zero-capability steering construct.  sn-2.95.3-136 does not
 * sibcall this shape, so the bare body is exact — and the six nearest
 * address-neighbours of these functions are 94% sn-2.95.3-136 already, so
 * the compiler key is a recovered setting, not a per-function invention. */
extern void func_0015FF10(void *obj);

__attribute__((section(".text.MtxCopy")))
void MtxCopy(void *dst, void *src) { func_0030A548(dst, src); }

__attribute__((section(".text.MtxMultiply")))
void MtxMultiply(void *dst, void *a, void *b) { sceVu0MulMatrix(dst, a, b); }

__attribute__((section(".text.Tramp_func_0030A2B0_001508D8")))
void Tramp_func_0030A2B0_001508D8(void *dst, void *mtx, void *src) { sceVu0ApplyMatrix(dst, mtx, src); }

__attribute__((section(".text.Tramp_func_0015B0F0_0015B080_15B080")))
void *Tramp_func_0015B0F0_0015B080_15B080(int size) { return PostInc_D_00566E10_0015B0F0_15B0F0(size); }

__attribute__((section(".text.Tramp_func_0015FF10_001612A8_1612A8")))
void Tramp_func_0015FF10_001612A8_1612A8(void *obj) { func_0015FF10(obj); }

__attribute__((section(".text.Tramp_func_002AAC28_00161970_161970")))
void Tramp_func_002AAC28_00161970_161970(cIDBaseObj * self) { cIDBase_trans(self); }

__attribute__((section(".text.Tramp_func_001614D0_00161BB0_161BB0")))
void Tramp_func_001614D0_00161BB0_161BB0(char * self) { ClearFields_1614D0(self); }

__attribute__((section(".text.Tramp_func_002AAC28_00162278_162278")))
void Tramp_func_002AAC28_00162278_162278(cIDBaseObj * self) { cIDBase_trans(self); }

__attribute__((section(".text.Tramp_func_001614D0_00166618_166618")))
void Tramp_func_001614D0_00166618_166618(char * self) { ClearFields_1614D0(self); }

__attribute__((section(".text.Tramp_func_001614D0_001673B0_1673B0")))
void Tramp_func_001614D0_001673B0_1673B0(char * self) { ClearFields_1614D0(self); }

__attribute__((section(".text.Tramp_func_002AAC28_001682A8_1682A8")))
void Tramp_func_002AAC28_001682A8_1682A8(cIDBaseObj * self) { cIDBase_trans(self); }

__attribute__((section(".text.Tramp_func_001C29D0_0016F5E8_16F5E8")))
void Tramp_func_001C29D0_0016F5E8_16F5E8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_0016F8E0")))
void Tramp_func_001C29D0_0016F8E0(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_0016FBD8")))
void Tramp_func_001C29D0_0016FBD8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_0016FE48")))
void Tramp_func_001C29D0_0016FE48(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00170130")))
void Tramp_func_001C29D0_00170130(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00170418")))
void Tramp_func_001C29D0_00170418(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001BFB80_001706E0")))
void Tramp_func_001BFB80_001706E0(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001BFB80_00170970")))
void Tramp_func_001BFB80_00170970(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001BFB80_00170C00")))
void Tramp_func_001BFB80_00170C00(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001BFB80_00170E90")))
void Tramp_func_001BFB80_00170E90(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001BFB80_00171000")))
void Tramp_func_001BFB80_00171000(cOmBase *self) { func_001BD6B0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001717A0")))
void Tramp_func_001B79B0_001717A0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BD6B0_00171C20")))
void Tramp_func_001BD6B0_00171C20(cOmBase *self) { func_001BD6B0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00173198")))
void Tramp_func_001B79B0_00173198(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001741E8")))
void Tramp_func_001B79B0_001741E8(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00174FB0")))
void Tramp_func_001B79B0_00174FB0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00176738")))
void Tramp_func_001B79B0_00176738(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00177DC0")))
void Tramp_func_001B79B0_00177DC0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_001784F8")))
void Tramp_func_001C29D0_001784F8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_001787A0")))
void Tramp_func_001C29D0_001787A0(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001789F8")))
void Tramp_func_001B79B0_001789F8(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00178CC0")))
void Tramp_func_001C29D0_00178CC0(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00178F58")))
void Tramp_func_001C29D0_00178F58(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00179798")))
void Tramp_func_001B79B0_00179798(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017A508")))
void Tramp_func_001B79B0_0017A508(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017B548")))
void Tramp_func_001B79B0_0017B548(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017C008")))
void Tramp_func_001B79B0_0017C008(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BD6B0_0017C5B0")))
void Tramp_func_001BD6B0_0017C5B0(cOmBase *self) { func_001BD6B0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017CE18")))
void Tramp_func_001B79B0_0017CE18(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_0017D560")))
void Tramp_func_001BC0A0_0017D560(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017DB40")))
void Tramp_func_001B79B0_0017DB40(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017E658")))
void Tramp_func_001B79B0_0017E658(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_0017EA28")))
void Tramp_func_001BC0A0_0017EA28(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001BD6B0_0017EB98")))
void Tramp_func_001BD6B0_0017EB98(cOmBase *self) { func_001BD6B0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017EDD0")))
void Tramp_func_001B79B0_0017EDD0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017F1D0")))
void Tramp_func_001B79B0_0017F1D0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_0017F470")))
void Tramp_func_001BC0A0_0017F470(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017F990")))
void Tramp_func_001B79B0_0017F990(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0017FD80")))
void Tramp_func_001B79B0_0017FD80(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001815B0")))
void Tramp_func_001B79B0_001815B0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_001817C8")))
void Tramp_func_001BC0A0_001817C8(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00182020")))
void Tramp_func_001B79B0_00182020(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00182818")))
void Tramp_func_001C29D0_00182818(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00182FD8")))
void Tramp_func_001B79B0_00182FD8(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001BFB80_001834F0")))
void Tramp_func_001BFB80_001834F0(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001C29D0_001837D8")))
void Tramp_func_001C29D0_001837D8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00184A20")))
void Tramp_func_001B79B0_00184A20(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_0014EFA8_001866A0")))
void Tramp_func_0014EFA8_001866A0(struct cObjBase *self) { cObjBase_KageDraw(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_00186928")))
void Tramp_func_001BC0A0_00186928(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00187190")))
void Tramp_func_001B79B0_00187190(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00187958")))
void Tramp_func_001C29D0_00187958(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00187C18")))
void Tramp_func_001C29D0_00187C18(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_00188528")))
void Tramp_func_001B79B0_00188528(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00188C88")))
void Tramp_func_001C29D0_00188C88(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00188F10")))
void Tramp_func_001C29D0_00188F10(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018A110")))
void Tramp_func_001B79B0_0018A110(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018AD88")))
void Tramp_func_001B79B0_0018AD88(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018BAA0")))
void Tramp_func_001B79B0_0018BAA0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018C8A8")))
void Tramp_func_001B79B0_0018C8A8(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018D698")))
void Tramp_func_001B79B0_0018D698(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018E450")))
void Tramp_func_001B79B0_0018E450(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_0018EC28")))
void Tramp_func_001C29D0_0018EC28(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001BFB80_0018EE38")))
void Tramp_func_001BFB80_0018EE38(cOmBase *self) { StateObj_runHandler(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_0018F0A0")))
void Tramp_func_001BC0A0_0018F0A0(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_0018FBF0")))
void Tramp_func_001B79B0_0018FBF0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001915B8")))
void Tramp_func_001B79B0_001915B8(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00191CC8")))
void Tramp_func_001C29D0_00191CC8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_00191F30")))
void Tramp_func_001BC0A0_00191F30(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001BC0A0_00192198")))
void Tramp_func_001BC0A0_00192198(cOmBase *self) { func_001BC0A0(self); }

__attribute__((section(".text.Tramp_func_001B79B0_001928B0")))
void Tramp_func_001B79B0_001928B0(cOmBase *self) { cOmBase_dieCommon(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00192BC8")))
void Tramp_func_001C29D0_00192BC8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00192EF8")))
void Tramp_func_001C29D0_00192EF8(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

__attribute__((section(".text.Tramp_func_001C29D0_00193180")))
void Tramp_func_001C29D0_00193180(cOmBase * self) { cOmBase_tickModeTableSkip381(self); }

