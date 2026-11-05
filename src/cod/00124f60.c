/* SN ProDG ee-gcc 2.95.3 matched TU. */

#include "godhand/objField.h"
#include "godhand/cCamManager.h"
#include "godhand/rand.h"
extern void cPlCamera_setCamUpdate(void *a0);
extern void func_00150710(float a, float b, float c);

__attribute__((section(".text.pl00_clearMotionCam")))
void pl00_clearMotionCam(void *a0, int a1, int a2) {
    cCamManager *mgr;
    if (((a2 ^ 1) & 1) != 0) {
        int v1 = *(int*)((char*)a0 + 0x15F4);
        if ((v1 & 2) == 0) {
            return;
        }
        *(int*)((char*)a0 + 0x15F4) = v1 & ~2;
    }
    mgr = &D_00463050;
    if (mgr != 0) {
        cPlCamera_setCamUpdate(mgr);
    }
    cCamManager_setPlCamera(mgr, 0);
}

__attribute__((section(".text.fRand0_1")))
float fRand0_1(void) {
    return func_0030F518();
}

__attribute__((section(".text.ForwardVec3At30_147C60")))
void ForwardVec3At30_147C60(void *a0, float *a1) {
    func_00150710(a1[12], a1[13], a1[14]);
}
