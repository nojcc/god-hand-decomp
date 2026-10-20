/* NON_MATCHING func_0037B0E0 (sn-2.95.3-136;
 * PARK, 139 diffs): retail keeps the print column 3 in s0 (set once after the first switch) and passes it as a register to every func_002E0DE8 call; ours folds it to an immediate, which shifts all register numbering.
 * Typing x as short/char or moving its assignment does not change that; sound debug page print */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char *D_003F26C8[];
extern void (*D_003F26D8[])(void *p);
extern char D_0076A790[];
extern unsigned char D_0076DF10[];
extern unsigned char D_0076E510[];
extern unsigned char D_0076EA50[];
extern char D_0045BCC8[];
extern char D_0045BCD8[];
extern char D_0045BCE8[];
extern char D_0045BD00[];
extern char D_0045BD18[];
extern char D_0045BD30[];
extern char D_0045BD48[];
extern char D_0045BD60[];
extern char D_0045BD78[];
extern void func_002E0DE8(int x, int y, int col, char *fmt, ...);

__attribute__((section(".text.func_0037B0E0")))
void func_0037B0E0(char *p)
{
    char *g = D_0076A790;
    short n = 0;
    short sel;
    short idx;
    int x;

    func_002E0DE8(3, 3, 8, D_0045BCC8, D_003F26C8[*(signed char *)(p + 7)]);
    D_003F26D8[*(signed char *)(p + 7)](p);
    sel = *(short *)(p + 0x1C + *(signed char *)(p + 7) * 2);
    idx = *(short *)(p + 0x16 + *(signed char *)(p + 7) * 2);
    switch (*(signed char *)(p + 7)) {
    case 0:
        n = *(unsigned short *)(D_0076DF10 + idx * 0x20) - 1;
        break;
    case 1:
        n = *(unsigned short *)(D_0076E510 + idx * 0x20) - 1;
        break;
    case 2:
        n = *(unsigned short *)(D_0076EA50 + idx * 0x20 + 0x14) - 1;
        break;
    }
    x = 3;
    func_002E0DE8(x, 6, 8, D_0045BCD8);
    func_002E0DE8(x, 7, 8, D_0045BCE8, sel, n);
    func_002E0DE8(x, 8, 8, D_0045BD00, *(int *)(p + 0xC));
    func_002E0DE8(x, 0xA, 0xD, D_0045BD18);
    func_002E0DE8(x, 0xC, 8, D_0045BD30, *(short *)(g + 0x28), *(short *)(g + 0x2A));
    switch (*(signed char *)(p + 7)) {
    case 0:
        func_002E0DE8(x, 0xD, 8, D_0045BD48, *(short *)(g + 0x2C), *(short *)(g + 0x2E));
        break;
    case 1:
        func_002E0DE8(x, 0xD, 8, D_0045BD60, *(short *)(g + 0x30), *(short *)(g + 0x32));
        break;
    case 2:
        func_002E0DE8(x, 0xD, 8, D_0045BD78, *(short *)(g + 0x34), *(short *)(g + 0x36));
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037B0E0);
#endif
