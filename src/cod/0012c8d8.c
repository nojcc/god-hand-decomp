/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmWeapon.h"
#include "godhand/cCoreSave.h"
#include "godhand/cVecType.h"
#include "godhand/vecInline.h"
#include "godhand/pl00.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

/* Give the player the paper (object 0x376) when its hand is empty: mark it in the save, create it
 * at the player's position, unturned, and attach it to hand 2 with the costume's grip offset. */
__attribute__((section(".text.pl00_setPaper")))
void pl00_setPaper(pl00 *self) {
    cVec grip[2];
    cCoreSave *w;
    cGameObj *obj;

    if (self->weapon == 0) {
        w = &D_00569B70;
        cCoreSave_setPaper(w);
        obj = CreateObj(0x376, 0xFFFF);
        self->weapon = (cOmWeapon *)obj;
        if (obj != 0) {
            cGameObj_vt(obj)->initial((char *)obj + cGameObj_vt(obj)->initialDelta);
            cVec_copy3(self->weapon->base.pos, self->base.pos);
            cVec_copy3(&self->weapon->base.posA, self->base.pos);
            vec3_set(&self->weapon->base.rot.x, 0.0f, 0.0f, 0.0f);
            VU0_SQC2_VF0(grip, 0x0);
            VU0_SQC2_VF0(grip, 0x10);
            grip[0].x = 0.0f;
            grip[0].y = 0.047f;
            grip[0].z = -0.14f;
            switch (cCoreSave_getCostumeNo(w)) {
            case 0:
            case 1:
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                grip[0].z = -0.155f;
                break;
            case 6:
            case 7:
                break;
            }
            grip[1].x = 0.0f;
            grip[1].y = 0.0f;
            grip[1].z = 0.0f;
            cOmWeapon_setParent(self->weapon, (cOmBase *)self, 2, &grip[0], &grip[1]);
        }
    }
}
