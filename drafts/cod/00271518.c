/* NON_MATCHING func_00271518 (sn-2.95.3-136): stack layout and the first enemy number switch differ. Retail keeps the matrix and both child count stores at sp+0 in a 0xC0 frame with three saved registers; ours gives them separate slots (0xE0, four saved). Retail tests 0x264 first and then 0x260 or 0x265 as single values; ours groups 0x264..0x265 as a range. */
/* sn-2.95.3-136 */
#include "include_asm.h"
#include "../vu0_pending.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/sceVu0.h"
#include "godhand/player.h"

extern float fRand1_1(void);
extern float capVu0Atan2(float x, float z);
extern void MtxInitRotY(void *a0, float angle);

/* cOmBase.h does not name 0x20 of the hit record yet: where the hit landed. */
#define TAKE_HITPOS(take) ((cVec *)((char *)(take) + 0x20))

/* Pick the point the enemy aims its grab at: where the last hit landed, moved out in front of the enemy with
 * some jitter (a smaller jitter in place for enemies 0x260, 0x264, 0x265 and 0x26A), or its child 4 when
 * nothing hit it. Throws (hit kinds 0x21 and 0x2B) aim at the player's child 20 instead. */
__attribute__((section(".text.func_00271518")))
void func_00271518(cEm00 *self, cVec *out)
{
    cGameObj *player;
    float height;

    player = Getplayer();
    switch (self->emNo) {
    case 0x260:
    case 0x264:
    case 0x265:
        height = 0.8f;
        break;
    default:
        height = 0.4f;
        break;
    }
    if (self->unk698 == 0) {
        char frame[16]; /* cOmBase_childAt stores the child count here, a dead store retail keeps */

        cVec_copy3(out, cOmBase_childAt((cOmBase *)self, (int *)frame, 4)->pos);
    } else {
        cVec ofs;
        cVec hit;
        cVec diff;

        cVec_zero(&ofs);
        VU0_LQC2_SQC2_MEM(4, &hit, TAKE_HITPOS(self->unk698));
        cVec_copy3(out, &hit);
        switch (self->emNo) {
        case 0x260:
        case 0x264:
        case 0x265:
        case 0x26A:
            out->x += fRand1_1() * 0.1f;
            out->y += fRand1_1() * 0.1f;
            out->z += fRand1_1() * 0.1f;
            break;
        default: {
            float mtx[16] __attribute__((aligned(16)));

            VU0_ZERO_VSUB_XYZ_MEM(&diff, 0, out, self->pos);
            VU0_LQC2_SQC2_MEM(4, &hit, &diff);
            cVec_copy3(&ofs, &hit);
            MtxInitRotY(mtx, capVu0Atan2(ofs.x, ofs.z));
            ofs.x = fRand1_1() * 0.2f;
            ofs.y = fRand1_1() * 0.2f;
            ofs.z = height + fRand1_1() * 0.1f;
            cVec_applyMatrix(&ofs, mtx);
            out->x = self->pos->x + ofs.x;
            out->z = self->pos->z + ofs.z;
            break;
        }
        }
    }
    if (((cDamageTake *)self->unk698)->kind == 0x21 || ((cDamageTake *)self->unk698)->kind == 0x2B) {
        char frame[16]; /* cOmBase_childAt stores the child count here, a dead store retail keeps */

        cVec_copy3(out, cOmBase_childAt((cOmBase *)player, (int *)frame, 20)->pos);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00271518);
#endif
