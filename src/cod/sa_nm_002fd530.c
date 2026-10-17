/* NON_MATCHING func_002FD530 (sn,inline-vec): 10 diffs: retail keeps the dest vector pointer in a pseudo (v0, copied to s1) and folds the source loads to s0 offsets; ours is the mirror image (source pointer pseudo, dest folded) with inline vset */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    char pad0[4];
    int flags;
} Sub2FD530;

typedef struct {
    char pad0[0x110];
    Sub2FD530 *unk110;
    char pad114[0x11D - 0x114];
    unsigned char unk11D;
    char pad11E[0x178 - 0x11E];
    float unk178;
    float unk17C;
    float unk180;
} Obj2FD530;

extern int D_00747A84;
extern float D_00741DC0;
extern float D_00747A14;
extern void func_002B62F8(float *, Obj2FD530 *);
extern void func_002B6230(Obj2FD530 *, float *);
extern void sceVu0ScaleVector(float *, float *, float);
extern void capVu0AddVectorXYZ(float *, float *, float *);
extern void Adjust_theta_vec(float *);

static inline void vset(float *d, float *s)
{
    float x = s[0], y = s[1], z = s[2];

    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

void func_002FD530(Obj2FD530 *o)
{
    float pos[4];
    float v[4];
    float *pv;

    func_002B62F8(pos, o);
    vset(v, &o->unk178);
    pv = v;
    if ((!(o->unk110->flags & 0x2000) && (o->unk11D & 1)) || (D_00747A84 & 0x20000)) {
        sceVu0ScaleVector(pv, pv, D_00741DC0 * D_00747A14);
    }
    capVu0AddVectorXYZ(pos, pos, pv);
    Adjust_theta_vec(pos);
    func_002B6230(o, pos);
}
#else
INCLUDE_ASM("asm/nonmatching", func_002FD530);
#endif
