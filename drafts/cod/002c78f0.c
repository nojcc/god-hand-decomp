/* sn-2.95.3-136 */
/* func_002C78F0 (rotated screen quad): the shape matches, but every pair of like
 * arguments takes the other register of its pair (x/y, w/h, tex/t3), and the address
 * of the vertex array is formed early. extern_jtbl D_0044C3D0. */
#include "include_asm.h"
#include "godhand/cOmBase.h"

#ifdef NON_MATCHING

/* The texture window handed to the polygon packer. */
typedef struct GpTexWin {
    int on;                             /* 0x00 */
    float u0;                           /* 0x04 */
    float v0;                           /* 0x08 */
    float u1;                           /* 0x0C */
    float v1;                           /* 0x10 */
    char unk14[0x3C];
} GpTexWin;

extern float capVu0Cos(float x);
extern float capVu0Sin(float x);
extern void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                             int t0, int t1, void *cfg, int t3, int extra);
extern float D_003C1184;
extern int D_003C11B0;

/* One corner of a screen quad. */
static __inline__ void gpCorner(cVec *v, float x, float y)
{
    v->x = x;
    v->y = y;
    v->z = 65535.0f;
    v->w = 1.0f;
}

/* Draw a textured screen quad of size w by h turned by rot, anchored at its centre (0) or
 * at one of its corners (1 to 4), squeezed toward the screen centre by scale. */
__attribute__((section(".text.func_002C78F0")))
void func_002C78F0(void *tex, unsigned int col, unsigned int anchor, int t3, int extra,
                   float x, float y, float w, float h, float rot,
                   float u0, float v0, float u1, float v1, float scale)
{
    cVec v[4];
    GpTexWin win;
    float c = capVu0Cos(rot);
    float s = capVu0Sin(rot);
    float vy = h * c;
    float vx = h * s;
    float uy = -w * s;
    float ux = w * c;
    int i;
    void *r;

    switch (anchor) {
    case 0:
        ux *= 0.5f;
        uy *= 0.5f;
        vy *= 0.5f;
        vx *= 0.5f;
        gpCorner(&v[0], x - ux + vx, y + uy - vy);
        gpCorner(&v[1], x + ux + vx, y - uy - vy);
        gpCorner(&v[2], x - ux - vx, y + uy + vy);
        gpCorner(&v[3], x + ux - vx, y - uy + vy);
        break;
    case 1:
        gpCorner(&v[0], x, y);
        gpCorner(&v[1], x + ux, y - uy);
        gpCorner(&v[2], x - vx, y + vy);
        gpCorner(&v[3], x + ux - vx, y - uy + vy);
        break;
    case 2:
        gpCorner(&v[0], x - ux, y + uy);
        gpCorner(&v[1], x, y);
        gpCorner(&v[2], x - ux - vx, y + uy + vy);
        gpCorner(&v[3], x - vx, y + vy);
        break;
    case 3:
        gpCorner(&v[0], x + vx, y - vy);
        gpCorner(&v[1], x + ux + vx, y - uy - vy);
        gpCorner(&v[2], x, y);
        gpCorner(&v[3], x + ux, y - uy);
        break;
    case 4:
        gpCorner(&v[0], x - ux + vx, y + uy - vy);
        gpCorner(&v[1], x + vx, y - vy);
        gpCorner(&v[2], x - ux, y + uy);
        gpCorner(&v[3], x, y);
        break;
    }
    for (i = 0; i < 4; i++)
        v[i].x = v[i].x * scale + D_003C1184 * (1.0f - scale) * 0.5f;
    win.on = 1;
    win.u0 = u0;
    win.v0 = v0;
    win.u1 = u1;
    win.v1 = v1;
    r = Gp_draw_polyFT4(v, col, 1, tex, D_003C11B0, 0x1CF0, &win, t3, extra);
    if (r != 0)
        *(long *)((char *)r + 0x1A0) = 0x3001D;
}

#else
INCLUDE_ASM("asm/nonmatching", func_002C78F0);
#endif
