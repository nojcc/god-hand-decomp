#include "godhand/cEm00.h"
#include "godhand/gameWork.h"
/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern void cEmManage_CreateItem(void *a0, int a1, int a2, int a3);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 candidate. */







__attribute__((section(".text.func_00273D30")))
void func_00273D30(cEm00 *self)
{
    int f = self->emFlags2;

    if ((f & 2) != 0) {
        return;
    }
    self->emFlags2 = f | 2;
    switch (self->emNo) {
    case 0x220: case 0x221: case 0x222: case 0x223:
        if (D_007474A0.room == 0x801) {
            unsigned int r = irand() % 100;

            self->dropItem = 0x3C1;
            if (r >= 0x14) {
                self->dropItem = 0x3C8;
            }
            if (r >= 0x28) {
                self->dropItem = 0x3D1;
            }
            if (r >= 0x31) {
                self->dropItem = 0x3D0;
            }
            if (r >= 0x32) {
                self->dropItem = 0x3E0;
            }
            if (r >= 0x41) {
                self->dropItem = 0x3E1;
            }
            if (r >= 0x3B) {
                self->dropItem = 0x3DE;
            }
            if (r >= 0x50) {
                self->dropItem = 0x3E2;
            }
            if (r >= 0x5A) {
                self->dropItem = 0x3DF;
            }
        } else {
            self->dropItem = func_002920B0(&D_005864F0);
            if (irand() % 100 >= 0x46) {
                self->dropItem = 0x3D8;
            }
        }
        break;
    case 0x21F: case 0x250: case 0x251: case 0x252: case 0x256: case 0x260:
    case 0x264: case 0x265: case 0x26A: case 0x275: case 0x27E:
        return;
    default:
        break;
    }
    cEmManage_CreateItem(&D_005864F0, *(int *)((char *)self + 0xF0), self->dropItem, 1);
}
