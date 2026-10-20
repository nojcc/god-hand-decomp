/* NON_MATCHING func_002D4340 (sn-2.95.3-136): DMA REF-tag strip packet + screen rect FTOI4; register allocation and global hi/lo placement differ throughout. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_007474A0[];
extern int D_003C1180;
extern int D_00586B80;
extern char D_00754C80[];
extern void sceVu0FTOI4Vector(int *out, float *in);
extern void func_0031A650(void *a0, int a1, int a2, void *a3, void *t0);

static inline char *game(void)
{
    return D_007474A0;
}

typedef struct {
    char pad0[0xC];
    char *pkt[2];
    int pad14;
    char *tex;
    short h;
    unsigned short w;
    short x;
    short y;
    short dw;
    short dh;
    int fmt;
} Spr;

__attribute__((section(".text.func_002D4340")))
void func_002D4340(Spr *s)
{
    float v[2][4];
    int iv[2][4];
    char *p;
    char *tex;
    unsigned int sz;
    unsigned short w;
    int n, i;
    float *fv;
    int *ip;

    tex = s->tex;
    if (tex == 0)
        return;
    n = s->h / 16;
    p = s->pkt[*(int *)(game() + 0x210) & 1];
    w = s->w;
    if (s->fmt == 0x21)
        w = (short)w / 2;
    sz = (short)w << 6;
    p += 0x40;
    if (n > 0) {
        unsigned int q = sz >> 4;
        unsigned long lo = (unsigned int)(q | 0x30000000);
        int t = q | 0x50000000;
        for (i = n; i != 0; i--) {
            p += 0x50;
            *(int *)(p + 8) = 0;
            *(int *)(p + 0xC) = t;
            *(unsigned long *)p = lo | ((unsigned long)((unsigned int)tex & 0xFFFFFFF) << 32);
            tex += sz;
            p += 0x10;
        }
    }
    p += 0x120;
    v[0][0] = s->x;
    v[0][1] = s->y;
    v[1][0] = s->dw + s->x;
    v[1][1] = s->dh + s->y;
    v[1][2] = 65500.0f;
    v[1][3] = 1.0f;
    v[0][2] = 65500.0f;
    v[0][3] = 1.0f;
    fv = v[1];
    ip = iv[1];
    for (i = 2; i != 0; i--) {
        sceVu0FTOI4Vector(ip, fv);
        fv -= 4;
        ip[1] += D_00586B80 << 4;
        ip[0] += (0x800 - D_003C1180 / 2) << 4;
        ip -= 4;
    }
    func_0031A650(D_00754C80, 6, (0x400 - (iv[0][2] >> 8)) & 0xFFF,
                  s->pkt[*(int *)(game() + 0x210) & 1], p);
}

#else
INCLUDE_ASM("asm/nonmatching", func_002D4340);
#endif
