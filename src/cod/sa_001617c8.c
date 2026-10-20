/* sn-2.95.3-136: func_001617C8, part visibility update: hide the four parts of both sets, show the selected one of each, show parts 12-14 or parts 4-7 depending on system flag 0x400000, then run the base move. */
typedef struct PartFlags {
    char pad00[0x2C];
    unsigned int flags;                 /* 0x2C */
} PartFlags;

typedef struct PartSetObj {
    char pad00[0x80];
    PartFlags *part[15];               /* 0x80 */
    signed char sel;                    /* 0xBC */
} PartSetObj;

extern int D_00747A24[];
extern void cIDBase_move(void *self);

#define PART_F_HIDE 0x08000000

__attribute__((section(".text.func_001617C8")))
void func_001617C8(PartSetObj *o)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        o->part[i]->flags |= PART_F_HIDE;
        o->part[i + 8]->flags |= PART_F_HIDE;
    }
    o->part[o->sel]->flags &= ~PART_F_HIDE;
    o->part[o->sel + 8]->flags &= ~PART_F_HIDE;
    if (D_00747A24[1] & 0x400000) {
        o->part[12]->flags |= PART_F_HIDE;
        o->part[13]->flags |= PART_F_HIDE;
        o->part[14]->flags |= PART_F_HIDE;
        o->part[4]->flags &= ~PART_F_HIDE;
        o->part[5]->flags &= ~PART_F_HIDE;
        o->part[6]->flags &= ~PART_F_HIDE;
        o->part[7]->flags &= ~PART_F_HIDE;
    } else {
        o->part[12]->flags &= ~PART_F_HIDE;
        o->part[13]->flags &= ~PART_F_HIDE;
        o->part[14]->flags &= ~PART_F_HIDE;
        o->part[4]->flags |= PART_F_HIDE;
        o->part[5]->flags |= PART_F_HIDE;
        o->part[6]->flags |= PART_F_HIDE;
        o->part[7]->flags |= PART_F_HIDE;
    }
    cIDBase_move(o);
}
