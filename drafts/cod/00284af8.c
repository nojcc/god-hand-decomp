/* sn-2.95.3-136 */
/* NON_MATCHING func_00284AF8 (extern_jtbl D_00448A70, D_00448A90): one word
 * short. Retail has a dead `daddu v0, zero, zero` between the two hit point
 * stores, before the appearance switch; ours has none. Every other word lines
 * up. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cModel.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"
#include "godhand/vecInline.h"

/* This enemy keeps other records than the ones cEm00.h names at these
 * offsets: its room record copy over unk155C and unk1560, four damage
 * sphere handles over unk678, its shadow work at 0x690, the eight hand and
 * mask meshes over hitWait, partYaw and hitPos, and its weapon in hitPos.w. */
#define EMHAND_SET(self)     ((SET_EM_DATA *)((char *)(self) + 0x1530))
#define EMHAND_SPHERE(self)  ((int *)((char *)(self) + 0x674))
#define EMHAND_SHADOW(self)  ((char *)(self) + 0x690)
#define EMHAND_MESH(self)    ((cModelNode **)((char *)(self) + 0x15CC))
#define EMHAND_WEAPON(self)  (*(cGameObj **)((char *)(self) + 0x15EC))

#define MOTION(off) ((char *)EM_RES_REC(self->resource, off))

extern unsigned char D_00747A50[];
extern char D_00574380[];
extern char D_003C3F68[];
extern char D_00448A08[];
extern char D_00448A18[];
extern char D_00448A28[];
extern char D_00448A30[];
extern char D_00448A38[];
extern char D_00448A40[];
extern char D_00448A48[];
extern char D_00448A50[];
extern char D_00448A58[];
extern char D_00448A60[];

/* Sets up the enemy from its room entry: copies the entry, sets the hit
 * points for the difficulty, starts the motion the entry's appearance picks
 * (appearance 9 also gets a weapon in its hand), builds the damage spheres
 * and the solid collision, looks up the hand meshes and rolls the item it
 * drops. Returns 0 if the model can't be loaded. */
