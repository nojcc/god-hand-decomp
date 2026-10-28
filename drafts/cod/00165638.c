/* sn-2.95.3-136 */
#include "godhand/cSubScrMenu.h"
#include "godhand/cCoreSave.h"
#include "godhand/cWorldTime.h"
#include "godhand/cRecordIndex.h"
#include "godhand/cScrSpriteDraw.h"
#include "include_asm.h"
#include "godhand/cIDBase.h"

/* NON_MATCHING: retail keeps &D_00569B70 in one register for all three calls
 * in the stage loop; here the event-flag call rebuilds it from the high half
 * kept since the start, which renumbers the stage loop's registers. Retail
 * also pads only the first div.s (after the branch join) and leaves the
 * second bare. Builds with the SN assembler and the fdiv pad. */
#ifdef NON_MATCHING

#define STATUS_OPTION_NUM  5            /* option entries ent[0..4] */
#define STATUS_REEL_NUM    0x1F
#define STATUS_MSG_OPTION  0x2000       /* message of option n is this + n */
#define STATUS_MSG_STAGE   0x2005       /* message of stage n is this + n */

extern short D_003BD9D8[];              /* cursor y of each option */

/* The glow follows the picture's fade: alpha of ent[23], scaled to 64,
 * on top of the glow's own alpha. */
static __inline__ void cSubScrMenu_setGlow(cSubScrMenu *self)
{
    cIDBaseEnt *glow = self->ent[29];

    glow->colorBase.c[3] = (int)((float)self->ent[23]->colorBase.c[3] * 0.0078125f * 64.0f
                                 + (float)glow->src->colorBase.c[3]);
}

/* Each frame of the status screen: cursor, gold, play time, reels, kill
 * counts and rank, the list of open stages, and the stage picture change. */
