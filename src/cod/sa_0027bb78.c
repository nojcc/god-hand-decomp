/* sn-2.95.3-136: NM closer handoff. */
extern int D_00747A78;
extern char D_005864F0[];
extern char D_00462FC0[];
extern float cEmManage_GetSpeedRate(void *a0);
extern void SetMotionStep(void *a0, float f12);
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_0027BDD8(char *self);
extern void cObjBase_SetSeqEffect(void *a0);
extern float Turn_dest(void *a0, float f12, float f13, void *a1);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float angle);
extern void func_0027D300(char *self);
extern void func_0027D400(char *self);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFE00;

static inline void *GetPart0_27BB78(char *p)
{
    int on[3];

    if ((on[0] = *(unsigned char *)(p + 0x2B4)) != 0)
        return **(void ***)(p + 0x278);
    return 0;
}

__attribute__((section(".text.func_0027BB78")))
void func_0027BB78(char *s0)
{
    char *e;
    char *parent = *(char **)(s0 + 0x1580);
    char *part;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    float t;
    float ang;
    float *src;
    float *dst;

    if (D_00747A78 & 0x40000000)
        return;
    if (parent != 0)
        *(float *)(s0 + 0x5A8) = *(float *)(parent + 0x5A8);
    else
        *(float *)(s0 + 0x5A8) = cEmManage_GetSpeedRate(D_005864F0);
    SetMotionStep(s0, *(float *)(s0 + 0x5A8));
    *(float *)(s0 + 0x618) = capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), *(void **)(s0 + 0xF0));
    func_0027BDD8(s0);
    t = *(float *)(s0 + 0x15B4);
    *(unsigned int *)(s0 + 0x1560) &= 0xFFFFFFFC;
    if (t > 0.0f)
        *(float *)(s0 + 0x15B4) = t - *(float *)(s0 + 0x5A8);

    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BFE00 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BFE00 + i8 + 4);
    }
    f0 = D_003BFE00.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    cObjBase_SetSeqEffect(s0);
    part = GetPart0_27BB78(s0);
    if (part != 0 && parent != 0) {
        if (*(unsigned int *)(s0 + 0x1560) & 2) {
            void *pos = *(void **)(parent + 0xF0);
            ang = Turn_dest(pos, *(float *)(parent + 0x104), 3.1415927f, *(void **)(Getplayer() + 0xF0));
        } else {
            ang = 0.0f;
        }
        *(float *)(s0 + 0x15D4) += Turn_dest_dir(*(float *)(s0 + 0x15D4), ang, *(float *)(s0 + 0x5A8) * 0.049087387f);
        *(float *)(s0 + 0x15D4) = Adjust_theta(*(float *)(s0 + 0x15D4));
        *(float *)(part + 0x104) = *(float *)(s0 + 0x15D4);
    }
    func_0027D300(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    func_0027D400(s0);
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);

    src = *(float **)(s0 + 0xF0);
    dst = (float *)(s0 + 0x490);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
