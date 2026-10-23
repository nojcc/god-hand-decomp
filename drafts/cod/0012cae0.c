/* NON_MATCHING func_0012CAE0 (sn-2.95.3-136): one word long. Retail returns 1 from the
 * register that held the 1 stored to mode; this loads 1 again before the return. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cSceAtManager.h"
#include "godhand/gameWork.h"

#define HIT_WAIT        90.0f
#define HIT_EFFECT      0x4B
#define HIT_DAMAGE      25
#define GAMESYS_NO_HIT  3

extern int SetEffect(int kind, int id, void *owner, void *param, int handle, unsigned int owner2);

/* Check whether the enemy stands in a hit unit; on a hit take 25 points, never
 * dropping below 1 (enemies with 10 or less are set to 0), and start the
 * damage state. Returns 1 on a hit. */
__attribute__((section(".text.func_0012CAE0")))
int func_0012CAE0(cEm00 *self)
{
    unsigned long f;
    unsigned long bit;
    int hit;

    if (0.0f < self->hitWait) {
        return 0;
    }
    if (0.0f < self->hitFlash) {
        return 0;
    }
    f = D_00747A2C.unk00;
    bit = f >> GAMESYS_NO_HIT & 1;
    if (bit == 0) {
    hit = FindNodeByHit_2C2490(&D_005FEA60, self->pos, &self->hitPos.x);
    if (hit != 1) {
        return 0;
    }
    self->hitWait = HIT_WAIT;
    if (D_00747A2C.unk25 == 5) {
        SetEffect(0, HIT_EFFECT, self, 0, -1, 0xFFFFFFFF);
    }
    if (self->vital > 10) {
        self->vital -= HIT_DAMAGE;
        if (self->vital <= 0) {
            self->vital = 1;
        }
    } else {
        self->vital = 0;
    }
    self->mode = 1;
    self->phase = 7;
    self->stepArg = 0;
    self->step = 0;
    return 1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012CAE0);
#endif
