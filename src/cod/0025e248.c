/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"

extern int Getplayer(void);
extern void SetMotionStep(void *a0, float f12);
#include "godhand/cCollisionSolid.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"
extern void func_00281560(int a0, int a1);
extern void func_00283438(int a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern float fRand1_1(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern char D_005CB000[];

#include "godhand/vu0.h"
#include "godhand/effectPos.h"



















__attribute__((section(".text.func_0025E248")))
void func_0025E248(cEm00 *self)
{
    char *s1;
    cVec buf;
    float v;

    s1 = (char *)Getplayer();
    v = *(float *)(s1 + 0x5A8);
    self->speedRate = v;
    SetMotionStep(self, v);
    self->hitFlash = 3.0f;
    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
    switch (self->step) {
    case 0: {
        int w = (int)self->pack;
        func_002A8578(self, *(int *)(w + 0x3E4C) + w, *(int *)(w + 0x3E50) + w,
                      0, 0.0f, 0, 0);
        if (self->sub0 != 0)
            func_00281560(self->sub0, 0);
        if (self->sub1 != 0)
            func_00283438(self->sub1, 0);
        if (self->sub2 != 0)
            func_00283438(self->sub2, 0);
        self->unk56A = 0;
        self->step = self->step + 1;
        goto phase1;
    }
    case 2: {
        int w = (int)self->pack;
        func_002A8578(self, *(int *)(w + 0x3E54) + w, *(int *)(w + 0x3E58) + w,
                      0, 0.0f, 0, 0);
        if (self->sub0 != 0)
            func_00281560(self->sub0, 1);
        if (self->sub1 != 0)
            func_00283438(self->sub1, 1);
        if (self->sub2 != 0)
            func_00283438(self->sub2, 1);
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 1:
    case 3:
    phase1:
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        self->step = *(unsigned char *)(s1 + 0x2F6);
        break;
    case 4: {
        int w = (int)self->pack;
        func_002A8578(self, *(int *)(w + 0x3E5C) + w, *(int *)(w + 0x3E60) + w,
                      0, 0.0f, 0, 0);
        if (self->sub0 != 0)
            func_00281560(self->sub0, 2);
        if (self->sub1 != 0)
            func_00283438(self->sub1, 2);
        if (self->sub2 != 0)
            func_00283438(self->sub2, 2);
        self->step = self->step + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(self))
            func_002705D8(self);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    default:
        break;
    }

    if (self->seqFlags & 3) {
        if (self->seqFlags & 1) {
            VU0_SQC2_VF0(&buf, 0);
            buf.x = fRand1_1() * 0.1f;
            buf.y = fRand1_1() * 0.1f + 1.5f;
            buf.z = fRand0_1() * 0.1f + 0.7f;
            sceVu0ApplyMatrix(&buf, s1 + 0x80, &buf);
            SetEffectPos(0, 0x4F, 0, &buf, -1, 1.0f);
        }
        if (self->unk56A != 0) {
            if (self->seqFlags & 1) {
                cGameObjVt *vt = cGameObj_vt((cGameObj *)self);
                short off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0x14, s1, 0, 0);
                if (self->hp <= 0)
                    self->hp = 1;
                cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
            }
            if (self->seqFlags & 2) {
                cGameObjVt *vt = cGameObj_vt((cGameObj *)self);
                short off = vt->unkA8Delta;
                vt->unkAC((char *)self + off, 0xC8, s1, 0, 0);
                cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
            }
        }
        self->unk56A = 0;
    } else {
        self->unk56A = 1;
    }
}
