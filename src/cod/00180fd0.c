/* sn-2.95.3-136 matched TU. */

#include "godhand/ColiseumBattle.h"
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/emPhaseTable.h"

extern char D_00747470[];
extern void classFADE_kill(void *p);
extern void classFADE_start(void *p, int b, int c, int d, unsigned int e, unsigned int f, int g);
extern void func_00300D20(int a0, int a1);
extern void Esp_killByGroupPair(int a0, int a1);
extern void Slots_runHandlerForAll(int a0, int a1);
extern void func_002FBA60(int a0, int a1, int a2);
extern int ClearField5B4IfFlagUnset_1B76B0(cOmBase *self);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(cOmBase *self);
extern void cOmShake_updateHeight(void *);
extern void cOmBase_shakeHeight(void *);

/* Start a screen fade (mode 0 fades to black, mode 1 from black): stop a running fade first, then flag a fade as running. */


__attribute__((section(".text.ColiseumUi_StartFade")))
void ColiseumUi_StartFade(ColiseumBattle *self, unsigned char mode)
{
    long t = self->flags;
    unsigned int f;

    if (((t >> 1) % 2L) != 0L) {
        classFADE_kill(D_00747470);
        self->flags = (int)self->flags & ~COLISEUM_FLAG_FADE;
    }
    switch (mode) {
    case 0:
    default:
        classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000u, 0, 0xF);
        break;
    case 1:
        classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000u, 0xF);
        /* net no-op; its flag stores make jump2 share the two call tails, as retail does */
        self->flags++;
        self->flags--;
        break;
    }
    f = self->flags;
    do { } while (0);   /* keeps the epilogue restores behind the flag store */
    self->flags = f | COLISEUM_FLAG_FADE;
}

/* Remove an effect from one or both of its lists: mode 0 the first list, 1 the second, 2 both. */


__attribute__((section(".text.KillEffect_306168")))
void KillEffect_306168(int a0, int a1, int a2) {
    switch (a2) {
    case 0:
        func_00300D20(a0, a1);
        break;
    case 1:
        Esp_killByGroupPair(a0, a1);
        break;
    case 2:
        Esp_killByGroupPair(a0, a1);
        func_00300D20(a0, a1);
        break;
    }
}

/* Remove an effect (unless it is the null/-1 pair) from one or both lists; mode 0 first list, 1 second list with flag, 2 both. */


__attribute__((section(".text.KillEffectWithFlag")))
void KillEffectWithFlag(int a0, int a1, int a2, unsigned char a3) {
    if (a0 == 0 && a1 == -1) {
        return;
    }
    switch (a2) {
    case 0:
        Slots_runHandlerForAll(a0, a1);
        break;
    case 1:
        func_002FBA60(a0, a1, a3);
        break;
    case 2:
        func_002FBA60(a0, a1, a3);
        Slots_runHandlerForAll(a0, a1);
        break;
    }
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDC18;


__attribute__((section(".text.UpdatePhaseWithPostStepA")))
void UpdatePhaseWithPostStepA(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDC18, self, self->mode);
    cOmShake_updateHeight(self);
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_00180FD0 { short f0; short f2; short f4; short f6; };


extern EmPhaseTable D_003BDAF8;


__attribute__((section(".text.UpdatePhaseWithPostStepB")))
void UpdatePhaseWithPostStepB(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDAF8, self, self->mode);
    cOmBase_shakeHeight(self);
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */


extern EmPhaseTable D_003BDD60;


__attribute__((section(".text.UpdatePhaseThenCalcParts")))
void UpdatePhaseThenCalcParts(cOmBase *self)
{
    if (ClearField5B4IfFlagUnset_1B76B0(self) == 0) return;
    EM_PHASE_RUN(&D_003BDD60, self, self->mode);
    func_002A87E8(self, 0);
    cModel_calcParts((cModel *)self);
    cModel_calcWorldParts((cModel *)self);
    func_001B76D8(self);
}
