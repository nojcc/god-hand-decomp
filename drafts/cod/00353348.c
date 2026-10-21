/* Retail keeps the ==3 test in its own block;
* C hoists it and drops the a2 return temp. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct PicTypeWork {
    char pad[0x74];
    unsigned int kind;
} PicTypeWork;

typedef struct PicTypeHn {
    char pad[0x1FC0];
    PicTypeWork *work;
} PicTypeHn;

int func_00353348(PicTypeHn *hn, int ptype)
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
