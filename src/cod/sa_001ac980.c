/* sn-2.95.3-136: func_001AC980, breakable gimmick phase update: run the handler of the current
 * phase entry, regenerate one guard point every 5 frames, and on a new hit (when not locked)
 * take its damage from the guard, breaking it at zero, with a hit sound. */
extern void cSnd_SeCall_2CBA48(void *snd, int a1, int id, void *owner, int t0, int t1, int t2, int t3);
extern void func_001AC370(char *self);
extern void func_001B7EE0(char *self, float f);
extern char D_005FEE00[];

#include "godhand/cOmBase.h"
#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDC40;

__attribute__((section(".text.func_001AC980")))
void func_001AC980(char *s0)
{
    char *e;
    int i8;
    int f0;
    int type; int arg; void (*fp)(int); long entry;
    cDamageTake *hit;
    int n;
    int m;
    int c;
    unsigned long t;

    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = (char *)&D_003BDC40 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (void (*)(int))(int)(entry >> 32);
    } else {
        fp = *(void (**)(int))((char *)&D_003BDC40 + i8 + 4);
    }
    f0 = D_003BDC40.e[*(unsigned char *)(s0 + 0x2F5)].adjust;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));

    c = --*(signed char *)(s0 + 0x621);
    if (c <= 0) {
        *(signed char *)(s0 + 0x621) = 5;
        n = *(short *)(s0 + 0x54A) + 1;
        if (n >= *(short *)(s0 + 0x548))
            *(short *)(s0 + 0x54A) = *(short *)(s0 + 0x548);
        else
            *(short *)(s0 + 0x54A) = n;
    }
    if (*(unsigned char *)(s0 + 0x60D) == 0) {
        hit = *(cDamageTake **)(s0 + 0x624);
        if (hit != 0) {
            t = hit->flags;
            t &= 1;
            if (t != 0) {
            int d = hit->power;

            m = *(short *)(s0 + 0x54A);
            m -= d;
            *(float *)(s0 + 0x54C) = 3.0f;
            if (m >= *(short *)(s0 + 0x548))
                *(short *)(s0 + 0x54A) = *(short *)(s0 + 0x548);
            else
                *(short *)(s0 + 0x54A) = m;
            *(int *)(s0 + 0x618) += d;
            if (*(short *)(s0 + 0x54A) <= 0) {
                *(unsigned char *)(s0 + 0x2F4) = 1;
                *(unsigned char *)(s0 + 0x2F5) = 0;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            } else {
                *(short *)(s0 + 0x610) = 8;
                *(float *)(s0 + 0x614) = (*(float **)(s0 + 0xF0))[1];
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, s0, 0, 0, 0, 0);
            }
        }
    }
    func_001AC370(s0);
    if (*(unsigned char *)(s0 + 0x60C) == 1)
        func_001B7EE0(s0, 2.0f);
}
