/* sn-2.95.3-136 */
#include "godhand/pl00.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cVec.h"
#include "godhand/motion.h"
#include "godhand/player.h"
#include "godhand/vecInline.h"

extern int func_00124540(pl00 *self, int kind);
extern void Obj0000_Clear_Fields_640_648_124E58(char *a0);
extern int GetField_68C_1D0C10(char *a0);
extern void Obj0000_Set_Field_68C_Zero_1D0C18(int *a0);
extern void InvokeVirtualAtField214AndForward_124E68(char *a0, float f12);
extern void func_0012AFE8(pl00 *self, cOmWeapon *weapon);
extern void func_0012AC98(pl00 *self);
extern int func_00123938(void *self, int mode);

/* Address of the motion whose offset sits at off in the model data block. */
#define MOTION_AT(data, off) (*(int *)((data) + (off)) + (int)(data))

/* The player's take-weapon step: play the take motion that fits the partner at
 * 0x698, and on the take frame take its weapon (a 0x390 partner keeps its own
 * and hands over a new 0x37C), or call func_0012AC98 when it has none. */
__attribute__((section(".text.func_00110B20")))
void func_00110B20(pl00 *self)
{
    self->flags15F4 |= 0x100000;
    switch (self->base.step) {
    case 0: {
        int start;
        int end;

        self->comboSlot = 0;
        self->comboSet = 0;
        func_00124540(self, 4);
        if (self->sub698 != 0 && self->sub698->actorId == 0x3AF)
            Obj0000_Clear_Fields_640_648_124E58((char *)self);
        start = MOTION_AT(self->base.pack, 0x3CC);
        end = MOTION_AT(self->base.pack, 0x3D0);
        if (self->sub698 != 0) {
            switch (self->sub698->actorId) {
            default:
                start = MOTION_AT(self->base.pack, 0x3CC);
                end = MOTION_AT(self->base.pack, 0x3D0);
                break;
            case 0x36D:
            case 0x377:
            case 0x378:
            case 0x3AA:
            case 0x3AB:
                start = MOTION_AT(self->base.pack, 0x91C);
                end = MOTION_AT(self->base.pack, 0x920);
                break;
            case 0x37B:
            case 0x390:
                start = MOTION_AT(self->base.pack, 0x3CC);
                end = MOTION_AT(self->base.pack, 0x3D0);
                if (GetField_68C_1D0C10((char *)self->sub698) != 0) {
                    start = MOTION_AT(self->base.pack, 0x934);
                    end = MOTION_AT(self->base.pack, 0x938);
                    self->base.stepArg = 1;
                }
                break;
            case 0x3AF:
                start = MOTION_AT(self->base.pack, 0x8C0);
                end = MOTION_AT(self->base.pack, 0x8C4);
                break;
            }
        }
        func_002A8578((int)self, start, end, 3, 0.0f, 0, 0);
        self->unk15B0 = 1;
        self->base.step++;
    }
    case 1:
        if (self->unk640 != 0)
            self->unk648 = 0x14;
        InvokeVirtualAtField214AndForward_124E68((char *)self, 0.19634955f);
        if (moveMotion(self) != 0) {
            Obj0000_Clear_Fields_640_648_124E58((char *)self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation((struct cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((struct cObjBase *)self, 1.0f);
        break;
    }
    if ((self->base.seqFlags & 1) && self->unk15B0 != 0) {
        int weapon;

        self->unk15B0 = 0;
        weapon = GetField_68C_1D0C10((char *)self->sub698);
        if (weapon != 0) {
            if (self->sub698->actorId == 0x390) {
                cGameObj *w = CreateObj(0x37C, 0xFFFF);

                if (w != 0) {
                    cVec heldPos;
                    cVec heldRot;

                    CVEC_ZERO(heldPos);
                    CVEC_ZERO(heldRot);
                    cGameObj_vt(w)->unk44((char *)w + cGameObj_vt(w)->unk40Delta);
                    cVec_copy3(w->pos, self->base.pos);
                    cVec_copy3(&w->posA, self->base.pos);
                    vec3_set(&w->rot.x, 0, 0, 0);
                    vec3_set(&heldPos.x, 0, 0, 0);
                    vec3_set(&heldRot.x, 0, 0, 0);
                    cOmWeapon_setParent((cOmWeapon *)w, (cOmBase *)self->sub698, 2, &heldPos, &heldRot);
                    func_0012AFE8(self, (cOmWeapon *)w);
                    SetEffect(0, 0x67, self->sub698, 0, -1, 0xFFFFFFFF);
                }
            } else {
                func_0012AFE8(self, (cOmWeapon *)weapon);
                Obj0000_Set_Field_68C_Zero_1D0C18((int *)self->sub698);
                SetEffect(0, 0x67, self->sub698, 0, -1, 0xFFFFFFFF);
            }
        } else {
            func_0012AC98(self);
        }
    }
    if (self->base.stepArg != 0)
        self->flags15F4 |= 0x1000000;
    if (func_00123938(self, 1) != 0)
        Obj0000_Clear_Fields_640_648_124E58((char *)self);
}
