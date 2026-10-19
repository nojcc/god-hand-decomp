/* sn-2.95.3-136: func_001AF098, enemy damage-phase update: sync motion speed, run the current phase handler, and on a confirmed hit either kill (guard at zero) or stagger with two hit sounds. */
extern float cEmManage_GetSpeedRate(void *a0);
extern void SetMotionStep(void *a0, float f12);
extern int cOmBase_checkDamage(void *, void *);
extern void func_001B7EE0(void *, float);
extern void func_001AEEA8(char *self, int a1);
extern void func_001B0078(char *self);
extern void func_001AEF40(char *self);
extern void cSnd_SeCall_2CBA48(void *snd, int a1, int id, void *owner, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];
extern char D_005864F0[];

#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDC80;

__attribute__((section(".text.func_001AF098")))
void func_001AF098(char *s0)
{
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    float rate;

    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + 0x5A8) = rate;
    SetMotionStep(s0, rate);

    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)&D_003BDC80 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BDC80 + i8 + 4);
    }
    f0 = D_003BDC80.e[*(unsigned char *)(s0 + 0x2F5)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    if (cOmBase_checkDamage(s0, *(void **)(s0 + 0x600)) == 1) {
        if (*(short *)(s0 + 0x54A) <= 0) {
            *(unsigned char *)(s0 + 0x2F4) = 1;
            *(unsigned int *)(s0 + 0x5B0) |= 1;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        } else {
            func_001AEEA8(s0, 8);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x55, s0, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, s0, 0, 0, 0, 0);
        }
    }
    func_001B0078(s0);
    if (*(unsigned char *)(s0 + 0xAF0) == 1)
        func_001B7EE0(s0, 2.0f);
    func_001AEF40(s0);
}
