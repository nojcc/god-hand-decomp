/* sn-2.95.3-136 matched TU. */
#include "godhand/Slot1.h"
#include "godhand/scrollLayer.h"

typedef struct { int w[15]; } Tbl15;
extern Tbl15 D_0042B890;

#define SCROLL_ROW_NUM    5
#define SCROLL_ROW_SHIFT  11
#define SCROLL_ARMED      0x8000
#define SCROLL_ON         0x4000
#define SCROLL_LAYER      11       /* scrollLayer[] index shown with every row */

/* Store row sel of table D_0042B890 in scroll (armed when arm is set), then show or hide that row's three layers and layer 11. */
__attribute__((section(".text.func_001E3E40")))
void func_001E3E40(Slot1 *self, unsigned short sel, int show, int arm)
{
    int tbl[5][3];

    *(Tbl15 *)tbl = D_0042B890;
    if (sel < SCROLL_ROW_NUM) {
        self->scroll = sel << SCROLL_ROW_SHIFT;
        if (arm != 0)
            self->scroll |= SCROLL_ARMED;
        if (show != 0) {
            self->scroll |= SCROLL_ON;
            displayScrollLayer(self->scrollLayer[tbl[sel][0]], 1);
            displayScrollLayer(self->scrollLayer[tbl[sel][1]], 1);
            displayScrollLayer(self->scrollLayer[tbl[sel][2]], 1);
            displayScrollLayer(self->scrollLayer[SCROLL_LAYER], 1);
        } else {
            displayScrollLayer(self->scrollLayer[tbl[sel][0]], 0);
            displayScrollLayer(self->scrollLayer[tbl[sel][1]], 0);
            displayScrollLayer(self->scrollLayer[tbl[sel][2]], 0);
            displayScrollLayer(self->scrollLayer[SCROLL_LAYER], 0);
        }
    }
}
