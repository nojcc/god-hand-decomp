/* NON_MATCHING func_0015ADA0: rotate a vector by a quaternion, q * (v, 0) * conj(q).
* Instruction sequence and stack temporaries match
only the FP register numbering of the copied quaternion differs (retail x/y/z/w in f9/f10/f12/f11, this gives f10/f9/f11/f12). */
#include "include_asm.h"
#include "godhand/cOmBase.h"

#ifdef NON_MATCHING
static inline void QuatMul15ADA0(cVec *r, cVec *a, cVec *b)
{
    r->x = a->y * b->z - a->z * b->y + a->x * b->w + a->w * b->x;
    r->y = a->z * b->x - a->x * b->z + a->y * b->w + a->w * b->y;
    r->z = a->x * b->y - a->y * b->x + a->z * b->w + a->w * b->z;
    r->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
}

__attribute__((section(".text.func_0015ADA0")))
cVec *func_0015ADA0(cVec *out, cVec *q, cVec *v)
{
    cVec r;
    cVec t;
    cVec vq;
    cVec c;
    cVec qq;

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
