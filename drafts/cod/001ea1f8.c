/* NON_MATCHING: 392 of 398 words. In case 0 the dog pointer is set before the two vector addresses instead of after them, and two null checks jump past the next check on the same object, where retail reloads it and tests again. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/DogRace.h"
#include "godhand/cOm71.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/classFADE.h"
#include "godhand/gameWork.h"
#include "godhand/menuKey.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"

/* The GameWork a GameSys sits in (D_00747A2C gives D_007474A0); retail forms it
 * this way. Kept here, not in gameWork.h: it is a container cast (not an upcast),
 * so it needs an answer before it can go into a header. */
static __inline__ GameWork *GameSys_work(GameSys *sys)
{
    return (GameWork *)((char *)sys - 0x58C);
}

#ifdef NON_MATCHING
/* The bet step: fade in on the five dogs, pick one, stake gold in DOGRACE_BET_STEP, then fade out to the race (or back). */
__attribute__((section(".text.func_001EA1F8")))
void func_001EA1F8(DogRace *self)
{
    int i;
    int n;
    cVec v;
    DogRaceDog *dog;
    GameWork *gw;

    switch (self->phase) {
    case 0:
        self->sel = 0;
        for (dog = self->dog, i = 0; i < DOGRACE_DOG_NUM; i++, dog++) {
            CVEC_COPY(v, &D_005681E0);
            if (dog->obj != 0) {
                cVec *pos = dog->obj->base.pos;
                CVEC_ASSIGN(*pos, &v);
            }
            CVEC_COPY(v, &D_005681F0);
            if (dog->obj != 0) {
                cVec *rot = &dog->obj->base.rot;
                CVEC_ASSIGN(*rot, &v);
            }
            if (dog->obj != 0) {
                cOm71_SetMotionWait(dog->obj);
            }
            if (i == self->sel) {
                if (dog->obj != 0) {
                    dog->obj->base.objFlags &= 0xFFFFFFFDU;
                }
            } else {
                if (dog->obj != 0) {
                    dog->obj->base.objFlags |= CMODEL_F_SHOWN;
                }
            }
            if (dog->obj != 0) {
                dog->obj->flags |= 4;
            }
            self->dog[i].obj->flags |= COM71_F_NO_NULL_SPEED;
        }
        classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0, 15);
        self->phase++;
        break;
    case 1:
        if ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) {
            self->phase++;
        }
        break;
    case 2:
        cCoreSave_payGoldOnPress(self);
        gw = GameSys_work(&D_00747A2C);
        if (gw->rep & (MENU_KEY_UP_ALL | MENU_KEY_DOWN_ALL)) {
            if (gw->rep & MENU_KEY_UP_ALL) {
                if (--self->sel < 0) {
                    self->sel = DOGRACE_DOG_NUM - 1;
                }
            } else if (gw->rep & MENU_KEY_DOWN_ALL) {
                if (++self->sel >= DOGRACE_DOG_NUM) {
                    self->sel = 0;
                }
            }
            for (n = 0; n < DOGRACE_DOG_NUM; n++) {
                cOm71 *obj = self->dog[n].obj;
                int picked = n == self->sel;
                if (obj != 0) {
                    if (picked) {
                        obj->base.objFlags &= 0xFFFFFFFDU;
                    } else {
                        obj->base.objFlags |= CMODEL_F_SHOWN;
                    }
                }
            }
            CustomID_placeByIndexB(&self->result, self->sel);
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
        } else {
            if (gw->trg & MENU_KEY_OK) {
                func_001ED178(&self->result, 1);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                self->phase += 2;
            } else if (gw->trg & MENU_KEY_BACK) {
                classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
                self->phase++;
            }
        }
        break;
    case 3:
        if ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) {
            self->phase = 0;
            self->step = 3;
            self->unk0C = 0;
        }
        break;
    case 4:
        if (D_007474A0.rep & MENU_KEY_UP_ALL) {
            if (self->bet < self->odds && cCoreSave_getGold(&D_00569B70) >= DOGRACE_BET_STEP) {
                cCoreSave_subGold(&D_00569B70, DOGRACE_BET_STEP);
                self->bet += DOGRACE_BET_STEP;
                CustomID_setArrowDisp(&self->result, self->bet);
                func_001ED490(&self->result, cCoreSave_getGold(&D_00569B70));
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            }
        } else if (D_007474A0.rep & MENU_KEY_DOWN_ALL) {
            if (self->bet > 0) {
                cCoreSave_addGold(&D_00569B70, DOGRACE_BET_STEP, 0);
                self->bet -= DOGRACE_BET_STEP;
                CustomID_setArrowDisp(&self->result, self->bet);
                func_001ED490(&self->result, cCoreSave_getGold(&D_00569B70));
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
            }
        } else if (D_007474A0.trg & MENU_KEY_OK) {
            if (self->bet > 0) {
                cSnd_BattleBgmAllPause(&D_005FEE00, 20.0f);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
                classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
                self->phase++;
            } else {
                cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            }
        } else if (D_007474A0.trg & MENU_KEY_BACK) {
            cCoreSave_addGold(&D_00569B70, self->bet, 0);
            self->bet = 0;
            CustomID_setArrowDisp(&self->result, 0);
            func_001ED490(&self->result, cCoreSave_getGold(&D_00569B70));
            cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
            func_001ED178(&self->result, 0);
            self->phase -= 2;
        }
        break;
    case 5:
        if ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) {
            self->phase = 0;
            self->step = 1;
            self->unk0C = 0;
        }
        break;
    }
    func_001ECBF0(&self->result);
    func_001ECC48(&self->result);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EA1F8);
#endif
