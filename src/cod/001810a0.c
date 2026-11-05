/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cRelSys.h"
#include "godhand/heapArena.h"
#include "godhand/cEvent.h"
#include "godhand/cDataManager.h"
#include "godhand/cDvd.h"
#include "godhand/espSys.h"

extern int cOmBase_checkDamage(cOmBase *self, int take);
extern void cDataSlot_resetSeHandles(cDataSlot *slot);
extern float fRand1_1(void);

/* Hit reaction: when the damage check reports a hit, go to state 2 and mark the object active. */


typedef struct cOmHitReact {
    cOmBase base;
    char unk5E0[0x20];
    int damageTake;                     /* 0x600 hit record handed to cOmBase_checkDamage */
} cOmHitReact;



__attribute__((section(".text.cOmBase_reactHit")))
void cOmBase_reactHit(cOmHitReact *self)
{
    if (cOmBase_checkDamage(&self->base, self->damageTake) == 1) {
        int flags = self->base.flags0;
        self->base.mode = 2;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->base.flags0 = flags | COMBASE_F0_ACTIVE;
    }
}

/* Close the cutscene record: unlink the display text if linked, free the cutscene data, return to idle. */







__attribute__((section(".text.cEvent_freeData")))
void cEvent_freeData(cEvent *self)
{
    unsigned long b = *(unsigned char *)&self->flags;
    int *node;
    if (b >> 7)
        cRelSys_unlinkNoFree(D_005E8640, 2);
    node = (int *)self->resData;
    if (node != 0)
        cHeap_free(HEAP_OWNER(node), node);
    self->resData = 0;
    func_00297660(self);
}

/* Try to retire an unused slot. Returns 1 when the slot is in use or was retired, 0 when it is pinned, flagged to stay, or not retirable yet. */


#define CDATA_FLAG_KEEP_BIT  1          /* bit number in flags: the slot may not be retired */




__attribute__((section(".text.cDataManager_retireSlot")))
int cDataManager_retireSlot(cDataSlot *slot)
{
    unsigned long f;
    unsigned long bit;
    if (slot->useCount < 0)
        return 0;
    if (slot->useCount > 0)
        return 1;
    f = slot->flags;
    bit = (f >> CDATA_FLAG_KEEP_BIT) & 1;
    if (bit)
        return 0;
    if (cDataSlot_releaseLoadedSe(slot) == 0)
        return 0;
    cDataSlot_resetSeHandles(slot);
    return 1;
}

#define LINKVT_HOOK         16          /* vtable entry 16, byte offset 0x80 */

/* Call virtual method 16 (the lock-on hook) unless the effect is hidden, or its owner has CMODEL_F_SHOWN and the effect lacks bit 7. */
__attribute__((section(".text.LinkObj_callLockOn")))
void LinkObj_callLockOn(EspAnim *self)
{
    unsigned long f = self->flags;
    unsigned long bit;
    cVtEnt *vt;
    if (f & ESP_ANIM_HIDE)
        return;
    if (self->owner != 0) {
        if (self->owner->objFlags & CMODEL_F_SHOWN) {
            bit = (f >> ESP_ANIM_KEEP_HOOK_BIT) & 1;
            if (bit == 0)
                return;
        }
    }
    vt = self->vtable;
    ((void (*)(void *))vt[LINKVT_HOOK].pfn)((char *)self + vt[LINKVT_HOOK].delta);
}

/* Poll the running read: status 1 or 3 means it ended, so free its slot and start the next job; status 2 means keep waiting. */




__attribute__((section(".text.cDvd_pollJob")))
void cDvd_pollJob(cDvd *self)
{
    switch (func_002018D0(self)) {
    case 1:
    case 3:
        FreeObjectSlot_2018F0(self);
        self->queueNum = 1;
        func_00201290(self);
        break;
    case 2:
        break;
    }
}

/* Shake the object's height: count the timer down and jitter its y by a small random amount, then restore the rest height when it runs out. */


#define OMSHAKE_JITTER  0.015f

typedef struct cOmShake {
    cOmBase base;
    char unk5E0[0x20];
    short timer;                        /* 0x600 frames of shake left */
    char unk602[2];
    float restY;                        /* 0x604 height to return to */
} cOmShake;



__attribute__((section(".text.cOmBase_shakeHeight")))
void cOmBase_shakeHeight(cOmShake *self)
{
    if (self->timer > 0) {
        self->timer--;
        if (self->timer != 0)
            self->base.pos->y = self->restY + fRand1_1() * OMSHAKE_JITTER;
        else
            self->base.pos->y = self->restY;
    }
}
