/* NON_MATCHING func_0026F328 (sn-2.95.3-136): 71 differing words, all from one swap:
 * retail keeps self in s1 and &me in s2, here they are the other way round. Branch
 * layout and code are otherwise the same. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#define SEE_EYE_HEIGHT    1.0f
#define SEE_FLAG_PLAYER   0x200000
#define SEE_HIT_MASK      0x10

/* An enemy with its sight flags. */
typedef struct cEmSight {
    cGameObj base;
    char unk5AC[0x16D0 - 0x5AC];
    unsigned int sight;         /* 0x16D0 SEE_FLAG_* */
} cEmSight;

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Whether the enemy sees the player, kept in its sight flags. Some kinds always see. */
__attribute__((section(".text.func_0026F328")))
int func_0026F328(cEmSight *self)
{
    cVec me;
    cVec pl;

    switch (self->base.emNo) {
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
        self->sight |= SEE_FLAG_PLAYER;
        return 1;
    }
    VU0_SQC2_VF0_MEM(&me, 0);
    VU0_SQC2_VF0_MEM(&pl, 0);
    cVec_copy3(&me, self->base.pos);
    me.y += SEE_EYE_HEIGHT;
    cVec_copy3(&pl, Getplayer()->pos);
    pl.y += SEE_EYE_HEIGHT;
    if (ChkLine(&me, &pl, 0, 0, 1, SEE_HIT_MASK, 0, 0, 0, 0, 0, 0, 1) == 1) {
        self->sight &= ~SEE_FLAG_PLAYER;
        return 0;
    }
    self->sight |= SEE_FLAG_PLAYER;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026F328);
#endif
