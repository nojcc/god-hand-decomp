/* NON_MATCHING func_00304C48 (inline-bool): sn: retail materialises each (sel[0]==n) bool with a branch + andi 0xFF and reloads link/sel[0] per test; inline helper variants, C++ bool, -fno-gcse/-O1 all fold it */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_00302918(void *self);
extern void func_003029C0(void *self);

typedef struct Link304C48 {
    char unk0[0x2F4];
    unsigned char sel[4];       /* 0x2F4 sel[0] doubles as the channel number */
} Link304C48;

typedef struct Obj304C48 {
    char unk0[0x108];
    Link304C48 *link;           /* 0x108 */
    char unk10C[0x240 - 0x10C];
    int cache[4];               /* 0x240 */
} Obj304C48;

static inline unsigned char IsChan304C48(Link304C48 *l, int n)
{
    return l->sel[0] == n;
}

void func_00304C48(Obj304C48 *o)
{
    int same;

    same = 1;
    if (IsChan304C48(o->link, 0) && (o->link->sel[0] ^ o->cache[0]) != 0)
        same = 0;
    if (IsChan304C48(o->link, 1) && (o->link->sel[1] ^ o->cache[1]) != 0)
        same = 0;
    if (IsChan304C48(o->link, 2) && (o->link->sel[2] ^ o->cache[2]) != 0)
        same = 0;
    if (IsChan304C48(o->link, 3) && (o->link->sel[3] ^ o->cache[3]) != 0)
        same = 0;
    if (same == 0)
        func_00302918(o);
    func_003029C0(o);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00304C48);
#endif
