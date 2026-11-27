/* func_002C0C28: 1 insn under -ffast-math + fdiv (the flags of 002c0cb0.c, its
 * 3D twin): retail repeats daddu v0,0 in the last bc1t delay slot, our reorg
 * drops it as redundant and leaves a nop. func_002C0B38, its quad twin, is matched
 * on main (HitNode_containsQuadPoint). */
#include "include_asm.h"
#include "godhand/cObjSimple.h"

#ifdef NON_MATCHING

typedef struct HitCircle {
    float x, z;                 /* 0x00 */
    float r;                    /* 0x08 */
    char unk0C[0x20 - 0xC];
    float yMin;                 /* 0x20 */
    float yMax;                 /* 0x24 */
} HitCircle;


int func_002C0C28(HitCircle *c, cObjSimpleVec3 *p)
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
INCLUDE_ASM("asm/nonmatching", func_002C0C28);

#endif
