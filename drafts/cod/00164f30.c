/* sn-2.95.3-136 */
/* NON_MATCHING func_00164F30 (sn-2.95.3-136, as sn): 424 vs 425 words. Retail pads
 * the second div.s (the heat maximum over 150) with two nops and leaves the first
 * (hp over hpMax, right after its cvt.s.w) bare; no fp_hazard_rules value pads one
 * and not the other. Everything else matches. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSubScrMenu.h"
#include "godhand/cIDManager.h"
#include "godhand/cCoreSave.h"
#include "godhand/cHeatSys.h"
#include "godhand/cRecordIndex.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"
#include "godhand/cIDBase.h"

extern char D_0041F6A0[];               /* "idsubscrmenu" */
extern int func_002C8EF8(void *self);

#define SUBSCR_MENU_RES     4           /* manager slot and resource of the menu */

/* Open the menu: load its id resource, build the four displays and their
 * entry tables, then show the difficulty, the gauges and the items held. */
__attribute__((section(".text.func_00164F30")))
void func_00164F30(cSubScrMenu *self)
{
    int i;
    unsigned short lv;
    cGameObj *pl;
    unsigned int godNum;

    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(&self->obj);
    cIDBase_initialize(&self->items, 1, 0xC);
    cIDBase_restartAnim(&self->items);
    if (func_00161500(&self->obj, D_0041F6A0) != 0) {
        cIDManager_setIDData(*D_003C2384, SUBSCR_MENU_RES, self->obj.resHandle);
        cIDBase_initialize(&self->obj.base, SUBSCR_MENU_RES, 0);
        cIDBase_initialize(&self->status, SUBSCR_MENU_RES, 1);
        cIDBase_initialize(&self->level, SUBSCR_MENU_RES, 2);
        cIDBase_setPackedMessData(&self->obj.base, SUBSCR_MENU_RES, 3);
        cIDBase_restartAnim(&self->obj.base);
        cIDBase_play(&self->status);
        cIDBase_play(&self->level);
        self->obj.result = 0;
    }
    for (i = 0; i < SUBSCR_MENU_ENT_NUM; i++) {
        self->ent[i] = cIDBase_getIDWork(&self->obj.base, i);
    }
    for (i = 0; i < SUBSCR_MENU_STATUS_NUM; i++) {
        cIDBase_initIDWork(&self->status, i);
        self->statusEnt[i] = cIDBase_getIDWork(&self->status, i);
    }
    for (i = 0; i < SUBSCR_MENU_ITEM_NUM; i++) {
        cIDBase_initIDWork(&self->items, i);
        self->itemEnt[i] = cIDBase_getIDWork(&self->items, i);
    }
    for (i = 0; i < SUBSCR_MENU_LEVEL_NUM; i++) {
        cIDBase_initIDWork(&self->level, i);
        self->levelEnt[i] = cIDBase_getIDWork(&self->level, i);
    }

    self->statusEnt[1]->flags |= IDENT_FLAG_NO_DRAW;
    self->statusEnt[2]->flags |= IDENT_FLAG_NO_DRAW;
    self->statusEnt[3]->flags |= IDENT_FLAG_NO_DRAW;
    self->statusEnt[4]->flags |= IDENT_FLAG_NO_DRAW;
    lv = cCoreSave_getGameLevel(&D_00569B70);
    if (lv == 4) {
        lv = 3;
    } else if (lv == 5) {
        lv = 4;
    }
    lv = lv - 1;
    pl = Getplayer();
    self->statusEnt[lv + 1]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->statusEnt[6]->sclX = (float)pl->hp / (float)pl->hpMax;
    self->statusEnt[7]->sclX = cHeatSys_GetHeatRatio(&D_005CB000);
    if (D_005CB000.mode != 0) {
        self->statusEnt[8]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->statusEnt[8]->sclX = self->statusEnt[7]->sclX;
    } else {
        cIDBaseEnt *heat = self->statusEnt[7];
        if (heat->sclX > 0.9999f) {
            self->statusEnt[8]->flags &= ~IDENT_FLAG_NO_DRAW;
        } else if (D_005CB000.cur >= 240.0f) {
            heat->colorBase.word = 0x80808080;
        } else if (D_005CB000.cur >= 120.0f) {
            heat->colorBase.word = 0x804E6060;
        } else {
            heat->colorBase.word = 0x80744042;
        }
    }

    self->levelEnt[2]->flags |= IDENT_FLAG_NO_DRAW;
    self->levelEnt[3]->flags |= IDENT_FLAG_NO_DRAW;
    self->levelEnt[4]->flags |= IDENT_FLAG_NO_DRAW;
    if (lv == 3) {
        self->levelEnt[1]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->levelEnt[5]->flags |= IDENT_FLAG_NO_DRAW;
        if (self->statusEnt[6]->sclX < 0.8f) {
            self->levelEnt[2]->flags &= ~IDENT_FLAG_NO_DRAW;
        }
        if (self->statusEnt[6]->sclX < 0.5f) {
            self->levelEnt[3]->flags &= ~IDENT_FLAG_NO_DRAW;
        }
        if (self->statusEnt[6]->sclX < 0.25f) {
            self->levelEnt[4]->flags &= ~IDENT_FLAG_NO_DRAW;
        }
    } else {
        self->levelEnt[5]->seed = lv + 1;
        self->levelEnt[5]->flags &= ~IDENT_FLAG_NO_DRAW;
        self->levelEnt[1]->flags |= IDENT_FLAG_NO_DRAW;
    }

    godNum = cCoreSave_getGodItemNum(&D_00569B70);
    for (i = 0; i < 6; i++) {
        if (i < (int)godNum) {
            self->itemEnt[i]->flags &= ~IDENT_FLAG_NO_DRAW;
        } else {
            self->itemEnt[i]->flags |= IDENT_FLAG_NO_DRAW;
        }
        if (i < cCoreSave_getReelItem(&D_00569B70)) {
            self->itemEnt[i + 7]->flags &= ~IDENT_FLAG_NO_DRAW;
        } else {
            self->itemEnt[i + 7]->flags |= IDENT_FLAG_NO_DRAW;
        }
    }
    self->statusEnt[0]->posY -= 60.0f;
    self->itemEnt[6]->posY -= 60.0f;
    self->levelEnt[0]->posY -= 60.0f;
    self->statusEnt[5]->sclX = ((float)cCoreSave_getVitalMax(&D_00569B70) - 100.0f) / 260.0f * 2.6f + 1.0f;
    self->statusEnt[9]->sclX = (D_005CB000.max - 120.0f) / 150.0f * 1.25f + 1.0f;
    self->data = 0;
    FileHolder_reload(self, D_0041F718[0].file);
    self->flags = 0;
    self->stageSel = 0;
    self->stageShown = 0;
    self->ent[0x16]->msg = 0x2005;
    self->ent[0x13]->seed = 0;
    GAMEWORK_AT(flags5E0) |= 0x04000000;
    GAMEWORK_AT(flags5E0) |= 0x02000000;
    GAMEWORK_AT(flags5E0) |= 0x40000000;
    GAMEWORK_AT(flags5E0) |= 0x80000000;
    GAMEWORK_AT(flags5E0) |= 0x00200000;
    GAMEWORK_AT(flags5E0) |= 0x20000000;
    GAMEWORK_AT(flags5E0) |= 0x10000000;
    GAMEWORK_AT(flags5E0) |= 0x08000000;
    func_002C8EF8(&D_005FEC58);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00164F30);
#endif
