/* ee-2.9-991111 */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, output.o :: _dispRefImageField
 *
 * NON_MATCHING: 262 of 264 words. Retail reloads c + 0x868, 0x9C and
 * 0x108 after the second field's pts store, as if that store could
 * alias them; this C keeps them in registers. */
#include "include_asm.h"

#ifdef NON_MATCHING

extern long long func_0031DE10(long long a, long long b);
extern void func_003B1EE0(char *buf, int size, char *fmt, int a, int b);
extern void func_0039C390(char *c, char *msg);
extern void func_0039BB20(char *c, char *pic);
extern void _cpr8(char *c, char *pic);
extern char D_0045E5A8[];

/* Show a decoded picture as two fields: set up the GS display registers for
 * the first and the second field (top picture first when c + 0x184 is 2),
 * check that the picture fits the output buffer, and copy it out. */
__attribute__((section(".text._dispRefImageField")))
void _dispRefImageField(char *c, char *pic0, char *pic1, int n)
{
    /* n (the picture index the caller passes) is not read. */
    char buf[0x100];
    int mask;
    char *first;
    char *second;
    char *g;
    long long *p10;
    long long *p18;
    long long *p20;
    long long *p28;
    long long *p30;
    long long *p38;
    int ok;
    int f;

    mask = 0;
    if (*(int *)(c + 0x184) == 2) {
        first = pic0;
        second = pic1;
        mask = 0x40;
    } else {
        first = pic1;
        second = pic0;
    }
    g = *(char **)(c + 0x868);
    p10 = (long long *)(g + 0x10);
    p18 = (long long *)(g + 0x18);
    p20 = (long long *)(g + 0x20);
    if (*(int *)(c + 0x8C) != 0 && *(long long *)(first + 0x18) < 0
        && *(int *)(c + 0x98) >= 0) {
        int b = (int)*(long long *)(c + 0xA0);
        long long a = *(long long *)(c + 0x90);
        int b1 = b & 1;
        int s = (b & 1) & ((*(int *)(c + 0x9C) & 1) & (a & 1));
        int r = (int)(func_0031DE10(a, (long long)b) >> 1);
        *(long long *)(g + 0x10) = *(int *)(c + 0x98) + (r + s);
        if ((b1 & *(long long *)(c + 0x90)) != 0)
            *(int *)(c + 0x9C) = *(int *)(c + 0x9C) + 1;
    } else {
        *p10 = *(long long *)(first + 0x18);
    }
    if (*(int *)(c + 0x108) == 2 && *(long long *)(c + 0x100) >= 0) {
        *p10 = *(long long *)(c + 0x100);
        *(int *)(c + 0x108) = 0;
        *(long long *)(c + 0x100) = -1;
    }
    *p18 = *(long long *)(first + 0x20);
    *p20 = ((long long)*(int *)(first + 0x34) << 8)
         | ((long long)*(int *)(first + 0x38) << 7)
         | ((long long)*(int *)(first + 0x3C) << 6)
         | ((long long)*(int *)(first + 0x40) << 5)
         | ((long long)*(int *)(first + 0x30) << 3)
         | (long long)*(int *)(first + 0x2C);
    *(int *)(c + 0x98) = (int)*(long long *)(*(char **)(c + 0x868) + 0x10);
    *(long long *)(c + 0xA0) = 1;
    p28 = (long long *)(*(char **)(c + 0x868) + 0x28);
    p30 = (long long *)(*(char **)(c + 0x868) + 0x30);
    p38 = (long long *)(*(char **)(c + 0x868) + 0x38);
    if (*(int *)(c + 0x8C) != 0 && *(long long *)(second + 0x18) < 0
        && *(int *)(c + 0x98) >= 0) {
        long long a = *(long long *)(c + 0x90);
        int s = (*(int *)(c + 0x9C) & 1) & (int)(a & 1);
        int r = (int)(a >> 1);
        *(long long *)(*(char **)(c + 0x868) + 0x28) =
            *(int *)(c + 0x98) + (r + s);
        if ((*(long long *)(c + 0x90) & 1) != 0)
            *(int *)(c + 0x9C) = *(int *)(c + 0x9C) + 1;
    } else {
        *p28 = *(long long *)(second + 0x18);
    }
    if (*(int *)(c + 0x108) == 2 && *(long long *)(c + 0x100) >= 0) {
        *p28 = *(long long *)(c + 0x100);
        *(int *)(c + 0x108) = 0;
        *(long long *)(c + 0x100) = -1;
    }
    *p30 = *(long long *)(second + 0x20);
    *p38 = ((long long)*(int *)(second + 0x34) << 8)
         | ((long long)*(int *)(second + 0x38) << 7)
         | ((long long)*(int *)(second + 0x3C) << 6)
         | ((long long)*(int *)(second + 0x40) << 5)
         | ((long long)*(int *)(second + 0x30) << 3)
         | (long long)*(int *)(second + 0x2C);
    *(int *)(c + 0x98) = (int)*(long long *)(*(char **)(c + 0x868) + 0x28);
    *(long long *)(c + 0xA0) = 1;
    *(long long *)(*(char **)(c + 0x868) + 0x20) |= mask;
    *(long long *)(*(char **)(c + 0x868) + 0x38) |= mask;
    *(int *)(c + 0xE0) = *(int *)(first + 0x5C);
    *(int *)(c + 0xE4) = *(int *)(first + 0x60);
    *(int *)(c + 0xC8) = *(int *)(first + 0x44);
    *(int *)(c + 0xCC) = *(int *)(second + 0x48);
    *(int *)(c + 0xD4) = *(int *)(first + 0x50);
    *(int *)(c + 0xD8) = *(int *)(second + 0x54);
    f = *(int *)(c + 0xF4);
    if (f != 0)
        ok = *(int *)(c + 0xF0) >= *(int *)(pic0 + 0x4)
          && f >= *(int *)(pic0 + 0x8);
    else
        ok = *(int *)(c + 0xF8) >= *(int *)(pic0 + 0xC) * *(int *)(pic0 + 0x10);
    if (ok == 0) {
        func_003B1EE0(buf, 0x100, D_0045E5A8, *(int *)(pic0 + 0x4),
                      *(int *)(pic0 + 0x8));
        func_0039C390(c, buf);
    }
    if (ok != 0) {
        if (*(int *)(pic0 + 0x28) == 1 && *(int *)(pic1 + 0x28) == 1) {
            *(int *)(pic0 + 0x10) <<= 1;
            if (*(int *)(c + 0xC4) != 0)
                func_0039BB20(c, pic0);
            else
                _cpr8(c, pic0);
            *(int *)(pic0 + 0x10) >>= 1;
            if (*(int *)(c + 0x8) != 2) {
                *(int *)(c + 0x8) = 2;
                *(int *)(c + 0xC0) = *(int *)(c + 0x128);
            }
            *(int *)(c + 0x834) = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", _dispRefImageField);
#endif
