/* sn-2.95.3-136 */
/* NON_MATCHING func_00175F38 (extern_jtbl D_004211C0): 507 vs 511 words.
 * Retail's dead child-count stores of the child lookups all land in one
 * reused stack word (0x20 in phase 0, where the after-loop scale vector also
 * lives, and 0 in phase 2), the way cc1 places an inlined helper's own
 * locals. Each `int frame[3]` here gets a slot of its own, which grows the
 * frame by 0x60 and moves every stack offset; the -0.02f debris speed is also
 * reloaded each pass where retail keeps it in $f22. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cObjBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cSnd.h"
#include "godhand/mtx.h"
#include "godhand/objField.h"
#include "godhand/rand.h"
#include "godhand/vecInline.h"
#include "godhand/vu0.h"

/* A breakable object: two parts that break off on hits, then the rest. */
typedef struct cOmBreak {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xC];
    int fxId;                           /* 0x5EC effect started when the rest breaks, 0 for none */
    int fxKind;                         /* 0x5F0 */
    char unk5F4[0xC];
    cDamageUnit *partHit[2];            /* 0x600 hit volume of each part */
    cDamageUnit *bodyHit;               /* 0x608 hit volume of the rest */
    char unk60C[0x4];
    char debris[3][0x60];               /* 0x610 debris effect records (objField.h) */
    char unk730[0xD30 - 0x730];
    unsigned int broken[1];             /* 0xD30 one bit per broken part, high bit first */
    short timer;                        /* 0xD34 */
    short partHp[2];                    /* 0xD38 */
    signed char lastPart;               /* 0xD3C part the last hit broke */
} cOmBreak;

/* The layer range of one piece of the model: the first child and the count. */
typedef struct LayerRange {
    unsigned char first;
    unsigned char count;
} LayerRange;

extern LayerRange D_00421290[];

void SetField5B0Bit2ClearBit8_1B7908(cOmBase *self);
void func_001769E0(void *a0, int a1);
void func_00176A50(char *p, unsigned int layer, int idx);

#define PART_BROKEN(self, i) ((self)->broken[(i) >> 5] & (0x80000000 >> ((i) & 0x1F)))

#define SET_MODE(self, m) { (self)->base.mode = (m); (self)->base.phase = 0; (self)->base.step = 0; (self)->base.stepArg = 0; }

/* The break sequence: a hit breaks one part off; once both are gone the rest
 * flies apart (debris, effect, sound), the pieces are moved onto the base
 * piece's matrix, and the animation slows to a stop. */
