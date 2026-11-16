/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cOmBase.h"
#include "godhand/CustomIDWork.h"
#include "godhand/PanelObj.h"
#include "godhand/cOm60.h"
#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/capVu0.h"

extern void func_001B6FB8(void *self);
extern float fRand1_1(void);

/* Set the object up: 40 life, a 1.6 by 2.24 hit cylinder through the damage manager, no flag byte. */


#define OBJ_LIFE  0x28






/* The object past cOmBase: the damage unit handle and a flag byte. */
typedef struct DamagedObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    unsigned char flag604;              /* 0x604 */
    char unk605[3];
    void *damage;                       /* 0x608 */
} DamagedObj;

__attribute__((section(".text.DamagedObj_setupHitCylinder")))
int DamagedObj_setupHitCylinder(DamagedObj *self) {
    cVec v[4];
    cVec *pos;
    cVec *dir;
    void *slot;
    float one, ca, cb;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.6f;
    cb = 2.24f;
    pos = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    pos->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 1);
    self->damage = slot;
    if (slot != 0) {
        dir = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        dir->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, self->base.mtx, pos, dir, v[1].y, v[1].x * 0.5f);
    }
    self->flag604 = 0;
    self->base.hpMax = OBJ_LIFE;
    self->base.hp = OBJ_LIFE;
    return 1;
}

/* Throw the held object in slot `no` with a random small tilt; `keepTime` leaves its flight timer, otherwise it is set to 150. The slot is emptied. */



#define THROW_SLOT_OFFSET  0x6E4        /* object handles the enemy holds */
#define THROW_UP_BASE      0.2f





__attribute__((section(".text.EmThrower_throwHeld")))
void EmThrower_throwHeld(cEm00 *self, int no, int keepTime) {
    cVec dir;
    cOm60 *obj;
    float side;
    float up;
    float depth;
    VU0_SQC2_VF0(&dir, 0);
    obj = self->held[no];
    if (obj == 0) {
        return;
    }
    self->held[no] = 0;
    side = fRand1_1() * THROW_SIDE;
    up = fRand1_1() * THROW_UP_RAND + THROW_UP_BASE;
    depth = fRand1_1() * THROW_SIDE;
    dir.x = side;
    dir.y = up;
    dir.z = depth;
    capVu0ApplyMatrixXYZ(&dir, self->mtx, &dir);
    if (keepTime != 0) {
        cOm60_setThrow(obj, &dir, THROW_KEEP_TIME);
    } else {
        cOm60_setThrow(obj, &dir, THROW_TIME);
    }
}

/* Slide the UI panel (element at +0x728) on or off and show or hide its two child elements 0xE and 0xF.
 * Mode 0: off screen, children hidden. 1: on screen. 2: slide in from the right. 3: slide out to the right. */




#define PANEL_WORK_ELEM    0xE          /* the element whose CustomIDWork slides the panel */
#define PANEL_OFF_X        200          /* pixels to the right of its resting place */
#define PANEL_SLIDE_FRAMES 10
#define PANEL_ELEM_A       0xE
#define PANEL_ELEM_B       0xF

__attribute__((section(".text.UiPanel_setSlideMode")))
void UiPanel_setSlideMode(PanelObj *self, unsigned char mode) {
    switch (mode) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(&self->elem[PANEL_WORK_ELEM], PANEL_OFF_X);
        func_001DEE60(self, PANEL_ELEM_A, 0);
        func_001DEE60(self, PANEL_ELEM_B, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(&self->elem[PANEL_WORK_ELEM], 0);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(&self->elem[PANEL_WORK_ELEM], PANEL_OFF_X, 0, PANEL_SLIDE_FRAMES);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(&self->elem[PANEL_WORK_ELEM], 0, PANEL_OFF_X, PANEL_SLIDE_FRAMES);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    }
}
