/* sn-2.95.3-136 */
/* func_0031B560: still differs from retail in where the camera pointer's lui
 * is scheduled (retail keeps it after the angle store) and the two address
 * registers that follow from it. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criStm.h"
#include "godhand/cOmBase.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/capVu0.h"
#include "godhand/cVec.h"
#include "godhand/gameWork.h"
#include "godhand/vu0.h"


/* cVec r = *a - *b; (operator- into its return slot, constructing r) */
#define CVEC_INIT_SUB(r, a, b)                                  \
    {                                                           \
        cVec tmp_;                                              \
        cVec *a_ = (a);                                         \
        cVec *b_ = (b);                                         \
        cVec *t_ = &tmp_;                                       \
                                                                \
        VU0_ZERO_VSUB_XYZ_MEM(&tmp_, 0, a_, b_);                \
        VU0_LQC2(4, t_, 0);                                     \
        VU0_SQC2_MEM(4, &(r), 0);                               \
    }

/* A controller port as the pad update reads it: the last two receive buffers. */
typedef struct PadPort {
    char unk00[0x100];
    unsigned char data[0x380];          /* 0x100 the port's receive buffer */
    unsigned char data2[0x20];          /* 0x480 the second slot's buffer */
} PadPort;

/* The state the pad update keeps for one controller. */
typedef struct PadState {
    unsigned int hold;                  /* 0x00 buttons held, PAD bits plus the stick directions */
    unsigned int prev;                  /* 0x04 hold of the previous frame */
    unsigned int trg;                   /* 0x08 pressed this frame */
    unsigned int rel;                   /* 0x0C released this frame */
    int analog;                         /* 0x10 nonzero: the left stick also drives the d-pad */
    unsigned char mode;                 /* 0x14 func_0031AF40's result */
    char unk15[3];
    unsigned int rep;                   /* 0x18 repeat bits, first after 10 frames */
    unsigned int repFast;               /* 0x1C repeat bits, first after 6 frames */
    signed char repWait[32];            /* 0x20 frames to the next repeat, per bit */
    signed char repWaitFast[32];        /* 0x40 */
    unsigned char stick[4];             /* 0x60 raw stick bytes: right x, y, left x, y */
    unsigned char press[12];            /* 0x64 button pressures */
    signed char axis[4];                /* 0x70 stick axes past the dead zone, 0 inside it */
    float angle;                        /* 0x74 left stick direction */
    float camAngle;                     /* 0x78 the same direction relative to the camera */
} PadState;                             /* 0x7C */

extern int func_0031AF70(int value);
extern int func_0031AF40(PadPort *port, int mode);
extern void func_0031BDC8(PadPort *port);

/* Reads one controller into its pad state: buttons and their edges, the
 * stick axes and directions, the pressures, the stick angles and the
 * repeat bits. mode 0 reads a neutral pad, 2 the second slot. */
