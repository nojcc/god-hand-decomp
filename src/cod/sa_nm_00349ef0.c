/* NON_MATCHING func_00349EF0 (cygnus-2.96, -freorder-blocks dropped): same size, 2 insns differ: after the first call retail sets a3 = &used before the bnez and copies self into a0 in the delay slot; this does the reverse. Tried: early returns, nested single-return form, struct locals. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad00[0x3C];
    void (*feed)(char *self, int data, int len, int *used);
} Ops349;

extern int func_0034A9B8(char *self, int *data, int *len);
extern int func_0034AA00(char *self, int used);
extern void func_0034AA20(char *self);

int func_00349EF0(char *self, int *size)
{
    int data, len, used;
    Ops349 *ops;
    int r;

    *size = 0;
    ops = *(Ops349 **)(self + 0x2004);
    r = func_0034A9B8(self, &data, &len);
    if (r != 0)
        return r;
    *size = len;
    ops->feed(self, data, len, &used);
    r = func_0034AA00(self, used);
    if (r != 0)
        return r;
    func_0034AA20(self);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00349EF0);
#endif
