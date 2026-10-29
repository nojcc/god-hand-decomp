/* NON_MATCHING func_0012AFE8 (sn-2.95.3-136, fp_hazard_rules "fdiv"): 6 instructions differ. Retail computes the address of the temporary at 0x50 into $s0 at the start of the block, ahead of the zero-and-subtract; ours computes it right before the copy that reads it. With a helper that takes the temporary as a parameter, the address moves up but the subtract then stores through 0($s0) instead of 0x50($sp). pl00ThrowView stands in for pl00 until pl00.h names the locked-on target at 0x640. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cSnd.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

/* View of pl00 with the locked-on target that pl00.h does not name yet. */
typedef struct pl00ThrowView {
    cGameObj base;
    char unk5AC[0x640 - 0x5AC];
    cGameObj *lockOn;                   /* 0x640 */
} pl00ThrowView;

typedef struct pl00ThrowFrame {
    int childNum;
    char unk04[0xC];
    cVec dir;                           /* 0x10 */
    cVec from;                          /* 0x20 */
    cVec to;                            /* 0x30 */
    cVec ret;                           /* 0x40 */
    cVec tmp;                           /* 0x50 */
} pl00ThrowFrame;

extern void capVu0ApplyMatrixXYZ(void *a0, void *a1, void *a2);
extern void cOmWeapon_setThrowPL(cOmWeapon *self, cVec *v);

/* Throws the held weapon from its grip: at the locked-on target when there is one
 * (its first part, or its position raised to chest height), else straight ahead. */
__attribute__((section(".text.func_0012AFE8")))
void func_0012AFE8(pl00ThrowView *self, cOmWeapon *weapon)
{
    pl00ThrowFrame f;
    cOmBase *grip;
    cOmBase *part;
    cVec *p;

    if (weapon == 0) {
        return;
    }
    grip = cOmBase_childAt((cOmBase *)weapon, &f.childNum, 0);
    if (grip == 0) {
        return;
    }
    cVec_zero(&f.dir);
    cVec_zero(&f.from);
    cVec_copy3(&f.from, grip->pos);
    if (self->lockOn != 0) {
        cVec_zero(&f.to);
        part = cOmBase_childAt((cOmBase *)self->lockOn, &f.childNum, 0);
        if (part != 0) {
            cVec_copy3(&f.to, part->pos);
            f.to.y += 0.5f;
        } else {
            p = cGameObj_vt(self->lockOn)->getPos((char *)self->lockOn + cGameObj_vt(self->lockOn)->getPosDelta);
            f.to.x = p->x;
            f.to.y = p->y;
            f.to.z = p->z;
            f.to.y += 1.6f;
        }
        VU0_ZERO_VSUB_XYZ_TO(&f.tmp, 0, &f.to, &f.from);
        VU0_LQC2_SQC2_MEM(4, &f.ret, &f.tmp);
        cVec_copy3(&f.dir, &f.ret);
        cVec_unitOf(&f.tmp, &f.dir);
        VU0_LQC2_SQC2_MEM(4, &f.ret, &f.tmp);
        cVec_copy3(&f.dir, &f.ret);
        VU0_VSCALE_XYZ_MEM(&f.dir, 0, 0.7f);
    } else {
        f.dir.x = 0.0f;
        f.dir.y = 0.0f;
        f.dir.z = 0.7f;
        capVu0ApplyMatrixXYZ(&f.dir, self->base.mtx, &f.dir);
    }
    cVec_copy3(weapon->base.pos, &f.from);
    cVec_copy3(&weapon->base.posA, &f.from);
    cOmWeapon_setThrowPL(weapon, &f.dir);
    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12E, self, 0, 0, 0, 0);
    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x104, self, 0, 0, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012AFE8);
#endif
