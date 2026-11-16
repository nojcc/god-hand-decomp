#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00274FE8(void *a0);

/* sn-2.95.3-136 matched TU. */















/* Phase machine on the step byte, 61 case labels. Calls func_002740D8, irand,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, ReleaseField6ECByTag564_26B1E8, cSnd_SeCall_2CBA48,
 * GetSeqSEBase and 6 more. */
__attribute__((section(".text.func_0025A3E8"))) void func_0025A3E8(cEm00 *self)
{
    int s3;
    int s2;
    int s4;

    if (self->step == 0) {
        switch (self->emNo) {
            case 0x20F:
            case 0x210:
            case 0x211:
            case 0x226:
            case 0x270:
            case 0x271:
            case 0x272:
            case 0x273:
            case 0x274:
                self->step = 2;
                break;
        }
    }
    switch (self->step) {
        case 0:
            if (func_002740D8(self) != 0) {
                if (irand() & 1) {
                    self->unk17C3 = 1;
                } else {
                    self->unk17C3 = 0;
                }
            }
            s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            ReleaseField6ECByTag564_26B1E8(self);
            switch (self->emNo) {
                case 0x256:
                case 0x27E: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x2A28);
                    s2 = EM_RES_REC(b, 0x2A2C);
                } break;
                case 0x20A:
                case 0x20B:
                case 0x20C:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247:
                case 0x24F:
                case 0x278:
                case 0x279: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0xB5C);
                    s2 = EM_RES_REC(b, 0xB60);
                } break;
                case 0x250:
                case 0x251: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0xB5C);
                    s2 = EM_RES_REC(b, 0xB60);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                } break;
                case 0x260: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0xB5C);
                    s2 = EM_RES_REC(b, 0xB60);
                } break;
                case 0x264: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x326C);
                    s2 = EM_RES_REC(b, 0x3270);
                    self->stepArg = 1;
                } break;
                case 0x265: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x3818);
                    s2 = EM_RES_REC(b, 0x381C);
                    self->stepArg = 1;
                } break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                case 0x241: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x17D0);
                    s2 = EM_RES_REC(b, 0x17D4);
                } break;
                case 0x209:
                case 0x21F: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x17D0);
                    s2 = EM_RES_REC(b, 0x17D4);
                } break;
                case 0x215:
                case 0x21A:
                case 0x21B:
                case 0x21C:
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
                case 0x252:
                case 0x25A: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x13B0);
                    s2 = EM_RES_REC(b, 0x13B4);
                    self->stepArg = 1;
                } break;
                default: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x638);
                    s2 = EM_RES_REC(b, 0x63C);
                } break;
                case 0x223: {
                    int b = (int)self->pack;
                    s3 = EM_RES_REC(b, 0x2E34);
                    s2 = EM_RES_REC(b, 0x2E38);
                    self->stepArg = 1;
                } break;
            }
            func_002A8578(self, s3, s2, 3, 0.0f, s4, 0);
            if (self->stepArg == 0) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2D, self, 0, 0, 0, 0);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, self, 0, 0, 0, 0);
            }
            if (self->hp <= 0) {
                self->hp = 1;
            }
            self->unk16EC = 0;
            self->step += 1;
            /* fallthrough */
        case 1:
            if (self->stepArg == 0) {
                self->emFlags |= 0x40000;
            }
            if (moveMotion(self) != 0) {
                if (self->stepArg == 0) {
                    func_002705D8(self);
                } else {
                    self->mode = 0;
                    self->phase = 0x6B;
                    self->step = 0;
                    self->stepArg = 1;
                }
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2:
            if (func_002740D8(self) != 0) {
                if (irand() & 1) {
                    self->unk17C3 = 1;
                } else {
                    self->unk17C3 = 0;
                }
            }
            s4 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            ReleaseField6ECByTag564_26B1E8(self);
            {
                int b = (int)self->pack;
                func_002A8578(self, EM_RES_REC(b, 0xF84), EM_RES_REC(b, 0xF88), 0, 0.0f, s4, 0);
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x2D, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, self, 0, 0, 0, 0);
            if (self->hp <= 0) {
                self->hp = 1;
            }
            self->unk16EC = 0;
            self->step += 1;
            /* fallthrough */
        case 3:
            self->emFlags |= 0x40000;
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 4: {
            int nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            int b = (int)self->pack;
            func_002A8578(self, EM_RES_REC(b, 0xF8C), EM_RES_REC(b, 0xF90), 0, 0.0f, nb, 0);
            self->timer = 150.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            self->emFlags |= 0x40000;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            self->timer -= self->speedRate;
            if (self->timer <= 0.0f) {
                func_00274FE8(self);
            }
            break;
    }
}
