/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/vu0.h"
#include "godhand/cObj21C0.h"

#ifdef NON_MATCHING
/* The constructor: the cGameObj base, the vtable D_00447F70, the 44 records
 * and the vector at 0x2190. */
static __inline__ void cObj21C0_construct(cObj21C0 *self)
{
    cObj21C0Ent *e;
    int i;

    cGameObj(self);
    self->vt = D_00447F70;
    e = self->ent;
    for (i = 0; i < COBJ21C0_ENT_NUM; i++, e++) {
        VU0_SQC2_VF0_AT(e->unk00);
        VU0_SQC2_VF0_AT(e->unk10);
        VU0_SQC2_VF0_AT(e->unk30);
        VU0_SQC2_VF0_AT(e->unk40);
        VU0_SQC2_VF0_AT(e->unk50);
        VU0_SQC2_VF0_AT(e->unk80);
    }
    VU0_SQC2_VF0_AT(self->unk2190);
}

/* Allocate a cObj21C0 from the D_00754220 arena, clear it and construct it;
 * 0 while the allocator is locked or the arena is full.
 * Still differs from retail: retail constructs through a copy of the pointer
 * in a second saved register and counts the records down to -1 (the C++
 * array constructor); this loop counts down to 0 with bgez. */
__attribute__((section(".text.func_003132D0")))
cObj21C0 *func_003132D0(void)
{
    cObj21C0 *self;

    if (!(D_00747A34 & COBJ21C0_NO_NEW)) {
        self = EnsureInitThenForward_2A9538_30EE08(COBJ21C0_SIZE, COBJ21C0_ALIGN, D_00754220);
        if (self != 0) {
            func_003A52F0(self, 0, COBJ21C0_SIZE);
            cObj21C0_construct(self);
            return self;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_003132D0);
#endif
