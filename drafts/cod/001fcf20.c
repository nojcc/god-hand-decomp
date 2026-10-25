/* sn-2.95.3-136 */
#include "godhand/cDamageGive.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/criStm.h"
#include "godhand/player.h"
#include "godhand/cVec.h"
#include "include_asm.h"

/* 230 words against retail's 231 (retail also saves fp). Still differs:
 * retail keeps &self->hitVec (spilled to the stack) and the subtraction's
 * temporary address (in fp) hoisted in front of the hit loop, and stores
 * dir.y from the float register that holds 0.0 for the compares; here both
 * addresses are rebuilt in the loop and dir.y is stored as an integer zero.
 * The register numbering and the order of the 0x40/0x44 copies follow. */

#define DAMAGE_HIT_MAX    20
#define DAMAGE_NO_LINE    1     /* flags bit 0 of the give and the take: hit without the line-of-sight check */
#define DAMAGE_TAKE_HIT   3     /* cDamageTake.flags: a hit arrived */
#define DAMAGE_LINE_KIND  7
#define DAMAGE_LINE_MASK  0x34

extern void SetField_ACD0_1FE348(int a0, int a1);
extern int D_003BF190;          /* hit stop when the player lands a hit */
extern int D_003BF194;          /* hit stop when the player takes one */

#ifdef NON_MATCHING
static inline unsigned char isSuspended(cGameObj *obj)
{
    if (obj->objFlags & GAMEOBJ_OBJ_SUSPEND)
        return 1;
    return 0;
}

static inline cVec *centerOf(cGameObj *obj)
{
    return obj->vt->getCenter((char *)obj + obj->vt->getCenterDelta);
}

static inline void cDamageTake_setKind(cDamageTake *take, int kind)
{
    take->kind = kind;
}

static inline void cDamageTake_setUnk44(cDamageTake *take, int unk44)
{
    take->unk44 = unk44;
}

/* Hand the attack to every volume its hit volumes touch: skip flashing,
 * suspended and own targets and any behind a wall, then fill the victim's take
 * record and start the hit stop when the player is in it. */
__attribute__((section(".text.func_001FCF20")))
void func_001FCF20(cDamageGive *self)
{
    cDamageData *hits[DAMAGE_HIT_MAX];
    cDamageNode *node;
    cDamageData *ent;

    if (self->owner != 0 && isSuspended(self->owner) == 1)
        return;
    func_003A52F0(hits, 0, sizeof(hits));
    for (node = self->nodes; node != 0; node = node->next) {
        int i;

        func_001FC810(node, hits, DAMAGE_HIT_MAX);
        for (i = 0; i < DAMAGE_HIT_MAX && (ent = hits[i]) != 0; i++) {
            cDamageTake *take = (cDamageTake *)func_002BB138(ent->keys, CDAMAGE_KEY_TAKE);
            cGameObj *victim = take->victim;
            cCollisionShape *shape;
            cDamageVtEnt *ent;
            long takeOpts;
            long giveFlags;

            if (victim != 0) {
                if (victim->hitFlash > 0.0f)
                    continue;
                if (victim == self->owner)
                    continue;
                if (victim == self->ignore)
                    continue;
                if (isSuspended(victim) == 1)
                    continue;
                takeOpts = (unsigned int)take->opts;
                giveFlags = (unsigned int)self->flags;
                if ((takeOpts & DAMAGE_NO_LINE) == 0 && (giveFlags & DAMAGE_NO_LINE) == 0
                    && self->owner != 0) {
                    cVec from;
                    cVec to;

                    CVEC_COPY(from, centerOf(self->owner));
                    CVEC_COPY(to, centerOf(victim));
                    from.y += 1.0f;
                    to.y += 1.0f;
                    if (ChkLine(&from, &to, 0, 0, DAMAGE_LINE_KIND, DAMAGE_LINE_MASK, 0,
                                0, 0, 0, 0, 0, 1) != 0)
                        continue;
                }
            }
            take->flags |= DAMAGE_TAKE_HIT;
            cDamageTake_setKind(take, self->unk46);
            take->unk40 = self->unk40;
            cDamageTake_setUnk44(take, self->unk44);
            {
                cVec dir;

                CVEC_COPY(dir, &self->hitVec);
                if (dir.x == 0.0f && dir.y == 0.0f && dir.z == 0.0f) {
                    if (victim != 0)
                        CVEC_SET_SUB(dir, victim->pos, &node->pos);
                    dir.y = 0.0f;
                }
                cVec_copy3(&take->dir, &dir);
            }
            shape = node->data->shape;
            ent = &shape->vt[CDAMAGE_SHAPE_GETPOS];
            cVec_copy3(&take->hitPos, ((cVec *(*)(void *))ent->pfn)((char *)shape + ent->delta));
            take->power = self->activeTime;
            take->attacker = (char *)self->owner;
            self->lastHit = take->victim;
            if (Getplayer() == self->owner)
                SetField_ACD0_1FE348((int)D_00574380, D_003BF190);
            if (Getplayer() == victim)
                SetField_ACD0_1FE348((int)D_00574380, D_003BF194);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001FCF20);
#endif
