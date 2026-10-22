/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 161 words against retail's 152. Retail tests the three
 * listener-off flag bits in separate branches (the third with dsrl), where
 * gcc merges the first two into one mask. Retail copies the camera target
 * into listenPos with lq/sq, so listenPos is a cVec there; here it is
 * float[4] and the copy is unaligned.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSnd.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define LISTEN_AT_CAMERA  0
#define LISTEN_AT_PLAYER  1
#define LISTEN_BETWEEN    2

extern int D_00747A84;
extern void func_0030A548(float *dst, float *src);
extern void sceVu0CameraMatrix(void *dst, void *eye, void *dir, void *up);
extern void sceVu0AddVector(void *dst, void *a, void *b);
extern void sceVu0ScaleVectorXYZ(void *dst, void *src, float s);

/* Place the sound listener for this frame: at the camera, just behind the
 * player's head looking at the player, or halfway between the two. */
__attribute__((section(".text.cSnd_UpdateListener")))
void cSnd_UpdateListener(cSnd *self)
{
    int flags = D_00747A84;
    cGameObj *pl;
    cVec ear;
    cVec eye;
    float m[4][4];
    cVec at;
    cVec dir;
    cVec diff;
    cVec d;
    cVec up;

    if ((flags & 0x20000000) || (flags & 0x80000) || ((flags >> 6) & 1)) {
        self->f110 = LISTEN_AT_CAMERA;
    } else {
        self->f110 = LISTEN_AT_PLAYER;
    }
    pl = Getplayer();
    switch (pl != 0 ? self->f110 : LISTEN_AT_CAMERA) {
    case LISTEN_AT_CAMERA:
        *(cVec *)self->listenPos = D_005CAFF0->target;
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    case LISTEN_AT_PLAYER:
        ear.x = 0.0f;
        ear.y = 1.5f;
        ear.z = -0.1f;
        ear.w = 1.0f;
        sceVu0ApplyMatrix(&ear, pl->mtx, &ear);
        *(cVec *)self->listenPos = ear;
        eye.x = ear.x;
        eye.y = ear.y;
        eye.z = ear.z;
        eye.w = 1.0f;
        VU0_LQC2_SQC2_MEM(4, &at, pl->pos);
        at.y += 1.5f;
        VU0_SQC2_VF0_MEM(&dir, 0);
        VU0_VMOVE_XYZW(4, 0);
        VU0_VMR32_XYZW(5, 4);
        VU0_VMR32_XYZW(6, 5);
        VU0_VMR32_XYZW(7, 6);
        VU0_SQC2(4, m, 0x30);
        VU0_SQC2(5, m, 0x20);
        VU0_SQC2(6, m, 0x10);
        VU0_SQC2(7, m, 0x0);
        sceVu0ApplyMatrix(&eye, m, &eye);
        sceVu0ApplyMatrix(&dir, m, &at);
        VU0_ZERO_VSUB_XYZ_MEM(&d, 0, &dir, &ear);
        VU0_LQC2_SQC2_MEM(4, &diff, &d);
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
        sceVu0AddVector(self->listenPos, &D_005CAFF0->target, pl->pos);
        sceVu0ScaleVectorXYZ(self->listenPos, self->listenPos, 0.5f);
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cSnd_UpdateListener);
#endif
