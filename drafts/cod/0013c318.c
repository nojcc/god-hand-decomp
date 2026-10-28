/* NON_MATCHING func_0013C318 (sn-2.95.3-136): show/hide the four sub-parts from the req bits.
* Retail
 * re-tests the hidden bit with a plain mask on the else-if path (no jump threading) and reloads part->flags in parts 1-3;
* the mask form gets threaded here and the shift form (used below) gives srl/andi instead. */
#include "include_asm.h"
#include "godhand/cIDBase.h"

#ifdef NON_MATCHING
typedef struct SubPart {
    char pad00[0x2C];
    unsigned int flags;                 /* 0x2C bit 27 = hidden */
} SubPart;

typedef struct SubPartOwner {
    char pad00[0x94];
    int req;                            /* 0x94 bits 31..28 = hide part 0..3 */
    SubPart *part[4];                /* 0x98 */
} SubPartOwner;


__attribute__((section(".text.func_0013C318")))
void func_0013C318(SubPartOwner *o)
{
    SubPart *p;

    p = o->part[0];
    if ((p->flags & 0x8000000) && (o->req & 0x80000000))
        p->flags &= ~0x8000000;
    else if (!((p->flags >> 27) & 1) && !((o->req >> 31) & 1))
        p->flags |= 0x8000000;
    p = o->part[1];
    if ((p->flags & 0x8000000) && (o->req & 0x40000000))
        p->flags &= ~0x8000000;
    else if (!((p->flags >> 27) & 1) && !((o->req >> 30) & 1))
        p->flags |= 0x8000000;
    p = o->part[2];
    if ((p->flags & 0x8000000) && (o->req & 0x20000000))
        p->flags &= ~0x8000000;
    else if (!((p->flags >> 27) & 1) && !((o->req >> 29) & 1))
        p->flags |= 0x8000000;
    p = o->part[3];
    if ((p->flags & 0x8000000) && (o->req & 0x10000000))
        p->flags &= ~0x8000000;
    else if (!((p->flags >> 27) & 1) && !((o->req >> 28) & 1))
        p->flags |= 0x8000000;
    o->req &= ~0x80000000;
    o->req &= ~0x40000000;
    o->req &= ~0x20000000;
    o->req &= ~0x10000000;
    cIDBase_move(o);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0013C318);
#endif
