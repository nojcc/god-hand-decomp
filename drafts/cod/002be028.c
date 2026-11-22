/* NON_MATCHING func_002BE028: the C matches except the R5900 short-loop pad: retail has jal/delay/nop/nop/beqz/nop for each of the 4 wait loops.
* The pass works on BlackJackId_Move, so the difference is the noreorder jal+slot loop body. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_0044C008[];
extern char D_0044C028[];
extern void sceSifInitRpc(int mode);
extern int func_00399008(int a);
extern int sceSifRebootIop(char *img);
extern int sceSifSyncIop(void);
extern void sceFsReset(void);
extern void func_00399BD8(int a);
extern void sceSifLoadFileReset(void);
extern int sceSifInitIopHeap(void);
extern void func_003A6A20(char *msg);
extern void func_0031DB70(int a);

void func_002BE028(void)
{
    sceSifInitRpc(0);
    while (func_00399008(0) == 0)
        ;
    while (sceSifRebootIop(D_0044C008) == 0)
        ;
    while (sceSifSyncIop() == 0)
        ;
    sceSifInitRpc(0);
    while (func_00399008(0) == 0)
        ;
    sceFsReset();
    func_00399BD8(2);
    sceSifLoadFileReset();
    if (sceSifInitIopHeap() != 0) {
        func_003A6A20(D_0044C028);
        func_0031DB70(-1);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BE028);
#endif
