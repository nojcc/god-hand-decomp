/* NON_MATCHING func_001B7568 (sn): 41 diffs (1 real): inrange() inline gives slti a3 direct; retail slti v0 + daddu a3,v0 copy (shifts all following by 1) */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct { char pad[0x2FE]; unsigned short kind; } Obj1B7568;
typedef struct {
    char pad0[0x34];
    Obj1B7568 *obj;
    char pad38[0x0E];
    short type;
    char pad48[4];
    int power;
} Hit1B7568;
typedef struct { char pad[0x5B4]; int flags; } Self1B7568;

static inline int inrange(int v)
{
    if (v < 0x100) return 0;
    if (v < 0x1FF) return 1;
    return 0;
}

void func_001B7568(Self1B7568 *s, Hit1B7568 *h)
{
    short t = h->type;
    int k;

    if (t < 0x30) {
        if (t >= 0x2E)
            s->flags |= 1;
    }
    if ((unsigned int)(t - 7) >= 2) {
        if (t != 0x15 && t != 0x13 && t != 0x18 && t != 0x1C && t != 0x21 && t != 0x22
            && t != 0x29 && t != 0x2A && t != 0x2B && t != 0x31 && h->obj != 0) {
            k = inrange(h->obj->kind);
            if (k == 1 && h->power >= 0xB)
                s->flags |= 2;
        }
    }
    if ((unsigned int)(t - 8) < 4 || t == 0x1C || t == 0x30 || t == 0x52)
        s->flags |= 4;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001B7568);
#endif
