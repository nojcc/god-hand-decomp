/* sn-2.95.3-136 */
/* NON_MATCHING func_00299DE0 (as: sn): 902 vs 907 words. Every GS register
 * value is right. Retail stores the last FRAME's base page (0) to a stack word
 * at the start (sw $zero, 0x10($sp)) and reloads and zero-extends it for the
 * final pass, so its source held that 0 in a variable; with the literal the
 * spill is gone and the saved-register assignment differs from the second
 * pass on. The GS_SET_* macros are copies of the ones in 002a02d0.c until a
 * shared GS header exists. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned long u_long;
typedef unsigned int u_int;
typedef unsigned char u_char;

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
extern void func_002E0D60(int a, int b, int c, int d, int e, int f, char *format, ...);

extern int D_003C1180;
extern int D_003C1188;
extern int D_003C118C;
extern int D_003C1194;
extern u_int D_003C11AC;
extern int D_003C11B8;
extern int D_00586B80;
extern u_char D_004A5F00[256];
extern u_char D_004A6000[256];
extern u_int D_004A6100[256];
extern u_int D_004A6500[256];
extern char D_0044AC88[];

/* Redraws the frame through the depth palette: copies the Z buffer in as a
 * texture, builds the 256-entry palettes at D_004A6100 and D_004A6500 (and
 * prints the first one), draws the frame through each, then six depth slices
 * and a final pass at the display size. */
