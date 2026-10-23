/* NON_MATCHING func_0026B240 (sn-2.95.3-136): the child index test and register use differ. Retail masks the 0/1 result of the index test with andi 0xFF before branching (the same pattern as func_00285C58), and keeps &tmp in s3 across the calls, saving five registers in a 0xC0 frame; ours saves four in 0xB0. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmWeapon.h"
#include "godhand/sceVu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, void *t0, int t1, int t2, int t3);
extern float fRand1_1(void);
extern void cOmWeapon_setThrow(cOmWeapon *self, cVec *v, int n);
extern char D_005FEE00[];

static __inline__ unsigned char hasChild(cOmBase *b, int *frame, int idx)
{
    int n;

    *frame = n = b->childNum;
    return idx >= 0 && idx < n;
}

/* Throw weapon at the player from the enemy's child idx: aim at a jittered point 1.5 above the player, with a
 * faster throw on game level 5. id is the weapon's model id and is not read. */
__attribute__((section(".text.func_0026B240")))
void func_0026B240(cOmBase *self, cOmWeapon *weapon, int id, int idx)
{
    char frame[16]; /* cOmBase_childAt stores the child count here, a dead store retail keeps */
    cVec target;
    cVec dir;
    cVec copy;
    cVec tmp;
    cOmBase *hand;
    float speed;

    if (weapon == 0) {
        return;
    }
    if (hasChild(self, (int *)frame, idx)) {
        hand = self->children[idx];
    } else {
        hand = 0;
    }
    if (hand == 0) {
        return;
    }
    cVec_zero(&target);
    cVec_zero(&dir);
    cVec_copy3(&target, Getplayer()->pos);
    target.x += fRand1_1() * 0.2f;
    target.y += fRand1_1() * 0.2f + 1.5f;
    target.z += fRand1_1() * 0.2f;
    VU0_ZERO_VSUB_XYZ_MEM(&tmp, 0, &target, hand->pos);
    VU0_LQC2_SQC2_MEM(4, &copy, &tmp);
    cVec_copy3(&dir, &copy);
    cVec_unitOf(&tmp, &dir);
    VU0_LQC2_SQC2_MEM(4, &copy, &tmp);
    cVec_copy3(&dir, &copy);
    speed = 0.6f;
    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
        speed = 0.9f;
    }
    VU0_VSCALE_XYZ_MEM(&dir, 0, speed);
    cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x1E, self, 0, 0, 0, 0);
    cVec_copy3(weapon->base.pos, hand->pos);
    cVec_copy3(&weapon->base.posA, hand->pos);
    cOmWeapon_setThrow(weapon, &dir, (int)self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026B240);
#endif
