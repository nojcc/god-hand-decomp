/* NON_MATCHING func_002BCF28 (sn-2.95.3-136): 9 differing words. Retail builds the work
 * vector's address (addiu s0, sp, 0x50) before the first copy, and loads a2/a3 before
 * f12/f13 for the final call; here both come later. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

/* The frame: both segments' start and end points, then the transform's result and work copy. */
typedef struct SegFrame {
    cVec startA;
    cVec endA;
    cVec startB;
    cVec endB;
    cVec out;
    cVec work;
} SegFrame;

#define SEGFRAME_OFFSET(field) ((int)&((SegFrame *)0)->field)

extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern int func_002BC0F8(cVec *startA, cVec *endA, cVec *startB, cVec *endB,
                         float lowA, float highA, float lowB, float highB);

/* Tests the vertical segments of two matrices against each other: each runs from the
 * matrix origin up its own y axis by highA / highB. */
__attribute__((section(".text.func_002BCF28")))
int func_002BCF28(float *mtxA, float *mtxB, float lowA, float highA, float lowB, float highB)
{
    SegFrame f;

    VU0_SQC2_VF0_MEM(&f.startA, 0);
    VU0_SQC2_VF0_MEM(&f.endA, 0);
    VU0_SQC2_VF0_MEM(&f.startB, 0);
    VU0_SQC2_VF0_MEM(&f.endB, 0);
    ForwardVec3At30_147C60(&f.startA, mtxA);
    f.endA.y = highA;
    VU0_LQC2(4, &f.endA, 0);
    VU0_SQC2(4, &f, SEGFRAME_OFFSET(work));
    sceVu0ApplyMatrix(&f.work, mtxA, &f.work);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, SEGFRAME_OFFSET(out));
    f.endA.x = f.out.x;
    f.endA.y = f.out.y;
    f.endA.z = f.out.z;
    ForwardVec3At30_147C60(&f.startB, mtxB);
    f.endB.y = highB;
    VU0_LQC2(4, &f.endB, 0);
    VU0_SQC2(4, &f, SEGFRAME_OFFSET(work));
    sceVu0ApplyMatrix(&f.work, mtxB, &f.work);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, SEGFRAME_OFFSET(out));
    f.endB.x = f.out.x;
    f.endB.y = f.out.y;
    f.endB.z = f.out.z;
    return func_002BC0F8(&f.startA, &f.endA, &f.startB, &f.endB, lowA, highA, lowB, highB);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BCF28);
#endif
