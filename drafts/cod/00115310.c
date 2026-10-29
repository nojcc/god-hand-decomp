/* sn-2.95.3-136 */
/* NON_MATCHING func_00115310: retail moves Turn_dest's result to $f1 and
 * loads the 0.0 for the sign test into $f0, so the absolute value is
 * mov.s/neg.s from $f1; here the result stays in $f0 and the zero takes $f1.
 * Needs the pl00.h and motion.h overlays (motionBlock_at). */
#include "godhand/pl00.h"
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cVec.h"
#include "godhand/angle.h"
#include "godhand/motion.h"
#include "godhand/sceVu0.h"

struct ThrowerObj;

extern char D_005CAE50[];
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void cOm_attachThrown(struct ThrowerObj *self);
extern void func_001331B8(void *a0, long a1, int a2);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float Adjust_theta(float f12);

/* The player's catch: step 0 aims unk580 straight ahead, looks for an enemy
 * within 40 and pi of the facing, and if one is found aims at it; the catch
 * motion and its partner's motion are the back pair when the enemy is more
 * than 3/4 pi off the facing, the front pair otherwise. Step 1 turns toward
 * unk580 while the motion allows it, and ends the state with the motion. */
__attribute__((section(".text.func_00115310")))
void func_00115310(pl00 *self)
{
    cVec pos;
    cGameObj *target;
    cVec *from;
    cVec *at;
    float rel;
    float turn;
    float off;
    int back;

    self->base.hitFlash = 5.0f;
    cEmManage_SetSlotWait(&D_005864F0, 2);
    cEmManage_SetPlCatched(&D_005864F0);
    self->unk5DC = 1.25f;
    self->base.speedRate = 1.25f;
    SetMotionStep(self, 1.25f);
    switch (self->base.step) {
    case 0:
        self->comboSlot = 0;
        self->comboSet = 0;
        back = 0;
        func_001268F0(self);
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->base.unk580.x = 0.0f;
        self->base.unk580.y = 0.0f;
        self->base.unk580.z = 1.0f;
        sceVu0ApplyMatrix(&self->base.unk580, self->base.mtx, &self->base.unk580);
        CVEC_COPY(pos, self->base.pos);
        target = func_00291010(&D_005864F0, &pos, self->base.rot.y, 40.0f, 3.1415927f, 0, 0, 0);
        self->unk640 = target;
        if (target != 0) {
            at = cGameObj_vt(target)->getPos((char *)target + cGameObj_vt(target)->getPosDelta);
            CVEC_PUT(&self->base.unk580, *at);
            from = self->base.pos;
            at = cGameObj_vt(self->unk640)->getPos((char *)self->unk640 + cGameObj_vt(self->unk640)->getPosDelta);
            rel = Turn_dest((float *)from, (float *)at, self->base.rot.y, 3.1415927f);
            if (rel < 0.0f)
                off = -rel;
            else
                off = rel;
            if (2.3561945f < off)
                back = 1;
        }
        self->unk15C0 = self->base.rot.y;
        if (back != 0) {
            cOm_attachThrown((struct ThrowerObj *)self);
            if (self->sub6A0 != 0) {
                func_002A8578((int)self->sub6A0, motionBlock_at(self->base.pack, 0x378),
                              motionBlock_at(self->base.pack, 0x394), 0, 0.0f, 0, 0);
                func_001331B8(D_005CAE50, ((cOmBase *)self->sub6A0)->modelHandle, 0);
            }
            func_002A8578((int)self, motionBlock_at(self->base.pack, 0x35C),
                          motionBlock_at(self->base.pack, 0x360), 0, 0.0f, 0, 0);
            self->unk15C0 = self->base.rot.y + 3.1415927f;
            self->unk15C0 = Adjust_theta(self->unk15C0);
        } else {
            cOm_attachThrown((struct ThrowerObj *)self);
            if (self->sub6A0 != 0) {
                func_002A8578((int)self->sub6A0, motionBlock_at(self->base.pack, 0x6E8),
                              motionBlock_at(self->base.pack, 0x6EC), 0, 0.0f, 0, 0);
                func_001331B8(D_005CAE50, ((cOmBase *)self->sub6A0)->modelHandle, 0);
            }
            func_002A8578((int)self, motionBlock_at(self->base.pack, 0x6E0),
                          motionBlock_at(self->base.pack, 0x6E4), 0, 0.0f, 0, 0);
        }
        Obj0000_Clear_Fields_640_648_124E58(self);
        self->base.step++;
    case 1:
        func_00124EC0(self);
        if (self->base.motionFlags & 0x10) {
            turn = Turn_dest((float *)self->base.pos, (float *)&self->base.unk580, self->unk15C0, 0.2244f);
            self->unk15C0 = self->unk15C0 + turn;
            self->unk15C0 = Adjust_theta(self->unk15C0);
            self->base.rot.y = self->base.rot.y + turn;
            self->base.rot.y = Adjust_theta(self->base.rot.y);
        }
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 1, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
}
