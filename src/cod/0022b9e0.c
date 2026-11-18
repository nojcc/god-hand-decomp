#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);

/* A three-motion attack: turn toward the player through the first motion, play the second
 * unk568 times (once; turning while timerA lasts), play the third, then go to phase 0x6B.
 * Throughout, a motion event (seqFlags bit 0) starts effect 6 and sound 0x22, at most once every
 * 3 frames, and bit 0x400 of emFlags2 is cleared once seqFlags bit 0 or 1 has set timerC. */
__attribute__((section(".text.func_0022B9E0"))) void func_0022B9E0(cEm00 *self)
{
    float d;

    self->unk186A = 2;
    self->emFlags |= 0x400;
    self->emFlags2 |= 0x400;
    switch (self->step) {
        case 0: {
            int gb;
            int b;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x2200), EM_RES_REC(b, 0x2204), 3, 0.0f, gb, 0);
            self->timerC = 0;
            self->unk56A = 0;
            self->step++;
        }
        case 1:
            if (self->stepArg == 0) {
                cGameObj *pl = Getplayer();

                cGameObj_SetTgtTurn(self, pl->pos, self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0) {
                self->step++;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int gb;
            int b;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x2208), EM_RES_REC(b, 0x220C), 3, 0.0f, gb, 0);
            self->timer = 0.0f;
            self->unk5F8 = 1;
            self->unk568 = 1;
            self->step++;
        }
        case 3:
            if (self->stepArg == 0) {
                if (self->timerA != 0) {
                    cGameObj *pl;

                    self->timerA--;
                    pl = Getplayer();
                    cGameObj_SetTgtTurn(self, pl->pos, self->speedRate * 0.049087387f);
                }
            }
            if (moveMotion(self) != 0) {
                self->unk568--;
                if (self->unk568 <= 0) {
                    self->step++;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4: {
            int gb;
            int b;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x2210), EM_RES_REC(b, 0x2214), 3, 0.0f, gb, 0);
            self->step++;
        }
        case 5:
            if (moveMotion(self) != 0) {
                /* retail stores stepArg back unchanged */
                unsigned char arg = self->stepArg;

                self->phase = 0x6B;
                self->stepArg = arg;
                self->mode = 0;
                self->step = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    d = self->timer;
    if (0.0f < d) {
        self->timer = d - self->speedRate;
    } else if ((self->seqFlags & 1) != 0) {
        func_0026BEF0(self, 6, 0);
        self->timer = 3.0f;
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x22, self, 0, 0, 0, 0);
    }
    if ((self->seqFlags & 3) != 0) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
