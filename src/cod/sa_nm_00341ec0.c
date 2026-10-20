/* NON_MATCHING func_00341EC0: kind at +0x9C, tail calls for 2, 1, else.
 * One diff, bne vs bnel on the first compare. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Obj341EC0 {
    char pad[0x9C];
    short kind;
} Obj341EC0;

extern void func_00341D18(Obj341EC0 *o);
extern void func_00341B98(Obj341EC0 *o);
extern void func_00341A00(Obj341EC0 *o);

void func_00341EC0(Obj341EC0 *o)
{
    if (o->kind == 2)
        func_00341D18(o);
    else if (o->kind == 1)
        func_00341B98(o);
    else
        func_00341A00(o);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00341EC0);
#endif
