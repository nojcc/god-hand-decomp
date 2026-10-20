/* NON_MATCHING func_001F2D60 (sn-2.95.3-136;
 * PARK, 214 diffs): same CidColor family as sa_nm_001f3118.c; retail keeps the case-0 colours on the stack (word RMW for r, sb for the other bytes through &c1) and case 1 reads uninitialized a2/a3 (phantom by-value param pattern, left for review like 001F3118) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { unsigned int r:8, g:8, b:8, a:8; } CidColor;

typedef struct {
    unsigned int flags;
    char pad004[0x60 - 0x004];
    char frameA[0x7C];
    char frameB[0x7C];
    char pad158[0x918 - 0x158];
    int state;
    int timer;
} Cid1F2D60;

extern char D_005FEE00[];
extern char *D_005CAFF0;
extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *work, CidColor from, CidColor to, unsigned short frames);
extern void CustomIDWork_SetColorAnimSin(void *work, CidColor from, CidColor to, int frames);
extern void CustomIDWork_SetColorAnimNormal_2D6898(void *work, int color, int frames);
extern void CustomIDWork_ResetColorAnim(void *work);
extern void CustomIDWork_SetScaleAnimNormal(void *work, float from, float to, int frames);
extern void SetCustomIDDispOneOrAll_1F29C0(void *self, int id, int disp);
extern int cSnd_SeCall(void *a0, int a1, int a2, void *a3, int a4, int a5);

static inline void setCol(CidColor *c, int r, int g, int b, int a)
{
    c->r = r;
    c->g = g;
    c->b = b;
    c->a = a;
}

void func_001F2D60(Cid1F2D60 *self)
{
    CidColor c0;
    CidColor c1;
    CidColor from;
    CidColor to;
    long t;

    t = self->flags;
    if ((((unsigned long)t >> 0) & 1UL) != 1UL)
        return;
    switch (self->state) {
    case 0:
        setCol(&c1, 0x80, 0x80, 0x80, 0x80);
        setCol(&c0, 0x80, 0x80, 0x80, 0);
        self->timer = 15;
        CustomIDWork_SetColorAnimNormal_2D68D8(self->frameA, c0, c1, self->timer);
        SetCustomIDDispOneOrAll_1F29C0(self, 0, 1);
        setCol(&c0, 0x80, 0x80, 0x80, 0);
        setCol(&c1, 0xD0, 0xD0, 0xD0, 0x80);
        CustomIDWork_SetColorAnimNormal_2D68D8(self->frameB, c0, c1, self->timer);
        SetCustomIDDispOneOrAll_1F29C0(self, 1, 1);
        self->state++;
        break;
    case 1:
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        from.r = 0x50;
        to.r = 0xD0;
        from.g = 0x50;
        to.g = 0xD0;
        from.b = 0x50;
        to.b = 0xD0;
        from.a = 0x80;
        to.a = 0x80;
        self->timer = 30;
        CustomIDWork_SetColorAnimSin(self->frameB, to, from, 6);
        self->state++;
        break;
    case 2:
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        CustomIDWork_SetColorAnimNormal_2D6898(self->frameA, 0xFFFFFF, 10);
        CustomIDWork_ResetColorAnim(self->frameB);
        CustomIDWork_SetColorAnimNormal_2D6898(self->frameB, 0xFFFFFF, 10);
        CustomIDWork_SetScaleAnimNormal(self->frameA, 1.0f, 2.5f, 10);
        CustomIDWork_SetScaleAnimNormal(self->frameB, 1.0f, 2.0f, 10);
        cSnd_SeCall(D_005FEE00, 2, 0x105, D_005CAFF0 + 0x210, 0, 0);
        self->timer = 10;
        self->state++;
        break;
    case 3:
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        SetCustomIDDispOneOrAll_1F29C0(self, 0, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 1, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 0xB, 0);
        SetCustomIDDispOneOrAll_1F29C0(self, 0xC, 0);
        self->state = 0;
        self->timer = 0;
        self->flags &= ~1;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F2D60);
#endif
