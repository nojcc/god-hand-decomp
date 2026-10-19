/* sn-2.95.3-136: enemy setup with a 2.6 x 1.8 x 1.2 damage-take volume, the enemy work
 * defaults, and effect data 0x25A registered from the resource at 0x304. */
#include "godhand/emDamageVol.h"

extern int espSys_effDataRegist(void *table, int id, void *data);
extern char D_007419A0[];

static inline void SetState16FA80(EmDmgVol *em, int v)
{
    em->base.hpMax = v;
    em->base.hp = v;
    em->unk5EC = v;
}

__attribute__((section(".text.func_0016FA80")))
int func_0016FA80(EmDmgVol *em)
{
    Vec4f v[4];             /* size twice, offset, rotation */
    Vec4f *ofs;
    Vec4f *rot;
    Vec4f *size;
    void *slot;
    char *res;
    float one, c0, c1, c2;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 2.6f;
    c1 = 1.8f;
    c2 = 1.2f;
    size = &v[1];
    ofs = &v[2];
    v[0].x = c0;
    v[0].y = c1;
    v[0].z = c2;
    v[1].x = c0;
    v[1].y = c1;
    v[1].z = c2;
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
    em->unk5E4 = 0;
    em->unk5F6 = 0;
    em->unk5E8 = 0x25A;
    em->unk5F0 = 0x25A;
    em->sub = em->subBuf;
    em->subKind = 9;
    em->target = -1;
    SetState16FA80((char *)em, 1);
    func_001C28A0(em);
    res = *(char **)((char *)em + 0x304);
    espSys_effDataRegist(D_007419A0, 0x25A, (char *)(*(int *)(res + 0xC) + (int)res));
    *(int *)((char *)em + 0x5A0) |= 0x10;
    return 1;
}
