/* Remaining: retail's stat==1 test is bne (not bnel) and the mode==1 sibcall block sits after the retry block with a b to the epilogue. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    signed char used; /* 0x00 */
    signed char stat; /* 0x01 */
    char pad2;
    signed char pause; /* 0x03 */
    char pad4[0x1958 - 0x4];
    int mode; /* 0x1958 */
} AixDmx;
extern void func_0032FAD8(AixDmx *d);
extern int func_0032FC38(AixDmx *d);
extern void func_00330080(AixDmx *d);

void func_003301B0(AixDmx *d)
{
    if (d->used != 1)
        return;
    if (d->stat == 1) {
        func_0032FAD8(d);
        return;
    }
    if (d->stat != 2)
        return;
    if (d->pause != 0)
        return;
    if (d->mode != 0) {
        if (d->mode == 1) {
            func_00330080(d);
            return;
        }
        return;
    }
    if (func_0032FC38(d) != -1)
        return;
    func_0032FC38(d);
}
#else
INCLUDE_ASM("asm/nonmatching", func_003301B0);
#endif
