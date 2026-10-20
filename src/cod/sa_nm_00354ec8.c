/* NON_MATCHING func_00354EC8 (cygnus-2.96 --drop-reorder; PARK, 124 diffs): field copy matches, but retail hoists
 * the source loads above the record stores (first-pass scheduling, t0-t2 temporaries) while keeping the record
 * stores and the *out reloads in order; no typing of the pointers reproduces both. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define W(b, o) (*(int *)((char *)(b) + (o)))
#define H(b, o) (*(unsigned short *)((char *)(b) + (o)))
#define B(b, o) (*(unsigned char *)((char *)(b) + (o)))
#define L(b, o) (*(long *)((char *)(b) + (o)))

extern int *func_00355490(char *ctx);

__attribute__((section(".text.func_00354EC8")))
void func_00354EC8(char *ctx, char *src, char **out)
{
    char *cur;
    int *p;
    char *d;
    char *h;

    cur = *(char **)(ctx + 0x1FC0);
    p = func_00355490(ctx);
    h = src + 0x5C;
    *p = 1;
    d = (char *)(p + 2);
    W(d, 0x00) = W(h, 0x00);
    W(d, 0x04) = W(h, 0x04);
    W(d, 0x08) = W(h, 0x08);
    W(d, 0x0C) = W(h, 0x0C);
    W(d, 0x10) = W(h, 0x18);
    W(d, 0x14) = W(src, 0x38);
    W(d, 0x18) = W(src, 0x3C);
    W(d, 0x1C) = W(ctx, 0x38);
    W(d, 0x20) = W(src, 0x08);
    W(d, 0x24) = W(src, 0x40);
    W(d, 0x28) = W(src, 0x44);
    W(d, 0x2C) = W(src, 0x48);
    W(d, 0x30) = W(src, 0x4C);
    W(d, 0x34) = W(src, 0x50);
    W(d, 0x38) = W(src, 0x54);
    W(d, 0x3C) = W(h, 0x40);
    W(d, 0x40) = W(h, 0x44);
    if (W(h, 0x40) == 0)
        W(d, 0x48) = 2;
    else
        W(d, 0x48) = 1;
    *(char **)(cur + 0x70) = src;
    *out = d;
    L(*out, 0x50) = L(src, 0xE0);
    W(*out, 0x58) = W(h, 0x38);
    W(*out, 0x5C) = W(h, 0x3C);
    W(*out, 0x60) = W(h, 0x48);
    W(*out, 0x64) = W(h, 0x4C);
    H(*out, 0x68) = H(h, 0x50);
    H(*out, 0x6A) = H(h, 0x52);
    B(*out, 0x6C) = B(h, 0x55);
    B(*out, 0x6D) = B(h, 0x56);
    B(*out, 0x6E) = B(h, 0x57);
    B(*out, 0x6F) = B(h, 0x59);
    B(*out, 0x70) = B(h, 0x5A);
    B(*out, 0x71) = B(h, 0x5B);
    B(*out, 0x72) = B(h, 0x5C);
    B(*out, 0x73) = B(h, 0x5D);
    B(*out, 0x74) = B(h, 0x5E);
    B(*out, 0x75) = B(h, 0x5F);
    B(*out, 0x76) = B(h, 0x60);
    B(*out, 0x77) = B(h, 0x61);
    B(*out, 0x78) = B(h, 0x62);
    B(*out, 0x79) = B(h, 0x63);
    B(*out, 0x7A) = B(h, 0x64);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00354EC8);
#endif
