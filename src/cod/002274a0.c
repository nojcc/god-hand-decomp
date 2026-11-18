/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */














/* Phase machine on the step byte, 7 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8, func_002A8578, cCoreSave_getGameLevel, func_0026EE40, moveMotion
 * and 5 more. */
__attribute__((section(".text.func_002274A0"))) void func_002274A0(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            char *v0;
            int a1v, a2v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x32, 0x21, 0x3E, -1, 0);
            v0 = self->pack;
            a1v = EM_RES_REC((int)v0, 0x2E0C);
            a2v = EM_RES_REC((int)v0, 0x2E10);
            self->timerA = 0;
            func_002A8578(self, a1v, a2v, 0xA, 0.0f, gb, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->timerA = 0x46;
                    break;
                case 2:
                    self->timerA = 0x50;
                    break;
                case 3:
                case 4:
                    self->timerA = 0x5A;
                    break;
                case 5:
                    break;
            }
            self->timerC = 0;
            self->unk568 = 0;
            self->timerB = 0x64;
            self->unk5F8 = 1;
            func_0026EE40(self, 0, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            self->emFlags |= 0x800000;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->seqFlags & 1) {
        if (self->timerB != 0) {
            self->timerB = 0;
            func_0026BEF0(self, 0x15, self->unk568);
            self->unk568 += 1;
        }
    } else {
        self->timerB = 1;
    }
    if (self->seqFlags & 2) {
        func_00260B30(self);
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
