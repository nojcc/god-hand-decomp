/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/rand.h"

#define EMFLAG_DOWN             0x20000
#define EMFLAG1644_STAY_DOWN    0x800000
#define EMMOVE_FACE_FLAG        0x200       /* picks the first motion pair of a set */
#define EMMOVE_DOWN_FLAG        0x8

/* Picks the motion pair at off (face flag set) or off + 8 into motA/motB.
 * A macro: several enemies pass the same pair for both. */
#define EM_PICK_MOTION(self, on, off)                                   \
    {                                                                   \
        if ((self)->moveFlags & EMMOVE_FACE_FLAG) {                     \
            motA = EM_RES_REC((self)->resource, (on));                  \
            motB = EM_RES_REC((self)->resource, (on) + 4);              \
        } else {                                                        \
            motA = EM_RES_REC((self)->resource, (off));                 \
            motB = EM_RES_REC((self)->resource, (off) + 4);             \
        }                                                               \
    }

/* NON_MATCHING: 8 instructions differ, all v0/v1 swaps: the 0x2F7 test at
 * 0x2598D0 and the 0x16D0/0x434 update at 0x2599C8. */

#ifdef NON_MATCHING
/* Knockdown phase machine: pick the enemy's fall motion and sound, lie with
 * the solid off (sliding to a stop when stepArg is set), then stay down for
 * 75 frames or get up. */
__attribute__((section(".text.func_00259548")))
void func_00259548(cEm00 *self)
{
    int motA;
    int motB;
    unsigned short sel;
    float slide;

    switch (self->step) {
    case 0:
        if (func_002740D8((char *)self) != 0) {
            if (irand() & 1) {
                self->unk17C3 = 1;
            } else {
                self->unk17C3 = 0;
            }
        }
        sel = Obj0000_Get_Byte_17C3_NZ_2_276468(self);
        switch (self->emNo) {
        default:
            EM_PICK_MOTION(self, 0x608, 0x610);
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
            EM_PICK_MOTION(self, 0xB1C, 0xB24);
            break;
        case 0x250:
        case 0x251:
            EM_PICK_MOTION(self, 0xB1C, 0xB24);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)(GetSeqSEBase((int *)self) + 0x23), self, 0, 0, 0, 0);
            break;
        case 0x260:
            EM_PICK_MOTION(self, 0xB1C, 0xB24);
            break;
        case 0x264:
            EM_PICK_MOTION(self, 0x326C, 0x326C);
            break;
        case 0x265:
            EM_PICK_MOTION(self, 0x3818, 0x3818);
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        case 0x241:
            EM_PICK_MOTION(self, 0x1798, 0x17A0);
            break;
        case 0x209:
        case 0x21F:
            EM_PICK_MOTION(self, 0x1798, 0x17A0);
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
            EM_PICK_MOTION(self, 0xF44, 0xF4C);
            break;
        case 0x220:
        case 0x221:
        case 0x222:
            EM_PICK_MOTION(self, 0x608, 0x610);
            break;
        case 0x223:
            if (self->moveFlags & EMMOVE_DOWN_FLAG) {
                EM_PICK_MOTION(self, 0x2E74, 0x2E74);
            } else {
                motA = EM_RES_REC(self->resource, 0x2E6C);
                motB = EM_RES_REC(self->resource, 0x2E70);
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
            EM_PICK_MOTION(self, 0x1370, 0x1378);
            break;
        }
        func_002A8578((int)self, motA, motB, 3, 0.0f, sel, 0);
        self->unk1866++;
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, (short)GetSeqSEBase((int *)self), self, 0, 0, 0, 0);
        self->step++;
        /* fallthrough */
    case 1:
        cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
        if (self->stepArg != 0) {
            cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
            slide = self->unk114 - 0.3f;
            self->emFlags |= EMFLAG_DOWN;
            self->hitFlash = 3.0f;
            self->unk114 = slide;
            if (slide <= 0.3f) {
                self->unk114 = 0.3f;
            }
        }
        self->unk434 |= 8;
        if (moveMotion(self) != 0) {
            if (self->vital <= 0) {
                if (self->stepArg != 0) {
                    self->step = 2;
                } else if (self->flags1644 & EMFLAG1644_STAY_DOWN) {
                    self->mode = 2;
                    self->phase = 3;
                    self->step = 0;
                    self->stepArg = 0;
                } else {
                    func_0025FE30(self, 0x1000000, 0);
                    self->mode = 2;
                    self->phase = 2;
                    self->step = 0;
                    self->stepArg = 0;
                }
            } else {
                func_00274FE8(self);
            }
        }
        break;
    case 2:
        self->timer = 75.0f;
        self->step++;
        /* fallthrough */
    case 3:
        cCollisionSolidManage_SetActive((int)D_00462FC0, (int)self, 0);
        self->emFlags |= EMFLAG_DOWN;
        self->hitFlash = 3.0f;
        self->unk434 |= 8;
        moveMotion(self);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            if (self->flags1644 & EMFLAG1644_STAY_DOWN) {
                self->mode = 2;
                self->phase = 3;
                self->step = 0;
                self->stepArg = 0;
            } else {
                func_0025FE30(self, 0x1000000, 0);
                self->mode = 2;
                self->phase = 2;
                self->step = 0;
                self->stepArg = 0;
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00259548);
#endif
