/* sn-2.95.3-136 */
/* func_002A2ED0 (palette gradient): 458 of 454 words. Retail rounds the float-to-int conversions with cvt.w.s where this C
 * gets trunc.w.s, keeps fill in fp and 255.0f in f22, and builds the 0xFF0000
 * and 0xFFFFFF masks inside the loops; its fill loop also carries the
 * short-loop nops neither assembler adds to this C. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cScrSpriteDraw.h"
#include "godhand/cCamManager.h"
#include "godhand/cCamera.h"

/* The colour and alpha keys of a 256-entry palette gradient. */
typedef struct ClutGrad {
    unsigned short n;           /* 0x00 colour keys */
    unsigned short nAlpha;      /* 0x02 alpha keys */
    unsigned int col[8];        /* 0x04 */
    unsigned short pos[8];      /* 0x24 */
    unsigned int alpha[8];      /* 0x34 */
    unsigned short alphaPos[8]; /* 0x54 */
} ClutGrad;

extern void SortPair_quicksort(short *key, int *val, int lo, int hi);
extern float func_003A1F38(float x, float y);

/* Build a 256-entry palette from the sorted colour keys (placed along a gamma
 * curve) and then the alpha keys. In mode 1 every eighth entry is fill and the
 * gamma follows the current camera's field of view. */
__attribute__((section(".text.func_002A2ED0")))
void func_002A2ED0(const ClutGrad *src, unsigned int *tbl, int mode, unsigned int fill)
{
    ClutGrad g;
    float gamma;
    int n;
    int na;
    int i;
    float hi;
    float lo;
    int j;
    int next;
    unsigned int cnt;
    unsigned int k;
    unsigned int idx;
    unsigned int c0;
    unsigned int c1;
    unsigned int *p;
    float fc;
    float fr;
    float fg;
    float fb;
    float fa;
    int dr;
    int dg;
    int db;
    int r;
    int gr;
    int b;

    n = src->n;
    na = src->nAlpha;
    g = *src;
    gamma = 1.0f;
    if (mode == 1)
        gamma = 31.0f / (D_005CAFF0->fov * 2.0f) * 2.0f;
    for (j = 255; j >= 0; j--)
        tbl[j] = 0x80FFFFFF;
    i = 0;
    if (n != 0) {
        n--;
        SortPair_quicksort((short *)g.pos, (int *)g.col, 0, n);
        do {
            next = i + 1;
            k = 0;
            hi = func_003A1F38(g.pos[next] / 255.0f, gamma);
            lo = func_003A1F38(g.pos[i] / 255.0f, gamma);
            cnt = func_0031ED08(hi * 255.0f) - func_0031ED08(lo * 255.0f) + 1;
            idx = func_0031ED08(func_003A1F38(g.pos[i] / 255.0f, gamma) * 255.0f);
            c0 = g.col[i];
            c1 = g.col[next];
            if (mode != 0)
                cnt -= cnt >> 3;
            fc = (float)cnt;
            db = ((c1 & 0xFF0000) >> 16) - ((c0 & 0xFF0000) >> 16);
            dg = ((c1 & 0xFF00) >> 8) - ((c0 & 0xFF00) >> 8);
            dr = (c1 & 0xFF) - (c0 & 0xFF);
            fb = db / fc;
            fg = dg / fc;
            fr = dr / fc;
            p = &tbl[idx];
            do {
                if (mode != 0 && (idx & 7) == 0) {
                    *p++ = fill;
                    idx++;
                }
                r = (float)(c0 & 0xFF) + fr * (float)k;
                gr = (float)((c0 & 0xFF00) >> 8) + fg * (float)k;
                b = (float)((c0 & 0xFF0000) >> 16) + fb * (float)k;
                *p++ = (r & 0xFF) | ((gr << 8) & 0xFF00) | ((b << 16) & 0xFF0000) | 0x80000000;
                k++;
                idx++;
            } while (--cnt != 0);
            i = next;
        } while (--n != 0);
    }
    i = 0;
    if (na != 0) {
        na--;
        SortPair_quicksort((short *)g.alphaPos, (int *)g.alpha, 0, na);
        do {
            next = i + 1;
            idx = g.alphaPos[i];
            cnt = g.alphaPos[next] - g.alphaPos[i] + 1;
            c0 = g.alpha[i];
            c1 = g.alpha[next];
            k = 0;
            if (mode != 0)
                cnt -= cnt >> 3;
            fc = (float)cnt;
            fa = (int)(((c1 & 0xFF000000) >> 24) - ((c0 & 0xFF000000) >> 24)) / fc;
            p = &tbl[idx];
            do {
                if (mode != 0 && (idx & 7) == 0) {
                    *p++ = fill;
                    idx++;
                }
                *p = (*p & 0xFFFFFF)
                   | ((int)((float)((c0 & 0xFF000000) >> 24) + fa * (float)k) << 24);
                p++;
                k++;
                idx++;
            } while (--cnt != 0);
            i = next;
        } while (--na != 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A2ED0);
#endif
