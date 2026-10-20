/* NON_MATCHING func_0037B918 (sn-2.95.3-136, -fno-gcse;
 * PARK, 61 diffs): -fno-gcse keeps x=0x1D in s4 like retail, but loop hoists %hi(D_0045BF30) into fp where retail hoists %hi(D_003F2800); post-loop table index regs differ */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    short f0;
    unsigned short f2;
    short f4;
    short f6;
    short f8;
    short fA;
    int fC;
    int f10;
    char pad14[0xC];
} Ent37B;

typedef struct {
    char pad0[0x27];
    signed char cur;
    signed char sel;
    char pad29[0x16C - 0x29];
    Ent37B ent[2];
} Pg37B;

typedef struct {
    char pad0[6];
    short f6;
    char pad8[0xC];
} Row37B;

typedef struct {
    short x0, y0, x1, y1, x2, y2, x3, y3;
} Quad37B;

extern void func_002E0DE8(int, int, int, const char *, ...);
extern void func_0031CB80(Quad37B *q, int col, int z);
extern char *D_003F27D8[];
extern Row37B D_003F26E8[][6];
extern Quad37B D_003F2800;
extern char D_0045BE90[];
extern char D_0045BEA0[];
extern char D_0045BEB0[];
extern char D_0045BEC0[];
extern char D_0045BED0[];
extern char D_0045BEE0[];
extern char D_0045BEF0[];
extern char D_0045BF00[];
extern char D_0045BF18[];
extern char D_0045BF30[];
extern char D_0045BF48[];
extern char D_0045BF50[];

void func_0037B918(Pg37B *self)
{
    Ent37B *e = self->ent;
    int y = 3;
    int x = 0x1D;
    int i;
    int c, c2, n;
    Row37B *r;

    for (i = 0; i < 2; i++) {
        func_002E0DE8(x, (short)y, (self->cur == i) ? 0xD : 8, D_0045BE90, i, D_003F27D8[e->f0]);
        c = (self->cur == i) ? 8 : 0xF;
        c2 = c;
        func_002E0DE8(x, (short)(y + 2), c, D_0045BEA0, e->f0);
        func_002E0DE8(x, (short)(y + 3), c, D_0045BEB0, e->f2);
        func_002E0DE8(x, (short)(y + 4), c, D_0045BEC0, e->f4);
        func_002E0DE8(x, (short)(y + 5), c, D_0045BED0, e->f6);
        if (c == 8 && (unsigned short)e->f0 - 7U > 1)
            c2 = 0xF;
        func_002E0DE8(x, (short)(y + 6), c2, D_0045BEE0, e->f8);
        func_002E0DE8(x, (short)(y + 7), c2, D_0045BEF0, e->fA);
        if (e->f10 == 0)
            n = e->fC;
        else
            n = e->fC - e->f10 + 1;
        func_002E0DE8(x, (short)(y + 8), c, D_0045BF00, e->f10);
        func_002E0DE8(x, (short)(y + 9), c, D_0045BF18, n);
        func_002E0DE8(x, (short)(y + 10), c, D_0045BF30, e->fC);
        y += 12;
        e++;
    }
    r = &D_003F26E8[self->cur][self->sel];
    y = self->cur * 12 + 3;
    func_002E0DE8(0x1B, (short)(r->f6 + y), 0xC, D_0045BF48);
    func_002E0DE8(0x2C, (short)(r->f6 + y), 0xC, D_0045BF50);
    n = (y + r->f6) * 8;
    D_003F2800.x0 = 0xE0;
    D_003F2800.y0 = n;
    D_003F2800.x1 = 0x160;
    D_003F2800.y1 = n;
    D_003F2800.x2 = 0xE0;
    D_003F2800.y2 = n + 8;
    D_003F2800.x3 = 0x160;
    D_003F2800.y3 = n + 8;
    func_0031CB80(&D_003F2800, 0x80006060, 0);
    n = y * 8;
    D_003F2800.x0 = 0xD4;
    D_003F2800.y0 = n - 4;
    D_003F2800.x1 = 0x194;
    D_003F2800.y1 = n - 4;
    D_003F2800.x2 = 0xD4;
    D_003F2800.y2 = n + 0x5C;
    D_003F2800.x3 = 0x194;
    D_003F2800.y3 = n + 0x5C;
    func_0031CB80(&D_003F2800, 0x80006000, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0037B918);
#endif
