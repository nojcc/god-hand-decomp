/* sn-2.95.3-136 */
#include "godhand/cIDBaseScreen.h"
#include "godhand/gameWork.h"
#include "include_asm.h"

/* NON_MATCHING: 490 of 494 words. Retail keeps the two row colours (0x303030,
 * 0x808080) in registers through the first row loop and spills the texture,
 * attribute and &tbl[0][1] bases to the stack; here the colours load inside the
 * branch and the bases stay in registers. Retail also rebuilds &D_007474A0 for the
 * confirm test, hoists the 1 of `i == 1` in the second loop, and tests the
 * picked attribute with xori/andi. */
#ifdef NON_MATCHING
/* Main phase: scroll the five rows through the list on the pad, ease them into place,
 * and open the picked entry when it is confirmed. */
__attribute__((section(".text.func_00145810")))
void func_00145810(cIDBaseScreen *self)
{
    short i;
    short n;
    int scrolling;

    self->unk2A4 *= 0.7f;
    self->scale *= 0.7f;
    if (self->unk2A4 < 1.0f)
        self->tbl[4][0]->flags |= IDENT_FLAG_CHILD;
    if (D_007474A0.trg & 0x0003010000000000L) {
        self->scale = 1.0f;
        self->unk2A4 = 32.0f;
        self->tbl[4][0]->flags &= ~IDENT_FLAG_CHILD;
        if (++self->cur >= self->listNum)
            self->cur = 0;
    }
    if (self->unk2A4 > 1.0f) {
        self->tbl[0][0]->posX = (self->rowX[4] - self->rowX[0]) * (1.0f - self->scale) + self->rowX[0];
        self->tbl[0][0]->sclX = D_0041E880[0] * self->scale;
        self->tbl[0][0]->sclY = D_0041E880[0] * self->scale;
        n = self->cur - 1;
        if (n < 0)
            n = self->listNum - 1;
    } else {
        self->tbl[0][0]->posX = self->rowX[0];
        self->tbl[0][0]->sclX = D_0041E880[0];
        self->tbl[0][0]->sclY = D_0041E880[0];
        n = self->cur;
    }
    self->tbl[4][0]->posX = (self->rowX[3] - self->rowX[4]) * (1.0f - self->scale) + self->rowX[4];
    self->tbl[4][0]->sclX = D_0041E880[3] * (1.0f - self->scale);
    self->tbl[4][0]->sclY = D_0041E880[3] * (1.0f - self->scale);
    for (i = 0; i < SCR_ROW_NUM; i++) {
        if (i != 0 && i != 4 && self->unk2A4 > 1.0f) {
            self->tbl[i][0]->posX = (self->rowX[i - 1] - self->rowX[i]) * (1.0f - self->scale) + self->rowX[i];
            self->tbl[i][0]->posY = self->rowY[i - 1] + self->unk2A4;
            self->tbl[i][0]->sclX = (D_0041E880[i - 1] - D_0041E880[i]) * (1.0f - self->scale) + D_0041E880[i];
            self->tbl[i][0]->sclY = (D_0041E880[i - 1] - D_0041E880[i]) * (1.0f - self->scale) + D_0041E880[i];
        } else if (i != 0 && i != 4) {
            self->tbl[i][0]->posX = self->rowX[i];
            self->tbl[i][0]->posY = self->rowY[i];
            self->tbl[i][0]->sclX = D_0041E880[i];
            self->tbl[i][0]->sclY = D_0041E880[i];
        }
        self->tbl[i][1]->tex = self->tex[n];
        if (self->attr[n] & SCR_ATTR_DIM)
            self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x303030;
        else
            self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x808080;
        self->tbl[i][4]->seed = self->item2[n];
        scrolling = 0;
        if (self->unk2A4 > 1.0f)
            scrolling = 1;
        if (i == scrolling + 1)
            self->tbl[i][0]->colorBase.word = (self->tbl[i][0]->colorBase.word & 0xFFFFFF) | 0x80000000;
        else
            self->tbl[i][0]->colorBase.word = (self->tbl[i][0]->colorBase.word & 0xFFFFFF) | 0x50000000;
        self->tbl[i][1]->f70[0] = D_0041E840[0][0];
        self->tbl[i][1]->f70[1] = D_0041E840[0][1];
        self->tbl[i][1]->f70[2] = D_0041E840[0][2];
        self->tbl[i][1]->f70[3] = D_0041E840[0][3];
        n++;
        if (n >= self->listNum)
            n = 0;
    }
    if (self->flags & SCR_FLAG_SHOWN) {
        self->step = 0;
        self->phase = 4;
        return;
    }
    n = self->cur + 1;
    if (n >= self->listNum)
        n = 0;
    if (((D_007474A0.language == 0 ? D_007474A0.trg & 0x800000000L : D_007474A0.trg & 0xA00000000L)
         || (self->flags & SCR_FLAG_SETUP)) && !(self->attr[n] & SCR_ATTR_DIM)) {
        {
            self->phase++;
            self->step = 0;
            func_002AC9B8(&self->row[1].id, self->tbl[1][3], 0);
            cIDBase_restartAnim(&self->row[1].id);
            self->tbl[1][3]->flags &= ~IDENT_FLAG_NO_DRAW;
            self->color0 = self->color1 = 0x80808080;
            if (self->unk2A4 > 1.0f) {
                self->tbl[4][0]->flags &= ~IDENT_FLAG_CHILD;
                self->tbl[0][0]->sclX = 1.0f;
                self->tbl[0][0]->sclY = 1.0f;
                n = self->cur;
                for (i = 0; i < SCR_ROW_NUM; i++) {
                    if (i == 1)
                        self->tbl[1][0]->colorBase.word = self->tbl[1][0]->src->colorBase.word;
                    else
                        self->tbl[i][0]->colorBase.word = 0x50808080;
                    self->tbl[i][0]->posX = self->rowX[i];
                    self->tbl[i][0]->posY = self->rowY[i];
                    self->tbl[i][0]->sclX = D_0041E880[i];
                    self->tbl[i][0]->sclY = D_0041E880[i];
                    self->tbl[i][1]->tex = self->tex[n];
                    if (self->attr[n] & SCR_ATTR_DIM)
                        self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x303030;
                    else
                        self->tbl[i][1]->colorBase.word = (self->tbl[i][1]->colorBase.word & 0xFF000000) | 0x808080;
                    self->tbl[i][4]->seed = self->item2[n];
                    self->tbl[i][1]->f70[0] = D_0041E840[0][0];
                    self->tbl[i][1]->f70[1] = D_0041E840[0][1];
                    self->tbl[i][1]->f70[2] = D_0041E840[0][2];
                    self->tbl[i][1]->f70[3] = D_0041E840[0][3];
                    n++;
                    if (n >= self->listNum)
                        n = 0;
                }
            }
            self->tbl[1][1]->f70[0] = D_0041E840[1][0];
            self->tbl[1][1]->f70[1] = D_0041E840[1][1];
            self->tbl[1][1]->f70[2] = D_0041E840[1][2];
            self->tbl[1][1]->f70[3] = D_0041E840[1][3];
            self->scale = 1.0f;
            for (i = 0; i < SCR_ROW_NUM; i++)
                cIDBase_move(&self->row[i].id);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00145810);
#endif
