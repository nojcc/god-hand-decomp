/* NON_MATCHING func_001C20D8 (sn-2.95.3-136): 43 differing words. Retail stores the two
 * position copies with memory-operand sqc2 (0x30(sp), 0x40(sp)); vu0.h has that form only
 * for $vf0, and with a memory-operand VU0_SQC2_MEM the prologue and vector part match.
 * What is left is s0/s1 for self and the player position, and the tail's return layout. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/vu0.h"


#define EM_SIGHT_FLAGS(self)    (*(unsigned char *)((char *)(self) + 0x676))
#define EM_SIGHT_LINE           0x01    /* also needs a clear line to the player */
#define EM_SIGHT_FAR            0x04    /* uses the far range */

#define EM_SIGHT_NEAR_SQ        4.0f
#define EM_SIGHT_FAR_SQ         16.0f
#define EM_SIGHT_SMALL_SQ       1.0f
#define EM_SIGHT_EYE_HEIGHT     0.5f

extern float capVu0LengthSq(void *v);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* out = a - b (xyz), through the work vectors f[0] and f[1]. */
static __inline__ void cVec_sub3(cVec *out, cVec *a, cVec *b, cVec *f)
{
    VU0_ZERO_VSUB_XYZ_MEM(f, 0x10, a, b);
    VU0_LQC2(4, &f[1], 0);
    VU0_SQC2(4, f, 0);
    cVec_copy3(out, &f[0]);
}

/* True when the player is within the enemy's sight range and, if the enemy
 * asks for it, nothing blocks the line between them. */
__attribute__((section(".text.func_001C20D8")))
int func_001C20D8(cEm00 *self)
{
    cVec me __attribute__((aligned(16)));
    cVec pl __attribute__((aligned(16)));
    cVec d __attribute__((aligned(16)));
    cVec f[2] __attribute__((aligned(16)));
    cGameObj *player;
    float range;
    long flags;

    VU0_LQC2(4, CEM00_VCALL0(self, getPos), 0);
    VU0_SQC2(4, &me, 0);
    player = Getplayer();
    VU0_LQC2(4, ((cVec *(*)(void *))cGameObj_vt(player)->lockOn)((char *)player + cGameObj_vt(player)->lockOnDelta), 0);
    VU0_SQC2(4, &pl, 0);
    VU0_SQC2_VF0_MEM(&d, 0);
    pl.y += EM_SIGHT_EYE_HEIGHT;
    cVec_sub3(&d, &me, &pl, f);
    flags = EM_SIGHT_FLAGS(self);
    range = EM_SIGHT_NEAR_SQ;
    if (((flags >> 2) & 1) == 1) {
        range = EM_SIGHT_FAR_SQ;
    }
    switch (self->actorId) {
    case 0x3EC:
    case 0x3ED:
        range = EM_SIGHT_SMALL_SQ;
        break;
    }
    if (capVu0LengthSq(&d) < range) {
        if (!(EM_SIGHT_FLAGS(self) & EM_SIGHT_LINE)) {
            return 1;
        }
        if (ChkLine(&me, &pl, 0, 0, 7, 0x204, 0, 0, 0, 0, 0, 0, 1) == 0) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C20D8);
#endif
