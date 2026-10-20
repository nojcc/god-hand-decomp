/* NON_MATCHING func_00353348 (cygnus-2.96, drop-reorder; PARK): picture-type predicate on work+0x74. Retail keeps the ==3 test in its own block; C hoists it and drops the a2 return temp. Best 28. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Work353348 {
    char pad[0x74];
    unsigned int kind;
} Work353348;

typedef struct Hn353348 {
    char pad[0x1FC0];
    Work353348 *work;
} Hn353348;

int func_00353348(Hn353348 *hn, int ptype)
{
    int p = ptype;
    unsigned int kind = hn->work->kind;
    int ret = 0;

    if (kind != 3) {
        if (kind >= 4)
            return ret;
        if (kind != 2)
            return ret;
        if ((unsigned)(p - 2) < 2U)
            ret = 1;
        return ret;
    }
    ret = (p == (int)kind);
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00353348);
#endif
