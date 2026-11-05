#include "godhand/vu0.h"
#include "godhand/cObjBase.h"

/* func_002717D0 — zero a stack vector, run func_00271518(a0, &vec), then
 * SetEffectPos(0, 0xB, 0, &vec, 1.0f, -1).  sn-2.95.3-136. */

extern void func_00271518(void *, void *);

__attribute__((section(".text.func_002717D0")))
void func_002717D0(void *a0) {
    unsigned char buf[16] __attribute__((aligned(16)));
    VU0_SQC2_VF0(buf, 0);
    func_00271518(a0, buf);
    SetEffectPos(0, 0xB, 0, (cVec *)buf, 1.0f, -1);
}
