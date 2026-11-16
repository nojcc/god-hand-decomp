#include "godhand/CustomIDPanel.h"

extern void cIDBase(void *);

/* -- PERMANENT (bnel/beql) — stay in monolithic asm/cod/000000 ------------ */
/* func_001F20F8 (beql+bnel, 0x324 B) stays in monolithic — PERMANENT.      */
/* func_001F2428 (bnel, 0x110 B) stays in monolithic — PERMANENT.           */
/* ArenaEm_stepBossIntro (beql+bnel, 0x108 B) stays in monolithic — PERMANENT.      */
/* func_001F2650 (bnel, 0x40 B) stays in monolithic — PERMANENT.            */

/* -- Accessor C bodies (5) — jr $ra; nop empty functions ------------------ */

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_20F0")))
void Obj1F20_NoOp_20F0(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2420")))
void Obj1F20_NoOp_2420(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2538")))
void Obj1F20_NoOp_2538(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2648")))
void Obj1F20_NoOp_2648(void) {}

/* jr $ra; nop */
__attribute__((section(".text.Obj1F20_NoOp_2690")))
void Obj1F20_NoOp_2690(void) {}

/* -- Call-chain (nonmatching) --------------------------------------------- */
/* Arena enemy intro: step 0 defeats every enemy and moves on, step 1 moves to the last step. */
typedef struct ArenaEm {
    char unk000[0xB94];
    int introStep;                      /* 0xB94 */
} ArenaEm;

extern void ColiseumBattle_DefeatAllEnemies(ArenaEm *self);

__attribute__((section(".text.ArenaEm_stepIntro")))
void ArenaEm_stepIntro(ArenaEm *self)
{
    switch (self->introStep) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->introStep = self->introStep + 1;
        break;
    case 1:
        self->introStep = 2;
        break;
    }
}

/* Construct the panel: clear the flags, then construct both displays and their works. */
__attribute__((section(".text.func_001F2708")))
CustomIDPanel *func_001F2708(CustomIDPanel *self) {
    CustomIDWork *p;
    int i;

    self->flags = 0;
    cIDBase(&self->id);

    p = self->work;
    /* `i != -1`, not `i >= 0`: retail materialises -1 and closes with bne. */
    for (i = CIDPANEL_WORK_NUM - 1; i != -1; i--) {
        CustomIDWork__ctor(p);
        p++;
    }

    cIDBase(&self->id2);

    p = self->sub;
    for (i = CIDPANEL_SUB_NUM - 1; i != -1; i--) {
        CustomIDWork__ctor(p);
        p++;
    }

    return self;
}

#define UI_IDDATA_KIND    0x15
#define UI_TITLE_MESS     0x300F

/* Build the 18 custom-ID works of a UI object's main display and the 3 of its sub display, hide the main works, set the sub title message and run the final setup step. */
__attribute__((section(".text.IdUi_initWorks")))
void IdUi_initWorks(CustomIDPanel *self)
{
    int i;
    int j;

    cIDBase_initialize(&self->id, UI_IDDATA_KIND, 1);
    cIDBase_restartAnim(&self->id);
    for (i = 0; i < CIDPANEL_WORK_NUM; i++) {
        CustomIDWork_Initialize(&self->work[i], cIDBase_getIDWork(&self->id, i));
    }
    SetCustomIDDispOneOrAll_1F29C0(self, CIDPANEL_WORK_NUM, 0);
    cIDBase_initialize(&self->id2, UI_IDDATA_KIND, 2);
    cIDBase_restartAnim(&self->id2);
    for (j = 0; j < CIDPANEL_SUB_NUM; j++) {
        CustomIDWork_Initialize(&self->sub[j], cIDBase_getIDWork(&self->id2, j));
    }
    CustomIDWork_SetMessNo(&self->sub[2], UI_TITLE_MESS);
    CustomIDOwner_setPanelState(self, 0);
}
