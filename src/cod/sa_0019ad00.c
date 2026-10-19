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

__attribute__((section(".text.func_0019AD00")))
int func_0019AD00(EmDmgVol *em)
{
    Vec4f v[4];             /* size twice, offset, rotation */
    Vec4f *ofs;
    Vec4f *rot;
    Vec4f *size;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(em);
    one = 1.0f;
    ca = 3.2f;
    cb = 1.1f;
    cc = 1.4f;
    size = &v[1];
    ofs = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[0].z = cc;
    v[1].x = ca;
    v[1].y = cb;
    v[1].z = cc;
    v[0].w = one;
    size->w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    ofs->w = one;
    slot = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    em->dmgTake = slot;
    if (slot != 0) {
        rot = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        rot->w = one;
        func_001FD9D8(slot, em->base.mtx, ofs, rot, size);
    }
    InitDmgVol((char *)em, 1, em->subBuf, 7, 7, 0);
    func_001C28A0(em);
    return 1;
}
