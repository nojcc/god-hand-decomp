/* NON_MATCHING func_00245538 (sn-2.95.3-136, extern_jtbl D_0043D0F0 D_0043D2B0): 18 of 166 insns differ, all in the two motion-record selects. Retail loads each pair of offsets into v1/a0 and adds the resource base into a1/a2 at the join, before setting f12; ours loads straight into a1/a2 and adds after. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cSceAtManager.h"
#include "godhand/cObjBase.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12);
extern int moveMotion(void *self);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);
extern void cGameObj_SetTgtTurn(char *self, void *target, float rate);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

/* cEm00.h does not name these yet: the point the enemy walks to, and a word cleared when the walk ends. */
#define EM_GOAL(self) ((float *)((char *)(self) + 0x6C0))
#define EM_1734(self) (*(int *)((char *)(self) + 0x1734))

/* Walk to the goal point: start the walk motion (or the turn-and-walk motion once the goal is in reach),
 * turn toward the goal while it is more than 0.5 away, and play the motion out. */
__attribute__((section(".text.func_00245538")))
void func_00245538(cEm00 *self)
{
    int nb;
    int mot;
    int sub;
    int res;

    if (self->step == 0 && FindNodeByHit_2C2490(&D_005FEA60, self->pos, EM_GOAL(self)) == 1) {
        self->step = 2;
    }
    switch (self->step) {
    case 0:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default:
            res = self->resource;
            mot = *(int *)(res + 0x348);
            sub = *(int *)(res + 0x34C);
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            res = self->resource;
            mot = *(int *)(res + 0xAE4);
            sub = *(int *)(res + 0xAE8);
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            res = self->resource;
            mot = *(int *)(res + 0x13D8);
            sub = *(int *)(res + 0x13DC);
            break;
        }
        func_002A8578((int)self, mot + res, sub + res, 3, nb, 0, 0.0f);
        self->step++;
    case 1:
        if (moveMotion(self) != 0) {
            EM_1734(self) = 0;
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    case 2:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        switch (self->emNo) {
        default:
            res = self->resource;
            mot = *(int *)(res + 0x350);
            sub = *(int *)(res + 0x354);
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
        case 0x245: case 0x246: case 0x247: case 0x24F: case 0x278: case 0x279:
            res = self->resource;
            mot = *(int *)(res + 0xAEC);
            sub = *(int *)(res + 0xAF0);
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E: case 0x225:
        case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249:
        case 0x24C: case 0x24D: case 0x24E: case 0x252: case 0x25A:
            res = self->resource;
            mot = *(int *)(res + 0x13E0);
            sub = *(int *)(res + 0x13E4);
            break;
        }
        func_002A8578((int)self, mot + res, sub + res, 3, nb, 0, 0.0f);
        self->timerA = 1;
        self->step++;
    case 3:
        if (capVu0MagnitudeSqXZ(EM_GOAL(self), self->pos) > 0.25f && self->timerA != 0) {
            cGameObj_SetTgtTurn((char *)self, EM_GOAL(self), self->speedRate * 0.3926991f);
        } else {
            self->timerA = 0;
        }
        if (moveMotion(self) != 0) {
            self->step = 0;
        }
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00245538);
#endif
