/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_0026EE40(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* Phase machine on the step byte, 7 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8, func_002A8578, cCoreSave_getGameLevel, func_0026EE40, Getplayer and
 * 8 more. */
__attribute__((section(".text.func_00229268"))) void func_00229268(cEm00 *self)
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
            StoreMotionParamsBoth_2609A8(self, 0, 0x10, 0x4C, -1, 0);
            v0 = self->pack;
            a1v = EM_RES_REC((int)v0, 0x1E7C);
            a2v = EM_RES_REC((int)v0, 0x1E80);
            self->timerA = 0xF;
            func_002A8578(self, a1v, a2v, 0xA, 0.0f, gb, 0);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->timerA = (int)((float)self->timerA * 0.75f);
                    break;
                case 2:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 3:
                case 4:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 5:
                    break;
            }
            self->timerC = 0;
            func_0026EE40(self, 0, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                cGameObj *pl;
                self->timerA -= 1;
                pl = Getplayer();
                cGameObj_SetTgtTurn(self, pl->pos, self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0) {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
                if (self->unk1864 == 0 || func_00273960(self, 6.0f) == 0) {
                    func_002705D8(self);
                }
                return;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    func_00260B30(self);
    if (self->seqFlags & 0x10) {
        if (func_00262AA8(self) != 0) {
            return;
        }
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
