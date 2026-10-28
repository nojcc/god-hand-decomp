/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/player.h"
#include "godhand/cObj.h"
#include "godhand/cObjBase.h"

extern unsigned char D_003C3CFC;
extern void func_0030ECF8(int a0);
extern void *cHeap_allocFirstFit(int a0, int a1, int a2);
extern void Slots_runHandlerForAll(int a0, int a1);
extern void ForEachSlotRunHandler(int a0, int a1);

__attribute__((section(".text._MemoryAlloc")))
void *_MemoryAlloc(int a0, int a1, int a2) {
    if (D_003C3CFC == 0) {
        func_0030ECF8(0);
    }
    return cHeap_allocFirstFit(a2, a0, a1);
}

__attribute__((section(".text.KillEffect")))
void KillEffect(void *owner, int handle, int arg) {
    /* The slot tables keep the owner as an int word. */
    int key = (int)owner;

    if (owner == 0 && handle == -1) {
        return;
    }
    switch (arg) {
    case 0:
        Slots_runHandlerForAll(key, handle);
        break;
    case 1:
        ForEachSlotRunHandler(key, handle);
        break;
    case 2:
        ForEachSlotRunHandler(key, handle);
        Slots_runHandlerForAll(key, handle);
        break;
    }
}

/* Makes the object of actor id kind from data id and registers it. */
__attribute__((section(".text.CreateObj")))
cGameObj *CreateObj(int kind, int id)
{
    return (cGameObj *)func_0030FB20(kind, func_0030FAC8(kind, id));
}
