/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cScenario.h"
#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/CustomIDWork.h"
#include "godhand/player.h"
#include "godhand/cModel.h"
#include "godhand/cEmManage.h"
#include "godhand/emPhaseTable.h"
#include "godhand/DogRace.h"

extern int D_003C264C;
extern int D_00747A24;
extern void func_002BFC80(int a0);
extern void cScenario_beginRoomJump_2C4548(cScenario *self, int room, float angle, void *pos, int a3, unsigned int t0, int t1);
extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_001B76D8(cOmBase *self);

typedef struct RoomJumpTarget {
    float pos[4];               /* 0x00 */
    float angle;                /* 0x10 */
    unsigned char pending;      /* 0x14 */
    char unk15;
    unsigned short roomNo;      /* 0x16 */
} RoomJumpTarget;

__attribute__((section(".text.cScenario_endExtraGame")))
void cScenario_endExtraGame(RoomJumpTarget *target)
{
    float pos[4];
    unsigned short room;
    float angle;
    int dead;

    if (target->pending == 1) {
        target->pending = 0;
        room = target->roomNo;
        VU0_LQC2(4, target, 0);
        VU0_SQC2(4, pos, 0);
        angle = target->angle;
        dead = Getplayer()->hp == 0;
        func_002BFC80(D_003C264C);
        if (dead == 0) {
            cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 2, 1);
        } else {
            cScenario_beginRoomJump_2C4548(D_003C2F84, room, angle, pos, 0, 0, 1);
        }
        D_00747A24 = (D_00747A24 | 0x1000000) & 0xF7FFFFFF;
    }
}

#define SLOT_COUNT      5
#define BANK_A_ELEM     12              /* first element of each message bank */
#define BANK_B_ELEM     23
#define BANK_Y_ELEM     6               /* first element moved to a row's Y */

typedef struct { int w[5]; } SlotY;

extern int D_0042BDC0[5];               /* local Y per slot */

/* Set message `messNo` on slot `msgSlot` of both banks and move the work entry of slot `ySlot` to that slot's Y
 * from the table. Both slots must be below 5. */
__attribute__((section(".text.CustomIDWork_setSlotMessAndPosY")))
void CustomIDWork_setSlotMessAndPosY(DogRaceList *self, unsigned char msgSlot, unsigned char ySlot, int messNo)
{
    SlotY tbl;

    if (msgSlot < SLOT_COUNT && ySlot < SLOT_COUNT) {
        CustomIDWork_SetMessNo(&self->elem[BANK_A_ELEM + msgSlot], messNo);
        CustomIDWork_SetMessNo(&self->elem[BANK_B_ELEM + msgSlot], messNo);
        tbl = *(SlotY *)D_0042BDC0;
        CustomIDWork_SetLocalPosY(&self->elem[BANK_Y_ELEM + ySlot], tbl.w[msgSlot]);
    }
}

/* An enemy object that counts down a timer for its current mode. */
typedef struct cEmModeTimer {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x28];
    float modeLeft;                     /* 0x608 seconds left in the current mode */
} cEmModeTimer;

extern EmPhaseTable D_003BDA58;

/* Mode tick: run the handler of the mode's table row, count the mode timer down by the speed rate (floored at 0), then
 * the shared post-update step. */
__attribute__((section(".text.cEmObj_tickModeTimer")))
void cEmObj_tickModeTimer(cEmModeTimer *self)
{
    float left;

    if (ClearField5B4IfFlagUnset_1B76B0(&self->base) == 0) return;
    EM_PHASE_RUN(&D_003BDA58, self, self->base.mode);
    left = self->modeLeft - cEmManage_GetSpeedRate(&D_005864F0);
    self->modeLeft = left;
    if (left < 0.0f)
        self->modeLeft = 0.0f;
    func_001B76D8(&self->base);
}
