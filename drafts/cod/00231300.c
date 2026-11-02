/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/angle.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"

/* The enemy numbers that use the second set of motion records. */
#define EM_CASE_ALT_MOTIONS \
    case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225: \
    case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: \
    case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A

#define EMFLAG_APPROACH     0x40400
#define PI_F                3.1415927f
#define TURN_FAST           0.19634955f /* pi / 16 per frame */
#define TURN_SLOW           0.049087387f /* pi / 64 per frame */
#define FACING_MAX          0.5235988f  /* 30 degrees */
#define STEP_GIVE_UP        10

/* NON_MATCHING: two instructions differ in the facing check; retail copies
 * the turn angle out of the return register before comparing it with zero and
 * negates that copy. Builds with the SN assembler (as: sn). */

#ifdef NON_MATCHING
/* Approach-and-strike phase machine: walk up to the player, strike when
 * close and facing it, maybe follow up with a second strike (chance set by
 * stepArg), and give up after 300 frames or when the player gets away. */
__attribute__((section(".text.func_00231300")))
void func_00231300(cEm00 *self)
{
    unsigned short sel;
    int motA;
    int motB;
    float start;
    float turn;
    float angle;
    cVec *pos;
    unsigned int chance;

    switch (self->step) {
    case 0:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            motA = EM_RES_REC(self->resource, 0x73C);
            motB = EM_RES_REC(self->resource, 0x740);
            break;
        EM_CASE_ALT_MOTIONS:
            motA = EM_RES_REC(self->resource, 0x1218);
            motB = EM_RES_REC(self->resource, 0x121C);
            break;
        }
        func_002A8578((int)self, motA, motB, 10, 0.0f, sel, 0);
        self->stepArg = 0;
        self->step++;
        /* fallthrough */
    case 1:
        self->emFlags |= EMFLAG_APPROACH;
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * TURN_FAST);
        if (moveMotion(self) != 0) {
            self->step++;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            motA = EM_RES_REC(self->resource, 0x744);
            motB = EM_RES_REC(self->resource, 0x748);
            break;
        EM_CASE_ALT_MOTIONS:
            motA = EM_RES_REC(self->resource, 0x1220);
            motB = EM_RES_REC(self->resource, 0x1224);
            break;
        }
        func_002A8578((int)self, motA, motB, 10, 0.0f, sel, 0);
        self->timer = 300.0f;
        self->step++;
        /* fallthrough */
    case 3:
        self->emFlags |= EMFLAG_APPROACH;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        switch (self->emNo) {
        default:
            cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * TURN_SLOW);
            if (self->playerDist < 1.44f) {
                pos = self->pos;
                turn = Turn_dest((float *)pos, (float *)Getplayer()->pos, self->rot.y, PI_F);
                if (turn < 0.0f) {
                    angle = -turn;
                } else {
                    angle = turn;
                }
                if (angle < FACING_MAX) {
                    self->step = 4;
                }
            }
            break;
        EM_CASE_ALT_MOTIONS:
            if (self->playerDist < 2.25f) {
                self->step = 4;
            }
            break;
        }
        if (self->playerDist > 225.0f) {
            self->step = STEP_GIVE_UP;
        }
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            self->step = STEP_GIVE_UP;
        }
        if (self->unk16EC > 0) {
            self->step = STEP_GIVE_UP;
        }
        break;
    case 4:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            motA = EM_RES_REC(self->resource, 0x74C);
            motB = EM_RES_REC(self->resource, 0x750);
            self->timerA = 7;
            self->timerB = 0;
            StoreMotionParamsBoth_2609A8((char *)self, 0x3E7, 0x11, 0x4E, -1, 0);
            start = 0.0f;
            break;
        EM_CASE_ALT_MOTIONS:
            StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0x1C, 0x3E, -1, 0);
            motA = EM_RES_REC(self->resource, 0x1230);
            motB = EM_RES_REC(self->resource, 0x1234);
            start = 5.0f;
            self->timerB = 1;
            self->timerA = 0;
            break;
        }
        func_002A8578((int)self, motA, motB, 3, start, sel, 0);
        switch (self->stepArg) {
        case 0:
            chance = 7;
            break;
        case 1:
            chance = 5;
            break;
        case 2:
            chance = 3;
            break;
        case 3:
            chance = 1;
            break;
        default:
            chance = 0;
            break;
        }
        if ((unsigned int)irand() % 10 < chance) {
            self->unk5F8 = 1;
        } else {
            self->unk5F8 = 0;
        }
        self->step++;
        /* fallthrough */
    case 5:
        if (self->atkHit->attacker != 0) {
            self->timerB = 1;
        }
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * TURN_FAST);
        }
        if (moveMotion(self) != 0) {
            switch (self->emNo) {
            default:
                if (self->timerB != 0) {
                    self->step = 8;
                } else {
                    func_002705D8(self);
                }
                break;
            EM_CASE_ALT_MOTIONS:
                func_002705D8(self);
                break;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if ((self->moveFlags & 0x10) && self->timerB == 0 && self->unk5F8 != 0) {
            self->step = 6;
        }
        break;
    case 6:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x754), EM_RES_REC(self->resource, 0x758), 3, 0.0f,
                      sel, 0);
        self->step++;
        /* fallthrough */
    case 7:
        if (moveMotion(self) != 0) {
            self->step = 2;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 8:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (irand() & 1) {
            motA = EM_RES_REC(self->resource, 0x75C);
            motB = EM_RES_REC(self->resource, 0x760);
        } else {
            motA = EM_RES_REC(self->resource, 0x764);
            motB = EM_RES_REC(self->resource, 0x768);
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        self->timerA = 7;
        self->step++;
        /* fallthrough */
    case 9:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case STEP_GIVE_UP:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            motA = EM_RES_REC(self->resource, 0x76C);
            motB = EM_RES_REC(self->resource, 0x770);
            break;
        EM_CASE_ALT_MOTIONS:
            motA = EM_RES_REC(self->resource, 0x1228);
            motB = EM_RES_REC(self->resource, 0x122C);
            break;
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        self->step++;
        /* fallthrough */
    case 11:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    func_00260B30(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00231300);
#endif
