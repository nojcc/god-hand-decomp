/* NON_MATCHING func_00262750 (sn-2.95.3-136, extern_jtbl D_004440E0): 4 of 140 insns differ, a v0/v1 swap in the motion vector block. Retail puts &posA in v1 and the vsub result address in v0; ours has them the other way round. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cDamageGive.h"
#include "godhand/vu0.h"

extern void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active);
extern void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset);
extern void ForwardEventToList_1FD820(void *a0, void *a1);
extern void cDamageGive_SetDmgGiveHitVec(cDamageGive *self, cVec *dir);

/* cEm00.h does not name 0x690 yet, and cDamageGive.h does not name 0x40..0x4C. */
#define EM00_DAMAGE_GIVE(self) (*(char **)((char *)(self) + 0x690))
#define GIVE_KIND(g)  (*(short *)((g) + 0x46))
#define GIVE_POWER(g) (*(int *)((g) + 0x4C))

/* Arm the enemy's attack volume for attack `kind`: set the hit kind and power, size and place the volume, and
 * push along the enemy's motion this frame. */
__attribute__((section(".text.func_00262750")))
void func_00262750(cEm00 *self, unsigned int kind)
{
    cVec ofs;
    cVec scale;
    cVec hit;
    cVec dir;
    cVec delta;
    char *give;

    VU0_SQC2_VF0_MEM(&ofs, 0);
    VU0_SQC2_VF0_MEM(&scale, 0);
    ofs.x = 0.0f;
    ofs.y = 0.0f;
    ofs.z = 0.0f;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    switch (kind) {
    case 0:
    default:
        GIVE_KIND(EM00_DAMAGE_GIVE(self)) = 0x2E;
        GIVE_POWER(EM00_DAMAGE_GIVE(self)) = 0xA;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)EM00_DAMAGE_GIVE(self), 1);
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        ofs.z = 0.0f;
        scale.x = 2.0f;
        scale.y = 2.0f;
        scale.z = 2.0f;
        break;
    case 1:
        GIVE_KIND(EM00_DAMAGE_GIVE(self)) = 0x2F;
        GIVE_POWER(EM00_DAMAGE_GIVE(self)) = 0x14;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)EM00_DAMAGE_GIVE(self), 1);
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        ofs.z = 0.0f;
        scale.x = 2.0f;
        scale.y = 2.0f;
        scale.z = 2.0f;
        break;
    case 2:
        GIVE_KIND(EM00_DAMAGE_GIVE(self)) = 0x2E;
        GIVE_POWER(EM00_DAMAGE_GIVE(self)) = 1;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)EM00_DAMAGE_GIVE(self), 1);
        ofs.x = 0.0f;
        ofs.y = -2.0f;
        ofs.z = 0.0f;
        scale.x = 0.3f;
        scale.y = 1.0f;
        scale.z = 0.3f;
        break;
    case 3:
        GIVE_KIND(EM00_DAMAGE_GIVE(self)) = 0x2F;
        GIVE_POWER(EM00_DAMAGE_GIVE(self)) = 0x14;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)EM00_DAMAGE_GIVE(self), 1);
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        ofs.z = 0.0f;
        scale.x = 2.5f;
        scale.y = 2.5f;
        scale.z = 2.5f;
        break;
    case 4:
        GIVE_KIND(EM00_DAMAGE_GIVE(self)) = 0x2E;
        GIVE_POWER(EM00_DAMAGE_GIVE(self)) = 1;
        cDamageUnit_SetDamageCollActive((cDamageUnit *)EM00_DAMAGE_GIVE(self), 1);
        ofs.x = 0.0f;
        ofs.y = -0.5f;
        ofs.z = 0.0f;
        scale.x = 1.0f;
        scale.y = 1.5f;
        scale.z = 1.0f;
        break;
    }
    cDamageUnit_SetDamageCollOffset((cDamageUnit *)EM00_DAMAGE_GIVE(self), &ofs);
    ForwardEventToList_1FD820(EM00_DAMAGE_GIVE(self), &scale);
    VU0_SQC2_VF0_MEM(&hit, 0);
    VU0_ZERO_VSUB_XYZ_MEM(&delta, 0, self->pos, &self->posA);
    VU0_LQC2_SQC2_MEM(4, &dir, &delta);
    hit.x = dir.x;
    hit.y = dir.y;
    hit.z = dir.z;
    cDamageGive_SetDmgGiveHitVec((cDamageGive *)EM00_DAMAGE_GIVE(self), &hit);
    give = EM00_DAMAGE_GIVE(self);
    *(int *)(give + 0x40) = -1;
    *(short *)(give + 0x44) = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00262750);
#endif
