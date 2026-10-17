/* NON_MATCHING func_00342FF8 (cyg,near-miss,regalloc): best 5 (cyg dr): the three-way buffer request is right. In the third case retail puts kind2 in v0 (delay-slot load) and c2 in a1; ours swaps them. Retail also stores req.d=0 at the join before the argument moves, while ours stores it after. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int kind;
    int buf;
    int a;
    int b;
    int c;
    int d;
} BufReq;

typedef struct {
    char unk0[0x3C];
    int stm;
    char unk40[0x17C];
    int cur;
    int buf0;
    int a0;
    int b0;
    int c0;
    int kind2;
    int a2;
    int b2;
    int c2;
    int buf1;
    int a1;
    int b1;
} PicHn;

extern int func_00359270(int stm, BufReq *req);
extern void func_00345750(int err);
extern void MWSFSVM_Error(char *msg, ...);
extern char D_00457208[];

void func_00342FF8(PicHn *hn)
{
    BufReq req;
    int cur = hn->cur;
    int stm = hn->stm;

    if (cur == 0)
        return;
    if (cur == hn->buf1) {
        req.buf = cur;
        req.kind = 1;
        req.a = hn->a1;
        req.b = hn->b1;
        req.c = 0;
    } else if (cur == hn->buf0) {
        req.buf = cur;
        req.a = hn->a0;
        req.b = hn->b0;
        req.c = hn->c0;
        req.kind = 0;
    } else {
        req.kind = hn->kind2;
        req.buf = cur;
        req.a = hn->a2;
        req.b = hn->b2;
        req.c = hn->c2;
    }
    req.d = 0;
    if (func_00359270(stm, &req) != 0) {
        func_00345750(-0x138);
        MWSFSVM_Error(D_00457208);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00342FF8);
#endif
