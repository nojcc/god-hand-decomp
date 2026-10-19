/* sn-2.95.3-136: enemy setup, same shape as func_00188DE0 with a different volume and
 * the damage-take flag or'd with 1 after the volume is attached. */
#include "godhand/emDamageVol.h"


__attribute__((section(".text.func_00195D08")))
int func_00195D08(EmDmgVol *em)
{
    Vec4f v[4];             /* size twice, offset, rotation */
    Vec4f *ofs;
    Vec4f *rot;
    Vec4f *size;
    void *slot;
    float one, c0, c1, c2;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 5.2f;
    c1 = 0.8f;
    c2 = 2.4f;
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
    ofs->y = -0.4f;
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
        *(int *)em->dmgTake |= 1;
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->sub = em->subBuf;
    em->subKind = 5;
    em->unk5EC = 7;
    em->unk5F6 = 10;
    em->unk5E8 = 0;
    em->unk5E4 = 0;
    em->unk5F0 = 0;
    em->target = -1;
    func_001C28A0(em);
    return 1;
}
