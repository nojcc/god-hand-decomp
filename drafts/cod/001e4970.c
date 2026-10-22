/* NON_MATCHING Slot2_Execute (sn-2.95.3-136):
 * 254 words against retail's 246. Retail reads endFlag with lwu, keeps the second fade wait as a
 * jump to its bottom test (this build copies the test to the top), and allocates the saved registers
 * differently (self in s1, the hi halves of D_003C2F84, D_005FEE00, D_007474A0 and D_00569B70 in s4, s6, s7 and fp).
 * Callers' prototypes: 001e4920.c declares Slot2_Execute(void); func_001E6910 is defined (void) but is passed self. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/Slot2.h"
#include "godhand/SlotUi.h"
#include "godhand/cCoreSave.h"
#include "godhand/cScenario.h"
#include "godhand/classFADE.h"
#include "godhand/gameWork.h"
#include "godhand/CustomIDPanel.h"

#ifdef NON_MATCHING


#define SLOT2_BGM          0x31
#define SLOT2_FADE_TIME    15
#define SLOT2_BGM_FADE     20.0f
#define SYS_F_PAD_LOCK     0x02000000
#define FADE_BLACK         0xFF000000

extern unsigned int D_00747A78;
extern char D_005FEE00[];
extern char D_005FEA60[];
extern void cSnd_BattleBgmAllPause(void *snd, float time);
extern void cSnd_BgmEventStart(void *snd, int no, int a2, int a3);
extern void cSnd_BgmEventFade(void *snd, int no, float time, float level, float weight);
extern void cSnd_BgmFlaggedNodeKick(void *snd, float time);
extern void cTaskWork_exit(struct cTaskWork *task);
extern int cSceAtManager_SetEnable_2C2950(void *mgr, unsigned short id);
extern void Slot2_setLineMark(Slot2 *self, int on, int lit);
extern void func_001E6C80(Slot2 *self, int on, int lit);
extern void func_001E6D48(Slot2 *self, int on, int lit);
extern void func_001E6E10(Slot2 *self, int on, int lit);
extern void func_001E71B8(char *layer, int on);
extern void Slot2_showMarkLayers(Slot2 *self, int all);
extern void func_001E6870(Slot2 *self, float *eye, float *at);
extern void func_001E6910(Slot2 *self);
extern void func_001E73C0(void *layer);
extern void func_001E7440(void *layer);
extern void Slot2_update(Slot2 *self);
extern void SlotUi_release(SlotUi *self);

#define FADE_DONE()  ((D_00747470.state >> FADE_STATE_DONE_BIT) & 1)

/* The slot machine task: fade in to the machine's camera, run the game until it ends, then fade back to the room. */
__attribute__((section(".text.Slot2_Execute")))
void Slot2_Execute(Slot2 *self)
{
    cVec eye;
    cVec at;

    cScenario_startSoftEvent(D_003C2F84, 0);
    D_00747A78 &= ~SYS_F_PAD_LOCK;
    cSnd_BattleBgmAllPause(D_005FEE00, SLOT2_BGM_FADE);
    classFADE_start(&D_00747470, 0, 10, 0, 0, FADE_BLACK, SLOT2_FADE_TIME);
    while (!FADE_DONE()) {
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    cSnd_BgmEventStart(D_005FEE00, SLOT2_BGM, 0, 0);
    D_007474A0.unk569 = 1;
    self->endFlag = 0;
    self->state = 0;
    self->step = 0;
    self->phase = 0;
    self->betLv = 0;
    Slot2_setLineMark(self, 0, 0);
    func_001E6C80(self, 0, 0);
    func_001E6D48(self, 0, 0);
    func_001E6E10(self, 0, 0);
    func_001E71B8(self->layer, 1);
    CustomIDWork_SetNumber(self->customId, cCoreSave_getGold(&D_00569B70));
    Slot2_showMarkLayers(self, 1);
    eye.x = 1.5f;
    eye.y = 113.59f;
    eye.z = 505.7248f;
    eye.w = 1.0f;
    at.x = 1.5f;
    at.y = 113.59f;
    at.z = 94.00560f;
    at.w = 1.0f;
    func_001E6870(self, &eye.x, &at.x);
    classFADE_start(&D_00747470, 0, 10, 0, FADE_BLACK, 0, SLOT2_FADE_TIME);
    while (!FADE_DONE()) {
        func_001E73C0(self->layer);
        func_001E7440(self->layer);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    classFADE_kill(&D_00747470);
    while (!(self->endFlag & 1)) {
        Slot2_update(self);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    cSnd_BgmEventFade(D_005FEE00, SLOT2_BGM, 15.0f, 0.0f, -1.0f);
    classFADE_start(&D_00747470, 0, 10, 0, 0, FADE_BLACK, SLOT2_FADE_TIME);
    while (!FADE_DONE()) {
        func_001E73C0(self->layer);
        func_001E7440(self->layer);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    D_007474A0.unk569 = 2;
    cSnd_BgmFlaggedNodeKick(D_005FEE00, SLOT2_BGM_FADE);
    SlotUi_release((SlotUi *)self->layer);
    cCoreSave_initAddGold(&D_00569B70);
    Slot2_showMarkLayers(self, 0);
    func_001E6910(self);
    classFADE_start(&D_00747470, 0, 10, 0, FADE_BLACK, 0, SLOT2_FADE_TIME);
    cTaskWork_sleep(D_003C2F84->task.cur, SLOT2_FADE_TIME);
    classFADE_kill(&D_00747470);
    cSceAtManager_SetEnable_2C2950(D_005FEA60, self->slotId);
    cScenario__endSoftEvent(D_003C2F84);
    cTaskWork_exit(D_003C2F84->task.cur);
}
#else
INCLUDE_ASM("asm/nonmatching", Slot2_Execute);
#endif
