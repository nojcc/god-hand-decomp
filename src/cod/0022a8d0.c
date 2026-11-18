/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"

extern unsigned char D_005864F0[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern int cEmManage_CkPlSorry(void *a0);
extern int cEmManage_CkPlCatched(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

/* sn-2.95.3-136 matched TU. */





















/* Phase machine on the step byte, 11 case labels. Calls CheckSlotsShort2FEAndSetByte1864_262A10,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, InitRenderStruct_2A8608,
 * StoreMotionParams_2609E0, Set_Fields_1884_1894_2609F8 and 11 more. */
__attribute__((section(".text.func_0022A8D0"))) void func_0022A8D0(cEm00 *self)
{

    self->unk186A = 2;
    self->emFlags2 = self->emFlags2 | 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            int gb;
            int b;

            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x251C), EM_RES_REC(b, 0x2520), 3, 0.0f, gb, 0);
            InitRenderStruct_2A8608((cGameObj *)self, 0xAA, 7, 0, 2, 0);
            StoreMotionParams_2609E0(self, 0x28, 0x1C, 0x3E, -1, 0);
            Set_Fields_1884_1894_2609F8(self, 0x3C, 0x1B, 0x3E, -1, 0);
            self->timerC = 0;
            self->timer = self->rot.y;
            self->step = self->step + 1;
        }
        case 1: {
            void *e = self->pos;
            float t;
            float th;

            self->emFlags = self->emFlags | 0x800000;
            t = Turn_dest(e, Getplayer()->pos, self->timer,
                          self->speedRate * 0.09817477f);
            th = self->timer + t;
            self->timer = th;
            self->timer = Adjust_theta(th);
            th = self->rot.y + t;
            self->rot.y = th;
            self->rot.y = Adjust_theta(th);
            if (moveMotion(self) != 0) {
                self->step = self->step + 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 2: {
            int gb;
            int b;

            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x2524), EM_RES_REC(b, 0x2528), 0, 0.0f, gb, 1);
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    self->unk568 = 1;
                    break;
                case 2:
                    self->unk568 = 2;
                    break;
                case 3:
                    self->unk568 = 2;
                    break;
                case 4:
                    self->unk568 = 2;
                    break;
                case 5:
                    self->unk568 = 3;
                    break;
            }
            self->step = self->step + 1;
        }
        case 3: {
            void *e = self->pos;
            float t;
            float th;
            char *g;

            self->emFlags = self->emFlags | 0x800000;
            t = Turn_dest(e, Getplayer()->pos, self->timer,
                          self->speedRate * 0.09817477f);
            th = self->timer + t;
            self->timer = th;
            self->timer = Adjust_theta(th);
            th = self->rot.y + t;
            self->rot.y = th;
            self->rot.y = Adjust_theta(th);
            if (moveMotion(self) != 0) {
                if (self->unk568 != 0) {
                    self->unk568 = self->unk568 - 1;
                } else {
                    self->step = 4;
                }
            }
            g = (char *)&D_005864F0;
            if (cEmManage_CkPlSorry(g) != 0) {
                self->step = 4;
            } else if (cEmManage_CkPlCatched(g) != 0) {
                self->step = 4;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        case 4: {
            int gb;
            int b;

            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x252C), EM_RES_REC(b, 0x2530), 0, 0.0f, gb, 0);
            InitRenderStruct_2A8608((cGameObj *)self, 0xAA, 8, 0, 2, 0);
            self->step = self->step + 1;
        }
        case 5:
            self->emFlags = self->emFlags | 0x800000;
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    func_00260B30(self);
    if ((self->seqFlags & 3) != 0) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 = self->emFlags2 & 0xFFFFFBFFU;
    }
}
