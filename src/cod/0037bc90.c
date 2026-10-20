/* NON_MATCHING func_0037BC90 (sn-2.95.3-136): call sequence matches, but retail keeps the colour
 * (always 3) in a register as value<<16 (srl/sra 16 at each use, re-set in case 0/2) where this folds it to a
 * constant; probably a register-packed short pair or fixed-point value in the original. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_002E0DE8();
extern char D_003F26E8[];
extern char D_0045BF58[], D_0045BF70[], D_0045BF80[], D_0045BF98[], D_0045BFB0[], D_0045BFC8[];
extern char D_0045BFD8[], D_0045BFE0[], D_0045BFE8[], D_0045BFF8[], D_0045C010[];

typedef struct ColorEnt {
    short **name;                       /* 0x00 */
    char pad04[5];
    signed char state;                  /* 0x09 */
    short cntA;                         /* 0x0A */
    short cntB;                         /* 0x0C */
} ColorEnt;

__attribute__((section(".text.func_0037BC90")))
void func_0037BC90(unsigned char *a0)
{
    ColorEnt *e;
    short *flag;
    short c;

    e = (ColorEnt *)(D_003F26E8 + (signed char)a0[0x27] * 0x78 + (signed char)a0[0x28] * 0x14);
    flag = (short *)(a0 + (signed char)a0[0x27] * 32 + 0x16C);
    func_002E0DE8(3, 0xF, 0xD, D_0045BF58);
    switch (e->state) {
    case 0:
    case 2:
        c = 3;
        func_002E0DE8(c, 0x11, 8, D_0045BF70);
        break;
    case 1:
        c = 3;
        func_002E0DE8(3, 0x11, 8, D_0045BF80, **e->name, **e->name);
        func_002E0DE8(3, 0x13, 8, D_0045BF98, e->cntA, e->cntA);
        func_002E0DE8(3, 0x14, 8, D_0045BFB0, e->cntB, e->cntB);
        break;
    default:
        c = 3;
        break;
    }
    func_002E0DE8(c, 0x16, 8, D_0045BFC8);
    if ((signed char)a0[0x29] == 0) {
        if (*flag == 0)
            func_002E0DE8(0xC, 0x16, 0xF, D_0045BFD8);
        else
            func_002E0DE8(0xC, 0x16, 0xC, D_0045BFE0);
    } else if (*(int *)a0 & 0x10) {
        func_002E0DE8(0xC, 0x16, 0xD, D_0045BFE8);
    }
    func_002E0DE8(c, 0x18, 8, D_0045BFF8);
    func_002E0DE8(c, 0x19, 8, D_0045C010);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037BC90);
#endif
