/* NON_MATCHING func_001F3118: sn; switch tree fixed by an empty case 2; remaining: lw vs lwu on the 64-bit flag test, case-0 b/a masks not folded to andi 0x7373, and case-1 uninitialized CidColor locals land in a3 instead of t0 (retail register = phantom by-value param pattern under checkpoint-90 review) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { unsigned int r:8, g:8, b:8, a:8; } CidColor;

typedef struct CidPanel1F3118 {
    unsigned int flags;
    char pad004[0x158 - 0x004];
    char frame[0x7C];                   /* 0x158 CustomIDWork */
    char pad1D4[0x920 - 0x1D4];
    int state;                          /* 0x920 */
    int timer;                          /* 0x924 */
} CidPanel1F3118;

extern void CustomIDWork_SetColorAnimNormal_2D68D8(void *work, int a1, CidColor col, int frames);
extern void CustomIDWork_SetColorAnimSin(void *work, CidColor from, CidColor to, int frames);
extern void SetCustomIDDispOneOrAll_1F29C0(CidPanel1F3118 *self, int id, int disp);

void func_001F3118(CidPanel1F3118 *self)
{
    CidColor col;
    CidColor from;
    CidColor to;
    long t;

    t = self->flags;
    if ((((unsigned long)t >> 1) & 1UL) != 1UL)
        return;
    switch (self->state) {
    case 0:
        col.r = 0x73;
        col.g = 0x73;
        col.b = 0x73;
        col.a = 0x80;
        CustomIDWork_SetColorAnimNormal_2D68D8(self->frame, 0, col, 15);
        SetCustomIDDispOneOrAll_1F29C0(self, 2, 1);
        self->timer = 15;
        self->state++;
        break;
    case 1:
        if (self->timer != 0) {
            self->timer--;
            break;
        }
        from.r = 0x73;
        from.g = 0x73;
        from.b = 0x73;
        from.a = 0x80;
        to.r = 0xA8;
        to.g = 0xA8;
        to.b = 0xA8;
        to.a = 0x80;
        CustomIDWork_SetColorAnimSin(self->frame, from, to, 3);
        self->state++;
        break;
    case 2:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F3118);
#endif
