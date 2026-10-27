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

/* len = (*a - *b).lengthSq(); (operator- into the return slot, then
 * lengthSq on the slot). The caller includes capVu0.h. */
#define CVEC_SUB_LENGTH_SQ(len, a, b)                           \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *r_ = &ret_;                                       \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        (len) = capVu0LengthSq(r_);                             \
    }

/* a + b; (operator+ into the return slot, for a caller that reads ret_) */
#define CVEC_ADD(a, b)                                          \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VADD_XYZ_IP(&tmp_, 0, b_);                          \
        VU0_LQC2(4, &tmp_, 0);                                  \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
    }

/* a->unit(); (the unit vector of *a, built in the temporary by cVec_unitOf,
 * into the return slot, for a caller that reads ret_). The caller includes
 * sceVu0.h. */
#define CVEC_UNIT(a)                                            \
    {                                                           \
        cVec *a_ = (a);                                         \
                                                                \
        cVec_unitOf(&tmp_, a_);                                 \
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


/* Vec v(fx, fy, fz); (the three-float constructor in place, w = 1). As an
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

/* d = a->unit(); (the unit vector of *a, zero when *a has no length, built
 * in the temporary by cVec_unitOf, returned through the return slot, then
 * operator=, xyz only). The caller includes sceVu0.h. */
#define CVEC_SET_UNIT(d, a)                                     \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *r_ = &ret_;                                       \
                                                                \
        cVec_unitOf(&tmp_, a_);                                 \
        VU0_LQC2(4, &tmp_, 0);                                  \
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

/* cVec r = *a + *b; (operator+: a copy of *a with *b added in place,
 * constructing r through the return slot; r is ret_ when the sum is passed
 * on). b is used once and not bound: a copy of it adds a move. */
#define CVEC_INIT_ADD(r, a, b)                                  \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VADD_XYZ_IP(&tmp_, 0, b);                           \
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


/* d = s; (operator= on d with a named vector s: this is &d, compared
 * against &s before the copy, xyz only) */
#define CVEC_ASSIGN_VEC(d, s)                                   \
    {                                                           \
        cVec *d_ = &(d);                                        \
                                                                \
        if (d_ != &(s)) {                                       \
            d_->x = (s).x;                                      \
            d_->y = (s).y;                                      \
            d_->z = (s).z;                                      \
        }                                                       \
    }

/* cVec d(*s); (the copy constructor into a local: the whole quadword) */
#define CVEC_COPY(d, s)                                         \
    {                                                           \
        cVec *s_ = (s);                                         \
                                                                \
        VU0_LQC2(4, s_, 0);                                     \
        VU0_SQC2_MEM(4, &(d), 0);                               \
    }

/* *dp = v; (operator= from a named vector into one reached through a
 * pointer, xyz only: the pointer is read once) */
#define CVEC_PUT(dp, v)                                         \
    {                                                           \
        cVec *d_ = (dp);                                        \
                                                                \
        if (d_ != &(v)) {                                       \
            d_->x = (v).x;                                      \
            d_->y = (v).y;                                      \
            d_->z = (v).z;                                      \
        }                                                       \
    }

/* d = v; (operator= with its argument bound before this: &v is formed
 * first and only used for the self-check, the copy reads v by name, xyz) */
#define CVEC_ASSIGN_ARG(d, v)                                   \
    {                                                           \
        cVec *s_ = &(v);                                        \
        cVec *d_ = &(d);                                        \
                                                                \
        if (d_ != s_) {                                         \
            d_->x = (v).x;                                      \
            d_->y = (v).y;                                      \
            d_->z = (v).z;                                      \
        }                                                       \
    }

/* d = *a + *b; (operator+: a copy of *a with *b added in place, returned
 * through its return slot, then operator=, xyz only). t_ is the pointer the
 * returned copy is read through; retail forms it before the first load. */
#define CVEC_SET_ADD(d, a, b)                                   \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        VU0_VADD_XYZ_IP(&tmp_, 0, b_);                          \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
        CVEC_PUT(&(d), ret_);                                   \
    }

/* m * *a; (a matrix times a vector into the return slot, for a caller that
 * passes &ret_ on). The caller declares sceVu0ApplyMatrix (sceVu0.h). */
#define CVEC_APPLY(m, a)                                        \
    {                                                           \
        cVec *a_ = (a);                                         \
        void *m_ = (m);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_LQC2(4, a_, 0);                                     \
        VU0_SQC2_MEM(4, &tmp_, 0);                              \
        sceVu0ApplyMatrix(t_, m_, t_);                          \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &ret_, 0);                              \
    }

/* cVec r = *a - *b; (operator- constructing r through the return slot, xyz) */
#define CVEC_INIT_SUB(r, a, b)                                  \
    {                                                           \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

/* f(cVec(*s)); (a temporary copy passed by reference: p takes the
 * temporary's address before the copy is made into it) */
#define CVEC_TEMP_COPY(p, t, s)                                 \
    {                                                           \
        (p) = &(t);                                             \
        VU0_LQC2_SQC2_MEM(4, &(t), s);                          \
    }

/* f(cVec(*s)) for a by-value cVec argument: the copy into the temporary t is
 * made when the argument is evaluated; the expression is &t. */
#define CVEC_ARG_COPY(t, s)                                     \
    ({                                                          \
        VU0_LQC2_SQC2_MEM(4, &(t), s);                          \
        &(t);                                                   \
    })

#endif /* GODHAND_CVEC_H */
