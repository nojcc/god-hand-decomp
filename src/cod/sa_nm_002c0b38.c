/* NM, not registered. sn-2.95.3-136: collision hit shapes, XZ quad and circle with a Y band (0x2C0B38..).
 * func_002C0C28: 1 insn under -ffast-math + fdiv (the flags of 002c0cb0.c, its
 *   3D twin): retail repeats daddu v0,0 in the last bc1t delay slot, our reorg
 *   drops it as redundant and leaves a nop.
 * func_002C0B38: 27 insns, FP register choice (retail x0/z0 in f9/f6, dz f5)
 *   and the last test branching to its own return-0 block. */
#include "include_asm.h"

#ifdef NON_MATCHING

extern float sqrtf(float x);

typedef struct HitPos {
    float x;                    /* 0x0 */
    float y;                    /* 0x4 */
    float z;                    /* 0x8 */
} HitPos;

typedef struct HitQuad {
    float x0, z0;               /* 0x00 */
    float x1, z1;               /* 0x08 */
    float x2, z2;               /* 0x10 */
    float x3, z3;               /* 0x18 */
    float yMin;                 /* 0x20 */
    float yMax;                 /* 0x24 */
} HitQuad;

typedef struct HitCircle {
    float x, z;                 /* 0x00 */
    float r;                    /* 0x08 */
    char unk0C[0x20 - 0xC];
    float yMin;                 /* 0x20 */
    float yMax;                 /* 0x24 */
} HitCircle;

int func_002C0B38(HitQuad *q, HitPos *p)
{
    float x0, z0, dx, dz, ax, az, bx, bz, cx, cz;

    if (p->y < q->yMin) {
        return 0;
    }
    if (q->yMax < p->y) {
        return 0;
    }
    x0 = q->x0;
    z0 = q->z0;
    dx = p->x - x0;
    dz = p->z - z0;
    ax = q->x1 - x0;
    az = q->z1 - z0;
    bx = q->x3 - x0;
    bz = q->z3 - z0;
    if (ax * dz > az * dx) {
        return 0;
    }
    if (bz * dx > bx * dz) {
        return 0;
    }
    cz = q->z2 - z0;
    cx = q->x2 - x0;
    dx -= cx;
    dz -= cz;
    ax -= cx;
    az -= cz;
    bx -= cx;
    bz -= cz;
    if (az * dx > ax * dz) {
        return 0;
    }
    if (bx * dz > bz * dx) {
        return 0;
    }
    return 1;
}

int func_002C0C28(HitCircle *c, HitPos *p)
{
    float dx, dz;

    if (p->y < c->yMin) {
        return 0;
    }
    if (c->yMax < p->y) {
        return 0;
    }
    dx = p->x - c->x;
    dz = p->z - c->z;
    if (c->r < __builtin_sqrtf(dx * dx + dz * dz)) {
        return 0;
    } else {
        return 1;
    }
}

#else

INCLUDE_ASM("asm/nonmatching", func_002C0B38);
INCLUDE_ASM("asm/nonmatching", func_002C0C28);

#endif
