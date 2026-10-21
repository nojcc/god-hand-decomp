/* NON_MATCHING func_00137670 (sn-2.95.3-136): closest point of an oriented box. Retail keeps a
 * second pointer to the axis vector (for its w store and the inner product), spills the pointer
 * to the scaled vector and has a 0x100 frame; ours has one register fewer and a 0xF0 frame. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

extern float sceVu0InnerProduct(void *a, void *b);

/* An oriented box: centre, three unit axes and the half length along each. */
typedef struct CollOBB {
    cVec center;                        /* 0x00 */
    cVec axis[3];                       /* 0x10 */
    char unk40[0x10];
    float halfLen[3];                   /* 0x50 */
} CollOBB;

/* The point of the box closest to p: start at the centre and walk along each axis by the
 * distance of p on that axis, clamped to the half length. */
static __inline__ void cVec_sub(cVec *dst, cVec *a, cVec *b)
{
    cVec r;

    VU0_ZERO_VSUB_XYZ_MEM(&r, 0, a, b);
    VU0_LQC2(4, &r, 0);
    VU0_SQC2(4, dst, 0);
}

static __inline__ void cVec_scale(cVec *dst, cVec *src, float t)
{
    cVec r;

    VU0_LQC2(4, src, 0);
    VU0_SQC2(4, &r, 0);
    VU0_VSCALE_XYZ_MEM(&r, 0, t);
    VU0_LQC2(4, &r, 0);
    VU0_SQC2(4, dst, 0);
}

void func_00137670(cVec *p, CollOBB *box, cVec *out)
{
    cVec d;
    cVec ax;
    cVec step;
    float t;
    float h;
    int i;

    cVec_sub(&d, p, &box->center);
    cVec_copy3(out, &box->center);
    for (i = 0; i < 3; i++) {
        ax.y = box->axis[i].y;
        ax.x = box->axis[i].x;
        ax.z = box->axis[i].z;
        ax.w = 1.0f;
        t = sceVu0InnerProduct(&d, &ax);
        h = box->halfLen[i];
        if (h < t) {
            t = h;
        }
        h = -h;
        if (t < h) {
            t = h;
        }
        cVec_scale(&step, &ax, t);
        VU0_VADD_XYZ_IP(out, 0, &step);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00137670);
#endif
