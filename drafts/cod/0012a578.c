/* NON_MATCHING func_0012A578 (sn-2.95.3-136): point along the player's line from base. Retail moves
 * pl from a1 to a2 at entry and keeps &f.d in a1; ours leaves pl in a1, one instruction shorter. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* The player's live position and the point it is measured from. */
typedef struct PlTrail {
    char unk000[0xF0];
    cVec *pos;                          /* 0x0F0 */
    char unk0F4[0x630 - 0xF4];
    cVec base;                          /* 0x630 */
} PlTrail;

/* The point t times as far from base as the player is, along the same line, written to out. */
cVec *func_0012A578(cVec *out, PlTrail *pl, float t)
{
    struct {
        cVec v;                         /* 0x00 */
        cVec d;                         /* 0x10 */
        cVec tmp;                       /* 0x20 */
    } f;
    cVec *d;

    d = &f.d;
    VU0_SQC2_VF0(&f, 0x00);
    VU0_ZERO_VSUB_XYZ_MEM(&f, 0x20, pl->pos, &pl->base);
    VU0_LQC2(4, &f.tmp, 0);
    VU0_SQC2(4, &f, 0x10);
    cVec_copy3(&f.v, d);
    VU0_VSCALE_XYZ_MEM(&f, 0x00, t);
    VU0_VADD_XYZ_IP(&f, 0x00, pl->pos);
    VU0_LQC2(4, &f, 0);
    VU0_SQC2(4, out, 0);
    return out;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012A578);
#endif
