/* sn-2.95.3-136 */
#include "include_asm.h"

#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cModel.h"
#include "godhand/motion.h"
#include "godhand/player.h"

/* The base enemy keeps other records than the ones cEm00.h names for the
 * derived enemies at these offsets: its room entry copy at 0x1510, its
 * shadow work over atkHit, fourteen mesh nodes from 0x1550 over unk155C to
 * watchArg, five weapon objects from 0x1638 over flags1644, and four child
 * objects from 0x164C over unk1650. */
#define CEM00_SET(self)     ((SET_EM_DATA *)((char *)(self) + 0x1510))
#define CEM00_SHADOW(self)  ((char *)(self) + 0x670)
#define CEM00_MESH(self)    ((cModelNode **)((char *)(self) + 0x1550))
#define CEM00_WEAPON(self)  ((char **)((char *)(self) + 0x1638))
#define CEM00_CHILD(self)   ((cGameObj **)((char *)(self) + 0x164C))

#define MOTION(off) EM_RES_REC(self->resource, off)
#define START_MOTION(off) func_002A8578((int)self, MOTION(off), 0, 0, 0.0f, 0, 0)
#define SET_SCALE(s) (self->unk110 = self->unk114 = self->unk118 = (s))

/* Copies the room entry into the enemy (asm; its callers disagree on the types). */
extern void func_0028EBF0(cEm00 *self, SET_EM_DATA *data, int arg);
extern unsigned char D_00747A50[];
extern char D_003C3F68[];
extern char D_00448F38[];
extern char D_00448F40[];
extern char D_00448F48[];
extern char D_00448F50[];
extern char D_00448F58[];
extern char D_00448F60[];
extern char D_00448F68[];
extern char D_00448F70[];
extern char D_00448F78[];
extern char D_00448F80[];
extern char D_00448F90[];
extern char D_00448F98[];
extern char D_00448FA0[];
extern char D_00448FA8[];
extern char D_00448FB8[];
extern char D_00448FC0[];
extern char D_00448FC8[];
extern char D_00448FD8[];
extern char D_00448FE8[];
extern char D_00448FF0[];
extern char D_00448FF8[];
extern char D_00449000[];
extern char D_00449008[];

/* Sets up an enemy from its room entry: copies the entry, loads the model,
 * sets the model scale for the enemy number, starts the appearance's
 * motion, looks up and hides the meshes, creates the weapons and the child
 * objects some enemies carry. Returns 0 if the model can't be loaded. */
