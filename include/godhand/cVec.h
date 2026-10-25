/* include/godhand/cVec.h - the game's vector class, as statement macros.
 *
 * The SN C++ code uses an inline VU0 vector class whose operators go through
 * stack temporaries: each result is built in a temporary, copied to the
 * operator's return slot, then copied to its destination. SN gives a
 * function one return slot and one temporary and reuses them for every
 * operator in it, so a function that uses these macros declares them once,
 * with CVEC_TEMPS, where retail's stack order puts them among its cVec
 * locals. The macros rebuild the operators from vu0.h, one bare block each.
 * They are macros, not inline functions, for the reason EM_PHASE_RUN is: an
 * inline function moves registers.
 *
 * Shapes the bytes depend on: an operator binds its arguments first, then
 * its return-slot pointer, then copies through that pointer by name. The
 * pointer (r_) exists only for the self-check, and the order of a_, b_, r_
 * decides which registers they get. The copy can't be a helper call
 * (vec3_copy, cVec_copy3): those compare and read through their own
 * parameters and don't match.
 */
#ifndef GODHAND_CVEC_H
#define GODHAND_CVEC_H

#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

/* The return slot and the temporary every operator in the function shares. */
#define CVEC_TEMPS              cVec ret_; cVec tmp_

/* Vec v; (the default constructor: all four components zero) */
#define CVEC_ZERO(v)            VU0_SQC2_VF0_MEM(&(v), 0)

/* d = ret_; (operator= from the return slot, xyz only, skipped when d is the slot) */
#define CVEC_FROM_RET(d)                                        \
    {                                                           \
        cVec *r_ = &ret_;                                       \
                                                                \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* a - b; (operator- into the return slot, for a caller that passes &ret_ on) */
#define CVEC_SUB(a, b)                                          \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
    }

/* d = a - b; (operator- into the return slot, then operator=, xyz only) */
#define CVEC_SET_SUB(d, a, b)                                   \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* v *= s; (operator*= by a scalar, xyz) */
#define CVEC_MUL_SCALAR(v, s)   VU0_VSCALE_XYZ_MEM(&(v), 0, s)

/* v += *b; (operator+=, xyz) */
#define CVEC_ADD_TO(v, b)       VU0_VADD_XYZ_IP(&(v), 0, b)

/* *dst = v; (the whole quadword, as the copy constructor makes it) */
#define CVEC_STORE(dst, v)                                      \
    {                                                           \
        VU0_LQC2(4, &(v), 0);                                   \
        VU0_SQC2(4, dst, 0);                                    \
    }

/* Work-only operators, not in a PR yet: each is used by drafts only. */

/* d = m * *a; (a matrix times a vector: a copy of *a transformed in place by
 * sceVu0ApplyMatrix, returned through its return slot, then operator=, xyz
 * only). The caller declares sceVu0ApplyMatrix (sceVu0.h). */
#define CVEC_SET_APPLY(d, m, a)                                 \
    {                                                           \
        cVec *a_ = (a);                                         \
        void *m_ = (m);                                         \
        cVec *t_ = &tmp_;                                       \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        sceVu0ApplyMatrix(t_, m_, t_);                          \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* d = *a * s; (operator* by a scalar: a copy of *a scaled in place, returned
 * through its return slot, then operator=, xyz only). t_ is the pointer the
 * returned copy is read through; retail forms it before the first load. */
#define CVEC_SET_MUL(d, a, s)                                   \
    {                                                           \
        cVec *a_ = (a);                                         \
        float s_ = (s);                                         \
        cVec *t_ = &tmp_;                                       \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VSCALE_XYZ_MEM(&tmp_, 0, s_);                       \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        if (&(d) != r_) {                                       \
            (d).x = ret_.x;                                     \
            (d).y = ret_.y;                                     \
            (d).z = ret_.z;                                     \
        }                                                       \
    }

/* cVec r = *a * s; (operator* by a scalar: a copy of *a scaled in place,
 * constructing r through the return slot). s is used once and not bound:
 * a float copy of it adds a mov.s. */
#define CVEC_INIT_MUL(r, a, s)                                  \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VSCALE_XYZ_MEM(&tmp_, 0, s);                        \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

/* d = cVec(fx, fy, fz); (the three-float constructor, w = 1, into a
 * temporary, then operator=, xyz only). d is a float[3]. */
#define CVEC_SET_XYZ(d, fx, fy, fz)                             \
    {                                                           \
        float *d_ = (d);                                        \
        cVec *r_ = &tmp_;                                       \
                                                                \
        tmp_.x = (fx);                                          \
        tmp_.y = (fy);                                          \
        tmp_.z = (fz);                                          \
        tmp_.w = 1.0f;                                          \
        if ((cVec *)d_ != r_) {                                 \
            d_[0] = tmp_.x;                                     \
            d_[1] = tmp_.y;                                     \
            d_[2] = tmp_.z;                                     \
        }                                                       \
    }

/* d = *s; (operator=, xyz only) */
#define CVEC_ASSIGN(d, s)                                       \
    {                                                           \
        cVec *s_ = (s);                                         \
                                                                \
        if (&(d) != s_) {                                       \
            (d).x = s_->x;                                      \
            (d).y = s_->y;                                      \
            (d).z = s_->z;                                      \
        }                                                       \
    }

/* cVec v(fx, fy, fz); (the three-float constructor in place, w = 1). As an
 * inline function the arguments go through registers and 0.0 components are
 * no longer stored from $zero. */
#define CVEC_INIT_XYZ(v, fx, fy, fz)                            \
    {                                                           \
        cVec *v_ = &(v);                                        \
                                                                \
        v_->x = (fx);                                           \
        v_->y = (fy);                                           \
        v_->z = (fz);                                           \
        v_->w = 1.0f;                                           \
    }

/* cVec d(*s); (the copy constructor into a local: the whole quadword) */
#define CVEC_COPY(d, s)                                         \
    {                                                           \
        cVec *s_ = (s);                                         \
                                                                \
        VU0_LQC2(4, s_, 0);                                     \
        VU0_SQC2_MEM(4, &(d), 0);                               \
    }

#endif /* GODHAND_CVEC_H */
