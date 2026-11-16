/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_001268F0(void *a0);
extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012A8D8(void *a0);

__attribute__((section(".text.func_0028A9E8")))
void func_0028A9E8(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int b;
        func_0028FB08(a0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        if (*(int *)(s0 + 0x564) != 0x2A7 && *(int *)(s0 + 0x564) != 0x2AB) {
            b = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(b + 0x70) + b, *(int *)(b + 0x74) + b, 5, 0.0f, 0, 0);
        }
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x98) + b, *(int *)(b + 0x9C) + b, 5, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5F, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F5) = 1;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s0, one);
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
}

__attribute__((section(".text.func_00114CB8")))
void func_00114CB8(pl00 *self)
{
    float one;
    switch (self->base.step) {
    case 0: {
        char *v0;
        int p1, p2;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        func_00126770(self);
        pl00_clearMotionCam(self, 0, 0);
        v0 = self->base.pack;
        p1 = *(int *)(v0 + 0x3D8) + (int)v0;
        p2 = *(int *)(v0 + 0x3DC) + (int)v0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x29, self, 0, 0, 0, 0);
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.step += 1;
    }
    case 1:
        InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
    if ((self->base.seqFlags & 1) && self->sub698 == 0) {
        func_0012A8D8(self);
    }
    func_00123938(self, 1);
}
