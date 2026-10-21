/* NON_MATCHING func_0039CCC0 (ee-2.9-991111): retail keeps the per-macroblock field bases mp+0x6C8/0x6D0/0x6D4/0x6D8 in s1-s4 (set up before each DMA poll loop) and spills flags & 1 to the stack; our build keeps one base and fewer saved registers.
* The extra nops in the second poll loop are the assembler's short-loop padding; libmpeg macroblock setup */
#include "include_asm.h"

#ifdef NON_MATCHING
extern char D_0045E6A0[];
extern void func_0039C3E8(void *mp, char *msg, int type);
extern void func_0039C5B8(void *mp, int x, int y, int flags, int a4, int a5, int a6);
extern void dmaRefImage(void *mp);

typedef struct {
    int ref;
    int pad4;
    int intra;
    int fwd;
    int done;
    char pad[0x140 - 0x14];
} MbEnt;
#define MB(mp, f) (((MbEnt *)((mp) + 0x6C8))[*(int *)((mp) + 0x820)].f)

__attribute__((section(".text.func_0039CCC0")))
int func_0039CCC0(char *mp, int n, int mode, int flags, int type)
{
    int intra = flags & 1;
    int w = *(int *)(mp + 0x13C);
    int q = n / w;
    int r = n % w;
    int x = r << 4;
    int y = q << 4;
    int t;
    char *b;

    if (intra) {
        while ((*(volatile unsigned int *)0x1000D400 >> 8) & 1)
            ;
        MB(mp, done) = 0;
    } else {
        if ((unsigned int)(type - 1) >= 3) {
            func_0039C3E8(mp, D_0045E6A0, type);
            *(int *)(mp + 0x12C) = 1;
            return 0;
        }
        func_0039C5B8(mp, x, y, flags);
        while ((*(volatile unsigned int *)0x1000D400 >> 8) & 1)
            ;
        dmaRefImage(mp);
        MB(mp, done) = 1;
    }
    if (mode == 1 && (flags & 2))
        MB(mp, fwd) = mode;
    else
        MB(mp, fwd) = 0;
    MB(mp, intra) = intra;
    t = *(int *)(mp + 0x184);
    if (t == 3) {
        b = *(char **)(mp + 0x1D0);
        MB(mp, ref) = *(int *)b + (r * *(int *)(b + 0x10) + q) * 0x180;
    } else {
        if (t == 2)
            b = *(char **)(mp + 0x1F0);
        else
            b = *(char **)(mp + 0x1E0);
        MB(mp, ref) = *(int *)b + (r * *(int *)(b + 0x10) + q) * 0x180;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0039CCC0);
#endif
