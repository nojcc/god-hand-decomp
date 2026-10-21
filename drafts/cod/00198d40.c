/* sn-2.95.3-136 */
/* NON_MATCHING: needs --fp-hazard-rules fdiv; retail tests the variant as ==1, <2, ==2 (this switch gives ==1, ==2), keeps self in $s0 rather than $s1, and loads the half-extents y, z, x; 104 instructions differ. The record pointer at 0x5E0 needs a cOmHitVolume field. */
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
/* The record an object is placed from; its variant picks the box size. */
typedef struct cOmPlaceRec {
    char unk00[0x2C];
    unsigned char variant;              /* 0x2C */
} cOmPlaceRec;

#define OMHITVOLUME_REC(self)   (*(cOmPlaceRec **)(self)->unk5E0)

/* The stack vectors: the box size, the default size it is measured against,
 * the box half-extents, its offset, and a scratch vector. */
typedef struct cOmBoxFrame {
    cVec size;
    cVec base;
    cVec half;
    cVec ofs;
    cVec v;
} cOmBoxFrame;


#define OMBOX_FRAME_OFFSET(field) ((int)&((cOmBoxFrame *)0)->field)
#define OMHITVOLUME_SCALE(self) ((cVec *)((char *)(self) + 0x110))

extern void func_001BFB28(cOmHitVolume *self);

/* Set up the damage-take box from the variant's size and scale the model from
 * its 2.0 x 1.2 x 0.2 default to match. */
__attribute__((section(".text.func_00198D40")))
int func_00198D40(cOmHitVolume *self)
{
    cOmBoxFrame f;
    void *unit;

    func_001B6FB8(self);
    cVec_set4(&f.size, 2.0f, 1.2f, 0.2f, 1.0f);
    VU0_LQC2(4, &f, OMBOX_FRAME_OFFSET(size));
    VU0_SQC2(4, &f, OMBOX_FRAME_OFFSET(base));
    if (OMHITVOLUME_REC(self) != 0) {
        switch (OMHITVOLUME_REC(self)->variant) {
        case 1:
            f.size.x = 1.0f;
            f.size.y = 1.4f;
            f.size.z = 0.2f;
            break;
        case 2:
            f.size.z = 0.2f;
            f.size.y = 0.9f;
            f.size.x = 0.9f;
            break;
        }
    }
    cVec_set4(&f.half, f.base.x, f.base.y, f.base.z, 1.0f);
    cVec_set4(&f.ofs, 0.0f, f.base.y * -0.5f, 0.0f, 1.0f);
    unit = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    self->damageTake = unit;
    if (unit != 0) {
        cVec_set4(&f.v, 0.0f, 0.0f, 0.0f, 1.0f);
        func_001FD9D8(unit, self->base.mtx, &f.ofs, &f.v, &f.half);
    }
    self->base.hp = 1;
    self->base.hpMax = 1;
    VU0_SQC2_VF0(&f.v, 0);
    f.v.x = f.size.x / f.base.x;
    f.v.y = f.size.y / f.base.y;
    f.v.z = f.size.z / f.base.z;
    f.v.w = 1.0f;
    cVec_copy3(OMHITVOLUME_SCALE(self), &f.v);
    func_001BFB28(self);
    return 1;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_00198D40);
#endif