__attribute__((section(".text.func_0031B560")))
void func_0031B560(PadPort *port, PadState *st, int mode)
{
    unsigned char neutral[0x20];
    unsigned char *p;
    int n;
    int first;
    int firstFast;
    int next;
    int i;

    func_003A52F0(neutral, 0, 0x20);
    p = port->data;
    neutral[7] = 0x80;
    neutral[4] = 0x80;
    neutral[5] = 0x80;
    neutral[6] = 0x80;
    if (mode == 1) {
        func_0031BDC8(port);
    }
    st->prev = st->hold;
    if (mode == 2) {
        p = port->data2;
    }
    if (mode == 0) {
        p = neutral;
    }
    st->hold = p[2] << 8 | p[3];
    if (st->analog) {
        if (!(st->hold & 0xA000)) {
            if (st->stick[2] > 0xB0) {
                st->hold |= 0x8000;
            }
            if (st->stick[2] < 0x50) {
                st->hold |= 0x2000;
            }
        }
        if (!(st->hold & 0x5000)) {
            if (st->stick[3] > 0xB0) {
                st->hold |= 0x1000;
            }
            if (st->stick[3] < 0x50) {
                st->hold |= 0x4000;
            }
        }
    }
    st->axis[2] = func_0031AF70((signed char)(0xFF - p[4]));
    st->axis[3] = func_0031AF70((signed char)p[5]);
    if ((st->axis[2] > 0x40 || st->axis[2] < -0x40) && st->axis[3] == 0) {
        st->axis[3] = p[5] + 0x80;
    }
    /* retail bounds this one at -0x30, not -0x40 */
    if ((st->axis[3] > 0x40 || st->axis[3] < -0x30) && st->axis[2] == 0) {
        st->axis[2] = 0x7F - p[4];
    }
    st->axis[0] = func_0031AF70((signed char)(0xFF - p[6]));
    st->axis[1] = func_0031AF70((signed char)p[7]);
    if ((st->axis[0] > 0x40 || st->axis[0] < -0x40) && st->axis[1] == 0) {
        st->axis[1] = p[7] + 0x80;
    }
    if ((st->axis[1] > 0x40 || st->axis[1] < -0x40) && st->axis[0] == 0) {
        st->axis[0] = 0x7F - p[6];
    }
    if (st->axis[0] > 0x50) {
        st->hold |= 0x800000;
    }
    if (st->axis[0] < -0x50) {
        st->hold |= 0x400000;
    }
    if (st->axis[1] > 0x50) {
        st->hold |= 0x100000;
    }
    if (st->axis[1] < -0x50) {
        st->hold |= 0x200000;
    }
    if (st->axis[2] > 0x50) {
        st->hold |= 0x80000;
    }
    if (st->axis[2] < -0x50) {
        st->hold |= 0x40000;
    }
    if (st->axis[3] > 0x50) {
        st->hold |= 0x10000;
    }
    if (st->axis[3] < -0x50) {
        st->hold |= 0x20000;
    }
    st->rel = (st->hold ^ st->prev) & st->prev;
    st->trg = (st->hold ^ st->prev) & st->hold;
    st->stick[0] = p[4];
    st->stick[1] = p[5];
    st->stick[2] = p[6];
    st->stick[3] = p[7];
    st->press[3] = p[8];
    st->press[2] = p[9];
    st->press[0] = p[10];
    st->press[1] = p[11];
    st->press[4] = p[12];
    st->press[7] = p[13];
    st->press[5] = p[14];
    st->press[6] = p[15];
    st->press[8] = p[16];
    st->press[9] = p[17];
    st->press[10] = p[18];
    st->press[11] = p[19];
    st->mode = func_0031AF40(port, mode);
    st->angle = capVu0Atan2(-st->axis[0], st->axis[1]);
    {
        struct cCamera *cam = D_005CAFF0;
        cVec eye;
        cVec target;
        cVec d;

        CVEC_COPY(eye, &cam->eye);
        CVEC_COPY(target, &cam->target);
        CVEC_INIT_SUB(d, &eye, &target);
        st->camAngle = Adjust_theta(st->angle + capVu0Atan2(d.x, d.z));
    }
    n = 1;
    if (D_007474A0.unk569 == 1) {
        n = 2;
    }
    first = n * 10;
    firstFast = n * 6;
    next = n * 2;
    for (i = 31; i >= 0; i--) {
        if (st->hold & st->trg & 1 << i) {
            st->repWait[i] = first;
            st->rep |= 1 << i;
            st->repWaitFast[i] = firstFast;
            st->repFast |= 1 << i;
        } else if (st->hold & 1 << i) {
            if (st->repWait[i] != 0) {
                st->repWait[i]--;
                st->rep &= ~(1 << i);
            } else {
                st->repWait[i] = next;
                st->rep |= 1 << i;
            }
            if (st->repWaitFast[i] != 0) {
                st->repWaitFast[i]--;
                st->repFast &= ~(1 << i);
            } else {
                st->repWaitFast[i] = next;
                st->repFast |= 1 << i;
            }
        } else {
            st->rep &= ~(1 << i);
            st->repWait[i] = 0;
            st->repFast &= ~(1 << i);
            st->repWaitFast[i] = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0031B560);
#endif
