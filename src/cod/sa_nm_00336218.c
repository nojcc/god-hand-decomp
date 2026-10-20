/* NON_MATCHING func_00336218: the only differences are two branches; retail uses bne (non-likely) with the speculative sll v0,a1,5 in the slot before each call, ours uses bnel.
 * Unprototyped or int-returning callees and -fno-gcse / -fno-align-jumps don't change it. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int state;
    char unk4[0x1C];
} StmSlot;

typedef struct {
    char unk0[0x10];
    int cur;
    int count;
    char unk18[0x28];
    StmSlot slot[1];
} StmSub;

typedef struct {
    char unk0;
    signed char run;
    char unk2[2];
    signed char stop;
    char unk5[0xB];
    StmSub sub;
} StmObj;

#define STM_CUR(o) (sub->slot[(o)->sub.cur])

extern void func_00336048(StmObj *o);
extern void func_00336110(StmObj *o);
extern void func_00335F20(StmObj *o);

void func_00336218(StmObj *o)
{
    StmSub *sub;

    if (o->stop == 1)
        return;
    if (o->run != 2)
        return;
    if (o->sub.count <= 0)
        return;
    sub = &o->sub;
    if (STM_CUR(o).state == 1)
        func_00336048(o);
    if (STM_CUR(o).state == 2)
        func_00336110(o);
    if (STM_CUR(o).state != 0)
        return;
    func_00335F20(o);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00336218);
#endif
