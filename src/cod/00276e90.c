/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmLinked.h"
#include "godhand/cOmBase.h"

/* Runs the push step on the enemy's model. */
__attribute__((section(".text.func_0027A748")))
void func_0027A748(cEmLinked *self)
{
    func_00104010(self, &self->work, &self->base.unk5B0);
}

/* Runs the push step on the enemy's model. */
__attribute__((section(".text.func_0027B240")))
void func_0027B240(cEmLinked *self)
{
    func_00104010(self, &self->work, &self->base.unk5B0);
}

/* Runs the push step on the enemy's model. */
__attribute__((section(".text.func_002844A0")))
void func_002844A0(cEmLinked *self)
{
    func_00104010(self, &self->work, &self->base.unk5B0);
}

/* Hangs the enemy's first child from child idx of parent and links the enemy
 * to parent with step kind `kind`; does nothing when either child is missing. */
static __inline__ void cEmLinked_setParent(cEmLinked *self, cGameObj *parent, int idx, int kind)
{
    int frame[3];
    cOmBase *part;
    cOmBase *at;

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
    self->work.kind = kind;
}

/* Hangs cEm12 from child idx of parent. */
__attribute__((section(".text.cEm12_SetParent")))
void cEm12_SetParent(cEmLinked *self, cGameObj *parent, int idx)
{
    cEmLinked_setParent(self, parent, idx, 8);
}

/* Hangs cEm53 from child idx of parent. */
__attribute__((section(".text.cEm53_SetParent")))
void cEm53_SetParent(cEmLinked *self, cGameObj *parent, int idx)
{
    cEmLinked_setParent(self, parent, idx, 0xB);
}

/* Hangs cEm57 from child idx of parent. */
__attribute__((section(".text.cEm57_SetParent")))
void cEm57_SetParent(cEmLinked *self, cGameObj *parent, int idx)
{
    cEmLinked_setParent(self, parent, idx, 0xB);
}

/* Hangs the enemy from child idx of parent. */
__attribute__((section(".text.func_00283BE8")))
void func_00283BE8(cEmLinked *self, cGameObj *parent, int idx)
{
    cEmLinked_setParent(self, parent, idx, 4);
}

/* Hangs the enemy from child idx of parent. */
__attribute__((section(".text.func_002844C0")))
void func_002844C0(cEmLinked *self, cGameObj *parent, int idx)
{
    cEmLinked_setParent(self, parent, idx, 0xC);
}
