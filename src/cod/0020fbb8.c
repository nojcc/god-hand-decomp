#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/motion.h"
#include "godhand/cEmManage.h"
#include "godhand/player.h"
#include "godhand/gameWork.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int irand(void);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_002A74E0(void *a0, void *a1, int a2);
extern void cEm00_clearSetFlags(int a0);

/* sn-2.95.3-136 matched TU. */























/* Phase machine on the step byte, 657 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * ForwardAnimParamPairByIndex_27EA50, irand, func_002A8578, InitRenderStruct_2A8608, moveMotion and
 * 11 more. */
__attribute__((section(".text.func_0020FBB8"))) void func_0020FBB8(cEm00 *self)
{
    int s2v, s0v;
    int gb;
    float fv;
    int p2, p1;
    int flag6;
    int old, nw;

    fv = 0.0f;
    p2 = 1;
    p1 = 0x4E2;
    flag6 = 0;
    old = self->emFlags;
    nw = old | 0x400;
    self->emFlags = nw;
    switch (self->step) {
        case 0:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            self->emFlags = self->emFlags | 0x8000;
            switch (self->unk1650) {
                default:
                case 0x0:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x98);
                            s0v = EM_RES_REC(b, 0x9C);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x24B: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x648);
                            s0v = EM_RES_REC(b, 0x9C);
                        } break;
                        case 0x242:
                        case 0x243:
                        case 0x244: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x35CC);
                            s0v = EM_RES_REC(b, 0x35D0);
                        } break;
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x25AC);
                            s0v = EM_RES_REC(b, 0x25B0);
                        } break;
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
                            s2v = EM_RES_REC(b, 0x10A8);
                            s0v = EM_RES_REC(b, 0x10AC);
                        } break;
                        case 0x225:
                        case 0x24D: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3C88);
                            s0v = EM_RES_REC(b, 0x3C8C);
                        } break;
                        case 0x252: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x24EC);
                            s0v = EM_RES_REC(b, 0x24F0);
                        } break;
                        case 0x20A:
                        case 0x20B:
                        case 0x20D:
                        case 0x20E:
                        case 0x245:
                        case 0x246:
                        case 0x247: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x828);
                            s0v = EM_RES_REC(b, 0x82C);
                        } break;
                        case 0x278:
                        case 0x279: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1FB0);
                            s0v = EM_RES_REC(b, 0x1FB4);
                        } break;
                        case 0x218: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3BB4);
                            s0v = EM_RES_REC(b, 0x3BB8);
                        } break;
                        case 0x250:
                        case 0x251: {
                            if (D_007474A0.room == 0x504) {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x1A48);
                                s0v = EM_RES_REC(b, 0x1A4C);
                            } else {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x18F0);
                                s0v = EM_RES_REC(b, 0x18F4);
                            }
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x20C:
                        case 0x24F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1EAC);
                            s0v = EM_RES_REC(b, 0x1EB0);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1560);
                            s0v = EM_RES_REC(b, 0x1564);
                        } break;
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3A00);
                            s0v = EM_RES_REC(b, 0x3A04);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3418);
                            s0v = EM_RES_REC(b, 0x341C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            if (self->flags1644 & 0x200000) {
                                int b = EM_RES(self);
                                s0v = EM_RES_REC(b, 0xFBC);
                                s2v = s0v;
                            } else {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0xCF8);
                                s0v = EM_RES_REC(b, 0xCFC);
                            }
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x275:
                        case 0x276: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2274);
                            s0v = EM_RES_REC(b, 0x2278);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x18:
                    switch (self->entryNo & 7) {
                        default:
                        case 0:
                            fv = 7.0f;
                            break;
                        case 1:
                            fv = 6.0f;
                            break;
                        case 2:
                            fv = 5.0f;
                            break;
                        case 3:
                            fv = 4.0f;
                            break;
                        case 4:
                            fv = 3.0f;
                            break;
                        case 5:
                            fv = 2.0f;
                            break;
                        case 6:
                            fv = 1.0f;
                            break;
                        case 7:
                            fv = 0.0f;
                            break;
                    }
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3F4);
                            s0v = EM_RES_REC(b, 0x3F8);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x214:
                        case 0x215:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x244:
                        case 0x24B: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3F4);
                            s0v = EM_RES_REC(b, 0x3F8);
                        } break;
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3F4);
                            s0v = EM_RES_REC(b, 0x3F8);
                        } break;
                        case 0x21A:
                        case 0x21C:
                        case 0x21D:
                        case 0x21E:
                        case 0x22C:
                        case 0x22E:
                        case 0x22F:
                        case 0x248:
                        case 0x249:
                        case 0x24C:
                        case 0x24E:
                        case 0x252:
                        case 0x25A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x13F8);
                            s0v = EM_RES_REC(b, 0x13FC);
                        } break;
                        case 0x21B:
                        case 0x22D: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1448);
                            s0v = EM_RES_REC(b, 0x144C);
                        } break;
                        case 0x225:
                        case 0x24D: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1450);
                            s0v = EM_RES_REC(b, 0x1454);
                        } break;
                        case 0x20A:
                        case 0x20B:
                        case 0x20D:
                        case 0x20E:
                        case 0x218:
                        case 0x245:
                        case 0x246:
                        case 0x247: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBCC);
                            s0v = EM_RES_REC(b, 0xBD0);
                        } break;
                        case 0x278:
                        case 0x279: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBCC);
                            s0v = EM_RES_REC(b, 0xBD4);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBCC);
                            s0v = EM_RES_REC(b, 0xBD0);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x20C:
                        case 0x24F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBCC);
                            s0v = EM_RES_REC(b, 0xBD0);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1560);
                            s0v = EM_RES_REC(b, 0x1564);
                        } break;
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3A00);
                            s0v = EM_RES_REC(b, 0x3A04);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3418);
                            s0v = EM_RES_REC(b, 0x341C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            if (self->flags1644 & 0x200000) {
                                int b = EM_RES(self);
                                s0v = EM_RES_REC(b, 0xFBC);
                                s2v = s0v;
                            } else {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0xCF8);
                                s0v = EM_RES_REC(b, 0xCFC);
                            }
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x275:
                        case 0x276: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3F4);
                            s0v = EM_RES_REC(b, 0x3F8);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x19:
                    switch (self->entryNo & 7) {
                        default:
                        case 0:
                            fv = 0.0f;
                            break;
                        case 1:
                            fv = 30.0f;
                            break;
                        case 2:
                            fv = 15.0f;
                            break;
                        case 3:
                            fv = 45.0f;
                            break;
                        case 4:
                            fv = 10.0f;
                            break;
                        case 5:
                            fv = 40.0f;
                            break;
                        case 6:
                            fv = 5.0f;
                            break;
                        case 7:
                            fv = 25.0f;
                            break;
                    }
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x43C);
                            s0v = EM_RES_REC(b, 0x440);
                        } break;
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1458);
                            s0v = EM_RES_REC(b, 0x145C);
                        } break;
                        case 0x20A:
                        case 0x20B:
                        case 0x20D:
                        case 0x20E:
                        case 0x218:
                        case 0x245:
                        case 0x246:
                        case 0x247:
                        case 0x278:
                        case 0x279: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBF8);
                            s0v = EM_RES_REC(b, 0xBFC);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xB84);
                            s0v = EM_RES_REC(b, 0xB88);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x20C:
                        case 0x24F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xB84);
                            s0v = EM_RES_REC(b, 0xB88);
                        } break;
                        case 0x205:
                        case 0x207: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x17F8);
                            s0v = EM_RES_REC(b, 0x17FC);
                        } break;
                        case 0x224: {
                            int t = irand();
                            if (t & 1) {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x18DC);
                                s0v = EM_RES_REC(b, 0x18E0);
                            } else {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x18E4);
                                s0v = EM_RES_REC(b, 0x18E8);
                            }
                        } break;
                        case 0x241: {
                            int t = irand();
                            if (t & 1) {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x3B1C);
                                s0v = EM_RES_REC(b, 0x3B20);
                            } else {
                                int b = EM_RES(self);
                                s2v = EM_RES_REC(b, 0x3B24);
                                s0v = EM_RES_REC(b, 0x3B28);
                            }
                        } break;
                        case 0x206: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1890);
                            s0v = EM_RES_REC(b, 0x1894);
                        } break;
                        case 0x208: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1EA0);
                            s0v = EM_RES_REC(b, 0x1EA4);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3418);
                            s0v = EM_RES_REC(b, 0x341C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xF94);
                            s0v = EM_RES_REC(b, 0xF98);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x275:
                        case 0x276: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3F4);
                            s0v = EM_RES_REC(b, 0x3F8);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x4:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x40C);
                            s0v = EM_RES_REC(b, 0x410);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x244:
                        case 0x24B:
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x40C);
                            s0v = EM_RES_REC(b, 0x410);
                        } break;
                        case 0x214:
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1418);
                            s0v = EM_RES_REC(b, 0x141C);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x40C);
                            s0v = EM_RES_REC(b, 0x410);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1800);
                            s0v = EM_RES_REC(b, 0x1804);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3418);
                            s0v = EM_RES_REC(b, 0x341C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            p1 = 0x58;
                            p2 = 0x47;
                            s2v = EM_RES_REC(b, 0xFC4);
                            s0v = EM_RES_REC(b, 0xFC8);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x1:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3FC);
                            s0v = EM_RES_REC(b, 0x400);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x24B:
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3FC);
                            s0v = EM_RES_REC(b, 0x400);
                        } break;
                        case 0x244: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x36F8);
                            s0v = EM_RES_REC(b, 0x36FC);
                        } break;
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1438);
                            s0v = EM_RES_REC(b, 0x143C);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBD8);
                            s0v = EM_RES_REC(b, 0xBDC);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1810);
                            s0v = EM_RES_REC(b, 0x1814);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1810);
                            s0v = EM_RES_REC(b, 0x1814);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xFAC);
                            s0v = EM_RES_REC(b, 0xFB0);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x5:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x424);
                            s0v = EM_RES_REC(b, 0x428);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x24B:
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x424);
                            s0v = EM_RES_REC(b, 0x428);
                        } break;
                        case 0x244: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x36F8);
                            s0v = EM_RES_REC(b, 0x36FC);
                        } break;
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1438);
                            s0v = EM_RES_REC(b, 0x143C);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBD8);
                            s0v = EM_RES_REC(b, 0xBDC);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1810);
                            s0v = EM_RES_REC(b, 0x1814);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1810);
                            s0v = EM_RES_REC(b, 0x1814);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xFD4);
                            s0v = EM_RES_REC(b, 0xFD8);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
            }
            if (*(int *)((char *)self + 0x6EC) != 0) {
                if (self->unk1650 == 9) {
                    int b = EM_RES(self);
                    self->stepArg = 0;
                    s2v = EM_RES_REC(b, 0x490);
                    s0v = EM_RES_REC(b, 0x494);
                } else {
                    int b = EM_RES(self);
                    self->stepArg = 0;
                    s2v = EM_RES_REC(b, 0x44C);
                    s0v = EM_RES_REC(b, 0x450);
                }
            }
            func_002A8578(self, s2v, s0v, 0, fv, gb, 0);
            if ((p1 ^ 0x4E2) != 0) {
                InitRenderStruct_2A8608((cGameObj *)self, p1, p2, 0, 2, 0);
            }
            {
                cVec *dst = &self->home;
                cVec *src = self->pos;
                if (dst != src) {
                    self->home.x = src->x;
                    dst->y = src->y;
                    dst->z = src->z;
                }
            }
            self->timerA = 0x1E;
            self->step = self->step + 1;
        case 1:
            if (self->unk1650 == 5) {
                self->emFlags = self->emFlags | 0x20000;
            }
            if (self->flags1644 & 0x100000) {
                self->emFlags = self->emFlags | 0x10000;
            }
            if (0.0f < self->tint.w) {
                cVec *fp1;
                cVec *fp2;
                fv = 1.0f;
                moveMotion(self);
                cObjBase_addNullSpeed_Rotation(self, fv);
                cObjBase_addNullSpeed(self, fv);
                fp1 = self->pos;
                fp1->x = fp1->x * 0.99500002f + self->home.x * 0.0049999999f;
                fp2 = self->pos;
                fp2->z = fp2->z * 0.99500002f + self->home.z * 0.0049999999f;
            }
            {
                GameWork *g = &D_007474A0;
                if ((g->frame & 7) == (self->unk17D0 & 7)) {
                    if (self->playerDist < 64.0f) {
                        func_0026F328(self);
                    }
                }
            }
            if (self->flags1644 & 0x10008000) {
                if (self->flags1644 & 0x10000000) {
                    cCollisionSolidManage_SetActive(&D_00462FC0, (struct cGameObj *)self, 0);
                    self->emFlags = self->emFlags | 0x1000;
                }
                if (self->unk16EC != 0) {
                    if (self->unk1650 == 9) {
                        self->step = 2;
                    }
                    if (self->flags1644 & 0x8000) {
                        self->step = 2;
                    }
                }
            } else {
                if (self->timerA != 0) {
                    self->timerA = self->timerA - 1;
                } else if (self->emFlags & 0x200000) {
                    if (self->playerDist < 64.0f) {
                        GameWork *g = &D_007474A0;
                        if ((g->frame & 7) == (self->unk17D0 & 7)) {
                            void *h;
                            self->emFlags2 = self->emFlags2 & 0xF7FFFFFF;
                            h = Getplayer();
                            func_002A74E0(self, *(void **)((char *)h + 0xF0), 1);
                            if (func_002A7CA0((cGameObj *)self, (cVec *)&self->unk16A0) != 0) {
                                self->emFlags2 = self->emFlags2 | 0x8000000;
                            }
                            if (self->unk510 < 8.0f) {
                                self->step = 2;
                            }
                        }
                    }
                    if (self->playerDist < 9.0f) {
                        self->step = 2;
                    }
                }
                if (self->emFlags & 0x200000) {
                    GameWork *g = &D_007474A0;
                    if ((g->frame & 7) == (self->unk17D0 & 7)) {
                        if (cEmManage_ckEnemyActiveNear(&D_005864F0, self->pos, 4.0f) != 0) {
                            self->step = 2;
                        }
                        if (cEmManage_ckEmNear(&D_005864F0, self->pos, (cEmActor *)self, 3.0f) != 0) {
                            self->step = 2;
                        }
                    }
                }
                if (self->unk16EC != 0) {
                    self->step = 2;
                }
            }
            if (self->emFlags & 0x20000000) {
                flag6 = 1;
                self->step = 2;
            }
            if (0.0f < self->slideTime) {
                self->step = 2;
            }
            if (self->step != 2) {
                break;
            }
            cEm00_clearSetFlags((int)self);
            switch (self->unk1650) {
                default:
                case 0x0:
                case 0x19:
                    if ((irand() & 1) != 0 && self->slideTime <= 0.0f &&
                        self->unk16EC <= 0) {
                        self->mode = 0;
                        self->phase = 0x6B;
                        self->step = 0;
                        self->stepArg = 0;
                        break;
                    }
                    func_002705D8(self);
                    break;
                case 0x9:
                    if (flag6 != 0) {
                        if (*(int *)((char *)self + 0x6EC) != 0) {
                            int t = 0x47;
                            self->stepArg = 1;
                            self->phase = t;
                        } else {
                            self->stepArg = 0;
                            self->phase = 0x15;
                        }
                        self->step = 0;
                        self->mode = 0;
                        break;
                    }
                    func_002705D8(self);
                    break;
                case 0x1:
                case 0x4:
                case 0x5:
                    break;
            }
            break;
        case 2:
            if (!(nw & 0x20000000) && !(fv < self->slideTime)) {
                self->emFlags = old | 0x402;
            }
            self->emFlags = self->emFlags & 0xFFFF7FFF;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (self->unk1650) {
                default:
                case 0x4:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x414);
                            s0v = EM_RES_REC(b, 0x418);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x244:
                        case 0x24B:
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x7B4);
                            s0v = EM_RES_REC(b, 0x7B8);
                        } break;
                        case 0x214:
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1420);
                            s0v = EM_RES_REC(b, 0x1424);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x414);
                            s0v = EM_RES_REC(b, 0x418);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1808);
                            s0v = EM_RES_REC(b, 0x180C);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3418);
                            s0v = EM_RES_REC(b, 0x341C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xFCC);
                            s0v = EM_RES_REC(b, 0xFD0);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x1:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x404);
                            s0v = EM_RES_REC(b, 0x408);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x21A:
                        case 0x21B:
                        case 0x21C:
                        case 0x21D:
                        case 0x21E:
                        case 0x225:
                        case 0x229:
                        case 0x22A:
                        case 0x22C:
                        case 0x22D:
                        case 0x22E:
                        case 0x22F:
                        case 0x242:
                        case 0x243:
                        case 0x248:
                        case 0x249:
                        case 0x24B:
                        case 0x24C:
                        case 0x24D:
                        case 0x24E:
                        case 0x252:
                        case 0x256:
                        case 0x25A:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x404);
                            s0v = EM_RES_REC(b, 0x408);
                        } break;
                        case 0x244: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3700);
                            s0v = EM_RES_REC(b, 0x3704);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBE0);
                            s0v = EM_RES_REC(b, 0xBE4);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1818);
                            s0v = EM_RES_REC(b, 0x181C);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1818);
                            s0v = EM_RES_REC(b, 0x181C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xFB4);
                            s0v = EM_RES_REC(b, 0xFB8);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
                case 0x5:
                    switch (self->emNo) {
                        default: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x42C);
                            s0v = EM_RES_REC(b, 0x430);
                        } break;
                        case 0x202:
                        case 0x203:
                        case 0x213:
                        case 0x216:
                        case 0x217:
                        case 0x229:
                        case 0x22A:
                        case 0x242:
                        case 0x243:
                        case 0x24B:
                        case 0x256:
                        case 0x27E: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x7BC);
                            s0v = EM_RES_REC(b, 0x7C0);
                        } break;
                        case 0x244: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3700);
                            s0v = EM_RES_REC(b, 0x3704);
                        } break;
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1440);
                            s0v = EM_RES_REC(b, 0x1444);
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
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xBE0);
                            s0v = EM_RES_REC(b, 0xBE4);
                        } break;
                        case 0x250:
                        case 0x251: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x18F0);
                            s0v = EM_RES_REC(b, 0x18F4);
                        } break;
                        case 0x260: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3038);
                            s0v = EM_RES_REC(b, 0x303C);
                        } break;
                        case 0x264: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x326C);
                            s0v = EM_RES_REC(b, 0x3270);
                        } break;
                        case 0x265: {
                            int b = EM_RES(self);
                            cEm00 *h = self->unk744;
                            s2v = EM_RES_REC(b, 0x3724);
                            s0v = EM_RES_REC(b, 0x3728);
                            if (h != 0) {
                                ForwardAnimParamPairByIndex_27EA50(h, 0);
                            }
                        } break;
                        case 0x26A: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x3D34);
                            s0v = EM_RES_REC(b, 0x3D38);
                        } break;
                        case 0x205:
                        case 0x206:
                        case 0x207:
                        case 0x208:
                        case 0x224:
                        case 0x241: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1818);
                            s0v = EM_RES_REC(b, 0x181C);
                        } break;
                        case 0x209:
                        case 0x21F: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1818);
                            s0v = EM_RES_REC(b, 0x181C);
                        } break;
                        case 0x20F:
                        case 0x210:
                        case 0x211:
                        case 0x226:
                        case 0x270:
                        case 0x271:
                        case 0x272:
                        case 0x273:
                        case 0x274: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0xFDC);
                            s0v = EM_RES_REC(b, 0xFE0);
                        } break;
                        case 0x220:
                        case 0x221:
                        case 0x222: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x1BC0);
                            s0v = EM_RES_REC(b, 0x1BC4);
                        } break;
                        case 0x223: {
                            int b = EM_RES(self);
                            s2v = EM_RES_REC(b, 0x2D38);
                            s0v = EM_RES_REC(b, 0x2D3C);
                        } break;
                    }
                    break;
            }
            func_002A8578(self, s2v, s0v, 10, 0.0f, gb, 0);
            self->step = self->step + 1;
        case 3:
            if (self->unk1650 == 5) {
                self->emFlags = self->emFlags | 0x20000;
            }
            if (moveMotion(self) != 0) {
                if ((irand() & 1) != 0 && self->slideTime <= 0.0f &&
                    self->unk16EC <= 0) {
                    self->mode = 0;
                    self->phase = 0x6B;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_002705D8(self);
                }
            }
            fv = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, fv);
            cObjBase_addNullSpeed(self, fv);
            break;
    }
}
