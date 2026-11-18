#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"

/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002A74E0(void *a0, void *a1, int a2);

extern int irand(void);
extern unsigned int D_007476B0;
/* Phase machine on the step byte, 223 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * ForwardAnimParamPairByIndex_27EA50, func_002A8578, moveMotion, cObjBase_addNullSpeed_Rotation,
 * cObjBase_addNullSpeed and 7 more. */
__attribute__((section(".text.func_002112F0"))) void func_002112F0(cEm00 *self)
{
    int s1v;
    int s0v;
    int gb;
    float d;
    float new_var;
    float ad;
    float f0z;
    float k3;
    char *sp0;
    *((int *)&self->emFlags) = (*((int *)&self->emFlags)) | 0x400;
    switch (*((unsigned char *)&self->step)) {
        case 0:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            switch (*((int *)&self->emNo)) {
                default: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x98))) + b;
                    s0v = (*((int *)(b + 0x9C))) + b;
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
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x648))) + b;
                    s0v = (*((int *)(b + 0x64C))) + b;
                    break;
                }

                case 0x242:

                case 0x243:

                case 0x244: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x35CC))) + b;
                    s0v = (*((int *)(b + 0x35D0))) + b;
                    break;
                }

                case 0x256:

                case 0x27E: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x25AC))) + b;
                    s0v = (*((int *)(b + 0x25B0))) + b;
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
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x10A8))) + b;
                    s0v = (*((int *)(b + 0x10AC))) + b;
                    break;
                }

                case 0x225:

                case 0x24D: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x3C88))) + b;
                    s0v = (*((int *)(b + 0x3C8C))) + b;
                    break;
                }

                case 0x252: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x24EC))) + b;
                    s0v = (*((int *)(b + 0x24F0))) + b;
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
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x828))) + b;
                    s0v = (*((int *)(b + 0x82C))) + b;
                    break;
                }

                case 0x278:

                case 0x279: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x1FB0))) + b;
                    s0v = (*((int *)(b + 0x1FB4))) + b;
                    break;
                }

                case 0x250:

                case 0x251: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x18F0))) + b;
                    s0v = (*((int *)(b + 0x18F4))) + b;
                    break;
                }

                case 0x260: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x3038))) + b;
                    s0v = (*((int *)(b + 0x303C))) + b;
                    break;
                }

                case 0x264: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x326C))) + b;
                    s0v = (*((int *)(b + 0x3270))) + b;
                    break;
                }

                case 0x265: {
                    int b = *((int *)&self->pack);
                    cEm00 *m = self->unk744;
                    s1v = (*((int *)(b + 0x3724))) + b;
                    s0v = (*((int *)(b + 0x3728))) + b;
                    if (m != 0) {
                        ForwardAnimParamPairByIndex_27EA50(m, 0x0);
                    }
                    break;
                }

                case 0x26A: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x3D34))) + b;
                    s0v = (*((int *)(b + 0x3D38))) + b;
                    break;
                }

                case 0x20C:

                case 0x24F: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x1EAC))) + b;
                    s0v = (*((int *)(b + 0x1EB0))) + b;
                    break;
                }

                case 0x205:

                case 0x206:

                case 0x207:

                case 0x208:

                case 0x224: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x1560))) + b;
                    s0v = (*((int *)(b + 0x1564))) + b;
                    break;
                }

                case 0x241: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x3A00))) + b;
                    s0v = (*((int *)(b + 0x3A04))) + b;
                    break;
                }

                case 0x209:

                case 0x21F: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x3418))) + b;
                    s0v = (*((int *)(b + 0x341C))) + b;
                    break;
                }

                case 0x20F:

                case 0x210:

                case 0x211:

                case 0x226:

                case 0x270:

                case 0x271:

                case 0x272:

                case 0x273:

                case 0x274: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0xCF8))) + b;
                    s0v = (*((int *)(b + 0xCFC))) + b;
                    break;
                }

                case 0x220:

                case 0x221:

                case 0x222: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x1BC0))) + b;
                    s0v = (*((int *)(b + 0x1BC4))) + b;
                    break;
                }

                case 0x223: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x2D38))) + b;
                    s0v = (*((int *)(b + 0x2D3C))) + b;
                    break;
                }

                case 0x275:

                case 0x276: {
                    int b = *((int *)&self->pack);
                    s1v = (*((int *)(b + 0x2274))) + b;
                    s0v = (*((int *)(b + 0x2278))) + b;
                    break;
                }
            }

            if ((*((int *)&self->unk6EC)) != 0) {
                int b = *((int *)&self->pack);
                s1v = (*((int *)(b + 0x44C))) + b;
                s0v = (*((int *)(b + 0x450))) + b;
            }
            func_002A8578(self, s1v, s0v, 10, 0.0f, gb, 0);
            *((int *)&self->timerA) = 10;
            *((unsigned char *)&self->step) = (*((unsigned char *)&self->step)) + 1;

        case 1:
            if ((*((int *)&self->timerA)) != 0) {
                *((int *)&self->timerA) = (*((int *)&self->timerA)) - 1;
                moveMotion(self);
            } else {
                *((int *)&self->emFlags) = (*((int *)&self->emFlags)) | 0x8000;
                if (0.0f < (*((float *)&self->tint.w))) {
                    moveMotion(self);
                    cObjBase_addNullSpeed_Rotation(self, 1.0f);
                    cObjBase_addNullSpeed(self, 1.0f);
                }
            }
            sp0 = *((char **)&self->pos);
            d = Turn_dest(sp0, Getplayer()->pos, *((float *)&self->rot.y),
                          3.14159274f);
            if (d < 0.0f) {
                ad = (new_var = -d);
            } else {
                ad = d;
            }
            if (0.34906584f < ad) {
                *((unsigned char *)&self->step) = 2;
            }
            break;

        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            sp0 = *((char **)&self->pos);
            d = Turn_dest(sp0, Getplayer()->pos, *((float *)&self->rot.y),
                          3.14159274f);
            if (d < 0.0f) {
                switch (*((int *)&self->emNo)) {
                    default: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0xB0))) + b;
                        s0v = (*((int *)(b + 0xB4))) + b;
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
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x650))) + b;
                        s0v = (*((int *)(b + 0x654))) + b;
                        break;
                    }

                    case 0x242:

                    case 0x243:

                    case 0x244: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x35D4))) + b;
                        s0v = (*((int *)(b + 0x35D8))) + b;
                        break;
                    }

                    case 0x256:

                    case 0x27E: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x25DC))) + b;
                        s0v = (*((int *)(b + 0x25E0))) + b;
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

                    case 0x252:

                    case 0x25A: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x10B0))) + b;
                        s0v = (*((int *)(b + 0x10B4))) + b;
                        break;
                    }

                    case 0x225:

                    case 0x24D: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3C90))) + b;
                        s0v = (*((int *)(b + 0x3C94))) + b;
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
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x830))) + b;
                        s0v = (*((int *)(b + 0x834))) + b;
                        break;
                    }

                    case 0x278:

                    case 0x279: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1FB8))) + b;
                        s0v = (*((int *)(b + 0x1FBC))) + b;
                        break;
                    }

                    case 0x250:

                    case 0x251: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x18F8))) + b;
                        s0v = (*((int *)(b + 0x18FC))) + b;
                        break;
                    }

                    case 0x260: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3040))) + b;
                        s0v = (*((int *)(b + 0x3044))) + b;
                        break;
                    }

                    case 0x264: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3274))) + b;
                        s0v = (*((int *)(b + 0x3278))) + b;
                        break;
                    }

                    case 0x265: {
                        int b = *((int *)&self->pack);
                        cEm00 *m = self->unk744;
                        s1v = (*((int *)(b + 0x3734))) + b;
                        s0v = (*((int *)(b + 0x3738))) + b;
                        if (m != 0) {
                            ForwardAnimParamPairByIndex_27EA50(m, 0x4);
                        }
                        break;
                    }

                    case 0x26A: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3D34))) + b;
                        s0v = (*((int *)(b + 0x3D38))) + b;
                        break;
                    }

                    case 0x20C:

                    case 0x24F: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1EB4))) + b;
                        s0v = (*((int *)(b + 0x1EB8))) + b;
                        break;
                    }

                    case 0x205:

                    case 0x206:

                    case 0x207:

                    case 0x208:

                    case 0x224: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1568))) + b;
                        s0v = (*((int *)(b + 0x156C))) + b;
                        break;
                    }

                    case 0x241: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3A08))) + b;
                        s0v = (*((int *)(b + 0x3A0C))) + b;
                        break;
                    }

                    case 0x209:

                    case 0x21F: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3420))) + b;
                        s0v = (*((int *)(b + 0x3424))) + b;
                        break;
                    }

                    case 0x20F:

                    case 0x210:

                    case 0x211:

                    case 0x226:

                    case 0x270:

                    case 0x271:

                    case 0x272:

                    case 0x273:

                    case 0x274: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0xD18))) + b;
                        s0v = (*((int *)(b + 0xD1C))) + b;
                        break;
                    }

                    case 0x220:

                    case 0x221:

                    case 0x222: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1BC8))) + b;
                        s0v = (*((int *)(b + 0x1BCC))) + b;
                        break;
                    }

                    case 0x223: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x2D48))) + b;
                        s0v = (*((int *)(b + 0x2D4C))) + b;
                        break;
                    }

                    case 0x275:

                    case 0x276: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x227C))) + b;
                        s0v = (*((int *)(b + 0x2280))) + b;
                        break;
                    }
                }

            } else {
                switch (*((int *)&self->emNo)) {
                    default: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0xB0))) + b;
                        s0v = (*((int *)(b + 0xB4))) + b;
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
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x650))) + b;
                        s0v = (*((int *)(b + 0x654))) + b;
                        break;
                    }

                    case 0x242:

                    case 0x243:

                    case 0x244: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x35D4))) + b;
                        s0v = (*((int *)(b + 0x35D8))) + b;
                        break;
                    }

                    case 0x256:

                    case 0x27E: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x25DC))) + b;
                        s0v = (*((int *)(b + 0x25E0))) + b;
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

                    case 0x252:

                    case 0x25A: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x10B0))) + b;
                        s0v = (*((int *)(b + 0x10B4))) + b;
                        break;
                    }

                    case 0x225:

                    case 0x24D: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3C90))) + b;
                        s0v = (*((int *)(b + 0x3C94))) + b;
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
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x830))) + b;
                        s0v = (*((int *)(b + 0x834))) + b;
                        break;
                    }

                    case 0x278:

                    case 0x279: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1FB8))) + b;
                        s0v = (*((int *)(b + 0x1FBC))) + b;
                        break;
                    }

                    case 0x250:

                    case 0x251: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x18F8))) + b;
                        s0v = (*((int *)(b + 0x18FC))) + b;
                        break;
                    }

                    case 0x260: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3040))) + b;
                        s0v = (*((int *)(b + 0x3044))) + b;
                        break;
                    }

                    case 0x264: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3274))) + b;
                        s0v = (*((int *)(b + 0x3278))) + b;
                        break;
                    }

                    case 0x265: {
                        int b = *((int *)&self->pack);
                        cEm00 *m = self->unk744;
                        s1v = (*((int *)(b + 0x3734))) + b;
                        s0v = (*((int *)(b + 0x3738))) + b;
                        if (m != 0) {
                            ForwardAnimParamPairByIndex_27EA50(m, 0x4);
                        }
                        break;
                    }

                    case 0x26A: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3D34))) + b;
                        s0v = (*((int *)(b + 0x3D38))) + b;
                        break;
                    }

                    case 0x20C:

                    case 0x24F: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1EB4))) + b;
                        s0v = (*((int *)(b + 0x1EB8))) + b;
                        break;
                    }

                    case 0x205:

                    case 0x206:

                    case 0x207:

                    case 0x208:

                    case 0x224: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1568))) + b;
                        s0v = (*((int *)(b + 0x156C))) + b;
                        break;
                    }

                    case 0x241: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3A08))) + b;
                        s0v = (*((int *)(b + 0x3A0C))) + b;
                        break;
                    }

                    case 0x209:

                    case 0x21F: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x3420))) + b;
                        s0v = (*((int *)(b + 0x3424))) + b;
                        break;
                    }

                    case 0x20F:

                    case 0x210:

                    case 0x211:

                    case 0x226:

                    case 0x270:

                    case 0x271:

                    case 0x272:

                    case 0x273:

                    case 0x274: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0xD20))) + b;
                        s0v = (*((int *)(b + 0xD24))) + b;
                        break;
                    }

                    case 0x220:

                    case 0x221:

                    case 0x222: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x1BC8))) + b;
                        s0v = (*((int *)(b + 0x1BCC))) + b;
                        break;
                    }

                    case 0x223: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x2D48))) + b;
                        s0v = (*((int *)(b + 0x2D4C))) + b;
                        break;
                    }

                    case 0x275:

                    case 0x276: {
                        int b = *((int *)&self->pack);
                        s1v = (*((int *)(b + 0x227C))) + b;
                        s0v = (*((int *)(b + 0x2280))) + b;
                        break;
                    }
                }
            }
            if ((*((int *)&self->unk6EC)) != 0) {
                int b = *((int *)&self->pack);
                s1v = (*((int *)(b + 0x454))) + b;
                s0v = (*((int *)(b + 0x458))) + b;
            }
            func_002A8578(self, s1v, s0v, 10, 0.0f, gb, 0);
            *((unsigned char *)&self->step) = (*((unsigned char *)&self->step)) + 1;

        case 3:
            cGameObj_SetTgtTurn(self, Getplayer()->pos,
                                (*((float *)&self->speedRate)) * 0.09817477f);
            if (900.0f < (*((float *)&self->playerDist))) {
                if ((D_007476B0 & 7) == ((*((unsigned int *)&self->unk17D0)) & 7)) {
                    moveMotion(self);
                }
            } else {
                moveMotion(self);
            }
            sp0 = *((char **)&self->pos);
            d = Turn_dest(sp0, Getplayer()->pos, *((float *)&self->rot.y),
                          3.14159274f);
            if (d < 0.0f) {
                ad = -d;
            } else {
                ad = d;
            }
            k3 = 0.08726646f;
            d = k3;
            if (ad < d) {
                *((unsigned char *)&self->step) = 0;
            }
            break;
    }

    if (((*((float *)&self->playerDist)) < 64.0f) || ((*((int *)&self->unk16EC)) != 0)) {
        if ((D_007476B0 & 7) == ((*((unsigned int *)&self->unk17D0)) & 7)) {
            *((int *)&self->emFlags2) = (*((int *)&self->emFlags2)) & 0xF7FFFFFF;
            func_002A74E0(self, Getplayer()->pos, 1);
            if (func_002A7CA0((cGameObj *)self, (cVec *)&self->unk16A0.x) != 0) {
                *((int *)&self->emFlags2) = (*((int *)&self->emFlags2)) | 0x8000000;
            }
            if (((*((float *)&self->unk510)) < 8.0f) || ((*((int *)&self->unk16EC)) != 0)) {
                *((int *)&self->emFlags) = ((*((int *)&self->emFlags)) | 2) & 0xFFFF7FFF;
                if ((((irand() & 1) != 0) && ((*((float *)&self->slideTime)) <= 0.0f)) &&
                    ((*((int *)&self->unk16EC)) <= 0)) {
                    *((unsigned char *)&self->stepArg) = 0;
                    *((unsigned char *)&self->mode) = 0;
                    *((unsigned char *)&self->step) = 0;
                    *((unsigned char *)&self->phase) = 0x6B;
                } else {
                    func_002705D8(self);
                }
                return;
            }
        }
    }
    if (0.0f < (*((float *)&self->slideTime))) {
        func_002705D8(self);
    }
}
