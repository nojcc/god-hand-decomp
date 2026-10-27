/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"

extern unsigned char cOmbb_ckFire(unsigned char *a0);
extern int func_001B8720(char *a0);
extern void MtxInverse(float *dst, float *src);
extern void func_002DBB08(void);

#define BOMB_ACTOR_NUM 2

/* If one of the two bomb actors is burning inside the box in front of
 * enemy self (x and y within 1 and 0.5, z from -0.8 to 3, in the enemy's
 * own frame), offer the player's action button through func_002DBB08.
 * Still differs from retail: retail hoists all six box bounds into $f20..$f25
 * before the loop; here only -1, 1 and -0.8 are hoisted, so 3, -0.5 and 0.5
 * are loaded in the loop and the frame is 0x10 smaller. It matches with
 * -fmove-all-movables, which is not an allowed per-unit flag yet. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_0012A108")))
void func_0012A108(cEm00 *self)
{
    cVec loc;
    float inv[16];
    CVEC_TEMPS;
    unsigned int i;
    cEmActor *actor;

    if (self->unk6A0 != 0) {
        return;
    }
    for (i = 0; i < BOMB_ACTOR_NUM; i++) {
        actor = func_002948C8(&D_005864F0, i);
        if (actor == 0) {
            continue;
        }
        if (cOmbb_ckFire((unsigned char *)actor) == 0) {
            continue;
        }
        CVEC_ZERO(loc);
        MtxInverse(inv, self->mtx);
        CVEC_SET_APPLY(loc, inv, (cVec *)func_001B8720((char *)actor));
        if (loc.x < -1.0f || 1.0f < loc.x) {
            continue;
        }
        if (loc.z < -0.8f || 3.0f < loc.z) {
            continue;
        }
        if (loc.y < -0.5f || 0.5f < loc.y) {
            continue;
        }
        func_002DBB08();
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012A108);
#endif
