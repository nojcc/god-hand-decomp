/* NON_MATCHING func_001846D8 (sn-2.95.3-136): retail uses 7 s-regs (ours strength-reduces the 0x61C hit index into an 8th), keeps &D_007474A0 hoisted, reuses single D_00422F70/0x4C loads, and splits the 26..39 level test into two compares */
#include "include_asm.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"

#ifdef NON_MATCHING
extern char D_007474A0[];
extern short D_00422F70;
extern unsigned char D_005CB010;
extern int cOmBase_checkDamage(void *self, void *part);
extern void func_00186598(void *self, float f);

#define PART(self, i) (((char **)((self) + 0x600))[i])
#define HITS(self) ((short *)((self) + 0x61C))

void func_001846D8(char *self)
{
    unsigned int i;
    unsigned int j;
    float v;
    float f;
    short lvl;
    float *t = (float *)(self + 0x638);
    char **parts;

    for (j = 1; j < 7; j++) {
        if (0.0f < t[j]) {
            v = t[j] - *(float *)(self + 0x5A8) * *(float *)(D_007474A0 + 0x574);
            t[j] = v;
            if (v < 0.0f)
                t[j] = 0.0f;
        }
    }
    if (PART(self, 0) == 0)
        return;
    if (cOmBase_checkDamage(self, PART(self, 0)) == 0)
        return;
    if (*(short *)(self + 0x548) > D_00422F70)
        *(short *)(self + 0x54A) = D_00422F70;
    else
        *(short *)(self + 0x54A) = *(short *)(self + 0x548);
    *(short *)(self + 0x61C) = D_00422F70;
    *(short *)(self + 0x62A) = D_00422F70;
    *(short *)(self + 0x662) = *(int *)(PART(self, 0) + 0x4C);
    if (D_005CB010)
        *(short *)(self + 0x662) = *(int *)(PART(self, 0) + 0x4C) * 2;
    func_00186598(self, (float)*(short *)(self + 0x662));
    parts = (char **)(self + 0x600);
    for (i = 1; i < 7; i++) {
        if (parts[i] == 0)
            continue;
        if (t[i] != 0.0f)
            continue;
        if (!(*(unsigned int *)(parts[i] + 0x60) & 1))
            continue;
        if (i < 7) {
            HITS(self)[i] -= *(short *)(self + 0x662);
            if (HITS(self)[i] < 0)
                HITS(self)[i] = 0;
        }
        lvl = *(short *)(PART(self, 0) + 0x46);
        f = 3.0f;
        if (lvl < 0x28 && lvl >= 0x1A)
            f = 15.0f;
        t[i] = f;
        switch (i) {
        case 1:
            if (*(unsigned char *)(self + 0x65C) == 0) {
                SetEffect(0x298, 0xD, self, 0, -1, 0xFFFFFFFF);
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x10F, self, 0, 0, 0, 0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x117, self, 0, 0, 0, 0);
            }
            break;
        case 2:
            if (*(unsigned char *)(self + 0x65D) == 0) {
                SetEffect(0x298, 0xE, self, 0, -1, 0xFFFFFFFF);
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x10F, self, 0, 0, 0, 0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x117, self, 0, 0, 0, 0);
            }
            break;
        case 3:
            if (*(unsigned char *)(self + 0x65E) == 0) {
                SetEffect(0x298, 0x10, self, 0, -1, 0xFFFFFFFF);
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x10F, self, 0, 0, 0, 0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x117, self, 0, 0, 0, 0);
            }
            break;
        case 4:
            if (*(unsigned char *)(self + 0x65F) == 0) {
                SetEffect(0x298, 0xF, self, 0, -1, 0xFFFFFFFF);
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x10F, self, 0, 0, 0, 0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, self, 0, 0, 0, 0);
            } else {
                cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x117, self, 0, 0, 0, 0);
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001846D8);
#endif
