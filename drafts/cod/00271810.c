/* sn-2.95.3-136 */
/* NON_MATCHING func_00271810 (extern_jtbl D_00446360 D_00446380): retail
 * schedules cEffectParam_init's -1 and 0xFF byte stores after the 0x44/0x48
 * word stores, with -1 in a0 and 0xFF in a1; this C emits them first with the
 * registers swapped. The heat-mode byte in the slot-wait branch loads through
 * v1 in retail and v0 here. Needs the cSnd.h overlay (cSnd_SeCall_2CBA48). */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cEmManage.h"
#include "godhand/cSnd.h"
#include "godhand/cCoreSave.h"
#include "godhand/cHeatSys.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"
#include "godhand/rand.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

extern void func_00271518(cEm00 *self, cVec *pos);

/* An enemy's hit sparks: the guard or block spark for the enemies and attack
 * kinds that have one, then the hit effect at the hit point (a spark on a
 * random body part for a kind-0x23 hit, a gold spark in front of the player
 * for some enemies), with the hit and heat sounds. */
__attribute__((section(".text.func_00271810")))
void func_00271810(cEm00 *self)
{
    cVec pos;
    cEffectParam param;
    int frame[3];
    cGameObj *pl;
    cOmBase *part;

    pl = Getplayer();
    VU0_SQC2_VF0_MEM(&pos, 0);
    cEffectParam_init(&param);
    param.size = self->unk114;
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;
    if (self->unk698 != 0 && ((cDamageTake *)self->unk698)->kind == 0x55)
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
    switch (self->emNo) {
    default:
        if (self->unk698 != 0) {
            switch (((cDamageTake *)self->unk698)->kind) {
            case 0x34:
            case 0x35:
                SetEffect(0x58, 0x9E, self, &param, -1, 0xFFFFFFFF);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
                break;
            }
        }
        break;
    case 0x207:
    case 0x240:
    case 0x249:
    case 0x24A:
    case 0x24E:
        SetEffect(0x58, 0x9E, self, &param, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
        break;
    case 0x275:
    case 0x276:
        SetEffect(0xCD, 0x16, self, &param, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x12B, self, 0, 0, 0, 0);
        break;
    }
    if (((cDamageTake *)self->unk698)->kind == 0x23) {
        switch (self->emNo) {
        default:
            switch (irand() & 7) {
            case 0:
            default:
                part = cOmBase_childAt((cOmBase *)self, frame, 1);
                break;
            case 1:
                part = cOmBase_childAt((cOmBase *)self, frame, 2);
                break;
            case 2:
                part = cOmBase_childAt((cOmBase *)self, frame, 3);
                break;
            case 3:
                part = cOmBase_childAt((cOmBase *)self, frame, 4);
                break;
            case 4:
                part = cOmBase_childAt((cOmBase *)self, frame, 9);
                break;
            case 5:
                part = cOmBase_childAt((cOmBase *)self, frame, 15);
                break;
            case 6:
                part = cOmBase_childAt((cOmBase *)self, frame, 18);
                break;
            case 7:
                part = cOmBase_childAt((cOmBase *)self, frame, 22);
                break;
            }
            if (part == 0)
                return;
            cVec_copy3(&pos, part->pos);
            pos.x += fRand1_1() * 0.1f;
            pos.y += fRand1_1() * 0.1f;
            pos.z += fRand1_1() * 0.1f;
            SetEffectPos(0, 0xC, 0, &pos, -1, 1.0f);
            break;
        case 0x260:
        case 0x264:
        case 0x265:
        case 0x26A:
            pos.x = fRand1_1() * 0.3f;
            pos.y = fRand1_1() * 0.2f + 1.5f;
            pos.z = fRand1_1() * 0.3f + 0.5f;
            sceVu0ApplyMatrix(&pos, pl->mtx, &pos);
            SetEffectPos(0, 0xC, 0, &pos, -1, 1.0f);
            break;
        }
        return;
    }
    func_00271518(self, &pos);
    if (D_005864F0.slotWait > 0) {
        SetEffectPos(0, 0xC, 0, &pos, -1, 1.0f);
        if (D_005CB010 != 0 || Obj0000_Get_Field_5FC_NE_Zero_12C748((char *)pl))
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x121, self, 0, 0, 0, 0);
        return;
    }
    if (self->moveFlags & 0x100) {
        if ((D_007474A0.unk590 & 0x800) == 0 && (self->emFlags2 & 0x8000) == 0) {
            if (cEmManage_CkBigHitEffWait(&D_005864F0) == 0)
                SetEffectPos(0x58, 0x12, 0, &pos, -1, 1.0f);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 1, self, 0, 0, 0, 0);
        }
        SetEffectPos(0, 0x40, 0, &pos, -1, 1.0f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x121, self, 0, 0, 0, 0);
        return;
    }
    if (D_005CB010 != 0 || Obj0000_Get_Field_5FC_NE_Zero_12C748((char *)pl)) {
        SetEffectPos(0, 0x40, 0, &pos, -1, 1.0f);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x121, self, 0, 0, 0, 0);
        return;
    }
    switch (cCoreSave_getCostumeNo(&D_00569B70)) {
    case 1:
    case 3:
    case 5:
    case 7:
        SetEffectPos(0, 0x40, 0, &pos, -1, 1.0f);
        break;
    case 0:
    case 2:
    case 4:
    case 6:
    default:
        SetEffectPos(0x58, 0x10, 0, &pos, -1, 1.0f);
        break;
    }
}
