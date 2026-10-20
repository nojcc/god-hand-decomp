#include "godhand/emDamageVol.h"
#include "godhand/cOmBase.h"

extern void espSys_effDataRegist(void *sys, int id, void *data);
extern int D_007419A0;

typedef struct DataHdr {
    char pad0[0xC];
    int off;                            /* 0xC */
} DataHdr;

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
int func_0016F4A8(EmDmgVol *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb;
    char *data;
    DataHdr *hdr;

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
    slot = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    self->dmgTake = slot;
    if (slot != 0) {
        nv = &f[12];
        *(int *)&f[12] = 0;
        *(int *)&f[13] = 0;
        *(int *)&f[14] = 0;
        nv[3] = one;
        func_001FD9D8(slot, (char *)self + 0x80, m, nv, t);
    }
    InitDmgVol((char *)self, 1, self->subBuf, 6, 1, 600);
    func_001C28A0(self);
    {
        int h = self->base.texKey;
        espSys_effDataRegist(&D_007419A0, 600, (void *)(*(int *)(h + 0xC) + h));
    }
    return 1;
}
