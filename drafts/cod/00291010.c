/* sn-2.95.3-136 */
/* NON_MATCHING func_00291010: 503 vs 505 words. The control flow and the
 * stack frame layout match; the differences are register choice. Retail moves
 * more invariants out of the enemy loop (flag & 1, the kind 3/4 test, the 1.0
 * and 0.0 constants, and 2, 0x260 and 0x26A for the compares), spills two of
 * them, and so folds the alias test of the dir subtraction. Retail never sets
 * the heading difference on the kind 3 and 4 paths and keeps a stale value;
 * the draft starts it at 0. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/angle.h"
#include "godhand/capVu0.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cEmManage.h"
#include "godhand/cEmWrap.h"
#include "godhand/cGameObj.h"
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"
#include "godhand/cVec.h"
#include "godhand/ptrVec.h"

extern long func_001B79E0(cOmBase *self);

#define EM_VCALL(em, fn) ((em)->vt->fn((char *)(em) + (em)->vt->fn##Delta))
#define OBJ_GETPOS(obj) CVCALL_FN(obj, 13, cVec *(*)(void *))(CVCALL_THIS(obj, 13))

/* The best target near pos: first the enemies of the manager, then the objects
 * that can be picked up. kind 2 also checks the pitch, kinds 3 and 4 skip the
 * heading test, and kinds 0 and 2 need a clear line from pos. */
__attribute__((section(".text.func_00291010")))
cGameObj *func_00291010(cEmManage *self, cVec *pos, cGameObj *skip, int kind, int flag,
                        float rotY, float range, float angle)
{
    cVec from;
    cVec to;
    cVec dir;
    float nearest = 1.0e16f;            /* never lowered: kinds 3 and 4 take the last target in range */
    cGameObj *found = 0;
    cEmSlot *slot;
    void **it;
    void **end;
    float dist;
    float dy;
    float turn = 0.0f;

    CVEC_ZERO(from);
    CVEC_ZERO(to);
    CVEC_ZERO(dir);
    cVec_copy3(&from, pos);
    from.y += 1.0f;

    for (slot = self->list.top; slot != 0; slot = slot->next) {
        cEmActor *em = slot->em;
        float extra;
        int id;
        long boss;

        if (em == 0 || em == (cEmActor *)skip) {
            continue;
        }
        if (!(cGameObj_idInRange((cGameObj *)em, 0x200, 0x300) & 0xFF)) {
            continue;
        }
        id = em->actorId;
        boss = id >= 0x280;
        if (boss) {
            continue;
        }
        if (em->unk617 != 0) {
            continue;
        }
        if (em->vital <= 0 && (flag & 1)) {
            continue;
        }
        if (EM_VCALL(em, unkE4) == 0) {
            continue;
        }
        if (kind == 2) {
            dy = pos->y - EM_VCALL(em, getPos)->y;
            if (dy < 0.0f) {
                dy = -dy;
            }
            if (dy > 3.5f) {
                continue;
            }
            if (dy > 1.0f) {
                CVEC_SET_SUB(dir, EM_VCALL(em, getPos), pos);
                turn = -capVu0Atan2(dir.y, __builtin_sqrtf(dir.x * dir.x + dir.z * dir.z));
                if (turn < 0.0f) {
                    turn = -turn;
                }
                if (turn > 0.2617994f) {
                    continue;
                }
            }
        } else if (EM_VCALL(em, ckTarget) == 0) {
            dy = pos->y - EM_VCALL(em, getPos)->y;
            if (dy < 0.0f) {
                dy = -dy;
            }
            if (dy > 1.5f) {
                continue;
            }
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
        dist = capVu0MagnitudeSqXZ(pos, EM_VCALL(em, getPos));
        if (dist > (range + extra) * (range + extra)) {
            continue;
        }
        if (kind == 3 || kind == 4) {
            if (dist > nearest) {
                continue;
            }
        } else {
            turn = Turn_dest(&pos->x, &EM_VCALL(em, getPos)->x, rotY, 3.14159274f);
            if (turn < 0.0f) {
                turn = -turn;
            }
            if (turn > angle) {
                continue;
            }
        }
        if (kind == 4 && EM_VCALL(em, getPos)->x > 0.0f) {
            continue;
        }
        switch (em->emNo) {
        case 0x260:
        case 0x264:
        case 0x265:
        case 0x26A:
            break;
        default:
            if (kind == 0 || kind == 2) {
                cVec_copy3(&to, EM_VCALL(em, getPos));
                to.y += 1.0f;
                if (ChkLine(&from, &to, 0, 0, 7, 0x13C, 0, 0, 0, 0, 0, 0, 1) != 0) {
                    continue;
                }
            }
            break;
        }
        found = (cGameObj *)em;
        angle = turn;
    }

    it = D_00754C58.v->begin;
    end = D_00754C58.v->end;
    while (it != end) {
        cOmBase *obj = *it++;
        cVec at;
        long v;

        if (obj->objFlags & GAMEOBJ_OBJ_SUSPEND) {
            continue;
        }
        if (obj->objFlags < 0) {
            continue;
        }
        if (!(cGameObj_idInRange((cGameObj *)obj, 0x300, 0x500) & 0xFF)) {
            continue;
        }
        if (func_001B79E0(obj) == 0) {
            continue;
        }
        if (obj == (cOmBase *)skip) {
            continue;
        }
        v = (unsigned int)obj->flags0;
        if (v >> 2 & 1) {
            continue;
        }
        v = (unsigned int)obj->flags2;
        if ((v >> 12 & 1) == 0) {
            continue;
        }
        CVEC_COPY(at, OBJ_GETPOS(obj));
        dist = capVu0MagnitudeSqXZ(pos, &at);
        if (kind == 3) {
            if (dist > nearest) {
                continue;
            }
        } else {
            long big;

            v = (unsigned int)obj->flags2;
            big = v >> 10 & 1;
            if (big == 1) {
                if (dist > (range + range) * (range + range)) {
                    continue;
                }
                dy = pos->y - at.y;
                if (dy < 0.0f) {
                    dy = -dy;
                }
                if (dy > 1.5f) {
                    continue;
                }
                turn = Turn_dest(&pos->x, &at.x, rotY, 3.14159274f);
                if (turn < 0.0f) {
                    turn = -turn;
                }
                if (turn > angle * 1.25f) {
                    continue;
                }
            } else {
                if (dist > range * range) {
                    continue;
                }
                dy = pos->y - at.y;
                if (dy < 0.0f) {
                    dy = -dy;
                }
                if (dy > 1.0f) {
                    continue;
                }
                turn = Turn_dest(&pos->x, &at.x, rotY, 3.14159274f);
                if (turn < 0.0f) {
                    turn = -turn;
                }
                if (turn > angle) {
                    continue;
                }
            }
        }
        if (kind == 0 || kind == 2) {
            v = (unsigned int)obj->flags2;
            if ((v >> 7 & 1) == 0) {
                to.x = at.x;
                to.y = at.y + 1.0f;
                to.z = at.z;
                if (ChkLine(&from, &to, 0, 0, 7, 0x13C, 0, 0, 0, 0, 0, 0, 1) != 0) {
                    continue;
                }
            }
        }
        found = (cGameObj *)obj;
        angle = turn;
    }
    return found;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00291010);
#endif
