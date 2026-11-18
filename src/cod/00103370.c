/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"

#include "godhand/cObj.h"

extern void func_0012C348(void *a0, int a1);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern unsigned int D_00747A24;

/* An object that runs the death demo, counting down a timer of its own at 0x1490. */
typedef struct cDieDemoObj {
    cGameObj base;                      /* 0x000 */
    char unk5B0[0x1490 - 0x5B0];
    int demoLeft;                       /* 0x1490 frames left before the demo sets D_00747A24 bit 3 */
} cDieDemoObj;

/* Death demo: start the demo sound, drop the level points, set the player's state 3 and play the death motion with
 * its effect; then count the timer down and play the motion out, setting D_00747A24 bit 3 when either ends. */
__attribute__((section(".text.func_00103370")))
void func_00103370(cDieDemoObj *self)
{
    cGameObj *pl;
    int res;
    int motA;
    int motB;

    pl = Getplayer();
    self->base.hitFlash = 30.0f;
    switch (self->base.step) {
    case 0:
        res = (int)self->base.pack;
        motA = EM_RES_REC(res, 0x4C);
        motB = EM_RES_REC(res, 0x50);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_dropLevelPoint(&D_00569B70);
        func_0012C348(pl, 3);
        func_002A8578(self, motA, motB, 2, 0.0f, 0, 0);
        SetEffect(0, 0x53, self, 0, -1, 0xFFFFFFFF);
        self->demoLeft = 0x82;
        self->base.step = self->base.step + 1;
    case 1:
        if (self->demoLeft != 0) {
            self->demoLeft = self->demoLeft - 1;
        } else {
            D_00747A24 = D_00747A24 | 8;
        }
        if (moveMotion(self) != 0) {
            D_00747A24 = D_00747A24 | 8;
            self->base.step = self->base.step + 1;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        break;
    }
}
