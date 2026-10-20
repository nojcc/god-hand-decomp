/* NON_MATCHING func_002BE028: the C matches except the R5900 short-loop pad: retail has jal/delay/nop/nop/beqz/nop for each of the 4 wait loops.
* The pass works on BlackJackId_Move, so the difference is the noreorder jal+slot loop body. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_0044C008[];
extern char D_0044C028[];
extern void sceSifInitRpc(int mode);
extern int func_00399008(int a);
extern int func_003B6290(char *img);
extern int func_003B6240(void);
extern void func_003B41E8(void);
extern void func_00399BD8(int a);
extern void func_003B5C10(void);
extern int func_003B58E0(void);
extern void func_003A6A20(char *msg);
extern void func_0031DB70(int a);

void func_002BE028(void)
{
    sceSifInitRpc(0);
    while (func_00399008(0) == 0)
        ;
    while (func_003B6290(D_0044C008) == 0)
        ;
    while (func_003B6240() == 0)
        ;
    sceSifInitRpc(0);
    while (func_00399008(0) == 0)
        ;
    func_003B41E8();
    func_00399BD8(2);
    func_003B5C10();
    if (func_003B58E0() != 0) {
        func_003A6A20(D_0044C028);
        func_0031DB70(-1);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BE028);
#endif
