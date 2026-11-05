/* include/godhand/cCamManager.h - cCamManager, the owner of the game cameras.
 *
 * A cCamManager holds four cameras back to back (player at 0, motion at
 * 0x530, parts at 0x920, sub-screen at 0xC90), each starting with a cCamera, the camera that was current before the last switch (0xFF0), and
 * a mode word (0x1028) that says which camera is current. The setXxxCamera
 * methods in camera/cCamManager.c switch the mode and publish the new camera
 * in the global D_005CAFF0.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCAMMANAGER_H
#define GODHAND_CCAMMANAGER_H

#include "godhand/cCamera.h"

/* Values of cCamManager.mode. */
#define CAMMGR_MODE_PLAYER   0x01       /* player camera */
#define CAMMGR_MODE_MOTION   0x04       /* motion camera, at 0x530 */
#define CAMMGR_MODE_NO_MOVE  0x04       /* with this bit set, update does not call cCamera_move */
#define CAMMGR_MODE_HOLD     0x10       /* no setter switches away from it */
#define CAMMGR_MODE_PARTS    0x40       /* parts camera, at 0x920 */
#define CAMMGR_MODE_SUBSCR   0x80       /* sub-screen camera */

typedef struct cCamManager {
    struct cCamera player;              /* 0x000 */
    char unk360[0x530 - 0x360];
    struct cCamera motion;              /* 0x530 */
    char unk890[0x920 - 0x890];
    struct cCamera parts;               /* 0x920 */
    char unkC80[0xC90 - 0xC80];
    struct cCamera subScr;              /* 0xC90 */
    struct cCamera *prevCamera;         /* 0xFF0 camera that was current before the switch */
    char unkFF4[0x1028 - 0xFF4];        /* 0xFF4 state that func_00137F38 updates */
    int mode;                           /* 0x1028 CAMMGR_MODE_* */
    int prevMode;                       /* 0x102C */
} cCamManager;

extern cCamManager D_00463050;         /* the game's camera manager */
extern struct cCamera *D_005CAFF0;     /* the current camera */
/* The setters read the current camera as a word: read through the pointer type,
 * the load moves above their prevMode store. */
#define CAMMGR_CUR_CAMERA_WORD (*(int *)&D_005CAFF0)

/* Construct the manager: its four cameras, the state at 0xFF4, then start on the player camera. */
void *func_00138BE8(void *a0);
/* Move the current camera when the mode has CAMMGR_MODE_NO_MOVE (the motion camera). */
void func_00138F98(cCamManager *self);
/* Start on the player camera: set the mode, reset the camera and make it current. */
void func_00138C70(cCamManager *self);
/* Copy the parts of src that mask selects into dst: bit 0 the eye, bit 1 the target, bit 3 the whole cCamera record. */
void func_00138CA8(cCamManager *self, struct cCamera *dst, struct cCamera *src, unsigned char mask);
/* The setters make their camera current, unless it already is or the mode is CAMMGR_MODE_HOLD;
 * a nonzero blend first copies those parts of the current camera into it. */
void cCamManager_setPlCamera(cCamManager *self, unsigned char blend);
void cCamManager_setMotCamera(cCamManager *self, unsigned char blend);
void cCamManager_setPartsCamera(cCamManager *self, unsigned char blend);
/* Also resets the sub-screen camera. */
void cCamManager_setSubScrCamera(cCamManager *self, unsigned char blend);

#endif
