/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"
#include "godhand/cCamera.h"

extern int setMotionInfo(cObjBase *self, char *motion, SEQ_DATA_HEADER_1 *seqData, unsigned int blendLen,

float step, float start, int flags);

extern unsigned int func_0031ED08(float f);
extern void func_0014E818(cObjBase *self, float maxTurn, cVec *target);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern unsigned int irand(void);
extern void func_001034E0(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);

/* Phase 2: start the stored motion and play it while turning the model toward
 * its turn target, then keep moving it by its null-part speed. */
__attribute__((section(".text.func_0014EB90")))
void func_0014EB90(cObjBase *self)
{
    switch (self->step) {
    case 0:
        setMotionInfo(self, self->motion, self->seqData, func_0031ED08(self->blendLeft),
                      self->motionRate, self->motionFrame, self->motionFlags);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->step = self->step + 1;
        }
        func_0014E818(self, self->turnRate, &self->turnTarget);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    case 2:
        moveMotion(self);
        func_0014E818(self, self->turnRate, &self->turnTarget);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}

/* Count an NPC kill, play motion pair 0x90 and sound 0x5F with the
 * collision off, then mode 2, phase 2. */
__attribute__((section(".text.func_00288A58")))
void func_00288A58(cEm00 *self)
{
    int b;

    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    self->hitFlash = 3.0f;
    switch (self->step) {
    case 0:
        func_0028FB08(self);
        cCoreSave_addKillNpcNum(&D_00569B70);
        b = EM_RES(self);
        func_002A8578(self, EM_RES_REC(b, 0x90), EM_RES_REC(b, 0x94), 5, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5F, self, 0, 0, 0, 0);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->stepArg = 0;
            self->mode = 2;
            self->step = 0;
            self->phase = 2;
        } else {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        }
        break;
    }
}

/* Start motion pair 0x28, or 0x344 / 0x3AC with step argument 3 when sub6A0 /
 * sub698 is set (sub6A0 also gets pair 0x36C), then keep it playing. */
__attribute__((section(".text.func_0011A530")))
void func_0011A530(pl00 *self)
{
    char *t0;
    int p1, p2;

    self->flags15F4 |= 0x80;
    switch (self->base.step) {
    case 0:
        t0 = self->base.pack;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        p1 = EM_RES_REC(t0, 0x28);
        p2 = EM_RES_REC(t0, 0x2C);
        if (self->sub6A0 != 0) {
            func_002A8578(self->sub6A0, EM_RES_REC(t0, 0x36C),
                          EM_RES_REC(t0, 0x388), 10, 0.0f, 0, 0);
            p1 = EM_RES_REC(self->base.pack, 0x344);
            p2 = EM_RES_REC(self->base.pack, 0x348);
            self->base.stepArg = 3;
        }
        if (self->sub698 != 0) {
            p1 = EM_RES_REC(self->base.pack, 0x3AC);
            p2 = EM_RES_REC(self->base.pack, 0x3B0);
            self->base.stepArg = 3;
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    case 1:
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}

/* Play the motion pair the step argument picks (0 to 3), then go back to
 * mode 0, phase 0. */
__attribute__((section(".text.func_00102CB0")))
void func_00102CB0(cGameObj *self)
{
    int p1, p2, sel;

    sel = 0;
    switch (self->step) {
    case 0:
        switch (self->stepArg) {
        case 0:
        default:
            p1 = EM_RES_REC(self->pack, 0x6C);
            p2 = EM_RES_REC(self->pack, 0x70);
            sel = (irand() & 1) << 1;
            break;
        case 1:
            p1 = EM_RES_REC(self->pack, 0x64);
            p2 = EM_RES_REC(self->pack, 0x68);
            break;
        case 2:
            p1 = EM_RES_REC(self->pack, 0x5C);
            p2 = EM_RES_REC(self->pack, 0x60);
            break;
        case 3:
            sel = 2;
            p1 = EM_RES_REC(self->pack, 0x5C);
            p2 = EM_RES_REC(self->pack, 0x60);
            break;
        }
        func_002A8578(self, p1, p2, 5, 0.0f, sel, 0);
        self->step = self->step + 1;
    case 1:
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}

/* Loop a motion; while the player's unk61F is set, turn by (unk608 - pi/6) * 0.4,
 * clamped to 0..2.4 degrees a frame and negated when the player's unk604 is
 * negative. */
__attribute__((section(".text.func_00102938")))
void func_00102938(cGameObj *self)
{
    pl00 *pl;
    int b;
    float f;

    pl = (pl00 *)Getplayer();
    switch (self->step) {
    case 0:
        b = EM_RES(self);
        func_002A8578(self, EM_RES_REC(b, 0x14), EM_RES_REC(b, 0x18), 10, 0.0f, 0, 0);
        self->step = self->step + 1;
    case 1:
        if (pl->unk61F != 0) {
            f = pl->unk608 - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.4f;
            if (0.041887902f < f) {
                f = 0.041887902f;
            }
            if (pl->unk604 < 0.0f) {
                f = -f;
            }
            self->rot.y = self->rot.y + f;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    func_001034E0(self);
}

/* Clear the children's states and play motion pair 0x3D94 for 30 frames of
 * emFlags 0x800000, then phase 0xA1. */
__attribute__((section(".text.func_0024AA68")))
void func_0024AA68(cEm00 *self)
{
    int b;
    int gb;
    float f;

    self->emFlags = self->emFlags | 0x30400;
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        b = EM_RES(self);
        func_002A8578(self, EM_RES_REC(b, 0x3D94), EM_RES_REC(b, 0x3D98), 10, 0.0f, gb, 0);
        if (self->sub0 != 0) {
            Obj2810_ClearState_5(self->sub0);
        }
        if (self->sub1 != 0) {
            ClearBytes2F4To2F7_283170(self->sub1);
        }
        if (self->sub2 != 0) {
            ClearBytes2F4To2F7_283170(self->sub2);
        }
        self->timer = 30.0f;
        self->step = self->step + 1;
    case 1:
        f = self->timer;
        if (0.0f < f) {
            self->emFlags = self->emFlags | 0x800000;
            self->timer = f - self->speedRate;
        }
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0xA1;
            self->step = 0;
            self->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
