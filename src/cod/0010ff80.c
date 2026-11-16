/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"

extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float *cGameObj_findBurningPos(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012A3C0(void *a0);

__attribute__((section(".text.func_0010FF80")))
void func_0010FF80(pl00 *self)
{
    float b[12] __attribute__((aligned(16)));
    cVec *s1;
    float *src;
    float *dp;
    float *dd;
    float *d;
    cVec *obj;
    char *q;
    char *q2;
    cVec *obj2;
    float k;
    float one;
    char *t;

    VU0_SQC2_VF0(b, 0);
    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        Obj0000_Clear_Fields_640_648_124E58(self);
        s1 = &self->base.unk580;
        func_00126770(self);
        pl00_clearMotionCam(self, 0, 0);
        src = cGameObj_findBurningPos(self);
        if (&s1->x != src) {
            self->base.unk580.x = src[0];
            s1->y = src[1];
            s1->z = src[2];
        }
        t = self->base.pack;
        /* Called as int-returning: the $v0 def steers obj and d into v1 and a0. */
        ((int (*)(void *, int, int, int, float, int, int))func_002A8578)(
            self, EM_RES_REC(t, 0x20C), EM_RES_REC(t, 0x6DC), 3, 15.0f, 0, 0);
        obj = self->base.pos;
        d = &b[4];
        VU0_SQC2_VF0(b, 0x20);
        VU0_LQC2(4, s1, 0);
        VU0_LQC2(5, obj, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        q = (char *)b + 0x20;
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, b, 0x10);
        dp = (float *)&self->base.unk590;
        if (dp != d) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            dp[0] = t0;
            *(volatile float *)&dp[1] = t1;
            t2 = *(volatile float *)&b[6];
            dp[2] = t2;
        }
        self->base.step = self->base.step + 1;
    case 1:
        k = 0.1f;
        q2 = (char *)b + 0x20;
        VU0_LQC2(4, &self->base.unk590, 0);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, b, 0x20);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, q2, 0);
        VU0_SQC2(4, b, 0x10);
        dd = b;
        src = &b[4];
        if (dd != src) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            t2 = b[6];
            dd[0] = t0;
            dd[1] = t1;
            dd[2] = t2;
        }
        obj2 = self->base.pos;
        VU0_LQC2(4, obj2, 0);
        VU0_LQC2(5, b, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, obj2, 0);
        VU0_LQC2(4, self, 0x590);
        VU0_LQC2(5, b, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, self, 0x590);
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        if (!(self->base.seqFlags & 4)) {
            cObjBase_addNullSpeed(self, one);
        }
        break;
    }
    if (self->base.seqFlags & 1) {
        func_0012A3C0(self);
    }
    self->base.seqFlags = self->base.seqFlags | 0x200;
    func_00123938(self, 1);
}
