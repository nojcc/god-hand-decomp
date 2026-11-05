/* NON_MATCHING Draw_Line2 (sn-2.95.3-136, as sn).
 * Draw_Line2: 106 vs 103 words; retail rebuilds &v (addiu sp, 0x50) before each call where
 * this keeps it in a saved register, which costs one more saved register.
 * Draw_Line_sc matches in src/cod/0015f0b8.c (#42); LineAttr and Gp_draw_line are now in
 * drawPrim.h. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/gameWork.h"
#include "godhand/cCamManager.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"

/* The line drawing attributes Gp_draw_line reads: flags and the TEX1 register value. */
typedef struct LineAttr {
    int flags;                          /* 0x00 */
    int pad04[11];
    long tex1;                          /* 0x30 */
    long pad38[3];
} LineAttr;                             /* 0x50 */

extern int D_00586B80;
extern int D_003C1180;
extern void *Gp_draw_line(float (*pts)[4], unsigned int color, int a2, int a3, int a4, LineAttr *attr);

/* Draw a world-space polyline: project each point with the current camera and draw a
 * segment only when both ends are in front of the camera and inside the GS window. */
void Draw_Line2(float (*pts)[4], unsigned int count, unsigned int color, int flat)
{
    LineAttr attr;
    cVec v;
    unsigned int i;
    int out;
    int prev;

    if (D_00747A2C.unk00 & 0x40000000)
        return;
    attr.flags = 0;
    if (!flat) {
        attr.flags = 0x20;
        attr.tex1 = 0x30000;
    }
    prev = 0;
    for (i = 0; i < count; i++) {
        out = 0;
        cVec_zero(&v);
        sceVu0ApplyMatrix(&v, D_005CAFF0->mtx[0], pts[i]);
        if (v.w < 0.1f)
            out = 0x80;
        sceVu0DivVector(&v, &v, v.w);
        if (v.x < 0.0f || 4095.9f < v.x || v.y < 0.0f || 4095.9f < v.y)
            out = 0x80;
        if (i != 0 && out == 0 && prev == 0)
            Gp_draw_line(&pts[i - 1], color, 0, 8, 2, &attr);
        prev = out;
    }
}

#else
INCLUDE_ASM("asm/nonmatching", Draw_Line2);
#endif
