/* NON_MATCHING func_00347AF8 (cygnus,dr,regalloc-swap): best 9 with -freorder-blocks dropped: only s0/s1 are swapped. Retail puts buf in s0 and hn (then hn->sj) in s1; ours gives hn/sj s0 and buf s1. Local order, -fno-gcse and nested ifs (25) do not change it. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x48];
    int sj; /* 0x48 */
    char pad4C[0x1A4 - 0x4C];
    int type; /* 0x1A4 */
} SfdHn;
extern char D_00459040[];
extern char D_00459070[];
extern int GetField0OrZero_346828(SfdHn *hn);
extern void MWSFSVM_Error(char *msg);
extern int func_003245B0(int buf, int size, int type, int *a, int *b, int *c);
extern int func_003247D0(int buf, int buf2, int size);
extern void func_00335638(int sj, int hdr, int a, int b, int c);

void func_00347AF8(SfdHn *hn, int buf, int size)
{
    int sj;
    int a, b, c;

    if (GetField0OrZero_346828(hn) != 1) {
        MWSFSVM_Error(D_00459040);
        return;
    }
    sj = hn->sj;
    if (func_003245B0(buf, size, hn->type, &a, &b, &c) == 0) {
        func_00335638(sj, func_003247D0(buf, buf, size), a, b, c);
        return;
    }
    MWSFSVM_Error(D_00459070);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00347AF8);
#endif
