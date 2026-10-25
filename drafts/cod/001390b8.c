/* NON_MATCHING cMotCamera_setMotion (sn-2.95.3-136): 4 instructions differ, all in the
 * pos operator=: retail loads x, y and z before the first store and stores x, z, y;
 * this C interleaves the loads with the stores. Retail stores y/z and roll[1..2]
 * through this-pointers (inline operator= and set). The 0x27A/0x2B4 fields sit in
 * cCamera.h padding, and cCamera_setMode's definition on main takes no parameters. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cVec.h"

typedef struct MotCamView {
    char pad000[0x27A];
    short frameNum;                     /* 0x27A */
    char pad27C[0x2B4 - 0x27C];
    float speed;                        /* 0x2B4 */
    char pad2B8[0x3A4 - 0x2B8];
    int data;                           /* 0x3A4 */
    int frame;                          /* 0x3A8 */
    int mode;                           /* 0x3AC */
    cVec pos;                           /* 0x3B0 */
    float roll[3];                      /* 0x3C0 */
    char pad3CC[0x3E4 - 0x3CC];
    unsigned int flags;                 /* 0x3E4 */
} MotCamView;

void cCamera_setMode(void *self, int mode);

/* Start a camera motion: data, mode, start position (origin if none), roll, loop flag. */
void cMotCamera_setMotion(MotCamView *self, int data, int mode, cVec *pos, int frameNum, int loop, float roll)
{
    cVec v;

    self->data = data;
    self->mode = mode;
    self->frame = 0;
    self->speed = 1.0f;
    if (pos != 0) {
        CVEC_COPY(v, pos);
    } else {
        CVEC_INIT_XYZ(v, 0.0f, 0.0f, 0.0f);
    }
    CVEC_ASSIGN(self->pos, &v);
    self->frameNum = frameNum;
    self->flags = 0;
    self->roll[0] = 0.0f;
    self->roll[1] = roll;
    self->roll[2] = 0.0f;
    cCamera_setMode(self, 3);
    if (loop != 0) {
        self->flags |= 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cMotCamera_setMotion);
#endif
