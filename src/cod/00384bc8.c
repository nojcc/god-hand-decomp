/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"
#include "godhand/dbgText.h"

extern char D_0045CD50[];               /* "MUTE[%d]   : %s" */
extern char D_0045CD60[];               /* "MUTE      : %s" */
extern char *D_003F2870[];              /* "OFF", "ON" */

/* Print the mute state of the track the sound page shows, or of the whole
 * stream when no track is picked. ctx is not read. */
__attribute__((section(".text.func_00384BC8")))
void func_00384BC8(int ctx, SlotView *view, SlotInfoA *sub)
{
    if (view->track != 0) {
        func_002E0DE8(3, 0x18, 8, D_0045CD50, view->track - 1,
                      D_003F2870[sub->mute[view->track]]);
    } else {
        func_002E0DE8(3, 0x18, 8, D_0045CD60, D_003F2870[sub->mute[view->track]]);
    }
}
