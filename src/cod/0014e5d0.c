/* sn-2.95.3-136 matched TU. */

#include "godhand/cTaskWork.h"
#include "godhand/Poker.h"
#include "godhand/cObjBase.h"
#include "godhand/cDataManager.h"
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cGameObj.h"
#include "godhand/Slot1.h"
#include "godhand/vtables.h"

extern int CreateThread(void *param);
extern void StartThread_3B0BA8(int tid, cTaskWork *self);
extern void WakeupThread(int tid);
extern void WaitSema(int sema);
extern void cTaskWork_kill(cTaskWork *self);
extern cDataManager D_005864E0;
extern cDataManager D_00580D20;
extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern void displayScrollLayer(int id, int on);

/* The sleep counter at 0xE sits in cTaskWork's unnamed span; the thread parameters start at 0x20. */
#define TASKWORK_COUNT(self)   (*(unsigned short *)((char *)(self) + 0xE))
#define TASKWORK_THREAD_ARGS(self) ((char *)(self) + 0x20)
#define TASKWORK_STATE_DONE    0x7F







/* cTaskWork_step: one step of the task, switched on its state (0xC). State 2 creates the thread, state 1
 * counts the sleep down and wakes the thread at zero, state 4 and the ends of the other two mark the task
 * done and wait on the manager's semaphore. Once the state is DONE the task is killed. */
__attribute__((section(".text.cTaskWork_step")))
void cTaskWork_step(cTaskWork *self)
{
    switch (self->running) {
    case 2:
        self->tid = CreateThread(TASKWORK_THREAD_ARGS(self));
        StartThread_3B0BA8(self->tid, self);
        goto done;
    case 1:
        TASKWORK_COUNT(self) = TASKWORK_COUNT(self) - 1;
        if (TASKWORK_COUNT(self) != 0) {
            break;
        }
        WakeupThread(self->tid);
    case 4:
    done:
        self->running = TASKWORK_STATE_DONE;
        WaitSema(self->owner[TASKWORK_SEMA_WORD]);
        break;
    }
    if (self->running == TASKWORK_STATE_DONE) {
        cTaskWork_kill(self);
    }
}

/* cObj__dtor: the cObj part of the destructor. Put this class's vtable back, release the actor's data
 * kind from whichever manager holds it, then run the cModel part. */
__attribute__((section(".text.cObj__dtor")))
void cObj__dtor(cObjBase *self, int flags)
{
    self->vtable = D_0041EAF0;
    if (self->actorId != 0) {
        if (cDataManager_isLoaded(&D_005864E0, self->actorId) == 1) {
            cDataManager_resetKind(&D_005864E0, self->actorId, 0);
        } else if (cDataManager_isLoaded(&D_00580D20, self->actorId) == 1) {
            cDataManager_resetKind(&D_00580D20, self->actorId, 0);
        }
    }
    cModel_destroy((cModel *)self, flags);
}

/* The element that slides in and out sits at 0xDC of the owner. */
#define SLIDE_ELEM      1               /* the sliding element */
#define SLIDE_HIDDEN_Y  (-0x46)

/* CustomIDOwner_setSlideState: place or slide the element in (sel 2: down from hidden to shown over 10 frames; sel 3:
 * the way back; sel 1: shown at once; others: hidden). */
__attribute__((section(".text.CustomIDOwner_setSlideState")))
void CustomIDOwner_setSlideState(Poker *self, unsigned char sel)
{
    switch (sel) {
    case 0:
    default:
        CustomIDWork_SetOffsetPosY(&self->elem[SLIDE_ELEM], SLIDE_HIDDEN_Y);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosY(&self->elem[SLIDE_ELEM], 0);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosY(&self->elem[SLIDE_ELEM], SLIDE_HIDDEN_Y, 0, 10);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosY(&self->elem[SLIDE_ELEM], 0, SLIDE_HIDDEN_Y, 10);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    }
}

/* ColiseumBattle_stepEntryWait5: phase 0 defeats every enemy and moves on; phase 1 clears each of the first five entry
 * handles whose entry reports active. */
__attribute__((section(".text.ColiseumBattle_stepEntryWait5")))
void ColiseumBattle_stepEntryWait5(ColiseumBattle *self)
{
    switch (self->phase) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->unkC64[0] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[0]) != 0) {
                self->unkC64[0] = 0;
            }
        }
        if (self->unkC64[1] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[1]) != 0) {
                self->unkC64[1] = 0;
            }
        }
        if (self->unkC64[2] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[2]) != 0) {
                self->unkC64[2] = 0;
            }
        }
        if (self->unkC64[3] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[3]) != 0) {
                self->unkC64[3] = 0;
            }
        }
        if (self->unkC64[4] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[4]) != 0) {
                self->unkC64[4] = 0;
            }
        }
        break;
    }
}

/* A box as centre and half-extents. */
typedef struct Box {
    float x, y, z;              /* 0x00 centre */
    float hx, hy, hz;           /* 0x0C half-extents */
} Box;

extern void func_001F8A88(Box *self, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

/* Box_growToContain: grow the box to contain another box, by taking the lower and upper bound on each axis. */
__attribute__((section(".text.Box_growToContain")))
Box *Box_growToContain(Box *self, Box *other)
{
    float minX, maxX, minY, maxY, minZ, maxZ;
    float t;

    t = self->x - self->hx;
    minX = other->x - other->hx;
    if (t < minX) minX = t;
    t = self->x + self->hx;
    maxX = other->x + other->hx;
    if (maxX < t) maxX = t;

    t = self->y - self->hy;
    minY = other->y - other->hy;
    if (t < minY) minY = t;
    t = self->y + self->hy;
    maxY = other->y + other->hy;
    if (maxY < t) maxY = t;

    t = self->z - self->hz;
    minZ = other->z - other->hz;
    if (t < minZ) minZ = t;
    t = self->z + self->hz;
    maxZ = other->z + other->hz;
    if (maxZ < t) maxZ = t;

    func_001F8A88(self, minX, maxX, minY, maxY, minZ, maxZ);
    return self;
}

#define DRIFT_LAYER_0  21      /* scrollLayer[] indices of the drift layers */
#define DRIFT_LAYER_1  22
#define DRIFT_LAYER_2  23
#define DRIFT_LAYER_3  24
#define DRIFT_LAYER_4  33
#define DRIFT_LAYER_5  34

/* LayerScreen_hideLayers: with both objects present, hide every layer and clear the shown flag; for sel 1 also
 * zero the objects' x positions and show the two main layers again. */
__attribute__((section(".text.LayerScreen_hideLayers")))
void LayerScreen_hideLayers(Slot1 *self, unsigned char sel)
{
    if (sel < 2) {
        if (self->drift[0] == 0) return;
        if (self->drift[1] == 0) return;
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_0], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_1], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_2], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_3], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_4], 0);
        displayScrollLayer(self->scrollLayer[DRIFT_LAYER_5], 0);
        self->flags &= ~SLOT1_F_DRIFT;
        if (sel == 0) return;
        if (sel == 1) {
            self->drift[0]->pos->x = 0.0f;
            self->drift[1]->pos->x = 0.0f;
            displayScrollLayer(self->scrollLayer[DRIFT_LAYER_0], 1);
            displayScrollLayer(self->scrollLayer[DRIFT_LAYER_4], 1);
            self->flags |= SLOT1_F_DRIFT;
        }
    }
}
