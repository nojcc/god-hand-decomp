#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */












#include "godhand/vu0.h"


/* Phase machine on the step byte, 58 case labels. Calls VU0_SQC2_VF0,
 * Obj0000_Get_Byte_17C3_NZ_2_276468, irand, cSnd_SeCall_2CBA48, GetSeqSEBase, func_002A8578 and 4
 * more. */
__attribute__((section(".text.func_0025ED00"))) void func_0025ED00(cEm00 *self)
{
    cEffectParam s;
    int s2;
    int s1;
    int nb;

    s.color.x = 1.0f;
    s.color.y = 1.0f;
    s.color.z = 1.0f;
    s.color.w = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.scale.x;
        s.scale.x = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.size = 1.0f;
    s.unk4C = -1;
    s.unk4F = 0xFF;
    s.unk44 = 0;
    s.flags = 0;
    s.unk4D = 0;
    s.unk4E = 0;
    s.unk50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    s.unk70 = 0;
    s.size = self->scale.y;
    s.unk72 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    switch (self->step) {
        case 0:
            nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default:
                    if ((self->seqFlags & 0x200) != 0) {
                        if ((irand() & 1) != 0) {
                            int b = EM_RES(self);
                            s2 = EM_RES_REC(b, 0x380);
                            s1 = EM_RES_REC(b, 0x384);
                        } else {
                            int b = EM_RES(self);
                            s2 = EM_RES_REC(b, 0x388);
                            s1 = EM_RES_REC(b, 0x38C);
                        }
                    } else {
                        if ((irand() & 1) != 0) {
                            int b = EM_RES(self);
                            s2 = EM_RES_REC(b, 0x370);
                            s1 = EM_RES_REC(b, 0x374);
                        } else {
                            int b = EM_RES(self);
                            s2 = EM_RES_REC(b, 0x378);
                            s1 = EM_RES_REC(b, 0x37C);
                        }
                    }
                    break;
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
                case 0x279:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB44);
                        s1 = EM_RES_REC(b, 0xB48);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB3C);
                        s1 = EM_RES_REC(b, 0xB40);
                    }
                    break;
                case 0x250:
                case 0x251:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB44);
                        s1 = EM_RES_REC(b, 0xB48);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB3C);
                        s1 = EM_RES_REC(b, 0xB40);
                    }
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x23), self, 0, 0,
                                       0, 0);
                    break;
                case 0x260:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB44);
                        s1 = EM_RES_REC(b, 0xB48);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xB3C);
                        s1 = EM_RES_REC(b, 0xB40);
                    }
                    break;
                case 0x264:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x326C);
                        s1 = EM_RES_REC(b, 0x3270);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x326C);
                        s1 = EM_RES_REC(b, 0x3270);
                    }
                    break;
                case 0x265:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3818);
                        s1 = EM_RES_REC(b, 0x381C);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x3818);
                        s1 = EM_RES_REC(b, 0x381C);
                    }
                    break;
                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224:
                case 0x241:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x17B8);
                        s1 = EM_RES_REC(b, 0x17BC);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x17B0);
                        s1 = EM_RES_REC(b, 0x17B4);
                    }
                    break;
                case 0x209:
                case 0x21F:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x17B8);
                        s1 = EM_RES_REC(b, 0x17BC);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x17B0);
                        s1 = EM_RES_REC(b, 0x17B4);
                    }
                    break;
                case 0x20F:
                case 0x210:
                case 0x211:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xF6C);
                        s1 = EM_RES_REC(b, 0xF70);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0xF64);
                        s1 = EM_RES_REC(b, 0xF68);
                    }
                    break;
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
                case 0x25A:
                    if ((self->seqFlags & 0x200) != 0) {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1398);
                        s1 = EM_RES_REC(b, 0x139C);
                    } else {
                        int b = EM_RES(self);
                        s2 = EM_RES_REC(b, 0x1390);
                        s1 = EM_RES_REC(b, 0x1394);
                    }
                    break;
            }
            func_002A8578(self, s2, s1, 5, 0.0f, nb, 0);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 8), self, 0, 0, 0, 0);
            switch (self->emNo) {
                case 0x207:
                case 0x240:
                case 0x249:
                case 0x24A:
                case 0x24E:
                    SetEffect(0x58, 0x9F, self, &s, -1, 0xFFFFFFFF);
                    cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase(self) + 0x22), self, 0, 0,
                                       0, 0);
                    break;
            }
            self->step += 1;
            /* fallthrough */
        case 1:
            if (moveMotion(self) != 0) {
                if ((self->flags1644 & 0x800000) != 0) {
                    self->mode = 2;
                    self->phase = 3;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    self->mode = 2;
                    self->phase = 2;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                cObjBase_addNullSpeed_Rotation(self, 1.0f);
                cObjBase_addNullSpeed(self, 1.0f);
            }
            break;
    }
}
