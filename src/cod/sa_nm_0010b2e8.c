/* NON_MATCHING func_0010B2E8 (sn-2.95.3-136; PARK, 159 diffs): 5-slot busy check (f564 0x2A2/0x2A5 -> 0, motion
 * ranges -> 1). Retail's last slot gets different regs and owns the shared return blocks, so the source is
 * probably not 5 identical copies; the bool range test must stay branchy (no movn). */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x2FE];
    unsigned short f2FE;
    char pad300[0x564 - 0x300];
    int f564;
} Obj10B2;

typedef struct {
    char pad0[0x34];
    Obj10B2 *f34;
} Ent10B2;

typedef struct {
    Ent10B2 *e;
    int pad;
} Slot10B2;

typedef struct {
    char pad0[0x5B0];
    Slot10B2 slot[5];
} Self10B2;

static inline unsigned char inRange200(int h)
{
    if (h < 0x200)
        return 0;
    return h < 0x300;
}

#define CHECK(i)                                        \
    o = self->slot[i].e->f34;                           \
    if (o != 0) {                                       \
        if (flag)                                       \
            return 1;                                   \
        if (o->f564 == 0x2A2 || o->f564 == 0x2A5)       \
            return 0;                                   \
        h = o->f2FE;                                    \
        if (inRange200(h))                              \
            return 1;                                   \
        switch (h) {                                    \
        case 0x31F:                                     \
        case 0x359:                                     \
        case 0x35A:                                     \
        case 0x35D:                                     \
        case 0x3B3:                                     \
        case 0x440:                                     \
            return 1;                                   \
        }                                               \
    }

__attribute__((section(".text.func_0010B2E8")))
int func_0010B2E8(Self10B2 *self, int flag)
{
    Obj10B2 *o;
    int h;

    CHECK(0)
    CHECK(1)
    CHECK(2)
    CHECK(3)
    CHECK(4)
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0010B2E8);
#endif
