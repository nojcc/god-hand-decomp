/* sn-2.95.3-136 */
/* ColiseumBattle_ApplyRingRules (as: sn). Still differs: retail keeps the
 * new hpMax in $v1 and the ring's life in $a0 where this swaps them, and
 * retail pads only the last of its three divides with two nops. */
#include "include_asm.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

#ifdef NON_MATCHING
extern char *D_003BD6E8;
extern void cCockPlBar_initData(int a0);

/* Applies the ring's rules: the player's life and heat gauge levels and
 * starting amounts, the reel and god item counts and the game level. */
__attribute__((section(".text.ColiseumBattle_ApplyRingRules")))
void ColiseumBattle_ApplyRingRules(ColiseumBattle *self)
{
    cGameObj *pl;
    int hp;
    float heatMax;
    int i;

    pl = Getplayer();
    if (pl != 0) {
        if (self->ring.vitalLv != -1) {
            cCoreSave_setState154(&D_00569B70, self->ring.vitalLv);
            pl->hpMax = self->ring.vitalLv * 20 + 100;
            hp = self->ring.vitalPct;
            if (hp >= pl->hpMax) {
                pl->hp = pl->hpMax;
            } else {
                pl->hp = hp;
            }
        } else {
            hp = pl->hpMax * (self->ring.vitalPct / 100.0f);
            if (hp >= pl->hpMax) {
                pl->hp = pl->hpMax;
            } else {
                pl->hp = hp;
            }
        }
        if (self->ring.heatLv != -1) {
            cCoreSave_setState155(&D_00569B70, self->ring.heatLv);
            heatMax = self->ring.heatLv * 30 + 120;
            cHeatSys_UpdateHeatMax(&D_005CB000, heatMax);
            cHeatSys_SetHeatGage(&D_005CB000, heatMax * (self->ring.heatPct / 100.0f));
        } else {
            cHeatSys_SetHeatGage(&D_005CB000, D_005CB000.max * (self->ring.heatPct / 100.0f));
        }
    }
    if (self->ring.statLv != -1) {
        cCoreSave_setReelItemNum(&D_00569B70, self->ring.statLv);
    }
    cCoreSave_clearGodItem(&D_00569B70);
    for (i = 0; i < self->ring.godItemNum; i++) {
        cCoreSave_addGodItem(&D_00569B70, 1);
    }
    cCoreSave_setGameLevel(&D_00569B70, self->ring.gameLevel);
    cCockPlBar_initData((int)(D_003BD6E8 + 0x460));
}
#else
INCLUDE_ASM("asm/nonmatching", ColiseumBattle_ApplyRingRules);
#endif
