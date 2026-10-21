/* sn-2.95.3-136 */
/* NON_MATCHING: needs --fp-hazard-rules fdiv; retail tests D_00747A84 bit 6 with a 64-bit dsrl (only a long temporary gives that) and tests the 0x20000000/0x40000000 bits separately where this C merges them; 128 instructions differ. */
#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
#define GAMEOBJ_FADE  0x10              /* objFlags: drawn faded by animRate */
#define SYS_NO_FADE_A 0x20000000
#define SYS_NO_FADE_B 0x40000000

extern unsigned int D_00747A84;
extern char D_00463050[];               /* the camera manager; its first camera is the player camera */

/* Fade the object out while it stands between the camera and the player:
 * animRate becomes the fade (cubed distance past 2.0) and objFlags bit 0x10 marks it. */
__attribute__((section(".text.func_002A87E8")))
void func_002A87E8(cGameObj *self, cVec *ref)
{
    cVec eye;
    cGameObj *player;
    float camDist;
    float refDist;
    float fade;

    if (!(D_00747A84 & SYS_NO_FADE_A) && !(D_00747A84 & SYS_NO_FADE_B)
        && !((D_00747A84 >> 6) & 1)) {
        player = Getplayer();
        VU0_SQC2_VF0(&eye, 0);
        if (D_005CAFF0 == 0) {
            return;
        }
        if (ref == 0) {
            ref = self->pos;
        }
        cVec_copy3(&eye, &D_005CAFF0->target);
        camDist = __builtin_sqrtf((eye.x - player->pos->x) * (eye.x - player->pos->x)
                                  + (eye.z - player->pos->z) * (eye.z - player->pos->z));
        refDist = __builtin_sqrtf((eye.x - ref->x) * (eye.x - ref->x)
                                  + (eye.z - ref->z) * (eye.z - ref->z));
        fade = refDist - 2.0f;
        fade = fade * (fade * fade);
        if (cGameObj_idInRange(self, 0x200, 0x300) & 0xFF) {
            if (ref->y + 1.7f < eye.y) {
                fade = 1.0f;
            }
            if (D_005CAFF0 != (struct cCamera *)D_00463050) {
                fade = 1.0f;
            }
        }
        if (!(camDist <= refDist) && !(fade >= 1.0f)) {
            if (fade < 0.15f) {
                self->animRate = 0.0f;
                self->objFlags &= ~GAMEOBJ_FADE;
            } else {
                self->animRate = fade;
                self->objFlags |= GAMEOBJ_FADE;
            }
            return;
        }
    }
    self->objFlags &= ~GAMEOBJ_FADE;
    self->animRate = 1.0f;
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_002A87E8);
#endif
