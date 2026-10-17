/* libgraph sceGsSetHalfOffset / func_003960D0 (ee-2.9-991111, 136 B): xyoffset1 from the scissor size.
 * Near-miss: same instructions, 26 scheduled differently (retail interleaves the x and y halves). Not registered. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned long u_long;
typedef struct {
    char unk0[0x20];
    u_long xyoffset1;                   /* 0x20 */
    char unk28[0x8];
    u_long scissor1;                    /* 0x30 */
} DrawEnv1;

__attribute__((section(".text.sceGsSetHalfOffset")))
void sceGsSetHalfOffset(DrawEnv1 *draw, short centerx, short centery, short halfoff)
{
    int w, h;
    u_long ofx, ofy;

    w = (draw->scissor1 >> 16) & 0x7FF;
    h = (draw->scissor1 >> 48) & 0x7FF;
    ofx = (u_long)centerx - ((u_long)(w + 1) >> 1);
    ofy = (u_long)centery - ((u_long)(h + 1) >> 1);
    draw->xyoffset1 = (ofx << 4) | ((halfoff ? (ofy << 4) + 8 : (ofy << 4)) << 32);
}
#else
INCLUDE_ASM("asm/nonmatching", sceGsSetHalfOffset);
#endif
