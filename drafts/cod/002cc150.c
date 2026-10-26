/* sn-2.95.3-136 */
/* NON_MATCHING cSnd_UpdateListener: matches byte for byte, but needs VU0_LQC2_SQC2_MEM, VU0_ZERO_VSUB_XYZ_TO, which vu0.h doesn't have.
 * Waiting on LucasPicoli (progress/decisions_needed.md, "vu0.h macros"). */
#include "include_asm.h"
#include "../vu0_pending.h"
/* sn-2.95.3-136 */
#include "godhand/cSnd.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define LISTEN_AT_CAMERA  0
#define LISTEN_AT_PLAYER  1
#define LISTEN_BETWEEN    2

typedef int u_long128 __attribute__((mode(TI)));

extern int D_00747A84;
extern void func_0030A548(void *dst, void *src);
extern void sceVu0CameraMatrix(void *dst, void *a1, void *a2, void *a3);
extern void sceVu0AddVector(void *a0, void *a1, void *a2);
extern void sceVu0ScaleVectorXYZ(void *a0, void *a1, float s);

/* Set m to the identity matrix. */
static __inline__ void unitMatrix(float m[4][4])
{
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
}

/* out = (a - b) in x, y and z with w cleared; returns out. */
static __inline__ cVec *subVecXYZ(cVec *out, cVec *a, cVec *b)
{
    VU0_ZERO_VSUB_XYZ_TO(out, 0, a, b);
    return out;
}

#ifdef NON_MATCHING
/* Place the sound listener for this frame: at the camera, just behind the
 * player's head looking at the player, or halfway between the two. */
__attribute__((section(".text.cSnd_UpdateListener")))
void cSnd_UpdateListener(cSnd *self)
{
    unsigned long flags = D_00747A84;
    cGameObj *pl;
    int mode;
    cVecQuad ear;
    cVec eye;
    float m[4][4];
    cVec at;
    cVec dir;
    cVec diff;
    cVec d;
    cVec up;

    if (flags & 0x20000000) {
        self->f110 = LISTEN_AT_CAMERA;
    } else if (flags & 0x80000) {
        self->f110 = LISTEN_AT_CAMERA;
    } else if (((flags >> 6) & 1) == 1) {
        self->f110 = LISTEN_AT_CAMERA;
    } else {
        self->f110 = LISTEN_AT_PLAYER;
    }
    pl = Getplayer();
    mode = self->f110;
    if (pl == 0) {
        mode = LISTEN_AT_CAMERA;
    }
    switch (mode) {
    case LISTEN_AT_CAMERA:
        *(u_long128 *)&self->listenPos = *(u_long128 *)&D_005CAFF0->target;
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    case LISTEN_AT_PLAYER:
        ear.x = 0.0f;
        ear.y = 1.5f;
        ear.z = -0.1f;
        ear.w = 1.0f;
        sceVu0ApplyMatrix(&ear, pl->mtx, &ear);
        self->listenPos = ear;
        eye.x = ear.x;
        eye.y = ear.y;
        eye.z = ear.z;
        eye.w = 1.0f;
        VU0_LQC2_SQC2_MEM(4, &at, pl->pos);
        at.y += 1.5f;
        VU0_SQC2_VF0_MEM(&dir, 0);
        unitMatrix(m);
        sceVu0ApplyMatrix(&eye, m, &eye);
        sceVu0ApplyMatrix(&dir, m, &at);
        VU0_LQC2_SQC2_MEM(4, &diff, subVecXYZ(&d, &dir, &ear));
        d.x = diff.x;
        d.y = diff.y;
        d.z = diff.z;
        d.w = 1.0f;
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        up.w = 1.0f;
        sceVu0CameraMatrix(self->listenMtx, &eye, &d, &up);
        break;
    case LISTEN_BETWEEN:
        sceVu0AddVector(&self->listenPos, &D_005CAFF0->target, pl->pos);
        sceVu0ScaleVectorXYZ(&self->listenPos, &self->listenPos, 0.5f);
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cSnd_UpdateListener);
#endif
