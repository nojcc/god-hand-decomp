/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/vu0.h"
#include "include_asm.h"

#define EMFLAG_JUMPING      0x400
#define EMFLAG_AIRBORNE     0x10000
#define LINE_FLOOR          2
#define LINE_CEILING        7
#define SE_JUMP_STEP        0x365

/* Jump phase machine: crouch while turning to the player, rise and fall with
 * the jump speed in home.y (landing on the floor or stopping under the
 * ceiling), land, then jump again toward the point at 0x16A0.
 * Differs from retail in two places: step 2 sets the float argument of
 * func_002A8578 one instruction later, and in step 7 retail compares home.y
 * with zero before the gravity update and reloads it after the store (its
 * update sat in an if/else with identical arms). */
#ifdef NON_MATCHING
__attribute__((section(".text.func_00216078")))
void func_00216078(cEm00 *self)
{
    cVec *pos = self->pos;
    cVec from;
    cVec to;
    cVec floor;
    cVec ceiling;
    float top;
    cGameObj *player;
    unsigned short sel;
    int motA;
    int motB;
    cOmWeapon *rec;

    VU0_LQC2_SQC2_MEM(4, &from, pos);
    VU0_LQC2_SQC2_MEM(4, &to, pos);
    VU0_SQC2_VF0_MEM(&floor, 0);
    self->emFlags |= EMFLAG_JUMPING;
    switch (self->step) {
    case 0:
        self->unk17D0 = (unsigned int)irand() % 5;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(EM_RES(self), 0x161C);
        motB = EM_RES_REC(EM_RES(self), 0x1620);
        func_002A8578(self, motA, motB, 3, 0.0f, sel, 0);
        self->unk5F8 = 0;
        self->timerC = 0;
        self->step++;
    case 1:
        player = Getplayer();
        cGameObj_SetTgtTurn((char *)self, player->pos, self->speedRate * 0.09817477f);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(EM_RES(self), 0x1624);
        motB = EM_RES_REC(EM_RES(self), 0x1628);
        func_002A8578(self, motA, motB, 3, 0.0f, sel, 0);
        self->home.x = 0.0f;
        self->home.y = 0.112f;
        self->home.z = 0.0f;
        self->step++;
    case 3:
        self->pos->y += self->home.y * self->speedRate;
        self->home.y -= self->speedRate * 0.007f;
        if (self->home.y <= 0.0f) {
            self->step = 6;
            from.y += 0.5f;
            to.y = self->pos->y - 10.0f;
            if (ChkLine(&from, &to, &floor, 0, LINE_FLOOR, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                if (self->pos->y <= floor.y + 0.01f) {
                    self->pos->y = floor.y;
                    self->step = 4;
                }
            }
        } else {
            VU0_SQC2_VF0_MEM(&ceiling, 0);
            to.y = self->pos->y + 10.0f;
            if (ChkLine(&from, &to, &ceiling, 0, LINE_CEILING, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                top = ceiling.y - 1.5f;
                if (top < self->pos->y) {
                    self->pos->y = top;
                    self->home.y = 0.0f;
                }
            }
        }
        self->emFlags |= EMFLAG_AIRBORNE;
        player = Getplayer();
        cGameObj_SetTgtTurn((char *)self, player->pos, self->speedRate * 0.19634955f);
        self->motionFlags |= 8;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 4:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(EM_RES(self), 0x162C);
        motB = EM_RES_REC(EM_RES(self), 0x1630);
        func_002A8578(self, motA, motB, 3, 0.0f, sel, 0);
        self->step++;
    case 5:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 6:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        motA = EM_RES_REC(EM_RES(self), 0x1634);
        motB = EM_RES_REC(EM_RES(self), 0x1638);
        self->unk5F8 = 1;
        self->timerC = 1;
        func_002A8578(self, motA, motB, 3, 0.0f, sel, 0);
        self->step++;
    case 7:
        if (self->seqFlags & 0x10) {
            self->pos->y += self->home.y * self->speedRate;
            self->home.y -= self->speedRate * 0.007f;
            if (self->home.y <= 0.0f) {
                from.y += 0.5f;
                to.y = self->pos->y - 10.0f;
                if (ChkLine(&from, &to, &floor, 0, LINE_FLOOR, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    if (self->pos->y <= floor.y + 0.01f) {
                        self->pos->y = floor.y;
                        self->step = 4;
                    }
                }
            } else {
                VU0_SQC2_VF0_MEM(&ceiling, 0);
                to.y = self->pos->y + 10.0f;
                if (ChkLine(&from, &to, &ceiling, 0, LINE_CEILING, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    top = ceiling.y - 1.5f;
                    if (top < self->pos->y) {
                        self->pos->y = top;
                        self->home.y = 0.0f;
                    }
                }
            }
        }
        self->emFlags |= EMFLAG_AIRBORNE;
        cGameObj_SetTgtTurn((char *)self, &self->unk16A0, self->speedRate * 0.19634955f);
        self->motionFlags |= 8;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    if (self->seqFlags & 1) {
        if (self->unk5F8 != 0) {
            self->unk5F8 = 0;
            rec = func_0026AA30(self, SE_JUMP_STEP);
            if (rec != 0) {
                func_0026B240(self, rec, SE_JUMP_STEP, 0xA);
            }
        }
    } else {
        self->unk5F8 = 1;
    }
    if (self->seqFlags & 2) {
        if (self->timerC != 0) {
            self->timerC = 0;
            rec = func_0026AA30(self, SE_JUMP_STEP);
            if (rec != 0) {
                func_0026B240(self, rec, SE_JUMP_STEP, 0x10);
            }
        }
    } else {
        self->timerC = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00216078);
#endif
