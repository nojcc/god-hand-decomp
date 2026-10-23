/* sn-2.95.3-136 */
/* Gp_draw_polyG4: the packet layout, colour and position packing match (needs as=sn for the
 * dli constants). Retail indexes the projected vertex array by the loop counter for each call
 * and walks a separate pointer for the screen offsets; this build strength-reduces both into
 * pointers, which shifts the register assignment. Retail also shares the 4/8 queue call with
 * the depth-sorted call and keeps the screen-space call separate. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cCamManager.h"

extern int PostInc_D_00566E10_0015B0F0_15B0F0(int a0);
extern void func_0030A548(void *dst, void *src);
extern void sceVu0RotTransPers(int *dst, float (*m)[4], float *src, int mode);
extern void sceVu0FTOI4Vector(void *a0, void *a1);
extern void func_0031A600(char *a0, int a1, int a2, int a3);
extern int D_003C1180;
extern int D_00586B80;
extern char D_00754C80[];

#define GP_RGBAQ(c, q) \
    ((unsigned long)((c) & 0xFF) | (unsigned long)((c) >> 8 & 0xFF) << 8 | \
     (unsigned long)((c) >> 16 & 0xFF) << 16 | (unsigned long)((c) >> 24 & 0xFF) << 24 | \
     (unsigned long)(q) << 32)
#define GP_XYZ(x, y, z) \
    ((unsigned long)(x) | (unsigned long)(y) << 16 | (unsigned long)(z) << 32)

/* Builds a Gouraud-shaded quad strip packet from four vertices and four colours and queues it.
 * With screen == 0 the vertices are projected through the current camera; otherwise they are
 * already screen positions, offset to the GS drawing area. */
__attribute__((section(".text.Gp_draw_polyG4")))
void *Gp_draw_polyG4(void *verts, unsigned int *colors, int screen, int colorNo, int fontNo)
{
    float mtx[4][4];
    int xy[4][4];
    unsigned long *pkt;
    float (*v)[4] = verts;
    float one;
    int i;
    int prio;

    pkt = (unsigned long *)PostInc_D_00566E10_0015B0F0_15B0F0(0xE0);
    if (pkt == 0) {
        return 0;
    }
    pkt[0] = 0x1000000D;
    ((int *)pkt)[2] = 0x11000000;
    ((int *)pkt)[3] = 0x5000000D;
    pkt[2] = 0x3000000000000001;
    pkt[3] = 0xEEE;
    pkt[4] = 0xFF;
    pkt[5] = 0x3F;
    pkt[6] = 0x8000000044;
    pkt[7] = 0x42;
    pkt[8] = 0x50000;
    pkt[9] = 0x47;
    if (screen == 0) {
        func_0030A548(mtx, D_005CAFF0);
        for (i = 4; i != 0; i--) {
            sceVu0RotTransPers(xy[i - 1], mtx, v[i - 1], 0);
        }
    } else {
        for (i = 4; i != 0; i--) {
            sceVu0FTOI4Vector(xy[i - 1], v[i - 1]);
            xy[i - 1][0] += (0x800 - D_003C1180 / 2) << 4;
            xy[i - 1][1] += D_00586B80 << 4;
        }
    }
    one = 1.0f;
    pkt[11] = 0xE;
    pkt[10] = 0x1026400000008008;
    pkt[13] = 1;
    pkt[12] = GP_RGBAQ(*colors, *(unsigned int *)&one);
    colors++;
    pkt[17] = 1;
    pkt[16] = GP_RGBAQ(*colors, *(unsigned int *)&one);
    colors++;
    pkt[21] = 1;
    pkt[20] = GP_RGBAQ(*colors, *(unsigned int *)&one);
    colors++;
    pkt[25] = 1;
    pkt[24] = GP_RGBAQ(*colors, *(unsigned int *)&one);
    prio = ((0x400 - (xy[0][2] >> 8)) & 0xFFF) + 0x32;
    pkt[14] = GP_XYZ(xy[0][0], xy[0][1], xy[0][2] >> 4);
    pkt[15] = 0xD;
    pkt[19] = 5;
    pkt[18] = GP_XYZ(xy[1][0], xy[1][1], xy[1][2] >> 4);
    pkt[23] = 5;
    pkt[22] = GP_XYZ(xy[2][0], xy[2][1], xy[2][2] >> 4);
    pkt[26] = GP_XYZ(xy[3][0], xy[3][1], xy[3][2] >> 4);
    pkt[27] = 5;
    if (prio >= 0x400) {
        prio = 0x3FF;
    }
    if (colorNo == 4 || colorNo == 8) {
        prio = fontNo;
    } else if (screen != 0) {
        func_0031A600(D_00754C80, colorNo, fontNo, (int)pkt);
        return pkt;
    } else if (prio <= 0) {
        return pkt;
    }
    func_0031A600(D_00754C80, colorNo, prio, (int)pkt);
    return pkt;
}
#else
INCLUDE_ASM("asm/nonmatching", Gp_draw_polyG4);
#endif
