/* NON_MATCHING cOmWeapon_SetBreak (sn-2.95.3-136, extern_jtbl D_0042A930): 3 words short. In the debris loop retail looks up child i + 1 by first computing a 0/1 "index in range" value and testing it with andi 0xFF (a bool-returning lookup); cOmBase_childAt branches on the two compares instead. Retail also enters the loop at the top (do-while shape) where ours jumps to the test first. The four stores to the collision body are ordered z, owner, x, y in retail. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmWeapon.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"

extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);
extern float fRand0_1(void);
extern float fRand1_1(void);

/* Break the weapon: drop it from its holder, free the collision body, show the broken mesh layer, play the break
 * sound for the weapon kind and launch a debris piece for each child body after the first. */
__attribute__((section(".text.cOmWeapon_SetBreak")))
void cOmWeapon_SetBreak(cOmWeapon *self)
{
    char frame[16];                     /* cOmBase_childAt stores the child count here, a dead store retail keeps */
    cOmBase *body;
    cOmWeaponPiece *piece;
    unsigned int i;

    if (self->parent != 0)
        cVec_copy3(&self->base.posA, self->parent->pos);
    self->base.animRate = 1.0f;
    self->base.objFlags &= ~0x10U;
    self->fallSpeed = 0.091000006f;
    self->parent = 0;
    body = cOmBase_childAt(&self->base, (int *)frame, 0);
    if (body == 0)
        return;
    body->posPrev.z = 0.0f;
    body->owner = &self->base;
    body->posPrev.x = 0.0f;
    body->posPrev.y = 0.0f;
    cModel_calcParts(self);
    self->base.mode = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
    self->base.phase = 0xB;
    cOmBase_setMeshDispFromLayer(self, 0, 0);
    cOmBase_setMeshDispFromLayer(self, 0x40, 1);
    switch (self->base.actorId) {
    case 0x361:
    default:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x115, self, 0, 0, 0, 0);
        break;
    case 0x362: case 0x36D: case 0x375: case 0x377: case 0x378: case 0x3A8:
    case 0x3A9: case 0x3AA: case 0x3AB: case 0x3AD: case 0x3AE: case 0x3B4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x116, self, 0, 0, 0, 0);
        break;
    case 0x363: case 0x380: case 0x3B7:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11D, self, 0, 0, 0, 0);
        break;
    case 0x3AF:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xD4, self, 0, 0, 0, 0);
    case 0x3B8: case 0x3B9: case 0x3BA:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11C, self, 0, 0, 0, 0);
        break;
    }
    for (i = 0; i < COMWEAPON_PIECE_NUM; i++) {
        if (cOmBase_childAt(&self->base, (int *)frame, i + 1) == 0)
            break;
        piece = &self->piece[i];
        piece->vel[0] = fRand1_1() * 0.3f;
        piece->vel[1] = fRand0_1() * 0.6f;
        piece->vel[2] = fRand1_1() * 0.3f;
        piece->rot[0] = fRand1_1() * 0.5235988f;
        piece->rot[1] = fRand1_1() * 0.5235988f;
        piece->rot[2] = fRand1_1() * 0.5235988f;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cOmWeapon_SetBreak);
#endif
