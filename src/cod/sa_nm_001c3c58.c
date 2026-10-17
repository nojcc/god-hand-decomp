/* NON_MATCHING func_001C3C58 (sn-2.95.3-136): retail has an assembler-style nop pair at a branch-likely target. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int magic;
    int count;
    int kind;
    int data[1];
} SmoHeader;

__attribute__((section(".text.func_001C3C58")))
int func_001C3C58(void **out, SmoHeader *h)
{
    if (h == 0) {
        return 0;
    }
    out[0] = h;
    if (h->magic != 0x534D4F || h->count == 0) {
        out[0] = 0;
        return 0;
    }
    if ((unsigned int)h->kind < 2) {
        out[1] = &h->data[0];
    } else {
        out[1] = &h->data[1];
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C3C58);
#endif