__attribute__((section(".text.func_00175F38")))
void func_00175F38(cOmBreak *self)
{
    unsigned int i;
    unsigned int j;
    int n;
    cParts *part;
    char *slot;

    switch (self->base.phase) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 4, self, 0, 0, 0, 0);
        switch (self->lastPart) {
        case 0:
            func_00176A50((char *)self, 0, 3);
            break;
        case 1:
            func_00176A50((char *)self, 1, 4);
            break;
        }
        func_001769E0(self, self->lastPart);
        n = 0;
        {
            unsigned int k;

            for (k = 0; k < 2; k++) {
                if (PART_BROKEN(self, k)) {
                    n++;
                }
            }
        }
        if (n == 0) {
            SET_MODE(self, 0)
            break;
        }
        {
            cVec ofs;
            cVec spin;

            SetField5B0Bit2ClearBit8_1B7908(&self->base);
            vec4_set_point(&ofs.x, 0.0f, 0.0f, 0.0f);
            VU0_SQC2_VF0_MEM(&spin, 0);
            spin.x += fRand1_1() * 0.01f;
            spin.y += fRand1_1() * 0.01f;
            spin.z += fRand1_1() * 0.01f;
            for (i = 0; i < 2; i++) {
                cVec scale;

                if (PART_BROKEN(self, i)) {
                    continue;
                }
                {
                    int frame[3];

                    part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[i].first);
                    part->partFlags |= CPARTS_NO_LOCAL;
                }
                {
                    int frame[3];

                    part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[i].first);
                    part->partFlags |= CPARTS_NO_PARENT;
                }
                {
                    int frame[3];

                    part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[i].first);
                }
                slot = self->debris[D_00421290[i].first];
                Obj0000_Set_Byte_54(slot, 1);
                Obj0000_Set_Field_50_173998(slot, part->mtx);
                ForwardVec3At30_147C60(slot, part->mtx);
                func_00147C88(slot + 0x10, part->mtx, 0);
                CopyVec3ToField20_173908(slot, &ofs.x);
                CopyVec3ToField30_173938(slot, &spin.x);
                cVec_set4(&scale, 1.0f, 1.0f, 1.0f, 1.0f);
                CopyVec3ToField40_173968(slot, &scale.x);
                *(float *)(slot + 0x58) = -0.02f;
            }
            {
                int frame[3];

                part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[2].first);
                part->partFlags |= CPARTS_NO_LOCAL;
            }
            {
                int frame[3];

                part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[2].first);
                part->partFlags |= CPARTS_NO_PARENT;
            }
            {
                int frame[3];

                part = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[2].first);
            }
            {
                cVec scale;

                slot = self->debris[D_00421290[2].first];
                Obj0000_Set_Byte_54(slot, 1);
                Obj0000_Set_Field_50_173998(slot, part->mtx);
                ForwardVec3At30_147C60(slot, part->mtx);
                func_00147C88(slot + 0x10, part->mtx, 0);
                CopyVec3ToField20_173908(slot, &ofs.x);
                CopyVec3ToField30_173938(slot, &spin.x);
                cVec_set4(&scale, 1.0f, 1.0f, 1.0f, 1.0f);
                CopyVec3ToField40_173968(slot, &scale.x);
                *(float *)(slot + 0x58) = -0.02f;
            }
        }
        if (self->fxId != 0) {
            SetEffect(self->fxKind, self->fxId, 0, 0, -1, 0xFFFFFFFF);
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 4, self, 0, 0, 0, 0);
        vec3_set(&self->base.knock.x, 0.0f, 12.0f, 0.0f);
        self->timer = 20;
        if (self->bodyHit != 0) {
            cDamageUnit_SetDamageCollActive(self->bodyHit, 1);
        }
        self->base.phase = 1;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 1:
        if (--self->timer <= 0) {
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            if (PART_BROKEN(self, i)) {
                continue;
            }
            switch (i) {
            case 0:
                func_00176A50((char *)self, 0, 3);
                break;
            case 1:
                func_00176A50((char *)self, 1, 4);
                break;
            }
        }
        {
            cParts *root;
            int frame[3];

            root = (cParts *)cOmBase_childAtIdx(&self->base, frame, D_00421290[2].first);
            for (j = D_00421290[5].first; j < D_00421290[5].first + D_00421290[5].count; j++) {
                int f0[3];
                int f1[3];

                part = (cParts *)cOmBase_childAtIdx(&self->base, f0, j);
                MtxMultiply(part->mtx, root->mtx, ((cParts *)cOmBase_childAtIdx(&self->base, f1, j))->mtxLocal);
            }
        }
        func_00176A50((char *)self, 2, 5);
        self->timer = 25;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 0;
        break;
    case 3:
        if (--self->timer <= 0) {
            self->timer = 15;
            self->base.phase = 4;
            self->base.step = 0;
            self->base.stepArg = 0;
            if (self->bodyHit != 0) {
                cDamageUnit_SetDamageCollActive(self->bodyHit, 0);
            }
        }
        break;
    case 4:
        self->timer--;
        self->base.animRate = self->timer / 15.0f;
        if (self->timer <= 0) {
            self->base.phase = 5;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 5:
        SET_MODE(self, 3)
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00175F38);
#endif
