/* NON_MATCHING func_002A6FF8 (sn-2.95.3-136; 102 vs 110 words: retail keeps self and the
 * table base in separate s-regs and hoists the 0x7FFFFFFF/0x80000000 masks into s3/s5) */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct LinkEnt2A6 {
    unsigned short a;           /* 0x0 */
    unsigned short b;           /* 0x2 */
    int pad4;
    unsigned int flags;         /* 0x8 */
} LinkEnt2A6;

typedef struct LinkTbl2A6 {
    int pad00;
    LinkEnt2A6 *ents;           /* 0x04 */
    int nEnts;                  /* 0x08 */
    char *verts;                /* 0x0C */
    int nVerts;                 /* 0x10 */
    char pad14[0x1C - 0x14];
    int cursor;                 /* 0x1C */
} LinkTbl2A6;

typedef struct Obj2A6 {
    char pad000[0x18C];
    LinkTbl2A6 tbl;             /* 0x18C */
} Obj2A6;

extern int D_00747A38;
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

static inline LinkEnt2A6 *LinkTbl2A6_ent(LinkTbl2A6 *t, int i)
{
    long ok;
    int tt;

    ok = 0;
    if (i >= 0) {
        tt = i < t->nEnts;
        ok = tt;
    }
    if (ok & 0xFF)
        return &t->ents[i];
    return 0;
}

static inline void *LinkTbl2A6_vert(LinkTbl2A6 *t, int i)
{
    long ok;
    int tt;

    ok = 0;
    if (i >= 0) {
        tt = i < t->nVerts;
        ok = tt;
    }
    if (ok & 0xFF)
        return t->verts + i * 32;
    return 0;
}

__attribute__((section(".text.func_002A6FF8")))
void func_002A6FF8(Obj2A6 *self)
{
    LinkTbl2A6 *t;
    LinkEnt2A6 *e;
    int i;

    if (D_00747A38 & 0x80000)
        return;
    t = &self->tbl;
    if (t->nEnts <= 0)
        return;
    for (i = 0; i < 2; i++) {
        e = LinkTbl2A6_ent(t, self->tbl.cursor);
        if (e != 0 && e->a != 0xFFFF && e->b != 0xFFFF) {
            if (ChkLine(LinkTbl2A6_vert(t, e->a), LinkTbl2A6_vert(t, e->b), 0, 0, 1, 0x40, 0, 0,
                        0, 0, 0, 0, 1))
                e->flags |= 0x80000000;
            else
                e->flags &= 0x7FFFFFFF;
        }
        self->tbl.cursor = (unsigned int)(self->tbl.cursor + 1) % (unsigned int)t->nEnts;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A6FF8);
#endif
