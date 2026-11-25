/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern float SetMotionStep(void *a0, float f12);
#include "godhand/motion.h"
#include "godhand/cEm00.h"
#include "godhand/pl00Fn.h"
#include "godhand/cModel.h"
extern float Adjust_theta(float f12);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cEm00_startJumpSetup(void *a0);

extern float Turn_dest_dir(float f12, float f13, float f14);
extern void Add_nullspeedDir(void *a0, float f12);
__attribute__((section(".text.func_0010C300")))
void func_0010C300(pl00 *self)
{
    int t0;
    int v0;
    void *q;
    int p1;
    int p2;
    float v;
    float sp;
    if (self->base.hp <= 0) {
        self->base.hp = 1;
    }
    if (self->unk5F2 == 3) {
        self->base.speedRate = 1.6f;
        SetMotionStep(self, 1.6f);
    } else {
        self->base.speedRate = 1.3f;
        SetMotionStep(self, 1.3f);
    }
    switch (self->base.step) {
    case 0:
        self->comboSlot = 0;
        self->comboSet = 0;
        if ((signed char)self->unk648 >= 0xB) {
            self->unk648 = 0xA;
        }
        t0 = EM_RES(&self->base);
        q = self->sub6A0;
        p1 = EM_RES_REC(t0, 0x58);
        p2 = EM_RES_REC(t0, 0x5C);
        if (q != 0) {
            func_002A8578(q, EM_RES_REC(t0, 0x370), EM_RES_REC(t0, 0x38C),
                          0xA, 0.0f, 0, 0);
            v0 = EM_RES(&self->base);
            p1 = EM_RES_REC(v0, 0x34C);
            p2 = EM_RES_REC(v0, 0x350);
        }
        func_002A8578(self, p1, p2, 0xA, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
    case 1:
        self->unk15F0 = D_003BD480;
        if (self->unk5D8 != 4) {
            if (self->unk61F != 0) {
                v = self->unk608 - 0.52359879f;
                if (v < 0.0f) {
                    v = 0.0f;
                }
                v = v * 0.400000006f;
                if (D_003BD478 < v) {
                    v = D_003BD478;
                }
                if (self->unk604 < 0.0f) {
                    v = -v;
                }
                self->base.rot.y = self->base.rot.y + v;
                self->base.rot.y = Adjust_theta(self->base.rot.y);
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
        } else {
            v = Turn_dest_dir(self->base.rot.y, self->unk15FC, 0.39269909f);
            self->base.rot.y = self->base.rot.y + v;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
            moveMotion(self);
            cModel_calcNullPart((cModel *)self);
            Add_nullspeedDir(self, self->unk15FC);
        }
        break;
    }
    if (self->unk61F != 0) {
        if (self->unk60C < 10000.0f) {
            self->unk1601 = 2;
        }
    }
    if (func_00123938(self, 0) == 0) {
        cEm00_startJumpSetup(self);
    }
}
