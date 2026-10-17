/* Batch 30 near-misses — not registered.
 * 84: VU Adjust_theta_vec; bitfield decode schedule; list scan; ld/sd slot;
 *     float copy beql/const; ID release lui/v0 vs v1 (1 word); flag dsrl
 *     const order (2 words); beql task exit; FP-frame thunk; RNG nibble;
 *     dispatch beql.
 * 6-attempt cap. Closest: SlotUi_release (1), func_002BF420 (2). */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void cIDBase_release(void *p);
extern void cHeap_free(void *heap, void *block);
extern char *D_003C2384;
extern int D_00747A84[];
extern void cTaskWork_exit(void *p);
extern int func_00307878(void *a0, void *a1);
extern char D_00747A80[];
extern char D_0076A790[];
extern int func_0037C388(void *a0);
extern int func_0037C420(void *a0);
extern int func_0037C4C0(void *a0);

__attribute__((section(".text.Adjust_theta_vec")))
void Adjust_theta_vec(void *a0)
{
    (void)a0;
}

__attribute__((section(".text.func_002A4BA0")))
int func_002A4BA0(char *base, unsigned int id)
{
    char *a2 = base;
    unsigned int a0 = id & 0xFFFF;
    unsigned int hi;
    char *row;
    int v;
    int *tbl;
    unsigned short lim;
    int w;

    if (a0 == 0)
        return 0;
    hi = a0 >> 12;
    hi <<= 4;
    a0 &= 0xFFF;
    row = a2 + hi;
    a0 <<= 2;
    tbl = *(int **)(row + 4);
    lim = *(unsigned short *)(row + 0xE);
    w = *(int *)((char *)tbl + a0 + 8);
    w = (unsigned)w >> 14;
    w &= 0x3F;
    v = (int)lim - w;
    v = (short)v;
    return v;
}

__attribute__((section(".text.func_002BEAA8")))
void *func_002BEAA8(int **a0, unsigned int key)
{
    char *p = (char *)*a0;
    unsigned int n;
    char *slot;
    unsigned int i;

    key &= 0xFFFF;
    if (p == 0)
        return 0;
    n = *(unsigned int *)p;
    if (n == 0)
        return 0;
    p += 0x10;
    slot = p;
    i = 0;
    do {
        i++;
        if (*(unsigned short *)p == key)
            return slot;
        slot += 4;
        p += 4;
    } while (i < n);
    return 0;
}

__attribute__((section(".text.func_002BECB0")))
void func_002BECB0(int **a0, int *val)
{
    unsigned int i = 0;
    char *base;
    char *slot;
    int one = 1;

    if (val == 0)
        return;
    base = (char *)*a0 + 0x610;
    slot = base;
    do {
        if (*(int *)base == 0 && *((int *)base + 1) == 0) {
            *(int **)slot = val;
            base = (char *)*a0 + (i << 4);
            *((char *)base + 0x618) = (char)one;
            return;
        }
        i++;
        slot += 0x10;
        base += 0x10;
    } while (i < 0x100);
}

__attribute__((section(".text.func_00377FA0")))
int func_00377FA0(void)
{
    char *p = D_0076A790;
    short v = *(short *)(p + 0x20);
    unsigned short u = *(unsigned short *)(p + 0x20);
    unsigned short u2 = *(unsigned short *)(p + 0x20);
    int t = (int)v * 3;
    int b;
    int r;

    t <<= 16;
    t >>= 24;
    b = (u + t) & 0xFF;
    t &= 0xFF;
    r = b | (t << 8);
    if (u2 == (short)r)
        r = u2 + 1;
    *(unsigned short *)(p + 0x20) = (unsigned short)r;
    return r & 0xFF;
}

#else
INCLUDE_ASM("asm/nonmatching", Adjust_theta_vec);
INCLUDE_ASM("asm/nonmatching", func_002A4BA0);
INCLUDE_ASM("asm/nonmatching", func_002BEAA8);
INCLUDE_ASM("asm/nonmatching", func_002BECB0);
INCLUDE_ASM("asm/nonmatching", func_00377FA0);
#endif
