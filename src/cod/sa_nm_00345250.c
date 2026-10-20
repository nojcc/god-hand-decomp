/* func_00345250: ring lookup; same shape, register assignment differs throughout.
 * func_00354B40: 2 insns; clear loop store/increment order.
 * func_0033E5C0: 1 insn; first mode test is bne in retail, bnel here.
 * func_00356E98: 1 insn; retail sltiu (==0) where we get xori for >= 3. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/mwsfViews.h"

extern void func_0033E3B8(AdxPlay *p);
extern void func_0033E220(AdxPlay *p);
extern void func_0033E0A8(AdxPlay *p);
extern int func_00356358(SfdWkT *w);
extern int GetField0OrZero_346828(MwsfHn48 *mw);
extern void MWSFSVM_Error(const char *msg);
extern void func_00335C68(void *p, int v);
extern char D_00458F48[];

__attribute__((section(".text.func_00354B40")))
void func_00354B40(SfdClr *c)
{
    int i;

    c->f00[0] = 0;
    c->f00[1] = 0;
    c->f00[2] = 0;
    c->f00[3] = 0;
    c->f00[4] = 0;
    c->f00[5] = 0;
    c->f00[6] = 0;
    for (i = 0; i < 16; i++) {
        c->ent[i].a = 0;
        c->ent[i].b = 0;
    }
}

__attribute__((section(".text.func_0033E5C0")))
void func_0033E5C0(AdxPlay *p)
{
    if (p->mode == 2) {
        func_0033E3B8(p);
    } else if (p->mode == 1) {
        func_0033E220(p);
    } else if (p->mode == 0) {
        func_0033E0A8(p);
    }
}

#else

INCLUDE_ASM("asm/nonmatching", func_00354B40);
INCLUDE_ASM("asm/nonmatching", func_0033E5C0);

#endif
