/* NON_MATCHING: 19 words differ. Retail passes func_001EB718 the eye and target as by-reference temporaries whose addresses are taken before the copies; with the pending CVEC_TEMP_COPY shape (decisions row for DogRace_Load) that part matches and 11 words are left, where the null check after the rot assignment jumps past the next check on the same object instead of reloading it, as in func_001EA1F8. */
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
#include "godhand/cCamera.h"

/* D_007474A0.flags5E0 under its own symbol: retail stores it through %lo(D_00747A80). */
extern unsigned int D_00747A80;

#ifdef NON_MATCHING

static __inline__ unsigned char DogRace_wait(DogRace *self)
{
    if (self->timer != 0) {
        self->timer--;
        return 0;
    }
    return 1;
}

/* The result step: show the picked dog winning or losing, play the result music, count the payout into the gold total, then fade back to the menu. */
__attribute__((section(".text.func_001EB030")))
void func_001EB030(DogRace *self)
{
    int i;
    int sel;
    int j;
    int k;
    cVec eye;
    cVec target;
    unsigned int flags;

    switch (self->phase) {
    case 0:
        flags = D_00747A80;
        flags |= 0x04000000;
        flags |= 0x02000000;
        flags |= 0x40000000;
        flags |= 0x80000000;
        flags |= 0x200000;
        flags |= 0x10000000;
        flags |= 0x08000000;
        D_00747A80 = flags;
        CVEC_COPY(eye, &D_00568200);
        CVEC_COPY(target, &D_00568210);
        func_001EB718(self, &eye, &target);
        for (i = 0; i < DOGRACE_DOG_NUM; i++) {
            if (i == self->sel) {
                CVEC_COPY(eye, &D_005681E0);
                if (self->dog[i].obj != 0) {
                    cVec *pos = self->dog[i].obj->base.pos;
                    CVEC_ASSIGN(*pos, &eye);
                }
                sel = self->sel;
                CVEC_COPY(eye, &D_005681F0);
                if ((self->dog + sel)->obj != 0) {
                    cVec *rot = &(self->dog + sel)->obj->base.rot;
                    CVEC_ASSIGN(*rot, &eye);
                }
                if ((self->dog + self->sel)->obj != 0) {
                    (self->dog + self->sel)->obj->base.objFlags &= 0xFFFFFFFDU;
                }
                if ((self->dog + self->sel)->obj != 0) {
                    (self->dog + self->sel)->obj->flags |= 4;
                }
                (self->dog + self->sel)->obj->flags |= COM71_F_NO_NULL_SPEED;
                if (self->rank[i] != 0) {
                    if (self->rank[0]->no == self->sel) {
                        if ((self->dog + self->sel)->obj != 0) {
                            cOm71_SetMotion100((self->dog + self->sel)->obj);
                        }
                        self->payout = (self->dog + self->sel)->raceTime * self->bet / 10;
                        func_001EE2A8(&self->ui2, self->payout);
                        func_001EE2C8(&self->ui2, cCoreSave_getGold(&D_00569B70));
                        func_001EE2E8(&self->ui2, 1, 1);
                    } else {
                        if ((self->dog + self->sel)->obj != 0) {
                            cOm71_SetMotion102((self->dog + self->sel)->obj);
                        }
                        self->payout = 0;
                        func_001EE2A8(&self->ui2, 0);
                        func_001EE2C8(&self->ui2, cCoreSave_getGold(&D_00569B70));
                        func_001EE2E8(&self->ui2, 1, 0);
                    }
                }
            } else {
                if (self->dog[i].obj != 0) {
                    self->dog[i].obj->base.objFlags |= CMODEL_F_SHOWN;
                }
            }
        }
        for (j = 0; j < DOGRACE_DOG_NUM; j++) {
            if (self->rank[j]->no == self->sel) {
                func_001EE6C8(&self->ui2, j);
                func_001EE730(&self->ui2, 1);
                break;
            }
        }
        for (k = 0; k < DOGRACE_DOG_NUM; k++) {
            if (self->rank[k] != 0) {
                CustomIDWork_setSlotMessAndPosY(&self->ui2, k, self->rank[k]->no, self->rank[k]->stats.unk00);
            }
        }
        classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0, 15);
        self->phase++;
        break;
    case 1:
        if ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) {
            if (self->rank[0] != 0) {
                if (self->rank[0]->no == self->sel) {
                    cSnd_BgmEventStart(&D_005FEE00, 0x25, 0, 0);
                    cSnd_SeCall(&D_005FEE00, 0, 0x35, &self->cam->eye, 0, 0);
                } else {
                    cSnd_BgmEventStart(&D_005FEE00, 0x24, 0, 0);
                    cSnd_SeCall(&D_005FEE00, 0, 0x38, &self->cam->eye, 0, 0);
                }
            }
            self->timer = 60;
            self->phase++;
        }
        break;
    case 2:
        if (DogRace_wait(self)) {
            self->payoutSteps = self->payout / 10;
            self->phase++;
        }
        break;
    case 3:
        if ((D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) || self->payoutSteps == 0) {
            cCoreSave_addGold(&D_00569B70, self->payoutSteps * 10, 0);
            cCoreSave_initAddGold(&D_00569B70);
            self->payout = 0;
            self->phase++;
        } else {
            cCoreSave_addGold(&D_00569B70, 10, 0);
            self->payout -= 10;
            self->payoutSteps--;
        }
        func_001EE2A8(&self->ui2, self->payout);
        func_001EE2C8(&self->ui2, cCoreSave_getGold(&D_00569B70));
        break;
    case 4:
        if (D_007474A0.trg & (MENU_KEY_OK | MENU_KEY_BACK)) {
            classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, 15);
            self->phase++;
        }
        break;
    case 5:
        if ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1) {
            self->phase = 0;
            self->step = 3;
            self->unk0C = 0;
        }
        break;
    }
    func_001EDF80(&self->ui2);
    func_001EDFD8(&self->ui2);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EB030);
#endif
