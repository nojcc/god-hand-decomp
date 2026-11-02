/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"

#ifdef NON_MATCHING
/* The face a line check hit. */
typedef struct LineHitFace {
    char unk0[4];
    int flags;                          /* 0x4 */
} LineHitFace;

/* Look 0.8 ahead at waist height for a wall face with bits 0x120 set; when
 * there is one, store a point half a unit out from the hit, on the enemy's
 * floor, and the wall's facing angle, and start mode 1 phase 0x17. Returns 0
 * for the enemies that don't do this, or when there is no such wall.
 * Same length as retail (extern_jtbl D_0043D870), 13 instructions differ, all
 * in order: retail forms &pos before the vadd, and copies pos into unk6D0 as
 * x, y, z with each load after the previous store, where this copies x, z, y. */
__attribute__((section(".text.func_0024BF20")))
int func_0024BF20(cEm00 *self)
{
    cVec from;
    cVec to;
    cVec hit;
    cVec nrm;
    float m[16];
    cVec pos;
    LineHitFace *face;
    float ang;

    switch (self->emNo) {
    case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x20F: case 0x210:
    case 0x211: case 0x213: case 0x214: case 0x215: case 0x217: case 0x21C:
    case 0x21F: case 0x220: case 0x221: case 0x222: case 0x223: case 0x226:
    case 0x250: case 0x251: case 0x252: case 0x256: case 0x260: case 0x264:
    case 0x265: case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
    case 0x275: case 0x276: case 0x278: case 0x279: case 0x27E:
        return 0;
    }
    cVec_zero(&from);
    cVec_zero(&to);
    cVec_zero(&hit);
    cVec_zero(&nrm);
    from.x = 0.0f;
    from.y = 0.5f;
    from.z = 0.0f;
    to.x = 0.0f;
    to.y = 0.5f;
    to.z = -0.8f;
    cVec_applyMatrix(&from, self->mtx);
    cVec_applyMatrix(&to, self->mtx);
    if (ChkLine(&from, &to, &hit, (int)&nrm, 1, 0, &face, 1, 0, 0, 0, 0, 1) == 0 || (face->flags & 0x120) == 0) {
        return 0;
    }
    cVec_zero(&pos);
    ang = capVu0Atan2(nrm.x, nrm.z);
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = -0.5f;
    MtxInitRotY(m, ang);
    cVec_applyMatrix(&pos, m);
    CVEC_ADD_TO(pos, &hit);
    pos.y = self->pos->y;
    CVEC_ASSIGN_VEC(self->unk6D0, pos);
    self->unk6E0 = ang;
    self->mode = 1;
    self->phase = 0x17;
    self->step = 0;
    self->stepArg = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0024BF20);
#endif
