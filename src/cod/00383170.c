/* NON_MATCHING func_00383170: count-load delay slot + loop n=i+1 temp-copy shape */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[8];
    int count;
    char pad0C[0x14];
    void *obj;
} CtlList;

typedef struct {
    char pad0[8];
    short vals[(0x64 - 8) / 2];
    void *obj64;
    char pad68[0xA4 - 0x68];
    CtlList list;
    char padC8[0];
} ListCtl;

extern int func_00383280(void *a0, CtlList *l);
extern void func_0032EC78(void *obj, int i, int v);
extern void func_0032A9F0(void *obj, int v);

void func_00383170(void *a0, ListCtl *c, int a2)
{
    CtlList *l;
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
