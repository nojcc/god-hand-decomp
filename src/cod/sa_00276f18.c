#include "godhand/vec.h"
typedef struct {
    unsigned char b0, b1, b2, b3;
    float scale;
    float f8;
    float fC;
    Vec4f v1;
    Vec4f v2;
} Ent30;

extern Ent30 D_005850C0[];
extern void *func_003A52F0(void *, int, int);

static inline void setV4(Vec4f *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

static inline void setEnt(Ent30 *e, int id, int half, float x)
{
    func_003A52F0(e, 0, 0x30);
    e->b2 = id;
    e->b3 = id + half;
    e->scale = half ? 0.5f : 1.0f;
    e->f8 = 0.15f;
    setV4(&e->v1, x, 0.0f, 0.0f, 1.0f);
    setV4(&e->v2, x, 0.0f, 0.0f, 1.0f);
}

__attribute__((section(".text.func_00276F18")))
void func_00276F18(int a, int b)
{
    Ent30 *e;

    if (b != 0xFFFF || a == 0)
        return;
    e = D_005850C0;
    setEnt(e, 2, 0, -0.08f);
    e++;
    setEnt(e, 2, 0, 0.08f);
    e++;
    setEnt(e, 1, 0, -0.08f);
    e++;
    setEnt(e, 1, 0, 0.08f);
    e++;
    setEnt(e, 0x12, 0, 0.0f);
    e++;
    setEnt(e, 0x12, 1, 0.0f);
    e++;
    setEnt(e, 0x16, 0, 0.0f);
    e++;
    setEnt(e, 0x16, 1, 0.0f);
}
