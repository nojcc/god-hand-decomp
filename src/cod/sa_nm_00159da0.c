/* NON_MATCHING func_00159DA0 (sn-2.95.3-136, as sn;
 * PARK, 8 diffs): only the v0/v1 alternation of the four lhu/sw
 * pairs that fill r is swapped; field type, fill form and local choice do not change it.
 * Computes a sprite UV rectangle
 * by source kind (1 byte coords via the texture page tables and func_00156550, 3 u16 coords with scale/offset pairs,
 * 5 float coords). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct I4 { int v[4]; } I4;

typedef struct Spr159DA0 {
    unsigned char kind;    /* 0x00 */
    char pad01[3];
    void *src;             /* 0x04 */
    void *cur;             /* 0x08 */
    char pad0c[4];
    float u0, v0, u1, v1;  /* 0x10 */
} Spr159DA0;

extern float func_00156508(int id);
extern void func_00156550(void *out, I4 *in);

__attribute__((section(".text.func_00159DA0")))
void func_00159DA0(Spr159DA0 *p)
{
    float ox, sx;
    I4 c;
    I4 r;
    unsigned char *b;
    unsigned char *b2;
    unsigned short *h2;
    unsigned short *h;
    float *f;
    float *g;
    unsigned short *h3, *h4;
    float *f3, *f5, *g5;

    switch (p->kind) {
    case 0:
        break;
    case 1:
        ox = func_00156508(((unsigned short *)p->src)[0]);
        sx = func_00156508(((unsigned short *)p->src)[1]);
        h = (unsigned short *)p->src;
        r.v[0] = h[2];
        r.v[1] = h[3];
        r.v[2] = h[4];
        r.v[3] = h[5];
        c = r;
        func_00156550(&r, &c);
        b = (unsigned char *)p->cur;
        b2 = b - 4;
        p->v0 = (float)b[1] * sx + ox;
        p->v1 = (float)b[2] * ((float *)&r)[1] + ((float *)&r)[0];
        p->u0 = (float)b2[1] * sx + ox;
        p->u1 = (float)b2[3] * ((float *)&r)[3] + ((float *)&r)[2];
        break;
    case 3:
        h3 = (unsigned short *)p->cur;
        f3 = (float *)p->src;
        h4 = h3 - 4;
        p->v0 = (float)h3[1] * f3[1] + f3[0];
        p->v1 = (float)h3[2] * f3[3] + f3[2];
        p->u0 = (float)h4[1] * f3[1] + f3[0];
        p->u1 = (float)h4[3] * f3[5] + f3[4];
        break;
    case 5:
        f5 = (float *)p->cur;
        g5 = f5 - 4;
        p->u0 = g5[1];
        p->v0 = f5[1];
        p->u1 = g5[3];
        p->v1 = f5[2];
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00159DA0);
#endif
