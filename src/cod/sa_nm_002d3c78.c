/* NON_MATCHING func_002D3C78 (sn): 7 diffs: tail store/const scheduling (-1 vs 1.0f vs i2C load order); order sweeps + temp/flag/compiler probes exhausted */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct {
    int unk0;
    unsigned short s4, s6, s8, sA, sC, sE;
    int i10, i14, i18, i1C, i20, i24, i28, i2C;
} Src2D3C78;

typedef struct {
    int unk0;
    char pad4[0x1C - 4];
    unsigned short s1C, s1E, s20, s22, s24, s26;
    int i28, i2C, i30, i34, i38, i3C;
    char pad40[4];
    float f44, f48, f4C;
    float f50;
    char pad54[4];
    int i58, i5C, i60;
} Obj2D3C78;

extern int Obj0000_Get_D_0076A7A4_3756F0(void);
extern int func_002D3D88(Obj2D3C78 *a0);
extern void func_00345F48(int a0, int a1);

int func_002D3C78(Obj2D3C78 *o, Src2D3C78 *s)
{
    float f;

    o->s1C = s->s4;
    o->s1E = s->s6;
    o->s20 = s->s8;
    o->s22 = s->sA;
    o->s24 = s->sC;
    o->s26 = s->sE;
    o->i28 = s->i14;
    o->i2C = s->i18;
    o->i30 = s->i1C;
    o->i34 = s->i10;
    o->i38 = s->i20;
    if (Obj0000_Get_D_0076A7A4_3756F0() == 2) {
        o->f44 = f = (float)s->i28;
    } else {
        o->f44 = f = (float)s->i24;
    }
    o->f48 = f;
    {
    int t = s->i2C;
    o->f50 = 0.0f;
    o->i3C = t;
    o->f4C = 1.0f;
    o->i58 = -1;
    o->i5C = -1;
    }
    if (func_002D3D88(o) == 0) return 0;
    o->i60 = 0;
    if (!(o->i3C & 2)) func_00345F48(o->unk0, 1);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002D3C78);
#endif
