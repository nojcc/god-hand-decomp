#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */










/* Phase machine on the step byte, 74 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * ForwardAnimParamPairByIndex_27EA50, func_002A8578, Getplayer, cGameObj_SetTgtTurn, moveMotion and
 * 3 more. */
__attribute__((section(".text.func_0021A218"))) void func_0021A218(cEm00 *self)
{
    int s1v, s0v;
    int f = self->emFlags;

    self->emFlags = f | 0x400;
    switch (self->step) {
        case 0: {
            int gb;

            self->emFlags = (f | 0x402) & 0xFFFF7FFF;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->emNo) {
                default: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x98);
                    s0v = EM_RES_REC(b, 0x9C);
                    break;
                }

                case 0x202:
                case 0x203:
                case 0x213:
                case 0x216:
                case 0x217:
                case 0x229:
                case 0x22A:
                case 0x24B: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x648);
                    s0v = EM_RES_REC(b, 0x64C);
                    break;
                }

                case 0x242:
                case 0x243:
                case 0x244: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x35CC);
                    s0v = EM_RES_REC(b, 0x35D0);
                    break;
                }

                case 0x256:
                case 0x27E: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x25AC);
                    s0v = EM_RES_REC(b, 0x25B0);
                    break;
                }

                case 0x214:
                case 0x215:
                case 0x21A:
                case 0x21B:
                case 0x21C:
                case 0x21D:
                case 0x21E:
                case 0x22C:
                case 0x22D:
                case 0x22E:
                case 0x22F:
                case 0x248:
                case 0x249:
                case 0x24C:
                case 0x24E:
                case 0x25A: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x10A8);
                    s0v = EM_RES_REC(b, 0x10AC);
                    break;
                }

                case 0x225:
                case 0x24D: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x3C88);
                    s0v = EM_RES_REC(b, 0x3C8C);
                    break;
                }

                case 0x252: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x24EC);
                    s0v = EM_RES_REC(b, 0x24F0);
                    break;
                }

                case 0x20A:
                case 0x20B:
                case 0x20D:
                case 0x20E:
                case 0x218:
                case 0x245:
                case 0x246:
                case 0x247: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x828);
                    s0v = EM_RES_REC(b, 0x82C);
                    break;
                }

                case 0x278:
                case 0x279: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x1FB0);
                    s0v = EM_RES_REC(b, 0x1FB4);
                    break;
                }

                case 0x20C:
                case 0x24F: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x1EAC);
                    s0v = EM_RES_REC(b, 0x1EB0);
                    break;
                }

                case 0x205:
                case 0x206:
                case 0x207:
                case 0x208:
                case 0x224: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x1560);
                    s0v = EM_RES_REC(b, 0x1564);
                    break;
                }

                case 0x241: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x3A00);
                    s0v = EM_RES_REC(b, 0x3A04);
                    break;
                }

                case 0x209:
                case 0x21F: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x3418);
                    s0v = EM_RES_REC(b, 0x341C);
                    break;
                }

                case 0x250:
                case 0x251: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x18F0);
                    s0v = EM_RES_REC(b, 0x18F4);
                    break;
                }

                case 0x260: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x3038);
                    s0v = EM_RES_REC(b, 0x303C);
                    break;
                }

                case 0x264: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x326C);
                    s0v = EM_RES_REC(b, 0x3270);
                    break;
                }

                case 0x265: {
                    int b = EM_RES(self);
                    cEm00 *m = self->unk744;

                    s1v = EM_RES_REC(b, 0x3724);
                    s0v = EM_RES_REC(b, 0x3728);
                    if (m != 0) {
                        ForwardAnimParamPairByIndex_27EA50(m, 0);
                    }
                    break;
                }

                case 0x20F:
                case 0x210:
                case 0x226:
                case 0x270:
                case 0x271:
                case 0x272:
                case 0x273:
                case 0x274: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0xCF8);
                    s0v = EM_RES_REC(b, 0xCFC);
                    break;
                }

                case 0x211: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x244C);
                    s0v = EM_RES_REC(b, 0x2450);
                    break;
                }

                case 0x220:
                case 0x221:
                case 0x222: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x1BC0);
                    s0v = EM_RES_REC(b, 0x1BC4);
                    break;
                }

                case 0x223: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x2D38);
                    s0v = EM_RES_REC(b, 0x2D3C);
                    break;
                }

                case 0x275:
                case 0x276: {
                    int b = EM_RES(self);
                    s1v = EM_RES_REC(b, 0x2274);
                    s0v = EM_RES_REC(b, 0x2278);
                    break;
                }
            }
            if (*(int *)((char *)self + 0x6EC) != 0) {
                int b = EM_RES(self);
                s1v = EM_RES_REC(b, 0x44C);
                s0v = EM_RES_REC(b, 0x450);
            }
            func_002A8578(self, s1v, s0v, 0xA, 0.0f, gb, 0);
            self->step = self->step + 1;
        }
        case 1: {
            cGameObj *o = Getplayer();

            cGameObj_SetTgtTurn(self, o->pos,
                                self->speedRate * 0.09817477315664291f);
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
    }
    if (0.0f < self->slideTime) {
        self->mode = 0;
        self->phase = 0x13;
        self->step = 0;
        self->stepArg = 0;
    } else if ((self->emFlags & 0x20000000) != 0) {
        func_002705D8(self);
    }
}
