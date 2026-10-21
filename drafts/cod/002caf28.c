#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[0x60];
    float cur[5];    /* 0x60 */
    float target[5]; /* 0x74 */
    float step[5];   /* 0x88 */
} cSnd;

typedef struct {
    char pad0[0xEE8];
    int mode;        /* 0xEE8 */
} SndSys;

extern unsigned int D_00747A84;
extern SndSys *D_003BD930;

void func_002CAF28(cSnd *s)
{
    float *cur;
    float *step;
    float *target;
    int i;

    if (D_00747A84 & 0x08000000) {
        unsigned char quiet;
        s->step[2] = 0.1;
        s->target[2] = 0.45;
        s->target[1] = 0.0f;
        s->step[1] = 0.1;
        quiet = D_003BD930->mode == 0;
        s->target[3] = quiet ? 0.45 : 1.0f;
        s->step[3] = 0.1;
    } else {
        s->target[3] = 1.0f;
        s->step[3] = 0.1;
        s->target[1] = 1.0f;
        s->step[1] = 0.1;
        s->target[2] = 1.0f;
        s->step[2] = 0.1;
    }

    cur = s->cur;
    step = s->step;
    target = s->target;
    for (i = 4; i >= 0; i--) {
        if (*cur != *target) {
            if (*target < *cur) {
                *cur = *cur - *step;
                if (*cur < *target)
                    *cur = *target;
            } else {
                *cur = *cur + *step;
                if (*target < *cur)
                    *cur = *target;
            }
        }
        step++;
        target++;
        cur++;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002CAF28);
#endif
