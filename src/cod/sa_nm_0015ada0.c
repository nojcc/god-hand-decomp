/* NON_MATCHING func_0015ADA0 (sn-2.95.3-136; PARK at attempt 3, score 62): rotate a vector by a quaternion, q * (v, 0) * conj(q). Instruction sequence and stack temporaries match; only the FP register numbering of the copied quaternion differs (retail x/y/z/w in f9/f10/f12/f11, this gives f10/f9/f11/f12). Statement orders, conj-from-q, an inline conj helper and helper argument order were tried and did not move it. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Quat15ADA0 {
    float x, y, z, w;
} Quat15ADA0;

static inline void QuatMul15ADA0(Quat15ADA0 *r, Quat15ADA0 *a, Quat15ADA0 *b)
{
    r->x = a->y * b->z - a->z * b->y + a->x * b->w + a->w * b->x;
    r->y = a->z * b->x - a->x * b->z + a->y * b->w + a->w * b->y;
    r->z = a->x * b->y - a->y * b->x + a->z * b->w + a->w * b->z;
    r->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
}

__attribute__((section(".text.func_0015ADA0")))
Quat15ADA0 *func_0015ADA0(Quat15ADA0 *out, Quat15ADA0 *q, Quat15ADA0 *v)
{
    Quat15ADA0 r;
    Quat15ADA0 t;
    Quat15ADA0 vq;
    Quat15ADA0 c;
    Quat15ADA0 qq;

    vq.x = v->x;
    vq.y = v->y;
    vq.z = v->z;
    vq.w = 0.0f;
    qq.x = q->x;
    qq.y = q->y;
    qq.z = q->z;
    qq.w = q->w;
    c.x = -qq.x;
    c.y = -qq.y;
    c.z = -qq.z;
    c.w = qq.w;
    QuatMul15ADA0(&t, &qq, &vq);
    QuatMul15ADA0(&r, &t, &c);
    out->x = r.x;
    out->y = r.y;
    out->z = r.z;
    out->w = 1.0f;
    return out;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015ADA0);
#endif
