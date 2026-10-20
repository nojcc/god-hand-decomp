/* NON_MATCHING func_0030CF10 (sn-2.95.3-136;
 * PARK, 72 diffs): same length; retail allocates the hoisted constants as s5 = 1, s4 = 0xFF, s2 = -1, s6 = TH|TCC and schedules the next entry's width/height loads ahead of the pointer bump.
 * A macro (not an inline) is needed so the GS_SET_TEX0 constant fields fold; five TEX0 entries for the screen-copy textures */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef unsigned long u64;

extern unsigned char D_00752780[];
extern int D_003C1180;
extern int D_003C118C;
extern unsigned int D_003C11AC;
extern int func_00309D40(int w);

#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
     ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35))

#define SET_TEX(e, tbp, psm, th)                                                              \
    do {                                                                                      \
        int tw;                                                                               \
        *(unsigned short *)((e) + 4) = D_003C1180;                                            \
        (e)[0] = 1;                                                                           \
        (e)[1] = 0xFF;                                                                        \
        *(unsigned short *)((e) + 6) = D_003C118C;                                            \
        (e)[2] = 0;                                                                           \
        *(int *)((e) + 8) = 0;                                                                \
        tw = func_00309D40(D_003C1180);                                                       \
        *(u64 *)((e) + 0x20) = 0;                                                             \
        *(u64 *)((e) + 0x18) = GS_SET_TEX0(tbp, (D_003C1180 + 63) / 64, psm, tw, th, 1, 0);  \
    } while (0)

__attribute__((section(".text.func_0030CF10")))
void func_0030CF10(void)
{
    unsigned char *e = D_00752780;

    SET_TEX(e, 0, 0, 8);
    e += 0xB0;
    SET_TEX(e, 0xE00, 0, 8);
    e += 0xB0;
    SET_TEX(e, 0x1F00, 0xA, 4);
    e += 0xB0;
    SET_TEX(e, D_003C11AC, 0, 8);
    e += 0xB0;
    SET_TEX(e, 0x1B00, 0, 8);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030CF10);
#endif
