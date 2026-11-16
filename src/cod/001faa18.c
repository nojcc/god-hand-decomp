/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"

extern cVtEnt D_00447AD0[];
extern cVtEnt D_00447E68[];
extern cVtEnt D_00447F70[];
extern void NoOp_279E70(void);
extern cVtEnt D_00448028[];
extern cVtEnt D_004483A8[];
extern void cCollisionSolidManage_ReleaseUnit_27E088(void *a0);
extern cVtEnt D_00448890[];
extern cVtEnt D_00448948[];

/* clone */

__attribute__((section(".text.cCoreSave_addKeyNum")))
/* Add to the key count, clamped to 0..9. */
void cCoreSave_addKeyNum(cCoreSave *self, int n) {
    if (!self->data)
        return;
    self->data->keyNum += n;
    if (self->data->keyNum >= 0xA)
        self->data->keyNum = 9;
    if (self->data->keyNum < 0)
        self->data->keyNum = 0;
}

/* clone */

__attribute__((section(".text.func_0026E7A8")))
void func_0026E7A8(char *a0, float *a1) {
    float *p = (float*)(a0 + 0x1660);
    if (p == a1) return;
    *(float*)(a0 + 0x1660) = a1[0];
    p[1] = a1[1];
    p[2] = a1[2];
}

/* clone */


__attribute__((section(".text.func_002714B0")))
void func_002714B0(char *a0) {
    int v = *(int*)(a0 + 0x1860);
    if (v) {
        __builtin_vec_delete(v);
        *(int*)(a0 + 0x1860) = 0;
    }
}

/* clone */



__attribute__((section(".text.func_00276980")))
void func_00276980(struct cGameObj *self, int flags) {
    self->vtable = D_00447AD0;
    cGameObj__dtor(self, flags);
}

/* clone */




/* Destructor of the cGameObj subclass with method table D_00447E68. */
__attribute__((section(".text.func_00279D40")))
void func_00279D40(struct cGameObj *self, int flags) {
    self->vtable = D_00447E68;
    NoOp_279E70();
    func_0028EB88(self, flags);
}

/* clone */



__attribute__((section(".text.func_0027A2F8")))
void func_0027A2F8(struct cGameObj *self, int flags) {
    self->vtable = D_00447F70;
    cGameObj__dtor(self, flags);
}

/* clone */



__attribute__((section(".text.func_0027ADE8")))
void func_0027ADE8(struct cGameObj *self, int flags) {
    self->vtable = D_00448028;
    cGameObj__dtor(self, flags);
}

/* clone */




/* Destructor of the cGameObj subclass with method table D_004483A8: leave the solid-collision manager first. */
__attribute__((section(".text.func_0027DE18")))
void func_0027DE18(struct cGameObj *self, int flags) {
    self->vtable = D_004483A8;
    cCollisionSolidManage_ReleaseUnit_27E088(self);
    func_0028EB88(self, flags);
}

/* clone */



__attribute__((section(".text.func_00283660")))
void func_00283660(struct cGameObj *self, int flags) {
    self->vtable = D_00448890;
    cGameObj__dtor(self, flags);
}

/* clone */



__attribute__((section(".text.func_00284040")))
void func_00284040(struct cGameObj *self, int flags) {
    self->vtable = D_00448948;
    cGameObj__dtor(self, flags);
}
