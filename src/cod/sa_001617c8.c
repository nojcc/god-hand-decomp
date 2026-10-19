/* sn-2.95.3-136: func_001617C8, part visibility update: hide the four parts of both sets, show the selected one of each, show parts 12-14 or parts 4-7 depending on system flag 0x400000, then run the base move. */
typedef struct Part1617C8 {
    char pad00[0x2C];
    unsigned int flags;                 /* 0x2C */
} Part1617C8;

typedef struct Obj1617C8 {
    char pad00[0x80];
    Part1617C8 *part[15];               /* 0x80 */
    signed char sel;                    /* 0xBC */
} Obj1617C8;

extern int D_00747A24[];
extern void cIDBase_move(void *self);

#define HIDE1617C8 0x08000000

__attribute__((section(".text.func_001617C8")))
void func_001617C8(Obj1617C8 *o)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        o->part[i]->flags |= HIDE1617C8;
        o->part[i + 8]->flags |= HIDE1617C8;
    }
    o->part[o->sel]->flags &= ~HIDE1617C8;
    o->part[o->sel + 8]->flags &= ~HIDE1617C8;
    if (D_00747A24[1] & 0x400000) {
        o->part[12]->flags |= HIDE1617C8;
        o->part[13]->flags |= HIDE1617C8;
        o->part[14]->flags |= HIDE1617C8;
        o->part[4]->flags &= ~HIDE1617C8;
        o->part[5]->flags &= ~HIDE1617C8;
        o->part[6]->flags &= ~HIDE1617C8;
        o->part[7]->flags &= ~HIDE1617C8;
    } else {
        o->part[12]->flags &= ~HIDE1617C8;
        o->part[13]->flags &= ~HIDE1617C8;
        o->part[14]->flags &= ~HIDE1617C8;
        o->part[4]->flags |= HIDE1617C8;
        o->part[5]->flags |= HIDE1617C8;
        o->part[6]->flags |= HIDE1617C8;
        o->part[7]->flags |= HIDE1617C8;
    }
    cIDBase_move(o);
}
