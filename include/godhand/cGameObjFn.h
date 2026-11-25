/* include/godhand/cGameObjFn.h - cGameObj helpers and methods more than one unit calls.
 *
 * cGameObj.h holds the record. Older units declare several of these
 * themselves with their own parameter types, so the prototypes (and the
 * state-byte helper) live here for the units that take them from a header.
 */
#ifndef GODHAND_CGAMEOBJFN_H
#define GODHAND_CGAMEOBJFN_H

#include "godhand/cGameObj.h"

/* Destructor of the cGameObj subclass with method table D_0044A660: leave
 * the damage manager and the solid-collision manager, then run
 * cGameObj__dtor. */
void func_0028EB88(struct cGameObj *self, int flags);

/* Mode 0 and the given phase, step and step argument. */
static __inline__ void cGameObj_setState(struct cGameObj *self, unsigned char phase, unsigned char step, unsigned char arg)
{
    self->stepArg = arg;
    self->phase = phase;
    self->step = step;
    self->mode = 0;
}

/* State setters: phase N at step 0, with the step argument when they take one. */
void func_00281260(struct cGameObj *self);
void Obj2810_SetState_1_a1(struct cGameObj *self, int arg);
void Obj2810_SetState_2_a1(struct cGameObj *self, int arg);
void Obj2810_ClearState_4(struct cGameObj *self);
void Obj2810_ClearState_5(struct cGameObj *self);
void Obj2810_ClearState_6(struct cGameObj *self);
void Obj2810_SetState_8_a1(struct cGameObj *self, int arg);
void Obj2810_SetState_9_a1(struct cGameObj *self, int arg);
void Obj2810_SetState_E_a1(struct cGameObj *self, int arg);
void Obj2810_ClearState_B(struct cGameObj *self);
void Obj2810_ClearState_C(struct cGameObj *self);
void Obj2810_SetState_D_a1(struct cGameObj *self, int arg);
void ClearBytes2F4To2F7_283170(struct cGameObj *self);
void SetBytes2F4Mode1_283188(struct cGameObj *self, int arg);
void SetBytes2F4Mode2_2831B0(struct cGameObj *self, int arg);
void SetBytes2F4Mode4_283240(struct cGameObj *self);
void SetBytes2F4Mode5_283258(struct cGameObj *self);
void SetBytes2F4Mode7_283270(struct cGameObj *self, int arg);
void SetBytes2F4Mode8_283288(struct cGameObj *self, int arg);
void SetBytes2F4Mode11_283360(struct cGameObj *self, int arg);
void SetBytes2F4Mode10_2833C0(struct cGameObj *self, int arg);

/* Phase N at step 0, 2, 4 or 6 for kind 0 to 3 (an unknown kind gives step 0). */
void cGameObj_startPhase3(struct cGameObj *self, unsigned int kind, unsigned char arg);
void func_00281368(struct cGameObj *self, int kind);
void func_002813F0(struct cGameObj *self, int kind);
void func_00281470(struct cGameObj *self, unsigned char kind);
void func_00281500(struct cGameObj *self, unsigned char kind);
void func_00281560(struct cGameObj *self, unsigned char kind);
void func_00283378(struct cGameObj *self, unsigned char kind);
void func_002833D8(struct cGameObj *self, unsigned char kind);
void func_00283438(struct cGameObj *self, unsigned char kind);
int func_00273C38(struct cGameObj *self);
int func_00275888(struct cGameObj *self, float dist);
unsigned char func_002A7CA0(struct cGameObj *self, cVec *out);

/* Start effect id for self with the default parameters and kill it with self. */
void InitRenderStruct_2A8608(struct cGameObj *self, int kind, int id, int handle, int killMode, void *owner);

#endif /* GODHAND_CGAMEOBJFN_H */
