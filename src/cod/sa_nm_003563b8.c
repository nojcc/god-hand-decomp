/* NON_MATCHING func_003563B8 (cygnus-2.96 --drop-reorder;
 * PARK, 7 diffs): only the scheduling of the final state-reset
 * stores differs (retail: three sb, then the int stores in offset order, with 1 in v1 and -1 in v0); no source order
 * found by hill-climb reproduces it.
 * Sets up the movie decoder work at 0x1FC0 and creates the vi buffer. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int D_003EE2F4;
extern int ReturnK_003EE2BC_00358A38_358A38(void);
extern void func_00399E40(void *mp, int buf, int size);
extern void func_0039AAD8(void *mp, int kind, void *cb, void *data);
extern void func_00356890(void *self);
extern void viBufCreate(void *vb, int a, int b, int n, int c, int m);
extern void viBufAddDMA(void *vb);
extern void func_00355E88(void *vb);
extern void func_003565E0(void);
extern void func_003566E8(void);
extern void func_00356790(void);
extern void func_003567B8(void);

typedef struct MovHdr { int pad0, pad4, w, h, buf; } MovHdr;

__attribute__((section(".text.func_003563B8")))
void func_003563B8(char *self)
{
    char *w = *(char **)(self + 0x1FC0);
    MovHdr *h = (MovHdr *)(w + 4);
    char *st = w + 0x1128;
    char *mp = w + 0x1150;
    char *ix = w + 0x11F8;
    int size, a28, a2c, b0, b1;
    int t, v;

    if (D_003EE2F4 == 0) {
        *(int *)st = 0;
        return;
    }
    size = h->w * h->h * 9 / 2 + 0x2800;
    if (*(int *)(w + 0x28) == 0) {
        t = (h->buf + 0x3F) & ~0x3F;
        *(int *)(w + 0x28) = t;
        t = (t + size + 0x3F) & ~0x3F;
        *(int *)(w + 0x2C) = t;
    } else {
        *(int *)(w + 0x28) = (*(int *)(w + 0x28) + 0x3F) & ~0x3F;
        *(int *)(w + 0x2C) = (*(int *)(w + 0x2C) + 0x3F) & ~0x3F;
    }
    a2c = *(int *)(w + 0x2C);
    a28 = *(int *)(w + 0x28);
    b0 = (a2c + 0x8003F) & ~0x3F;
    b1 = (b0 + 0x104F) & ~0x3F;
    if (ReturnK_003EE2BC_00358A38_358A38() != 1) {
        func_00399E40(mp, a28, size);
        func_0039AAD8(mp, 0, func_003565E0, self);
        func_0039AAD8(mp, 1, func_003566E8, self);
        func_0039AAD8(mp, 2, func_00356790, self);
        func_0039AAD8(mp, 3, func_003567B8, self);
    } else {
        func_00356890(self);
    }
    viBufCreate(st + 0x70, a2c, b0, 0x100, b1, 0x200);
    viBufAddDMA(st + 0x70);
    func_00355E88(st + 0x70);
    st[0x10] = 0;
    st[0x12] = 0;
    *(int *)(ix + 0x0) = -1;
    *(int *)(st + 0x00) = 1;
    *(int *)(st + 0x20) = 0;
    *(int *)(ix + 0x4) = 0;
    *(int *)(st + 0x04) = 0;
    *(int *)(st + 0x08) = 0;
    *(int *)(st + 0x0C) = 0;
    st[0x11] = 0;
    *(int *)(st + 0x18) = 0;
    *(int *)(st + 0x1C) = 0;
    *(int *)(st + 0x14) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003563B8);
#endif
