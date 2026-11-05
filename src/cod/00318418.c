/* sn-2.95.3-136 matched TU. */
#include "godhand/cObjBase.h"

extern char D_00450B28[];
extern char D_00450C38[];
extern char D_00450CE8[];
extern char D_00454D68[];
extern char D_0076A790[];

/* clone */



__attribute__((section(".text.func_00318418")))
void func_00318418(struct cObjBase *self, int flags) {
    self->vtable = (cVtEnt *)D_00450B28;
    cObjBase__dtor(self, flags);
}

/* clone */



__attribute__((section(".text.func_00318518")))
void func_00318518(struct cObjBase *self, int flags) {
    self->vtable = (cVtEnt *)D_00450C38;
    cObjBase__dtor(self, flags);
}

/* clone */



__attribute__((section(".text.func_0031A018")))
void func_0031A018(struct cObjBase *self, int flags) {
    self->vtable = (cVtEnt *)D_00450CE8;
    cObj__dtor(self, flags);
}

/* clone */



__attribute__((section(".text.func_00335B40")))
int func_00335B40(int *a0) {
    if (a0) {
        return *(int *)((char *)a0 + 36);
    }
    func_00335D40(&D_00454D68);
    return -1;
}

/* clone */



__attribute__((section(".text.func_00386D70")))
void func_00386D70(void) {
    unsigned char *base = D_0076A790;
    unsigned short *p = (unsigned short *)(base + 0x22);
    unsigned short v;
    v = *p;
    if (v & 0x1) {
        *(unsigned short *)(base + 0x22) = v & 0xFFFE;
        SeqNode_setSubByKind(1, 1);
        v = *(unsigned short *)(base + 0x22);
    }
    if (v & 0x2) {
        *(unsigned short *)(base + 0x22) = v & 0xFFFD;
        SeqNode_setSubByKind(1, 2);
    }
}
