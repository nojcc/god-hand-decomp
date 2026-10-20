/* NON_MATCHING func_00283C70 (sn-2.95.3-136;
 * PARK, 108 diffs): retail keeps a second copy of the constant 2 in $s2 for
 * entry 1 (0x70 frame); ours shares $s1, so the frame is 0x60 and everything after the prologue shifts. */
#include "godhand/vec.h"
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Ent283C70 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;                   /* 0x02 */
    unsigned char b3;                   /* 0x03 */
    float f4;                           /* 0x04 */
    float f8;                           /* 0x08 */
    float fC;
    Vec4f a;                        /* 0x10 */
    Vec4f b;                        /* 0x20 */
} Ent283C70;

extern Ent283C70 D_00585660[4];
extern void *func_003A52F0(void *d, int c, unsigned int n);

static inline void SetVec(Vec4f *v, float x, float y)
{
    v->y = y;
    v->w = 1.0f;
    v->z = 0.055f;
}

static inline void InitEnt(Ent283C70 *e, float x, float y)
{
    func_003A52F0(e, 0, sizeof(Ent283C70));
    e->b3 = 2;
    e->b2 = 2;
    e->f4 = 1.0f;
    e->f8 = 0.3f;
    e->a.x = x;
    SetVec(&e->a, x, y);
    e->b.x = x;
    SetVec(&e->b, x, y);
}

__attribute__((section(".text.func_00283C70")))
void func_00283C70(int on, int id)
{
    Ent283C70 *e;

    if (id != 0xFFFF || on == 0)
        return;
    e = D_00585660;
    InitEnt(e, -0.08f, 0.1f);
    e++;
    InitEnt(e, 0.08f, 0.1f);
    e++;
    InitEnt(e, -0.08f, 0.0f);
    e++;
    InitEnt(e, 0.08f, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00283C70);
#endif
