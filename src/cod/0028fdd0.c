/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArena.h"
#include "godhand/typeInfo.h"

extern int D_00451038;
extern int D_007861D8;
extern int D_0044A750;
extern int D_007854D8;
extern void cGameObj__tf(void);
extern void SetField_0_4_8_31EEA8(int *, int *, int *);

__attribute__((section(".text.func_0031EE10")))
void func_0031EE10(TypeInfo *self, int flags) {
    self->vtable = &D_00451038;
    if (flags & 1) {
        __builtin_delete(self);
    }
}

__attribute__((section(".text.func_0028FDD0")))
void *func_0028FDD0(void) {
    if (D_007861D8 == 0) {
        cGameObj__tf();
        SetField_0_4_8_31EEA8(&D_007861D8, &D_0044A750, &D_007854D8);
    }
    return &D_007861D8;
}
