/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDPanel.h"

extern char D_00463050[];
extern int cCamManager_setSubScrCamera();
extern int cCamManager_setPlCamera();
extern int cIDBase_release();

/* clone */


__attribute__((section(".text.func_001E7848")))
void func_001E7848(char *self, int n) { CustomIDWork_SetNumber(self + 0x1C4, n); }

/* clone */


__attribute__((section(".text.func_001E7868")))
void func_001E7868(char *self, int n) { CustomIDWork_SetNumber(self + 0x240, n); }

/* clone */


__attribute__((section(".text.func_001E7888")))
void func_001E7888(char *self, int n) { CustomIDWork_SetNumber(self + 0x2BC, n); }

/* clone */


__attribute__((section(".text.func_001E78A8")))
void func_001E78A8(char *self, int n) { CustomIDWork_SetNumber(self + 0x338, n); }

/* clone */


__attribute__((section(".text.func_001E78C8")))
void func_001E78C8(char *self, int n) { CustomIDWork_SetNumber(self + 0x3B4, n); }

/* clone */


__attribute__((section(".text.func_001E78E8")))
void func_001E78E8(char *self, int n) { CustomIDWork_SetNumber(self + 0x430, n); }

/* clone */



__attribute__((section(".text.func_001EB718")))
void func_001EB718(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(D_00463050, 0);
    *(int *)(a0 + 0x200) = (int)(D_00463050 + 0xC90);
    dst1 = (float *)(D_00463050 + 0xEA0);
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x200) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.func_001EB9F8")))
void func_001EB9F8(void) {
    cCamManager_setPlCamera(D_00463050, 0);
}

/* clone */


__attribute__((section(".text.func_001ECBD0")))
void func_001ECBD0(void *a0) { cIDBase_release((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001ED490")))
void func_001ED490(void *self, int n) { CustomIDWork_SetNumber((char *)self + 0x124C, n); }
