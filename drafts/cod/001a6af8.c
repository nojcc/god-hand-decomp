/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmScripted.h"
#include "godhand/cScenario.h"
#include "godhand/gameWork.h"
#include "godhand/cHeatSys.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

#ifdef NON_MATCHING
/* The system flag words from D_00747A78 on: the third one is at +8. */
typedef struct SysFlagWords {
    unsigned int f78;                   /* 0x747A78 */
    unsigned int f7C;
    unsigned int f80;                   /* 0x747A80 */
} SysFlagWords;

extern SysFlagWords D_00747A78;
extern char *D_003BD6E8;
extern char D_004273F8[];               /* "A00" */
extern void cCockGetPoint_setData(void *self, cVec *pos, int point, short kind);

/* The scripted sequence: play cut "A00", and the first time give the reward
 * (120 heat while the gauge isn't full, otherwise 1000 gold, 2000 after a
 * clear, shown at the object), wait for a press of either confirm button,
 * then end the soft event and the task. Same length as retail, 15
 * instructions differ: retail loads D_003C2F84 for the first and last calls
 * only after the objFlags store (here the load is scheduled above it), and
 * builds D_003BD6E8's address in $v1 after the position copy where this uses
 * $v0 (as in drafts/cod/001c2408.c). */
__attribute__((section(".text.func_001A6AF8")))
void func_001A6AF8(cOmScripted *self)
{
    cVec pos;
    int gold;

    D_00747A78.f78 &= ~0x40000;
    D_00747A78.f80 &= ~0x2000000;
    self->base.objFlags |= 0x10000;
    cScenario_execUpCut(D_003C2F84, 0xFFFF, D_004273F8, 0, 1, 1);
    cTaskWork_sleep(D_003C2F84->task.cur, 10);
    if (self->rewarded == 0) {
        self->rewarded = 1;
        cTaskWork_sleep(D_003C2F84->task.cur, 20);
        if (D_005CB000.cur < D_005CB000.max) {
            cHeatSys_AddHeatGage(&D_005CB000, 1, 120.0f);
            cTaskWork_sleep(D_003C2F84->task.cur, 60);
        } else {
            gold = 1000;
            if (cCoreSave_getClearNum(&D_00569B70)) {
                gold = 2000;
            }
            cCoreSave_addGold(&D_00569B70, gold, 0);
            CVEC_COPY(pos, self->base.pos);
            cCockGetPoint_setData(D_003BD6E8 + 0x15C0, &pos, gold, self->base.unk2AC);
        }
    }
    while ((D_007474A0.trg & 0x30000000) == 0) {
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    self->base.objFlags &= ~0x10000;
    self->seqState = OMSCRIPTED_SEQ_DONE;
    cScenario__endSoftEvent(D_003C2F84);
    cTaskWork_exit(D_003C2F84->task.cur);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001A6AF8);
#endif
