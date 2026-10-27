/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cVec.h"

struct LineObj;
void LineObj_checkWaterHit(struct LineObj *self);

#define WEAPON_GRAVITY   0.013f
#define WEAPON_MIN_SPEED -1.95f
#define WEAPON_REST_OFS  0.15f
#define WEAPON_SPIN      0.5235988f

#ifdef NON_MATCHING
/* A dropped weapon: falls (spinning its body) until it lands on the floor,
 * plays its landing sound and effect, then waits; kind 0x3AF breaks after a
 * countdown. Still differs from retail in one word: case 2's fall-speed exit
 * branches past the reset block's `v0 = 1` (v0 already holds the unk664
 * store's 1); retail branches to the block's first word. */
__attribute__((section(".text.func_001C9AF0")))
void func_001C9AF0(cOmWeapon *self)
{
    int frame[3];
    cVec to;
    cVec from;
    cVec hit;
    float rate;
    cOmBase *body;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    body = cOmBase_childAt(&self->base, frame, 0);
    if (self->parent != 0) {
        return;
    }
    CVEC_ZERO(to);
    CVEC_COPY(from, self->base.pos);
    CVEC_ZERO(hit);
    switch (self->base.step) {
    case 0:
        self->base.unk531 = 2;
        self->fallVel = 450.0f;
        self->base.step++;
        self->base.unk56A = 0;
        /* fall through */
    case 1:
        if (body != 0) {
            body->posPrev.x += rate * WEAPON_SPIN;
        }
        self->base.pos->y += self->fallSpeed * rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallSpeed < WEAPON_MIN_SPEED) {
            break;
        }
        CVEC_ASSIGN(to, self->base.pos);
        to.y -= 1.0f;
        from.y += 0.5f;
        if (ChkLine(&from, &to, &hit, 0, 2, 0x534, 0, 0, 0, 0, 0, 0, 1) != 0
            && self->base.pos->y < hit.y + WEAPON_REST_OFS) {
            self->base.pos->y = hit.y + WEAPON_REST_OFS;
            self->fallSpeed = 0.0f;
            switch (self->base.actorId) {
            case 0x361: /* retail's sound table starts at 0x361 */
            default:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x115, self, 0, 0, 0, 0);
                break;
            case 0x362: case 0x36D: case 0x375: case 0x377: case 0x378:
            case 0x3A8: case 0x3A9: case 0x3AA: case 0x3AB: case 0x3AD:
            case 0x3AE: case 0x3B4:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x116, self, 0, 0, 0, 0);
                break;
            case 0x363:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11E, self, 0, 0, 0, 0);
                break;
            case 0x380:
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xEA, self, 0, 0, 0, 0);
                break;
            case 0x3B7:
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x27, self, 0, 0, 0, 0);
                break;
            case 0x3AF:
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xD4, self, 0, 0, 0, 0);
                break;
            }
            SetEffect(0, 0x2D, self, 0, -1, -1);
            self->base.step++;
            if (body != 0) {
                body->posPrev.x = 0.0f;
                body->posPrev.y = 0.0f;
                body->posPrev.z = 0.0f;
            }
        }
        LineObj_checkWaterHit((struct LineObj *)self);
        return;
    case 2:
        if (--self->base.unk56A <= 0) {
            self->base.unk56A = 60;
            SetEffectPos(0, 0x1B, 0, self->base.pos, -1, 1.0f);
        }
        self->unk664 = 1;
        self->base.pos->y += self->fallSpeed * rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallSpeed < WEAPON_MIN_SPEED) {
            break;
        }
        CVEC_ASSIGN(to, self->base.pos);
        to.y -= 1.0f;
        from.y += 0.5f;
        if (ChkLine(&from, &to, &hit, 0, 2, 0x534, 0, 0, 0, 0, 0, 0, 1) != 0
            && self->base.pos->y < hit.y + WEAPON_REST_OFS) {
            self->base.pos->y = hit.y + WEAPON_REST_OFS;
            self->fallSpeed = 0.0f;
        }
        if (self->base.actorId != 0x3AF) {
            return;
        }
        self->fallVel -= rate;
        if (self->fallVel <= 0.0f) {
            self->base.mode = 1;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        return;
    case 3:
        self->unk665 = 1;
        self->unk664 = 1;
        return;
    case 4:
        self->base.unk531 = -1;
        self->fallVel = 15.0f;
        self->base.step++;
        self->base.unk56A = 0;
        /* fall through */
    case 5:
        if (body != 0) {
            body->posPrev.x += rate * WEAPON_SPIN;
        }
        self->base.pos->y += self->fallSpeed * rate;
        self->fallVel -= rate;
        self->fallSpeed -= rate * WEAPON_GRAVITY;
        if (self->fallVel <= 0.0f) {
            self->base.mode = 1;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        return;
    default:
        return;
    }
    self->base.mode = 1;
    self->base.phase = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C9AF0);
#endif
