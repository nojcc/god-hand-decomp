/* NON_MATCHING func_0034A400 (cygnus,dr,prologue-order,regalloc): best 16 with -freorder-blocks dropped: branch layout and calls match. Retail copies the params in reverse order (a3,a2,a1,a0 into s3,s0,s1,s2), stores *skip=0 before the a0/a1 setup, and uses v1 for total / v0 for the handler address at the tail; ours copies in a2,a1,a0,a3 order and swaps v0/v1. Swapping the tail statements does not help. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x3C];
    void (*proc)(void); /* 0x3C */
} SfdDec;
typedef struct {
    char pad0[0x9C8];
    long total; /* 0x9C8 */
    char pad9D0[0x2004 - 0x9D0];
    SfdDec *dec; /* 0x2004 */
} SfdHn;
extern void func_0034A0F0(void);
extern int func_0032B758(unsigned char *data, int size, int *hdrsize);
extern int Obj34D8_GetTri78_Times100(SfdHn *hn);
extern unsigned char *sfadxt_SearchAlign(SfdHn *hn, unsigned char *data, int size);

void func_0034A400(SfdHn *hn, unsigned char *data, int size, int *skip)
{
    SfdDec *dec;
    int hdrsize;
    int n;

    *skip = 0;
    dec = hn->dec;
    if (size < 0x120)
        return;
    if (func_0032B758(data, size, &hdrsize) == 0) {
        if (Obj34D8_GetTri78_Times100(hn) < 0x6C)
            n = sfadxt_SearchAlign(hn, data, size) - data;
        else
            n = 0;
    } else {
        n = hdrsize;
    }
    *skip = n;
    hn->total += n;
    dec->proc = func_0034A0F0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034A400);
#endif
