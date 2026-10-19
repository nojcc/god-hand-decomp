/* sn-2.95.3-136: NM closer handoff. */
#include "godhand/emDamageVol.h"


static inline void InitDmgVol(EmDmgVol *em, int col, char *sub, int kind, int w, int t)
{
    em->unk5E8 = t;
    em->unk5E4 = 0;
    em->unk5F0 = t;
    em->unk5F6 = 0;
    em->base.hpMax = col;
    em->base.hp = col;
    em->sub = sub;
    em->subKind = kind;
    em->unk5EC = w;
    em->target = -1;
}

__attribute__((section(".text.func_00188B50")))
int func_00188B50(EmDmgVol *em)
{
    float base[4];
    float size[4];
    float ofs[4];
    float rot[4];
    float *sz;
    float *of;
    float *rt;
    void *slot;
    float one;

    func_001B6FB8(em);
    one = 1.0f;
    base[0] = 4.4f;
    base[1] = 1.234f;
    base[2] = 0.3f;
    base[3] = one;
    sz = size;
    size[0] = 4.4f;
    sz[1] = 1.6f;
    size[2] = 0.3f;
    sz[3] = one;
    of = ofs;
    ofs[0] = 0.0f;
    ofs[1] = 0.0f;
    ofs[2] = 0.0f;
    of[3] = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        rt = rot;
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        rt[3] = one;
        func_001FD9D8(slot, em->base.mtx, of, rt, sz);
    }
    InitDmgVol((char *)em, 1, em->subBuf, 6, 0xC9, 0);
    func_001C28A0(em);
    return 1;
}
