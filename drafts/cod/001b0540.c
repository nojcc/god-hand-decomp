/* sn-2.95.3-136, fp_hazard_rules sqrt */
/* func_001B0540. Retail tests falling == 0 && rolling == 1 with one 64-bit
 * load of 0x620..0x627 and a mask; this C merges the two byte tests into one
 * lhu at 0x624 (bitfields give the same). The bytes may sit in an 8-byte
 * record at 0x620. 52 instructions differ, all from that test on. */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/sceVu0.h"

#ifdef NON_MATCHING
/* The rolling object func_001B0980 starts; no header type yet. */
typedef struct RollObj {
    cGameObj base;
    char unk5B0[0x600 - 0x5B0];
    void *damage;                       /* 0x600 damage unit, 0 if none */
    char unk604[0x610 - 0x604];
    cVec vel;                           /* 0x610 */
    char unk620[2];
    short smokeWait;                    /* 0x622 frames to the next dust puff */
    unsigned char falling;              /* 0x624 thrown, not yet landed */
    unsigned char rolling;              /* 0x625 */
} RollObj;

extern float capVu0LengthSq(void *a0);
extern float sqrtf(float x);
extern int ChkCollScrWall(void *a0, void *a1, int a2, void *a3, int t0, int t1, float f12);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);

/* Moves the object by its velocity until it stops rolling: friction, gravity,
 * wall and floor contact, the landing sounds, and a dust puff every 10 frames
 * while it rolls on the ground. */
__attribute__((section(".text.func_001B0540")))
void func_001B0540(RollObj *self)
{
    cVec flat;
    cVec hit;
    float k;

    VU0_LQC2_SQC2_MEM(4, &flat, &self->vel);
    flat.y = 0.0f;
    if (__builtin_sqrtf(capVu0LengthSq(&flat)) < 0.03f)
        self->rolling = 0;
    if (self->rolling == 1 || self->falling == 1) {
        VU0_VADD_XYZ_IP(self->base.pos, 0, &self->vel);
        k = 0.7f;
        if (self->falling == 1)
            k = 0.95f;
        VU0_VSCALE_XYZ_MEM(&self->vel, 0, k);
    }
    self->vel.y += -0.02f;
    cVec_zero(&hit);
    if (ChkCollScrWall(self, &hit, 0, 0, 0, 0, 2.2f) != 0) {
        self->base.pos->x = hit.x;
        self->base.pos->z = hit.z;
    }
    cVec_zero(&hit);
    if (func_001329C0(self, &hit, 0, 0, 10.0f) != 0) {
        if (self->falling == 1) {
            if (self->base.pos->y < hit.y) {
                self->vel.x *= 0.5f;
                self->vel.z *= 0.5f;
                self->falling = 0;
                self->smokeWait = 0;
                if (self->damage != 0)
                    cDamageUnit_SetDamageCollActive(self->damage, 1);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 2, 0x91, -1, -1, 0, 0);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 2, 0x92, -1, -1, 0, 0);
            }
        } else {
            self->base.pos->y = hit.y - 0.0f;
        }
    }
    if (self->falling == 0 && self->rolling == 1) {
        self->base.pos->y += (float)(D_007474A0.frame & 1U) * 0.01f;
        if (self->smokeWait > 0) {
            self->smokeWait--;
        } else {
            SetEffect(1, 1, self, 0, -1, (void *)-1);
            self->smokeWait = 10;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001B0540);
#endif
