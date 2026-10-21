/* NON_MATCHING func_001A4650 (sn-2.95.3-136, as sn): 4 words out of place plus the shift.
 * Retail computes &f.d (sp+0x20) and &f.tmp before the vector subtraction and keeps
 * &f.d in a0 for capVu0LengthSq; here they are computed after it. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOm4f.h"
#include "godhand/cGameObj.h"
#include "godhand/cActionButton.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#define DOOR_REACH_HEIGHT  2.0f
#define DOOR_REACH_SQ      2.25f
#define DOOR_FACING_RANGE  1.3089969f
#define DOOR_BUTTON_PRIO   4
#define DOOR_MSG_OPEN      0x1E
#define DOOR_MSG_CLOSE     0x1F

/* The door's frame: its position, the player's, and their difference. */
typedef struct DoorReachFrame {
    cVec me;
    cVec pl;
    cVec d;
    cVec tmp;
} DoorReachFrame;

#define DOORFRAME_OFFSET(field) ((int)&((DoorReachFrame *)0)->field)

/* The rotation getter in the 0x88 slot of cGameObjVt. */
#define GAMEOBJ_GETROT(obj) \
    (*(cVec *(**)(void *))((char *)(obj)->vt + 0x8C))( \
        (char *)(obj) + *(short *)((char *)(obj)->vt + 0x88))

extern cActionButton D_00568288;
extern unsigned int cOm4f_isActive(cOm4f *self);
extern unsigned char cOm4f_isOpen(cOm4f *self);
extern void cOm4f_syncDoor(cOm4f *self);
extern float capVu0LengthSq(void *a0);
extern int Dest_ck(void *a0, void *a1, float f12, float f13);
extern void cActionButton_set(cActionButton *self, int priority, int life, int a3, int a4, int a5, int kind);
extern void Tramp_cOm4f_setOpen_1A4B90(void);
extern void Tramp_cOm4f_setClose_1A4BB0(void);

/* Offers the open or close prompt while the player stands at the door facing it. */
__attribute__((section(".text.func_001A4650")))
void func_001A4650(cOm4f *self)
{
    cGameObj *obj = (cGameObj *)self;
    DoorReachFrame f;
    float dy;

    if (cOm4f_isActive(self) == 0 && self->lock == 0) {
        VU0_LQC2(4, ((cVec *(*)(void *))obj->vt->lockOn)((char *)obj + obj->vt->lockOnDelta), 0);
        VU0_SQC2(4, &f, DOORFRAME_OFFSET(me));
        {
            cGameObj *player = Getplayer();
            VU0_LQC2(4, ((cVec *(*)(void *))player->vt->lockOn)((char *)player + player->vt->lockOnDelta), 0);
        }
        VU0_SQC2(4, &f, DOORFRAME_OFFSET(pl));
        dy = __builtin_fabsf(f.me.y - f.pl.y);
        f.me.y = f.pl.y;
        VU0_SQC2_VF0(&f, DOORFRAME_OFFSET(tmp));
        VU0_LQC2(4, &f.me, 0);
        VU0_LQC2(5, &f.pl, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, &f, DOORFRAME_OFFSET(tmp));
        VU0_LQC2(4, &f.tmp, 0);
        VU0_SQC2(4, &f, DOORFRAME_OFFSET(d));
        if (dy < DOOR_REACH_HEIGHT && capVu0LengthSq(&f.d) < DOOR_REACH_SQ) {
            cGameObj *player = Getplayer();
            if (Dest_ck(&f.pl, &f.me, GAMEOBJ_GETROT(player)->y, DOOR_FACING_RANGE) != 0) {
                if (cOm4f_isOpen(self) == 0) {
                    cActionButton_set(&D_00568288, DOOR_BUTTON_PRIO, DOOR_MSG_OPEN, 0,
                                      (int)Tramp_cOm4f_setOpen_1A4B90, (int)self, 0);
                } else {
                    cActionButton_set(&D_00568288, DOOR_BUTTON_PRIO, DOOR_MSG_CLOSE, 0,
                                      (int)Tramp_cOm4f_setClose_1A4BB0, (int)self, 0);
                }
            }
        }
    }
    cOm4f_syncDoor(self);
}
#else
INCLUDE_ASM("asm/nonmatching", func_001A4650);
#endif
