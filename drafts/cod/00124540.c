/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING func_00124540: 441 vs 443 words. Retail shares one exit
 * (unk648 = 20, return 1) between the check before the switch and every
 * search that finds an enemy; this form tests unk640 again after the switch.
 * With a goto to that exit the function is 6 instructions off: retail builds
 * &D_005864F0 through v1 instead of v0 at the start of cases 0, 1 and 3. */
#include "godhand/cEmManage.h"
#include "godhand/cVec.h"
#include "godhand/pl00.h"

void func_00124C30(char *s1, int flag);

#ifdef NON_MATCHING
/* Picks the enemy the player catches (unk640): kind selects the list of
 * ranges and angles tried in order; returns 1 and sets unk648 when one is
 * found. */
__attribute__((section(".text.func_00124540")))
int func_00124540(pl00 *self, int kind)
{
    cVec at;

    if (kind != 2) {
        func_00124C30((char *)self, 1);
        if (self->unk640 != 0) {
            self->unk648 = 20;
            return 1;
        }
    }
    switch (kind) {
    case 0:
    default:
        if (self->unk5D8 != 4) {
            CVEC_COPY(at, self->base.pos);
            self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 2.0f, 1.5707964f, 0, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 4.0f, 0.5235988f, 0, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 6.0f, 0.5235988f, 0, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 4.0f, 2.3561945f, 0, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 3.0f, 1.0471976f, 0, 0);
        } else {
            CVEC_COPY(at, self->base.pos);
            self->unk640 = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 2.0f, 0.5235988f, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 4.0f, 0.5235988f, 0, 0);
            if (self->unk640 != 0)
                break;
            CVEC_COPY(at, self->base.pos);
            self->unk640 = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 4.0f, 3.1415927f, 0, 0);
        }
        break;
    case 1:
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 8.0f, 0.7853982f, 0, 0, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 3.0f, 1.5707964f, 0, 0, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 3.0f, 1.5707964f, 0, 0);
        break;
    case 2: {
        cGameObj *nearest;
        cGameObj *other;

        CVEC_COPY(at, self->base.pos);
        nearest = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 4.0f, 0.5235988f, 0, 0);
        self->unk640 = nearest;
        CVEC_COPY(at, self->base.pos);
        other = cEmManage_GetTargetNear(&D_005864F0, &at, self->base.rot.y, 5.5f, 3.1415927f, nearest, 0);
        if (other != 0)
            self->unk640 = other;
        break;
    }
    case 3:
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 2.0f, 0.7853982f, 0, 0, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 4.0f, 3.1415927f, 0, 0, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 30.0f, 3.1415927f, 0, 0, 1);
        break;
    case 4:
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 3.0f, 0.7853982f, 0, 2, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 6.0f, 0.7853982f, 0, 2, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 9.0f, 0.7853982f, 0, 2, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 12.0f, 0.7853982f, 0, 2, 1);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 20.0f, 0.5235988f, 0, 2, 1);
        break;
    case 5:
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 2.0f, 0.5235988f, 0, 0, 0);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 4.0f, 0.5235988f, 0, 0, 0);
        if (self->unk640 != 0)
            break;
        CVEC_COPY(at, self->base.pos);
        self->unk640 = func_00291010(&D_005864F0, &at, self->base.rot.y, 4.0f, 2.3561945f, 0, 0, 0);
        break;
    }
    if (self->unk640 == 0)
        return 0;
    self->unk648 = 20;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00124540);
#endif
