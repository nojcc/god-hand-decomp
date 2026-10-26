/* drafts/vu0_pending.h - VU0 macros the drafts use that vu0.h doesn't have.
 *
 * Not approved for include/godhand/vu0.h: each waits on LucasPicoli (see
 * progress/decisions_needed.md, "vu0.h macros"). VU0_ZERO_VSUB_XYZ_TO is the
 * one non-volatile asm. Only drafts include this file; nothing in src/ may.
 */
#ifndef DRAFTS_VU0_PENDING_H
#define DRAFTS_VU0_PENDING_H

#include "godhand/vu0.h"

/* VU0_LQC2_SQC2_MEM(reg, dst, src): copy the quadword at src to dst through
 * $vf<reg>, as one statement. src is a register-addressed pointer; dst is a
 * memory operand, so a stack local is stored at its sp offset. */
#define VU0_LQC2_SQC2_MEM(reg, dst, src)                               \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "lqc2  $vf" #reg ", 0(%1)\n"                                   \
        "sqc2  $vf" #reg ", %0\n"                                      \
        ".set pop\n"                                                   \
        : "=m"(*(vu0_q128_t *)(dst)) : "r"((void *)(src)) : "memory")

/* VU0_VSUB_XYZ_IP(v, off, b): (v+off).xyz -= b.xyz, the vsub twin of VU0_VADD_XYZ_IP. */
#define VU0_VSUB_XYZ_IP(v, off, b)                                     \
    __asm__ __volatile__ (                                             \
        ".set push\n"                                                  \
        ".set noreorder\n"                                             \
        "lqc2  $vf4, %0\n"                                             \
        "lqc2  $vf5, 0(%1)\n"                                          \
        "vsub.xyz $vf4, $vf4, $vf5\n"                                  \
        "sqc2  $vf4, %0\n"                                             \
        ".set pop\n"                                                   \
        :                                                              \
        : "m"(*(vu0_q128_t *)((char *)(v) + (off))), "r"((void *)(b))  \
        : "memory")

/* VU0_ZERO_VSUB_XYZ_TO(v, off, a, b): the same five instructions as
 * VU0_ZERO_VSUB_XYZ_MEM, with (v+off) as an output operand and without
 * volatile, so unrelated address arithmetic can be scheduled across it. */
#define VU0_ZERO_VSUB_XYZ_TO(v, off, a, b)                             \
    __asm__ (                                                          \
        ".set push\n.set noreorder\n"                                  \
        "sqc2  $vf0, %0\n"                                             \
        "lqc2  $vf4, 0(%1)\n"                                          \
        "lqc2  $vf5, 0(%2)\n"                                          \
        "vsub.xyz $vf4, $vf4, $vf5\n"                                  \
        "sqc2  $vf4, %0\n"                                             \
        ".set pop\n"                                                   \
        : "=m"(*(vu0_q128_t *)((char *)(v) + (off)))                   \
        : "r"((void *)(a)), "r"((void *)(b))                           \
        : "memory")

#endif /* DRAFTS_VU0_PENDING_H */
