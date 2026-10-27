/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/capVu0.h"
#include "godhand/libm.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

extern void cEm00_setGoto(cEm00 *self, cVec *pos, int kind, int reset, float time);

#ifdef NON_MATCHING
/* Enemy reaction to the manager's stored point (unk520): when the manager
 * allows it and the enemy isn't sliding, an enemy within 5 (XZ) of the point
 * either goes to phase 0x6D (some enemy numbers), ignores it (0x220-0x223,
 * 0x26A), or walks to 10 units beyond the point, away from it (phase 0x13).
 * Returns 1 when it reacted.
 * Still differs from retail: in the away-from-the-point branch the sqrt.s is
 * scheduled before the direction copy; retail has it after the stores. */
__attribute__((section(".text.func_0026E258")))
int func_0026E258(cEm00 *self)
{
    cVec at;
    cVec dir;
    cVec goal;
    CVEC_TEMPS;
    float dist;
    float scale;

    if (func_00291FD8(&D_005864F0) == 0) {
        return 0;
    }
    if (0.0f < self->slideTime) {
        return 0;
    }
    CVEC_STORE(&at, D_005864F0.unk520);
    dist = capVu0MagnitudeSqXZ(&at, self->pos);
    if (25.0f < dist) {
        return 0;
    }
    switch (self->emNo) {
    case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
    case 0x218:
    case 0x245: case 0x246: case 0x247:
    case 0x24F: case 0x250: case 0x251:
    case 0x278: case 0x279:
        self->phase = 0x6D;
        self->stepArg = 0;
        break;
    case 0x220: case 0x221: case 0x222: case 0x223:
    case 0x26A:
        return 0;
    default:
        CVEC_ZERO(dir);
        CVEC_ZERO(goal);
        if (dist == 0.0f) {
            dir.x = 0.0f;
            dir.y = 0.0f;
            dir.z = 1.0f;
            dist = 1.0f;
        } else {
            CVEC_SUB(self->pos, &at);
            dir.x = ret_.x;
            dir.z = ret_.z;
            dir.y = 0.0f;
            dist = sqrtf(dist);
        }
        scale = 10.0f / dist;
        dir.x *= scale;
        dir.z *= scale;
        CVEC_ADD(&dir, self->pos);
        goal.x = ret_.x;
        goal.y = ret_.y;
        goal.z = ret_.z;
        cEm00_setGoto(self, &goal, 7, 0, 60.0f);
        self->stepArg = 1;
        self->phase = 0x13;
        break;
    }
    self->mode = 0;
    self->step = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0026E258);
#endif