__attribute__((section(".text.func_00284AF8")))
int func_00284AF8(cEm00 *self, SET_EM_DATA *data, int arg)
{
    cVec held;
    cVec ofs;
    cOmBase *child;
    unsigned int roll;

    SET_EM_DATA_copy(EMHAND_SET(self), data);
    /* The room entry's number is also the enemy number. */
    self->emNo = data->seBank;
    if (func_00288DA8(self) == 0) {
        return 0;
    }
    func_0028EBF0(self, data, arg);
    self->link = 0;
    EMHAND_WEAPON(self) = 0;
    switch (D_00747A50[1]) {
    case 1:
    default:
        self->vitalMax = self->vital = 500;
        break;
    case 2:
        self->vitalMax = self->vital = 600;
        break;
    case 3:
        self->vitalMax = self->vital = 700;
        break;
    case 4:
        self->vitalMax = self->vital = 800;
        break;
    case 5:
        self->vitalMax = self->vital = 900;
        break;
    case 6:
        self->vitalMax = self->vital = 1000;
        break;
    case 7:
        self->vitalMax = self->vital = 1100;
        break;
    case 8:
        self->vitalMax = self->vital = 1200;
        break;
    }
    switch (EMHAND_SET(self)->appPattern) {
    case 0:
    default:
        self->mode = 0;
        self->phase = 2;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x28), MOTION(0x2C), 0, 1.0f, 0.0f, 0);
        break;
    case 1:
        self->mode = 0;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0xC0), MOTION(0xC4), 0, 1.0f, 0.0f, 0);
        break;
    case 2:
        self->mode = 0;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 1;
        setMotionInfo((struct cObjBase *)self, MOTION(0xC8), MOTION(0xCC), 0, 1.0f, 0.0f, 0);
        break;
    case 3:
        self->mode = 0;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 2;
        setMotionInfo((struct cObjBase *)self, MOTION(0xD0), MOTION(0xD4), 0, 1.0f, 0.0f, 0);
        break;
    case 4:
        self->mode = 0;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 3;
        setMotionInfo((struct cObjBase *)self, MOTION(0xD8), MOTION(0xDC), 0, 1.0f, 0.0f, 0);
        break;
    case 5:
        self->mode = 0;
        self->phase = 2;
        self->step = 0;
        self->stepArg = 1;
        setMotionInfo((struct cObjBase *)self, MOTION(0x28), MOTION(0x2C), 0, 1.0f, 0.0f, 0);
        break;
    case 6:
        self->mode = 0;
        self->phase = 5;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x110), MOTION(0x114), 0, 1.0f, 0.0f, 0);
        break;
    case 7:
        self->mode = 0;
        self->phase = 6;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x120), MOTION(0x124), 0, 1.0f, 0.0f, 0);
        break;
    case 8:
        self->vitalMax = 200;
        self->vital = 200;
        self->mode = 0;
        self->phase = 7;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x140), MOTION(0x144), 0, 0.0f, 0.0f, 0);
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448A08));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448A18));
        break;
    case 9:
        self->timer = 30.0f;
        self->timer2 = 30.0f;
        self->mode = 0;
        self->phase = 8;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x168), MOTION(0x16C), 0, 0.0f, 0.0f, 0);
        EMHAND_WEAPON(self) = CreateObj(0x3B1, 0xFFFF);
        if (EMHAND_WEAPON(self) != 0) {
            CVEC_ZERO(held);
            CVEC_ZERO(ofs);
            cGameObj_vt(EMHAND_WEAPON(self))->unk44((char *)EMHAND_WEAPON(self) + cGameObj_vt(EMHAND_WEAPON(self))->unk40Delta);
            cVec_copy3(EMHAND_WEAPON(self)->pos, self->pos);
            cVec_copy3(&EMHAND_WEAPON(self)->posA, self->pos);
            vec3_set(&EMHAND_WEAPON(self)->rot.x, 0.0f, 0.0f, 0.0f);
            held.x = -0.1f;
            held.y = 0.05f;
            held.z = 0.0f;
            ofs.x = 0.0f;
            ofs.y = 0.0f;
            ofs.z = 0.6f;
            cOmWeapon_setParent((cOmWeapon *)EMHAND_WEAPON(self), (cOmBase *)self, 2, &held, &ofs);
        }
        SetEffect(1, 2, self, 0, -1, 0xFFFFFFFF);
        break;
    case 10:
        self->mode = 0;
        self->phase = 3;
        self->step = 0;
        self->stepArg = 4;
        setMotionInfo((struct cObjBase *)self, MOTION(0x148), MOTION(0x14C), 0, 0.0f, 0.0f, 0);
        break;
    case 11:
        self->mode = 0;
        self->phase = 9;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x168), MOTION(0x16C), 0, 0.0f, 0.0f, 0);
        break;
    case 12:
        self->mode = 0;
        self->phase = 10;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x180), MOTION(0x184), 0, 0.0f, 0.0f, 0);
        break;
    case 13:
        self->mode = 0;
        self->phase = 1;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x140), MOTION(0x144), 0, 0.0f, 0.0f, 0);
        break;
    case 14:
        self->mode = 0;
        self->phase = 11;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x140), MOTION(0x144), 0, 0.0f, 0.0f, 0);
        self->gotoFlags |= 0x40;
        break;
    case 15:
        self->mode = 0;
        self->phase = 12;
        self->step = 0;
        self->stepArg = 0;
        setMotionInfo((struct cObjBase *)self, MOTION(0x140), MOTION(0x144), 0, 0.0f, 0.0f, 0);
        break;
    }
    moveMotion(self);
    cModel_calcParts((cModel *)self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts((cModel *)self);
    cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
    cVec_copy3(&self->unk1590, self->pos);
    cParts_setRotationOrder((char *)self, 4);
    cObjBase_KageInit((struct cObjBase *)self, EMHAND_SHADOW(self), D_003C3F68);
    self->atkHit = cDamageManage_CreateDamageTake(D_00574380, self, 1);

    /* Four damage spheres, each centred on a joint of the model. */
    child = cOmBase_childAt((cOmBase *)self, (int *)&held, 1);
    held.x = 0.0f;
    held.y = 0.0f;
    held.z = 0.0f;
    held.w = 1.0f;
    EMHAND_SPHERE(self)[0] = cDamageUnit_AddDamageCollSphere(self->atkHit, child->mtx, &held.x, 0.25f);
    child = cOmBase_childAt((cOmBase *)self, (int *)&held, 3);
    held.x = 0.0f;
    held.y = 0.0f;
    held.z = 0.0f;
    held.w = 1.0f;
    EMHAND_SPHERE(self)[1] = cDamageUnit_AddDamageCollSphere(self->atkHit, child->mtx, &held.x, 0.25f);
    child = cOmBase_childAt((cOmBase *)self, (int *)&held, 0x13);
    held.x = 0.0f;
    held.y = 0.0f;
    held.z = 0.0f;
    held.w = 1.0f;
    EMHAND_SPHERE(self)[2] = cDamageUnit_AddDamageCollSphere(self->atkHit, child->mtx, &held.x, 0.25f);
    child = cOmBase_childAt((cOmBase *)self, (int *)&held, 0x17);
    held.x = 0.0f;
    held.y = 0.0f;
    held.z = 0.0f;
    held.w = 1.0f;
    EMHAND_SPHERE(self)[3] = cDamageUnit_AddDamageCollSphere(self->atkHit, child->mtx, &held.x, 0.25f);

    cCollisionSolidManage_CreateUnit(D_00462FC0, self, 5, 0.2f);
    held.x = 0.0f;
    held.y = 0.5f;
    held.z = 0.0f;
    held.w = 1.0f;
    cCollisionSolidManage_CreateSphere((int)D_00462FC0, (int)self, (int)self->mtx, (int)&held, 0.5f);

    self->stepVar.time = 0.02f;
    self->unk15B8 = 0;
    self->unk15BC = fRand0_1() * 90.0f + 90.0f;
    EMHAND_MESH(self)[0] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A28);
    EMHAND_MESH(self)[1] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A30);
    EMHAND_MESH(self)[2] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A38);
    EMHAND_MESH(self)[3] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A40);
    EMHAND_MESH(self)[4] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A48);
    EMHAND_MESH(self)[5] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A50);
    EMHAND_MESH(self)[6] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A58);
    EMHAND_MESH(self)[7] = cModel_getMeshPtr_14B730((cModel *)self, D_00448A60);
    cModelNode_hide(EMHAND_MESH(self)[0]);
    cModelNode_hide(EMHAND_MESH(self)[1]);
    cModelNode_hide(EMHAND_MESH(self)[2]);
    cModelNode_hide(EMHAND_MESH(self)[3]);
    cModelNode_hide(EMHAND_MESH(self)[4]);
    cModelNode_hide(EMHAND_MESH(self)[5]);
    cModelNode_hide(EMHAND_MESH(self)[6]);
    cModelNode_hide(EMHAND_MESH(self)[7]);
    cModelNode_show(EMHAND_MESH(self)[0]);
    cModelNode_show(EMHAND_MESH(self)[4]);
    self->unk1604 = 1;
    roll = irand() & 0xF;
    self->dropItem = 0x3C1;
    if (roll >= 7) self->dropItem = 0x3C8;
    if (roll >= 13) self->dropItem = 0x3D1;
    if (roll >= 15) self->dropItem = 0x3D0;
    if ((irand() & 7) == 0) self->dropItem = 0x3D8;
    if (EMHAND_SET(self)->flags & 0x10000000)
        self->gotoFlags |= 0x40;
    self->stepScale = 150.0f;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00284AF8);
#endif
