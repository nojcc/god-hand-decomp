/* NON_MATCHING func_00342D00: cygnus dr: 36 diffs, all register numbering in the size arithmetic; retail keeps an extra mb copy before the <<10 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Mwsf342D00 {
    char unk0[0x10];
    int nfrm;                   /* 0x10 */
    char unk14[0x10];
    int fmt;                    /* 0x24 */
} Mwsf342D00;

extern int D_003EC7D0;
extern void mwsfcre_CalcFrmRes(Mwsf342D00 *m, int *w, int *h, int *a, int *b);
extern int mwsfcre_ConvBufFmtFromMwsfd(int fmt);

void func_00342D00(Mwsf342D00 *m, int *size0, int *size1)
{
    int w, h, a, b;
    int n, fmt, mb, v;

    if (D_003EC7D0 != 0) {
        *size0 = 0;
        *size1 = 0;
        return;
    }
    n = m->nfrm;
    mwsfcre_CalcFrmRes(m, &w, &h, &a, &b);
    fmt = mwsfcre_ConvBufFmtFromMwsfd(m->fmt);
    mb = (w / 16) * (h / 16);
    v = w * h * 9;
    *size0 = v / 2 + 0x86910;
    v = n * (mb * 0x400 + 0x40);
    if (fmt != 2)
        v = n * (mb * 0x180 + 0x40);
    *size1 = v;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00342D00);
#endif
