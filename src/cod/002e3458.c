/* sn-2.95.3-136 matched TU. */
#include "godhand/cNode.h"

extern char D_0044E238[];
extern char D_0044E6D8[];
extern char D_0044E770[];
extern char D_0044E8C8[];
extern char D_0044F078[];
extern char D_0044F308[];
extern char D_0044F4F8[];
extern char D_0044F598[];
extern char D_0044F6D8[];

/* clone */



__attribute__((section(".text.func_002E3458")))
void func_002E3458(cNode *self, int flags) {
    self->vt = D_0044E238;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002E9B40")))
void func_002E9B40(cNode *self, int flags) {
    self->vt = D_0044E6D8;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002EA8E0")))
void func_002EA8E0(cNode *self, int flags) {
    self->vt = D_0044E770;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002EBF70")))
void func_002EBF70(cNode *self, int flags) {
    self->vt = D_0044E8C8;
    BlockOwner_dtor((struct BlockOwner *)self, flags);
}

/* clone */



__attribute__((section(".text.func_002F3E40")))
void func_002F3E40(cNode *self, int flags) {
    self->vt = D_0044F078;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002F5328")))
void func_002F5328(cNode *self, int flags) {
    self->vt = D_0044F308;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002F6230")))
void func_002F6230(cNode *self, int flags) {
    self->vt = D_0044F4F8;
    BlockOwner_dtor((struct BlockOwner *)self, flags);
}

/* clone */



__attribute__((section(".text.func_002F6CD0")))
void func_002F6CD0(cNode *self, int flags) {
    self->vt = D_0044F598;
    func_002FBE28(self, flags);
}

/* clone */



__attribute__((section(".text.func_002F7178")))
void func_002F7178(cNode *self, int flags) {
    self->vt = D_0044F6D8;
    BlockOwner_dtor((struct BlockOwner *)self, flags);
}

/* clone */


__attribute__((section(".text.func_002FFB10")))
void *func_002FFB10(void *a0) {
    void *r = a0;
    if (r)
        r = func_002E3480(a0);
    return r;
}
