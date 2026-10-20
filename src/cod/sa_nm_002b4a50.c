/* NON_MATCHING func_002B4A50 (sn-2.95.3-136; PARK 86 at attempt 3, best of 3): update the three live entities of the manager; for a dead one with a pending slot, clear the slot and its bit in the mask, and once the mask is empty clear eight request bits in D_00747A80. Retail materialises the alive test as a 0/1 byte (bnez/li/andi 0xFF) and hoists all eight masks plus %hi(D_00747A80) out of the loop (caller-saving a1-a3/t0 around the call); ours threads the test and hoists six. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int alive;
    char pad4[0xAC - 4];
} Ent2B4A50;

typedef struct {
    Ent2B4A50 *ents;
    int slot[3];
    char pad10[4];
    unsigned char busy;
    char pad15[3];
    unsigned int mask;
} Mgr2B4A50;

extern unsigned int D_00747A80;
extern void func_002D3750(Ent2B4A50 *e);

static inline unsigned char isAlive2B4A50(Ent2B4A50 *e)
{
    return e->alive != 0;
}

void func_002B4A50(Mgr2B4A50 *m)
{
    int i;
    Ent2B4A50 *e;

    m->busy = 0;
    e = m->ents;
    for (i = 0; i < 3; i++, e++) {
        if (isAlive2B4A50(e)) {
            func_002D3750(e);
            m->busy = 1;
        } else if (m->slot[i] != 0) {
            m->slot[i] = 0;
            if (m->mask != 0) {
                m->mask &= ~(1 << i);
                if (m->mask == 0) {
                    D_00747A80 &= ~0x00800000;
                    D_00747A80 &= ~0x80000000;
                    D_00747A80 &= ~0x40000000;
                    D_00747A80 &= ~0x20000000;
                    D_00747A80 &= ~0x10000000;
                    D_00747A80 &= ~0x01000000;
                    D_00747A80 &= ~0x04000000;
                    D_00747A80 &= ~0x08000000;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002B4A50);
#endif
