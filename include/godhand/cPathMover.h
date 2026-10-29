/* include/godhand/cPathMover.h - an object that walks a list of path nodes.
 *
 * The path walk (func_001B51B0) steps the position toward nodes[node] by
 * speed each frame; the spinning-blade phase machine at 0x1B4528 ramps the
 * speed up to speedMax, grows its child body, waits, then shrinks it and
 * slows back down.
 */
#ifndef GODHAND_CPATHMOVER_H
#define GODHAND_CPATHMOVER_H

#include "godhand/cGameObj.h"

#define PATH_REVERSE 0x1                /* pathFlags: walking the nodes backward */
#define PATH_LOOP    0x2                /* pathFlags: turn around at either end */

typedef struct PathMover {
    cGameObj base;
    char unk5B0[0x600 - 0x5B0];
    int pathFlags;                      /* 0x600 PATH_* */
    cVec *nodes;                        /* 0x604 */
    unsigned short nodeNum;             /* 0x608 */
    unsigned short node;                /* 0x60A the node it walks to */
    float speedMax;                     /* 0x60C top speed; a node within it counts as reached */
    float speed;                        /* 0x610 distance walked per frame */
    float accel;                        /* 0x614 speed gained per frame while speeding up */
    float decel;                        /* 0x618 speed lost per frame while slowing down */
    char unk61C[0x634 - 0x61C];
    float waitBase;                     /* 0x634 frames to wait at full size, before the random part */
    float wait;                         /* 0x638 frames left at full size */
    char unk63C[0x648 - 0x63C];
    int se;                             /* 0x648 handle of the running sound */
    char unk64C[0x654 - 0x64C];
    void *hitA;                         /* 0x654 damage units, active only at full size */
    void *hitB;                         /* 0x658 */
} PathMover;

/* Steps toward the current node; returns 1 when it reached it. */
int func_001B51B0(PathMover *self);

#endif
