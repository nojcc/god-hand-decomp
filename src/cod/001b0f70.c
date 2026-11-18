/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/espSys.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void DamagePairObj_clearHits(void *a0);
extern void func_001B1938(void *a0);
extern void func_001B1630(void *a0);
extern void func_001B76D8(cOmBase *self);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */


#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_GROUPS  0x104          /* offset of the slot's group mask word */

/* Run the kill handler of every effect slot that is in use, neither paused nor hidden, and whose group mask has a bit of mask. */
__attribute__((section(".text.Esp_killByGroup")))
void Esp_killByGroup(int mask) {
    unsigned char *p;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if ((*(int *)(p + ESP_SLOT_GROUPS) & mask) == 0) goto next;
        UpdateObjByIndexedOp_2FBE50((EspAnim *)p);
next: ;
    }
}

/* One row of the mode table: this adjust, method index (or -1), table offset in the object, or the inline handler. */

extern EmPhaseTable D_003BDCC0;

/* Mode tick: unless a hit stop is running, refresh the speed rate, run the handler of the mode's table row, then the shared post-update steps. */
__attribute__((section(".text.ModeDispatch_tickWithHitStop")))
void ModeDispatch_tickWithHitStop(cOmBase *self)
{
    float rate;
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    if (cDamageManage_CkHitStop(&D_00574380) != 0) return;
    DamagePairObj_clearHits(self);
    rate = cEmManage_GetSpeedRate(D_005864F0);
    self->speedRate = rate;
    EM_PHASE_RUN(&D_003BDCC0, self, self->mode);
    func_001B1938(self);
    func_001B1630(self);
    func_001B76D8(self);
}
