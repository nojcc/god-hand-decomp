/* sn-2.95.3-136 */
/* func_00283AA8: point the push along the heading of the link's holder (sn-2.95.3-136) */

#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

#define EMLINK_HOLDER     2             /* child of the link that holds this enemy */
#define EMLINK_LIFT       0.01f

/* An enemy that can be pushed along by a linked object. */
typedef struct cEmLinked {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x2130 - 0x1870];
    char work[0x5C];                    /* 0x2130 step work */
    int mode;                           /* 0x218C EMLINK_MODE_* */
    cVec push;                          /* 0x2190 */
    char unk21A0[0x10];
    cEm00 *link;                        /* 0x21B0 */
} cEmLinked;

extern void MtxInitRotY(float *mtx, float angle);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float capVu0Atan2(float y, float x);
/* v = m * v, in place. */
static __inline__ void cVec_applyMatrix(cVec *v, void *m) {
    sceVu0ApplyMatrix(v, m, v);
}
extern void func_00104010(void *self, void *work, void *model);

/* Point the push along the heading of the link's holder (or of the link), then run the step. */
__attribute__((section(".text.func_00283AA8")))
void func_00283AA8(cEmLinked *self)
{
    struct {
        float m[4][4];
        cVec v;
        int childNum;
    } f;
    cEm00 *link;
    cOmBase *holder;
    float angle;

    self->mode = EMLINK_MODE_FREE;
    link = self->link;
    if (link != 0 && link->vital > 0) {
        VU0_SQC2_VF0(&f, 0x40);
        holder = cOmBase_childAt((cOmBase *)link, &f.childNum, EMLINK_HOLDER);
        if (holder != 0) {
            f.v.x = 0.0f;
            f.v.y = 0.0f;
            f.v.z = 1.0f;
            cVec_applyMatrix(&f.v, holder->mtx);
            VU0_VSUB_XYZ_IP(&f.v, 0, holder->pos);
            angle = capVu0Atan2(f.v.x, f.v.z);
        } else {
            angle = link->rot.y;
        }
        MtxInitRotY((float *)f.m, angle);
        f.v.x = 0.0f;
        f.v.y = EMLINK_LIFT;
        f.v.z = -EMLINK_LIFT;
        cVec_applyMatrix(&f.v, f.m);
        cVec_copy3(&self->push, &f.v);
        self->mode = EMLINK_MODE_HELD;
    }
    func_00104010(self, self->work, &self->base.unk5B0);
}
