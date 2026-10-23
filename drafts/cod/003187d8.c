/* sn-2.95.3-136 */
/* func_003187D8 (objScroll init): 5 words short. Retail tests the setup flags 0x4000000,
 * 0x2000000 and bit 5 one at a time, where this build merges the first two into one mask;
 * it stores texFlags once before and once after life, and loads 0xFFFF/1/0xFF in another
 * order. cObj 0x2F0 (a flag word) has no field yet, hence the offset macro. */
#include "include_asm.h"
#include "godhand/cObj.h"
#include "godhand/cModel.h"
#include "godhand/gameWork.h"

#ifdef NON_MATCHING

/* The scroll object's setup record. */
typedef struct ScrollSet {
    char unk00[0x34];
    union {
        int flags;                      /* 0x34 */
        unsigned char flagByte[4];
    } u;
    char unk38[6];
    unsigned short uvSpeedU;            /* 0x3E F16 */
    unsigned short uvSpeedV;            /* 0x40 F16 */
    char unk42[2];
    float life;                         /* 0x44 seconds */
    unsigned short fadeIn;              /* 0x48 F16 */
    char unk4A[2];
    float rot[3];                       /* 0x4C degrees */
} ScrollSet;

typedef struct objScroll {
    COBJ_FIELDS
    cVec unk310;                        /* 0x310 */
    ScrollSet *set;                     /* 0x320 */
    float uvSpeed[2];                   /* 0x324 */
    unsigned char unk32C;
    unsigned char unk32D;
    unsigned char unk32E;
    char unk32F;
    unsigned short unk330;
    char unk332[0xE];
    cVec startRot;                      /* 0x340 radians */
    unsigned int bits[1];               /* 0x350 */
} objScroll;

#define SCROLL_FLAGS2F0(o) (*(int *)((char *)(o) + 0x2F0))

extern void func_00319CC0(void *self, int value);
extern void func_00319E00(void *a0);
extern void func_0031D2F8(char *model, int idx);
extern void func_0031A0B8(void *a0, unsigned int a1);
extern void func_0031A088(char *a0, unsigned int a1);
extern float F16toF32(unsigned short half);
extern cModelNode *cModel_getMeshPtr(cModel *self, int n);
extern cVec D_003BD890;

/* objScroll's init: resets the state bytes, sets up both packet buffers, applies the
 * setup record's display flags, scroll speeds, life and fade, and its start rotation. */
__attribute__((section(".text.func_003187D8")))
int func_003187D8(objScroll *self)
{
    cVec rot;
    unsigned long f;
    unsigned long bit;
    long v;

    self->unk32D = 0;
    self->mode = 0;
    self->phase = 0;
    self->step = 0;
    self->stepArg = 0;
    SCROLL_FLAGS2F0(self) |= 0x800;
    self->unk330 = 0xFFFF;
    self->unk32C = 1;
    self->unk32E = 0xFF;
    func_00319CC0(self, 10);
    D_007474A0.frame++;
    func_00319CC0(self, 10);
    D_007474A0.frame--;
    func_00319E00(self);
    if (self->set->u.flags & CMODEL_MESH_BACK)
        func_0031D2F8((char *)self, 0);
    if (self->set->u.flags & 0x40000) {
        self->objFlags |= CMODEL_F_HIDDEN;
        cModel_getMeshPtr((cModel *)self, 0)->dispFlags |= 0x2000;
    }
    if (self->set->u.flags & 0x80000000) {
        cModel_getMeshPtr((cModel *)self, 0)->dispFlags |= 0x4000;
        self->drawPrio = 1;
    }
    if (self->set->u.flags & CMODEL_MESH_SPECIAL) {
        self->drawKind = 3;
        self->id = 4;
        self->drawPrio = 1;
    }
    bit = self->set->u.flagByte[1];
    if (bit >> 7) {
        self->id = 3;
        self->drawPrio = 1;
        self->drawKind = 3;
    }
    if (self->set->u.flags & CMODEL_MESH_TO_BIT23)
        cModel_getMeshPtr((cModel *)self, 0)->dispFlags |= 0x800000;
    self->uvSpeed[0] = F16toF32(self->set->uvSpeedU);
    self->uvSpeed[1] = F16toF32(self->set->uvSpeedV);
    self->texFlags |= 0x80000000;
    self->life = (int)(self->set->life * 10.0f);
    self->texFlags |= 0x40000000;
    self->fadeLen = self->life * 15 / 100;
    self->fadeIn = F16toF32(self->set->fadeIn);
    cVec_set4(&rot, self->set->rot[0] * 0.017453292f, self->set->rot[1] * 0.017453292f,
              self->set->rot[2] * 0.017453292f, 1.0f);
    cVec_copy3(&self->startRot, &rot);
    func_0031A0B8(self, 3);
    if (rot.x != 0.0f || rot.y != 0.0f || rot.z != 0.0f)
        func_0031A088((char *)self, 3);
    self->unk310.x = D_003BD890.x;
    self->unk310.y = D_003BD890.y;
    self->unk310.z = D_003BD890.z;
    f = self->set->u.flags;
    bit = (f >> 4) & 1;
    if (bit)
        cModel_getMeshPtr((cModel *)self, 0)->dispFlags |= CMODEL_NODE_HIDE;
    f = self->set->u.flags;
    bit = (f >> 5) & 1;
    if ((f & 0x4000000) || (f & 0x2000000) || bit)
        self->bits[0] |= 0x20000000;
    return 1;
}

#else
INCLUDE_ASM("asm/nonmatching", func_003187D8);
#endif
