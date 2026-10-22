/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 149 vs 157 words. Retail stores the corners' z from an FPU
 * zero, reloads the screen globals after the vertex x store, and keeps the
 * left-edge count spilled on the stack; register allocation differs throughout.
 */
#include "include_asm.h"
#include "godhand/cNode.h"
#include "godhand/sceVu0.h"


#ifdef NON_MATCHING
extern float *func_002B6328(cNode *node);
extern void MtxCopy(float *dst, float *src);

extern int D_003C1180;                  /* screen width */
extern int D_003C118C;                  /* screen height */
extern int D_00586B80;                  /* screen top in GS pixels */
extern cVec D_0061B7A8;

/* A node drawn as a unit-high quad: width, and the pivot as a fraction of each side. */
typedef struct cQuadNode {
    cNode node;
    char unkF4[0x210 - 0xF4];
    float width;                        /* 0x210 */
    float pivotX;                       /* 0x214 */
    float pivotY;                       /* 0x218 */
} cQuadNode;

/* One GS vertex: 12.4 fixed-point x and y, depth, and a flag. */
typedef struct QuadVtx {
    int x, y, z, w;
} QuadVtx;

/* Project the node's quad to GS coordinates; -1 if a corner leaves the GS
 * range or the whole quad is off one side of the screen. */
__attribute__((section(".text.func_002FE8A0")))
int func_002FE8A0(cQuadNode *self, QuadVtx *vtx)
{
    cVec v[4];
    float m[16];
    int i;
    int left, right, top, bottom;
    int x, y;

    v[0].x = -self->pivotX * self->width;
    v[0].y = -self->pivotY;
    v[0].z = 0.0f;
    v[0].w = 1.0f;
    v[1].x = (1.0f - self->pivotX) * self->width;
    v[1].y = -self->pivotY;
    v[1].z = 0.0f;
    v[1].w = 1.0f;
    v[2].x = -self->pivotX * self->width;
    v[2].y = 1.0f - self->pivotY;
    v[2].z = 0.0f;
    v[2].w = 1.0f;
    v[3].x = (1.0f - self->pivotX) * self->width;
    v[3].y = 1.0f - self->pivotY;
    v[3].z = 0.0f;
    v[3].w = 1.0f;
    MtxCopy(m, func_002B6328(&self->node));
    left = right = top = bottom = 0;
    for (i = 3; i >= 0; i--) {
        sceVu0ApplyMatrix(&v[i], m, &v[i]);
        x = (int)(v[i].x * 16.0f) + ((0x800 - D_003C1180 / 2) << 4);
        y = (int)(v[i].y * 16.0f) + (D_00586B80 << 4);
        vtx[i].x = x;
        vtx[i].y = y;
        if ((unsigned int)(x - 0xA0) > 0xFEC0 || (unsigned int)(y - 0xA0) > 0xFEC0) {
            return -1;
        }
        vtx[i].z = 0xFFF00;
        vtx[i].w = 1;
        left += x < ((0x800 - D_003C1180 / 2) << 4);
        right += ((D_003C1180 + 0x800 - D_003C1180 / 2) << 4) < x;
        top += y < (D_00586B80 << 4);
        bottom += ((D_00586B80 + D_003C118C) << 4) < y;
    }
    if (left == 4 || right == 4 || top == 4 || bottom == 4) {
        return -1;
    }
    D_0061B7A8.x = 1.0f;
    D_0061B7A8.y = 1.0f;
    D_0061B7A8.z = 1.0f;
    D_0061B7A8.w = 1.0f;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002FE8A0);
#endif
