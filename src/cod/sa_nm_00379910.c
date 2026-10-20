/* NON_MATCHING func_00379910 (sn-2.95.3-136; PARK, 150 diffs): calls and block layout match; retail keeps the column x
 * (3, set in every switch arm) in v0 and schedules its sll after the format lui, ours puts x in a1. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void func_002E0DE8(int, int, int, const char *, ...);

typedef struct {
    void *val;
    int f4;
    signed char type;
    signed char kind;
    short a;
    short b;
    short c;
    short d;
    short pad;
} DbgEnt;

extern DbgEnt D_003F21E8[];
extern DbgEnt D_003F2368[];
extern DbgEnt D_003F24D0[];
extern char D_0045B768[];
extern char D_0045B780[];
extern char D_0045B790[];
extern char D_0045B7A8[];
extern char D_0045B7C0[];
extern char D_0045B7D8[];
extern char D_0045B7F0[];
extern char D_0045B808[];
extern char D_0045B820[];
extern char D_0045B838[];
extern char D_0045B850[];

__attribute__((section(".text.func_00379910")))
void func_00379910(char *self)
{
    DbgEnt *e = 0;
    signed char cv = 0;
    short sv = 0;
    int x;

    switch (*(signed char *)(self + 7)) {
    case 0:
        e = &D_003F21E8[*(signed char *)(self + 0x25)];
        x = 3;
        break;
    case 1:
        e = &D_003F2368[*(signed char *)(self + 0x25)];
        x = 3;
        break;
    case 2:
        e = &D_003F24D0[*(signed char *)(self + 0x25)];
        x = 3;
        break;
    default:
        x = 3;
        break;
    }
    func_002E0DE8((short)x, 0xF, 0xD, D_0045B768);
    switch (e->kind) {
    case 0:
        func_002E0DE8((short)x, 0x11, 8, D_0045B780);
        break;
    case 1:
        if (e->type == 0)
            cv = *(signed char *)e->val;
        else
            sv = *(short *)e->val;
        if (e->type == 0)
            func_002E0DE8((unsigned int)(x << 16) >> 16, 0x11, 8, D_0045B790, cv, cv);
        else
            func_002E0DE8((unsigned int)(x << 16) >> 16, 0x11, 8, D_0045B790, sv, sv);
        func_002E0DE8((short)x, 0x13, 8, D_0045B7A8, e->a, e->a);
        func_002E0DE8((short)x, 0x14, 8, D_0045B7C0, e->b, e->b);
        func_002E0DE8((short)x, 0x16, 0xD, D_0045B7D8);
        func_002E0DE8((short)x, 0x18, 8, D_0045B7F0, e->c, e->c);
        func_002E0DE8((short)x, 0x19, 8, D_0045B808, e->d, e->d);
        func_002E0DE8((short)x, 0x1A, 8, D_0045B820);
        break;
    case 2:
        if (e->type == 3 || e->type == 5)
            func_002E0DE8((short)x, 0x11, 8, D_0045B838, *(unsigned char *)e->val);
        else
            func_002E0DE8((short)x, 0x11, 8, D_0045B850, *(unsigned short *)e->val);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00379910);
#endif
