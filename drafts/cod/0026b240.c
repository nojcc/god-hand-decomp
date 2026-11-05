/* NON_MATCHING func_0026B240 (sn-2.95.3-136): register use differs. Retail keeps &tmp in s3 across the calls, saving five registers in a 0xC0 frame; ours saves four in 0xB0, so every stack offset after the prologue differs. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/sceVu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/player.h"
#include "godhand/cSnd.h"

extern float fRand1_1(void);
extern void cOmWeapon_setThrow(cOmWeapon *self, cVec *v, int n);

/* Throw weapon at the player from the enemy's child idx: aim at a jittered point 1.5 above the player, with a
 * faster throw on game level 5. type is the weapon's model id and is not read. */
__attribute__((section(".text.func_0026B240")))
void func_0026B240(cEm00 *self, cOmWeapon *weapon, int type, int idx)
{
    int frame[3];
    cVec target;
    cVec dir;
    cVec copy;
    cVec tmp;
    cOmBase *hand;
    float speed;

    if (weapon == 0) {
        return;
    }
    hand = cOmBase_childAtIdx((cOmBase *)self, frame, idx);
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
    cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x1E, self, 0, 0, 0, 0);
    cVec_copy3(weapon->base.pos, hand->pos);
    cVec_copy3(&weapon->base.posA, hand->pos);
    cOmWeapon_setThrow(weapon, &dir, (int)self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026B240);
#endif
