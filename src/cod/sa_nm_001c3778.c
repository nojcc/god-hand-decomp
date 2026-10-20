/* func_001C3778 / func_001C3988 (SN, 528 B): clear then set the local/parent matrix-skip bits on
 * child parts 1..n around cModel_calcParts.: retail range check compares idx against a
 * register zero (no movn) and reads flags0 as lwu+dsra. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cModel.h"
#include "godhand/cOmBase.h"

extern void func_001B7E50(void *self);
extern void cModel_calcParts(void *self, int arg);

typedef struct OmParts {
    cOmBase base;
    char unk5E0[0x2C];
    signed char partLimit;              /* 0x60C */
} OmParts;

static __inline__ cParts *partAt(cOmBase *b, int *frame, int idx)
{
    unsigned char ok;
    int n;

    *frame = n = b->childNum;
    ok = 0;
    if (idx >= 0)
        ok = idx < n;
    if (ok)
        return (cParts *)b->children[idx];
    return 0;
}

__attribute__((section(".text.func_001C3778")))
void func_001C3778(OmParts *self)
{
    int frame[4];
    int i;

    func_001B7E50(self);
    if ((((long)(unsigned int)self->base.flags0 >> 1) & 1) == 0) {
        for (i = 1; i < self->partLimit && i < self->base.childNum; i++) {
            partAt(&self->base, frame, i)->partFlags &= ~CPARTS_NO_LOCAL;
            partAt(&self->base, frame, i)->partFlags &= ~CPARTS_NO_PARENT;
        }
        cModel_calcParts(self, i);
        for (i = 1; i < self->partLimit && i < self->base.childNum; i++) {
            partAt(&self->base, frame, i)->partFlags |= CPARTS_NO_LOCAL;
            partAt(&self->base, frame, i)->partFlags |= CPARTS_NO_PARENT;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_001C3778);
#endif
