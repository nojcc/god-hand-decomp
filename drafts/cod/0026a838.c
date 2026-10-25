/* NON_MATCHING func_0026A838 (sn-2.95.3-136; c_flags_add -f=-ffast-math, fp_hazard_rules fdiv):
 * 13 instructions differ, all around the sqrt.s: retail loads playerDist, pads two nops and
 * takes the root before any constant load, as a volatile sqrt.s would. EmThrower is the
 * record 001a6098.c also uses (EmThrower_throwHeld), and needs one shared header. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cOm60.h"
#include "godhand/cVec.h"
#include "godhand/rand.h"

typedef struct EmThrower {
    char unk000[0x80];
    float mtx[16];                      /* 0x080 */
    char unk0C0[0x618 - 0x0C0];
    float playerDist;                   /* 0x618 */
    char unk61C[0x6E4 - 0x61C];
    cOm60 *held[3];                     /* 0x6E4 */
} EmThrower;

extern void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v);
extern void cOm60_setThrow(cOm60 *self, cVec *dir, float speed);

/* Let go of held object no: throw it forward, faster the farther the player is. */
void func_0026A838(EmThrower *self, int no)
{
    cVec dir;
    cOm60 *obj;
    float side;
    float up;
    float fwd;

    CVEC_ZERO(dir);
    obj = self->held[no];
    if (obj != 0) {
        self->held[no] = 0;
        fwd = (__builtin_sqrtf(self->playerDist) - 3.0f) * 0.02f;
        if (fwd < 0.05f) {
            fwd = 0.05f;
        }
        side = fRand1_1() * 0.02f;
        up = fRand1_1() * 0.01f + 0.3f;
        dir.x = side;
        dir.y = up;
        dir.z = fwd;
        capVu0ApplyMatrixXYZ(&dir, self->mtx, &dir);
        cOm60_setThrow(obj, &dir, 150.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026A838);
#endif
