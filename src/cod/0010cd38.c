/* NON_MATCHING func_0010CD38 (sn-2.95.3-136): enemy thrown-down step. The step increment after
 * func_002A8578 uses v1 where retail uses v0; the body matches when func_002A8578 is declared void,
 * but its definition in 00134880.c returns int. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, void *t0, int t1, int t2, int t3);
extern void cSnd_SeStop(void *a0, int a1);
extern int func_00124540(void *a0, int a1);
extern void InvokeVirtualAtField214AndForward_124E68(char *a0, float f12);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_001268F0(void *a0);
extern int func_00123938(void *a0, int a1);
extern void cCoreSave_addGameLevelPoint(void *self, int point);
extern int func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern char D_00569B70[];
extern char D_005FEE00[];

/* Thrown-down step of the enemy: on entry award the level points for a 0x200 actor in the
 * held link, stop the sound and start the knockdown motion and effect picked by stepArg;
 * then run the motion at the 0x15C0 speed scale until it ends. */
void func_0010CD38(cEm00 *self)
{
    int p1;
    int p2;

    switch (self->step) {
    case 0:
        if (self->stepArg != 0 && *(cGameObj **)((char *)self + 0x640) != 0) {
            if (cGameObj_idInRange(*(cGameObj **)((char *)self + 0x640), 0x200, 0x300) & 0xFF) {
                cCoreSave_addGameLevelPoint(D_00569B70, 8);
            }
        }
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_001268F0(self);
        *(float *)((char *)self + 0x15C0) = 1.0f;
        cSnd_SeStop(D_005FEE00, self->unk1620);
        self->unk1620 = 0;
        self->unk568 = 0;
        switch (self->stepArg) {
        case 0:
        default:
            Obj0000_Clear_Fields_640_648_124E58(self);
            p1 = EM_RES_REC(self->resource, 0x48);
            p2 = EM_RES_REC(self->resource, 0x4C);
            SetEffect(0, 0x17, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2A, self, 0, 0, 0, 0);
            self->unk568 = 0xC;
            break;
        case 1:
            self->hitFlash = 12.0f;
            Obj0000_Clear_Fields_640_648_124E58(self);
            p1 = EM_RES_REC(self->resource, 0x50);
            p2 = EM_RES_REC(self->resource, 0x54);
            SetEffect(0, 0x18, self, 0, -1, 0xFFFFFFFF);
            break;
        case 2:
            self->hitFlash = 5.0f;
            func_00124540(self, 5);
            p1 = EM_RES_REC(self->resource, 0x40);
            p2 = EM_RES_REC(self->resource, 0x44);
            SetEffect(0, 0x16, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2A, self, 0, 0, 0, 0);
            *(float *)((char *)self + 0x15C0) = 1.2f;
            break;
        case 3:
            self->hitFlash = 5.0f;
            func_00124540(self, 5);
            p1 = EM_RES_REC(self->resource, 0x38);
            p2 = EM_RES_REC(self->resource, 0x3C);
            SetEffect(0, 0x15, self, 0, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x2A, self, 0, 0, 0, 0);
            *(float *)((char *)self + 0x15C0) = 1.2f;
            break;
        }
        func_002A8578((int)self, p1, p2, 3, 0, 0, 0.0f);
        self->step += 1;
    case 1:
        if (*(int *)((char *)self + 0x640) != 0) {
            self->unk648 = 0x14;
        }
        if (self->stepArg == 0) {
            self->unk15F4 |= 0x4000;
        }
        switch (self->stepArg) {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
            if (*(int *)((char *)self + 0x640) == 0) {
                func_00124540(self, 5);
            }
            break;
        }
        if (self->unk568 > 0) {
            self->unk568 -= 1;
            if (*(unsigned char *)((char *)self + 0x61F) != 0) {
                self->unk15F4 |= 0x8000;
            }
        }
        InvokeVirtualAtField214AndForward_124E68((char *)self, 0.19634954f);
        if (moveMotion(self) != 0) {
            self->mode = 0;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        }
        self->stepVec.x *= *(float *)((char *)self + 0x15C0);
        self->stepVec.z *= *(float *)((char *)self + 0x15C0);
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    func_00123938(self, 1);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0010CD38);
#endif
