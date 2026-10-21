/* NON_MATCHING func_00347C80 (cygnus-2.96): 4 insns.
* Retail materializes the error string address before the
 * argument copies a1/a3/t0; here it comes after them. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int GetField0OrZero_346828(void *h);
extern void MWSFSVM_Error(char *fmt, int a1, int a2, int a3, int a4);
extern void func_00335638(void *ply, int a1, int a2, int a3, int a4);
extern char D_004590D8[];

__attribute__((section(".text.func_00347C80")))
void func_00347C80(char *h, int a1, int a2, int a3)
{
    if (GetField0OrZero_346828(h) == 1) {
        func_00335638(*(void **)(h + 0x48), a1, 0, a2, a3);
        return;
    }
    MWSFSVM_Error(D_004590D8, a1, 0, a2, a3);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00347C80);
#endif
