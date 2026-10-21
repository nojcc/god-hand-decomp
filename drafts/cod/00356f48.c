/* NON_MATCHING func_00356F48 (cygnus-2.96): 38 words vs 35
the constant 1 (mode default and the +0x44 store) is CSE'd into a saved register s2 across the call, where retail rematerialises it (a2 = 1 in the busy-check delay slot, addiu v1, 1 after the call). */
#include "include_asm.h"
#include "godhand/sftim.h"

#ifdef NON_MATCHING
extern int Obj34D8_SetGlobalEE0B8_IfField48(char *hn);
extern int func_00356FD8(char *hn, int mode);

void func_00356F48(char *hn, int on)
{
    int mode;

    if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != 0) {
        func_0034DD70(0, 0xFF000142);
        return;
    }
    mode = *(int *)(hn + 0x50) != 0 ? 2 : 1;
    if (on == 0) {
        if (*(int *)(hn + 0x50) == 0)
            return;
        mode = 0;
    }
    *(int *)(hn + 0x50) = on;
    func_00356FD8(hn, mode);
    *(int *)(hn + 0x44) = 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00356F48);
#endif
