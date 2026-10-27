/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/capVu0.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/ptrVec.h"
#include "godhand/cVec.h"

extern int cOmWeapon_ckGetEnable(cOmWeapon *self);
extern int func_001D0AE0(cOmWeapon *self);

/* The first weapon that can be picked up within radius of pos on the ground
 * plane, from 0.5 below to 1.7 above it, with a clear line from pos to it;
 * unless all is set, weapons whose 0x66C float is above zero are passed over.
 * 0 when there is none.
 * Still differs from retail: retail keeps the 0x379 case id in a saved
 * register across the loop (a 0x10 larger frame), builds the id >= 0x300
 * test with slti/xori, and loads each object into $a0 before $s0. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002DDAB0")))
cOmWeapon *func_002DDAB0(cVec *pos, int all, float radius)
{
    cVec from;
    cVec to;
    void **it;
    void **end;

    end = D_00754C58.v->end;
    it = D_00754C58.v->begin;
    while (it != end) {
        cGameObj *obj = *it++;
        cOmWeapon *w;
        float dy;

        if (obj->objFlags & 0x8000) {
            continue;
        }
        if (obj->objFlags & 0x80000000) {
            continue;
        }
        if ((cGameObj_idInRange(obj, 0x300, 0x500) & 0xFF) == 0) {
            continue;
        }
        w = (cOmWeapon *)obj;
        switch (obj->actorId) {
        case 0x361:
        case 0x362:
        case 0x363:
        case 0x368:
        case 0x379:
        case 0x380:
        case 0x3AF:
        case 0x3B7:
            break;
        default:
            continue;
        }
        if (cOmWeapon_ckGetEnable(w) == 0) {
            continue;
        }
        if (all == 0 && func_001D0AE0(w) != 0) {
            continue;
        }
        if (capVu0MagnitudeSqXZ(pos, w->base.pos) > radius * radius) {
            continue;
        }
        dy = pos->y - w->base.pos->y;
        if (1.7f < dy) {
            continue;
        }
        if (dy < -0.5f) {
            continue;
        }
        CVEC_ZERO(from);
        CVEC_ZERO(to);
        CVEC_ASSIGN(from, pos);
        CVEC_ASSIGN(to, w->base.pos);
        from.y += 0.5f;
        to.y += 0.5f;
        if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 0) {
            return w;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002DDAB0);
#endif
