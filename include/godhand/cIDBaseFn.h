/* include/godhand/cIDBaseFn.h - cIDBase methods.
 *
 * Work's prototypes that cIDBase.h on main does not carry: some clash with
 * main units' own declarations. Included by the work units that need them.
 */
#ifndef GODHAND_CIDBASEFN_H
#define GODHAND_CIDBASEFN_H

#include "godhand/cIDBase.h"

/* Draw the visible entries, layer 4 first and layer -4 last. */
void cIDBase_trans(cIDBaseObj *self);
/* cIDBase_trans(self). */
void Forward2AAC28_13F070(cIDBaseObj *self);
/* Re-initialise entry idx of an ID work (the record type is not known yet). */
void cIDBase_initIDWork(void *self, int idx);
int cIDBase_initialize(cIDBaseObj *self, int resNo, int id);
int cIDBase_setPackedMessData(cIDBaseObj *self, int resNo, int arg);
void cIDBase_restartAnim(cIDBaseObj *self);
/* Reset every entry's animation. */
void cIDBase_resetAnim(cIDBaseObj *self);
/* Step the jitter counters of every entry while the display plays. */
void cIDBase_stepJitter(cIDBaseObj *self);

#endif /* GODHAND_CIDBASEFN_H */
