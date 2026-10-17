/* NON_MATCHING func_00365D18 (cygnus-2.96, drop-reorder): 15 insns, same size; frame, layout and the target copy match, only the load schedule of the eight source words differs. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int unk00;
    int x;
    int unk08;
    int h;
    int w;
} RectSrc;

typedef struct {
    int x, w, h, unk0C;
} RectSize;

typedef struct {
    int v[4];
    int unk10[4];
} RectBox;

extern void *Obj0000_Get_D_003EEA98_365EB0(void);
extern void func_00365D90(RectSize *size, RectBox *box, void *dst);

void func_00365D18(RectSrc *a, RectSrc *b, void **target)
{
    RectSize size;
    RectBox box;
    void *cur;
    void *dst;

    size.x = a->x;
    size.w = a->w;
    size.h = a->h;
    cur = *target;
    box.v[0] = b->x;
    box.v[1] = b->unk08;
    box.v[2] = b->h;
    box.v[3] = b->w;
    dst = cur;
    if (cur == 0)
        dst = Obj0000_Get_D_003EEA98_365EB0();
    func_00365D90(&size, &box, dst);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00365D18);
#endif
