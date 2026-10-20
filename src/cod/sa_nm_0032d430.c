/* NON_MATCHING func_0032D430 (cygnus-2.96 dr;
 * PARK, 44 diffs): control flow, frame, search-loop pad and s-regs match;
 * retail schedules the handle init stores and the size math with less pre-RA reordering (constants reloaded into v0
 * right before each store), ours hoists them. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    signed char used;
    char f1;
    char f2;
    signed char nch;
    int f4;
    int f8;
    char pad0C[0x80];
    int f8C;
    int f90;
    char f94[0x80];
    char *f114;
    int f118;
    int f11C;
    char *buf[0x20];
    int f1A0;
    int f1A4;
    int f1A8;
    int pad1AC;
    char f1B0;
    char f1B1;
    char pad1B2[6];
    int f1B8;
    int f1BC;
    int f1C0;
    int f1C4;
    int f1C8;
    char *f1CC;
    char pad1D0[0x14];
    int f1E4;
    char pad1E8[0x84];
    int f26C;
    int f270;
    int f274;
} Hn32D430;

extern void Obj33F8_Tramp_0033F130_FCB0(char *);
extern void func_003A52F0(void *, int, int);
extern int func_0032ED70(Hn32D430 *, char *, int);
extern int func_003395A0(char *, int, int);
extern int func_0032F2D8(int, int, char *);
extern int func_00327D00(int, int);
extern void func_003283E8(int, void *, Hn32D430 *);
extern void func_0032E488(void);
extern void func_0032D720(Hn32D430 *);

extern Hn32D430 D_003D1488[4];
extern char D_004529D0[];

#define I(h, o) (*(int *)((h) + (o)))

__attribute__((section(".text.func_0032D430")))
char *func_0032D430(int *prm, char *buf, int size)
{
    char *pos = (char *)(((int)buf + 0x3F) & ~0x3F);
    int rem = size - (pos - buf);
    int i;
    Hn32D430 *h;
    int n;
    int k;
    char **p;
    int sz;
    int x;
    int rs;

    if (buf == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_004529D0);
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (D_003D1488[i].used == 0)
            break;
    }
    if (i == 4)
        return 0;
    h = &D_003D1488[i];
    func_003A52F0(h, 0, 0x278);
    h->nch = *(unsigned char *)&prm[0];
    h->f1A0 = 0x2000;
    h->f26C = prm[2];
    h->f1A4 = 0x40;
    h->f2 = *(unsigned char *)&prm[1];
    if (prm[2] == 1)
        n = prm[0] * 0x85C0;
    else
        n = prm[0] * (prm[1] * 0x40C0 + 0x40);
    x = func_0032ED70(h, pos, n);
    if (x < 0)
        goto fail;
    rem -= n;
    if (rem < 0)
        goto fail;
    pos += n;
    p = h->buf;
    for (k = 0; k < h->nch; k++) {
        sz = h->f1A0 + h->f1A4;
        *p = pos;
        rem -= sz;
        if (rem < 0)
            goto fail;
        pos += sz;
        x = func_003395A0(*p, h->f1A0, h->f1A4);
        *(int *)((char *)p - 0x8C) = x;
        if (!x)
            goto fail;
        p++;
    }
    h->f11C = 0x2000;
    h->f114 = pos;
    rs = ((rem - 0x2100) / 2048) * 2048;
    h->f118 = rs;
    sz = rs + 0x2000;
    rem -= sz;
    if (rem < 0)
        goto fail;
    pos += sz;
    h->f1CC = pos;
    if (rem < 0x100)
        goto fail;
    h->f90 = 0;
    x = func_003395A0(h->f114, rs, 0x2000);
    h->f8C = x;
    if (!x)
        goto fail;
    x = func_0032F2D8(prm[0], h->f90, h->f94);
    h->f4 = x;
    if (!x)
        goto fail;
    x = func_00327D00(h->f8C, 0);
    h->f8 = x;
    if (!x)
        goto fail;
    func_003283E8(x, func_0032E488, h);
    h->f1A8 = 0;
    h->f1B1 = 1;
    h->used = 1;
    h->f1B0 = 0;
    h->f1B8 = 0;
    h->f1C0 = 0;
    h->f1BC = 0;
    h->f1C4 = 0;
    h->f1C8 = 1;
    h->f1E4 = 0;
    h->f270 = 0;
    h->f274 = 0;
    return (char *)h;
fail:
    func_0032D720(h);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0032D430);
#endif
