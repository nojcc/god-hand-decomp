/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cModel.h"
#include "godhand/cObjBase.h"
#include "include_asm.h"

/* 827 of 830 words. Still differs: the first guard's (f & 0x80) == 0 folds
 * to a shift and xori where retail has andi and sltiu; retail keeps self in
 * s1 and the pose in s0 (swapped here); the %hi parts of D_00445230/38 are
 * held in saved registers here and reloaded in retail. */

extern char D_00445208[];
extern char D_00445210[];
extern char D_00445218[];
extern char D_00445220[];
extern char D_00445228[];
extern char D_00445230[];
extern char D_00445238[];
extern char D_00445240[];
extern char D_00445248[];
extern char D_00445250[];
extern char D_00445258[];
extern char D_00445260[];
extern char D_00445268[];
extern char D_00445270[];
extern char D_00445278[];
extern char D_00445280[];
extern char D_00445288[];
extern char D_00445290[];
extern char D_00445298[];
extern char D_004452A0[];
extern char D_004452A8[];
extern char D_004452B0[];
extern char D_004452B8[];
extern char D_004452C0[];
extern char D_004452C8[];
extern char D_004452D0[];


#define EM_FLAGS2_TEX_SWAP  0x04400000  /* emFlags2: the enemy wears its swapped texture */
#define EM_FLAGS2_SWAP_FX   0x00800000  /* emFlags2: the swap effect is running */
#define EM_FLAGS2_HANDS_OFF 0x00000200  /* emFlags2: the hand meshes are left as they are */

/* The 64-bit word that holds moveFlags in its bits 32..47. Retail tests two
 * moveFlags bits at once through this word; the halfword field gives an lhu. */
#define EM_MOVE_WORD(self)  (*(unsigned long *)((char *)(self) + 0x3A8))

#define EM_MESH_HIDE(self, name)                                        \
    mesh = cModel_getMeshPtr_14B730((cModel *)(self), (name));          \
    if (mesh != 0)                                                      \
        mesh->dispFlags |= CMODEL_NODE_HIDE

#define EM_MESH_SHOW(self, name)                                        \
    mesh = cModel_getMeshPtr_14B730((cModel *)(self), (name));          \
    if (mesh != 0)                                                      \
        mesh->dispFlags &= ~CMODEL_NODE_HIDE

/* The moveFlags bits of each hand's pose: the low bit gives pose 1, the
 * high bit pose 2, both pose 3. */
#define EM_HAND_A_LO    0x80
#define EM_HAND_A_HI    0x8000
#define EM_HAND_B_LO    0x40
#define EM_HAND_B_HI    0x4000
#define EM_HAND_A_BOTH  ((unsigned long)(EM_HAND_A_LO | EM_HAND_A_HI) << 32)
#define EM_HAND_B_BOTH  ((unsigned long)(EM_HAND_B_LO | EM_HAND_B_HI) << 32)

/* 1 when no hold or grab state (emFlags2 0x80, 0x100, 0x10000) keeps the
 * first hand's mesh as it is. */
static __inline__ int cEm00_firstHandFree(cEm00 *self)
{
    int f = self->emFlags2;
    int shown = (f & 0x80) == 0;

    if (f & 0x100)
        shown = 0;
    if (f & 0x10000)
        shown = 0;
    return shown;
}

#ifdef NON_MATCHING
/* Show the meshes that go with the enemy's type and state: the swapped
 * texture and its effect for 0x256 and 0x27E, the type's own meshes, then
 * one mesh per hand for its pose. */
