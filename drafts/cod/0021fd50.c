/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cCoreSave.h"
#include "godhand/cCamera.h"
#include "godhand/cEmManage.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/angle.h"
#include "godhand/rand.h"

#define RES(off) EM_RES_REC(EM_RES(self), off)

/* A weapon or combo attack: step 0 picks the first swing's motion, volumes,
 * turn time and effect for the enemy type, step 1 runs it; steps 2-3 swing
 * again (or with the weapon held), steps 4-5 repeat the last swing a counted
 * number of times, steps 6-7 end it; steps 8-13 are the three alternate
 * swings that end in a new phase when the player stands close. Every frame
 * enemies 0x275/0x276 start their volumes on the motion flags, and from
 * level 3 up a counter can end the attack. */
__attribute__((section(".text.func_0021FD50")))
void func_0021FD50(cEm00 *self)
{
    int mode = 0xA;
    int fxKind = FX_KIND_NONE;
    int fxNo = 1;
    int fxMode = 0;
    void *fxFollow = 0;
    unsigned short sel;
    int recA;
    int recB;
    float angle;

    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    switch (self->emNo) {
    case 0x20B:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x225:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x24D:
    case 0x260:
        if (self->step == 0) {
            self->step = 2;
        }
        break;
    case 0x256:
    case 0x27E:
        if (self->step == 0 && (irand() & 3)) {
            self->step = 8;
        }
        break;
    case 0x223:
        if (self->step == 0 && self->fx1 == 0) {
            self->step = 2;
        }
        break;
    case 0x204:
    case 0x218:
    case 0x21B:
    case 0x21F:
    case 0x22D:
    case 0x25B:
        if (self->step == 0 && (irand() & 1)) {
            self->step = 2;
        }
        break;
    }
    if (self->unk6EC != 0 && self->step == 0) {
        self->step = 2;
    }
    switch (self->emNo) {
    case 0x220:
    case 0x221:
    case 0x222:
        self->objFlags &= 0xFFFBFFFF;
        break;
    }
    if (self->emNo == 0x23B) {
        self->idleTimer = 60.0f;
    }
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
    case 0:
        self->unk1864 = 0;
        self->timer2 = 0.0f;
        self->timerB = 1;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
        case 0x200:
            recA = RES(0x138);
            recB = RES(0x13C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x140);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, -1, 0);
            break;
        case 0x23B:
            recA = RES(0x138);
            recB = RES(0x13C);
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, -1, 0);
            break;
        case 0x201:
            recA = RES(0x174);
            recB = RES(0x178);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x17C);
            }
            self->timerA = 0x3C;
            StoreMotionParamsBoth_2609A8((char *)self, 5, 0, 0x3D, -1, 0);
            break;
        case 0x228:
            recA = RES(0x174);
            recB = RES(0x178);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x17C);
            }
            self->timerA = 0x5A;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
            break;
        case 0x22B:
            recA = RES(0x168);
            recB = RES(0x16C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x170);
            }
            self->timerA = 0x3C;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 9, 0x37, -1, 0);
            break;
        case 0x204:
        case 0x25B:
            /* retail reads 0x1F4 for both the motion and its level 5 alternate */
            recA = RES(0x1EC);
            recB = RES(0x1F4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1F4);
            }
            self->timerA = 0x64;
            StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
            break;
        case 0x23A:
            switch ((unsigned int)irand() & 3) {
            default:
            case 0:
                recA = RES(0x138);
                recB = RES(0x13C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x140);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, -1, 0);
                break;
            case 1:
                recA = RES(0x6C4);
                recB = RES(0x6C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x6CC);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
                break;
            case 2:
                recA = RES(0x168);
                recB = RES(0x16C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x170);
                }
                self->timerA = 0x3C;
                StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 9, 0x37, -1, 0);
                break;
            case 3:
                /* retail's level 5 alternate is the 0x6CC motion of case 1 */
                recA = RES(0x700);
                recB = RES(0x704);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x6CC);
                }
                self->timerA = 0x4B;
                StoreMotionParams_2609E0((char *)self, 0xA, 0, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
                break;
            }
            break;
        case 0x214:
            recA = RES(0x1B24);
            recB = RES(0x1B28);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1B2C);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, 0, 0xF6);
            break;
        case 0x202:
        case 0x203:
        case 0x216:
            recA = RES(0x6C4);
            recB = RES(0x6C8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x6CC);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x229:
            recA = RES(0x6C4);
            recB = RES(0x6C8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x6CC);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x22A:
            if (irand() & 1) {
                recA = RES(0x6C4);
                recB = RES(0x6C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x6CC);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            } else {
                recA = RES(0x700);
                recB = RES(0x704);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x6CC);
                }
                self->timerA = 0x4B;
                StoreMotionParams_2609E0((char *)self, 0xA, 0, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            }
            break;
        case 0x24B:
            recA = RES(0x724);
            recB = RES(0x728);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x72C);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x213:
        case 0x217:
            recA = RES(0x2F34);
            recB = RES(0x2F38);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x2F3C);
                if (self->fx6 != 0) {
                    Obj1D00_SetState_7_1A_a1(&self->fx6->base, 1);
                }
            } else if (self->fx6 != 0) {
                Obj1D00_SetState_7_1A_a1(&self->fx6->base, 0);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
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
        case 0x25A:
            if (self->fx0 != 0
                && (self->playerDist > 4.0f
                    || (self->emNo == 0x21C && cCoreSave_getGameLevel(&D_00569B70) >= 3))) {
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    Obj1D00_SetState_6_4_a1(&self->fx0->base, 1);
                } else {
                    Obj1D00_SetState_6_4_a1(&self->fx0->base, 0);
                }
                recA = RES(0x117C);
                recB = RES(0x1180);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1184);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 0xA, 0x14, 0x3D, 0, 0xF5);
                Set_Fields_1884_1894_2609F8((char *)self, 0x14, 0x14, 0x3E, 0, 0xF5);
                break;
            }
            switch (self->emNo) {
            default:
                recA = RES(0x1140);
                recB = RES(0x1144);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1148);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, -1, 0);
                break;
            case 0x21A:
                if (self->unk186B >= 6) {
                    recA = RES(0x11B8);
                    recB = RES(0x11BC);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x11C0);
                    }
                    self->timerA = 0x46;
                    StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                    Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                } else {
                    recA = RES(0x1140);
                    recB = RES(0x1144);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x1148);
                    }
                    self->timerA = 0x32;
                    StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
                    Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x37, -1, 0);
                }
                break;
            case 0x21C:
                recA = RES(0x11C4);
                recB = RES(0x11C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11CC);
                }
                self->timerA = 0x50;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 0x22C:
                recA = RES(0x11B8);
                recB = RES(0x11BC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11C0);
                }
                self->timerA = 0x46;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 0x21D:
            case 0x22E:
                recA = RES(0x11C4);
                recB = RES(0x11C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11CC);
                }
                self->timerA = 0x50;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 0x21E:
            case 0x22F:
            case 0x25A:
                recA = RES(0x11D0);
                recB = RES(0x11D4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11D8);
                }
                self->timerA = 0x50;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 0x249:
            case 0x24E:
                switch (irand() & 1) {
                case 0:
                default:
                    recA = RES(0x11B8);
                    recB = RES(0x11BC);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x11C0);
                    }
                    self->timerA = 0x46;
                    StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                    Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                    break;
                case 1:
                    recA = RES(0x11D0);
                    recB = RES(0x11D4);
                    if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                        recB = RES(0x11D8);
                    }
                    self->timerA = 0x50;
                    StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                    Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                    break;
                }
                break;
            }
            break;
        case 0x252:
            switch ((unsigned int)irand() & 3) {
            default:
            case 0:
                recA = RES(0x2540);
                recB = RES(0x2544);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2548);
                }
                self->timerA = 0x32;
                StoreMotionParams_2609E0((char *)self, 0xA, 0, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
                break;
            case 1:
                recA = RES(0x11C4);
                recB = RES(0x11C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11CC);
                }
                self->timerA = 0x50;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 2:
                recA = RES(0x11B8);
                recB = RES(0x11BC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11C0);
                }
                self->timerA = 0x46;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            case 3:
                recA = RES(0x11D0);
                recB = RES(0x11D4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11D8);
                }
                self->timerA = 0x46;
                StoreMotionParams_2609E0((char *)self, 0xA, 9, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 8, 0x37, -1, 0);
                break;
            }
            break;
        case 0x20C:
        case 0x24F:
            recA = RES(0x1F00);
            recB = RES(0x1F04);
            self->timerA = 0x32;
            StoreMotionParamsBoth_2609A8((char *)self, 5, 0, 0x3D, 0, 0xF0);
            break;
        case 0x250:
        case 0x251:
            recA = RES(0x19BC);
            recB = RES(0x19C4);
            if (cCoreSave_getGameLevel(&D_00569B70) >= 2 && (irand() & 1)) {
                recB = RES(0x19C0);
            }
            self->timerA = 0x46;
            StoreMotionParams_2609E0((char *)self, 0x1E, 0, 0x3D, 1, 0x28);
            Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0, 0x3E, 1, 0x28);
            break;
        case 0x260:
            recA = RES(0x19BC);
            recB = RES(0x19C0);
            if (cCoreSave_getGameLevel(&D_00569B70) >= 2 && (irand() & 1)) {
                recB = RES(0x19C4);
            }
            self->timerA = 0x46;
            StoreMotionParams_2609E0((char *)self, 0x3C, 0, 0x3D, 1, 0x28);
            Set_Fields_1884_1894_2609F8((char *)self, 0x50, 0, 0x3E, 1, 0x28);
            break;
        case 0x205:
        case 0x207:
        case 0x224:
            recA = RES(0x15E4);
            recB = RES(0x15E8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x15EC);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x241:
            recA = RES(0x3A64);
            recB = RES(0x3A68);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3A6C);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 3, 0x3C, -1, 0);
            break;
        case 0x206:
        case 0x208:
            recA = RES(0x15E4);
            recB = RES(0x15E8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x15EC);
            }
            self->timerA = 0x32;
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, 0, 0xF0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, 0, 0xF0);
            break;
        case 0x209:
            fxFollow = self->fx5;
            fxKind = 0x61;
            fxNo = 0x10;
            fxMode = 2;
            if (irand() & 1) {
                recA = RES(0x34D0);
                recB = RES(0x34D4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x34D8);
                } else {
                    fxNo = 0xF;
                }
                self->timerA = 0x5A;
                StoreMotionParams_2609E0((char *)self, 0x1E, 0x16, 0x37, 0, 0xF0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x32, 0x16, 0x3E, 0, 0xF0);
            } else {
                recA = RES(0x34C4);
                recB = RES(0x34C8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    fxNo = 0xE;
                    recB = RES(0x34CC);
                } else {
                    fxNo = 0xD;
                }
                self->timerA = 0x5A;
                StoreMotionParams_2609E0((char *)self, 0x1E, 0x16, 0x37, 0, 0xF0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x32, 0x17, 0x3E, 0, 0xF0);
            }
            break;
        case 0x21F:
            fxKind = 0x77;
            fxNo = 0xD;
            fxMode = 2;
            fxFollow = self->fx5;
            if (irand() & 1) {
                recA = RES(0x3550);
                recB = RES(0x3554);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3558);
                } else {
                    fxNo = 0xC;
                }
                self->timerA = 0x5A;
                StoreMotionParams_2609E0((char *)self, 0x14, 0x18, 0x37, 0, 0xF0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x1E, 0x18, 0x3E, 0, 0xF0);
            } else {
                recA = RES(0x3570);
                recB = RES(0x3574);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    fxNo = 0x12;
                    recB = RES(0x3578);
                } else {
                    fxNo = 0x11;
                }
                self->timerA = 0x5A;
                StoreMotionParams_2609E0((char *)self, 0x14, 0x16, 0x37, 0, 0xF0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x1E, 0x17, 0x3E, 0, 0xF0);
            }
            break;
        case 0x275:
        case 0x276:
            if (self->emFlags2 & 0x80) {
                recA = RES(0x22EC);
                recB = RES(0x22F0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x22F4);
                }
                StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0xA, 0x3E, -1, 0);
                self->unk5F8 = 0;
            } else {
                /* retail's level 5 alternate is the same motion */
                recA = RES(0x2304);
                recB = RES(0x2308);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2308);
                }
                self->timerA = 0x37;
                self->unk5F8 = 1;
            }
            self->timer2 = 40.0f;
            break;
        case 0x223:
            recA = RES(0x2DD0);
            recB = RES(0x2DD4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x2DD8);
            }
            self->timerA = 0x4B;
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                self->timerA = 0x3A;
            }
            StoreMotionParams_2609E0((char *)self, 0x14, 0x2E, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0x1E, 0x2D, 0x3E, -1, 0);
            self->timer2 = 30.0f;
            break;
        case 0x256:
        case 0x27E:
            /* the second motion is 0x2C68, not 0x2C64 */
            if (self->emNo == 0x256 || (irand() & 1)) {
                recA = RES(0x2C60);
                recB = RES(0x2C68);
                self->timerA = 0x50;
                mode = 3;
                StoreMotionParams_2609E0((char *)self, 0x1E, 0, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x32, 2, 0x3E, -1, 0);
                self->timer2 = 30.0f;
            } else {
                recA = RES(0x29D8);
                recB = RES(0x29DC);
                self->timerA = 0x28;
                mode = 3;
                StoreMotionParams_2609E0((char *)self, 0x1E, 0, 0x37, -1, 0);
                Set_Fields_1884_1894_2609F8((char *)self, 0x32, 2, 0x3E, -1, 0);
                self->timer2 = 30.0f;
            }
            break;
        case 0x218:
        case 0x246:
            switch ((unsigned int)irand() & 3) {
            default:
            case 0:
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
                recA = RES(0x3B60);
                recB = RES(0x3B64);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3B68);
                }
                self->timerA = 0x4B;
                break;
            case 1:
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
                recA = RES(0x3B6C);
                recB = RES(0x3B70);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3B74);
                }
                self->timerA = 0x50;
                break;
            case 2:
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
                recA = RES(0x3B78);
                recB = RES(0x3B7C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3B80);
                }
                self->timerA = 0x6E;
                break;
            case 3:
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
                recA = RES(0x3B84);
                recB = RES(0x3B88);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3B8C);
                }
                self->timerA = 0x5F;
                break;
            }
            break;
        case 0x247:
            recA = RES(0x3C38);
            recB = RES(0x3C3C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3C40);
            }
            self->timerA = 0x32;
            StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
            break;
        case 0x278:
        case 0x279:
            recA = RES(0x2024);
            recB = RES(0x2028);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x202C);
            }
            self->timerA = 0x64;
            StoreMotionParams_2609E0((char *)self, 0xA, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        }
        self->timerC = 0;
        func_002A8578((int)self, recA, recB, mode, 0.0f, sel, 0);
        if (fxKind_isSet(fxKind)) {
            InitRenderStruct_2A8608((cGameObj *)self, fxKind, (void *)fxNo, 0, fxMode, fxFollow);
        }
        self->timer = self->rot.y;
        self->step++;
        /* fallthrough */
    case 1:
        if (0.0f < self->timer2) {
            self->emFlags |= 0x800000;
            self->timer2 -= self->speedRate;
        }
        if (self->emNo == 0x208 && self->fx4 != 0
            && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&self->fx4->base) == 0) {
            self->emFlags |= 0x80000000;
        }
        if (self->timerA != 0) {
            cVec *from = self->pos;

            self->timerA--;
            angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.09817477f);
            self->timer += angle;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += angle;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        self->unk1864 = 0;
        self->timer2 = 0.0f;
        self->timerB = 1;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            recA = RES(0x1C7C);
            recB = RES(0x1C80);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1C84);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x222:
            recA = RES(0x1C7C);
            recB = RES(0x1C88);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1C8C);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x221:
            recA = RES(0x1C7C);
            recB = RES(0x1C80);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1C84);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x3D, 0, 0xF0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, 0, 0xF0);
            break;
        case 0x20B:
            recA = RES(0x1DC0);
            recB = RES(0x1DC4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x1DC8);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, 0, 0x111);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, 0, 0x111);
            break;
        case 0x242:
        case 0x243:
            recA = RES(0x3614);
            recB = RES(0x3618);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x361C);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x244:
            recA = RES(0x3638);
            recB = RES(0x363C);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3640);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x260:
            recA = RES(0x30E4);
            recB = RES(0x30E8);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x30EC);
            }
            StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0x32, 0x3E, -1, 0);
            self->timer2 = 45.0f;
            break;
        case 0x223:
            recA = RES(0x2DDC);
            recB = RES(0x2DE0);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x2DE4);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 3, 0x3E, -1, 0);
            self->timer2 = 30.0f;
            break;
        case 0x21F:
            recA = RES(0x357C);
            recB = RES(0x3580);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3584);
            }
            StoreMotionParams_2609E0((char *)self, 0xF, 0x16, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xF, 0x16, 0x3E, -1, 0);
            break;
        case 0x225:
        case 0x24D:
            recA = RES(0x3CE0);
            recB = RES(0x3CE4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3CE8);
            }
            StoreMotionParams_2609E0((char *)self, 0xA, 0, 0x37, 0, 0xF0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, 0, 0xF0);
            break;
        case 0x204:
        case 0x25B:
            recA = RES(0x23C);
            recB = RES(0x240);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x244);
            }
            StoreMotionParams_2609E0((char *)self, 5, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0, 0x3E, -1, 0);
            break;
        case 0x218:
            recA = RES(0x3B90);
            recB = RES(0x3B94);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x3B98);
            }
            StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0, 0x37, -1, 0);
            break;
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
        case 0x25A:
            recA = RES(0x11DC);
            recB = RES(0x11E0);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x11E4);
            }
            StoreMotionParamsBoth_2609A8((char *)self, 0xA, 9, 0x37, -1, 0);
            break;
        }
        if (self->unk6EC != 0) {
            recA = RES(0x4C0);
            recB = RES(0x4C4);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                recB = RES(0x4C8);
            }
            /* weapon 0x368 has its own entry with the default swing */
            switch (self->unk6EC->base.actorId) {
            default:
            case 0x361:
                StoreMotionParams_2609E0((char *)self, 0x14, 0x13, 0x3A, 0, 0x111);
                Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0x12, 0x3B, 0, 0x111);
                break;
            case 0x362:
                StoreMotionParams_2609E0((char *)self, 0x14, 0x13, 0x3A, 0, 0x112);
                Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0x12, 0x3B, 0, 0x112);
                break;
            case 0x3B7:
            case 0x363:
                StoreMotionParams_2609E0((char *)self, 0x14, 0x13, 0x3A, 0, 0x11D);
                Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0x12, 0x3B, 0, 0x11D);
                break;
            case 0x380:
                StoreMotionParams_2609E0((char *)self, 5, 0x13, 0x3A, 0, 0xEA);
                Set_Fields_1884_1894_2609F8((char *)self, 0xA, 0x12, 0x3B, 0, 0xEA);
                break;
            case 0x368:
                StoreMotionParams_2609E0((char *)self, 0x14, 0x13, 0x3A, 0, 0x111);
                Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0x12, 0x3B, 0, 0x111);
                break;
            case 0x379:
                StoreMotionParams_2609E0((char *)self, 0x14, 0x13, 0x38, 0, 0x112);
                Set_Fields_1884_1894_2609F8((char *)self, 0x28, 0x12, 0x39, 0, 0x112);
                break;
            }
        }
        self->timerC = 0;
        func_002A8578((int)self, recA, recB, 5, 0.0f, sel, 0);
        self->timer = self->rot.y;
        self->step++;
        /* fallthrough */
    case 3: {
        cVec *from = self->pos;

        angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.09817477f);
        self->timer += angle;
        self->timer = Adjust_theta(self->timer);
        self->rot.y += angle;
        self->rot.y = Adjust_theta(self->rot.y);
    }
        if (0.0f < self->timer2) {
            self->emFlags |= 0x800000;
            self->timer2 -= self->speedRate;
        }
        if (moveMotion(self) != 0) {
            if (cEmManage_CkPlSorry(&D_005864F0) || cEmManage_CkPlCatched(&D_005864F0)) {
                self->step = 6;
                break;
            }
            self->step = 4;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 4:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (self->unk6EC != 0) {
            recA = RES(0x4CC);
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                func_002A8578((int)self, recA, RES(0x4D0), 2, 0.0f, sel, 0);
                InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x81, 0, 2, self->unk6EC);
            } else {
                func_002A8578((int)self, recA, RES(0x4D0), 2, 0.0f, sel, 0);
                InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x7C, 0, 2, self->unk6EC);
            }
        } else {
            switch (self->emNo) {
            default:
                recA = RES(0x1C90);
                recB = RES(0x1C94);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1C98);
                }
                break;
            case 0x222:
                recA = RES(0x1C90);
                recB = RES(0x1C9C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1CA0);
                }
                break;
            case 0x20B:
                recA = RES(0x1DCC);
                recB = RES(0x1DD0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1DD4);
                }
                break;
            case 0x242:
            case 0x243:
                recA = RES(0x3620);
                recB = RES(0x3624);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3628);
                }
                break;
            case 0x244:
                recA = RES(0x3644);
                recB = RES(0x3648);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x364C);
                }
                break;
            case 0x260:
                recA = RES(0x30F0);
                recB = RES(0x30F4);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x30F8);
                }
                break;
            case 0x223:
                recA = RES(0x2DE8);
                recB = RES(0x2DEC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2DF0);
                }
                break;
            case 0x21F:
                fxFollow = self->fx5;
                fxKind = 0x77;
                fxNo = 0x14;
                fxMode = 2;
                recA = RES(0x3588);
                recB = RES(0x358C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3590);
                } else {
                    fxNo = 0x13;
                }
                break;
            case 0x225:
            case 0x24D:
                recA = RES(0x3CEC);
                recB = RES(0x3CF0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3CF4);
                }
                break;
            case 0x204:
            case 0x25B:
                recA = RES(0x248);
                recB = RES(0x24C);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x250);
                }
                break;
            case 0x218:
                recA = RES(0x3B9C);
                recB = RES(0x3BA0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3BA4);
                }
                break;
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
            case 0x25A:
                recA = RES(0x11E8);
                recB = RES(0x11EC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11F0);
                }
                break;
            }
            func_002A8578((int)self, recA, recB, 2, 0.0f, sel, 0);
            if (fxKind_isSet(fxKind)) {
                InitRenderStruct_2A8608((cGameObj *)self, fxKind, (void *)fxNo, 0, fxMode, fxFollow);
            }
        }
        self->unk568 = 1;
        if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && (irand() & 1)) {
            self->unk568 = 2;
        }
        switch (self->emNo) {
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x227:
        case 0x228:
        case 0x229:
        case 0x22A:
        case 0x22B:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x23A:
        case 0x248:
        case 0x249:
        case 0x24B:
        case 0x24C:
        case 0x24E:
        case 0x25A:
            if (irand() & 1) {
                self->unk568++;
            }
            break;
        case 0x242:
        case 0x243:
        case 0x244:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk568 = 3;
                break;
            case 1:
                self->unk568 = 4;
                break;
            case 2:
                self->unk568 = 5;
                break;
            }
            break;
        case 0x223:
        case 0x260:
            self->unk568 = 2;
            if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && (irand() & 1)) {
                self->unk568 = 3;
            }
            break;
        case 0x21F:
            switch ((unsigned int)irand() % 3) {
            case 0:
            default:
                self->unk568 = 3;
                break;
            case 1:
                self->unk568 = 4;
                break;
            case 2:
                self->unk568 = 5;
                break;
            }
            break;
        }
        self->step++;
        /* fallthrough */
    case 5: {
        cVec *from = self->pos;

        angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.09817477f);
        self->timer += angle;
        self->timer = Adjust_theta(self->timer);
        self->rot.y += angle;
        self->rot.y = Adjust_theta(self->rot.y);
    }
        if (moveMotion(self) != 0) {
            self->unk568--;
            if (self->emNo != 0x260) {
                if (self->unk568 <= 0 || self->playerDist > 16.0f) {
                    self->step = 6;
                }
            } else if (self->unk568 <= 0) {
                self->step = 6;
            }
            if (self->unk1864 != 0) {
                self->step = 6;
            }
            if (cEmManage_CkPlSorry(&D_005864F0) || cEmManage_CkPlCatched(&D_005864F0)) {
                self->step = 6;
            }
        }
        if (self->emNo == 0x204) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 2.0f);
        } else {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        }
        if (self->emNo == 0x260) {
            if ((self->seqFlags & 1) && func_00270DB0(self) != 0) {
                func_00129718(Getplayer(), self, 0xB);
                cEm00_setState(self, 0, 0x5C, 0);
                return;
            }
            self->seqFlags &= 0xFFFE;
        }
        break;
    case 6:
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (self->unk6EC != 0) {
            recA = RES(0x4E0);
            switch (self->unk6EC->base.actorId) {
            default:
            case 0x361:
            case 0x363:
            case 0x380:
            case 0x3B7:
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    func_002A8578((int)self, recA, RES(0x4E4), 2, 0.0f, sel, 0);
                    InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x82, 0, 2, self->unk6EC);
                } else {
                    func_002A8578((int)self, recA, RES(0x4E4), 2, 0.0f, sel, 0);
                    InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x7D, 0, 2, self->unk6EC);
                }
                break;
            case 0x362:
            case 0x368:
            case 0x379:
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    func_002A8578((int)self, recA, RES(0x4E8), 2, 0.0f, sel, 0);
                    InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x82, 0, 2, self->unk6EC);
                } else {
                    func_002A8578((int)self, recA, RES(0x4E8), 2, 0.0f, sel, 0);
                    InitRenderStruct_2A8608((cGameObj *)self, 0x58, (void *)0x7D, 0, 2, self->unk6EC);
                }
                break;
            }
        } else {
            switch (self->emNo) {
            default:
                recA = RES(0x1CA4);
                recB = RES(0x1CA8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1CAC);
                }
                break;
            case 0x222:
                recA = RES(0x1CA4);
                recB = RES(0x1CB0);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1CB4);
                }
                break;
            case 0x20B:
                recA = RES(0x1DD8);
                recB = RES(0x1DDC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x1DE0);
                }
                break;
            case 0x242:
            case 0x243:
                recA = RES(0x362C);
                recB = RES(0x3630);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3634);
                }
                break;
            case 0x244:
                recA = RES(0x3650);
                recB = RES(0x3654);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3658);
                }
                break;
            case 0x260:
                recA = RES(0x30FC);
                recB = RES(0x3100);
                break;
            case 0x223:
                recA = RES(0x2DF4);
                recB = RES(0x2DF8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x2DFC);
                }
                break;
            case 0x21F:
                fxFollow = self->fx5;
                fxKind = 0x77;
                fxNo = 0x16;
                fxMode = 2;
                recA = RES(0x3594);
                recB = RES(0x3598);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x359C);
                } else {
                    fxNo = 0x15;
                }
                break;
            case 0x225:
            case 0x24D:
                recA = RES(0x3CF8);
                recB = RES(0x3CFC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3D00);
                }
                break;
            case 0x204:
            case 0x25B:
                recA = RES(0x254);
                recB = RES(0x258);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x25C);
                }
                break;
            case 0x218:
                recA = RES(0x3BA8);
                recB = RES(0x3BAC);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x3BB0);
                }
                break;
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
            case 0x25A:
                recA = RES(0x11F4);
                recB = RES(0x11F8);
                if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                    recB = RES(0x11FC);
                }
                break;
            }
            func_002A8578((int)self, recA, recB, 2, 0.0f, sel, 0);
            if (fxKind_isSet(fxKind)) {
                InitRenderStruct_2A8608((cGameObj *)self, fxKind, (void *)fxNo, 0, fxMode, fxFollow);
            }
        }
        self->timerA = 0xA;
        self->unk1864 = 0;
        self->step++;
        /* fallthrough */
    case 7:
        if (self->timerA != 0) {
            cVec *from = self->pos;

            self->timerA--;
            angle = Turn_dest(&from->x, &Getplayer()->pos->x, self->timer, self->speedRate * 0.09817477f);
            self->timer += angle;
            self->timer = Adjust_theta(self->timer);
            self->rot.y += angle;
            self->rot.y = Adjust_theta(self->rot.y);
        }
        if (moveMotion(self) != 0) {
            switch (self->emNo) {
            case 0x220:
            case 0x221:
            case 0x222:
                cEm00_setState(self, 0, 0x12, 1);
                return;
            /* retail's jump table also lists these enemies, with nothing to do */
            case 0x20B:
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
            case 0x25A:
                break;
            }
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->unk1864 != 0) {
            self->timerB = 0;
        }
        break;
    case 8:
        self->unk1864 = 0;
        self->timerB = 1;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (self->playerDist > 4.0f) {
            recA = RES(0x2B0C);
            recB = RES(0x2B10);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2B14);
            }
            self->timerA = 0x32;
            StoreMotionParamsBoth_2609A8((char *)self, 0x28, 0, 0x37, -1, 0);
        } else if (self->emNo == 0x256 || (irand() & 1)) {
            recA = RES(0x2A50);
            recB = RES(0x2A54);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2A58);
            }
            self->timerA = 0x32;
            StoreMotionParamsBoth_2609A8((char *)self, 0xF, 0, 0x3D, -1, 0);
        } else {
            recA = RES(0x2B58);
            recB = RES(0x2B5C);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2B60);
            }
            self->timerA = 0x32;
            StoreMotionParamsBoth_2609A8((char *)self, 0xF, 0, 0x3D, -1, 0);
        }
        func_002A8578((int)self, recA, recB, 3, 0.0f, sel, 0);
        self->step++;
        /* fallthrough */
    case 9:
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if (self->seqFlags & 0x10) {
            if (self->playerDist < 16.0f && self->playerDist > 6.25f && (irand() & 1)) {
                if (irand() & 1) {
                    cEm00_setState(self, 0, 0x4B, 0);
                } else {
                    cEm00_setState(self, 0, 0x17, 0);
                }
                break;
            }
            if (irand() & 1) {
                cEm00_setState(self, 0, 0x4B, 0);
                return;
            }
            self->step++;
            return;
        }
        break;
    case 10:
        self->unk1864 = 0;
        self->timerB = 1;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (irand() & 1) {
            StoreMotionParams_2609E0((char *)self, 0x1E, 0, 0x37, -1, 0);
            Set_Fields_1884_1894_2609F8((char *)self, 0x1E, 0, 0x37, -1, 0);
            recA = RES(0x2B18);
            recB = RES(0x2B1C);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2B20);
            }
            self->timerA = 0x32;
        } else if (self->emNo == 0x256 || (irand() & 1)) {
            StoreMotionParamsBoth_2609A8((char *)self, 0xF, 0, 0x3D, -1, 0);
            recA = RES(0x2A5C);
            recB = RES(0x2A60);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2A64);
            }
            self->timerA = 0x32;
        } else {
            StoreMotionParamsBoth_2609A8((char *)self, 0xF, 0, 0x3D, -1, 0);
            recA = RES(0x2B64);
            recB = RES(0x2B68);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2B6C);
            }
            self->timerA = 0x32;
        }
        func_002A8578((int)self, recA, recB, 3, 0.0f, sel, 0);
        self->step++;
        /* fallthrough */
    case 11:
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        if ((self->seqFlags & 0x10) && self->playerDist < 16.0f) {
            if (self->playerDist > 6.25f && (irand() & 1)) {
                if ((unsigned int)irand() % 3 == 0) {
                    cEm00_setState(self, 0, 0x4B, 0);
                } else {
                    cEm00_setState(self, 0, 0x17, 0);
                }
            } else {
                self->step++;
            }
        }
        break;
    case 12:
        self->unk1864 = 0;
        self->timerB = 1;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        if (irand() & 1) {
            StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0, 0x3E, -1, 0);
            recA = RES(0x2B34);
            recB = RES(0x2B38);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2B3C);
            }
            self->timerA = 0x32;
        } else {
            StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0, 0x3E, -1, 0);
            recA = RES(0x2A8C);
            recB = RES(0x2A90);
            if (self->emFlags2 & 0x4000000) {
                recB = RES(0x2A94);
            }
            self->timerA = 0x32;
        }
        func_002A8578((int)self, recA, recB, 3, 0.0f, sel, 0);
        self->step++;
        /* fallthrough */
    case 13:
        if (self->timerA != 0) {
            self->timerA--;
            cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * 0.19634955f);
        }
        if (moveMotion(self) != 0) {
            cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
            cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
    switch (self->emNo) {
    case 0x275:
    case 0x276:
        if (self->unk5F8 != 0) {
            if (self->seqFlags & 2) {
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0x26, 0x38, 0, 0xF5);
            }
            if (self->seqFlags & 1) {
                StoreMotionParamsBoth_2609A8((char *)self, 0x1E, 0x27, 0x38, 0, 0xF5);
            }
            if ((self->seqFlags & 3) == 3) {
                StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0x28, 0x38, 0, 0xF5);
            }
        }
        break;
    }
    if (self->timerB != 0) {
        func_00260B30(self);
    }
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(self) == 0 && self->unk1864 == 0
        && (self->seqFlags & 0x10) && func_00262AA8(self) != 0) {
        return;
    }
    if (self->seqFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
