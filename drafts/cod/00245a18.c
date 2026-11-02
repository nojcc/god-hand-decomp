/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCoreSave.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/angle.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"

#define EMFLAG_SPIN_FX          0x100000
#define TURN_FAST               0.19634955f /* pi / 16 per frame */
#define TURN_SLOW               0.049087387f /* pi / 64 per frame */
#define EM_NEAR                 16.0f

/* Spinning attack phase machine: wind up turning to the player, then either
 * a close lunge (half the time when near) or a spin of 2, 3 or 5 turns by
 * difficulty, drifting at a speed picked per spin; the lunge homes on the
 * player for a time that shrinks with the difficulty.
 * Byte-identical to retail, but only with the lunge effect started from two
 * identical if/else arms on the difficulty, and with the difficulty switches
 * listing every level as its own case (so cc1 builds retail's tables). */
#ifdef NON_MATCHING
__attribute__((section(".text.func_00245A18")))
void func_00245A18(cEm00 *self)
{
    unsigned int n;
    unsigned int i;
    int motA;
    int motB;
    float turn;
    cVec *from;
    cVec *to;

    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x3538),
                      EM_RES_REC(self->resource, 0x353C), 3, 0.0f, 0, 0);
        InitRenderStruct_2A8608((cGameObj *)self, 0x77, (void *)8, 0, 2, (void *)self->fx5);
        self->timer = 15.0f;
        self->step++;
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * TURN_FAST);
        self->hitFlash = 3.0f;
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->moveFlags & 1) {
            if (self->playerDist < EM_NEAR && (irand() & 1)) {
                self->step = 4;
                break;
            }
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            case 1:
                n = 2;
                break;
            default:
                n = 2;
                break;
            case 2:
                n = 3;
                break;
            case 3:
                n = 5;
                break;
            case 4:
                n = 5;
                break;
            case 5:
                n = 5;
                break;
            }
            self->stepArg = irand() % n;
            for (i = 0; i < n; i++) {
                if (self->stepArg != i) {
                    func_00260890(self, i);
                }
            }
            self->step = 2;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            case 1:
                self->idleTimer = 1800.0f;
                break;
            default:
                self->idleTimer = 1800.0f;
                break;
            case 2:
                self->idleTimer = 1350.0f;
                break;
            case 3:
                self->idleTimer = 1350.0f;
                break;
            case 4:
                self->idleTimer = 1350.0f;
                break;
            case 5:
                self->idleTimer = 900.0f;
                break;
            }
        }
        break;
    case 2:
        switch (self->stepArg) {
        case 0:
            self->timer = 0.0f;
            break;
        default:
            self->timer = 0.0f;
            break;
        case 1:
            self->timer = 0.2f;
            break;
        case 2:
            self->timer = -0.2f;
            break;
        case 3:
            self->timer = 0.4f;
            break;
        case 4:
            self->timer = -0.4f;
            break;
        }
        if (self->emFlags2 & EMFLAG_SPIN_FX) {
            InitRenderStruct_2A8608((cGameObj *)self, 0x77, (void *)9, 0, 2, (void *)self->fx5);
        }
        self->timer2 = 30.0f;
        self->step++;
        /* fallthrough */
    case 3:
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * TURN_SLOW);
        self->hitFlash = 3.0f;
        if (moveMotion(self) != 0) {
            func_002A8578((int)self, EM_RES_REC(self->resource, 0x3418),
                          EM_RES_REC(self->resource, 0x341C), 3, 0.0f, 0, 0);
        }
        self->stepVec.x = self->timer * self->speedRate;
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer2 -= self->speedRate;
        if (self->timer2 <= 0.0f) {
            func_002705D8(self);
        }
        break;
    case 4:
        motA = EM_RES_REC(self->resource, 0x3544);
        motB = EM_RES_REC(self->resource, 0x3548);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            motB = EM_RES_REC(self->resource, 0x354C);
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, 0, 0);
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            InitRenderStruct_2A8608((cGameObj *)self, 0x77, (void *)0xA, 0, 2, (void *)self->fx5);
        } else {
            InitRenderStruct_2A8608((cGameObj *)self, 0x77, (void *)0xA, 0, 2, (void *)self->fx5);
        }
        self->timerA = 15;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 5:
            break;
        default:
        case 1:
            self->timerA = (int)(self->timerA * 0.75f);
            break;
        case 2:
            self->timerA = (int)(self->timerA * 0.8f);
            break;
        case 3:
        case 4:
            self->timerA = (int)(self->timerA * 0.9f);
            break;
        }
        self->timer = self->rot.y;
        self->step++;
        /* fallthrough */
    case 5:
        if (self->timerA != 0) {
            self->timerA--;
            from = self->pos;
            to = Getplayer()->pos;
            turn = Turn_dest((float *)from, (float *)to, self->timer, self->speedRate * TURN_FAST);
            self->timer += turn;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += turn;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->unk1864 == 0) {
            func_00260B30(self);
        }
        break;
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00245A18);
#endif
