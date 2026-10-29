/* NON_MATCHING func_0012B618 (sn-2.95.3-136): the frame size, the four saved registers and every stack offset match retail. Retail keeps self in $s0 and the vector addresses in $s1..$s3; ours numbers them differently. Ours also addresses the subtraction and unit temporaries through a register, where retail addresses them off $sp. Retail's shape is a by-value vector return, a result pointer that lives in a saved register with the temporary on the stack, which plain C does not express directly. pl00ThrowView stands in for pl00 until pl00.h names the locked-on target at 0x640. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

/* View of pl00 with the locked-on target that pl00.h does not name yet. */
typedef struct pl00ThrowView {
    cGameObj base;
    char unk5B0[0x640 - 0x5B0];
    cGameObj *lockOn;                   /* 0x640 */
    char unk644[0x6A0 - 0x644];
    cGameObj *sub6A0;                   /* 0x6A0 */
} pl00ThrowView;

/* Stack record of func_0012B618; the child count and the copied unit vector share 0x30. */
typedef struct pl00ThrowFrame {
    cVec dir;                           /* 0x00 */
    cVec from;                          /* 0x10 */
    cVec aim;                           /* 0x20 */
    union {
        int childNum;
        cVec unit;
    } u;                                /* 0x30 */
    cVec unit;                          /* 0x40 */
    cVec diff;                          /* 0x50 */
} pl00ThrowFrame;

/* Position of the locked-on target, through its method table. */
#define LOCKON_POS(self) \
    ((cVec *(*)(void *))cGameObj_vt((self)->lockOn)->getPos)((char *)(self)->lockOn + cGameObj_vt((self)->lockOn)->getPosDelta)

/* *ret = a - b (x, y, z; w zero), built in tmp; returns ret. */
static __inline__ cVec *cVec_subTo(cVec *ret, cVec *a, cVec *b, cVec *tmp)
{
    VU0_ZERO_VSUB_XYZ_MEM(tmp, 0, a, b);
    VU0_LQC2_SQC2_MEM(4, ret, tmp);
    return ret;
}

/* *ret = v scaled to length 1, built in tmp; returns ret. */
static __inline__ cVec *cVec_unitTo(cVec *ret, cVec *v, cVec *tmp)
{
    cVec_unitOf(tmp, v);
    VU0_LQC2_SQC2_MEM(4, ret, tmp);
    return ret;
}

extern void capVu0ApplyMatrixXYZ(void *a0, void *a1, void *a2);
extern void cOmThrow_SetThrow(unsigned char *p, float *v);

/* Throws the held object: toward the locked-on target when there is one, else straight ahead. */
__attribute__((section(".text.func_0012B618")))
void func_0012B618(pl00ThrowView *self)
{
    pl00ThrowFrame f;
    cVec *p;

    if (self->sub6A0 == 0) {
        return;
    }
    cVec_zero(&f.dir);
    cVec_zero(&f.from);
    cVec_copy3(&f.from, self->sub6A0->pos);
    f.from.y += 1.6f;
    if (self->lockOn != 0) {
        cVec_zero(&f.aim);
        if (!(cGameObj_idInRange(self->lockOn, 0x200, 0x300) & 0xFF)) {
            p = LOCKON_POS(self);
            f.aim.x = p->x;
            f.aim.y = p->y;
            f.aim.z = p->z;
            f.aim.y += 1.0f;
        } else {
            cOmBase *body = cOmBase_childAt((cOmBase *)self->lockOn, &f.u.childNum, 0);

            if (body != 0) {
                cVec_copy3(&f.aim, body->pos);
                f.aim.y += 0.5f;
            } else {
                p = LOCKON_POS(self);
                f.aim.x = p->x;
                f.aim.y = p->y;
                f.aim.z = p->z;
                f.aim.y += 1.6f;
            }
        }
        cVec_copy3(&f.dir, cVec_subTo(&f.unit, &f.aim, &f.from, &f.diff));
        cVec_copy3(&f.dir, cVec_unitTo(&f.u.unit, &f.dir, &f.unit));
        VU0_VSCALE_XYZ_MEM(&f.dir, 0, 0.7f);
    } else {
        f.dir.x = 0.0f;
        f.dir.y = 0.01f;
        f.dir.z = 0.7f;
        capVu0ApplyMatrixXYZ(&f.dir, self->base.mtx, &f.dir);
    }
    cOmThrow_SetThrow((unsigned char *)self->sub6A0, (float *)&f.dir);
    cVec_copy3(self->sub6A0->pos, &f.from);
    cVec_copy3(&self->sub6A0->posA, &f.from);
    self->sub6A0 = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012B618);
#endif
