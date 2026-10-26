/* sn-2.95.3-136 */
/* func_001067B8 (camera sphere push-out, fp_hazard_rules fdiv,sqrt): retail takes the first
 * length with the checked sqrtf expansion (sqrt.s, NaN test, sqrtf call) and the second, the
 * distance to the sphere, with a bare sqrt.s; C has no spelling for the bare one (it waits for
 * an fpu.h macro), so this draft uses the checked form twice. The early return also lays out
 * differently. */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern float sqrtf(float x);
extern float capVu0LengthSq(void *a0);
extern float capVu0Acos(float x);
extern void sceVu0OuterProduct(void *a0, void *a1, void *a2);
extern void func_0015AF30(float out[4][4], float *dir, float *pos, float roll);
extern float D_003BD880[];

/* One sphere the camera is kept out of. */
typedef struct CamSphere {
    char unk00[0x90];
    float pos[3];                       /* 0x90 */
    char unk9C[0xB0 - 0x9C];
    float radius;                       /* 0xB0 */
    char unkB4[0xC0 - 0xB4];
} CamSphere;

typedef struct CamSphereList {
    unsigned int num;
    CamSphere *sphere;
} CamSphereList;

/* Pushes pos out of every sphere it is inside, swinging it around center at the same distance
 * when it can, else straight out from the sphere. Returns 1 if it moved. */
__attribute__((section(".text.func_001067B8")))
int func_001067B8(cVec *pos, cVec *center, CamSphereList *list)
{
    float mtx[4][4];
    cVec d;
    cVec e;
    cVec axis;
    cVec ret;
    cVec tmp;
    CamSphere *s;
    unsigned int i;
    int moved;
    float len;
    float r2;
    float dist;
    float ang;

    cVec_zero(&d);
    cVec_zero(&e);
    cVec_zero(&axis);
    if (list == 0)
        return 0;
    VU0_ZERO_VSUB_XYZ_TO(&tmp, 0, pos, center);
    VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
    len = __builtin_sqrtf(capVu0LengthSq(&ret));
    s = list->sphere;
    moved = 0;
    for (i = 0; i < list->num; i++, s++) {
        d.x = pos->x - s->pos[0];
        d.y = pos->y - s->pos[1];
        d.z = pos->z - s->pos[2];
        r2 = s->radius * s->radius;
        if (d.x * d.x + d.y * d.y + d.z * d.z < r2) {
            d.x = s->pos[0] - center->x;
            d.y = s->pos[1] - center->y;
            d.z = s->pos[2] - center->z;
            dist = __builtin_sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
            ang = capVu0Acos((r2 - len * len - dist * dist) / (len * -2.0f * dist));
            if (ang > 0.01f && ang < 3.1315928f) {
                e.x = pos->x - center->x;
                e.y = pos->y - center->y;
                e.z = pos->z - center->z;
                sceVu0OuterProduct(&axis, &d, &e);
                func_0015AF30(mtx, (float *)&axis, D_003BD880, ang);
                cVec_unitOf(&tmp, &d);
                VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
                cVec_copy3(&d, &ret);
                VU0_VSCALE_XYZ_MEM(&d, 0, len);
                sceVu0ApplyMatrix(&d, mtx, &d);
                pos->x = center->x + d.x;
                pos->y = center->y + d.y;
                pos->z = center->z + d.z;
            } else {
                cVec_unitOf(&tmp, &d);
                VU0_LQC2_SQC2_MEM(4, &ret, &tmp);
                cVec_copy3(&d, &ret);
                VU0_VSCALE_XYZ_MEM(&d, 0, s->radius + 1.0f);
                pos->x = s->pos[0] + d.x;
                pos->y = s->pos[1] + d.y;
                pos->z = s->pos[2] + d.z;
            }
            moved = 1;
        }
    }
    return moved;
}

#else
INCLUDE_ASM("asm/nonmatching", func_001067B8);
#endif
