/* Batch 38 hash-breakers — not registered. */
#include "include_asm.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
extern void cIDBase_initialize(void *self, int a1, int a2);
extern int cIDManager_getTexAddr_2ACE28(void *mgr, int id);
extern void *EnsureInitThenForward_2A9538_30EE08(int size, int align, void *region);
extern void func_003A52F0(void *dst, int val, int len);
extern void func_0014E598(void *self);
extern void *D_003C2388;
extern char D_00754C20[];
extern int D_00450CE8;

__attribute__((section(".text.func_00312E88")))
void *func_00312E88(void)
{
    char *s0;

    s0 = EnsureInitThenForward_2A9538_30EE08(0x360, 0x10, D_00754C20);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x360);
    func_0014E598(s0);
    *(int **)(s0 + 0x214) = &D_00450CE8;
    VU0_SQC2_VF0(s0, 0x310);
    s0[0x32C] = 0;
    VU0_SQC2_VF0(s0, 0x340);
    return s0;
}


#else
INCLUDE_ASM("asm/nonmatching", func_00312E88);
#endif
