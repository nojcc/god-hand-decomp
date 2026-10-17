/* NM, not registered. sn-2.95.3-136, -ffast-math, fp_hazard_rules sqrt: scaled twin of func_001F8550 (0x1F8810).
 * Instructions match except cc1 emits .p2align 3 before the return-0 label, padding one nop at
 * 0x7C; retail has that label unaligned at 0x1F888C. goto-free variants regress (35 diffs). */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/cArea.h"

/* Scaled variant: the probe height and the centre are scaled by `scale` before the same
 * height-band and XZ radius test. */
__attribute__((section(".text.func_001F8810")))
int func_001F8810(cArea *self, float *pt, float scale) {
    float y = self->y;
    float py = pt[1] * scale;
    float h = self->height;
    float t, dx, dz, d;
    int r;
    t = y + h;
    if (py < y) goto zero;
    r = 0;
    if (t < py) goto ret;
    dx = pt[0] - self->corner[0].x * scale;
    dz = pt[2] - self->corner[0].z * scale;
    d = __builtin_sqrtf(dx * dx + dz * dz);
    do { } while (0);
    r = 1;
    if (d < self->radius) goto ret;
zero:
    return 0;
ret:
    return r;
}

#else
INCLUDE_ASM("asm/nonmatching", func_001F8810);
#endif
