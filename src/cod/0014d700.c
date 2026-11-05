#include "godhand/cDamageManage.h"
#include "godhand/cModel.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cDvd.h"

extern unsigned char D_004292F0[];

extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void func_00155D98(cModelNode *node, int a1, int a2);
/* Call func_00155D98 on every mesh node of the model. */
__attribute__((section(".text.ForwardToAllNodes_14D700")))
void ForwardToAllNodes_14D700(cModel *self, int a1, int a2) {
    cModelNode *node;
    node = cModel_getMeshPtr(self, 0);
    while (node != 0) {
        func_00155D98(node, a1, a2);
        node = node->next;
    }
}

extern void func_00155D60(cModelNode *node, int a1, int a2);
/* Call func_00155D60 on every mesh node of the model. */
__attribute__((section(".text.ForwardNodeUpdate_14D768")))
void ForwardNodeUpdate_14D768(cModel *self, int a1, int a2) {
    cModelNode *node;
    node = cModel_getMeshPtr(self, 0);
    while (node != 0) {
        func_00155D60(node, a1, a2);
        node = node->next;
    }
}

__attribute__((section(".text.ResetActorState_1BBF00")))
void ResetActorState_1BBF00(int a0, int a1)
{
    int v1;
    *(int *)(a0 + 0x214) = (int)D_004292F0;
    v1 = *(int *)(a0 + 0x600);
    if (v1 != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (cDamageUnit *)v1);
        *(int *)(a0 + 0x600) = 0;
    }
    cOmDoor_releaseObjCollision(a0);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.SetCustomIDSlotNumber_1F4C40")))
void SetCustomIDSlotNumber_1F4C40(int a0, unsigned short a1, int a2, int a3)
{
    unsigned int s0 = a1;
    int off;
    if (s0 < 7) {
        off = s0 * 0x7C + 0xC00;
        CustomIDWork_SetNumber((CustomIDWork *)(a0 + off), a2);
        SetCustomIDDispOneOrAll_1F4778(a0, (int)(s0 + 0x18), a3);
    }
}

__attribute__((section(".text.SetCustomIDSlotNumberAlt_1F5210")))
void SetCustomIDSlotNumberAlt_1F5210(int a0, unsigned short a1, int a2, int a3)
{
    unsigned int s0 = a1;
    int off;
    if (s0 < 7) {
        off = s0 * 0x7C + 0x2058;
        CustomIDWork_SetNumber((CustomIDWork *)(a0 + off), a2);
        SetCustomIDDispOneOrAll_1F4778(a0, (int)(s0 + 0x42), a3);
    }
}

/* The file number of name, or -1; its size goes in *size (key is not read). */
__attribute__((section(".text.FindEntryValue_1FF9C0")))
int FindEntryValue_1FF9C0(PathTable *table, const char *name, int *size, char *key)
{
    PathNode *node;
    if (size != 0) {
        *size = 0;
    }
    node = func_001FFA68(table, name);
    if (node == 0) {
        return -1;
    }
    if (size != 0) {
        *size = BuildPackedAddr_1FFD98(table, node);
    }
    return node->u.fileNo;
}
