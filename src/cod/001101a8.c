/* sn-2.95.3-136 */
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/capVu0.h"
#include "godhand/motion.h"

/* Defined as int func_0010B2E8(BusyOwner *self, int flag); BusyOwner is its view of pl00. */
extern int func_0010B2E8(pl00 *self, int flag);
/* Defined with WeaponCarrier *self, 0012b2e0.c's view of pl00's weapon slot at 0x698. */
extern void WeaponCarrier_damageHeldWeapon(pl00 *self, int damage);
extern int func_00124540(void *a0, int a1);
extern void func_0010A438(void *a0);
extern int func_00123938(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);

/* Swing of the held weapon: wear the weapon, pick the swing motion and attack
 * parameters for the weapon type and side (stepArg), then play it out. */
__attribute__((section(".text.func_001101A8")))
void func_001101A8(pl00 *self)
{
    int motA;
    int motB;

    if (func_0010B2E8(self, 0) != 0 && self->sub698 != 0) {
        switch (self->base.stepArg) {
        case 0:
        default:
            WeaponCarrier_damageHeldWeapon(self, 10);
            break;
        case 1:
            WeaponCarrier_damageHeldWeapon(self, 15);
            break;
        }
        if (self->sub698 != 0
            && (self->sub698->actorId == 0x363 || self->sub698->actorId == 0x3B7)) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x137, self, 0, 0, 0, 0);
        }
    }

    switch (self->base.step) {
    case 0:
        self->comboSlot = 0;
        self->comboSet = 0;
        func_00124540(self, 0);
        switch (self->base.stepArg) {
        case 0:
        default:
            self->unk1684 = 0;
            switch (self->sub698->actorId) {
            default:
                motA = EM_RES_REC((int)self->base.pack, 0x3B4);
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                break;
            case 0x377:
            case 0x378:
                motA = EM_RES_REC((int)self->base.pack, 0x90C);
                motB = EM_RES_REC((int)self->base.pack, 0x910);
                break;
            case 0x36D:
            case 0x3AA:
            case 0x3AB:
                motA = EM_RES_REC((int)self->base.pack, 0x924);
                motB = EM_RES_REC((int)self->base.pack, 0x928);
                break;
            }
            if (self->sub698 == 0) {
                break;
            }
            switch (self->sub698->actorId) {
            case 0x361: /* listed in retail: the table starts at 0x361 */
            default:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 0x14, 0x1F, 0x32, 0x111);
                break;
            case 0x362:
            case 0x37B:
            case 0x390:
            case 0x3A9:
                motB = EM_RES_REC((int)self->base.pack, 0x3BC);
                pl00_setSwing(self, 0xF, 0x1F, 0x32, 0x112);
                break;
            case 0x3A8: /* retail keeps separate jump-table targets for 0x3A8 and 0x3AD */
                motB = EM_RES_REC((int)self->base.pack, 0x3BC);
                pl00_setSwing(self, 0x1E, 0x1F, 0x32, 0x112);
                break;
            case 0x3AD:
            case 0x3AE:
            case 0x3B4:
                motB = EM_RES_REC((int)self->base.pack, 0x3BC);
                pl00_setSwing(self, 0x1E, 0x1F, 0x32, 0x112);
                break;
            case 0x363:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 0x19, 0x1F, 0x32, 0x11D);
                break;
            case 0x380:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 4, 0x1F, 0x32, 0xEA);
                break;
            case 0x3B7:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 0x14, 0x1F, 0x32, 0x11D);
                break;
            case 0x368:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 0x1E, 0x1F, 0x32, 0x111);
                break;
            case 0x379:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 0x1E, 0x1F, 0x34, 0x112);
                break;
            case 0x3AF:
                motB = EM_RES_REC((int)self->base.pack, 0x3B8);
                pl00_setSwing(self, 1, 0x1F, 0x32, 0x11D);
                break;
            case 0x375:
            case 0x377:
            case 0x378:
                pl00_setSwing(self, 0x32, 0x1F, 0x32, 0xF0);
                break;
            case 0x3AA:
            case 0x3AB:
                pl00_setSwing(self, 0x14, 0x21, 0x32, 0xF0);
                break;
            case 0x36D:
                pl00_setSwing(self, 0x32, 0x21, 0x32, 0xF0);
                break;
            }
            break;
        case 1:
            self->unk1684 = 0;
            switch (self->sub698->actorId) {
            default:
                motA = EM_RES_REC((int)self->base.pack, 0x3C0);
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                break;
            case 0x377:
            case 0x378:
                motA = EM_RES_REC((int)self->base.pack, 0x914);
                motB = EM_RES_REC((int)self->base.pack, 0x918);
                break;
            case 0x36D:
            case 0x3AA:
            case 0x3AB:
                motA = EM_RES_REC((int)self->base.pack, 0x92C);
                motB = EM_RES_REC((int)self->base.pack, 0x930);
                break;
            }
            if (self->sub698 == 0) {
                break;
            }
            switch (self->sub698->actorId) {
            case 0x361: /* listed in retail: the table starts at 0x361 */
            default:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 0x28, 0x20, 0x33, 0x111);
                break;
            case 0x362: /* retail keeps separate jump-table targets for 0x362 and 0x37B */
                motB = EM_RES_REC((int)self->base.pack, 0x3C8);
                pl00_setSwing(self, 0x1E, 0x20, 0x33, 0x112);
                break;
            case 0x37B:
            case 0x390:
            case 0x3A9:
                motB = EM_RES_REC((int)self->base.pack, 0x3C8);
                pl00_setSwing(self, 0x1E, 0x20, 0x33, 0x112);
                break;
            case 0x3A8: /* retail keeps separate jump-table targets for 0x3A8 and 0x3AD */
                motB = EM_RES_REC((int)self->base.pack, 0x3C8);
                pl00_setSwing(self, 0x3C, 0x20, 0x33, 0x112);
                break;
            case 0x3AD:
            case 0x3AE:
            case 0x3B4:
                motB = EM_RES_REC((int)self->base.pack, 0x3C8);
                pl00_setSwing(self, 0x3C, 0x20, 0x33, 0x112);
                break;
            case 0x363:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 0x32, 0x20, 0x33, 0x11D);
                break;
            case 0x380:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 8, 0x20, 0x33, 0xEA);
                break;
            case 0x3B7:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 0x28, 0x20, 0x33, 0x11D);
                break;
            case 0x368:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 0x3C, 0x20, 0x33, 0x111);
                break;
            case 0x379:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 0x3C, 0x20, 0x35, 0x112);
                break;
            case 0x3AF:
                motB = EM_RES_REC((int)self->base.pack, 0x3C4);
                pl00_setSwing(self, 2, 0x20, 0x33, 0x11D);
                break;
            case 0x375:
            case 0x377:
            case 0x378:
                pl00_setSwing(self, 0x64, 0x20, 0x33, 0xF0);
                break;
            case 0x3AA:
            case 0x3AB:
                pl00_setSwing(self, 0x28, 0x22, 0x33, 0xF0);
                break;
            case 0x36D:
                pl00_setSwing(self, 0x64, 0x22, 0x33, 0xF0);
                break;
            }
            break;
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, 0, 0);
        self->unk15B0 = 1;
        self->base.step++;
        /* fall through */
    case 1:
        if (self->unk640 != 0) {
            self->unk648 = 0x14;
        }
        InvokeVirtualAtField214AndForward_124E68(self, 0.19634955f);
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        if (self->unk640 != 0) {
            cGameObj *target = self->unk640;
            cVec *pos = self->base.pos;

            if (capVu0MagnitudeSqXZ(pos, cGameObj_vt(target)->getPos((char *)target + cGameObj_vt(target)->getPosDelta)) < 1.21f) {
                ((cObjBase *)self)->nullSpeed.x = 0.0f;
                ((cObjBase *)self)->nullSpeed.z = 0.0f;
            }
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    func_0010A438(self);
    func_00123938(self, 1);
}
