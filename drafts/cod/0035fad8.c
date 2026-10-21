#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int used;        /* 0x00 */
    int f4, f8, fC;  /* 0x04 */
    char pad10[0x28 - 0x10];
    int f28;         /* 0x28 */
    int f2C;         /* 0x2C */
    int pad30;
    int f34;         /* 0x34 */
    int base;        /* 0x38 */
    int buf[3];      /* 0x3C */
    char pad48[0x50 - 0x48];
    int work;        /* 0x50 */
    int size;        /* 0x54 */
    int f58;         /* 0x58 */
    char pad5C[0x64 - 0x5C];
    int f64;         /* 0x64 */
} DecWork;

extern void func_003A52F0(void *p, int c, int n);

void func_0035FAD8(DecWork *w, int work, int size)
{
    int base;
    int b0, b1, b2;

    func_003A52F0(w, 0, 0x94);
    base = (work + 0x1F) & ~0x1F;
    b2 = base + 0xC00;
    b0 = base + 0x400;
    b1 = base + 0x800;
    w->work = work;
    w->size = size;
    w->used = 1;
    w->buf[0] = b0;
    w->buf[1] = b1;
    w->buf[2] = b2;
    w->f58 = -1;
    w->f4 = 0;
    w->f8 = 0;
    w->fC = 0;
    w->f28 = 1;
    w->f2C = 0;
    w->f34 = 0;
    w->base = base;
    w->f64 = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035FAD8);
#endif
