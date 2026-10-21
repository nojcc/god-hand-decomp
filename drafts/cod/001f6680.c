#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad[0x2C];
    unsigned int flags;
} IDWork;

typedef struct {
    char pad0[0xC];
    int cur;
    int on[4];
    char pad20[0x10];
    char ids[1];
} ActBtnObj;

extern IDWork *cIDBase_getIDWork(void *self, int idx);

void func_001F6680(ActBtnObj *o)
{
    int i = 0;
    int *on = o->on;

    do {
        if (*on != 0) {
            cIDBase_getIDWork(o->ids, i)->flags &= ~0x20000000;
        } else {
            cIDBase_getIDWork(o->ids, i)->flags |= 0x20000000;
        }
        if (i == o->cur) {
            cIDBase_getIDWork(o->ids, i + 4)->flags &= ~0x20000000;
        } else {
            cIDBase_getIDWork(o->ids, i + 4)->flags |= 0x20000000;
        }
        i++;
        on++;
    } while (i < 4);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F6680);
#endif
