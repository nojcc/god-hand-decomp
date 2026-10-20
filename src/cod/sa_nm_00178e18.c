/* NON_MATCHING func_00178E18 (sn-2.95.3-136): 2 diffs.
 * Only the 0x5F4/0x5F6 halfword stores swap in the tail;
 * every ordering of the tail stores tried by order search leaves them swapped. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/emDamageVol.h"


__attribute__((section(".text.func_00178E18")))
int func_00178E18(EmDmgVol *em)
{
    Vec4f v[4];             /* size twice, offset, rotation */
    Vec4f *ofs;
    Vec4f *rot;
    Vec4f *size;
    void *slot;
    float one, c0, c1;

    func_001B6FB8(em);
    one = 1.0f;
    c0 = 4.8f;
    c1 = 3.0f;
    size = &v[1];
    ofs = &v[2];
    v[0].x = c0;
    v[0].y = c1;
    v[0].z = c0;
    v[1].y = c1;
    v[0].w = one;
    v[1].x = c0;
    v[1].z = c0;
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
        *(unsigned int *)em->dmgTake |= 1;
    }
    em->base.hpMax = 1;
    em->base.hp = 1;
    em->sub = em->subBuf;
    em->subKind = 18;
    em->base.flags2 |= 0x800;
    em->unk5E8 = 0;
    em->unk5EC = 17;
    em->unk5F6 = 5;
    em->unk5E4 = 0;
    em->target = -1;
    em->unk5F0 = 0;
    func_001C28A0(em);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00178E18);
#endif
