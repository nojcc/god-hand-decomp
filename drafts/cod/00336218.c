/* NON_MATCHING lsc_ExecHndl: the only differences are two branches; retail uses bne (non-likely) with the speculative sll v0,a1,5 in the slot before each call, ours uses bnel. */
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

extern void lsc_StatRead(StmObj *o);
extern void lsc_StatEnd(StmObj *o);
extern void lsc_StatWait(StmObj *o);

void lsc_ExecHndl(StmObj *o)
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
        lsc_StatRead(o);
    if (STM_CUR(o).state == 2)
        lsc_StatEnd(o);
    if (STM_CUR(o).state != 0)
        return;
    lsc_StatWait(o);
}
#else
INCLUDE_ASM("asm/nonmatching", lsc_ExecHndl);
#endif
