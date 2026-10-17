/* NON_MATCHING func_0034C890 (cygnus-2.96): index/branch layout; 6 attempts (two-step base matched sibling 0034C930 after cap). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int f00;
    int busy;
    int f08[3];
    int value;
    int pad[23];
} Entry34C;

extern int func_0034DD70(char *self, unsigned int code);

__attribute__((section(".text.func_0034C890")))
int func_0034C890(char *self, int idx, int *out)
{
    Entry34C *e = (Entry34C *)(self + 0x1310) + idx;

    *out = 0;
    if (e->busy != 0) {
        *out = e->value;
        return 0;
    }
    return func_0034DD70(self, 0xFF000401);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0034C890);
#endif
