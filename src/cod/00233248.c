/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
#include "godhand/cOmWeapon.h"
#include "godhand/player.h"
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern float Adjust_theta(float f12);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */





















__attribute__((section(".text.func_00233248")))
void func_00233248(cEm00 *self)
{
    float fv = 0.0f;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
    case 0: {
        int gb;
        int a1v, a2v;
        int st;

        self->unk1864 = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        self->timerB = 0;
        self->timerC = 0;
        self->timerA = 0xF;
        self->timer3 = 1.0f;
        StoreMotionParamsBoth_2609A8(self, 0x14, 0, 0x37, -1, 0);
        st = self->emNo;
        self->timer2 = fv;
        self->unk60C = fv;
        if (st >= 0x250) {
            if (st < 0x252) goto lb;
            if (st == 0x260) goto lc;
        }
        {
            char *pa;
            StoreMotionParamsBoth_2609A8(self, 0x14, 3, 0x37, -1, 0);
            pa = self->pack;
            a1v = *(int *)(pa + 0x390) + (int)pa;
            a2v = *(int *)(pa + 0x394) + (int)pa;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = self->pack;
            a2v = *(int *)(v1 + 0x398) + (int)v1;
        }
        fv = 2.0f;
        goto lmerge;
    lb:
        {
            char *pb;
            StoreMotionParamsBoth_2609A8(self, 0x1E, 0x1B, 0x45, -1, 0);
            pb = self->pack;
            a1v = *(int *)(pb + 0x19E8) + (int)pb;
            a2v = *(int *)(pb + 0x19EC) + (int)pb;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = self->pack;
            a2v = *(int *)(v1 + 0x19F0) + (int)v1;
        }
        self->timer2 = 20.0f;
        fv = 3.0f;
        goto lmerge;
    lc:
        {
            char *pc;
            StoreMotionParamsBoth_2609A8(self, 0x46, 0x1B, 0x45, -1, 0);
            pc = self->pack;
            a1v = *(int *)(pc + 0x30D8) + (int)pc;
            a2v = *(int *)(pc + 0x30DC) + (int)pc;
        }
        self->timer2 = 20.0f;
        fv = 3.0f;
    lmerge:
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: self->timerA = (int)((float)self->timerA * 0.75f); break;
        case 2: self->timerA = (int)((float)self->timerA * 0.8f); break;
        case 3: case 4: self->timerA = (int)((float)self->timerA * 0.9f); break;
        case 5: break;
        }
        func_002A8578(self, a1v, a2v, 5, fv, gb, 0);
        {
            void *p = self->fx0;
            if (p != 0) {
                Obj1D00_ClearState_6((cOmBase *)p);
            }
            p = self->fx6;
            if (p != 0) {
                Obj1D00_ClearState_7((cOmBase *)p);
            }
        }
        self->hitFlash = 5.0f;
        self->timer = self->rot.y;
        self->step += 1;
    }
        /* fallthrough */
    case 1:
        if (self->timer2 > 0.0f) {
            self->emFlags |= 0x800000;
            self->timer2 -= self->speedRate;
        }
        if (self->timerA != 0) {
            cVec *tgt;
            cGameObj *o;
            float d;
            self->timerA -= 1;
            tgt = self->pos;
            o = Getplayer();
            d = Turn_dest(tgt, o->pos, self->timer,
                          self->speedRate * 0.19634955f);
            self->timer += d;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += d;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_002705D8(self);
            return;
        }
        self->nullSpeed.z = self->nullSpeed.z * self->timer3;
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if (self->emNo == 0x222) {
        unsigned short fl = self->seqFlags;
        if (fl & 2) {
            self->seqFlags = fl & 0xFFFD;
            self->unk1865 = 2;
            self->unk17D4 = 6.0f;
        }
    }
    if (self->emNo == 0x208) {
        cOmWeapon *p = self->fx4;
        if (p != 0 && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&p->base) == 0) {
            self->emFlags |= 0x80000000;
        }
    }
    func_00260B30(self);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(self) == 0 &&
        (self->seqFlags & 0x10) != 0 &&
        self->unk1864 == 0 && func_00262AA8(self) != 0) {
        return;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
