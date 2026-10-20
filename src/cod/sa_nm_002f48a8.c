/* NON_MATCHING func_002F48A8 (sn-2.95.3-136, as sn;
 * PARK, 13 diffs): only the motion frame-count
 * block differs -- retail keeps the uint count in a0 and reloads 0x2B0/0x4D0 after the join
 * (no gcse carry), ours keeps MOT(self) live in a0.  linkOn() inline shape fixed the flag. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void func_002FBED0(void *self);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern int moveMotion(void *a0);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void CopyVec16From20_B62E0(void *dst, void *self);
extern void cNode_setLocalScale(void *self, void *v);
extern void func_002B60D0(void *dst, void *self);
extern int func_00307118(void *p);

static inline void vcopy(Vec3 *d, Vec3 *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int linkOn(char *self)
{
    char *q = *(char **)(self + 0x120);
    if (q) {
        if (*(int *)(*(char **)(q + 0xC) + 0x250) >= 0) {
            if (func_00307118(q) == 1)
                return 1;
        } else {
            *(char **)(self + 0x120) = 0;
        }
    }
    return 0;
}

#define F(p, o) (*(float *)((char *)(p) + (o)))
#define MOT(s) (*(char **)((char *)(s) + 0x2B0))

__attribute__((section(".text.func_002F48A8")))
void func_002F48A8(char *self)
{
    Vec3 v;
    Vec3 w;
    unsigned int n;
    char *mi;
    char *o;
    char *q;
    float scale;

    func_002FBED0(self);
    n = 0;
    F(self, 0x2D8) += F(self, 0x2C0);
    F(self, 0x2C0) += F(self, 0x2C4);
    if (1.0f < F(self, 0x2D8))
        F(self, 0x2D8) = 1.0f;
    if (F(self, 0x2D8) < 0.0f)
        F(self, 0x2D8) = 0.0f;
    mi = *(char **)(MOT(self) + 0x4D0);
    if (mi)
        n = *(unsigned short *)(mi + 4) - 1;
    setMotionInfo(MOT(self), *(int *)(MOT(self) + 0x4D0), 0, 0, 0.0f, (float)n * F(self, 0x2D8), 0);
    moveMotion(MOT(self));
    o = MOT(self);
    StoreVecFromFieldB0_2B6160(&v, self);
    vcopy(*(Vec3 **)(o + 0xF0), &v);
    CopyVec16From20_B62E0(&v, self);
    v.z = v.x;
    cNode_setLocalScale(self, &v);
    func_002B60D0(&w, self);
    vcopy((Vec3 *)(MOT(self) + 0x100), &w);
    vcopy((Vec3 *)(MOT(self) + 0x110), &v);
    F(MOT(self), 0x240) = F(self, 0x188);
    F(MOT(self), 0x244) = F(self, 0x18C);
    F(MOT(self), 0x248) = F(self, 0x190);
    F(MOT(self), 0x24C) = F(self, 0x194);
    scale = 1.0f;
    if (*(unsigned char *)(self + 0x24C)) {
        int a = *(unsigned char *)(self + 0x24C);
        scale = (float)(a - *(unsigned char *)(self + 0x24D)) / (float)a;
    }
    if (linkOn(self) == 1) {
        q = *(char **)(self + 0x120);
        if ((*(int *)(q + 0x10) >> 1) & 1)
            scale *= F(q, 8);
    }
    F(MOT(self), 0x24C) *= scale;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002F48A8);
#endif