__attribute__((section(".text.func_00299DE0")))
void func_00299DE0(char *ctx)
{
    int i;
    int k;
    u_int n;
    u_int j;

    PushEntryAtField10000_299868(ctx, 0x3F, 0xFF);
    PushEntryAtField10000_299868(ctx, 0x46, 1);
    PushEntryAtField10000_299868(ctx, 0x19,
        GS_SET_XYOFFSET((0x800 - D_003C1180 / 2) << 4, (0x800 - D_003C118C / 2) << 4));
    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(D_003C11AC >> 5, D_003C1180 / 64, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x3B, GS_SET_TEXA(0, 0, 0x80));
    PushEntryAtField10000_299868(ctx, 0x43, GS_SET_ALPHA(2, 2, 2, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x4F, GS_SET_ZBUF(0xF8, 0xA, 1));
    PushEntryAtField10000_299868(ctx, 0x48, 0x30000);
    PushEntryAtField10000_299868(ctx, 9, GS_SET_CLAMP(2, 2, 0, D_003C1180 - 1, 0, D_003C118C));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(0x1F00, D_003C1180 / 64, 0x3A, 9, D_003C11B8, 1, 1, 0, 0, 0, 0, 0));
    PushEntryAtField10000_299868(ctx, 0x15, 0);
    PushEntryAtField10000_299868(ctx, 0, 0x316);
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C118C - 1));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ((D_003C1180 - D_003C1180 / 2 + 0x800) << 4, (D_00586B80 + D_003C118C) << 4, 0xFFFF));
    }

    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(D_003C11AC >> 5, D_003C1180 / 64, 2, 0x3FFF));
    PushEntryAtField10000_299868(ctx, 9, GS_SET_CLAMP(2, 2, 0, D_003C1180 - 1, 0, D_003C118C * 2));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC, D_003C1180 / 64, 2, 9, D_003C11B8 + 1, 1, 1, 0, 0, 0, 0, 0));
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C118C * 2));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((0x808 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C * 2 << 4) + 9));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ((D_003C1180 - D_003C1180 / 2 + 0x808) << 4,
                       (D_00586B80 + D_003C118C + D_003C118C) << 4, 0xFFFF));
    }

    j = 0;
    for (n = 0; n < 256; n++) {
        D_004A5F00[j] = n;
        D_004A6000[n] = j;
        if (n & 7) {
            j++;
        }
    }
    for (n = 0; n < 256; n++) {
        D_004A6100[n] = D_004A5F00[~n >> 3 & 0x1F] << 24;
    }
    for (i = 0; i < 256; i++) {
        /* retail prints the table's address, not the entry */
        func_002E0D60(8, 8, i / 32 * 0x70 + 0x20, (i % 32 + 5) * 8, 2, 0x80FFFFFF, D_0044AC88, i, D_004A6100);
    }
    func_00299908((int)ctx);
    func_00299A28(ctx, 0x1C04, (int *)D_004A6100);
    func_002998D8((int)ctx, 0, 0xE);

    PushEntryAtField10000_299868(ctx, 0x4F, GS_SET_ZBUF(0xF8, 0xA, 1));
    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(D_003C11AC >> 5, D_003C1180 / 64, 0, 0xFFFFFF));
    PushEntryAtField10000_299868(ctx, 0x48, 0x50000);
    PushEntryAtField10000_299868(ctx, 9, GS_SET_CLAMP(2, 2, 0, D_003C1180 - 1, 0, D_003C118C));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC, D_003C1180 / 64, 0x1B, 9, D_003C11B8, 1, 1, 0x1C04, 0, 0, 0, 1));
    for (i = 0; i < D_003C1180 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C118C - 1));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, 0x1BFF));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ((D_003C1180 - D_003C1180 / 2 + 0x800) << 4, (D_00586B80 + D_003C118C) << 4, 0x1BFF));
    }

    for (n = 0; n < 256; n++) {
        D_004A6500[n] = D_004A5F00[(u_char)(D_004A6000[n] + 0x20)] << 24;
    }
    func_00299908((int)ctx);
    func_00299A28(ctx, 0x1C04, (int *)D_004A6500);
    func_002998D8((int)ctx, 0, 0xE);

    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC, D_003C1180 / 64, 0x1B, 9, D_003C11B8, 1, 1, 0x1C04, 0, 0, 0, 1));
    for (k = 1; k < 7; k++) {
        for (i = 0; i < D_003C1180 / 64; i++) {
            PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C118C - 1));
            PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
            PushEntryAtField10000_299868(ctx, 0xD,
                GS_SET_XYZ((0x800 - D_003C1180 / 2) << 4, D_00586B80 << 4, (k << 10) - 1));
            PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
            PushEntryAtField10000_299868(ctx, 5,
                GS_SET_XYZ((D_003C1180 - D_003C1180 / 2 + 0x800) << 4, (D_00586B80 + D_003C118C) << 4,
                           (k << 10) - 1));
        }
    }

    PushEntryAtField10000_299868(ctx, 0x4D, GS_SET_FRAME(0, D_003C1188 / 64, 0, 0xFFFFFF));
    PushEntryAtField10000_299868(ctx, 0x48, 0x30000);
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C11AC, D_003C1180 / 64, 0, 9, D_003C11B8, 1, 1, 0, 0, 0, 0, 1));
    PushEntryAtField10000_299868(ctx, 0x19,
        GS_SET_XYOFFSET((0x800 - D_003C1188 / 2) << 4, (0x800 - D_003C1194 / 2) << 4));
    for (i = 0; i < D_003C1188 / 64; i++) {
        PushEntryAtField10000_299868(ctx, 0x41, GS_SET_SCISSOR(i * 64, i * 64 + 0x3F, 0, D_003C1194 - 1));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(8, 8));
        PushEntryAtField10000_299868(ctx, 0xD,
            GS_SET_XYZ((0x800 - D_003C1188 / 2) << 4, (0x800 - D_003C1194 / 2) << 4, 0x1BFF));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV((D_003C1180 << 4) + 9, (D_003C118C << 4) + 9));
        PushEntryAtField10000_299868(ctx, 5,
            GS_SET_XYZ((D_003C1188 / 2 + 0x800) << 4, (D_003C1194 / 2 + 0x800) << 4, 0x1BFF));
    }
    PushEntryAtField10000_299868(ctx, 0x19,
        GS_SET_XYOFFSET((0x800 - D_003C1180 / 2) << 4, (0x800 - D_003C118C / 2) << 4));
}
#else
INCLUDE_ASM("asm/nonmatching", func_00299DE0);
#endif
