/* sn-2.95.3-136 (as: sn) */
/* NON_MATCHING func_0029F7D8: 188 of 190 words. Every GS register value is
 * right. Retail builds the FRAME_2 value with 0x70 and the 0xFF000000 mask in
 * two registers, ORed in one at a time; cc1 folds them into one constant. */
#include "include_asm.h"
#include "godhand/gsPacket.h"

#ifdef NON_MATCHING
/* Draw the texture at D_003C3CC8 over the screen in 32-pixel strips, blended
 * at the context's alpha (0x140D8) into frame 0x70, Z writes masked. */
__attribute__((section(".text.func_0029F7D8")))
void func_0029F7D8(char *ctx)
{
    int i;

    PushEntryAtField10000_299868(ctx, GS_PRIM, 0x356);
    PushEntryAtField10000_299868(ctx, GS_FRAME_2, GS_SET_FRAME(0x70, D_003C1180 / 64, 0, 0xFF000000));
    PushEntryAtField10000_299868(ctx, 0x43, GS_SET_ALPHA(0, 1, 2, 1, *(unsigned char *)(ctx + 0x140D8)));
    PushEntryAtField10000_299868(ctx, 7,
        GS_SET_TEX0(D_003C3CC8, D_003C1188 / 64, D_003C3CC9, 9, D_003C11C0, 0, 1, 0, 0, 1, 0, 2));
    PushEntryAtField10000_299868(ctx, 0x15, 0x60);
    PushEntryAtField10000_299868(ctx, 9, GS_SET_CLAMP(2, 2, 0, D_003C1188 - 1, 0, D_003C1194 - 1));
    PushEntryAtField10000_299868(ctx, 0x4F, GS_SET_ZBUF(0xF8, 0xA, 1));
    PushEntryAtField10000_299868(ctx, 0x48, GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, GS_ZTST_ALWAYS));
    for (i = 0; i < D_003C1180 / 32; i++) {
        PushEntryAtField10000_299868(ctx, GS_SCISSOR_2,
            GS_SET_SCISSOR(i * 32, i * 32 + 31, 0, D_003C118C - 1));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(0, 0));
        PushEntryAtField10000_299868(ctx, GS_XYZ3,
            GS_SET_XYZ((GS_WINDOW_CENTER - D_003C1180 / 2) << 4, D_00586B80 << 4, 0xFFFF));
        PushEntryAtField10000_299868(ctx, 3, GS_SET_UV(D_003C1188 << 4, D_003C1194 << 4));
        PushEntryAtField10000_299868(ctx, GS_XYZ2,
            GS_SET_XYZ((GS_WINDOW_CENTER - D_003C1180 / 2 + D_003C1180) << 4, (D_00586B80 + D_003C118C) << 4, 0xFFFF));
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0029F7D8);
#endif
