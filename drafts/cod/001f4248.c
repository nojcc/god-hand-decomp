/* sn-2.95.3-136 */
/* func_001F4248 (fp_hazard_rules mtc1,fdiv). Still differs: retail passes
 * cCoreSave_getReelItem's int to func_001F5650's short `num` without
 * narrowing it, which only a declaration that disagrees with the
 * definition gives; and the life percent clamp swaps $f0 and $f1. */
#include "include_asm.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/CustomIDWork.h"
#include "godhand/CustomIDPanel.h"
#include "godhand/ColiseumEmSelect.h"

#ifdef NON_MATCHING

/* Shows the ring's rules on the status panel: life and heat gauge sizes and
 * starting amounts (the player's own where the ring leaves them alone), reel
 * items and god items. A locked ring shows only the frame. */
__attribute__((section(".text.func_001F4248")))
void func_001F4248(ColiseumEmSelect *self)
{
    short vitalMax;
    short vital;
    short heatMax;
    short heat;
    float pct;
    int num;

    if (func_001F4530(self, self->ring.ringNo, self->ring.unk04) != 0) {
        if (self->ring.vitalLv != -1) {
            vitalMax = self->ring.vitalLv * 20 + 100;
            vital = self->ring.vitalPct;
        } else {
            vitalMax = cCoreSave_getVitalMax(&D_00569B70);
            pct = self->ring.vitalPct;
            if (pct > 100.0f) {
                pct = 100.0f;
            }
            vital = (int)(pct / 100.0f * vitalMax);
        }
        if (self->ring.heatLv != -1) {
            heatMax = self->ring.heatLv * 30 + 120;
            heat = (int)self->ring.heatPct;
        } else {
            heatMax = (int)D_005CB000.max;
            pct = self->ring.heatPct;
            if (pct > 100.0f) {
                pct = 100.0f;
            }
            heat = (int)(pct / 100.0f * heatMax);
        }
        num = self->ring.statLv;
        if (num == -1) {
            num = cCoreSave_getReelItem(&D_00569B70);
        }
        func_001F5650(&self->idBase, 2, vitalMax, vital, heatMax, heat, num,
                      self->ring.godItemNum);
    } else {
        func_001F5650(&self->idBase, 1, 0, 0, 0, 0, 0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F4248);
#endif
