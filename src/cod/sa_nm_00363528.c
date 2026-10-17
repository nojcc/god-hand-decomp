/* NON_MATCHING func_00363528 (cygnus-2.96 -freorder-blocks dropped): 44 diffs: dst/mbw get s6/s5 instead of retail s5/s6, and retail loads dst->data in the preheader/latch (bnel slot) with dst->h at the loop top; for/while/do/goto shapes, ee-2.9 all no better */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Img363528 {
    char unk00[4];
    char *data;                 /* 0x04 */
    int w;                      /* 0x08 */
    int h;                      /* 0x0C */
} Img363528;

extern void cftraw_CnvMbRAW8toARGB(char *dst, char *src, int arg);

void func_00363528(Img363528 *dst, Img363528 *src, int arg)
{
    int i;
    int j;
    int mbw = src->w / 16;
    int mbh = src->h / 16;
    char *s = src->data;
    char *d;

    for (i = 0; i < mbw; i++) {
        d = dst->data + dst->h * i * 24;
        for (j = 0; j < mbh; j++) {
            cftraw_CnvMbRAW8toARGB(d, s, arg);
            d += 0x180;
            s += 0x400;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00363528);
#endif
