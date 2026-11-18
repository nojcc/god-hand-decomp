/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int irand(void);
extern void func_0026DB00(void *a0, int a1, int a2);

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cDamageUnit_SetDamageCollActive, cSnd_SeCall_2CBA48, GetSeqSEBase, moveMotion and
 * 2 more. */
__attribute__((section(".text.func_0025FCF8"))) void func_0025FCF8(cEm00 *self)
{
    cDamageUnit *du;
    cGameObjVt *vt;
    int nb;
    char *b;
    int o;
    float one;

    vt = cGameObj_vt((cGameObj *)self);
    du = vt->getDamageUnit((char *)self + vt->damageUnitDelta);
    switch (self->step) {
        case 0:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = self->pack;
            o = EM_RES_REC(b, 0x108C);
            func_002A8578(self, o, o, 3, 0.0f, nb, 0);
            cDamageUnit_SetDamageCollActive(du, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 8), self, 0, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->step = 0;
                self->mode = 2;
                self->phase = 2;
                self->stepArg = 0;
            } else {
                one = 1.0f;
                cObjBase_addNullSpeed_Rotation(self, one);
                cObjBase_addNullSpeed(self, one);
            }
            break;
    }
    self->seqFlags = self->seqFlags | 0x400;
}

/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * cCoreSave_getGameLevel, Obj2810_SetState_8_a1, SetBytes2F4Mode7_283270,
 * ClearBytes2F4To2F7_283170, func_002A8578 and 4 more. */
__attribute__((section(".text.func_0024B218"))) void func_0024B218(cEm00 *self)
{
    float one;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
        case 0: {
            int t0, b, b2, a1v, a2v;
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            a1v = EM_RES_REC(b, 0x3DA4);
            a2v = EM_RES_REC(b, 0x3DA8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                b2 = EM_RES(self);
                a2v = EM_RES_REC(b2, 0x3DAC);
                if (self->sub0 != 0)
                    Obj2810_SetState_8_a1(self->sub0, 1);
                if (self->sub1 != 0)
                    SetBytes2F4Mode7_283270(self->sub1, 1);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170(self->sub2);
            } else {
                if (self->sub0 != 0)
                    Obj2810_SetState_8_a1(self->sub0, 0);
                if (self->sub1 != 0)
                    SetBytes2F4Mode7_283270(self->sub1, 0);
                if (self->sub2 != 0)
                    ClearBytes2F4To2F7_283170(self->sub2);
            }
            func_002A8578(self, a1v, a2v, 0xA, 0.0f, t0, 0);
        }
            self->step++;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
    if (self->seqFlags & 1) {
        func_0026DB00(self, 4, 0);
    }
}
