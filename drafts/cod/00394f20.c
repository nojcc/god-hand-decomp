/* NON_MATCHING func_00394F20: list-walk loop tail is bnel+lw where retail has nop+bne+lw;
* D_003F8528 hi in v0 vs v1 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/regTbl.h"

extern int D_003F8528;
extern char D_0045DC00[];
extern int func_00394D00(RegTbl *tbl);
extern int func_00394668(int name, unsigned short id);
extern void func_003951C0(void);
extern void func_00395180(void);
extern void func_003951D0(void);
extern void func_003951B0(void);
extern void func_003A6A20(char *fmt, ...);

int func_00394F20(RegTbl *tbl)
{
    RegTbl **pp;
    RegTbl *p;
    RegEnt *s;
    int n;
    int r;

    pp = &D_003F852C;
    if (*pp != 0) {
        while (*pp != tbl) {
            pp = &(*pp)->next;
            if (*pp == 0)
                return 5;
        }
    }
    p = *pp;
    if (p == 0)
        return 5;
    *pp = p->next;
    if (tbl->fini != 0)
        tbl->fini();
    r = func_00394D00(tbl);
    if (r < 0)
        return 11;
    func_003951C0();
    n = tbl->count;
    s = tbl->ents;
    for (; n != 0; n--, s++) {
        if (s->active != 0)
            func_00394668(s->name, s->id);
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
