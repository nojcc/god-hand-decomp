/* NON_MATCHING func_00383170 (sn): 28 diffs: count-load delay slot + loop n=i+1 temp-copy shape; do-while variant (structurally 1 insn short) in build/sa/v3170_A.c */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    int count;
    char pad0C[0x14];
    void *obj;
} List383170;

typedef struct {
    char pad0[8];
    short vals[(0x64 - 8) / 2];
    void *obj64;
    char pad68[0xA4 - 0x68];
    List383170 list;
    char padC8[0];
} Ctl383170;

extern int func_00383280(void *a0, List383170 *l);
extern void func_0032EC78(void *obj, int i, int v);
extern void func_0032A9F0(void *obj, int v);

void func_00383170(void *a0, Ctl383170 *c, int a2)
{
    List383170 *l;
    unsigned char *flags;
    int i, n;

    if ((unsigned char)a2) {
        l = &c->list;
        if (func_00383280(a0, l) != 0) {
            flags = (unsigned char *)c + 0xBC;
            for (i = 0; i < l->count; i = n) {
                n = i + 1;
                if (flags[n])
                    func_0032EC78(l->obj, i, -0x3C0);
                else
                    func_0032EC78(l->obj, i, c->vals[n]);
            }
        } else {
            for (i = 0; i < l->count; i = n) {
                n = i + 1;
                func_0032EC78(l->obj, i, c->vals[n]);
            }
        }
    } else {
        func_0032A9F0(c->obj64, c->vals[0]);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00383170);
#endif
