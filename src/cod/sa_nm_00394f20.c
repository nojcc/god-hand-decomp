/* NON_MATCHING func_00394F20 (sn): 5 diffs: list-walk loop tail is bnel+lw where retail has nop+bne+lw; D_003F8528 hi in v0 vs v1 */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Sym394F20 {
    int addr;
    int pad4;
    unsigned short size;
    unsigned char padA;
    unsigned char used;
} Sym394F20;

typedef struct Dll394F20 {
    char pad0[0xC];
    Sym394F20 *syms;
    int nsym;
    char pad14[8];
    void (*fini)(void);
    char pad20[0x10];
    struct Dll394F20 *next;
} Dll394F20;

extern Dll394F20 *D_003F852C;
extern int D_003F8528;
extern char D_0045DC00[];
extern int func_00394D00(Dll394F20 *dll);
extern void func_00394668(int addr, int size);
extern void func_003951C0(void);
extern void func_00395180(void);
extern void func_003951D0(void);
extern void func_003951B0(void);
extern void func_003A6A20(char *fmt, ...);

int func_00394F20(Dll394F20 *dll)
{
    Dll394F20 **pp;
    Dll394F20 *p;
    Sym394F20 *s;
    int n;
    int r;

    pp = &D_003F852C;
    if (*pp != 0) {
        while (*pp != dll) {
            pp = &(*pp)->next;
            if (*pp == 0)
                return 5;
        }
    }
    p = *pp;
    if (p == 0)
        return 5;
    *pp = p->next;
    if (dll->fini != 0)
        dll->fini();
    r = func_00394D00(dll);
    if (r < 0)
        return 11;
    func_003951C0();
    n = dll->nsym;
    s = dll->syms;
    for (; n != 0; n--, s++) {
        if (s->used != 0)
            func_00394668(s->addr, s->size);
    }
    func_00395180();
    func_003951D0();
    if (D_003F8528 == 0)
        func_003951B0();
    else if (D_003F8528 == 1)
        func_003A6A20(D_0045DC00, r);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00394F20);
#endif
