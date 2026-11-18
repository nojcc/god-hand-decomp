#ifndef GODHAND_COMHITHOLDER_H
#define GODHAND_COMHITHOLDER_H

#include "godhand/cOmBase.h"

/* A map object that keeps the last hit it took: the cDamageTake at 0x600 is
 * cleared by cOmBase_updateWithHitRecord each frame, which the gimmick updates
 * run instead of their phase table while flags0 bit 2 is set. */
typedef struct cOmHitHolder {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageTake *take;                  /* 0x600 */
} cOmHitHolder;

void cOmBase_updateWithHitRecord(cOmHitHolder *self);

#endif /* GODHAND_COMHITHOLDER_H */
