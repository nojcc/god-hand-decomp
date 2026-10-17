/* NON_MATCHING func_00342E88 (cygnus,const-reassoc): best 23 (45 vs 46 words): calls/prologue match; fold merges one +0x40 into the trailing +0x800 (addiu 0x840) and reorders the sum. Retail keeps (s1+s2+s3+0x40)+n+(s0+s4)+((d0+0x40)+(d1+s5))+E80()+0x800 unfolded. Locals for partial sums or a pad local move values into s-regs across the E80 call (39-44). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void mwsfcre_CalcWorkStmBuf(int hn, int *a, int *b, int *c, int *d, int *e, int *f);
extern void func_00342D00(int hn, int *a, int *b);
extern int func_00342E50(int hn, int *a, int *b, int *c);
extern int func_00342E80(void);

int func_00342E88(int hn)
{
    int s0, s1, s2, s3, s4, s5;
    int d0, d1;
    int e0, e1, e2;
    int n;

    mwsfcre_CalcWorkStmBuf(hn, &s0, &s1, &s2, &s3, &s4, &s5);
    func_00342D00(hn, &d0, &d1);
    n = func_00342E50(hn, &e0, &e1, &e2);
    return s1 + s2 + s3 + 0x40 + n + (s0 + s4) + (d0 + 0x40 + (d1 + s5)) + func_00342E80() + 0x800;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00342E88);
#endif
