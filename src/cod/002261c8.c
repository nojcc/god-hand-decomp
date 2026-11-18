/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */
















/* Phase machine on the step byte, 7 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, StoreMotionParamsBoth_2609A8, cCoreSave_getGameLevel, irand,
 * func_002A8578 and 7 more. */
__attribute__((section(".text.func_002261C8"))) void func_002261C8(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int gb;
            char *v0;
            int a1v, a2v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x3E, 0, 0xF5);
            v0 = self->pack;
            a1v = EM_RES_REC((int)v0, 0x1990);
            a2v = EM_RES_REC((int)v0, 0x1994);
            self->timerA = 0x25;
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                if (irand() & 1) {
                    char *v1 = self->pack;
                    int f = *(int *)(v1 + 0x1998);
                    self->timerA = 0x14;
                    a2v = f + (int)v1;
                } else {
                    char *v1 = self->pack;
                    int f = *(int *)(v1 + 0x199C);
                    self->timerA = 0x19;
                    a2v = f + (int)v1;
                }
            }
            func_002A8578(self, a1v, a2v, 0xA, 0.0f, gb, 0);
            self->timerC = 0;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                case 1:
                default:
                    self->timerA = (int)((float)self->timerA * 0.8f);
                    break;
                case 2:
                    self->timerA = (int)((float)self->timerA * 0.9f);
                    break;
                case 3:
                case 4:
                    self->timerA = (int)((float)self->timerA * 1.0f);
                    break;
                case 5:
                    break;
            }
            self->timerB = 0x32;
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
            if (self->timerB != 0) {
                self->timerB -= 1;
                self->emFlags |= 0x800000;
            }
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    func_00260B30(self);
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
