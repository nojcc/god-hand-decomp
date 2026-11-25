#include "godhand/cEm00.h"
#include "godhand/cCamManager.h"
#include "godhand/cDamageUnitFn.h"
#include "godhand/motion.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cPartsCamera_SetParts(void *parts, void *obj, cOmBase *a2, cOmBase *a3);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);

/* Phase machine on the step byte, 19 case labels. Calls Getplayer, func_002A8578, func_0025FE30,
 * cDamageUnit_SetDamageCollActive, moveMotion, cObjBase_addNullSpeed_Rotation and 4 more. */
__attribute__((section(".text.func_0025FA18"))) void func_0025FA18(cEm00 *self)
{
    void *parts;
    cGameObj *pl;
    cDamageUnit *s2;
    int v0;
    cGameObjVt *vt;
    float one;
    cCamManager *mgr;
    cOmBase *a2v;
    cOmBase *a3v;
    int spill[2];

    pl = Getplayer();
    vt = cGameObj_vt((cGameObj *)self);
    s2 = vt->getDamageUnit((char *)self + vt->damageUnitDelta);
    self->hitFlash = 3.0f;
    if (self->step == 0) {
        switch (self->emNo) {
            case 0x21A:
            case 0x21B:
            case 0x21D:
            case 0x21E:
            case 0x225:
            case 0x22C:
            case 0x22D:
            case 0x22E:
            case 0x22F:
            case 0x248:
            case 0x249:
            case 0x24C:
            case 0x24D:
            case 0x24E:
            case 0x25A:
                self->step = 2;
                break;
        }
    }
    switch (self->step) {
        case 0:
            v0 = EM_RES(self);
            func_002A8578(self, EM_RES_REC(v0, 0x444), EM_RES_REC(v0, 0x448), 0, 0.0f, 0, 0);
            self->seqFlags = self->seqFlags & 0xFDFF;
            self->unk617 = 1;
            func_0025FE30(self, 0x400000, 1);
            cDamageUnit_SetDamageCollActive(s2, 0);
            self->unk568 = 0xDD;
            self->step = self->step + 1;
        case 1:
            one = 1.0f;
            self->motionFlags = self->motionFlags | 8;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (self->unk568 != 0) {
                self->unk568 = self->unk568 - 1;
            } else {
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        case 2:
            v0 = EM_RES(self);
            func_002A8578(self, EM_RES_REC(v0, 0x153C), EM_RES_REC(v0, 0x1540), 0, 0.0f, 0, 0);
            self->seqFlags = self->seqFlags & 0xFDFF;
            self->unk617 = 1;
            func_0025FE30(self, 0x400000, 1);
            cDamageUnit_SetDamageCollActive(s2, 0);
            self->unk568 = 0x11D;
            self->step = self->step + 1;
        case 3:
            mgr = &D_00463050;
            cCamManager_setPartsCamera(mgr, 0);
            parts = &mgr->parts;
            a2v = cOmBase_childAt((cOmBase *)self, spill, 0x1B);
            a3v = cOmBase_childAt((cOmBase *)self, spill, 0x1C);
            one = 1.0f;
            cPartsCamera_SetParts(parts, self, a2v, a3v);
            self->motionFlags = self->motionFlags | 8;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (self->unk568 != 0) {
                self->unk568 = self->unk568 - 1;
            } else {
                pl00_clearMotionCam(pl, 0, 1);
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
