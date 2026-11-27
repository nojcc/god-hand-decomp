/* sn-2.95.3-136 matched TU. */

#include "godhand/cSubScrShopMain.h"
#include "godhand/cIDBaseFn.h"
#include "godhand/cIDManager.h"
#include "godhand/cSubScr.h"
#include "godhand/sysFlags.h"
#include "godhand/player.h"
#include "godhand/cWorldLight.h"
#include "godhand/cVec.h"

extern cIDManager **D_003C2384;
extern cWorldLight D_00604700;
extern char D_0041FCD0[];               /* "idskillshop" */

/* Opens the skill shop's main screen: loads its id resource the first time,
 * resets the three displays and their entries, takes the sub screen camera
 * and puts it at the player, saves and clears the player's rot, sets the
 * system flags for the screen and resets the world light. */
__attribute__((section(".text.func_00168560")))
void func_00168560(cSubScrShopMain *self)
{
    int i;

    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(&self->obj);
    if (func_00161500(&self->obj, D_0041FCD0) != 0) {
        cIDManager_setIDData(*D_003C2384, 10, self->obj.resHandle);
        cIDBase_initialize(&self->obj.base, 10, 1);
        cIDBase_setPackedMessData(&self->obj.base, 10, 3);
        cIDBase_initialize(&self->idBaseB, 10, 2);
        cIDBase_initialize(&self->idBaseC, 10, 4);
        cIDBase_resetAnim(&self->idBaseC);
        cIDBase_restartAnim(&self->obj.base);
        cIDBase_restartAnim(&self->idBaseB);
        self->obj.result = 7;
    }
    self->obj.base.mode = 0;
    self->idBaseC.mode = 6;
    for (i = 0; i < SUBSCR_SHOP_ENT_NUM; i++) {
        self->ent[i] = cIDBase_getIDWork(&self->obj.base, i);
    }
    {
        /* Walked by pointer: indexing this loop as well is 6 words off. */
        cIDBaseEnt **ent = self->entB;

        for (i = 0; i < SUBSCR_SHOP_ENTB_NUM; i++) {
            *ent++ = cIDBase_getIDWork(&self->idBaseB, i);
        }
    }
    switch (D_003BD930->mode) {
    case 0:
        self->ent[0]->flags |= IDENT_FLAG_NO_DRAW;
        break;
    case 1:
        self->ent[1]->flags |= IDENT_FLAG_NO_DRAW;
        break;
    }
    self->entB[0]->posX = self->entB[0]->src->posX - 350.0f;
    self->ent[3]->msg = 0x2000;
    self->ent[4]->msg = 0x2000;
    self->unk1B4 = 0;
    self->unk1D2 = 0;
    self->unk1D0 = 0;
    self->obj.state = 0;
    self->obj.step = 0;
    self->obj.unk5C = 0;
    self->obj.unk5D = 0;
    self->ent[6]->msg = 0x2003;
    self->ent[8]->msg = 0x2004;
    self->ent[7]->msg = 0x2003;
    self->ent[9]->msg = 0x2004;
    self->unk1D4 = 0;
    for (i = 0; i < 5; i++) {
        self->unk260[i] = 0;
        self->unk26C[i] = 0;
    }
    self->unk282 = 0;
    self->player = Getplayer();
    self->jacket = GetJacket();
    cCamManager_setSubScrCamera(&D_00463050, 0);
    self->camera = &D_00463050.subScr;
    cVec_copy3(&self->target, &self->player->rot);
    {
        cVec zero;

        CVEC_INIT_XYZ(zero, 0.0f, 0.0f, 0.0f);
        CVEC_ASSIGN_VEC(self->player->rot, zero);
    }
    /* pos in its own block: declared at the top of the function it is 109 words off. */
    {
        cVec pos __attribute__((aligned(16)));

        CVEC_COPY(pos, self->player->pos);
        {
            cVec res __attribute__((aligned(16)));
            cVec ofs;
            cVec sum __attribute__((aligned(16)));

            CVEC_INIT_XYZ(ofs, -1.42412f, 1.15232f, 1.27033f);
            CVEC_COPY(sum, &pos);
            CVEC_ADD_TO(sum, &ofs);
            CVEC_COPY(res, &sum);
            CVEC_ASSIGN_ARG(self->camera->target, res);
        }
        {
            cVec res __attribute__((aligned(16)));
            cVec ofs;
            cVec sum __attribute__((aligned(16)));
            struct cCamera *cam;

            CVEC_INIT_XYZ(ofs, 2.49258f, 0.35f, 6.215f);
            /* Bound after ofs: no cam local is 63 words off, cam set at the
             * top of the block 6. */
            cam = self->camera;
            CVEC_COPY(sum, &cam->target);
            CVEC_ADD_TO(sum, &ofs);
            CVEC_COPY(res, &sum);
            CVEC_ASSIGN_ARG(cam->eye, res);
        }
    }
    D_00747A78.f80 |= 0x08000000;
    D_00747A78.f80 |= 0x04000000;
    D_00747A78.f80 |= 0x40000000;
    D_00747A78.f80 |= 0x10000000;
    D_00747A78.f80 |= 0x02000000;
    D_00747A78.f78 &= 0x7FFFFFFF;
    D_00747A78.f80 |= 0x40000000;
    D_00747A78.f80 |= 0x20000000;
    D_00747A78.f80 |= 0x10000000;
    D_00747A78.f80 |= 0x00800000;
    func_002D9778(&D_00604700);
    self->unk286 = 0;
    self->obj.state = 0;
    self->obj.step = 0;
    self->obj.unk5C = 0;
    self->obj.unk5D = 0;
}
