/* include/godhand/effectPos.h - SetEffectPos (0x306838), on its own.
 *
 * Its callers include this header. func_00252070 (00252070.c) does not: its
 * second hit-spark call matches retail only with the size evaluated before
 * the handle, so that unit keeps its own declaration in that order. It
 * reaches cObjBase.h through cEm00.h, which is why the prototype is not in
 * cObjBase.h.
 */
#ifndef GODHAND_EFFECTPOS_H
#define GODHAND_EFFECTPOS_H

struct cVec;

/* Start effect id at pos with the default parameters and the given size. */
void SetEffectPos(int kind, int id, void *owner, struct cVec *pos, int handle, float size);

#endif
