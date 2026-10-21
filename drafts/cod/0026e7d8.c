/* NON_MATCHING func_0026E7D8 (sn-2.95.3-136, call-loop pad): 79 differing words. Retail
 * keeps self in s2 and &dest in s3 (built in a1 first) and writes spot[1]'s y, z and w
 * through a pointer; here self and &dest swap s-registers and the stores are sp-relative. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#define EM_NO_RETREATER      0x211
#define RETREAT_NEAR_DIST    16.0f
#define EMFLAG2_NO_RETREAT   0x20
#define RETREAT_SPREAD       6.0f
#define RETREAT_SPEED        120.0f
#define GOTO_RETREAT_MODE    0xE

extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float fRand1_1(void);
extern void cEm00_setGoto(cEm00 *self, cVec *pos, int a2, int a3, float f);

/* Sends the retreating enemy kind to whichever of its two fixed spots is farther from
 * the player, with a little random spread, once the player comes close. Returns 1 if
 * it set the goto up. */
__attribute__((section(".text.func_0026E7D8")))
int func_0026E7D8(cEm00 *self)
{
    cVec spot[2];
    cVec dest;
    float far;
    float d;
    cVec *s;
    unsigned int i;

    if ((self->emNo ^ EM_NO_RETREATER) != 0) {
        return 0;
    }
    if (RETREAT_NEAR_DIST < self->playerDist) {
        return 0;
    }
    if (self->emFlags2 & EMFLAG2_NO_RETREAT) {
        return 0;
    }
    cVec_set4(&spot[0], -0.5f, 0.0f, -11.0f, 1.0f);
    cVec_set4(&spot[1], -1.8f, 0.0f, -32.0f, 1.0f);
    VU0_SQC2_VF0_MEM(&dest, 0);
    cVec_copy3(&dest, spot);
    far = 0.0f;
    for (i = 0, s = spot; i < 2; i++, s++) {
        d = capVu0MagnitudeSqXZ(Getplayer()->pos, s);
        if (!(d < far)) {
            far = d;
            cVec_copy3(&dest, s);
        }
    }
    dest.x += fRand1_1() * RETREAT_SPREAD;
    dest.z += fRand1_1() * RETREAT_SPREAD;
    cEm00_setGoto(self, &dest, GOTO_RETREAT_MODE, 1, RETREAT_SPEED);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026E7D8);
#endif
