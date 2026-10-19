/* sn-2.95.3-136, as=sn: menu cursor (four entries, three when the option flag is set). */
#include "godhand/gameWork.h"
extern char D_005FEE00[];
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern void func_001645E0(char *self);
extern unsigned short D_00583ED4;

__attribute__((section(".text.func_001643F8")))
void func_001643F8(char *self)
{
    unsigned long t;

    if (D_007474A0.rep & 0x1000001000000L) {
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        *(short *)(self + 0x130) = *(unsigned short *)(self + 0x130) - 1;
    }
    if (D_007474A0.rep & 0x2000002000000L) {
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        *(short *)(self + 0x130) = *(unsigned short *)(self + 0x130) + 1;
    }
    if (((t = D_007474A0.flags) >> 6 & 1) == 1) {
        *(short *)(self + 0x130) = *(short *)(self + 0x130) <= 0 ? 3
                                 : *(short *)(self + 0x130) < 4 ? *(unsigned short *)(self + 0x130) : 1;
    } else {
        *(short *)(self + 0x130) = *(short *)(self + 0x130) < 0 ? 3
                                 : *(short *)(self + 0x130) < 4 ? *(unsigned short *)(self + 0x130) : 0;
    }
    if (D_007474A0.trg & 0x10000000) {
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        *(int *)(self + 0x60) = -1;
        switch (*(short *)(self + 0x130)) {
        case 0:
            *(unsigned short *)(self + 0x134) = 0xFFFF;
            *(int *)(self + 0x60) = 0xC;
            break;
        case 1:
            if (D_007474A0.room == 0x21) {
                func_001645E0(self);
                return;
            }
            *(unsigned short *)(self + 0x134) = D_00583ED4;
            break;
        case 2:
            *(short *)(self + 0x136) = 1;
        clear:
            *(short *)(self + 0x134) = 0;
            break;
        case 3:
            *(short *)(self + 0x136) = 0;
            goto clear;
        }
    }
}
