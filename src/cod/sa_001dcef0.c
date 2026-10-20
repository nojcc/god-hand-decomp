/* sn-2.95.3-136: static initializer (priority 0xFFFF) for two vectors, a five entry row of
 * offsets at D_00568170 and a two entry row at D_005681C0. */
#include "godhand/vec.h"
extern Vec4f D_00568150;
extern Vec4f D_00568160;
extern Vec4f D_00568170[5];
extern Vec4f D_005681C0[2];

static inline void setVec4(Vec4f *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

__attribute__((section(".text.func_001DCEF0")))
void func_001DCEF0(int owner, int code)
{
    Vec4f *p;
    Vec4f *q;

    if (code != 0xFFFF || owner == 0)
        return;
    setVec4(&D_00568150, 0.0f, 0.0f, 0.0f, 1.0f);
    setVec4(&D_00568160, 0.238f, 0.184f, 0.0f, 1.0f);
    p = D_00568170;
    setVec4(p, -0.278f, 0.024f, 0.0f, 1.0f);
    p++;
    setVec4(p, -0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    setVec4(p, 0.0f, 0.024f, 0.0f, 1.0f);
    p++;
    setVec4(p, 0.139f, 0.024f, 0.0f, 1.0f);
    p++;
    setVec4(p, 0.278f, 0.024f, 0.0f, 1.0f);
    q = D_005681C0;
    setVec4(q, -0.1112f, 0.024f, 0.0f, 1.0f);
    q++;
    setVec4(q, 0.1112f, 0.024f, 0.0f, 1.0f);
}
