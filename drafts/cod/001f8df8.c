/* NON_MATCHING func_001F8DF8 (sn-2.95.3-136): 148 words vs 157. Retail writes each corner through its
 * own address register (only x at an sp offset), zeroes the matrix translation with mtc1/swc1 rather than
 * sw zero, and counts the corner loop up from 0; here every store folds to an sp offset and the loop
 * counts down. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cOmBase.h"
#include "godhand/cCamManager.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
extern void MtxCopy(void *dst, void *src);

/* An object's bounding box in model space: its centre and half extents. */
typedef struct cBoundBox {
    float center[3];                    /* 0x00 */
    float half[3];                      /* 0x0C */
} cBoundBox;

/* Whether any corner of box, placed by mtx and seen through the current camera, has depth within limit. */
__attribute__((section(".text.func_001F8DF8")))
int func_001F8DF8(cBoundBox *box, float *mtx, float limit)
{
    cVec c;
    cVec tmp;
    cVec w;
    float m[16];
    cVec pts[8];
    float near;
    cVec *p;
    int i;

    cVec_set4(&c, box->center[0], box->center[1], box->center[2], 1.0f);
    VU0_LQC2_SQC2_MEM(4, &w, &c);
    cVec_applyMatrix(&w, mtx);
    VU0_LQC2_SQC2_MEM(4, &tmp, &w);
    cVec_copy3(&c, &tmp);
    MtxCopy(m, mtx);
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    cVec_set4(&pts[0], -box->half[0], box->half[1], -box->half[2], 1.0f);
    cVec_set4(&pts[1], box->half[0], box->half[1], -box->half[2], 1.0f);
    cVec_set4(&pts[2], -box->half[0], box->half[1], box->half[2], 1.0f);
    cVec_set4(&pts[3], box->half[0], box->half[1], box->half[2], 1.0f);
    cVec_set4(&pts[4], -box->half[0], -box->half[1], -box->half[2], 1.0f);
    cVec_set4(&pts[5], box->half[0], -box->half[1], -box->half[2], 1.0f);
    cVec_set4(&pts[6], -box->half[0], -box->half[1], box->half[2], 1.0f);
    cVec_set4(&pts[7], box->half[0], -box->half[1], box->half[2], 1.0f);
    for (i = 0, p = pts; i < 8; i++, p++) {
        cVec_applyMatrix(p, m);
        VU0_VADD_XYZ_IP(p, 0, &c);
        sceVu0ApplyMatrix(p, D_005CAFF0, p);
    }
    near = pts[0].w;
    if (pts[1].w < near) near = pts[1].w;
    if (pts[2].w < near) near = pts[2].w;
    if (pts[3].w < near) near = pts[3].w;
    if (pts[4].w < near) near = pts[4].w;
    if (pts[5].w < near) near = pts[5].w;
    if (pts[6].w < near) near = pts[6].w;
    if (pts[7].w < near) near = pts[7].w;
    if (limit < near) {
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F8DF8);
#endif
