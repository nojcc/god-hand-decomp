/* NON_MATCHING func_0028E0E0 (sn-2.95.3-136): switch value in v1 (retail a0, constant in v1) and bit-6 test srl vs retail dsrl */
#include "include_asm.h"
#include "godhand/cObjSimple.h"

#ifdef NON_MATCHING
#include "godhand/cCoreSave.h"
#include "godhand/cModel.h"
#include "godhand/cObjBase.h"

typedef struct {
    int f0;
    int pad4[3];
    cObjSimpleVec3 pos;
    int pad1C;
    float f20;
    int f24;
    int f28;
    int f2C;
    unsigned char c30;
    unsigned char c31;
} InitArg;

extern char D_007419A0[];
extern unsigned short D_00747A50;
extern char D_003C3F68[];
extern void espSys_effDataRegist(void *self, int id, void *data);
extern int cModel_setupFromPack(void *self);
extern void func_0028EBF0(char *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int moveMotion(void *self);

static inline void vecCopy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

#define PACK(self) (*(char **)((self) + 0x304))
#define PACKI(self) (*(int **)((self) + 0x304))

int func_0028E0E0(char *self, InitArg *arg, int a2)
{
    InitArg *d = (InitArg *)(self + 0x1510);

    d->f0 = arg->f0;
    vecCopy(&d->pos, &arg->pos);
    d->f20 = arg->f20;
    d->f24 = arg->f24;
    d->f28 = arg->f28;
    d->f2C = arg->f2C;
    d->c30 = arg->c30;
    d->c31 = arg->c31;
    *(int *)(self + 0x564) = arg->f28;
    espSys_effDataRegist(D_007419A0, 0xD7, (char *)(PACKI(self)[4] + (int)PACKI(self)));
    switch (D_00747A50) {
    case 0x105:
        if (D_00569B70.data->flags & 0x4000)
            return 0;
        break;
    case 0x102:
        if (D_00569B70.data->flags & 0x2000)
            return 0;
        break;
    case 0x204:
        if (D_00569B70.data->flags & 0x1000)
            return 0;
        break;
    case 0x300:
        if (D_00569B70.data->flags & 0x800)
            return 0;
        break;
    case 0x404:
        if (D_00569B70.data->flags & 0x400)
            return 0;
        break;
    case 0x503:
        if (D_00569B70.data->flags & 0x200)
            return 0;
        break;
    case 0x607:
        if (((unsigned char *)&D_00569B70.data->flags)[1] & 1)
            return 0;
        break;
    case 0x701:
        if ((D_00569B70.data->flags >> 7) & 1)
            return 0;
        break;
    case 0x802:
        if (((unsigned long)D_00569B70.data->flags >> 6) & 1)
            return 0;
        break;
    }
    if (cModel_setupFromPack(self) == 0)
        return 0;
    func_0028EBF0(self, arg, a2);
    *(float *)(self + 0x118) = 0.5f;
    *(float *)(self + 0x114) = 0.5f;
    *(float *)(self + 0x110) = 0.5f;
    func_002A8578(self, PACKI(self)[3] + (int)PACKI(self), 0, 0, 0.0f, 0, 0);
    moveMotion(self);
    cModel_calcParts(self);
    IK_InverseKinematics(self + 0x448, self);
    cModel_calcWorldParts(self);
    *(unsigned int *)(self + 0x258) |= 0x80000000;
    cParts_setRotationOrder(self, 4);
    *(unsigned char *)(self + 0x531) = 0;
    cObjBase_KageInit(self, self + 0x670, D_003C3F68);
    SetEffect(0xD7, 1, self, 0, -1, 0xFFFFFFFF);
    *(int *)(self + 0x1550) = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028E0E0);
#endif
