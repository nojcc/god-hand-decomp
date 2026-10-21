/* sn-2.95.3-136. Differs from retail: retail computes the address of the subtraction work vector (sp+0x30) before the VU0 block and addresses it from sp; ours folds it into the temporary's address (16 off a0) and computes sp+0x30 after the subtraction, so nine instructions in the vector block differ. */
#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cOmSub.h"
#include "godhand/cSnd.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

/* A map object that slides once along its cOmSub path. */
typedef struct cOmSlider {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cOmSub move;                        /* 0x600 */
    char unk740[0x24];
    unsigned char done;                 /* 0x764 1 once the slide has finished */
    unsigned char moving;               /* 0x765 1 while it slides */
} cOmSlider;

typedef struct cOmSliderFrame {
    cVec target;                        /* 0x00 */
    cVec ofs;                           /* 0x10 */
} cOmSliderFrame;

/* *d.xyz = a.xyz - b.xyz through two vector temporaries. */
static __inline__ void cVec_assignSub(cVec *d, cVec *a, cVec *b)
{
    cVec tmp, r;

    VU0_ZERO_VSUB_XYZ_MEM(&r, 0, a, b);
    VU0_LQC2(4, &r, 0);
    VU0_SQC2(4, &tmp, 0);
    cVec_copy3(d, &tmp);
}

extern cSnd D_005FEE00;
extern int cSnd_SeCall_2CBA48(cSnd *self, int slot, int id, void *obj, int a4, int a5, int a6, int a7);
extern void cOmSub_initMove1_pos(cOmSub *mv, void *obj, int ent, int frames, cVec *pos, float f12, float f13);
extern int cOmSub_move(cOmSub *mv);

/* Slides the object 0.7 along its local -x axis once, with a sound, then marks it done. */
__attribute__((section(".text.func_0017F6C0")))
void func_0017F6C0(cOmSlider *self)
{
    cOmSliderFrame f;

    switch (self->base.phase) {
    case 0:
        if (self->done == 1)
            return;
        VU0_SQC2_VF0(&f, 0);
        cVec_set4(&f.ofs, -0.7f, 0.0f, 0.0f, 1.0f);
        cVec_applyMatrix(&f.ofs, self->base.mtx);
        cVec_assignSub(&f.target, self->base.pos, &f.ofs);
        cOmSub_initMove1_pos(&self->move, self, -1, 10, &f.target, 0.1f, 0.1f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x6B, self, 0, 0, 0, 0);
        self->moving = 1;
        self->base.phase = 1;
        self->base.step = 0;
        self->base.stepArg = 0;
    case 1:
        if (cOmSub_move(&self->move) == 0) {
            self->done = 1;
            self->moving = 0;
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_0017F6C0);
#endif
