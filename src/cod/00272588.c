/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/capVu0.h"
#include "godhand/player.h"

extern void func_001D0AD0(cOmWeapon *self);
extern void cEm00_setGoto(cEm00 *self, cVec *pos, int kind, int reset, float time);

__attribute__((section(".text.func_00272588")))
int func_00272588(cEm00 *self) {
    if (self->unk6EC != 0) {
        return 0;
    }
    if (self->fx0 != 0) {
        return 0;
    }
    switch (self->emNo) {
    case 0x200: case 0x201: case 0x202: case 0x203: case 0x216:
    case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
    case 0x23A: case 0x240: case 0x24A: case 0x24B:
    {
        cOmWeapon *s0 = func_002DDAB0(self->pos, 0, 10.0f);
        if (s0 == 0) {
            return 0;
        }
        {
            cGameObj *o = Getplayer();
            if (capVu0MagnitudeSqXZ(o->pos, s0->base.pos) < 6.25f) {
                return 0;
            }
        }
        func_001D0AD0(s0);
        cEm00_setGoto(self, s0->base.pos, 8, 0, 300.0f);
        self->stepArg = 0;
        self->mode = 0;
        self->step = 0;
        self->phase = 0x13;
        return 1;
    }
    default:
        return 0;
    }
}
