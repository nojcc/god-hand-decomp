/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/cVec.h"

extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *give);

typedef struct cOmTwin {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageTake *take;                  /* 0x600 */
    cOmBase *part[2];                   /* 0x604 */
} cOmTwin;

/* The part's position word at 0x600; the part's own record is not typed yet. */
#define PART_POS(o)  (*(cVec *)((char *)(o) + 0x600))

/* Twin-part gimmick update: a hit plays sound 0x8C or, at no hp left, starts
 * the break; phase 0 places both parts 0.17 left and right of the
 * translation, 1.483 up and 0.5 forward, turns them to this object's
 * rotation and waits for flags2 bit 0; phase 1 sets bit 0 on both parts;
 * phase 2 clears it on both once this object's bit 0 drops.
 * Still differs from retail: retail builds cVec(translation) in a third
 * temporary between the return slot and the temporary (stack 0x30/0x40/0x50);
 * CVEC_TEMPS keeps the two together, so the corner is a named local after
 * them. The part pointer is also reloaded for each copy store. */
#ifdef NON_MATCHING

__attribute__((section(".text.func_001B5B30")))
void func_001B5B30(cOmTwin *self)
{
    cVec pos;
    cVec offL;
    cVec offR;
    CVEC_TEMPS;
    cVec at;
    long v;

    if (cOmBase_checkDamage(&self->base, self->take) == 1) {
        if (self->base.hp <= 0) {
            self->base.mode = 1;
            self->base.flags0 |= COMBASE_F0_ACTIVE;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
            return;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x8C, self, 0, 0, 0, 0);
    }
    CVEC_ZERO(pos);
    switch (self->base.phase) {
    case 0:
        if (self->base.stepArg == 0) {
            CVEC_INIT_XYZ(offL, -0.17f, 1.483f, 0.0f);
            CVEC_INIT_XYZ(offR, 0.17f, 1.483f, 0.0f);
            if (self->part[0] != 0) {
                cOmBase *p;

                CVEC_INIT_XYZ(at, self->base.mtx[12], self->base.mtx[13], self->base.mtx[14]);
                CVEC_INIT_ADD(ret_, &offL, &at);
                CVEC_FROM_RET(pos);
                pos.z += 0.5f;
                p = self->part[0];
                CVCALL_FN(p, 15, void (*)(char *, cVec *))(CVCALL_THIS(p, 15), &self->base.posPrev);
                CVEC_COPY(ret_, &pos);
                CVEC_FROM_RET(PART_POS(self->part[0]));
            }
            if (self->part[1] != 0) {
                cOmBase *p;

                CVEC_INIT_XYZ(at, self->base.mtx[12], self->base.mtx[13], self->base.mtx[14]);
                CVEC_INIT_ADD(ret_, &offR, &at);
                CVEC_FROM_RET(pos);
                pos.z += 0.5f;
                p = self->part[1];
                CVCALL_FN(p, 15, void (*)(char *, cVec *))(CVCALL_THIS(p, 15), &self->base.posPrev);
                CVEC_COPY(ret_, &pos);
                CVEC_FROM_RET(PART_POS(self->part[1]));
            }
            self->base.stepArg = 1;
        }
        v = (unsigned int)self->base.flags2;
        if (v & 1) {
            self->base.phase++;
        }
        break;
    case 1:
        if (self->part[0] != 0) {
            self->part[0]->flags2 |= 1;
        }
        if (self->part[1] != 0) {
            self->part[1]->flags2 |= 1;
        }
        self->base.phase++;
    case 2:
        v = (unsigned int)self->base.flags2;
        if (!(v & 1)) {
            if (self->part[0] != 0) {
                self->part[0]->flags2 &= ~1;
            }
            if (self->part[1] != 0) {
                self->part[1]->flags2 &= ~1;
            }
            self->base.phase = 0;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001B5B30);
#endif
