/* NON_MATCHING cEmManage_GetTargetNear (sn-2.95.3-136): 383 words vs 385.
 * Retail keeps the constant 1 (the flags2 bit-10 test and ChkLine's last
 * argument in the object loop) in s6 for the whole loop; this C loads it
 * inside the loop, so mode, the list end and the 1 take other saved
 * registers. The height test of the object loop's other branch also gives
 * a branch-likely where retail copies before the compare. */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/cEmManage.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBaseFn.h"
#include "godhand/cVec.h"
#include "godhand/ptrVec.h"
#include "godhand/capVu0.h"
#include "godhand/angle.h"
#include "godhand/cCollisionSolid.h"

/* The nearest target within range of pos and within angle of dir, other than
 * skip: listed enemies first (a few big ones get 4 or 8 more range), then the
 * objects in the other-object list; modes 0 and 2 also need a clear line of
 * sight. Returns the one with the smallest turn from dir, or 0. */
__attribute__((section(".text.cEmManage_GetTargetNear")))
cEmActor *cEmManage_GetTargetNear(cEmManage *self, cVec *pos, float dir, float range, float angle, cEmActor *skip, int mode)
{
    cVec eye;
    cVec at;
    cVec opos;
    cEmSlot *slot;
    cGameObj *em;
    cGameObj *best;
    cOmBase *o;
    void **it;
    void **end;
    int id;
    int tooHigh;
    float extra;
    float dy;
    float turn;
    float dist;

    best = 0;
    CVEC_ZERO(eye);
    CVEC_ZERO(at);
    CVEC_ASSIGN(eye, pos);
    eye.y += 1.0f;
    for (slot = self->list.top; slot != 0; slot = slot->next) {
        em = (cGameObj *)slot->em;
        if (em == 0 || em == (cGameObj *)skip)
            continue;
        if (!(cGameObj_idInRange(em, 0x200, 0x300) & 0xFF))
            continue;
        id = em->actorId;
        tooHigh = id >= 0x280;
        if (tooHigh)
            continue;
        if (mode != 2 && cGameObj_vt(em)->ckTarget((char *)em + cGameObj_vt(em)->ckTargetDelta) == 0) {
            dy = absf(pos->y - cGameObj_vt(em)->getPos((char *)em + cGameObj_vt(em)->getPosDelta)->y);
            if (dy > 1.5f)
                continue;
        }
        extra = 0.0f;
        switch (em->emNo) {
        case 0x260:
        case 0x264:
        case 0x265:
            extra = 4.0f;
            break;
        case 0x26A:
            extra = 8.0f;
            break;
        }
        dist = capVu0MagnitudeSqXZ(pos, cGameObj_vt(em)->getPos((char *)em + cGameObj_vt(em)->getPosDelta));
        if ((range + extra) * (range + extra) < dist)
            continue;
        turn = Turn_dest(&pos->x, dir, &cGameObj_vt(em)->getPos((char *)em + cGameObj_vt(em)->getPosDelta)->x, 3.1415927f);
        turn = absf(turn);
        if (angle < turn)
            continue;
        switch (em->emNo) {
        case 0x260:
        case 0x264:
        case 0x265:
        case 0x26A:
            break;
        default:
            if (mode == 0 || mode == 2) {
                CVEC_ASSIGN(at, cGameObj_vt(em)->getPos((char *)em + cGameObj_vt(em)->getPosDelta));
                at.y += 1.0f;
                if (ChkLine(&eye, &at, 0, 0, 7, 0x13C, 0, 0, 0, 0, 0, 0, 1) != 0)
                    continue;
            }
            break;
        }
        best = em;
        angle = turn;
    }
    end = D_00754C58.v->end;
    it = D_00754C58.v->begin;
    while (it != end) {
        o = *it++;
        if (o->objFlags & GAMEOBJ_OBJ_SUSPEND)
            continue;
        if (o->objFlags < 0)
            continue;
        if (!(cGameObj_idInRange((cGameObj *)o, 0x300, 0x500) & 0xFF))
            continue;
        if (func_001B79E0(o) == 0)
            continue;
        if (o == (cOmBase *)skip)
            continue;
        {
            long f0 = (unsigned int)o->flags0;
            long off = f0 >> 2 & 1;

            if (off != 0)
                continue;
        }
        CVEC_COPY(opos, cGameObj_vt((cGameObj *)o)->getPos((char *)o + cGameObj_vt((cGameObj *)o)->getPosDelta));
        dist = capVu0MagnitudeSqXZ(pos, &opos);
        {
            long f2 = (unsigned int)o->flags2;
            long big = f2 >> 10 & 1;

            if (big == 1) {
                if ((range + range) * (range + range) < dist)
                    continue;
                dy = absf(pos->y - opos.y);
                if (dy > 1.5f)
                    continue;
                turn = Turn_dest(&pos->x, dir, &opos.x, 3.1415927f);
                turn = absf(turn);
                if (angle * 1.25f < turn)
                    continue;
            } else {
                if (range * range < dist)
                    continue;
                dy = absf(pos->y - opos.y);
                if (dy > 1.0f)
                    continue;
                turn = Turn_dest(&pos->x, dir, &opos.x, 3.1415927f);
                turn = absf(turn);
                if (angle < turn)
                    continue;
            }
        }
        if (mode == 0 || mode == 2) {
            long f2 = (unsigned int)o->flags2;
            long noLine = f2 >> 7 & 1;

            if (noLine == 0) {
                at.x = opos.x;
                at.y = opos.y;
                at.z = opos.z;
                at.y += 1.0f;
                if (ChkLine(&eye, &at, 0, 0, 7, 0x13C, 0, 0, 0, 0, 0, 0, 1) != 0)
                    continue;
            }
        }
        best = (cGameObj *)o;
        angle = turn;
    }
    return (cEmActor *)best;
}
#else
INCLUDE_ASM("asm/nonmatching", cEmManage_GetTargetNear);
#endif
