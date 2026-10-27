/* sn-2.95.3-136 */
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cSubScrMenu.h"
#include "godhand/menuKey.h"

#define MENU_SE_PAGE        0x164

#define SUBSCR_MENU_ROWS    5

/* Input step of the sub-screen menu: up and down move through the five rows,
 * the page keys step through the open stages, OK answers the row and back closes it. */
__attribute__((section(".text.func_00165EB8")))
void func_00165EB8(cSubScrMenu *self)
{
    if (D_007474A0.rep & MENU_KEY_UP) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
        if (--self->obj.state < 0) {
            self->obj.state = SUBSCR_MENU_ROWS - 1;
        }
    }
    if (D_007474A0.rep & MENU_KEY_DOWN) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_MOVE, -1, -1, 0, 0);
        if (++self->obj.state >= SUBSCR_MENU_ROWS) {
            self->obj.state = 0;
        }
    }
    if ((D_007474A0.rep & MENU_KEY_PAGE_NEXT) && !(self->flags & SUBSCR_MENU_NOPAGE)) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_PAGE, -1, -1, 0, 0);
        self->flags &= ~SUBSCR_MENU_NOPAGE;
        self->wait = 10;
        self->stageSel++;
    } else if ((D_007474A0.rep & MENU_KEY_PAGE_PREV) && !(self->flags & SUBSCR_MENU_NOPAGE)) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_PAGE, -1, -1, 0, 0);
        self->flags &= ~SUBSCR_MENU_NOPAGE;
        self->wait = 10;
        self->stageSel--;
    }
    self->stageSel = self->stageSel < 0 ? self->stageNum
               : self->stageSel > self->stageNum ? 0 : self->stageSel;
    /* retail tests this bit as (flags ^ bit) & bit: !(flags & bit) changes the code */
    if ((D_007474A0.trg & MENU_KEY_OK) && ((self->flags ^ SUBSCR_MENU_NOOK) & SUBSCR_MENU_NOOK)) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_OK, -1, -1, 0, 0);
        switch (self->obj.state) {
        case 0:
            self->obj.result = 1;
            break;
        case 1:
            self->obj.result = 2;
            break;
        case 2:
            self->obj.result = 3;
            break;
        case 3:
            self->obj.result = 4;
            break;
        default:
            self->obj.result = -1;
            break;
        }
    }
    if (D_007474A0.trg & (MENU_KEY_BACK | MENU_KEY_CLOSE)) {
        cSnd_SeCall_2CB8A0(&D_005FEE00, 0, MENU_SE_BACK, -1, -1, 0, 0);
        self->obj.result = -1;
    }
}
