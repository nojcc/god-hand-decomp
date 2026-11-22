/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/angle.h"
#include "godhand/cCamera.h"
#include "godhand/globals.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */
















/* Phase machine on the step byte, 7 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, cCoreSave_getGameLevel, Getplayer, Turn_dest, Adjust_theta and 6 more. */
__attribute__((section(".text.func_002170B8"))) void func_002170B8(cEm00 *self)
{
    switch (self->step) {
        case 0: {
            int gb;
            char *v0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v0 = self->pack;
            func_002A8578(self, EM_RES_REC(v0, 0x1C8), EM_RES_REC(v0, 0x1CC), 3, 0.0f, gb,
                          0);
            self->timerA = 0x1E;
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
            self->timer = self->rot.y;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if (self->timerA != 0) {
                cVec *pos;
                cGameObj *pl;
                float th;
                self->timerA -= 1;
                pos = self->pos;
                pl = Getplayer();
                th = Turn_dest(&pos->x, &pl->pos->x, self->timer,
                               self->speedRate * 0.39269908f);
                self->timer += th;
                self->timer = Adjust_theta(self->timer);
                self->rot.y += th;
                self->rot.y = Adjust_theta(self->rot.y);
            }
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->seqFlags & 1) {
        if ((self->emFlags2 & 8) == 0) {
            cModelNode *r;
            func_0026BEF0(self, 8, 0);
            self->emFlags2 |= 8;
            r = cModel_getMeshPtr_14B730((cModel *)self, D_004365A8);
            if (r != 0) {
                r->dispFlags |= CMODEL_NODE_HIDE;
            }
            r = cModel_getMeshPtr_14B730((cModel *)self, D_004365B0);
            if (r != 0) {
                r->dispFlags |= CMODEL_NODE_HIDE;
            }
        }
    }
}
