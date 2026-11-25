#include "godhand/cModel.h"
#include "godhand/vu0.h"
#include "godhand/vtables.h"
#include "godhand/globals.h"

/* func_0017EC08 — object constructor: InitFields_1B6E90 base, set vtable at 0x214,
 * zero 0 quadword(s), return the object.  sn-2.95.3-136. */

extern void InitFields_1B6E90(void *);

__attribute__((section(".text.func_0017EC08")))
void *func_0017EC08(void *a0) {
    InitFields_1B6E90(a0);
    *(cVtEnt **)((char *)a0 + 0x214) = (cVtEnt *)&D_00422240;
    return a0;
}
