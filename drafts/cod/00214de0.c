/* sn-2.95.3-136 */
/* NON_MATCHING func_00214DE0 (extern_jtbl D_00436120, D_00436310): 986 vs 983
 * words. Retail loads emNo before masking the motion selector at the top of
 * step 0, keeps case 0x208's idle-action stores apart from the shared
 * set-action-and-return block where ours merges them, and lays out the
 * distance tests of the decision switch differently from case 0x208 on. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cEmManage.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/rand.h"

#define EMMOVE_HIT_FRAME    0x10        /* the motion reached its hit frame */
#define EMMOVE_THROW_FRAME  0x01
#define EM_TURN_RATE        0.19634955f /* pi / 16 per frame at full speed */

#define PICK_MOTION(a, b) { recA = EM_RES_REC(self->resource, a); recB = EM_RES_REC(self->resource, b); }
#define SET_ACTION(ph, arg) { self->mode = 0; self->phase = (ph); self->step = 0; self->stepArg = (arg); }

extern unsigned short D_00747A50;

/* The enemy's step after a guard or a dodge: start the recovery motion for
 * its number, then, once it ends, pick the next attack from the distance to
 * the player and a few random rolls. */
__attribute__((section(".text.func_00214DE0")))
void func_00214DE0(cEm00 *self)
{
    int recA;
    int recB;
    float frame;
    unsigned short sel;
    int end;

    switch (self->step) {
    case 0:
        EmThrower_throwHeld((struct EmThrower *)self, 0, 0);
        EmThrower_throwHeld((struct EmThrower *)self, 1, 0);
        if (self->fx0 != 0) {
            Obj1D00_ClearState_6(&self->fx0->base);
        }
        if (self->fx6 != 0) {
            Obj1D00_ClearState_7(&self->fx6->base);
        }
        frame = 0.0f;
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        self->timer2 = 1.0f;
        switch (self->emNo) {
        default:
            PICK_MOTION(0xEC, 0xF0)
            self->timer2 = 0.6f;
            frame = 5.0f;
            break;
        case 0x213: case 0x217:
            frame = 8.0f;
            PICK_MOTION(0x2F1C, 0x2F20)
            break;
        case 0x242: case 0x243: case 0x244:
            PICK_MOTION(0x35FC, 0x3600)
            self->timer2 = 0.6f;
            frame = 7.0f;
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x25A:
            frame = 3.0f;
            PICK_MOTION(0x10DC, 0x10E0)
            break;
        case 0x252:
            if (Rnd() & 1) {
                PICK_MOTION(0x10DC, 0x10E0)
                self->timer2 = 1.2f;
                frame = 3.0f;
            } else {
                PICK_MOTION(0x10F4, 0x10F8)
                self->timer2 = 1.2f;
                frame = 3.0f;
            }
            break;
        case 0x256:
            if (irand() & 1) {
                recA = EM_RES_REC(self->resource, 0x2B8C);
                recB = EM_RES_REC(self->resource, 0x2B90);
                if (self->emFlags2 & 0x4000000) {
                    recB = EM_RES_REC(self->resource, 0x2B94);
                }
                StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0, 0x37, -1, 0);
                frame = 1.0f;
            } else {
                frame = 2.0f;
                PICK_MOTION(0x25D4, 0x25D8)
            }
            self->timer2 = 1.3f;
            break;
        case 0x27E:
            if (irand() & 1) {
                PICK_MOTION(0x2B8C, 0x2B94)
                StoreMotionParamsBoth_2609A8((char *)self, 0x32, 0, 0x37, -1, 0);
                frame = 1.0f;
            } else {
                frame = 2.0f;
                PICK_MOTION(0x25D4, 0x25D8)
            }
            self->timer2 = 1.3f;
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270: case 0x271:
        case 0x272: case 0x273: case 0x274:
            frame = 6.0f;
            PICK_MOTION(0xD08, 0xD0C)
            break;
        case 0x275: case 0x276:
            PICK_MOTION(0x22B4, 0x22B8)
            break;
        case 0x20A: case 0x20B: case 0x20D: case 0x20E: case 0x218: case 0x245:
        case 0x246: case 0x247:
            PICK_MOTION(0x86C, 0x870)
            self->timer2 = 1.5f;
            break;
        case 0x278: case 0x279:
            PICK_MOTION(0x2004, 0x2008)
            frame = 5.0f;
            if (self->emNo == 0x279) {
                ReleaseField6ECByTag564_26B1E8(self);
            }
            break;
        case 0x20C: case 0x24F:
            PICK_MOTION(0x1EBC, 0x1EC0)
            self->timer2 = 1.5f;
            frame = 7.0f;
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224: case 0x241:
            frame = 4.0f;
            PICK_MOTION(0x15A4, 0x15A8)
            break;
        case 0x209: case 0x21F:
            frame = 4.0f;
            PICK_MOTION(0x15A4, 0x15A8)
            break;
        case 0x250: case 0x251:
            frame = 7.0f;
            PICK_MOTION(0x194C, 0x1950)
            break;
        case 0x260:
            frame = 7.0f;
            PICK_MOTION(0x3078, 0x307C)
            break;
        case 0x264:
            PICK_MOTION(0x326C, 0x3270)
            break;
        case 0x265:
            PICK_MOTION(0x3724, 0x3728)
            break;
        case 0x223:
            PICK_MOTION(0x2D6C, 0x2D70)
            self->timer2 = 1.5f;
            frame = 7.0f;
            break;
        }
        if (self->stepArg != 0) {
            self->timer = frame;
            frame = 0.0f;
            if (self->timer <= 0.0f) {
                self->hitFlash = 15.0f;
            }
        } else {
            self->timer = 0.0f;
            self->hitFlash = 15.0f;
        }
        func_002A8578((int)self, recA, recB, 3, frame, sel | 0x40, 0);
        self->unk16E0 = 0;
        self->step++;
        /* fallthrough */
    case 1:
        cGameObj_SetTgtTurn((char *)self, Getplayer()->pos, self->speedRate * EM_TURN_RATE);
        if (self->timer > 0.0f) {
            self->timer -= self->speedRate;
            if (self->timer <= 0.0f) {
                self->hitFlash = 15.0f;
            }
        }
        end = 0;
        if (moveMotion(self) != 0) {
            end = 1;
        }
        if (func_0026F1D8(self) == 0 && (self->moveFlags & EMMOVE_HIT_FRAME)) {
            end = 1;
        }
        if (end) {
            switch (self->emNo) {
            case 0x200: case 0x201: case 0x202: case 0x203: case 0x204: case 0x216:
            case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B: case 0x23A:
            case 0x23B: case 0x240: case 0x242: case 0x243: case 0x244: case 0x24A:
            case 0x24B: case 0x25B:
                if (self->emNo == 0x228 && self->playerDist > 12.25f) {
                    if (self->emFlags2 & 8) {
                        SET_ACTION(0x10, 0)
                    } else {
                        SET_ACTION(0xF, 0)
                    }
                    break;
                }
                if (irand() & 1) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                func_00262AA8(self);
                break;
            case 0x275: case 0x276:
                if (self->emFlags2 & 0x10000) {
                    SET_ACTION(0x8A, 0)
                    return;
                }
                if ((self->emFlags2 & 0x80) && (irand() & 1)) {
                    SET_ACTION(0x8A, 0)
                    return;
                }
                if ((self->emFlags2 & 0x100) && self->unk1869 > 0 && self->playerDist > 9.0f) {
                    SET_ACTION(0x39, 0)
                    return;
                }
                if ((self->emFlags2 & 0x380) == 0 && self->playerDist > 9.0f && self->unk17A8 >= 0x33) {
                    SET_ACTION(0x3A, 0)
                    return;
                }
                if (self->emFlags2 & 0x10380) {
                    func_00262AA8(self);
                    break;
                }
                if (irand() & 1) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                func_00262AA8(self);
                break;
            case 0x205: case 0x207: case 0x224: case 0x241:
                if (self->playerDist < 9.0f && (irand() & 1) && func_00273960(self, 6.0f)) {
                    return;
                }
                if (self->playerDist > 12.25f && func_00294A78(&D_005864F0) == 0) {
                    D_005864F0.unk541 = 90;
                    switch (irand() & 1) {
                    case 0:
                    default:
                        SET_ACTION(0xC, 0)
                        break;
                    case 1:
                        SET_ACTION(0x11, 0)
                        break;
                    }
                }
                if (self->playerDist < 6.25f && (irand() & 1)) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                if (irand() & 1) {
                    self->unk16DC = 0;
                    self->unk16E0 = 0;
                    if (func_00262AA8(self) == 0) {
                        func_002705D8(self);
                    }
                    break;
                }
                SET_ACTION(0xA, 1)
                break;
            case 0x208:
                if (self->playerDist < 9.0f && self->idleTimer <= 0.0f && (irand() & 3) == 0) {
                    self->phase = 0x2D;
                    self->idleTimer = 300.0f;
                    self->mode = 0;
                    self->step = 0;
                    self->stepArg = 0;
                    return;
                }
                if (self->playerDist < 9.0f && (irand() & 1) && func_00273960(self, 6.0f)) {
                    return;
                }
                if (self->playerDist > 9.0f && self->fx4 != 0 &&
                    Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&self->fx4->base) == 0) {
                    SET_ACTION(0xE, 0)
                    break;
                }
                if (self->playerDist < 6.25f && (irand() & 1) && self->fx4 != 0 &&
                    Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&self->fx4->base) == 0) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                if (irand() & 1) {
                    self->unk16DC = 0;
                    self->unk16E0 = 0;
                    if (func_00262AA8(self) == 0) {
                        func_002705D8(self);
                    }
                    break;
                }
                SET_ACTION(0xA, 1)
                break;
            case 0x21F:
                if (self->idleTimer <= 0.0f && self->playerDist > 9.0f &&
                    (unsigned int)func_002919C0(&D_005864F0, self->actorId, self->emNo) < 2) {
                    SET_ACTION(0x8B, 0)
                    return;
                }
                /* fallthrough */
            case 0x209:
                if (self->playerDist < 25.0f && (irand() & 1)) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                if ((irand() & 1) == 0) {
                    SET_ACTION(0xA, 1)
                    break;
                }
                self->unk16DC = 0;
                self->unk16E0 = 0;
                if (func_00262AA8(self) != 0) {
                    break;
                }
                /* fallthrough */
            default:
                func_002705D8(self);
                break;
            case 0x214: case 0x215:
                if (func_00294970(&D_005864F0) != 0) {
                    if (self->playerDist < 9.0f) {
                        self->stepArg = 1;
                        self->phase = 0xA;
                        self->mode = 0;
                        self->step = 0;
                        return;
                    }
                    if (self->playerDist < 36.0f) {
                        self->stepArg = 1;
                        self->phase = 0x17;
                        self->mode = 0;
                        self->step = 0;
                        return;
                    }
                }
                if (irand() & 1) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                func_00262AA8(self);
                break;
            case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
            case 0x22C: case 0x22D: case 0x22E: case 0x248: case 0x249: case 0x24C:
            case 0x24D: case 0x24E: case 0x252:
                if (irand() & 1) {
                    if (self->fx0 != 0) {
                        if (self->playerDist < 16.0f) {
                            SET_ACTION(0x16, 0)
                            break;
                        }
                    } else if (self->playerDist < 6.25f) {
                        SET_ACTION(0x16, 0)
                        break;
                    }
                }
                if (self->playerDist < 6.25f && (irand() & 1)) {
                    SET_ACTION(0xA, 1)
                    break;
                }
                func_00262AA8(self);
                break;
            case 0x22F:
                if (self->playerDist > 9.0f && self->fx4 != 0 &&
                    Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(&self->fx4->base) == 0) {
                    SET_ACTION(0xE, 0)
                    break;
                }
                if ((irand() & 1) && self->playerDist < (self->fx0 != 0 ? 16.0f : 6.25f)) {
                    SET_ACTION(0x16, 0)
                    break;
                }
                if (self->playerDist < 6.25f && (irand() & 1)) {
                    SET_ACTION(0xA, 1)
                    break;
                }
                func_00262AA8(self);
                break;
            case 0x20B:
                switch ((unsigned int)irand() % 3) {
                case 0:
                default:
                    SET_ACTION(0x1F, 0)
                    return;
                case 1:
                    SET_ACTION(0x1B, 0)
                    return;
                case 2:
                    if (self->playerDist < 6.25f) {
                        SET_ACTION(0x16, 0)
                        return;
                    }
                    SET_ACTION(0x1F, 0)
                    return;
                }
            case 0x256: case 0x27E:
                if (self->playerDist > 25.0f && D_00747A50 == 0x406 && (irand() & 3) == 0) {
                    SET_ACTION(0x6B, 0)
                    return;
                }
                if (self->playerDist < 4.0f) {
                    SET_ACTION(0x16, 0)
                    return;
                }
                if (self->playerDist < 25.0f) {
                    if (self->emNo != 0x27E) {
                        SET_ACTION(0x17, 0)
                        return;
                    }
                    if (irand() & 1) {
                        SET_ACTION(0x11, 0)
                        return;
                    }
                    SET_ACTION(0x17, 0)
                    return;
                }
                break;
            case 0x278:
                if (D_00747A50 == 0x303 && self->playerDist > 9.0f && self->vital < self->vitalMax / 2 &&
                    self->unk1728 <= 0.0f) {
                    SET_ACTION(0x8C, 0)
                    return;
                }
                break;
            case 0x213: case 0x217:
                if (self->playerDist > 9.0f && func_00294A78(&D_005864F0) == 0) {
                    D_005864F0.unk541 = 150;
                    SET_ACTION(0x49, 0)
                    return;
                }
                break;
            case 0x250:
                if (self->playerDist > 9.0f) {
                    if (irand() & 1) {
                        SET_ACTION(0x20, 0)
                        return;
                    }
                    SET_ACTION(0x19, 0)
                    return;
                }
                break;
            case 0x251:
                if (self->playerDist > 9.0f) {
                    switch ((unsigned int)irand() % 3) {
                    case 0:
                    default:
                        SET_ACTION(0x20, 0)
                        return;
                    case 1:
                        SET_ACTION(0x19, 0)
                        return;
                    case 2:
                        SET_ACTION(0x23, 1)
                        return;
                    }
                }
                break;
            case 0x260:
                switch (irand() & 3) {
                case 0:
                default:
                    SET_ACTION(0x16, 0)
                    return;
                case 1:
                    SET_ACTION(0x23, 0)
                    return;
                case 2:
                    SET_ACTION(0x1A, 0)
                    return;
                case 3:
                    SET_ACTION(0x22, 0)
                    return;
                }
            }
            func_002705D8(self);
            return;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, self->timer2);
        break;
    }
    switch (self->emNo) {
    case 0x20F:
        if (self->unk1714 <= 0.0f && (self->moveFlags & EMMOVE_THROW_FRAME)) {
            func_0026A638(self, 0);
            EmThrower_throwHeld((struct EmThrower *)self, 0, 0);
        }
        break;
    case 0x256:
    case 0x27E:
        func_00260B30(self);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00214DE0);
#endif
