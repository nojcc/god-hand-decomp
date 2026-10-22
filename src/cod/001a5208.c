/* func_001A5208: gimmick init (damage give/take spheres, solid sphere, mesh layers). sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cOmHitVolumeSetup.h"
extern char D_00574380[];
extern char D_00462FC0[];
extern char D_00747B00[];
extern void cCollisionSolidManage_CreateUnit(void *mgr, void *owner, int kind, float radius);
extern void cCollisionSolidManage_CreateSphere(void *mgr, void *owner, void *body, void *centre, float radius);
extern void SetField380Bit2000ForTag_1B7300(void *self, int tag, int on);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);

static inline void VCall(char *o, int slot, void *arg)
{
    cVtEnt *e = &(*(cVtEnt **)(o + 0x214))[slot];
    ((void (*)(void *, void *))e->pfn)(o + e->delta, arg);
}

__attribute__((section(".text.func_001A5208")))
int func_001A5208(char *self)
{
    char buf[0x20];
    void *u;
    char *part;
    char *p2;
    char *p3;
    float *r;
    char *mgr;

    func_001B6FB8(self);
    u = cDamageManage_CreateDamageGive(D_00574380, 2, self);
    *(void **)(self + 0x620) = u;
    if (u) {
        part = (char *)cOmBase_childAt((cOmBase *)self, (int *)buf, 0);
        r = (float *)(buf + 0x10);
        *(int *)(buf + 0x10) = 0;
        *(int *)(buf + 0x14) = 0;
        *(int *)(buf + 0x18) = 0;
        r[3] = 1.0f;
        cDamageUnit_AddDamageCollSphere(*(void **)(self + 0x620), part + 0x80, r, 2.0f);
        *(short *)(*(char **)(self + 0x620) + 0x46) = 0x55;
        *(int *)(*(char **)(self + 0x620) + 0x4C) = 100;
        cDamageUnit_SetDamageCollActive(*(void **)(self + 0x620), 0);
    }
    u = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    *(void **)(self + 0x624) = u;
    if (u) {
        p2 = (char *)cOmBase_childAt((cOmBase *)self, (int *)buf, 0);
        ((float *)buf)[3] = 1.0f;
        *(int *)(buf + 0) = 0;
        *(int *)(buf + 4) = 0;
        *(int *)(buf + 8) = 0;
        cDamageUnit_AddDamageCollSphere(*(void **)(self + 0x624), p2 + 0x80, buf, 2.5f);
        **(int **)(self + 0x624) |= 1;
        cDamageUnit_SetDamageCollActive(*(void **)(self + 0x624), 1);
    }
    *(short *)(self + 0x54A) = *(short *)(self + 0x548) = 0x14;
    mgr = D_00462FC0;
    cCollisionSolidManage_CreateUnit(mgr, self, 0, 0.3f);
    p3 = (char *)cOmBase_childAt((cOmBase *)self, (int *)buf, 0);
    ((float *)buf)[3] = 1.0f;
    *(int *)(buf + 0) = 0;
    *(int *)(buf + 4) = 0;
    *(int *)(buf + 8) = 0;
    cCollisionSolidManage_CreateSphere(mgr, self, p3 + 0x80, buf, 1.9f);
    SetField380Bit2000ForTag_1B7300(self, 0, 0);
    SetField380Bit2000ForTag_1B7300(self, 0x40, 0);
    *(int *)(self + 0x250) |= 0x10000;
    cOmBase_setMeshDispFromLayer(self, 0, 1);
    cOmBase_setMeshDispFromLayer(self, 0x40, 0);
    *(int *)(self + 0x5B8) |= 8;
    VCall(self, 14, D_00747B00);
    VCall(self, 15, D_00747B00);
    return 1;
}
