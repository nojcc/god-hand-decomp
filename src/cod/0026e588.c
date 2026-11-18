/* sn-2.95.3-136 matched TU. */
#include "godhand/player.h"
#include "godhand/cEm00.h"

extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cEm00_setGoto(void *a0, int a1, int a2, int a3, float f);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0026E588")))
int func_0026E588(cEm00 *self) {
    if (0.0f < self->slideTime) return 0;
    if (self->flags1644 & 0x40000000) return 0;
    switch (self->emNo) {
    case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x211:
    case 0x213: case 0x214: case 0x215: case 0x217: case 0x21C:
    case 0x21F: case 0x220: case 0x221: case 0x222: case 0x223:
    case 0x250: case 0x251: case 0x252: case 0x256: case 0x260:
    case 0x264: case 0x265: case 0x26A: case 0x270: case 0x271:
    case 0x272: case 0x273: case 0x274: case 0x275: case 0x276:
    case 0x278: case 0x279: case 0x27E:
        return 0;
    }
    if (self->playerDist < 16.0f) return 0;
    if (self->unk16EC > 0) return 0;
    {
        char *vec = ((char *)self + 0x1660);
        cGameObj *r = Getplayer();
        float mag = capVu0MagnitudeSqXZ(vec, r->pos);
        float sq = *(float *)((char *)self + 0x16C8);
        if (mag < sq * sq) return 0;
        self->emFlags &= 0xFFFFFFFD;
        cEm00_setGoto(self, (int)vec, 6, 0, 450.0f);
        self->stepArg = 0;
        self->mode = 0;
        self->step = 0;
        self->phase = 0x13;
        return 1;
    }
}
