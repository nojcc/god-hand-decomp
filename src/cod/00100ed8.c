/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cloth.h"
#include "godhand/cOmBase.h"


/* sn-2.95.3-136 matched TU. */





/* Hangs the costume cloth from child idx of parent; the cloth kind follows the costume. */
__attribute__((section(".text.pl01__SetParent")))
void pl01__SetParent(pl01 *self, cGameObj *parent, int idx)
{
    int frame[3];
    cOmBase *part;
    cOmBase *at;
    int kind;

    if (parent == 0) {
        return;
    }
    part = cOmBase_childAt((cOmBase *)self, frame, 0);
    if (part == 0) {
        return;
    }
    at = cOmBase_childAtIdx((cOmBase *)parent, frame, idx);
    if (at == 0) {
        return;
    }
    part->parent = (struct cParts *)at;
    self->linkChild = idx;
    self->link = parent;
    self->work.parent = parent;
    switch (cCoreSave_getCostumeNo(&D_00569B70)) {
    case 2:
    case 3:
        kind = 0xB;
        break;
    case 4:
    case 5:
        kind = 7;
        break;
    case 0:
    case 1:
    case 6:
    case 7:
    default:
        kind = 0xC;
        break;
    }
    self->work.kind = kind;
}
