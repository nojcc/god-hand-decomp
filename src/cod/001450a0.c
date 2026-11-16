/* sn-2.95.3-136 matched TU. */

#include "godhand/cMc.h"
#include "godhand/criStm.h"
#include "godhand/cEvent.h"
#include "godhand/Slot2.h"
#include "godhand/Slot1.h"
#include "godhand/scrollLayer.h"
#include "godhand/cIDBaseScreen.h"

extern void func_0();
extern cMc D_005E6900;
extern cMcTaskRef D_00752C00;
extern void cMc_DllLoad(cMc *self, int pump);
extern void cMc_DllRelease(cMc *self);
extern void cTaskWork_exit(void *task);
extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(int a0);
extern void cIDBase_release(int a0);
extern void func_00161590(int a0);
extern char **D_003C2384;

/* sn-2.95.3-136 */
/* Copy num item ids from src into the screen (clamped to SCR_LIST_MAX) and mark it ready. */
__attribute__((section(".text.BlendWork_copyShortTable")))
void BlendWork_copyShortTable(cIDBaseScreen *self, short *src, short num) {
    if (num >= SCR_LIST_MAX + 1) {
        self->listNum = SCR_LIST_MAX;
    } else {
        self->listNum = num;
    }
    func_003A5148(self->item, src, self->listNum << 1);
    self->flags |= SCR_FLAG_READY;
}

/* sn-2.95.3-136 */










/* Load the memory card module, run its two stripped log hooks, release it and end the calling task. */
__attribute__((section(".text.cMc_loadRunReleaseB")))
void cMc_loadRunReleaseB(void) {
    cMc_DllLoad(&D_005E6900, 0);
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr00);
    cMc_DllRelease(&D_005E6900);
    cTaskWork_exit(D_00752C00.task);
}

/* sn-2.95.3-136 */





/* Reset an object: run the base reset, release its four id slots, clear two counters on the shared record. */
__attribute__((section(".text.IdObj_resetAndReleaseIds4")))
void IdObj_resetAndReleaseIds4(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0 + 0x230);
    cIDBase_release(a0 + 0x100);
    cIDBase_release(a0);
    cIDBase_release(a0 + 0x180);
    p = *D_003C2384;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x20) = 0;
    func_00161590(a0);
}

/* sn-2.95.3-136 */




/* Slot2 line mark 2, once a frame: while lit (bit 15), count 8 frames, then flip the shown bit (14) and update the layer. */
#define MARK_BLINK   0x8000     /* markFlag: start lit, counting */
#define MARK_ON      0x4000     /* markFlag: line shown */
#define MARK_COUNT   0x3FFF     /* markFlag: frames since the last flip */
#define MARK_PERIOD  8

__attribute__((section(".text.Slot2_updateLineMark2")))
void Slot2_updateLineMark2(Slot2 *self) {
    unsigned int flag = self->markFlag[2];
    if (flag & MARK_BLINK) {
        unsigned short next;    /* short: the store keeps retail's andi 0xFFFF */
        flag = flag + 1;
        self->markFlag[2] = flag;
        if ((flag & MARK_COUNT) >= MARK_PERIOD) {
            next = (~flag & MARK_ON) | MARK_BLINK;
            self->markFlag[2] = next;
            if (next & MARK_ON) {
                displayScrollLayer(self->lineLayer, 1);
            } else {
                displayScrollLayer(self->lineLayer, 0);
            }
        }
    }
}

/* sn-2.95.3-136 */




/* Slot2 line mark 3, once a frame: while lit (bit 15), count 8 frames, then flip the shown bit (14) and update the layer. */
#define MARK_BLINK   0x8000     /* markFlag: start lit, counting */
#define MARK_ON      0x4000     /* markFlag: line shown */
#define MARK_COUNT   0x3FFF     /* markFlag: frames since the last flip */
#define MARK_PERIOD  8

__attribute__((section(".text.Slot2_updateLineMark3")))
void Slot2_updateLineMark3(Slot2 *self) {
    unsigned int flag = self->markFlag[3];
    if (flag & MARK_BLINK) {
        unsigned short next;    /* short: the store keeps retail's andi 0xFFFF */
        flag = flag + 1;
        self->markFlag[3] = flag;
        if ((flag & MARK_COUNT) >= MARK_PERIOD) {
            next = (~flag & MARK_ON) | MARK_BLINK;
            self->markFlag[3] = next;
            if (next & MARK_ON) {
                displayScrollLayer(self->lineLayer, 1);
            } else {
                displayScrollLayer(self->lineLayer, 0);
            }
        }
    }
}

/* sn-2.95.3-136 */


#define MARK_LAYER   12           /* scrollLayer[] index of the mark's layer */
#define MARK_BLINK   0x8000     /* markFlag: start lit, counting */
#define MARK_ON      0x4000     /* markFlag: line shown */
#define MARK_COUNT   0x3FFF     /* markFlag: frames since the last flip */
#define MARK_PERIOD  8

/* Mark at 0x4A8, once a frame: while lit (bit 15), count 8 frames, then flip the shown bit (14) and update the layer. */
__attribute__((section(".text.Slot2_updateMarkAt4A8")))
void Slot2_updateMarkAt4A8(Slot1 *self) {
    unsigned int flag = self->markFlag[6];
    if (flag & MARK_BLINK) {
        unsigned short next;    /* short: the store keeps retail's andi 0xFFFF */
        flag = flag + 1;
        self->markFlag[6] = flag;
        if ((flag & MARK_COUNT) >= MARK_PERIOD) {
            next = (~flag & MARK_ON) | MARK_BLINK;
            self->markFlag[6] = next;
            if (next & MARK_ON) {
                displayScrollLayer(self->scrollLayer[MARK_LAYER], 1);
            } else {
                displayScrollLayer(self->scrollLayer[MARK_LAYER], 0);
            }
        }
    }
}
