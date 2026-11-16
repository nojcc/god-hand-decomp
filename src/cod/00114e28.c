/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void KillEffect(void *a0, int a1, int a2);
extern void KillEffectWithFlag(void *a0, int a1, int a2, int a3);
extern void func_001AAB10(void *a0);
extern void SetField5B0Bit2ClearBit8_1B7908(int a0);
extern void func_001268F0(void *a0);
extern void func_00126770(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/pl00.h"
#include "godhand/cEm00.h"
#include "godhand/heapArena.h"
#include "godhand/cIDBase.h"
#include "godhand/cDvd.h"
#include "godhand/motion.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"
extern void func_0012A8D8(void *a0);
extern void cIDManager_getLocalFileName();
extern void cIDManager_setIDData();
extern int D_003C2388;
extern char D_0041E190[];
extern int *D_003C2384;
extern void SetMotionStep(void *a0, float f12);
extern float D_003BDE70;
extern float D_003BDE74;
extern float D_003BDE78;
extern float D_003BDE7C;
extern float D_003BDE80;
extern float D_003BDE84;
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

/* sn-2.95.3-136 matched TU. */


















#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001215C8")))
void func_001215C8(pl00 *self)
{
    cEm00 *s2;
    cVec buf;
    float v;

    self->base.hitFlash = 5.0f;
    self->base.objFlags = self->base.objFlags | 0x10000;
    s2 = self->unk694;
    cCollisionSolidManage_SetActive(&D_00462FC0, &self->base, 0);
    cEmManage_SetPlCatched(&D_005864F0);

    switch (self->base.step) {
    case 0:
        CallWithAndClearField698_12AC28(self);
        func_0012B928(self);
        buf.x = -0.257099986f;
        buf.y = 0.0f;
        buf.z = 1.64129996f;
        buf.w = 1.0f;
        v = buf.y;
        func_001299F0(self, s2, &buf, 0, v);
        cEm00_GetPlMotion(s2, 0x2D, v, v);
        self->unk15B0 = 1;
        self->base.unk56E = 0xF;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        if (self->base.unk56E != 0 && s2 != 0) {
            cVec *d;
            cVec *e = &s2->vel;
            self->base.unk56E = self->base.unk56E - 1;
            d = self->base.pos;
            VU0_VADD_XYZ_IP(d, 0, e);
        }
        func_00124EC0(self);
        if (moveMotion(self)) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if (func_00123938(self, 1)) {
        pl00_clearMotionCam(self, 0, 0);
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/effectPos.h"









__attribute__((section(".text.func_001AA6C0")))
void func_001AA6C0(void *a0)
{
    char *s1 = (char *)a0;
    cVec buf;
    int hold[4];

    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0: {
        char *vt;
        short off;
        float *(*fp)();
        float *src;
        int b;
        void *part;
        KillEffect(s1, 0xB, 0);
        KillEffectWithFlag(s1, 3, 2, 0x1E);
        VU0_SQC2_VF0(&buf, 0);
        vt = *(char **)(s1 + 0x214);
        off = *(short *)(vt + 0x80);
        fp = *(float *(**)())(vt + 0x84);
        src = fp(s1 + off);
        if (&buf.x != src) {
            buf.x = src[0];
            buf.y = src[1];
            buf.z = src[2];
        }
        SetEffectPos(0, 7, 0, &buf, -1, 1.0f);
        {
            int i = 5;
            if ((hold[0] = b = *(unsigned char *)(s1 + 0x2B4)), i < b)
                part = *(void **)(*(int *)(s1 + 0x278) + i * 4);
            else
                part = 0;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x5B, s1, 0, part, 0, 0);
        {
            int i = 5;
            if ((hold[0] = b = *(unsigned char *)(s1 + 0x2B4)), i < b)
                part = *(void **)(*(int *)(s1 + 0x278) + i * 4);
            else
                part = 0;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x87, s1, 0, part, 0, 0);
        func_001AAB10(s1);
        SetField5B0Bit2ClearBit8_1B7908((int)s1);
        *(short *)(s1 + 0x600) = 0x1E;
        *(unsigned char *)(s1 + 0x2F5) = 1;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)(s1 + 0x600) - 1;
        *(short *)(s1 + 0x600) = v;
        if ((short)v > 0)
            break;
        *(short *)(s1 + 0x600) = 0xF;
        *(unsigned char *)(s1 + 0x2F5) = 2;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)(s1 + 0x600) - 1;
        *(short *)(s1 + 0x600) = v;
        if ((short)v > 0)
            break;
        *(unsigned char *)(s1 + 0x2F5) = 3;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
    case 3:
        *(unsigned char *)(s1 + 0x2F4) = 0;
        *(unsigned char *)(s1 + 0x2F5) = 0;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_00114E28")))
void func_00114E28(pl00 *self)
{
    int t;
    int p1;
    int p2;

    switch (self->base.step) {
    case 0:
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        func_00126770(self);
        pl00_clearMotionCam(self, 0, 0);
        t = (int)self->base.pack;
        p1 = *(int *)(t + 0x3D8) + t;
        p2 = *(int *)(t + 0x3DC) + t;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x29, self, 0, 0, 0, 0);
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.step = self->base.step + 1;
        /* fallthrough */
    case 1:
        InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if ((self->base.seqFlags & 1) != 0 && self->sub698 == 0) {
        cGameObj *obj = CreateObj(0x3AF, 0xFFFF);
        self->sub698 = obj;
        if (obj != 0) {
            cGameObj *p2c;
            cGameObj *p3;
            cVec *src1;
            cVec *src2;
            cVec *dst;
            cVec *posA;
            cVec *rot;

            {
                cGameObjVt *v1 = cGameObj_vt(obj);
                short off = v1->initialDelta;
                int (*fn)(void *) = v1->initial;
                fn((char *)obj + off);
            }
            src1 = self->base.pos;
            dst = self->sub698->pos;
            if (dst != src1) {
                dst->x = src1->x;
                dst->y = src1->y;
                dst->z = src1->z;
            }
            p2c = self->sub698;
            src2 = self->base.pos;
            posA = &p2c->posA;
            if (posA != src2) {
                posA->x = src2->x;
                posA->y = src2->y;
                posA->z = src2->z;
            }
            p3 = self->sub698;
            rot = &p3->rot;
            rot->x = 0.0f;
            rot->y = 0.0f;
            rot->z = 0.0f;
            func_0012A8D8(self);
        }
    }
    func_00123938(self, 1);
}

/* sn-2.95.3-136 matched TU. */














typedef struct MiddleBossPart {
    cIDBaseObj id;                      /* 0x00 */
    char pad48[0x50 - sizeof(cIDBaseObj)];
} MiddleBossPart;

typedef struct {
    cIDBaseObj base;     /* 0x00 */
    char pad48[0x90 - sizeof(cIDBaseObj)];
    int f90;             /* 0x90 */
    char pad94[0xC];
    int fA0;             /* 0xA0 */
    int fA4;             /* 0xA4 */
    int fA8[5];          /* 0xA8 */
    char padBC[4];
    MiddleBossPart id[5]; /* 0xC0 */
    char pad250[0x70];
    float f2C0[5];       /* 0x2C0 */
    float f2D4[5];       /* 0x2D4 */
    float f2E8[5];       /* 0x2E8 */
    short f2FC[5];       /* 0x2FC */
    char pad306[0x6A];
    int f370[5];         /* 0x370 */
} MiddleBoss;

__attribute__((section(".text.cCockMiddleBoss_roomInit")))
void cCockMiddleBoss_roomInit(MiddleBoss *self) {
    char buf[0x40];
    int r;
    unsigned short i;

    do {
        if (self->fA0 == 0) {
            cIDManager_getLocalFileName(D_003C2388, buf, D_0041E190, -1);
            r = cDvd_ReadAlloc(&D_00583F20, buf, &self->fA0, &D_00754220, 0, 0, 0, 0);
            self->fA4 = r;
            cDvd_CheckWait(&D_00583F20, r);
            cIDManager_setIDData(*D_003C2384, 0xD, self->fA0);
            cIDBase_initialize(&self->base, 0xD, 0);
            cIDBase_resetAnim(&self->base);
            cIDBase_getIDWork(&self->base, 0)->posX = -100.0f;
            self->f90 = 0;
            for (i = 0; i < 5; i++) {
                MiddleBossPart *id = &self->id[i];
                cIDBaseEnt *w;
                cIDBase_initialize(&id->id, 0xD, 1);
                cIDBase_resetAnim(&id->id);
                self->f2C0[i] = 1.0f;
                self->f2D4[i] = 1.0f;
                self->f2E8[i] = 1.0f;
                self->f2FC[i] = 0;
                self->f370[i] = 0;
                self->fA8[i] = 0;
                w = cIDBase_getIDWork(&id->id, 0);
                w->posY = cIDBase_getIDWork(&self->base, 0)->posY;
            }
        }
    } while (0);
    self->f90 = 0x80000000;
}

/* sn-2.95.3-136 matched TU. */










__attribute__((section(".text.func_001C8020")))
void func_001C8020(char *s0)
{
    int hold[4];
    char *s1;
    char *p;
    float *d;
    float *s;
    int b;

    {
        int i = 0;
        if ((hold[0] = b = *(unsigned char *)(s0 + 0x2B4)), i < b)
            s1 = *(char **)(*(int *)(s0 + 0x278) + i * 4);
        else
            s1 = 0;
    }
    p = *(char **)(s0 + 0x644);
    if (p == 0) return;
    s = *(float **)(p + 0xF0);
    d = *(float **)(s0 + 0xF0);
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    {
        char *q = *(char **)(s0 + 0x644);
        float *d2 = (float *)(s0 + 0x100);
        float *s2 = (float *)(q + 0x100);
        if (d2 != s2) {
            d2[0] = s2[0];
            d2[1] = s2[1];
            d2[2] = s2[2];
        }
    }
    *(float *)(s0 + 0x5A8) = *(float *)(*(char **)(s0 + 0x644) + 0x5A8);
    SetMotionStep(s0, *(float *)(s0 + 0x5A8));
    moveMotion(s0);
    if (s1 == 0) return;
    switch (*(unsigned short *)(s0 + 0x2FE)) {
    case 0x30A:
    case 0x325:
    case 0x33F:
    case 0x411:
    case 0x41A:
        (*(float **)(s1 + 0xD0))[0] += D_003BDE70 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[1] += D_003BDE74 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[2] += D_003BDE78 * *(float *)(s0 + 0x624);
        break;
    case 0x301:
    case 0x30B:
    case 0x30C:
    case 0x332:
    case 0x410:
    case 0x419:
    case 0x41F:
    case 0x42E:
        (*(float **)(s1 + 0xD0))[0] += D_003BDE7C * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[1] += D_003BDE80 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[2] += D_003BDE84 * *(float *)(s0 + 0x624);
        break;
    }
    *(float *)(s0 + 0x624) = *(float *)(s0 + 0x624) + 0.0500000007f;
    if (1.0f < *(float *)(s0 + 0x624)) *(float *)(s0 + 0x624) = 1.0f;
}

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_00273748")))
void func_00273748(cEm00 *self)
{
    int frame[3];
    cOmWeapon *o;
    cOmBase *part;
    int big;
    float k;
    float t;
    float v;

    o = self->fx4;
    if (o == 0) return;
    switch (self->emNo) {
    case 0x208:
        if (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&o->base)) {
            if ((*(long *)((char *)self + 0x2F0) & 0xFFFF00000000) == 0xE0000000000) return;
            if (!(capVu0MagnitudeSqXZ(self->fx4->base.pos, self->pos) < 0.360000014f)) return;
            SetOrientByType_26AF20((cOmBase *)self, self->fx4, 0);
        } else if (self->emFlags < 0) {
            SetOrientByType_26AF20((cOmBase *)self, self->fx4, 1);
        } else {
            SetOrientByType_26AF20((cOmBase *)self, self->fx4, 0);
        }
        return;
    case 0x22F:
        big = 1;
        if (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&o->base)) {
            if ((*(long *)((char *)self + 0x2F0) & 0xFFFF00000000) != 0xE0000000000) {
                if (capVu0MagnitudeSqXZ(self->fx4->base.pos, self->pos) < 0.360000014f) {
                    SetOrientByType_26AF20((cOmBase *)self, self->fx4, 2);
                }
            }
        } else if (self->emFlags < 0) {
            SetOrientByType_26AF20((cOmBase *)self, self->fx4, 3);
        } else {
            big = 0;
            SetOrientByType_26AF20((cOmBase *)self, self->fx4, 2);
        }
        o = self->fx4;
        part = cOmBase_childAt(&o->base, frame, 1);
        if (part == 0) return;
        k = 1.0f;
        if (big) k = 4.0f;
        t = 1.0f - self->speedRate * 0.100000001f;
        v = part->scale.x * t + k * (1.0f - t);
        part->scale.x = v;
        part->scale.y = v;
        part->scale.z = v;
        self->fx4->base.objFlags |= 0x40000;
        return;
    }
}
