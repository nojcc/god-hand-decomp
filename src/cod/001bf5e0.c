/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/capVu0.h"
#include "godhand/cCamera.h"
#include "godhand/vu0.h"
#include "godhand/cVec.h"
#include "godhand/cActionButton.h"

extern int Dest_ck(float *from, float *to, float cur, float max);
extern void cActionButton_set(cActionButton *self, int priority, int life, int a3, int a4, int a5, int kind);
extern void cOmBase_startCutTask(cOmBase *self);
extern cActionButton D_00568288;

/* A switch that spins in place and offers the player a cut-scene button. */
typedef struct cOmSpinSwitch {
    cGameObj obj;                       /* 0x000 */
    char unk5AC[0x602 - 0x5AC];
    short timer;                        /* 0x602 phase 2 countdown */
} cOmSpinSwitch;

/* Spinning switch: turn by pi/30 a frame; while idle, show the action button
 * (it starts the cut-scene task) when the player is within 2.5 and faces it
 * within 1.396 rad (80 degrees), as Dest_ck tests it; phase 2 waits out the timer, then goes back to idle. */
__attribute__((section(".text.func_001BF5E0")))
void func_001BF5E0(cOmSpinSwitch *self)
{
    cVec rot;
    CVEC_TEMPS;

    CVEC_STORE(&rot, *self->obj.vt->getRot((char *)self + self->obj.vt->getRotDelta));
    rot.y += 0.10471976f;
    rot.y = Adjust_theta(rot.y);
    self->obj.vt->setRot((char *)self + self->obj.vt->setRotDelta, &rot);

    switch (self->obj.phase) {
    case 0: {
        cGameObj *pl = Getplayer();
        float len;

        CVEC_SUB_LENGTH_SQ(len, pl->vt->lockOn((char *)pl + pl->vt->lockOnDelta),
                           self->obj.vt->lockOn((char *)self + self->obj.vt->lockOnDelta));
        if (len < 6.25f) {
            cGameObj *p1 = Getplayer();
            cVec *from = p1->vt->lockOn((char *)p1 + p1->vt->lockOnDelta);
            cGameObj *p2 = Getplayer();
            cVec *plRot = p2->vt->getRot((char *)p2 + p2->vt->getRotDelta);
            cVec *to = self->obj.vt->lockOn((char *)self + self->obj.vt->lockOnDelta);

            if (Dest_ck(&from->x, &to->x, plRot->y, 1.3962634f) != 0) {
                cActionButton_set(&D_00568288, 4, 0x28, 0, (int)cOmBase_startCutTask, (int)self, 0);
            }
        }
        break;
    }
    case 1:
        /* retail has a case for phase 1 that does nothing: dropping it changes the code */
        break;
    case 2:
        if (self->timer <= 0) {
            self->obj.phase = 0;
        }
        self->timer--;
        break;
    }
}
