#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_00302918(void *self);
extern void func_003029C0(void *self);

typedef struct ObjLink {
    char unk0[0x2F4];
    unsigned char sel[4];       /* 0x2F4 sel[0] doubles as the channel number */
} ObjLink;

typedef struct LinkedObj {
    char unk0[0x108];
    ObjLink *link;           /* 0x108 */
    char unk10C[0x240 - 0x10C];
    int cache[4];               /* 0x240 */
} LinkedObj;

static inline unsigned char IsChan304C48(ObjLink *l, int n)
{
    return l->sel[0] == n;
}

void func_00304C48(LinkedObj *o)
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