__attribute__((section(".text.func_0028B190")))
int func_0028B190(cEm00 *self, SET_EM_DATA *data, int arg)
{
    SET_EM_DATA_copy(CEM00_SET(self), data);
    self->emNo = data->seBank;
    if (func_0028C400(self) == 0) {
        return 0;
    }
    func_0028EBF0(self, data, arg);
    self->link = 0;
    func_0028CED8(self);
    func_0028CDD0((char *)self);
    SET_SCALE(1.04f);
    switch (self->emNo) {
    case 0x220: case 0x221: case 0x222:
        SET_SCALE(1.2f);
        break;
    case 0x223:
        SET_SCALE(1.0f);
        break;
    case 0x250: case 0x251:
        SET_SCALE(1.2f);
        break;
    case 0x260:
        SET_SCALE(2.0f);
        break;
    case 0x264:
        SET_SCALE(1.5f);
        break;
    case 0x265:
        SET_SCALE(1.5f);
        break;
    case 0x26A:
        SET_SCALE(20.0f);
        break;
    case 0x23B:
        SET_SCALE(1.15f);
        break;
    case 0x205: case 0x206: case 0x207: case 0x209: case 0x20A: case 0x20C:
    case 0x20D: case 0x20F: case 0x211: case 0x21F: case 0x224: case 0x245:
    case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
        SET_SCALE(1.0f);
        break;
    case 0x247:
        SET_SCALE(1.15f);
        break;
    case 0x241:
        SET_SCALE(1.08f);
        break;
    case 0x210: case 0x226:
        SET_SCALE(1.25f);
        break;
    case 0x21C:
        SET_SCALE(1.02f);
        if (D_00747A50[1] == 8) {
            SET_SCALE(1.15f);
        }
        break;
    case 0x208: case 0x20B:
        SET_SCALE(1.0f);
        break;
    case 0x275: case 0x276:
        SET_SCALE(1.3f);
        break;
    case 0x204: case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
    case 0x23A: case 0x243: case 0x244: case 0x24B:
        SET_SCALE(1.2f);
        break;
    case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        SET_SCALE(1.15f);
        break;
    case 0x24A:
        SET_SCALE(1.2f);
        break;
    case 0x249: case 0x24E:
        SET_SCALE(1.15f);
        break;
    case 0x225: case 0x24D:
        SET_SCALE(1.2f);
        break;
    case 0x278: case 0x279:
        SET_SCALE(1.2f);
        break;
    case 0x20E:
        SET_SCALE(1.0f);
        break;
    case 0x218: case 0x246:
        SET_SCALE(1.2f);
        break;
    case 0x256:
        SET_SCALE(1.1f);
        /* fallthrough: retail stores the same scale again */
    case 0x213: case 0x214: case 0x215: case 0x217: case 0x24F: case 0x252:
        SET_SCALE(1.1f);
        break;
    }
    switch (CEM00_SET(self)->appPattern) {
    case 0:
    default:
        START_MOTION(0x80);
        break;
    case 1:
        START_MOTION(0x84);
        break;
    case 2:
        START_MOTION(0x88);
        break;
    case 3:
        START_MOTION(0x8C);
        break;
    case 4:
        START_MOTION(0x90);
        break;
    case 5:
        START_MOTION(0x94);
        break;
    case 6:
        START_MOTION(0x98);
        break;
    case 7:
        START_MOTION(0x9C);
        break;
    case 8:
        START_MOTION(0xA0);
        break;
    case 9:
        START_MOTION(0xA4);
        break;
    case 10:
        START_MOTION(0xA8);
        break;
    case 11:
        START_MOTION(0xAC);
        break;
    case 12:
        START_MOTION(0xB0);
        break;
    case 13:
        START_MOTION(0xB4);
        break;
    case 14:
        START_MOTION(0xB8);
        break;
    case 15:
        START_MOTION(0xBC);
        break;
    case 16:
        START_MOTION(0xC0);
        break;
    case 17:
        START_MOTION(0xC4);
        break;
    case 18:
        START_MOTION(0xC8);
        break;
    case 19:
        START_MOTION(0xCC);
        break;
    case 20:
        START_MOTION(0xD0);
        break;
    case 21:
        START_MOTION(0xD4);
        break;
    case 22:
        START_MOTION(0xD8);
        break;
    case 23:
        START_MOTION(0xDC);
        break;
    case 24:
        START_MOTION(0xE0);
        break;
    case 25:
        START_MOTION(0xE4);
        break;
    case 26:
        START_MOTION(0xE8);
        break;
    }
    moveMotion(self);
    cModel_calcParts((cModel *)self);
    IK_InverseKinematics(self->ik, self);
    cModel_calcWorldParts((cModel *)self);
    cParts_setRotationOrder((char *)self, 4);
    cObjBase_KageInit((struct cObjBase *)self, CEM00_SHADOW(self), D_003C3F68);

    CEM00_MESH(self)[0] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F38);
    CEM00_MESH(self)[1] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F40);
    CEM00_MESH(self)[2] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F48);
    CEM00_MESH(self)[3] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F50);
    CEM00_MESH(self)[4] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F58);
    CEM00_MESH(self)[5] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F60);
    CEM00_MESH(self)[6] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F68);
    CEM00_MESH(self)[7] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F70);
    cModelNode_hide(CEM00_MESH(self)[0]);
    cModelNode_hide(CEM00_MESH(self)[2]);
    cModelNode_hide(CEM00_MESH(self)[3]);
    cModelNode_hide(CEM00_MESH(self)[4]);
    cModelNode_hide(CEM00_MESH(self)[6]);
    cModelNode_hide(CEM00_MESH(self)[7]);
    CEM00_MESH(self)[8] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F78);
    CEM00_MESH(self)[9] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F80);
    CEM00_MESH(self)[10] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F90);
    cModelNode_hide(CEM00_MESH(self)[10]);
    CEM00_MESH(self)[12] = cModel_getMeshPtr_14B730((cModel *)self, D_00448F98);
    switch (self->emNo) {
    case 0x22B:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FA0));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FA8));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FB8));
        break;
    case 0x204:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FB8));
        break;
    case 0x24A:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FC0));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FC8));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FD8));
        break;
    case 0x240:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FD8));
        break;
    case 0x201: case 0x228:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FE8));
        break;
    case 0x242:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FF0));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FF8));
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00449000));
        break;
    case 0x243: case 0x244:
        cModelNode_hide(cModel_getMeshPtr_14B730((cModel *)self, D_00448FF0));
        break;
    case 0x256:
        /* retail's table runs to this enemy, which hides no meshes */
        break;
    }
    CEM00_MESH(self)[13] = cModel_getMeshPtr_14B730((cModel *)self, D_00449008);
    cModelNode_hide(CEM00_MESH(self)[13]);

    CEM00_WEAPON(self)[0] = 0;
    CEM00_WEAPON(self)[1] = 0;
    CEM00_WEAPON(self)[2] = 0;
    CEM00_WEAPON(self)[3] = 0;
    switch (self->emNo) {
    case 0x205: case 0x207: case 0x224:
        CEM00_WEAPON(self)[0] = func_0028D048((char *)self, 0x365);
        cOmBase_attachWeaponGrip((cOmBase *)self, CEM00_WEAPON(self)[0], 0);
        CEM00_WEAPON(self)[1] = func_0028D048((char *)self, 0x365);
        cOmBase_attachWeaponGrip((cOmBase *)self, CEM00_WEAPON(self)[1], 1);
        break;
    case 0x225: case 0x24D:
        CEM00_WEAPON(self)[0] = func_0028D048((char *)self, 0x37D);
        cOmBase_attachWeaponGrip((cOmBase *)self, CEM00_WEAPON(self)[0], 0);
        CEM00_WEAPON(self)[1] = func_0028D048((char *)self, 0x37D);
        cOmBase_attachWeaponGrip((cOmBase *)self, CEM00_WEAPON(self)[1], 1);
        break;
    case 0x208:
        CEM00_WEAPON(self)[2] = func_0028D048((char *)self, 0x367);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[2], 0);
        break;
    case 0x21E:
        CEM00_WEAPON(self)[2] = func_0028D048((char *)self, 0x36C);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[2], 2);
        break;
    case 0x22F:
        CEM00_WEAPON(self)[2] = func_0028D048((char *)self, 0x370);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[2], 2);
        break;
    case 0x217:
        CEM00_WEAPON(self)[3] = func_0028D048((char *)self, 0x36F);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[3], 5);
        if (CEM00_WEAPON(self)[3] != 0) {
            Obj1D00_ClearState_7((cOmBase *)CEM00_WEAPON(self)[3]);
        }
        break;
    case 0x213:
        CEM00_WEAPON(self)[3] = func_0028D048((char *)self, 0x37A);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[3], 5);
        if (CEM00_WEAPON(self)[3] != 0) {
            Obj1D00_ClearState_7((cOmBase *)CEM00_WEAPON(self)[3]);
        }
        break;
    }
    if (CEM00_SET(self)->flags & 0x100) {
        CEM00_WEAPON(self)[2] = func_0028D048((char *)self, 0x37F);
        cOmWeapon_loadEffectParamsByType(self, (int)CEM00_WEAPON(self)[2], 10);
    }
    CEM00_WEAPON(self)[4] = 0;
    if (CEM00_SET(self)->flags & 0x200) {
        func_0028D138(self, (struct cOmWeapon *)func_0028D048((char *)self, 0x369), 0x369);
    }

    CEM00_CHILD(self)[3] = 0;
    if (self->emNo == 0x2FF) {
        CEM00_CHILD(self)[3] = CreateObj(0x101, 0xFFFF);
        if (CEM00_CHILD(self)[3] != 0) {
            if (cGameObj_vt(CEM00_CHILD(self)[3])->unk44((char *)CEM00_CHILD(self)[3] + cGameObj_vt(CEM00_CHILD(self)[3])->unk40Delta)) {
                pl01__SetParent(CEM00_CHILD(self)[3], self, 0x11);
                CEM00_CHILD(self)[3]->actorGroup &= 0x7FFFFFFF;
                CEM00_CHILD(self)[3]->actorGroup |= 0x40000000;
            } else {
                CEM00_CHILD(self)[3] = 0;
            }
        }
    }
    CEM00_CHILD(self)[0] = 0;
    if (self->emNo == 0x279) {
        CEM00_CHILD(self)[0] = CreateObj(0x27A, 0xFFFF);
        if (CEM00_CHILD(self)[0] != 0) {
            if (cGameObj_vt(CEM00_CHILD(self)[0])->unk44((char *)CEM00_CHILD(self)[0] + cGameObj_vt(CEM00_CHILD(self)[0])->unk40Delta)) {
                func_00283BE8((char *)CEM00_CHILD(self)[0], (char *)self, 2);
            } else {
                CEM00_CHILD(self)[0] = 0;
            }
        }
    }
    CEM00_CHILD(self)[1] = 0;
    if (self->emNo == 0x252) {
        CEM00_CHILD(self)[1] = CreateObj(0x253, 0xFFFF);
        if (CEM00_CHILD(self)[1] != 0) {
            if (cGameObj_vt(CEM00_CHILD(self)[1])->unk44((char *)CEM00_CHILD(self)[1] + cGameObj_vt(CEM00_CHILD(self)[1])->unk40Delta)) {
                cEm53_SetParent((char *)CEM00_CHILD(self)[1], (char *)self, 2);
            } else {
                CEM00_CHILD(self)[1] = 0;
            }
        }
    }
    CEM00_CHILD(self)[2] = 0;
    if (self->emNo == 0x256) {
        if (self->actorId == 0x258) {
            CEM00_CHILD(self)[2] = CreateObj(0x259, 0xFFFF);
        } else {
            CEM00_CHILD(self)[2] = CreateObj(0x257, 0xFFFF);
        }
        if (CEM00_CHILD(self)[2] != 0) {
            if (cGameObj_vt(CEM00_CHILD(self)[2])->unk44((char *)CEM00_CHILD(self)[2] + cGameObj_vt(CEM00_CHILD(self)[2])->unk40Delta)) {
                cEm57_SetParent((char *)CEM00_CHILD(self)[2], (char *)self, 0x11);
            } else {
                CEM00_CHILD(self)[2] = 0;
            }
        }
    }
    return 1;
}
