/* sn-2.95.3-136 */
/* NON_MATCHING func_0025D0B8 (extern_jtbl D_00443A20; 368 words, 8 differ):
 * in both stepVec = home * speedRate copies retail loads z from the return
 * slot after storing x and y (it treats the stores as possibly aliasing the
 * slot); here all three loads come first. */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/cVec.h"
#include "godhand/motion.h"
#include "godhand/rand.h"

unsigned int func_00271EB0(cEm00 *self);

/* *dp = *sp; (operator=, xyz only, with this and the argument both bound
 * as pointers; pending for cVec.h) */
#define CVEC_ASSIGN_P(dp, sp)                                   \
    {                                                           \
        cVec *d_ = (dp);                                        \
        cVec *s_ = (sp);                                        \
                                                                \
        if (d_ != s_) {                                         \
            d_->x = s_->x;                                      \
            d_->y = s_->y;                                      \
            d_->z = s_->z;                                      \
        }                                                       \
    }

/* The enemy's charge: steps 0-1 start the charge motion, sounds and trails
 * and run along home (scaled by the speed rate) until the charge hits or the
 * motion ends; steps 2-3 play the stop motion, slowing down, then pick the
 * next state; steps 4-5 keep charging for up to 60 frames. Steps 4 and up
 * need emFlags bit 0x4000000, and step 2 skips to 4 without it. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_0025D0B8")))
void func_0025D0B8(cEm00 *self)
{
    CVEC_TEMPS;
    unsigned short sel;
    unsigned int hit;

    self->emFlags |= 0x1000;
    if (self->step == 2 && !(self->emFlags & 0x4000000))
        self->step = 4;
    if (self->step >= 4 && (self->emFlags & 0x4000000))
        self->step = 2;
    switch (self->step) {
    case 0:
        self->unk1710 = 0;
        self->home.x = 0.0f;
        self->home.y = 0.0f;
        self->home.z = 0.5f;
        self->home.w = 1.0f;
        if (func_002740D8((char *)self) != 0) {
            if (irand() & 1)
                self->unk17C3 = 1;
            else
                self->unk17C3 = 0;
        }
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x14D8), EM_RES_REC(self->resource, 0x14DC),
                      2, 0.0f, sel, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0xC), self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2B, self, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2E, self, 0, 0, 0, 0);
        InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)4, 0, 2, 0);
        InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)8, 0, 2, 0);
        self->step++;
        /* fall through */
    case 1:
        self->unk434 |= 8;
        if (moveMotion(self) != 0) {
            self->step = 2;
            if (cEm00_startHitUnitAim(self) != 0) {
                self->mode = 1;
                self->phase = 4;
                self->step = 4;
                self->stepArg = 1;
                break;
            }
        }
        CVEC_SET_MUL(self->stepVec, &self->home, self->speedRate);
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        self->hitFlash = 15.0f;
        func_00262750(self, 0);
        func_00271EB0(self);
        break;
    case 2:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x14E0), EM_RES_REC(self->resource, 0x14E4),
                      5, 0.0f, sel, 0);
        self->step++;
        /* fall through */
    case 3:
        if (moveMotion(self) != 0) {
            if (self->vital <= 0) {
                if (self->emFlags2 & 0x100000)
                    cEm00_setState(self, 2, 2, 0);
                else if (self->flags1644 & 0x800000)
                    cEm00_setState(self, 2, 3, 0);
                else if (func_0025FE30(self, 0x1000000, 0) != 0)
                    cEm00_setState(self, 2, 2, 0);
                else
                    cEm00_setState(self, 2, 1, 0);
            } else if (cEm00_startHitUnitAim(self) == 0) {
                func_00274FE8(self);
            }
            break;
        }
        self->home.z *= 0.92f;
        CVEC_ASSIGN_P(&self->stepVec, &self->home);
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if ((self->moveFlags & 0x10) && self->vital <= 0) {
            if (self->flags1644 & 0x800000)
                cEm00_setState(self, 2, 3, 0);
            else if (func_0025FE30(self, 0x1000000, 0) != 0)
                cEm00_setState(self, 2, 2, 0);
            else
                cEm00_setState(self, 2, 1, 0);
        }
        break;
    case 4:
        self->timer = 0.0f;
        self->step++;
        /* fall through */
    case 5:
        self->unk434 |= 8;
        moveMotion(self);
        CVEC_SET_MUL(self->stepVec, &self->home, self->speedRate);
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        if (self->stepArg == 0) {
            self->hitFlash = 15.0f;
            func_00262750(self, 0);
        }
        hit = func_00271EB0(self);
        if (hit != 0) {
            if (hit < 3)
                break;
        }
        self->timer += self->speedRate;
        if (60.0f < self->timer)
            cEm00_setState(self, 2, 2, 1);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0025D0B8);
#endif
