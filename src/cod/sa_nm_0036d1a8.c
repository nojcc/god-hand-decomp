/* NON_MATCHING func_0036D1A8 (cygnus-2.96, -freorder-blocks dropped, as=sn): same size, 17 insns: hang loop and layout match, but retail keeps the flag load after all register saves, reuses a0 = 4 from the compare as the call argument, and stores D_0076A588 through a fully materialised address (addiu then sw 0); this hoists the load to the top and folds %lo into the store. Tried: plain form, shared mode local, volatile flag. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern unsigned char D_0045A514;
extern char D_0045A478[];
extern char *D_0076A588;
extern void func_0036D7C0(int a0);
extern void func_0036DCE8(void);
extern void func_0036D280(int a0, int a1, int a2);
extern void func_0036D238(void);

void func_0036D1A8(int a0, int a1, int a2)
{
    if (D_0045A514 != 4) {
        for (;;)
            ((void (*)(void))-1)();
    }
    D_0076A588 = D_0045A478;
    func_0036D7C0(4);
    func_0036DCE8();
    func_0036D280(a0, a1, a2);
    func_0036D238();
}
#else
INCLUDE_ASM("asm/nonmatching", func_0036D1A8);
#endif
