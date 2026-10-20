/* NON_MATCHING func_0029FDE0 (sn-2.95.3-136;
 * PARK, 7 diffs): only the loop pre-header order differs; retail sets the i*32+0x1F counter after the hoisted 64-bit constants, ours before.
 * 0x800 sits in a local so loop.c leaves it in the loop. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_0029FDE0: clear the frame buffer to black in 64-pixel scissored strips (GS FRAME/SCISSOR/XYZ packets). */
typedef unsigned long u_long;
typedef unsigned int u_int;

#define GS_SET_FRAME(fbp, fbw, psm, fbmsk) \
    ((u_long)(fbp) | ((u_long)(fbw) << 16) | ((u_long)(psm) << 24) | ((u_long)(fbmsk) << 32))
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u_long)(tbp) | ((u_long)(tbw) << 14) | ((u_long)(psm) << 20) | ((u_long)(tw) << 26) | \
     ((u_long)(th) << 30) | ((u_long)(tcc) << 34) | ((u_long)(tfx) << 35) | ((u_long)(cbp) << 37) | \
     ((u_long)(cpsm) << 51) | ((u_long)(csm) << 55) | ((u_long)(csa) << 56) | ((u_long)(cld) << 61))
#define GS_SET_SCISSOR(x0, x1, y0, y1) \
    ((u_long)(x0) | ((u_long)(x1) << 16) | ((u_long)(y0) << 32) | ((u_long)(y1) << 48))
#define GS_SET_ALPHA(a, b, c, d, fix) \
    ((u_long)(a) | ((u_long)(b) << 2) | ((u_long)(c) << 4) | ((u_long)(d) << 6) | ((u_long)(fix) << 32))
#define GS_SET_UV(u, v) ((u_long)(u) | ((u_long)(v) << 16))
#define GS_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))

extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern int D_003C1180;
extern u_int D_003C11AC;
extern int D_003C11B4;
extern u_int D_003C11C8;
extern int D_00586B80;

__attribute__((section(".text.func_0029FDE0")))
void func_0029FDE0(char *ctx, int p)
{
    int i;
    int c800 = 0x800;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0, 0x306);
    PushEntryAtField10000_299868(ctx, 0x4D,
        GS_SET_FRAME((D_003C11AC + D_003C11C8 * p) >> 5, D_003C1180 / 128, 0, 0));
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41,
            GS_SET_SCISSOR(i * 32, i * 32 + 0x1F, 0, D_003C11B4 - 1));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((c800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ(0x8000, (D_00586B80 + D_003C11B4) << 4, 0xFFFF));
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0029FDE0);
#endif
