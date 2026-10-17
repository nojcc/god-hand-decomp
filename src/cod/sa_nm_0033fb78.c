/* NON_MATCHING func_0033FB78 (cygnus-2.96 -freorder-blocks dropped): 1 diff: odd-result test emits bnel (annulled li v0,3) where retail has bne with li v0,3 in its delay slot; tried state locals, goto, flag-callee prototypes, as sn and -fno-gcse */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Req33FB78 {
    char unk00[0xC];
    int state;                  /* 0x0C */
    int result;                 /* 0x10 */
    int simple;                 /* 0x14 */
    int a;                      /* 0x18 */
    int b;                      /* 0x1C */
    int c;                      /* 0x20 */
    int d;                      /* 0x24 */
    char buf28[4];              /* 0x28 */
    char buf2C[4];              /* 0x2C */
    short e;                    /* 0x30 */
    short f;                    /* 0x32 */
    char buf34[2];              /* 0x34 */
    short g;                    /* 0x36 */
    short h;                    /* 0x38 */
} Req33FB78;

extern int func_00341F00(int a, int b, int c, void *p, short e, short f, void *q, short g, short h);
extern int func_003427F0(int a, int b, int c, void *p, int d, void *p2, short e, short f, void *q,
                         short g, short h);
extern void Obj33F8_SetFlag_D003EB850_FB68(void);

void func_0033FB78(Req33FB78 *r)
{
    if (r->state == 1)
        r->state = 2;
    if (r->state == 2) {
        if (r->simple == 1) {
            r->result = func_00341F00(r->a, r->b, r->c, r->buf28, r->e, r->f, r->buf34, r->g, r->h);
        } else {
            r->result = func_003427F0(r->a, r->b, r->c, r->buf28, r->d, r->buf2C, r->e, r->f,
                                      r->buf34, r->g, r->h);
            if (r->result % 2 == 1)
                Obj33F8_SetFlag_D003EB850_FB68();
        }
        r->state = 3;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0033FB78);
#endif
