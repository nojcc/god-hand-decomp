/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cCamManager.h"
#include "godhand/cModel.h"
#include "godhand/cObjBase.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/globals.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cEm00_attachToTarget(void *a0, void *a1);

extern void cPartsCamera_SetParts(void *parts, void *obj, int a2, int a3);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_00275DA8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);


/* Phase machine on the step byte, 4 case labels. Calls Getplayer,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, cEm00_attachToTarget, cModel_getMeshPtr_14B730,
 * cCamManager_setPartsCamera and 9 more. */
__attribute__((section(".text.func_00247B18"))) void func_00247B18(cEm00 *self)
{
    cGameObj *pl;
    int spill[2];
    cEffectParam s;
    char *v;
    cCamManager *mgr;
    struct cCamera *parts;
    int nb, b, lim, a2v, a3v;
    float one;
    float *fp;

    pl = Getplayer();
    self->objFlags = self->objFlags | 0x40000;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x38B0), EM_RES_REC(b, 0x38B4), 0, 0.0f, nb, 0);
            if (self->unk744 != 0) {
                cEm00_attachToTarget(self->unk744, self);
            }
            self->unk1768 = 600.0f;
            v = cModel_getMeshPtr_14B730(self, &D_0042CAD0);
            if (v != 0) {
                *(int *)(v + 0x380) = *(int *)(v + 0x380) & 0xFFFFFFFE;
            }
            self->step = self->step + 1;
        case 1:
            self->hitFlash = 3.0f;
            mgr = &D_00463050;
            cCamManager_setPartsCamera(mgr, 0);
            parts = &mgr->parts;
            b = self->partNum;
            spill[0] = b;
            lim = 0x24;
            if (lim < b) {
                a2v = *(int *)(*(int *)((char *)self + 0x278) + 0x90);
            } else {
                a2v = 0;
            }
            b = self->partNum;
            spill[0] = b;
            lim = 0x25;
            if (lim < b) {
                a3v = *(int *)(*(int *)((char *)self + 0x278) + 0x94);
            } else {
                a3v = 0;
            }
            cPartsCamera_SetParts(parts, self, a2v, a3v);
            self->emFlags = self->emFlags | 0x800000;
            if (moveMotion(self) != 0) {
                pl00_clearMotionCam(pl, 0, 1);
                if (self->unk744 != 0) {
                    ReleaseObj(self->unk744);
                    *(int *)((char *)self + 0x744) = 0;
                    func_00275DA8(self);
                }
                fp = &s.color.x;
                s.color.x = 1.0f;
                fp[1] = 1.0f;
                fp[2] = 1.0f;
                fp[3] = 1.0f;
                VU0_SQC2_VF0(spill, 0x20);
                VU0_SQC2_VF0(spill, 0x30);
                {
                    float *q = &s.scale.x;
                    s.scale.x = 1.0f;
                    q[1] = 1.0f;
                    q[2] = 1.0f;
                    q[3] = 1.0f;
                }
                fp[0x10] = 1.0f;
                s.unk44 = 0;
                s.flags = 0;
                ((signed char *)fp)[0x4C] = -1;
                s.unk4D = 0;
                s.unk4E = 0;
                ((unsigned char *)fp)[0x4F] = 0xFF;
                s.unk50 = 0;
                VU0_SQC2_VF0(spill, 0x70);
                s.size = self->scale.y;
                s.unk70 = 0;
                s.unk72 = 0;
                s.unk74 = 0;
                s.unk78 = 0;
                SetEffect(0xBD, 0x19, self, &s, 1, 0xFFFFFFFF);
                self->emFlags2 = self->emFlags2 | 0x20000000;
                *(char *)((char *)self + 0x186C) = 2;
                self->step = 2;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 2:
            self->unk1864 = 0;
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            func_002A8578(self, EM_RES_REC(b, 0x3778), EM_RES_REC(b, 0x377C), 3, 0.0f, nb, 0);
            self->step = self->step + 1;
        case 3:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x9C;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}