__attribute__((section(".text.func_00268DC8")))
void func_00268DC8(cEm00 *self)
{
    cEffectParam param;
    cModelNode *mesh;
    unsigned int pose;

    cEffectParam_init(&param);
    param.size = self->unk114;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;

    switch (self->emNo) {
    case 0x20B:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
        return;
    }

    switch (self->emNo) {
    case 0x256:
        if (self->emFlags2 & EM_FLAGS2_TEX_SWAP) {
            self->texFlags |= CMODEL_TEX_EXCHANGE;
            cModel_setTextureExchange((cModel *)self, (void *)self->texSet,
                                      (cTexTable *)EM_RES_REC(self->resource, 0x84), 0);
            if (!(self->emFlags2 & EM_FLAGS2_SWAP_FX)) {
                self->emFlags2 |= EM_FLAGS2_SWAP_FX;
                SetEffect(0xAE, 1, self, &param, 1, -1);
            }
        } else {
            self->texFlags &= ~CMODEL_TEX_EXCHANGE;
            if (self->emFlags2 & EM_FLAGS2_SWAP_FX) {
                self->emFlags2 &= ~EM_FLAGS2_SWAP_FX;
                KillEffect((int)self, 1, 2);
            }
        }
        break;
    case 0x27E:
        if (self->emFlags2 & EM_FLAGS2_TEX_SWAP) {
            self->texFlags |= CMODEL_TEX_EXCHANGE;
            cModel_setTextureExchange((cModel *)self, (void *)self->texSet,
                                      (cTexTable *)EM_RES_REC(self->resource, 0x90), 0);
            if (!(self->emFlags2 & EM_FLAGS2_SWAP_FX)) {
                self->emFlags2 |= EM_FLAGS2_SWAP_FX;
                SetEffect(0, 0x72, self, &param, 1, -1);
            }
        } else {
            self->texFlags &= ~CMODEL_TEX_EXCHANGE;
            if (self->emFlags2 & EM_FLAGS2_SWAP_FX) {
                self->emFlags2 &= ~EM_FLAGS2_SWAP_FX;
                KillEffect((int)self, 1, 2);
            }
        }
        break;
    }

    if (self->hand[0] != 0)
        self->hand[0]->dispFlags |= CMODEL_NODE_HIDE;
    if (self->hand[1] != 0)
        self->hand[1]->dispFlags |= CMODEL_NODE_HIDE;
    if (self->hand[2] != 0)
        self->hand[2]->dispFlags |= CMODEL_NODE_HIDE;
    if (self->hand[3] != 0)
        self->hand[3]->dispFlags |= CMODEL_NODE_HIDE;
    if (self->hand[4] != 0)
        self->hand[4]->dispFlags |= CMODEL_NODE_HIDE;
    if (self->hand[5] != 0)
        self->hand[5]->dispFlags |= CMODEL_NODE_HIDE;

    switch (self->emNo) {
    case 0x276:
        EM_MESH_HIDE(self, D_00445228);
        /* fall through */
    case 0x275:
        EM_MESH_HIDE(self, D_00445230);
        EM_MESH_HIDE(self, D_00445238);
        EM_MESH_HIDE(self, D_00445240);
        EM_MESH_HIDE(self, D_00445248);
        EM_MESH_HIDE(self, D_00445250);
        EM_MESH_HIDE(self, D_00445258);
        EM_MESH_HIDE(self, D_00445260);
        EM_MESH_HIDE(self, D_00445268);
        EM_MESH_HIDE(self, D_00445270);
        EM_MESH_HIDE(self, D_00445278);
        EM_MESH_HIDE(self, D_00445280);
        if (self->emFlags2 & 0x200) {
            EM_MESH_SHOW(self, D_00445228);
            EM_MESH_SHOW(self, D_00445268);
            EM_MESH_SHOW(self, D_00445270);
        }
        if (self->emFlags2 & 0x80) {
            EM_MESH_SHOW(self, D_00445258);
            EM_MESH_SHOW(self, D_00445260);
        } else if (self->emFlags2 & 0x100) {
            EM_MESH_SHOW(self, D_00445230);
            if (self->unk1869 > 0) {
                EM_MESH_SHOW(self, D_00445238);
            }
            if (self->unk1869 >= 2) {
                EM_MESH_SHOW(self, D_00445240);
            }
            if (self->unk1869 >= 3) {
                EM_MESH_SHOW(self, D_00445248);
            }
            if (self->unk1869 >= 4) {
                EM_MESH_SHOW(self, D_00445250);
            }
        } else if (!(self->emFlags2 & 0x10000)) {
            EM_MESH_SHOW(self, D_00445268);
            EM_MESH_SHOW(self, D_00445270);
        }
        EM_MESH_SHOW(self, D_00445278);
        EM_MESH_SHOW(self, D_00445280);
        break;
    case 0x223:
        EM_MESH_SHOW(self, D_00445288);
        EM_MESH_HIDE(self, D_00445290);
        EM_MESH_SHOW(self, D_00445298);
        EM_MESH_HIDE(self, D_004452A0);
        EM_MESH_SHOW(self, D_004452A8);
        EM_MESH_HIDE(self, D_004452B0);
        EM_MESH_SHOW(self, D_004452B8);
        EM_MESH_HIDE(self, D_004452C0);
        return;
    case 0x242:
    case 0x243:
    case 0x244:
        if (self->hand[1] != 0)
            self->hand[1]->dispFlags &= ~CMODEL_NODE_HIDE;
        if (self->hand[4] != 0)
            self->hand[4]->dispFlags &= ~CMODEL_NODE_HIDE;
        return;
    case 0x252:
        EM_MESH_HIDE(self, D_00445208);
        EM_MESH_HIDE(self, D_00445210);
        EM_MESH_HIDE(self, D_00445218);
        EM_MESH_HIDE(self, D_00445220);
        break;
    case 0x256:
    case 0x27E:
        EM_MESH_HIDE(self, D_004452C8);
        EM_MESH_HIDE(self, D_004452D0);
        break;
    }

    pose = 1;
    if (cEm00_firstHandFree(self)) {
        if (self->unk17C3 != 0) {
            if (!(self->moveFlags & EM_HAND_A_LO))
                pose = 0;
            if (self->moveFlags & EM_HAND_A_HI)
                pose = 2;
            if ((EM_MOVE_WORD(self) & EM_HAND_A_BOTH) == EM_HAND_A_BOTH)
                pose = 3;
        } else {
            if (!(self->moveFlags & EM_HAND_B_LO))
                pose = 0;
            if (self->moveFlags & EM_HAND_B_HI)
                pose = 2;
            if ((EM_MOVE_WORD(self) & EM_HAND_B_BOTH) == EM_HAND_B_BOTH)
                pose = 3;
        }
        switch (pose) {
        case 0:
        default:
            mesh = self->hand[0];
            break;
        case 1:
            mesh = self->hand[1];
            break;
        case 2:
            mesh = self->hand[2];
            break;
        case 3:
            mesh = cModel_getMeshPtr_14B730((cModel *)self, D_004452C8);
            break;
        }
        if (mesh != 0)
            mesh->dispFlags &= ~CMODEL_NODE_HIDE;
        if (self->emNo == 0x252) {
            switch (pose) {
            case 1:
                EM_MESH_SHOW(self, D_00445210);
                break;
            case 2:
            case 3:
                break;
            default:
                EM_MESH_SHOW(self, D_00445208);
                break;
            }
        }
    }

    pose = 1;
    if (!(self->emFlags2 & EM_FLAGS2_HANDS_OFF)) {
        if (self->unk17C3 != 0) {
            if (!(self->moveFlags & EM_HAND_B_LO))
                pose = 0;
            if (self->moveFlags & EM_HAND_B_HI)
                pose = 2;
            if ((EM_MOVE_WORD(self) & EM_HAND_B_BOTH) == EM_HAND_B_BOTH)
                pose = 3;
        } else {
            if (!(self->moveFlags & EM_HAND_A_LO))
                pose = 0;
            if (self->moveFlags & EM_HAND_A_HI)
                pose = 2;
            if ((EM_MOVE_WORD(self) & EM_HAND_A_BOTH) == EM_HAND_A_BOTH)
                pose = 3;
        }
        switch (pose) {
        case 0:
        default:
            mesh = self->hand[3];
            break;
        case 1:
            mesh = self->hand[4];
            break;
        case 2:
            mesh = self->hand[5];
            break;
        case 3:
            mesh = cModel_getMeshPtr_14B730((cModel *)self, D_004452D0);
            break;
        }
        if (mesh != 0)
            mesh->dispFlags &= ~CMODEL_NODE_HIDE;
        if (self->emNo == 0x252) {
            switch (pose) {
            case 1:
                EM_MESH_SHOW(self, D_00445220);
                break;
            case 2:
                break;
            default:
                EM_MESH_SHOW(self, D_00445218);
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00268DC8);
#endif
