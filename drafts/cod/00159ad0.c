/* sn-2.95.3-136 */
/*
 * NON_MATCHING: same length as retail (179 words); only the ceiling of t
 * differs. Retail converts (int)t back to float in the FPU (cvt.s.w on the
 * cvt.w.s result) and copies it to the frame register after; here the value
 * goes through the GPR and back (mfc1/mtc1). The rest is identical.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#define REC_KIND_BYTES   1
#define REC_KIND_SHORTS  3
#define REC_KIND_SHORTS2 5

/* View of RecIn in 001599b0.c. */
typedef struct RecCurveIn {
    unsigned int hdr;
    int dataOff;
    union {
        int off;
        float value;
    } u;
} RecCurveIn;

/* View of RecOut in 001599b0.c, with the curve keys after the value. */
typedef struct RecCurve {
    unsigned char kind;                 /* 0x00 */
    char unk01[3];
    char *src;                          /* 0x04 data block */
    char *cur;                          /* 0x08 current entry */
    unsigned short pos;                 /* 0x0C */
    unsigned short first;               /* 0x0E first entry value */
    union {
        int zero;
        float value;
    } u;                                /* 0x10 */
    float next;                         /* 0x14 */
    float tanA;                         /* 0x18 */
    float tanB;                         /* 0x1C */
} RecCurve;

extern void RecDecode_readHeader(RecCurve *out, char *blob, RecCurveIn *in);
extern void func_00159DA0(RecCurve *out);

/* Evaluate a decoded record at time t: step to the keys around t (re-reading
 * the header when t goes back) and blend them with a cubic Hermite curve. */
__attribute__((section(".text.func_00159AD0")))
float func_00159AD0(RecCurve *self, char *blob, RecCurveIn *in, float t)
{
    unsigned int frame;
    int stepped;
    float s, s2, s3;

    if (self->kind == 0) {
        return self->u.value;
    }
    stepped = 0;
    if (t < 0.0f) {
        frame = 0;
    } else {
        frame = (int)t;
        if ((float)(int)t != t) {
            frame++;
        }
    }
    if (t < (float)self->pos) {
        RecDecode_readHeader(self, blob, in);
    }
    switch (self->kind) {
    case REC_KIND_BYTES:
        while (self->first < frame) {
            stepped = 1;
            self->pos = self->first;
            self->cur += 4;
            self->first += *(unsigned char *)self->cur;
        }
        break;
    case REC_KIND_SHORTS:
        while (self->first < frame) {
            stepped = 1;
            self->cur += 8;
            self->pos = self->first;
            self->first = *(unsigned short *)self->cur;
        }
        break;
    case REC_KIND_SHORTS2:
        while (self->first < frame) {
            stepped = 1;
            self->cur += 0x10;
            self->pos = self->first;
            self->first = *(unsigned short *)self->cur;
        }
        break;
    }
    if (stepped) {
        func_00159DA0(self);
    }
    if ((float)self->pos == t) {
        return self->u.value;
    }
    if ((float)self->first == t) {
        return self->next;
    }
    switch (self->kind) {
    case REC_KIND_BYTES:
    case REC_KIND_SHORTS:
    case REC_KIND_SHORTS2:
        s = (t - (float)self->pos) / (float)(self->first - self->pos);
        s2 = s * s;
        s3 = s2 * s;
        return self->u.value * (2.0f * s3 - 3.0f * s2 + 1.0f)
             + self->next * (-(2.0f * s3) + 3.0f * s2)
             + self->tanA * (s3 - s2 - s2 + s)
             + self->tanB * (s3 - s2);
    }
    return self->u.value;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00159AD0);
#endif
