/* sn-2.95.3-136 */
#include "godhand/cOmWeapon.h"
#include "godhand/cEmManage.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "include_asm.h"

/* 229 words against retail's 231. Still differs in the debris loop: retail
 * builds i + 1 and the child range flag in registers of their own and copies
 * them (two moves), and forms &body->posPrev for Adjust_theta_vec just before
 * the add instead of before the scaled copy. */
#ifdef NON_MATCHING

#define WEAPON_SPIN         0.87266463f /* 50 degrees: spin of a child body per unit of speed rate */
#define WEAPON_SWAY_Z       0.05f
#define WEAPON_SWAY_X       0.02f
#define WEAPON_GRAVITY      0.013f   /* taken off the fall speed every frame */
#define WEAPON_FADE         0.02f    /* taken off animRate every frame */

extern void KillEffect(int owner, int handle, int mode);


/* Broken weapon: stop the trail once (step 0), then every frame spin the
 * bodies left (one, two or the seven debris pieces, by actorId), drop, and
 * fade out; end when the fade reaches 0. */
__attribute__((section(".text.func_001CC668")))
void func_001CC668(cOmWeapon *self)
{
    float rate = cEmManage_GetSpeedRate(&D_005864F0);
    int frame[3];
    cOmBase *child;
    cOmBase *body;
    unsigned int i;

    switch (self->base.step) {
    case 0:
        KillEffect((int)self, 8, 2);
        self->base.step++;
    case 1:
        break;
    default:
        return;
    }
    switch (self->base.actorId) {
    case 0x361: case 0x362: case 0x363: case 0x368: case 0x36D: case 0x375:
    case 0x377: case 0x378: case 0x379: case 0x37B: case 0x380: case 0x390:
    case 0x3A8: case 0x3A9: case 0x3AA: case 0x3AB: case 0x3AD: case 0x3AE:
    case 0x3AF: case 0x3B4: case 0x3B7:
        child = cOmBase_childAt(&self->base, frame, 1);
        if (child != 0) {
            float spin = rate * WEAPON_SPIN;
            float z = rate * WEAPON_SWAY_Z;
            float x = rate * WEAPON_SWAY_X;

            child->posPrev.x += spin;
            child->anchor->z += z;
            child->anchor->x += x;
        }
        child = cOmBase_childAt(&self->base, frame, 2);
        if (child != 0) {
            float spin = rate * -WEAPON_SPIN;
            float z = rate * WEAPON_SWAY_Z;
            float x = rate * WEAPON_SWAY_X;

            child->posPrev.x += spin;
            child->anchor->z -= z;
            child->anchor->x += x;
        }
        self->base.pos->y += self->fallSpeed;
        self->fallSpeed -= WEAPON_GRAVITY;
        break;
    default:
        child = cOmBase_childAt(&self->base, frame, 0);
        if (child != 0) {
            child->posPrev.x += rate * WEAPON_SPIN;
        }
        self->base.pos->y += self->fallSpeed;
        self->fallSpeed -= WEAPON_GRAVITY;
        break;
    case 0x3B8: case 0x3B9: case 0x3BA:
        i = 0;
        do {
            cOmWeaponPiece *p;
            cVec *rot;

            body = cOmBase_childAtIdx(&self->base, frame, i + 1);
            if (body == 0) {
                break;
            }
            p = &self->piece[i];
            rot = &body->posPrev;
            {
                cVec d;

                CVEC_INIT_MUL(d, &p->rot, rate);
                CVEC_ADD_TO(*rot, &d);
            }
            Adjust_theta_vec(rot);
            {
                cVec d;

                CVEC_INIT_MUL(d, &p->vel, rate);
                CVEC_ADD_TO(*body->anchor, &d);
            }
            p->vel.y -= rate * WEAPON_GRAVITY;
            i++;
        } while (i < COMWEAPON_PIECE_NUM);
        break;
    }
    self->base.animRate -= WEAPON_FADE;
    self->base.objFlags |= COMBASE_OBJ_HELD;
    if (self->base.animRate <= 0.0f) {
        self->base.animRate = 0.0f;
        self->base.mode = 1;
        self->base.stepArg = 0;
        self->base.phase = 0;
        self->base.step = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001CC668);
#endif
