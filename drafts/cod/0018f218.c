/* sn-2.95.3-136 */
/* func_0018F218: everything up to the child loop matches. In the loop retail
 * stores the child count to a stack slot (shared with v[1]) on every lookup,
 * tests the index against zero held in a register through a second counter,
 * and keeps the in-range test as a byte; this build tests with bltz and keeps
 * the count in a register, 11 instructions shorter. */
#include "include_asm.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/player.h"

#ifdef NON_MATCHING

/* The object func_0018F218 sets up: a cOmBase with its damage units after
 * the base part. */
typedef struct cOmPlayerHit {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x654 - 0x5E0];
    void *damageTake;                   /* 0x654 */
    void *damageGive;                   /* 0x658 */
    unsigned char unk65C;               /* 0x65C cleared at setup */
} cOmPlayerHit;

#define PLAYER_POWER(p)     (*(float *)((char *)(p) + 0x600))   /* the player record is not typed yet */
#define DMG_GIVE_KIND(u)    (*(short *)((char *)(u) + 0x46))    /* cDamageGive does not name these yet */
#define DMG_GIVE_POWER(u)   (*(int *)((char *)(u) + 0x4C))
#define CHILD_FLAGS(o)      (*(int *)((char *)(o) + 0x154))     /* cOmBase does not name 0x154 yet */

extern int cDamageUnit_AddDamageCollCylinder(char *self, int a1, int a2, int a3,
                                             float f12, float f13);
extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);

/* Setup: a damage-give sphere of radius 2.5 whose power follows the player's,
 * a 0.872 x 1.34 damage-take cylinder, 50 hp, layer 0 shown and layer 0x40
 * hidden, and flags 8 and 0x10 set on child bodies 1 to 6. */
__attribute__((section(".text.func_0018F218")))
int func_0018F218(cOmPlayerHit *self)
{
    int i;

    func_001B6FB8((cOmHitVolume *)self);
    {
        cVec v[4];         /* size twice, offset, rotation */
        cVec *ofs;
        cVec *rot;
        float *ov;
        cGameObj *player;
        void *give;
        void *take;

        ofs = &v[2];
        v[0].x = 0.872f;
        v[0].y = 1.34f;
        v[0].z = 0.872f;
        v[0].w = 1.0f;
        v[1].x = 0.872f;
        v[1].y = 1.34f;
        v[1].z = 0.872f;
        v[1].w = 1.0f;
        v[2].x = 0.0f;
        v[2].y = 0.0f;
        v[2].z = 0.0f;
        ofs->w = 1.0f;
        give = cDamageManage_CreateDamageGive(D_00574380, 3, self);
        self->damageGive = give;
        if (give != 0) {
            player = Getplayer();
            ov = &v[3].x;
            v[3].x = 0.0f;
            v[3].y = 0.0f;
            v[3].z = 0.0f;
            ov[3] = 1.0f;
            cDamageUnit_AddDamageCollSphere(self->damageGive, self->base.mtx, ov, 2.5f);
            DMG_GIVE_KIND(self->damageGive) = 0x52;
            DMG_GIVE_POWER(self->damageGive) = (int)(PLAYER_POWER(player) * 80.0f);
            cDamageUnit_SetDamageCollActive(self->damageGive, 0);
        }
        take = cDamageManage_CreateDamageTake(D_00574380, self, 2);
        self->damageTake = take;
        if (take != 0) {
            rot = &v[3];
            v[3].x = 0.0f;
            v[3].y = 0.0f;
            v[3].z = 0.0f;
            rot->w = 1.0f;
            cDamageUnit_AddDamageCollCylinder(take, (int)self->base.mtx, (int)ofs, (int)rot,
                                              v[1].y, v[1].x * 0.5f);
        }
    }
    self->unk65C = 0;
    self->base.hpMax = 50;
    self->base.hp = 50;
    cOmBase_setMeshDispFromLayer(self, 0, 1);
    cOmBase_setMeshDispFromLayer(self, 0x40, 0);
    for (i = 1; i < 7 && self->base.childNum != i; i++) {
        int frame;

        CHILD_FLAGS(cOmBase_childAt(&self->base, &frame, i)) |= 8;
        CHILD_FLAGS(cOmBase_childAt(&self->base, &frame, i)) |= 0x10;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0018F218);
#endif
