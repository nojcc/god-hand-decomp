/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/DispMgr.h"
#include "godhand/DogRace.h"
#include "godhand/JukeBox.h"
#include "godhand/Slot1.h"

extern short D_005CAE40;
extern void displayScrollLayer(int layer, int on);
extern long D_007474A0[];

/* Run an entry's update hook from the type table D_003BF0E0 (g++ 2.x
 * delta/index/pfn entries, indexed by the type byte at +0), set the screen
 * state to 10, then move and draw the inner display at +0x30. */
typedef struct HookEnt {
    short delta;                        /* added to the object before the call */
    short index;
    void (*pfn)(void *self);
} HookEnt;

extern HookEnt D_003BF0E0[];




#define SCREEN_STATE_ENTRY_RUN 10

__attribute__((section(".text.Entry_runHookAndDraw")))
void Entry_runHookAndDraw(JukeBoxObj *self) {
    int type = self->unk00;
    int delta = D_003BF0E0[type].delta;
    D_003BF0E0[type].pfn((char *)self + delta);
    D_005CAE40 = SCREEN_STATE_ENTRY_RUN;
    cIDBase_move(&self->idBase);
    cIDBase_trans(&self->idBase);
}

/* Set message `messNo` on row `slot` (slot < 5) of the result screen's two
 * message columns, elements 9..13 and 38..42. */
#define SLOT_COUNT      5
#define COLUMN_A        9
#define COLUMN_B        38



__attribute__((section(".text.CustomIDWork_setSlotMessNo")))
void CustomIDWork_setSlotMessNo(DogRaceResult *self, unsigned short slot, int messNo) {
    if (slot < SLOT_COUNT) {
        CustomIDWork_SetMessNo(&self->elem[COLUMN_A + slot], messNo);
        CustomIDWork_SetMessNo(&self->elem[COLUMN_B + slot], messNo);
    }
}

/* Run the hook method (vtable entry 3) of every registered sub-record, clear
 * ready, then mark every sub-record with value 0 (func_001415E8). */



__attribute__((section(".text.cHookList_callAll")))
void cHookList_callAll(DispMgr *self) {
    int i;
    for (i = 0; i < DISPMGR_SLOT_NUM; i++) {
        DispMgrSub *obj = self->slot[i].obj;
        if (obj != 0)
            obj->vt[DISPMGR_SUB_HOOK].pfn((char *)obj + obj->vt[DISPMGR_SUB_HOOK].delta);
    }
    self->ready = 0;
    func_001415E8(self, 0);
}

/* Set the mark flag word of scroll mark `mark` (0 to 2): `lit` writes the
 * mark number into bits 11 up and sets bit 15; otherwise clear it and, for
 * marks 0 and 1, hide the line layer. */
#define KEEP_LAYER  32               /* scrollLayer[] index of the keep mark's layer */



__attribute__((section(".text.MarkObj_setMarkFlag")))
void MarkObj_setMarkFlag(Slot1 *self, unsigned short mark, int lit) {
    if (mark < 3) {
        if (lit) {
            self->keepFlag = (mark << 11) | 0x8000;
        } else {
            self->keepFlag = 0;
            switch (mark) {
            case 0:
                displayScrollLayer(self->scrollLayer[KEEP_LAYER], 0);
                break;
            case 1:
                displayScrollLayer(self->scrollLayer[KEEP_LAYER], 0);
                break;
            }
        }
    }
}

/* Per-frame check of the 64-bit input word D_007474A0[0x34]: bit 29 puts the
 * object's mode (0x60) to 10; bit 21 plays sound 0x161 and resets the mode to -1. */
typedef struct ModeObj {
    char unk00[0x60];
    int mode;                           /* 0x60 */
} ModeObj;





#define INPUT_WORD(base)   (((long *)((char *)(base) + 0x1A0))[0])
#define INPUT_BIT_MODE     0x20000000
#define INPUT_BIT_SOUND    0x200000

__attribute__((section(".text.ModeObj_pollInputBits")))
void ModeObj_pollInputBits(ModeObj *self) {
    char *in = (char *)D_007474A0;
    if (INPUT_WORD(in) & INPUT_BIT_MODE)
        self->mode = 10;
    if (INPUT_WORD(in) & INPUT_BIT_SOUND) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        self->mode = -1;
    }
}

/* Restart the animation and refill the 13 entry pointers at 0xB0 from
 * cIDBase_getIDWork, then clear the two state bytes at 0x94/0x95. */
#define ENTRY_COUNT 13

typedef struct IdScreen {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x90 - sizeof(cIDBaseObj)];
    int unk90;                          /* 0x90 */
    unsigned char sel0;                 /* 0x94 */
    unsigned char sel1;                 /* 0x95 */
    char unk96[0x1A];
    void *ent[ENTRY_COUNT];             /* 0xB0 */
} IdScreen;




__attribute__((section(".text.IdScreen_refillEntries")))
void IdScreen_refillEntries(IdScreen *self) {
    unsigned short i = 0;
    self->unk90 = 0;
    cIDBase_restartAnim(&self->base);
    self->base.playing = 1;
    do {
        self->ent[i] = cIDBase_getIDWork(&self->base, i);
        i = i + 1;
    } while (i < ENTRY_COUNT);
    self->sel0 = 0;
    self->sel1 = 0;
}
