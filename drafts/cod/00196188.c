/* NON_MATCHING func_00196188 (sn-2.95.3-136): 282 words vs 283.
 * Retail reuses its stack slots the way SN's C++ temporaries do: the
 * damage-take vectors take the slot of the give part's child-count store
 * (0x20) while the give rotation (0x30) stays, and the last loop stores the
 * child count into the slot it then uses for pos (0x10). Block-scoped C
 * locals free their slots at other points, so the frame is 0x110 bytes and
 * every stack offset differs. The take's flag word at 0x00 has no name in
 * cDamageUnit.h yet. */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/cOmEffSlots.h"
#include "godhand/cOmBaseFn.h"
#include "godhand/cDamageManage.h"
#include "godhand/cModel.h"
#include "godhand/cVec.h"
#include "godhand/objField.h"

/* The part groups: two single parts, then the parts 0..2 and 3..7. */
extern cOmPartGroup D_00424ED0[4];

/* Copy x, y and z from src into the translation row of mtx (floats 12 to 14). */
extern void CopyVec3ToField30_147C40(void *mtx, void *src);


/* Set up the object: a damage-give box on part group 1's part, a damage-take
 * box, the meshes of layers 0/1 shown and 0x40/0x41 hidden, the parts of
 * groups 2 and 3 taken off their parents, and group 3's parts moved to
 * positions relative to group 1's part. */
__attribute__((section(".text.func_00196188")))
int func_00196188(cOmEffSlots *self)
{
    int g, i;
    unsigned int n, k;
    cOmBase *child;

    func_001B6FB8(&self->base);
    {
        cVec size;
        cVec ofs;

        size.x = 2.25f;
        size.y = 0.5f;
        size.z = 5.8f;
        size.w = 1.0f;
        ofs.x = 0.0f;
        ofs.y = 0.0f;
        ofs.z = 0.0f;
        ofs.w = 1.0f;
        self->give = cDamageManage_CreateDamageGive(&D_00574380, 2, self);
        if (self->give != 0) {
            int frame[3];
            cVec rot;

            child = cOmBase_childAtIdx(&self->base, frame, D_00424ED0[1].first);
            rot.x = 0.0f;
            rot.y = 0.0f;
            rot.z = 0.0f;
            rot.w = 1.0f;
            func_001FD9D8((cDamageUnit *)self->give, child->mtx, &ofs, &rot, &size);
            self->give->unk46 = 0x53;
            self->give->activeTime = 10;
            cDamageUnit_SetDamageCollActive((cDamageUnit *)self->give, 0);
        }
    {
        cVec size;
        cVec ofs;

        size.x = 0.4f;
        size.y = 3.4f;
        size.z = 0.4f;
        size.w = 1.0f;
        ofs.x = -2.0f;
        ofs.y = 0.0f;
        ofs.z = -2.5f;
        ofs.w = 1.0f;
        self->take = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
        if (self->take != 0) {
            cVec rot;

            rot.x = 0.0f;
            rot.y = 0.0f;
            rot.z = 0.0f;
            rot.w = 1.0f;
            func_001FD9D8(self->take, self->base.mtx, &ofs, &rot, &size);
            *(unsigned int *)self->take |= 1;
        }
    }
    }
    self->unk9D8 = 1;
    cOmBase_setMeshDispFromLayer(&self->base, 0, 1);
    cOmBase_setMeshDispFromLayer(&self->base, 1, 1);
    cOmBase_setMeshDispFromLayer(&self->base, 0x40, 0);
    cOmBase_setMeshDispFromLayer(&self->base, 0x41, 0);
    for (g = 2; g < 4; g++) {
        for (i = D_00424ED0[g].first; i < D_00424ED0[g].first + D_00424ED0[g].num && i < self->base.partNum; i++) {
            int frame[3];

            cOmBase_childAtIdx(&self->base, frame, i)->partFlags |= CPARTS_NO_LOCAL;
            cOmBase_childAtIdx(&self->base, frame, i)->partFlags |= CPARTS_NO_PARENT;
        }
    }
    {
        cVec base;
        cVec pos;
        CVEC_TEMPS;
        int frame[3];

        n = D_00424ED0[3].num;
        CVEC_ZERO(base);
        ForwardVec3At30_147C60(&base, cOmBase_childAtIdx(&self->base, frame, D_00424ED0[1].first)->mtxLocal);
        for (k = 0, i = D_00424ED0[3].first; k < n; k++, i++) {
            child = cOmBase_childAtIdx(&self->base, frame, i);
            CVEC_ZERO(pos);
            ForwardVec3At30_147C60(&pos, child->mtxLocal);
            CVEC_SUB(&pos, &base);
            pos.x = ret_.x;
            pos.y = ret_.y;
            pos.z = ret_.z;
            CopyVec3ToField30_147C40(child->mtxLocal, &pos.x);
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00196188);
#endif
