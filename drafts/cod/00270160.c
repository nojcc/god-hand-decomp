/* NON_MATCHING func_00270160 (sn-2.95.3-136): same length as retail, 21 instructions
 * differ in the two sway pushes: retail multiplies before it loads sway[no], keeps
 * &sway[0] in a register and forms &sway[no] again for the second push. The
 * cVec(x, y, z) temporary binds its three arguments before its stores, which no
 * cVec.h macro does yet. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"

#define SWAY_JOINTS 8

typedef struct cEmSway {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x1920 - 0x1870];
    float sway[SWAY_JOINTS];            /* 0x1920 per joint offset */
    float swayBias;                     /* 0x1940 added to every push */
} cEmSway;

extern int D_003BF8B8[SWAY_JOINTS];
extern float D_003BF8D8[SWAY_JOINTS];
extern float D_003BF8F8[SWAY_JOINTS];
extern float D_003BF918[SWAY_JOINTS];
extern float D_003BF938[SWAY_JOINTS];

/* Push sway joint no by a (plus the bias) and b, and move its part along x. */
void func_00270160(cEmSway *self, unsigned int no, float a, float b)
{
    cVec v;
    int frame[3];
    cParts *part;
    float *rate;

    CVEC_ZERO(v);
    if (no >= SWAY_JOINTS) {
        return;
    }
    part = (cParts *)cOmBase_childAtIdx((cOmBase *)self, frame, D_003BF8B8[no]);
    if (part == 0) {
        return;
    }
    part->partFlags |= CPARTS_NO_BLEND | 0x200;
    a += self->swayBias;
    rate = a > 0.0f ? D_003BF8D8 : D_003BF8F8;
    self->sway[no] += a * rate[no];
    rate = b > 0.0f ? D_003BF8D8 : D_003BF8F8;
    self->sway[no] += b * rate[no];
    {
        cVec t;
        cVec *r_ = &t;

        float x = part->mtxLocal[12];
        float y = part->mtxLocal[13];
        float z = part->mtxLocal[14];

        t.x = x;
        t.y = y;
        t.z = z;
        r_->w = 1.0f;
        if (&v != r_) {
            v.x = t.x;
            v.y = t.y;
            v.z = t.z;
        }
    }
    v.x += self->sway[no] * self->base.speedRate;
    if (v.x < D_003BF918[no]) {
        v.x = D_003BF918[no];
        self->sway[no] = 0.0f;
    }
    if (D_003BF938[no] < v.x) {
        v.x = D_003BF938[no];
        self->sway[no] = 0.0f;
    }
    {
        cVec *s_ = &v;
        cVec *d_ = part->anchor;

        if (d_ != s_) {
            d_->x = v.x;
            d_->y = v.y;
            d_->z = v.z;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00270160);
#endif
