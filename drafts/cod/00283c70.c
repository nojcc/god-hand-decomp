/* NON_MATCHING func_00283C70 (sn-2.95.3-136): retail keeps a second copy of the constant 2 in $s2 for
 * entry 1 (0x70 frame); ours shares $s1, so the frame is 0x60 and everything after the prologue shifts. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/criStm.h"

#ifdef NON_MATCHING
typedef struct SpawnEnt {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;                   /* 0x02 */
    unsigned char b3;                   /* 0x03 */
    float f4;                           /* 0x04 */
    float f8;                           /* 0x08 */
    float fC;
    cVec a;                        /* 0x10 */
    cVec b;                        /* 0x20 */
} SpawnEnt;

extern SpawnEnt D_00585660[4];

static inline void SetVec(cVec *v, float x, float y)
{
    v->y = y;
    v->w = 1.0f;
    v->z = 0.055f;
}

static inline void InitEnt(SpawnEnt *e, float x, float y)
{
    func_003A52F0(e, 0, sizeof(SpawnEnt));
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
    SpawnEnt *e;

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
