#include "include_asm.h"

#include "godhand/cIDBaseAnim.h"

#ifdef NON_MATCHING
/* 5 words short: retail keeps cells-1 and step+1 separate in the reverse modes and allocates self/step differently. */
#define IDSRC_F_UVANIM   0x2000000      /* source flag: the texture steps through a grid of cells */
#define IDSRC_F_UVLOOP   0x100000       /* source flag: the cell animation loops */
#define ENT_F_UV_DONE    0x4000         /* entry flag: the cell animation reached its end */

__attribute__((section(".text.func_002ABDC0")))
void func_002ABDC0(cIDBaseObj *self, cIDBaseEnt *ent)
{
    cIDBaseSrcAnim *src = (cIDBaseSrcAnim *)ent->src;
    int cells, step, bounce, idx, col, row, loop, m;
    unsigned long bits;

    if ((src->flags & IDSRC_F_UVANIM) == 0) return;
    if (ent->flags & ENT_F_UV_DONE) return;
    if (src->uvStop != 0) return;

    cells = src->uvCols * src->uvRows;
    if ((unsigned short)ent->jit[0] % src->uvRate == 0) {
        self->b1D = 0;
        idx = 0;
        step = ((unsigned short)ent->jit[0] / src->uvRate) % (cells * cells);
        bounce = step;
        if (step >= cells)
            bounce = (cells - 1) * 2 - (unsigned short)ent->jit[0];
        switch (src->uvMode) {
        case 0: idx = step; break;
        case 1: idx = bounce; break;
        case 2: idx = cells - (step + 1); break;
        case 3: idx = cells - (bounce + 1); break;
        }
        col = idx % src->uvCols;
        row = idx / src->uvCols;
        ent->f70[0] = (float)col / (float)src->uvCols;
        ent->f70[2] = (float)(col + 1) / (float)src->uvCols;
        row = row % src->uvRows;
        ent->f70[1] = (float)row / (float)src->uvRows;
        ent->f70[3] = (float)(row + 1) / (float)src->uvRows;
        loop = (src->flags & IDSRC_F_UVLOOP) != 0;
        switch (src->uvMode) {
        case 0:
        case 2:
            if (step < cells) break;
            m = ent->flags;
            if (loop) ent->flags = m & ~ENT_F_UV_DONE;
            else ent->flags = m | ENT_F_UV_DONE;
            break;
        case 1:
        case 3:
            if (step < cells * 2 - 1) break;
            m = ent->flags;
            if (loop) ent->flags = m & ~ENT_F_UV_DONE;
            else ent->flags = m | ENT_F_UV_DONE;
            break;
        }
    }
    bits = ent->flags;
    if (((bits >> 5) & 1) == 0)
        ent->jit[0] = (unsigned short)ent->jit[0] + 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002ABDC0);
#endif
