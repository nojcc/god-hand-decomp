/* NON_MATCHING func_001A6FB0: inlined parts[] range check: retail keeps branchy slt-vs-zero-reg + andi 0xFF, sn emits movn/movz; also two IVs for vel[i] (a2-0x84 and a3) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Pos1A6FB0 {
    float x;
    float y;
    float z;
} Pos1A6FB0;

typedef struct Part1A6FB0 {
    char pad000[0xD0];
    Pos1A6FB0 *pos;
} Part1A6FB0;

typedef struct Obj1A6FB0 {
    char pad000[0x278];
    Part1A6FB0 **parts;
    char pad27C[0x2B4 - 0x27C];
    unsigned char nparts;
    char pad2B5[0x640 - 0x2B5];
    float vel[33];
    float prev[33];
    unsigned char moved[32];
    unsigned char dirty;
} Obj1A6FB0;

static inline unsigned char InRange1A6FB0(int i, int n)
{
    unsigned char ok = 0;
    if (i >= 0 && i < n) {
        ok = 1;
    }
    return ok;
}

static inline Part1A6FB0 *Obj1A6FB0_part(Obj1A6FB0 *self, int i)
{
    char hold[16];
    int n = self->nparts;

    *(int *)hold = n;
    if (InRange1A6FB0(i, n)) {
        return self->parts[i];
    }
    return 0;
}

void func_001A6FB0(Obj1A6FB0 *self)
{
    unsigned int i;
    Part1A6FB0 *p;
    float d;

    for (i = 1; i < 32; i++) {
        p = Obj1A6FB0_part(self, i);
        if (p != 0) {
            d = p->pos->z - self->prev[i];
            self->vel[i] = d;
            self->prev[i] = p->pos->z;
            if (p->pos->z > 0.0f) {
                self->vel[i] = d - 0.1f;
            }
            if (p->pos->z < 0.0f) {
                self->vel[i] += 0.1f;
            }
            p->pos->z += self->vel[i];
            p->pos->z = 0.0f;
            self->moved[i] = 0;
        }
    }
    self->dirty = 1;
    self->moved[0] = 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001A6FB0);
#endif
