#include "godhand/cObjBase.h"

/* sn-2.95.3-136 matched TU. */

extern int D_0041EBE8;
extern char D_0044AE28[];
extern void (*D_003C4908)(void);
extern void func_00329EA8(int a0);
extern void func_0032B300(int a0, int a1);
extern void func_003298C0(int a0);
extern void func_0031C900(int a0);
extern int D_003FA62C;
extern void __malloc_lock(int a0);
extern void __malloc_unlock(int a0);
extern void func_0015EAC8(char *work);
extern void func_002D5890(int a0, int a1);
extern void func_002D5440(int a0, int a1);

extern int cObj__dtor(struct cObjBase *self);
/* The cObjBase part of the destructor: put this class's vtable back, then run
 * the cObj destructor. */
__attribute__((section(".text.cObjBase__dtor")))
int cObjBase__dtor(struct cObjBase *self) {
    self->vtable = (cVtEnt *)&D_0041EBE8;
    return cObj__dtor(self);
}

__attribute__((section(".text.cGameObj__dtor")))
int cGameObj__dtor(int a0) {
    *(int*)((char*)a0+0x214) = (int)D_0044AE28;
    return cObjBase__dtor(a0);
}

__attribute__((section(".text.func_00201228")))
int func_00201228(int a0, int a1) {
    return func_003A52F0(a1, 0, 0x88);
}

__attribute__((section(".text.func_00320280")))
void func_00320280(void) {
    D_003C4908();
}

__attribute__((section(".text.func_00380EB0")))
void func_00380EB0(int a0, int a1, int a2)
{
    int t;
    func_00329EA8(*(int*)((char*)a1+0x30));
    if (*(unsigned char*)((char*)a2+0x0) != 0) {
        *(char*)((char*)a2+0x0) = 0;
        func_0032B300(*(int*)((char*)a1+0x30), 0);
    }
    func_003298C0(*(int*)((char*)a1+0x30));
    t = *(int*)((char*)a1+0x34);
    *(int*)((char*)a1+0x30) = 0;
    func_0031C900(t);
}

__attribute__((section(".text.func_003A7C70")))
int func_003A7C70(int a0)
{
    int r;
    __malloc_lock(D_003FA62C);
    r = func_003AC2F8(D_003FA62C, a0);
    __malloc_unlock(D_003FA62C);
    return r;
}


/* Remember the shadow data and its two work areas, and initialise each work
 * area. */
__attribute__((section(".text.cObjBase_KageInit")))
void cObjBase_KageInit(cObjBase *self, char *work, void *shadowData)
{
    int offset = 0;
    int left = 1;
    self->shadowData = shadowData;
    self->kageWork = work;
    do {
        left = left - 1;
        func_0015EAC8(self->kageWork + offset);
        offset += 0x750;
    } while (left >= 0);
}

__attribute__((section(".text.cTaskManager_execute")))
int cTaskManager_execute(int a0, int a1, int a2)
{
    int *v1 = *(int**)((char*)a0+0x30);
    int (*fp)(int, int) = (int (*)(int, int))v1[5];
    int s0 = fp(a0 + *(short*)((char*)v1+0x10), a2);
    if (s0 != -1) {
        func_002D5890(*(int*)((char*)a0+0x0) + s0 * 0x58, a1);
    }
    func_002D5440(a0, s0);
    return s0;
}
