/* NON_MATCHING func_00241908 (sn-2.95.3-136, extern_jtbl D_0043C800): the game level switch differs. Retail dispatches levels 1..5 through a five-entry table (1 shares the default arm, 3..5 share one arm); our cc1 groups 1 into the default and 3..5 into one range, counts four case nodes and emits a compare tree instead. The rest follows retail. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12);
extern float Turn_dest_dir(float angle, float dest, float rate);
extern float Adjust_theta(float angle);
extern int moveMotion(void *self);
extern void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale);
extern void cObjBase_addNullSpeed(cObjBase *self, float scale);

/* cEm00.h does not name 0x1748 yet. */
#define EM_1748(self) (*(float *)((char *)(self) + 0x1748))

/* Wait facing forward: hold the waiting motion until both partner enemies (cEmManage slots 2 and 3) are down,
 * this one is told to go, or the level's time limit runs out; then wait one more second and switch to phase 0x75. */
__attribute__((section(".text.func_00241908")))
void func_00241908(cEm00 *self)
{
    int nb;
    int done;

    switch (self->step) {
    case 0:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        func_002A8578((int)self, EM_RES_REC(self->resource, 0x10A8), EM_RES_REC(self->resource, 0x10AC), 0xA, nb, 0, 0.0f);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1:
        default:
            self->timer = 750.0f;
            break;
        case 2:
            self->timer = 600.0f;
            break;
        case 3:
        case 4:
        case 5:
            self->timer = 450.0f;
            break;
        }
        self->step++;
    case 1:
        self->unk617 = 1;
        self->rot.y += Turn_dest_dir(self->rot.y, 0.0f, self->speedRate * 0.09817477f);
        self->rot.y = Adjust_theta(self->rot.y);
        self->hitFlash = 3.0f;
        self->emFlags = self->emFlags | 0x10000 | 0x20000;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        done = (self->emFlags & 0x20000000) != 0;
        if (D_005864F0.unk560[3] == 0 || D_005864F0.unk560[3]->vital <= 0) {
            done = 1;
        }
        if (D_005864F0.unk560[2] == 0 || D_005864F0.unk560[2]->vital <= 0) {
            done = 1;
        }
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            done = 1;
        }
        if (done) {
            self->step = 2;
        }
        break;
    case 2:
        self->timer = 60.0f;
        self->step++;
    case 3:
        self->hitFlash = 3.0f;
        self->unk617 = 1;
        self->emFlags = self->emFlags | 0x10000 | 0x20000;
        moveMotion(self);
        cObjBase_addNullSpeed_Rotation((cObjBase *)self, 1.0f);
        cObjBase_addNullSpeed((cObjBase *)self, 1.0f);
        self->timer -= self->speedRate;
        if (self->timer <= 0.0f) {
            EM_1748(self) = 300.0f;
            self->unk6D0.x = 1.954f;
            self->unk6D0.y = 4.0f;
            self->unk6D0.z = -14.872f;
            self->unk6E0 = 0.0f;
            self->phase = 0x75;
            self->stepArg = 0;
            self->mode = 0;
            self->step = 0;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00241908);
#endif
