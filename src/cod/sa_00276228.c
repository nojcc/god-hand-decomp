/* sn-2.95.3-136: func_00276228, move the model to pos: set the transform and cached positions, recalc the
 * parts, IK and world parts, then update every attached sub-model the same way. */
extern void cModel_calcParts(void *self);
extern void IK_InverseKinematics(void *ik, void *self);
extern void cModel_calcWorldParts(void *self);
extern void func_001CF3A8(void *self);
extern void func_001C2378(void *self);
extern void func_0027D300(void *self);
extern void func_0027E950(void *self);
extern void func_00280DB8(void *self);
extern void func_00283070(void *self);

#include "godhand/vecInline.h"

__attribute__((section(".text.func_00276228")))
void func_00276228(char *p, float *pos)
{
    vec3_copy(*(float **)(p + 0xF0), pos);
    vec3_copy((float *)(p + 0x490), pos);
    ((float *)(p + 0xB0))[0] = pos[0];
    ((float *)(p + 0xB0))[1] = pos[1];
    ((float *)(p + 0xB0))[2] = pos[2];
    cModel_calcParts(p);
    IK_InverseKinematics(p + 0x448, p);
    cModel_calcWorldParts(p);
    if (*(void **)(p + 0x6EC) != 0) {
        func_001CF3A8(*(void **)(p + 0x6EC));
        cModel_calcParts(*(void **)(p + 0x6EC));
    }
    if (*(void **)(p + 0x6F0) != 0) {
        func_001CF3A8(*(void **)(p + 0x6F0));
        cModel_calcParts(*(void **)(p + 0x6F0));
    }
    if (*(void **)(p + 0x6F8) != 0) {
        func_001CF3A8(*(void **)(p + 0x6F8));
        cModel_calcParts(*(void **)(p + 0x6F8));
    }
    if (*(void **)(p + 0x6FC) != 0) {
        func_001CF3A8(*(void **)(p + 0x6FC));
        cModel_calcParts(*(void **)(p + 0x6FC));
    }
    if (*(void **)(p + 0x700) != 0) {
        func_001CF3A8(*(void **)(p + 0x700));
        cModel_calcParts(*(void **)(p + 0x700));
    }
    if (*(void **)(p + 0x704) != 0) {
        func_001CF3A8(*(void **)(p + 0x704));
        cModel_calcParts(*(void **)(p + 0x704));
    }
    if (*(void **)(p + 0x708) != 0) {
        func_001CF3A8(*(void **)(p + 0x708));
        cModel_calcParts(*(void **)(p + 0x708));
    }
    if (*(void **)(p + 0x734) != 0) {
        func_001CF3A8(*(void **)(p + 0x734));
        cModel_calcParts(*(void **)(p + 0x734));
    }
    if (*(void **)(p + 0x6F4) != 0) {
        func_001CF3A8(*(void **)(p + 0x6F4));
        cModel_calcParts(*(void **)(p + 0x6F4));
    }
    if (*(void **)(p + 0x70C) != 0) {
        func_001C2378(*(void **)(p + 0x70C));
        cModel_calcParts(*(void **)(p + 0x70C));
    }
    if (*(void **)(p + 0x740) != 0) {
        func_0027D300(*(void **)(p + 0x740));
        cModel_calcParts(*(void **)(p + 0x740));
    }
    if (*(void **)(p + 0x744) != 0) {
        func_0027E950(*(void **)(p + 0x744));
        cModel_calcParts(*(void **)(p + 0x744));
    }
    if (*(void **)(p + 0x748) != 0) {
        func_00280DB8(*(void **)(p + 0x748));
        cModel_calcParts(*(void **)(p + 0x748));
    }
    if (*(void **)(p + 0x74C) != 0) {
        func_00283070(*(void **)(p + 0x74C));
        cModel_calcParts(*(void **)(p + 0x74C));
    }
    if (*(void **)(p + 0x750) != 0) {
        func_00283070(*(void **)(p + 0x750));
        cModel_calcParts(*(void **)(p + 0x750));
    }
}
