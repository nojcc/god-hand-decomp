/* sn-2.95.3-136 */
/* Differs from retail (24 insns): cc1 converts (float)(int)uv through a GPR
 * (trunc.w.s, mfc1, mtc1, cvt.s.w); retail converts in the FPU register and
 * then reloads each scroll value from memory before subtracting. With fpu.h's
 * FPU_CVT_W_S/FPU_CVT_S_W the conversions match but the reloads stay missing. */
#include "include_asm.h"
#include "godhand/cModel.h"

#ifdef NON_MATCHING
#define CMODEL_NODE_TAG_NO_UV   0x80000000      /* tag: the node's uv does not scroll */

/* Scroll node's uv by its mesh's speed times rate, keeping only the fraction. */
__attribute__((section(".text.func_00149220")))
void func_00149220(cModelNode *node, float rate)
{
    float du;
    float dv;

    if (!(node->tag & CMODEL_NODE_TAG_NO_UV)) {
        du = F16toF32(node->info->uvSpeed[0]) * rate;
        dv = F16toF32(node->info->uvSpeed[1]) * rate;
        node->uvScroll[0] += du;
        node->uvScroll[1] += dv;
        node->uvScroll[0] -= (float)(int)node->uvScroll[0];
        node->uvScroll[1] -= (float)(int)node->uvScroll[1];
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00149220);
#endif
