/* NON_MATCHING func_001FE370 (sn, likely-slot fill + loop pad): retail pads the first loop head to 8 bytes (nop before .L001FE3A0, as in ScriptRun_runChannel) and fills the live/owner branch slots with the pointer/counter increment via beql/bnel, reloading lbu in the back-edge slot; ours fills them from the fall-through (daddu a1) with plain beq/bne. for, do-while and continue forms are the same. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x30];
    void *owner; /* 0x30 */
    char pad34[0x4A - 0x34];
    unsigned char live; /* 0x4A */
    char pad4B[0x60 - 0x4B];
} DmgGive;
typedef struct {
    char pad0[0x30];
    void *owner; /* 0x30 */
    char pad34[0x4A - 0x34];
    unsigned char live; /* 0x4A */
    char pad4B[0x70 - 0x4B];
} DmgRecv;
typedef struct {
    DmgGive give[160]; /* 0x0000 */
    DmgRecv recv[256]; /* 0x3C00 */
} DmgMgr;
extern int cDamageManage_ReleaseDamageGive(DmgMgr *mgr, DmgGive *give);
extern void ClearAndResetFields_1FE278(DmgMgr *mgr, DmgRecv *recv);

void func_001FE370(DmgMgr *mgr, void *owner)
{
    DmgGive *g;
    DmgRecv *r;
    unsigned int i;

    g = mgr->give;
    do {
        if (g->live == 0)
            continue;
        if (g->owner != owner)
            continue;
        cDamageManage_ReleaseDamageGive(mgr, g);
    } while (++g < &mgr->give[160]);
    r = mgr->recv;
    for (i = 0; i < 256; i++, r++) {
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
