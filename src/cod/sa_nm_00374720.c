/* NON_MATCHING func_00374720 (sn-2.95.3-136, as=sn): 59 insns, 52 words vs 63. Retail copies self to a2 (a0 becomes the loop counter), leaves the first bne delay slot empty, strength-reduces only the spd pointer and recomputes &tgt (self + 0x1C) in every branch. An inline per-element helper is closest. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int on;
    char pad04[8];
    int n;
    char pad10[0xC];
    float tgt[2];
    float spd[2];
    char pad2C[8];
    float spdDown;
    float spdUp;
} Fader;

static inline void Fader_set(Fader *self, int i, float f, float g)
{
    if (g == 0.0f) {
        if (f <= self->tgt[i]) {
            g = self->spdUp;
        } else {
            g = self->spdDown;
        }
    }
    self->spd[i] = g;
    self->tgt[i] = f;
}

void func_00374720(Fader *self, float f, float g, int idx)
{
    int i;

    if (self->on == 0) {
        return;
    }
    if (idx == -1) {
        for (i = 0; i < self->n; i++) {
            Fader_set(self, i, f, g);
        }
        return;
    }
    Fader_set(self, idx, f, g);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00374720);
#endif