__attribute__((section(".text.func_00165638")))
void func_00165638(cSubScrMenu *self)
{
    unsigned short i;
    unsigned int n;
    unsigned int reels;
    unsigned int kills;
    unsigned int h;
    unsigned int m;
    unsigned int s;
    unsigned int stageIdx;

    self->ent[5]->posY = (float)D_003BD9D8[self->obj.state];
    for (i = 0; i < STATUS_OPTION_NUM; i++) {
        self->ent[i]->flags |= IDENT_FLAG_NO_DRAW;
    }
    self->ent[self->obj.state]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[6]->seed = cCoreSave_getGold(&D_00569B70);
    self->ent[16]->msg = self->obj.state + STATUS_MSG_OPTION;
    self->ent[17]->msg = self->obj.state + STATUS_MSG_OPTION;
    cWorldTime_getGlobalHMS(&D_0061A990, (unsigned int *)&self->ent[13]->seed,
                            (unsigned int *)&self->ent[14]->seed, (unsigned int *)&self->ent[15]->seed);
    if (self->ent[13]->seed > 100) {
        self->ent[13]->seed = 99;
        self->ent[14]->seed = 59;
        self->ent[15]->seed = 59;
    }

    reels = 0;
    for (n = 0; n < STATUS_REEL_NUM; n++) {
        if (cCoreSave_ckGodReel(&D_00569B70, n)) {
            reels++;
        }
    }
    self->ent[11]->seed = reels - 2;
    self->ent[12]->seed = 0x1D;
    self->ent[25]->seed = cCoreSave_getKillEmNum(&D_00569B70, 1);
    self->ent[26]->seed = cCoreSave_getKillEmNum(&D_00569B70, 2);
    self->ent[27]->seed = cCoreSave_getKillEmNum(&D_00569B70, 3);
    self->ent[28]->seed = cCoreSave_getKillEmNum(&D_00569B70, 5);
    kills = cCoreSave_getKillEmNum(&D_00569B70, 1) + cCoreSave_getKillEmNum(&D_00569B70, 2)
          + cCoreSave_getKillEmNum(&D_00569B70, 3) + cCoreSave_getKillEmNum(&D_00569B70, 5);
    self->ent[7]->seed = func_0031ED08(((float)cCoreSave_getKillEmNum(&D_00569B70, 1)
                                         + (float)cCoreSave_getKillEmNum(&D_00569B70, 2) * 2.0f
                                         + (float)cCoreSave_getKillEmNum(&D_00569B70, 3) * 3.0f
                                         + (float)cCoreSave_getKillEmNum(&D_00569B70, 5) * 5.0f)
                                        / (float)kills * 10.0f);
    self->ent[9]->seed = D_005FEC58.limit;
    self->ent[10]->seed = 0x72;
    self->stageNum = 0;
    cWorldTime_getStageHMS(&D_0061A990, &h, &m, &s);

    self->ent[21]->flags &= ~IDENT_FLAG_NO_DRAW;
    self->ent[30]->flags |= IDENT_FLAG_NO_DRAW;
    for (stageIdx = 0; stageIdx < SUBSCR_MENU_STAGE_NUM; stageIdx++) {
        unsigned short stage = D_0041F718[stageIdx].stage;

        if (cCoreSave_ckClearStage(&D_00569B70, (unsigned short)(stage - 1)) == 0 && stage != 1) {
            continue;
        }
        if (cCoreSave_ckClearStage(&D_00569B70, D_0041F718[stageIdx].stage) == 0 && m < D_0041F718[stageIdx].limit && h == 0) {
            continue;
        }
        self->stageNum++;
        if (cCoreSave_ckEventFlag(&D_00569B70, stageIdx) == 0) {
            self->ent[30]->flags &= ~IDENT_FLAG_NO_DRAW;
        }
    }
    if (self->stageNum == 0) {
        self->ent[21]->flags |= IDENT_FLAG_NO_DRAW;
    }
    if (self->stageSel == 0 || self->stageShown == 0) {
        self->ent[18]->flags |= IDENT_FLAG_NO_DRAW;
    } else {
        self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
    }

    if (self->stageSel != self->stageShown || self->obj.step != 0) {
        switch (self->obj.step) {
        case 0:
            self->flags |= 1;
            self->ent[23]->colorBase.c[3] = 0;
            self->obj.step++;
        case 1:
            self->ent[23]->colorBase.c[3] += 0x30;
            self->ent[23]->flags &= ~IDENT_FLAG_NO_DRAW;
            if (self->stageSel == 0) {
                self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
            }
            if (self->ent[23]->colorBase.c[3] > 0x80) {
                self->ent[23]->colorBase.c[3] = 0x80;
                self->obj.step++;
            }
            cSubScrMenu_setGlow(self);
            break;
        case 2:
            self->ent[18]->flags |= IDENT_FLAG_NO_DRAW;
            if (self->stageSel == 0) {
                self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
            }
            if (self->wait == 0) {
                self->obj.step++;
            }
            break;
        case 3:
            self->flags |= 2;
            func_002AC9B8(&self->obj.base, self->ent[21], 0);
            if (self->stageSel != 0) {
                if (self->stageShown == 0) {
                    self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
                }
                FileHolder_reload(self, D_0041F718[self->stageSel - 1].file);
                self->ent[18]->tex = self->data;
            }
            self->obj.step++;
        case 4:
            self->ent[23]->flags &= ~IDENT_FLAG_NO_DRAW;
            if (self->stageShown == 0) {
                self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
            }
            if (self->ent[23]->colorBase.c[3] - 0x20 < 0) {
                self->ent[23]->colorBase.c[3] = 0;
                self->obj.step++;
            } else {
                self->ent[23]->colorBase.c[3] -= 0x20;
            }
            cSubScrMenu_setGlow(self);
            break;
        case 5:
            if (self->stageShown == 0) {
                self->ent[18]->flags &= ~IDENT_FLAG_NO_DRAW;
            }
            self->ent[23]->flags |= IDENT_FLAG_NO_DRAW;
            cCoreSave_setEventFlag(&D_00569B70, self->stageSel);
            self->ent[23]->colorBase.c[3] = 0;
            self->obj.step = 0;
            self->stageShown = self->stageSel;
            self->flags &= ~3;
            break;
        }
        if (self->stageSel == self->stageShown && self->stageSel == 0) {
            self->ent[18]->flags |= IDENT_FLAG_NO_DRAW;
        }
    }

    if (--self->wait < 0) {
        self->wait = 0;
    }
    self->ent[19]->seed = self->stageSel;
    self->ent[22]->msg = self->stageSel + STATUS_MSG_STAGE;
    self->ent[20]->rotSpeed = (float)self->stageSel / ((float)self->stageNum + 1.0f) * 6.2870002f;
    func_001661A0(self);
    cIDBase_move(&self->obj.base);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00165638);
#endif
