/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern unsigned int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* Phase machine on the step byte, 12 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, StoreMotionParamsBoth_2609A8, cCoreSave_getGameLevel, irand,
 * func_002A8578 and 8 more. */
__attribute__((section(".text.func_00225E30"))) void func_00225E30(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int r;
            int p1;
            int p2;
            self->unk1864 = 0;
            r = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0, 0x3E, 0, 0x111);
            if (cCoreSave_getGameLevel(&D_00569B70) >= 2 && (irand() & 1)) {
                int w = EM_RES(self);
                p1 = EM_RES_REC(w, 0x1DF0);
                p2 = EM_RES_REC(w, 0x1DF4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    int w2 = EM_RES(self);
                    p2 = EM_RES_REC(w2, 0x1DF8);
                }
                self->timerB = 0x66;
            } else {
                int w = EM_RES(self);
                p1 = EM_RES_REC(w, 0x1DE4);
                p2 = EM_RES_REC(w, 0x1DE8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    int w2 = EM_RES(self);
                    p2 = EM_RES_REC(w2, 0x1DEC);
                }
                self->timerB = 0x2C;
            }
            self->timerC = 0;
            func_002A8578(self, p1, p2, 0xA, 0.0f, r, 0);
            self->timerA = 0x2C;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
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
            self->unk5F8 = 0;
            self->step = self->step + 1;
        }
        /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                cGameObj *pl;
                self->timerA = self->timerA - 1;
                pl = Getplayer();
                cGameObj_SetTgtTurn(self, pl->pos, self->speedRate * 0.19634954f);
            }
            if (moveMotion(self))
                func_002705D8(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        default:
            break;
    }

    if (self->seqFlags & 1)
        func_00260B30(self);
    if (self->seqFlags & 2) {
        if (self->unk5F8 == 0) {
            self->unk5F8 = 1;
            func_0026BEF0(self, 4, 0);
        }
        self->timerA = 0x1E;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
            default:
            case 1:
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
    } else {
        self->unk5F8 = 0;
    }
    if (self->seqFlags & 3)
        self->timerC = 1;
    if (self->timerC != 0)
        self->emFlags2 &= 0xFFFFFBFFU;
}
