/* sn-2.95.3-136 */
/* func_001DFDE0 (slot machine 1 task): the body and calls match. Retail keeps the high halves of
 * D_007474A0 and D_00569B70 in s7 and fp for the whole function and enters the first three wait
 * loops through a jump to the test; this build rebuilds both addresses at each use and enters the
 * panel wait loop test-first, which shifts the register assignment throughout. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/Slot1.h"
#include "godhand/MarkPanel.h"
#include "godhand/classFADE.h"
#include "godhand/cCoreSave.h"
#include "godhand/cScenario.h"
#include "godhand/cSceAtManager.h"
#include "godhand/cSnd.h"
#include "godhand/cTaskWork.h"
#include "godhand/gameWork.h"

typedef struct Slot2Marks Slot2Marks;

extern void cSnd_BattleBgmAllPause(cSnd *self, float time);
extern void cSnd_BgmEventStart(cSnd *self, int reqNo, int a2, int a3);
extern void cSnd_BgmEventFade(cSnd *self, int reqNo, float time, float level, float weight);
extern void cSnd_BgmFlaggedNodeKick(cSnd *self, float arg);
extern void cTaskWork_exit(cTaskWork *self);
extern void MarkPanel_setMark(MarkPanel *self, unsigned short mark, int show, int startLit);
extern void Slot2_setMarkLayersAt464(Slot2Marks *self, int show, int startLit);
extern void Slot2_setMarkLayersAt46C(Slot2Marks *self, int show, int startLit);
extern void Slot2_setMarkLayers(Slot2Marks *self, int show, int startLit);
extern void func_001E3D78(void *a0, int a1, int a2);
extern void func_001E71B8(char *a0, int a1);
extern void CustomIDWork_SetNumber(CustomIDWork *self, int number);
extern void func_001E73C0(void *a0);
extern void func_001E7440(char *self);
extern void Scroll_showLayerBySelector(char *self, int sel);
extern void func_001E32E8(int a0, float *a1, float *a2);
extern void func_001E0210(int a0);
extern void SlotUi_release(SlotUi *self);
extern void func_001E3388(void *self);
extern int cSceAtManager_SetEnable_2C2950(cSceAtManager *self, unsigned short id);
extern cSnd D_005FEE00;
extern unsigned int D_00747A78;         /* D_007474A0.flags5D8 under its own symbol */

#define SLOT1_BGM        0x31           /* casino music request */
#define SLOT1_FADE_TIME  15

/* Slot machine 1 task: fades into the machine, sets up the board, the panel and the camera,
 * runs the game until it ends, then fades back out and gives the scene back. */
__attribute__((section(".text.func_001DFDE0")))
void func_001DFDE0(Slot1 *self)
{
    cVec eye;
    cVec at;

    cScenario_startSoftEvent(D_003C2F84, 0);
    D_00747A78 &= ~0x02000000;
    cSnd_BattleBgmAllPause(&D_005FEE00, 20.0f);
    classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, SLOT1_FADE_TIME);
    while ((D_00747470.state >> FADE_STATE_DONE_BIT & 1) == 0) {
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    cSnd_BgmEventStart(&D_005FEE00, SLOT1_BGM, 0, 0);
    D_007474A0.unk569 = 1;
    self->endFlag = 0;
    self->state = 0;
    self->step = 0;
    self->phase = 0;
    self->markSel = 0;
    self->payMode = SLOT1_PAYMODE_ON;
    MarkPanel_setMark((MarkPanel *)self, 0, 0, 0);
    MarkPanel_setMark((MarkPanel *)self, 1, 0, 0);
    MarkPanel_setMark((MarkPanel *)self, 2, 0, 0);
    Slot2_setMarkLayersAt464((Slot2Marks *)self, 0, 0);
    Slot2_setMarkLayersAt46C((Slot2Marks *)self, 0, 0);
    Slot2_setMarkLayers((Slot2Marks *)self, 0, 0);
    func_001E3D78(self, 0, 0);
    func_001E71B8((char *)&self->ui, 0);
    CustomIDWork_SetNumber(&self->ui.mark[0], cCoreSave_getGold(&D_00569B70));
    func_001E73C0(&self->ui);
    func_001E7440((char *)&self->ui);
    Scroll_showLayerBySelector((char *)self, 1);
    eye.x = 1.5f;
    eye.y = 133.4301f;
    eye.z = 505.6223f;
    eye.w = 1.0f;
    at.x = 1.5f;
    at.y = 133.4301f;
    at.z = 90.8088f;
    at.w = 1.0f;
    func_001E32E8((int)self, &eye.x, &at.x);
    classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0, SLOT1_FADE_TIME);
    while ((D_00747470.state >> FADE_STATE_DONE_BIT & 1) == 0) {
        func_001E73C0(&self->ui);
        func_001E7440((char *)&self->ui);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    classFADE_kill(&D_00747470);
    for (;;) {
        long end = (unsigned int)self->endFlag;
        long done = end & 1;
        if (done != 0) {
            break;
        }
        func_001E0210((int)self);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    cSnd_BgmEventFade(&D_005FEE00, SLOT1_BGM, 15.0f, 0.0f, -1.0f);
    classFADE_start(&D_00747470, 0, 10, 0, 0, 0xFF000000, SLOT1_FADE_TIME);
    while ((D_00747470.state >> FADE_STATE_DONE_BIT & 1) == 0) {
        func_001E73C0(&self->ui);
        func_001E7440((char *)&self->ui);
        cTaskWork_sleep(D_003C2F84->task.cur, 1);
    }
    D_007474A0.unk569 = 2;
    cSnd_BgmFlaggedNodeKick(&D_005FEE00, 20.0f);
    SlotUi_release(&self->ui);
    cCoreSave_initAddGold(&D_00569B70);
    Scroll_showLayerBySelector((char *)self, 0);
    func_001E3388(self);
    classFADE_start(&D_00747470, 0, 10, 0, 0xFF000000, 0, SLOT1_FADE_TIME);
    cTaskWork_sleep(D_003C2F84->task.cur, SLOT1_FADE_TIME);
    classFADE_kill(&D_00747470);
    cSceAtManager_SetEnable_2C2950(&D_005FEA60, self->atId);
    cScenario__endSoftEvent(D_003C2F84);
    cTaskWork_exit(D_003C2F84->task.cur);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001DFDE0);
#endif
