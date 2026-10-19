/* sn-2.95.3-136: enemy setup with a damage-take volume (0x19AA80). */
#include "godhand/emDamageVol.h"

static inline void Vec4f_setW(Vec4f *v, float w)
{
    v->w = w;
}

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

__attribute__((section(".text.func_0019AA80")))
int func_0019AA80(EmDmgVol *em)
{
    Vec4f hit;              /* filled but never passed on */
    Vec4f size;
    Vec4f ofs;
    Vec4f rot;

    func_001B6FB8(em);
    hit.x = 2.8f; hit.y = 0.6f; hit.z = 1.6f;
    Vec4f_setW(&hit, 1.0f);
    size.x = 2.8f; size.y = 1.0f; size.z = 1.6f;
    Vec4f_setW(&size, 1.0f);
    ofs.x = 0.0f; ofs.y = 0.0f; ofs.z = 0.0f;
    Vec4f_setW(&ofs, 1.0f);
    em->dmgTake = cDamageManage_CreateDamageTake(D_00574380, em, 2);
    if (em->dmgTake != 0) {
        rot.x = 0.0f; rot.y = 0.0f; rot.z = 0.0f;
        Vec4f_setW(&rot, 1.0f);
        func_001FD9D8(em->dmgTake, em->base.mtx, &ofs, &rot, &size);
    }
    InitDmgVol(em, 1, em->subBuf, 7, 7, 0);
    func_001C28A0(em);
    return 1;
}
