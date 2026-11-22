/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/emPhaseTable.h"
#include "godhand/cOmEntry.h"
#include "godhand/globals.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(cOmBase *self);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];
extern void cModel_ScrollTexture(void *a0, float f);
extern int D_005CAE50;
extern void func_0012EC58(void *a, int b);
extern void *SetField214PtrThenInit_1B6F38(void *a, void *b);

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDA08;


__attribute__((section(".text.UpdatePhaseThenCalcPartsB")))
void UpdatePhaseThenCalcPartsB(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDA08, self, self->mode);
    func_002A87E8(self, 0);
    func_001B76D8(self);
    cModel_calcParts((cModel *)self);
    cModel_calcWorldParts((cModel *)self);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDC98;


__attribute__((section(".text.UpdatePhaseWithHitCheck")))
void UpdatePhaseWithHitCheck(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDC98, self, self->mode);
    cCollisionSolidManage_ChkHit(&D_00462FC0, (cGameObj *)self);
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDE40;


__attribute__((section(".text.UpdatePhaseConditionalSync")))
void UpdatePhaseConditionalSync(cOmEntry *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(&self->base) == 0) return;
    EM_PHASE_RUN(&D_003BDE40, self, self->base.mode);
    if (self->unk675 == 0) {
        func_002A87E8(self, 0);
    }
    func_001C0450(self);
    func_001B76D8(&self->base);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDC68;


__attribute__((section(".text.UpdatePhaseWithScroll")))
void UpdatePhaseWithScroll(cOmBase *self)
{
    float rate;
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDC68, self, self->mode);
    rate = cEmManage_GetSpeedRate(D_005864F0);
    self->speedRate = rate;
    cModel_ScrollTexture(self, rate);
    cCollisionSolidManage_ChkHit(&D_00462FC0, (cGameObj *)self);
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* Tick: dispatch the current action: pick the table entry for state byte +0x2F5 (reset to 0 when out of range) and call its handler, then sync. */


__attribute__((section(".text.UpdateActionTable")))
void UpdateActionTable(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 1) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003C0480 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003C0480 + i8 + 4);
    }
    f0 = *(short *)(D_003C0480 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_002A87E8(s0, 0);
}

/* Release an object's slot array: free the slot at +0x600, the damage give at +0x604 and the entry at +0xDA8, then reset the base. */


__attribute__((section(".text.ReleaseObjSlotsAndEffect")))
void *ReleaseObjSlotsAndEffect(void *a0, void *a1) {
    int *p = (int *)((char *)a0 + 0x600);
    int i = 0;
    *(int **)((char *)a0 + 0x214) = &D_00420EF0;
    do {
        if (*p != 0) {
            ClearAndResetFields_1FE278(&D_00574380, (void *)*p);
            *p = 0;
        }
        p++;
        i--;
    } while (i >= 0);
    if (*(int *)((char *)a0 + 0x604) != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, (cDamageGive *)(*(int *)((char *)a0 + 0x604)));
        *(int *)((char *)a0 + 0x604) = 0;
    }
    if (*(int *)((char *)a0 + 0xDA8) != 0) {
        func_0012EC58(&D_005CAE50, *(int *)((char *)a0 + 0xDA8));
        *(int *)((char *)a0 + 0xDA8) = 0;
    }
    return SetField214PtrThenInit_1B6F38(a0, a1);
}
