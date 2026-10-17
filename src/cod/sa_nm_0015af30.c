/* NON_MATCHING func_0015AF30 (NEAR-MISS): sn + -ffast-math + fp_hazard_rules sqrt; 17 diffs, tail: &v (sp+0x80) is CSE'd into s0 across sceVu0ApplyMatrix where retail rematerializes it (inv's address is CSE'd in both); block scope, pointer alias, -fno-gcse tried */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef float Mtx15AF30[4][4];
typedef float Vec15AF30[4];

extern float D_003C3C40[4][4];
extern float capVu0Atan2(float y, float x);
extern float sqrtf(float x);
extern void func_0030A650(void *dst, void *src, float rx);
extern void func_0030A7B8(void *dst, void *src, float ry);
extern void func_0030A700(void *dst, void *src, float rz);
extern void func_0030A2E0(void *dst, void *a, void *b);
extern void sceVu0TransposeMatrix(void *dst, void *src);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void sceVu0SubVector(void *v0, void *v1, void *v2);

void func_0015AF30(Mtx15AF30 out, float *dir, float *pos, float roll)
{
    Mtx15AF30 m;
    Mtx15AF30 inv;
    Vec15AF30 v;
    float a;

    if (dir[0] == 0.0f && dir[2] == 0.0f) {
        a = -capVu0Atan2(dir[1], 0.0f);
        func_0030A650(m, D_003C3C40, a);
    } else {
        a = capVu0Atan2(dir[2], dir[0]);
        func_0030A7B8(m, D_003C3C40, a);
        a = -capVu0Atan2(dir[1], __builtin_sqrtf(dir[0] * dir[0] + dir[2] * dir[2]));
        func_0030A650(m, m, a);
    }
    sceVu0TransposeMatrix(inv, m);
    func_0030A700(m, m, roll);
    func_0030A2E0(out, inv, m);
    sceVu0ApplyMatrix(v, out, pos);
    sceVu0SubVector(out[3], pos, v);
    out[3][3] = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0015AF30);
#endif
