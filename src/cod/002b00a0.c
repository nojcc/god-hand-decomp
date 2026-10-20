/* NON_MATCHING func_002B00A0 (sn-2.95.3-136): same size, 66 insns;
* FP vertex/uv stores scheduled differently (retail stores the uv header between the first and second vertex) and FP register naming differs. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cMessDrawFont.h"

extern int cIDManager_getTexAddr_2ACE28(int a0, int a1);
extern int D_003C2388;
extern int D_00747A0C;
extern void Gp_draw_polyFT4(void *a0, int a1, int a2, int a3, int a4, int a5,
                            void *a6, int a7, int a8);

void func_002B00A0(cMessDrawFont *self)
{
    unsigned char uv[0x50];
    float vt[16];
    float x, y, d, c, y0, y1, x1;
    unsigned char *puv = uv;

    if (*(unsigned short *)(self->cursor + 2) != (short)self->unk54)
        return;
    x = self->unk88;
    y = self->unk8C;
    if (self->flags & 1)
        y += (self->unk34[1] + 12.0f) * self->zoomY;
    d = 8.0f;
    if (D_00747A0C != 0) {
        d = 4.0f;
        y += d;
    }
    x += d;
    c = y + 13.0f;
    y0 = c - 17.0f;
    x1 = x + 34.0f;
    y1 = c + 17.0f;
    *(int *)(puv + 0x0) = 1;
    *(int *)(puv + 0x4) = 0;
    *(float *)(puv + 0x8) = 1.0f;
    *(float *)(puv + 0xC) = 1.0f;
    *(int *)(puv + 0x10) = 0;
    vt[0] = x;
    vt[1] = y1;
    vt[2] = 65535.0f;
    vt[3] = 1.0f;
    vt[4] = x1;
    vt[5] = y1;
    vt[6] = 65535.0f;
    vt[7] = 1.0f;
    vt[8] = x;
    vt[9] = y0;
    vt[10] = 65535.0f;
    vt[11] = 1.0f;
    vt[12] = x1;
    vt[13] = y0;
    vt[14] = 65535.0f;
    vt[15] = 1.0f;
    Gp_draw_polyFT4(vt, 0x80808080, 1, cIDManager_getTexAddr_2ACE28(D_003C2388, 0x2F),
                    0x3B00, 0x1CF0, puv, 6, 2);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002B00A0);
#endif
