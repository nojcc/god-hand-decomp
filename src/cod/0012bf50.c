/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/criStm.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cMc.h"
#include "godhand/cEvent.h"
#include "godhand/cIDBaseScreen.h"

extern cGameObj *InitFields_1B6E90(cGameObj *self);
#include "godhand/objField.h"
extern cVtEnt D_00427400[];
extern int D_005864F0;
extern int cEmManage_CkPlCatched(void *p);
extern void func_0();
extern cMc D_005E6900;
extern cMcTaskRef D_00752C00;
extern void cMc_DllLoad(cMc *self, int pump);
extern void cMc_DllRelease(cMc *self);
extern void cTaskWork_exit(void *task);

/* Constructor of a game object subclass: base init, method table, seven cleared quadwords at 0x610, tag the block at 0x630. */
__attribute__((section(".text.cGameObj_constructSubclassA")))
cGameObj *cGameObj_constructSubclassA(cGameObj *self) {
    char *blk;
    InitFields_1B6E90(self);
    self->vtable = D_00427400;
    VU0_SQC2_VF0(self, 0x610);
    VU0_SQC2_VF0(self, 0x620);
    blk = (char *)self + 0x630;
    VU0_SQC2_VF0(self, 0x630);
    VU0_SQC2_VF0(self, 0x640);
    VU0_SQC2_VF0(self, 0x650);
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    Obj0000_Set_Byte_54(blk, 0);
    return self;
}

/* Copy num texture addresses from src into the screen (clamped to SCR_LIST_MAX) and mark it ready. */
__attribute__((section(".text.BlendWork_copyTable")))
void BlendWork_copyTable(cIDBaseScreen *self, void **src, short num) {
    if (num >= SCR_LIST_MAX + 1) {
        self->texNum = SCR_LIST_MAX;
    } else {
        self->texNum = num;
    }
    func_003A5148(self->tex, src, self->texNum << 2);
    self->flags |= SCR_FLAG_READY;
}

/* Nonzero if the player may start an attack action: alive, free, not caught, and the button flag is on. */
__attribute__((section(".text.pl00_ckAtkActBtnEnable")))
int pl00_ckAtkActBtnEnable(pl00 *self) {
    if (self->sub6A0 != 0) {
        return 0;
    }
    if (self->base.hp <= 0) {
        return 0;
    }
    if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(self) != 0) {
        return 0;
    }
    if (cEmManage_CkPlCatched(&D_005864F0) != 0) {
        return 0;
    }
    return ((unsigned char *)&self->flags15F4)[1] & 1;
}

/* Load the memory card module, run its two stripped log hooks, release it and end the calling task. */
__attribute__((section(".text.cMc_loadRunRelease")))
void cMc_loadRunRelease(void) {
    cMc_DllLoad(&D_005E6900, 0);
    func_0(cEvent_nullStr00);
    func_0(cEvent_nullStr00);
    cMc_DllRelease(&D_005E6900);
    cTaskWork_exit(D_00752C00.task);
}

/* A four-slot table of {key, value} pairs. */
typedef struct KeySlot {
    int key;                            /* 0x0 key, 0 when the slot is free */
    int value;                          /* 0x4 */
} KeySlot;




/* Store value under key: replace the value of an existing key, else take a free slot. 1 on success, 0 if full. */
__attribute__((section(".text.KeySlotTable_set")))
int KeySlotTable_set(KeySlot *tbl, int key, int value) {
    KeySlot *found = func_002BB068(tbl, key);
    KeySlot *fresh;
    if (found != 0) {
        found->value = value;
    } else {
        fresh = func_002BB098(tbl);
        if (fresh == 0) {
            return 0;
        }
        fresh->key = key;
        fresh->value = value;
    }
    return 1;
}
