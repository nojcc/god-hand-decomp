/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/angle.h"
#include "godhand/motion.h"
#include "godhand/player.h"

/* The enemy's turn to face the player: steps 0-1 play the turn motion for
 * the side the player stands on (enemies 0x256 and 0x27E have their own
 * pair) and, once the motion allows it, go to the close or far attack, or to
 * step 2 when the player is within 30 degrees of straight ahead. Steps 2-3
 * play the grab motion and take the two 0x365 objects once it ends. */
__attribute__((section(".text.func_00217560")))
void func_00217560(cEm00 *self)
{
    unsigned short sel;
    float rel;
    cOmWeapon *p;
    int motA;
    int motB;

    switch (self->step) {
    case 0: {
        cVec *from;

        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        from = Getplayer()->pos;
        rel = Turn_dest((float *)from, (float *)self->pos, Getplayer()->rot.y, 3.1415927f);
        if (self->emNo != 0x256 && self->emNo != 0x27E) {
            if (0.0f < rel) {
                if (self->unk17C3 != 0) {
                    motA = EM_RES_REC(EM_RES(self), 0x1670);
                    motB = EM_RES_REC(EM_RES(self), 0x1674);
                } else {
                    motA = EM_RES_REC(EM_RES(self), 0x1660);
                    motB = EM_RES_REC(EM_RES(self), 0x1664);
                }
            } else {
                if (self->unk17C3 != 0) {
                    motA = EM_RES_REC(EM_RES(self), 0x1660);
                    motB = EM_RES_REC(EM_RES(self), 0x1664);
                } else {
                    motA = EM_RES_REC(EM_RES(self), 0x1670);
                    motB = EM_RES_REC(EM_RES(self), 0x1674);
                }
            }
        } else {
            if (0.0f < rel) {
                if (self->unk17C3 != 0) {
                    motA = EM_RES_REC(EM_RES(self), 0x25BC);
                    motB = EM_RES_REC(EM_RES(self), 0x25C0);
                } else {
                    motA = EM_RES_REC(EM_RES(self), 0x25C4);
                    motB = EM_RES_REC(EM_RES(self), 0x25C8);
                }
            } else {
                if (self->unk17C3 != 0) {
                    motA = EM_RES_REC(EM_RES(self), 0x25C4);
                    motB = EM_RES_REC(EM_RES(self), 0x25C8);
                } else {
                    motA = EM_RES_REC(EM_RES(self), 0x25BC);
                    motB = EM_RES_REC(EM_RES(self), 0x25C0);
                }
            }
        }
        func_002A8578(self, motA, motB, 3, 0.0f, sel, 0);
        self->hitFlash = 5.0f;
        self->step++;
    }
        /* fall through */
    case 1:
        cGameObj_SetTgtTurn((cGameObj *)self, &self->unk16A0, self->speedRate * 0.09817477f);
        if (moveMotion(self) != 0)
            func_002705D8(self);
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if (self->seqFlags & 0x10) {
            if (self->emNo != 0x256 && self->emNo != 0x27E) {
                cVec *from = Getplayer()->pos;

                rel = Turn_dest((float *)from, (float *)self->pos, Getplayer()->rot.y, 3.1415927f);
                rel = absf(rel);
                if (rel < 0.5235988f)
                    self->step = 2;
            } else {
                if (self->playerDist < 4.0f)
                    cEm00_setState(self, 0, 0x16, 0);
                else if (self->playerDist < 25.0f)
                    cEm00_setState(self, 0, 0x17, 0);
                else
                    func_00262AA8(self);
            }
        }
        break;
    case 2: {
        cVec *from;

        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->unk1864 = 0;
        from = Getplayer()->pos;
        /* retail computes the turn toward the player here and drops it */
        Turn_dest((float *)from, (float *)self->pos, Getplayer()->rot.y, 3.1415927f);
        func_002A8578(self, EM_RES_REC(EM_RES(self), 0x1668),
                      EM_RES_REC(EM_RES(self), 0x166C), 3, 0.0f, sel, 0);
        self->step++;
    }
        /* fall through */
    case 3:
        cGameObj_SetTgtTurn((cGameObj *)self, &self->unk16A0, self->speedRate * 0.09817477f);
        if (moveMotion(self) != 0)
            func_002705D8(self);
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if ((self->seqFlags & 3) && self->unk1864 == 0) {
            self->unk1864 = 1;
            p = func_0026AA30(self, 0x365);
            if (p != 0)
                func_0026B240(self, p, 0x365, 10);
            p = func_0026AA30(self, 0x365);
            if (p != 0)
                func_0026B240(self, p, 0x365, 0x10);
        }
        break;
    }
}
