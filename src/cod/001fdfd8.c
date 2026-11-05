#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"

extern void Trail_snapToSources(void *a0);
extern void FlashDriver_resetFlash(void *a0);
extern void func_001FCF20(void *a0);
extern void NoOp_1FD528(void *a0);

__attribute__((section(".text.func_001FDFD8")))
void func_001FDFD8(cDamageManage *m)
{
    cDamageGive *d;
    cDamageUnit *f;
    unsigned int i;

    if (m->hitStop != 0) {
        m->hitStop--;
        return;
    }
    d = m->give;
    do {
        if (d->live) Trail_snapToSources(d);
        d++;
    } while (d < m->give + CDAMAGE_GIVE_MAX);
    i = 0;
    f = m->take;
    do {
        if (f->live) FlashDriver_resetFlash(f);
        i++;
        f++;
    } while (i < CDAMAGE_TAKE_MAX);
    d = m->give;
    do {
        if (d->live) {
            func_001FCF20(d);
            cDamageUnit_UpdateDamageCollFlash((cDamageUnit *)d);
        }
        d++;
    } while (d < m->give + CDAMAGE_GIVE_MAX);
    f = m->take;
    i = 0;
    do {
        if (f->live) {
            NoOp_1FD528(f);
            cDamageUnit_UpdateDamageCollFlash(f);
        }
        i++;
        f++;
    } while (i < CDAMAGE_TAKE_MAX);
}
