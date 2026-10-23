/* NON_MATCHING func_00269B50 (sn-2.95.3-136): every instruction matches retail except at the child lookups. Retail copies each looked-up child from $v0 into $a0 before the null test (all sites but the last one, which uses $v1 as ours does), so ours is 0x30 bytes shorter. EmTwistPart stands in for cParts until cModel.h names the float at 0x150. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cOmBase.h"
#include "godhand/cCamera.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* View of cParts with the twist angle at 0x150 that cModel.h does not name yet. */
typedef struct EmTwistPart {
    char unk000[0xF0];
    cVec *pos;                          /* 0x0F0 */
    char unk0F4[0x150 - 0xF4];
    float twist;                        /* 0x150 */
    int partFlags;                      /* 0x154 */
} EmTwistPart;

#define CPARTS_TWIST 0x800

typedef struct EmTwistFrame {
    cVec target;
    int childNum;
} EmTwistFrame;

extern float Turn_dest(float *from, float *to, float cur, float max);
extern float Turn_dest_dir(float now, float dest, float spd);

#define TWIST_PART(self, f, idx, angle) { \
    EmTwistPart *p = (EmTwistPart *)cOmBase_childAt((cOmBase *)(self), &(f).childNum, (idx)); \
    if (p != 0) { p->partFlags |= CPARTS_TWIST; p->twist = (angle); } }

/* Turns an enemy's upper body toward the player and spreads the twist over its spine parts. */
__attribute__((section(".text.func_00269B50")))
void func_00269B50(cEm00 *self)
{
    EmTwistFrame f;
    EmTwistPart *head;
    float spd;
    float dest;

    VU0_SQC2_VF0_MEM(&f.target, 0);
    switch (self->emNo) {
    case 0x264:
    case 0x265:
        return;
    }
    cVec_copy3(&f.target, self->pos);
    spd = 0.19634955f;
    if (self->emNo == 0x26A) {
        head = (EmTwistPart *)cOmBase_childAt((cOmBase *)self, &f.childNum, 0x10);
        if (head != 0) {
            cVec_copy3(&f.target, head->pos);
        }
        spd = 0.012271847f;
    }
    if (self->emFlags & 0x400) {
        dest = Turn_dest((float *)&f.target, (float *)Getplayer()->pos, self->rot.y, 1.0471976f);
    } else {
        dest = 0.0f;
    }
    self->unk16F4 += Turn_dest_dir(self->unk16F4, dest, spd * self->speedRate);
    self->unk16F4 = Adjust_theta(self->unk16F4);
    if (self->emFlags2 < 0) {
        self->unk16F4 = 0.0f;
    }
    switch (self->emNo) {
    default:
        TWIST_PART(self, f, 3, self->unk16F4 * 0.5f);
        TWIST_PART(self, f, 4, self->unk16F4 * 0.5f);
        TWIST_PART(self, f, 0x1A, 0.0f);
        if (self->emNo == 0x256 || self->emNo == 0x27E) {
            TWIST_PART(self, f, 0x1D, 0.0f);
            TWIST_PART(self, f, 0x1E, 0.0f);
            TWIST_PART(self, f, 0x1F, 0.0f);
            TWIST_PART(self, f, 0x20, 0.0f);
            TWIST_PART(self, f, 0x21, 0.0f);
            TWIST_PART(self, f, 0x22, 0.0f);
        }
        break;
    case 0x223:
        TWIST_PART(self, f, 5, self->unk16F4 * 0.5f);
        TWIST_PART(self, f, 6, self->unk16F4 * 0.5f);
        break;
    case 0x26A:
        TWIST_PART(self, f, 0x10, self->unk16F4);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00269B50);
#endif
