/* sn-2.95.3-136: clear flag bit 4 on every entry listed in the selected index runs. */
typedef struct Ent12F600 {
    char pad0[0x10];
    unsigned int flags;    /* 0x10 */
} Ent12F600;

typedef struct Grp12F600 {
    int start;             /* 0x00 */
    unsigned char n[3];    /* 0x04 */
} Grp12F600;

typedef struct Obj12F600 {
    char pad0[0x14];
    Ent12F600 *ent;        /* 0x14 */
    char pad18[4];
    unsigned short *idx;   /* 0x1C */
} Obj12F600;

__attribute__((section(".text.func_0012F600")))
void func_0012F600(Obj12F600 *o, Grp12F600 *g, int mask)
{
    unsigned short *base = o->idx + g->start;

    if (mask & 1) {
        unsigned short *q = base;
        unsigned int n = g->n[0];
        while (n-- != 0)
            o->ent[*q++].flags &= ~4;
    }
    if (mask & 2) {
        unsigned short *q = base + g->n[0];
        unsigned int n = g->n[1];
        while (n-- != 0)
            o->ent[*q++].flags &= ~4;
    }
    if (mask & 4) {
        unsigned short *q = base + g->n[0] + g->n[1];
        unsigned int n = g->n[2];
        while (n-- != 0)
            o->ent[*q++].flags &= ~4;
    }
}
