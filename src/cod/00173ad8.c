/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cModel.h"

extern void func_001B6FB8(void *a0);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_00173AD8")))
int func_00173AD8(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0017C708")))
int func_0017C708(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_00186A80")))
int func_00186A80(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0018CF88")))
int func_0018CF88(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0018DD40")))
int func_0018DD40(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}

/* sn-2.95.3-136, -f=-fno-gcse */







__attribute__((section(".text.func_0019C670")))
int func_0019C670(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    void *slot;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.02f;
    cb = 1.288f;
    m = &v[2];
    v[0].x = ca;
    v[0].y = cb;
    v[1].y = cb;
    v[0].z = ca;
    v[0].w = one;
    v[1].x = ca;
    v[1].w = one;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    v[1].z = ca;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        cDamageUnit_AddDamageCollCylinder(slot, p + 0x80, m, nv, v[1].y, v[1].x * 0.5f);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&v[1] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&v[1] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
