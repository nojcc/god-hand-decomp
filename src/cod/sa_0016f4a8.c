#include "godhand/cOmBase.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *mtx, float *pos, float *dir, float *size);
extern int func_001C28A0(void *self);
extern void espSys_effDataRegist(void *sys, int id, void *data);
extern int D_00574380;
extern int D_007419A0;

typedef struct Hdr16F4A8 {
    char pad0[0xC];
    int off;                            /* 0xC */
} Hdr16F4A8;

typedef struct Obj16F4A8 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[4];
    int unk5E4;                         /* 0x5E4 */
    int unk5E8;                         /* 0x5E8 */
    int unk5EC;                         /* 0x5EC */
    int unk5F0;                         /* 0x5F0 */
    short unk5F4;                       /* 0x5F4 */
    short unk5F6;                       /* 0x5F6 */
    char unk5F8[8];
    void *damage;                       /* 0x600 */
    char unk604[4];
    void *work;                         /* 0x608 */
    unsigned char workNum;              /* 0x60C */
    char unk60D[0x13];
    char workBuf[4];                    /* 0x620 */
} Obj16F4A8;

static inline void InitDmgVol(char *p, int col, char *sub, int kind, int w, int t)
{
    *(int *)(p + 0x5E8) = t;
    *(int *)(p + 0x5E4) = 0;
    *(int *)(p + 0x5F0) = t;
    *(short *)(p + 0x5F6) = 0;
    *(short *)(p + 0x548) = col;
    *(short *)(p + 0x54A) = col;
    *(char **)(p + 0x608) = sub;
    *(unsigned char *)(p + 0x60C) = kind;
    *(int *)(p + 0x5EC) = w;
    *(short *)(p + 0x5F4) = -1;
}

__attribute__((section(".text.func_0016F4A8")))
int func_0016F4A8(Obj16F4A8 *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb;
    char *data;
    Hdr16F4A8 *hdr;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.6f;
    cb = 1.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = one;
    f[2] = cb;
    f[6] = cb;
    f[3] = one;
    f[5] = one;
    t[3] = one;
    *(int *)&f[8] = 0;
    *(int *)&f[9] = 0;
    *(int *)&f[10] = 0;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        *(int *)&f[12] = 0;
        *(int *)&f[13] = 0;
        *(int *)&f[14] = 0;
        nv[3] = one;
        func_001FD9D8(slot, (char *)self + 0x80, m, nv, t);
    }
    InitDmgVol((char *)self, 1, self->workBuf, 6, 1, 600);
    func_001C28A0(self);
    {
        int h = self->base.texKey;
        espSys_effDataRegist(&D_007419A0, 600, (void *)(*(int *)(h + 0xC) + h));
    }
    return 1;
}
