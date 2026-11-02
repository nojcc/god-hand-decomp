/* sn-2.95.3-136 */
#include "godhand/idPair.h"
#include "godhand/cMessDrawFontCode.h"

#define IDPAIR_TOP       (-50.0f)       /* entry 0's start and exit position */

/* The queued message the banner shows, a short at 0xBEE in the message bank. D_003C23A4 is
 * declared as the int handle the cMessage_* calls take (cMessDrawFontCode.h) and cMessage
 * stops at 0xBDA, so there is no field to name; main's 00162c98.c and 001630e8.c write
 * this short through the same offset. */
#define MESS_BANNER_MSG(bank) (*(unsigned short *)((bank) + 0xBEE))

/* func_00146A18: the banner step. Slide entry 0 down, grow entry 1, show the
 * queued message for 90 frames, shrink entry 1 and move entry 0 out, then pop
 * both queues and start again. */
__attribute__((section(".text.func_00146A18")))
void func_00146A18(IdPair *self)
{
    unsigned short i;
    unsigned int j;
    float low;

    if (self->state[0] != 0 && self->state[0] != 6) {
        if (self->altQueue[0] == 0) {
            for (i = 0; i < IDPAIR_WORK_NUM; i++)
                self->work[i] = cIDBase_getIDWork(&self->base, i);
        } else {
            for (i = 0; i < IDPAIR_WORK_NUM; i++)
                self->work[i] = cIDBase_getIDWork(&self->part2, i);
        }
    }
    low = 0.0f;
    if (self->flags & IDPAIR_FLAG_LOW)
        low = 50.0f;
    self->flags &= ~IDPAIR_FLAG_LOW;
    switch (self->state[0]) {
    case 0:
        if (self->count != 0)
            self->state[0]++;
        break;
    case 1:
        self->work[0]->posY += 10.0f;
        self->work[0]->rotSpeed = (1.0f - (self->work[0]->src->posY - self->work[0]->posY)
                                   / (self->work[0]->src->posY - IDPAIR_TOP)) * 9.424776f;
        if (self->work[0]->src->posY + low < self->work[0]->posY) {
            self->work[0]->rotSpeed = 0.0f;
            self->work[0]->posY = self->work[0]->src->posY + low;
            self->state[0]++;
        }
        break;
    case 2:
        self->work[1]->sclX += 0.3f;
        self->work[1]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (self->work[1]->sclX > 1.3f) {
            self->work[1]->sclX = 1.3f;
            self->timer = IDPAIR_SHOW_TIME;
            self->state[0]++;
        }
        break;
    case 3:
        MESS_BANNER_MSG(D_003C23A4) = self->msgQueue[0];
        self->work[2]->msg = 0x30F0;
        self->work[2]->flags &= ~IDENT_FLAG_NO_DRAW;
        if (--self->timer < 0) {
            self->work[2]->flags |= IDENT_FLAG_NO_DRAW;
            self->state[0]++;
        }
        break;
    case 4:
        self->work[1]->sclX -= 0.3f;
        if (self->work[1]->sclX < 0.0f) {
            self->work[1]->flags |= IDENT_FLAG_NO_DRAW;
            self->work[1]->sclX = 0.0f;
            self->state[0]++;
        }
        break;
    case 5:
        self->work[0]->posX -= 10.0f;
        if (self->work[0]->posX < IDPAIR_TOP) {
            self->work[0]->posY = IDPAIR_TOP;
            self->state[0]++;
        }
        break;
    case 6:
        for (j = 0; j < self->count - 1; j++) {
            self->msgQueue[j] = self->msgQueue[j + 1];
            self->altQueue[j] = self->altQueue[j + 1];
        }
        self->msgQueue[self->count - 1] = 0;
        self->altQueue[self->count - 1] = 0;
        self->count--;
        IdPair_init(self);
        self->state[0] = 0;
        break;
    }
    if (self->state[0] != 0 && self->state[0] != 6) {
        if (self->altQueue[0] == 0) {
            self->work[3]->msg = 0x30F1;
            cIDBase_move(&self->base);
        } else {
            self->work[3]->msg = 0x30C5;
            cIDBase_move(&self->part2);
        }
    }
}
