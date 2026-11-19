/* include/godhand/cOm71.h - cOm71, the racing dog (CreateObj kind 0x371).
 * A cGameObj with its own flag word at 0x600; nothing else past the base is
 * named, and the size of the object is not known.
 */
#ifndef GODHAND_COM71_H
#define GODHAND_COM71_H

#include "godhand/cGameObj.h"

/* Bits of cOm71.flags (0x600), as func_001B1E30 uses them. */
#define COM71_F_TO_RUN          0x08    /* switch to the run motion when the current one ends */
#define COM71_F_NO_NULL_SPEED   0x80    /* skip cObjBase_addNullSpeed */
#define COM71_F_MOTION_END      0x100   /* the motion ended this frame */

typedef struct cOm71 {
    cGameObj base;
    char unk5B0[0x600 - 0x5B0];
    int flags;                          /* 0x600 COM71_F_* */
} cOm71;

/* Start the run motion (motion table entry 0x5). */
void cOm71_SetMotionRun(void *a0);
/* Start the wait motion (motion table entry 0x10) at step 1.0. */
void cOm71_SetMotionWait(void *a0);
/* Start motion table entry 0x48 (the win motion on the result screen). */
void cOm71_SetMotion100(void *a0);
/* Start motion table entry 0x54 (the lose motion on the result screen). */
void cOm71_SetMotion102(void *a0);

#endif
