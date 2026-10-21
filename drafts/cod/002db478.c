/* sn-2.95.3-136. Differs from retail: retail keeps the actor-id range test as a byte bool (slt/xori against 0x300 held in a register, then andi 0xFF) and reloads D_00754C58 every iteration; ours folds the range into one sltiu and keeps the list pointer. 0x2FD is the object's layer byte (no cOmBase field yet). */
#ifdef NON_MATCHING
#include "godhand/cMc.h"
#include "godhand/cOmBase.h"

#define OM_LAYER_HIDE 0x2U

extern cMcObjList *D_00754C58;

/* Shows (on != 0) or hides every layered object on the given layer. */
__attribute__((section(".text.displayOmLayer")))
void displayOmLayer(int layer, int on)
{
    cMcObj **p;
    cOmBase *om;
    unsigned char isLayer;

    for (p = D_00754C58->begin; p != D_00754C58->end; p++) {
        om = (cOmBase *)*p;
        isLayer = om->actorId >= 0x300 && om->actorId < 0x500;
        if (isLayer && *((unsigned char *)om + 0x2FD) == layer) {
            if (on) {
                om->objFlags &= ~OM_LAYER_HIDE;
            } else {
                om->objFlags |= OM_LAYER_HIDE;
            }
        }
    }
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", displayOmLayer);
#endif
