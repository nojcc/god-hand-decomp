/* NM, not registered. cygnus-2.96 singletons.
 * func_0035A7A0: 3 insns; retail loads id into v1 and -1 into a2 (ours swapped).
 * func_00342E50: 4 insns; retail materialises 0x600 after the first store (schedule order). */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct SfdObj4C {
    char unk00[0x4C];
    int type;                   /* 0x4C */
} SfdObj4C;

typedef struct SfdObj2CC {
    char unk000[0x2CC];
    int id;                     /* 0x2CC */
} SfdObj2CC;

__attribute__((section(".text.func_0035A7A0")))
int func_0035A7A0(SfdObj4C *a, SfdObj2CC *b)
{
    if (b->id == -1) return 0;
    return a->type == 4;
}

__attribute__((section(".text.func_00342E50")))
int func_00342E50(void *obj, int *a, int *b, int *c)
{
    *a = 0x4000; *b = 0x100; *c = 0x600;
    return *a + *b + *c;
}

#else

INCLUDE_ASM("asm/nonmatching", func_0035A7A0);
INCLUDE_ASM("asm/nonmatching", func_00342E50);

#endif
