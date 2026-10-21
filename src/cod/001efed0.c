/* NON_MATCHING func_001EFED0 (sn-2.95.3-136): arm the next damage unit. Retail keeps pos in s2 and
 * the unit array in s3; ours swaps them, and the reloads of the unit pointer use v0 where ours uses v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern void cDamageGive_SetDmgGiveHitVec(void *self, void *dir);
extern void cDamageUnit_SetDamageCollFlashActive(char *self, int active, short val);
extern void cDamageUnit_SetDamageCollOffset(void *self, void *offset);
extern int cSnd_SeCall(void *self, int slot, short key1, int mtx, int idA, int idB);
#include "godhand/cSnd.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cDamageGive.h"
#include "godhand/vu0.h"

#define HITSET_NUM      6
#define HITSET_EFFECT   0x57
#define HITSET_SE_SLOT  2
#define HITSET_SE_A     0xD2
#define HITSET_SE_B     0xD3

/* An object that arms its damage units one at a time. */
typedef struct cHitSet {
    char unk000[0xBB0];
    cDamageGive *unit[HITSET_NUM];      /* 0xBB0 */
    unsigned int next;                  /* 0xBC8 the unit armed next */
} cHitSet;

extern cSnd D_005FEE00;

extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);

/* Arm the next damage unit at pos with hit direction dir: flash, two sounds and the unit's offset and push. */
void func_001EFED0(cHitSet *self, cVec *pos, cVec *dir)
{
    cVec at;

    if (self->next < HITSET_NUM) {
        if (self->unit[self->next] != 0) {
            SetEffectPos(0, HITSET_EFFECT, 0, pos, -1, 1.0f);
            VU0_LQC2(4, pos, 0);
            VU0_SQC2(4, &at, 0);
            cSnd_SeCall(&D_005FEE00, HITSET_SE_SLOT, HITSET_SE_A, (int)&at, 0, 0);
            cSnd_SeCall(&D_005FEE00, HITSET_SE_SLOT, HITSET_SE_B, (int)&at, 0, 0);
            cDamageUnit_SetDamageCollOffset((void *)self->unit[self->next], pos);
            cDamageGive_SetDmgGiveHitVec(self->unit[self->next], dir);
            cDamageUnit_SetDamageCollFlashActive((char *)self->unit[self->next], 1, 1);
        }
        self->next++;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001EFED0);
#endif
