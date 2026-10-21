/* NON_MATCHING func_0035A968 (cygnus-2.96): 2 insns: li v0,-1 scheduled before sd s0. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern long func_0031DE10(long id, DItype v);
extern long func_003B7FE0(long a, long b);
extern long D_003EE308;
extern int D_003EE310;

typedef struct {
    char pad[0x158];
    long id;
} Obj35A;

__attribute__((section(".text.func_0035A968")))
int func_0035A968(Obj35A *o, int ntr)
{
    long id = o->id;
    int r;

    if (id < 0) {
        return -1;
    }
    r = func_003B7FE0(func_0031DE10(id), 90000);
    D_003EE308 = id;
    D_003EE310 = r;
    return r;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0035A968);
#endif
