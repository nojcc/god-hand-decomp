/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/cIDBase.h"
#include "godhand/cOmBase.h"
#include "godhand/mtx.h"
#include "godhand/DogRace.h"

extern void displayScrollLayer(int id, int on);
extern void func_001EC088(DogRace *self);
extern void cTaskWork_exit(void *work);

/* dst = src rotated by angle about y. */
__attribute__((section(".text.VecRotY")))
void VecRotY(cVec *dst, cVec *src, float angle)
{
    float m[4][4];
    MtxInitRotY(m[0], angle);
    Tramp_func_0030A2B0_001508D8(dst, m, src);
}

#define ICONSCREEN_SUB_FLAG_DONE 0x400  /* the child object finished its animation */

typedef struct IconScreenSub {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C */
} IconScreenSub;

typedef struct IconScreen {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x92 - sizeof(cIDBaseObj)];
    unsigned short step;                /* 0x92 */
    IconScreenSub *child;               /* 0x94 */
} IconScreen;

/* Advance to the next step once the child object has finished animating. */
__attribute__((section(".text.IconScreen_waitChildDone")))
void IconScreen_waitChildDone(IconScreen *self)
{
    if (self->child->flags & ICONSCREEN_SUB_FLAG_DONE) {
        cIDBase_move(&self->base);
        self->step++;
    }
}

#define SLOT2_OFFSET_LAYER_IDS  0x3A0   /* scroll layer ids, not named in Slot2.h */
#define SLOT2_LAYER_ID_NUM      12

/* Hide every scroll layer of the machine's layer id table. */
__attribute__((section(".text.Slot2_hideLayerIds")))
void Slot2_hideLayerIds(Slot2 *self)
{
    int *id = (int *)((char *)self + SLOT2_OFFSET_LAYER_IDS);
    int i;

    for (i = SLOT2_LAYER_ID_NUM - 1; i >= 0; i--) {
        displayScrollLayer(*id++, 0);
    }
}

/* Call the race's handler for the current step (with its `this` adjust), then run the shared update. */
__attribute__((section(".text.Slot2_dispatchStep")))
void Slot2_dispatchStep(DogRace *self)
{
    int i = self->step;
    short off = D_003BE528[i].delta;
    void (*fn)(void *self) = D_003BE528[i].fn;
    fn((char *)self + off);
    func_001EC088(self);
}

#define TASKFN_ARG1  1      /* call the function with the argument word */

/* The work record of a task that just runs one function and ends. */
typedef struct TaskFnWork {
    char unk00[0x14];
    void (*fn)();                       /* 0x14 */
    int arg;                            /* 0x18 */
    char unk1C[2];
    unsigned short kind;                /* 0x1E TASKFN_ARG1, anything else: no argument */
} TaskFnWork;



/* Task body: call the stored function (with its argument when kind is 1), then end the task. */
__attribute__((section(".text.TaskFnWork_runAndExit")))
void TaskFnWork_runAndExit(TaskFnWork *self)
{
    switch (self->kind) {
    default:
    case 0:
        self->fn();
        break;
    case TASKFN_ARG1:
        self->fn(self->arg);
        break;
    }
    cTaskWork_exit(self);
}
