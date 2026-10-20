/* sn-2.95.3-136: enemy per-frame update: sync motion speed and the player distance, run the
 * current phase handler, update the model and IK, then spin the scrolling texture on a sine wobble
 * and keep the follow position in step with the root. Phase dispatch as 001af098.c. */
#include "godhand/cEmManage.h"
extern int D_00747A78;
extern char D_00462FC0[];
extern void SetMotionStep(void *a0, float f12);
extern char *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_00281B40(char *self);
extern void cObjBase_SetSeqEffect(void *a0);
extern void func_00283070(char *self);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern float capVu0Sin(float f12);
extern float Adjust_theta(float angle);
extern void cModel_ScrollTexture(void *a0, float f);

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BFF40;

__attribute__((section(".text.func_00281968")))
void func_00281968(char *s0)
{
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    float rate;
    float scroll;
    float *src;
    float *dst;

    if (D_00747A78 & 0x40000000)
        return;
    rate = cEmManage_GetSpeedRate(&D_005864F0);
    *(float *)(s0 + 0x5A8) = rate;
    SetMotionStep(s0, rate);
    *(float *)(s0 + 0x618) = capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), *(void **)(s0 + 0xF0));
    func_00281B40(s0);

    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BFF40 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BFF40 + i8 + 4);
    }
    f0 = D_003BFF40.e[*(unsigned char *)(s0 + 0x2F4)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    cObjBase_SetSeqEffect(s0);
    func_00283070(s0);
    cModel_calcParts(s0);
    IK_InverseKinematics(s0 + 0x448, s0);
    cModel_calcWorldParts(s0);
    cCollisionSolidManage_SetActive(D_00462FC0, s0, 0);

    scroll = capVu0Sin(*(float *)(s0 + 0x15B4)) * 0.5f;
    scroll += 1.0f;
    scroll += scroll;
    scroll *= *(float *)(s0 + 0x5A8);
    *(float *)(s0 + 0x15B4) += *(float *)(s0 + 0x5A8) * 10.0f * 0.017453292f;
    *(float *)(s0 + 0x15B4) = Adjust_theta(*(float *)(s0 + 0x15B4));
    cModel_ScrollTexture(s0, scroll);

    src = *(float **)(s0 + 0xF0);
    dst = (float *)(s0 + 0x490);
    if (dst != src) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
