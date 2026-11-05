/* sn-2.95.3-136 matched TU. */
#include "godhand/motion.h"
#include "godhand/cNode.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/mtx.h"
#include "godhand/CustomIDWork.h"

extern void func_002A84A8(void *a0, int a1, int a2, int a3, float f12);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern int D_00429DD8;
extern int SetField214PtrThenInit_1B6F38(void *obj);
extern char *InitFields_1B6E90(char *a0);
extern int func_00305908(void *self, int id, void *data);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern char D_00568288;

__attribute__((section(".text.func_002A8578")))
void func_002A8578(void *obj, int motA, int motB, int mode, float start, int sel, int keep) {
    int m = sel & 0xFFFF;
    if ((keep & 0xFFFF) == 0) {
        func_002A84A8(obj, motA, motB, mode, start);
    }
    setMotionInfo(obj, motA, motB, mode,
                  *(float*)((char*)obj + 0x5A8), start, m);
}

__attribute__((section(".text.cNode_setLocalTranslation")))
void cNode_setLocalTranslation(cNode *self, cVec *v)
{
    func_002B6400(self);
    cVec_copy3(&self->trans, v);
}

__attribute__((section(".text.cCollisionSolidManage_CreateSphere")))
void cCollisionSolidManage_CreateSphere(cCollisionSolidManage *self, struct cGameObj *owner, void *body, cVec *center, float radius) {
    cCollisionSolidUnit *unit = func_001346C8(self, owner);
    if (unit) {
        func_00134520(unit, body, center, radius);
    }
}

__attribute__((section(".text.CustomIDWork_SetNumber_1D5760")))
void CustomIDWork_SetNumber_1D5760(char *a0, int number) {
    CustomIDWork_SetNumber((CustomIDWork *)(a0 + 0x158), number);
}

__attribute__((section(".text.func_002998D8")))
void func_002998D8(int a0, int a1, long a2) {
    int *p = (int *)(a0 + 0x10000);
    int v1 = p[0];
    *(short *)((char *)p + 0x14) = (short)(a1 & 0xFF);
    p[1] = v1;
    p[0] = v1 + 0x10;
    *(long *)((char *)p + 8) = a2;
    *(int *)((char *)p + 0x10) = 0;
}

__attribute__((section(".text.func_00299908")))
void func_00299908(int a0) {
    char *base = (char *)(a0 + 0x10000);
    unsigned long v1 = *(unsigned short *)(base + 0x14);
    unsigned long v0 = *(unsigned int *)(base + 0x10);
    long *p = *(long **)(base + 4);
    v0 = v0 | (v1 << 15);
    v0 = v0 | ((unsigned long)0x8000 << 45);
    *p = v0;
    *(long *)((char *)(*(long **)(base + 4)) + 8) = *(long *)(base + 8);
}

__attribute__((section(".text.cNode_setLocalScale")))
void cNode_setLocalScale(cNode *self, cVec *v)
{
    func_002B6400(self);
    cVec_copy3(&self->scale, v);
}

__attribute__((section(".text.func_001C7DE0")))
int func_001C7DE0(void *a0) {
    *(int **)((char *)a0 + 0x214) = &D_00429DD8;
    return SetField214PtrThenInit_1B6F38(a0);
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_001C7D98")))
char *func_001C7D98(char *a0) {
    InitFields_1B6E90(a0);
    *(int*)(a0 + 0x214) = (int)&D_00429DD8;
    VU0_SQC2_VF0(a0, 0x610);
    VU0_SQC2_VF0(a0, 0x630);
    *(int*)(a0 + 0x5B0) |= 0x8;
    return a0;
}

__attribute__((section(".text.espSys_effDataRegist")))
void espSys_effDataRegist(void *self, int id, void *data) {
    func_00305908(self, id, data);
}

__attribute__((section(".text.func_002DB770")))
void func_002DB770(void)
{
    cActionButton_set(&D_00568288, 0xB, 0x13, 0x10, 0, 0, 0);
}

__attribute__((section(".text.MtxMulRotVec")))
void MtxMulRotVec(void *dst, void *src, cVec *rot, int order)
{
    float m[4][4];
    MtxInitRotVec(m, rot, order);
    MtxMultiply(dst, src, m);
}
