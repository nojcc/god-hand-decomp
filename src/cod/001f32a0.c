/* Colours are bitfield structs passed by value (a register), which keeps the
 * per-byte and/or masks unmerged as in retail.
* func_001F32A0: 38 insns, register choice only - retail builds col from an
 * uninitialised a3 into a2 (from/to in t0/a2); ours uses a1 and t0/a3.
* CustomIDOwner_setPanelState: 3 insns, case 3 - retail hoists lui a1,0x8000 into a beql
 * delay slot where ours puts daddu a0,s0 in a plain beq slot. */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct { unsigned int r:8, g:8, b:8, a:8; } CidColor;

typedef struct CidPanel {
    unsigned int flags;
    char pad004[0x250 - 0x004];
    char blink[0x7C];           /* 0x250 CustomIDWork */
    char pad2CC[0x728 - 0x2CC];
    char number[0x7C];          /* 0x728 CustomIDWork */
    char pad7A4[0x928 - 0x7A4];
    int state;                  /* 0x928 */
    int timer;                  /* 0x92C */
    char pad930[0x980 - 0x930];
    char slide[0x7C];           /* 0x980 CustomIDWork */
} CidPanel;

extern void CustomIDWork_SetColorAnimSin(void *work, CidColor from, CidColor to, int frames);
extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *work, int a1, CidColor col, int frames);
extern void SetCustomIDDispOneOrAll_1F29C0(CidPanel *self, int id, int disp);

void func_001F32A0(CidPanel *self)
{
    long flags;
    CidColor col, from, to;

    flags = self->flags;
    if (((flags >> 2) & 1) == 0) {
        return;
    }
    switch (self->state) {
    case 0:
        col.r = 0x80; col.g = 0x80; col.b = 0x80; col.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D68D8(self->blink, 0, col, 0xF);
        SetCustomIDDispOneOrAll_1F29C0(self, 4, 1);
        self->timer = 15;
        self->state++;
        break;
    case 1:
        if (self->timer == 0) {
        from.r = 0x80; from.g = 0x80; from.b = 0x80; from.a = 0x80;
        to.r = 0x80; to.g = 0x80; to.b = 0x80; to.a = 0x4D;
        CustomIDWork_SetColorAnimSin(self->blink, from, to, 5);
        self->state++;
        } else {
            self->timer--;
        }
        break;
    case 2:
        break;
    }
}

#else

INCLUDE_ASM("asm/nonmatching", func_001F32A0);

#endif
