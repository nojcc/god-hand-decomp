/* sn-2.95.3-136 */
#include "godhand/cCockTutorial.h"
#include "godhand/cIDBaseFn.h"

/* Tutorial panel steps: grow the frame to its full size and show the message, fill in the page for the
 * message, shrink the frame away, then forget the message. */
__attribute__((section(".text.func_001471F0")))
void func_001471F0(cCockTutorial *self) {
    char st;

    if (self->data != 0) {
        st = self->unkB8 - 1;
        switch (st) {
        case 0:
            cIDBase_restartAnim(&self->base);
            self->base.playing = 1;
            self->unkB8 = 2;
        case 1:
            self->ent[0]->sclX = self->ent[0]->sclX + 0.1f;
            self->ent[0]->sclY = self->ent[0]->sclY + 0.1f;
            if (self->ent[0]->src->sclX < self->ent[0]->sclX) {
                self->ent[0]->sclX = self->ent[0]->src->sclX;
                self->ent[0]->sclY = self->ent[0]->src->sclY;
                self->ent[1]->msg = self->curMsg;
                self->ent[2]->msg = self->curMsg;
                self->unkB8 = 3;
            }
            break;
        case 2:
            self->ent[1]->flags = self->ent[1]->flags & ~IDENT_FLAG_NO_DRAW;
            self->ent[2]->flags = self->ent[2]->flags & ~IDENT_FLAG_NO_DRAW;
            switch (self->curMsg) {
            case 0x2000:
                self->ent[3]->msg = 0x2006;
                self->ent[4]->msg = 0x2006;
                self->ent[5]->flags = self->ent[5]->flags & ~IDENT_FLAG_NO_DRAW;
                break;
            case 0x2001:
                self->ent[3]->msg = 0x2007;
                self->ent[4]->msg = 0x2007;
                break;
            case 0x2002:
                self->ent[3]->msg = 0x2008;
                self->ent[4]->msg = 0x2008;
                break;
            case 0x2003:
                self->ent[3]->msg = 0x2009;
                self->ent[4]->msg = 0x2009;
                break;
            case 0x2004:
                self->ent[3]->msg = 0x200A;
                self->ent[4]->msg = 0x200A;
                self->ent[6]->flags = self->ent[6]->flags & ~IDENT_FLAG_NO_DRAW;
                break;
            case 0x2005:
                self->ent[3]->msg = 0x200B;
                self->ent[4]->msg = 0x200B;
                break;
            }
            break;
        case 3:
            self->ent[1]->flags = self->ent[1]->flags | IDENT_FLAG_NO_DRAW;
            self->ent[2]->flags = self->ent[2]->flags | IDENT_FLAG_NO_DRAW;
            self->ent[0]->sclX = self->ent[0]->sclX - 0.1f;
            self->ent[0]->sclY = self->ent[0]->sclY - 0.1f;
            if (self->ent[0]->sclX < 0.0f) {
                self->ent[0]->sclX = 0.0f;
                self->ent[0]->sclY = 0.0f;
                self->unkB8 = 5;
            }
            break;
        case 4:
            self->unkB8 = 0;
            self->curMsg = COCKTUT_MSG_NONE;
            break;
        }
        cIDBase_move(&self->base);
    }
}
