/* NON_MATCHING func_001FE370 (sn, likely-slot fill + loop pad): retail pads the first loop head to 8 bytes (nop before .L001FE3A0, as in ScriptRun_runChannel) and fills the live/owner branch slots with the pointer/counter increment via beql/bnel, reloading lbu in the back-edge slot; ours fills them from the fall-through (daddu a1) with plain beq/bne. for, do-while and continue forms are the same. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cDamageManage.h"

/* Release every give and take record owner holds. */
void func_001FE370(cDamageManage *mgr, void *owner)
{
    cDamageGive *g;
    cDamageUnit *r;
    unsigned int i;

    g = mgr->give;
    do {
        if (g->live == 0)
            continue;
        if (g->owner != owner)
            continue;
        cDamageManage_ReleaseDamageGive(mgr, g);
    } while (++g < &mgr->give[CDAMAGE_GIVE_MAX]);
    r = mgr->take;
    for (i = 0; i < CDAMAGE_TAKE_MAX; i++, r++) {
        if (r->live == 0)
            continue;
        if (r->owner != owner)
            continue;
        ClearAndResetFields_1FE278(mgr, r);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FE370);
#endif
