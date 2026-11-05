/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
#include "godhand/cModel.h"
#include "godhand/heapArena.h"
#include "godhand/cActionButton.h"
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"

extern int D_00428A20;
extern char D_005CAE50[];
extern void func_001331B8(char *a0, long a1, int a2);
extern cActionButtonEnt *func_001F7798(cActionButton *self);
extern void Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(cActionButton *self, int priority, cActionButtonEnt *ent);
extern int D_00747A34;

__attribute__((section(".text.SetField214PtrThenInit_1B6F38")))
void SetField214PtrThenInit_1B6F38(char *a0, int flags) {
    *(int*)(a0 + 0x214) = (int)&D_00428A20;
    func_001331B8(D_005CAE50, *(long*)(a0 + 0x540), 0);
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, (struct cGameObj *)a0);
    ReleaseObj((struct cModel *)a0);
    func_001FE370(&D_00574380, a0);
    cGameObj__dtor((struct cGameObj *)a0, flags);
}

__attribute__((section(".text.ReleaseField6ECByTag564_26B1E8")))
void ReleaseField6ECByTag564_26B1E8(cEm00 *self)
{
    cOmWeapon *x = self->unk6EC;
    if (x != 0) {
        if (self->emNo == 0x279) {
            cOmWeapon_SetBreak(x);
            self->unk6EC = 0;
        } else {
            cOmWeapon_setFall(x);
            self->unk6EC = 0;
        }
    }
}

/* Take a free entry and set its life, kind, flags and priority, then let
 * the manager sort it in by priority. */
__attribute__((section(".text.cActionButton_set")))
void cActionButton_set(cActionButton *self, int priority, int life, int a3, int a4, int a5, int kind)
{
    cActionButtonEnt *ent = func_001F7798(self);
    if (ent != 0) {
        ent->life = life;
        ent->unk20 = a3;
        ent->flags |= ACTBTN_ENT_USED;
        ent->unk10 = a4;
        ent->unk14 = a5;
        ent->kind = kind;
        ent->priority = priority;
        Obj0000_Swap_Field_4_In_Scaled_A1_Entry_1F7800(self, priority, ent);
    }
}

__attribute__((section(".text.__builtin_delete")))
void __builtin_delete(void *p) {
    if (p) {
        cHeap_free(((HeapBlk *)p - 1)->heap, p);
    }
}

