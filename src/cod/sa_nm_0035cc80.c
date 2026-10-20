/* NON_MATCHING func_0035CC80 (cygnus-2.96 --drop-reorder;
 * PARK, 88 diffs): arguments and call order are right; retail runs a 0x210 frame with one more 64-bit spill slot (the 0x1AC field) and loads the int fields in a different order, so every register and stack offset in the argument setup differs. */
#include "include_asm.h"

#ifdef NON_MATCHING
/* func_0035CC80: append one stream-timing debug line for a handle to the debug log buffer
 * (the log set up by func_0035CB20); wrap to the restart point when under 1 KB is left. */
extern char D_00459AA8[];
extern int D_003EE320;
extern int D_003EE31C;
extern int D_003EE328;
extern int D_003EE32C;
extern int D_003EE0A4;
extern int func_0036C920(int pos, int a, int rate);
extern int func_003A6C58(char *dst, const char *fmt, ...);
extern void func_003A57C4(int a0, char *a1);

__attribute__((section(".text.func_0035CC80")))
void func_0035CC80(char *h)
{
    char buf[0x100];
    int n;
    int t;
    long a;
    long cur;
    long prev;
    long start;

    if (D_003EE320 == 0)
        return;
    t = func_0036C920(1000, *(int *)(h + 0x118), *(int *)(h + 0x120));
    a = *(long *)(h + 0x118);
    start = *(long *)(h + 0x128);
    cur = *(long *)(h + 0x188) ;
    prev = *(long *)(h + 0x108);
    n = func_003A6C58(buf, D_00459AA8, h, a / *(long *)(h + 0x120), (long)t,
                      a >> 32, a, a & 0x7FFFFFFF,
                      cur, prev, start, prev - start, cur - start,
                      (long)*(int *)(h + 0x1AC), (long)*(int *)(h + 0x1B0),
                      (long)*(int *)(h + 0x1B4), (long)*(int *)(h + 0x1B8),
                      (long)*(unsigned int *)(h + 0x4), (long)*(unsigned int *)(h + 0x8),
                      (long)*(int *)(h + 0x19C), (long)*(int *)(h + 0x1A0),
                      (long)*(int *)(h + 0x190), (long)*(int *)(h + 0x194),
                      (long)*(int *)(h + 0x198), (long)*(int *)(h + 0x1A4),
                      (long)*(int *)(h + 0x1A8), (long)D_003EE0A4);
    func_003A57C4(D_003EE328, buf);
    D_003EE328 = D_003EE328 + n;
    if ((unsigned int)D_003EE328 >= (unsigned int)(D_003EE320 + D_003EE31C - 0x400))
        D_003EE328 = D_003EE32C;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035CC80);
#endif
