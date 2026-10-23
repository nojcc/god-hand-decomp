/* NON_MATCHING func_002A0C60 (sn-2.95.3-136): every GS register value is right, but retail keeps the work page 0xE00 in $s4 for the whole function. It ORs 0xE00 into the first TEX0 apart from that register's other constant fields, and builds the second FRAME's base with `srl $s4, $s4, 5`, so the page was not a literal where retail's source used it. Ours folds it, which changes the saved-register assignment throughout. func_0029E2C0 holds 0xE00 the same way. The GS_SET_* macros are copies of the ones in 002a02d0.c until a shared GS header exists. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING

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
#define GS_SET_XYOFFSET(x, y) ((u_long)(x) | ((u_long)(y) << 32))
#define GS_SET_ZBUF(zbp, psm, zmsk) ((u_long)(zbp) | ((u_long)(psm) << 24) | ((u_long)(zmsk) << 32))
#define GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u_long)(wms) | ((u_long)(wmt) << 2) | ((u_long)(minu) << 4) | ((u_long)(maxu) << 14) | \
     ((u_long)(minv) << 24) | ((u_long)(maxv) << 34))
#define GS_SET_TEXA(ta0, aem, ta1) ((u_long)(ta0) | ((u_long)(aem) << 15) | ((u_long)(ta1) << 32))

extern void PushEntryAtField10000_299868(char *a0, long a1, long a2);
extern void func_002998D8(int a0, int a1, long a2);
extern void func_00299908(int a0);
extern void func_00299A28(char *a0, int a1, int *pal);
extern int D_003C1180;
extern int D_003C118C;
extern u_int D_003C11AC;
extern int D_003C11B8;
extern int D_003C1B00[];
extern int D_00586B80;

/* Copies the frame buffer to a work page, uploads a palette at 0x1C04 and draws the
 * screen back as an 8-bit indexed texture through it. */
__attribute__((section(".text.func_002A0C60")))
void func_002A0C60(char *ctx)
{
    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(D_003C11AC >> 5, D_003C1180 / 64, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x19,
        GS_SET_XYOFFSET((0x800 - D_003C1180 / 2) << 4, (0x800 - D_003C118C / 2) << 4));
    PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(0, D_003C1180 - 1, 0, D_003C118C - 1));
    PushEntryAtField10000_299868(ctx, 0x43, GS_SET_ALPHA(2, 2, 2, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x4F, GS_SET_ZBUF(0xF8, 0xA, 1));
    PushEntryAtField10000_299868(ctx, 0x48, 0x30000);
    PushEntryAtField10000_299868(ctx, 9, GS_SET_CLAMP(0, 0, 0x3F0, 0, 0x3F0, 0));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(0xE00, D_003C1180 / 64, 0, 9, D_003C11B8, 1, 1, 0, 0, 1, 0, 2));
    PushEntryAtField10000_299868(ctx, 0x15, 0);
    PushEntryAtField10000_299868(ctx, 0, 0x316);
    PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
    PushEntryAtField10000_299868(ctx, 0xD,
        GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
    PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
    PushEntryAtField10000_299868(ctx, 5,
        GS_SET_XYZ((D_003C1180 + 0x800 - D_003C1180 / 2) << 4, (D_00586B80 + D_003C118C) << 4, 0xFFFF));
    func_00299908((int)ctx);
    func_00299A28(ctx, 0x1C04, D_003C1B00);
    func_002998D8((int)ctx, 0, 0xE);
    PushEntryAtField10000_299868(ctx, 0, 0x316);
    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(0xE00 >> 5, D_003C1180 / 64, 0, 0xFF000000));
    PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(0, D_003C1180 - 1, 0, D_003C118C - 1));
    PushEntryAtField10000_299868(ctx, 0x3B, GS_SET_TEXA(0, 0, 0x80));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC, D_003C1180 / 64, 0x1B, 9, D_003C11B8, 0, 1, 0x1C04, 0, 0, 0, 1));
    PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
    PushEntryAtField10000_299868(ctx, 0xD,
        GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
    PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
    PushEntryAtField10000_299868(ctx, 5,
        GS_SET_XYZ((D_003C1180 + 0x800 - D_003C1180 / 2) << 4, (D_00586B80 + D_003C118C) << 4, 0xFFFF));
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A0C60);
#endif
