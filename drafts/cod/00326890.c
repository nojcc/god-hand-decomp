/* NON_MATCHING func_00326890 (cygnus-2.96): stream header parse; retail assembler padded the two-block zero-skip loop with 3 nops after the inner exit branch, which our ee-as never does (multi-block), so everything after it is shifted by 3 words */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int GetD003E9D5C_33C718(void);
extern void func_0033F1A8(void *a0, void *a1);
extern void func_0033ACA0(void *a0, int a1, void *a2, void *a3);
extern int func_0033CCF0(void *a0, void *a1, int a2);
extern void func_0033CC50(void *a0);
extern int Obj33C8_GetShort_98(void *a0);
extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern char D_00451E48[];
extern char D_00451E68[];
extern char D_00451E88[];
extern char D_00451EA8[];
extern void (*D_003CF9EC)(void *a0, int a1);

void func_00326890(char *self)
{
    int b0[4];
    int b10[4];
    char *s0;
    char *s2;
    signed char *p;
    int len;
    int i;
    int r;
    int k;

    s0 = *(char **)(self + 0x8);
    s2 = *(char **)(self + 0x4);
    (*(void (**)())(*(int *)s0 + 0x18))(s0, 1, 0xC800, b0);
    len = b0[1];
    i = 0;
    if (len > 0) {
        p = (signed char *)b0[0];
        for (i = 0; i < len && p[i] == 0; i++)
            ;
    }
    if (i % 2 == 1) {
        (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b0);
        if (GetD003E9D5C_33C718() == 0)
            func_0033F1A8(D_00451E48, D_00451E68);
        self[1] = 4;
        return;
    }
    func_0033ACA0(b0, i, b10, b0);
    (*(void (**)())(*(int *)s0 + 0x20))(s0, 0, b10);
    if (b0[1] < 16) {
        (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b0);
        return;
    }
    r = func_0033CCF0(s2, (void *)b0[0], b0[1]);
    if (r == 0 || b0[1] < r) {
        (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b0);
        return;
    }
    if (r < 0) {
        if (*(short *)(s2 + 0x9A) != 0) {
            func_0033CC50(s2);
            r = 0;
        } else {
            (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b0);
            if (GetD003E9D5C_33C718() == 0)
                func_0033F1A8(D_00451E88, D_00451EA8);
            self[1] = 4;
            return;
        }
    }
    *(int *)(self + 0x98) = r;
    if (Obj33C8_GetShort_98(s2) == 4)
        self[3] = 1;
    if (Obj33C8_GetShort_98(s2) == 2) {
        func_003A5148(self + 0x58, (void *)b0[0], b0[1] < 65 ? b0[1] : 64);
    }
    k = Obj33C8_GetShort_98(s2);
    if ((unsigned int)(k - 10) < 3 || k == 20 || k == 15) {
        (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b0);
    } else {
        func_0033ACA0(b0, r, b0, b10);
        (*(void (**)())(*(int *)s0 + 0x20))(s0, 0, b0);
        (*(void (**)())(*(int *)s0 + 0x1C))(s0, 1, b10);
    }
    if (*(int *)(s2 + 0xE8) != 0 && D_003CF9EC != 0)
        D_003CF9EC(s2, *(int *)(s2 + 0x14));
    self[1] = 2;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00326890);
#endif
