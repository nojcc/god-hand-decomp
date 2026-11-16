/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"

extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern void func_001B76D8(void *a0);
extern void cOmBase_setMeshDispFromLayer(void *model, int layer, int show);
extern void func_001B6FB8(void *a0);
extern void func_001BFB28(void *a0);

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_00194480 { short f0; short f2; short f4; short f6; };
struct Table_func_00194480 { struct Entry_func_00194480 e[1]; };



extern struct Table_func_00194480 D_003BDB48;



__attribute__((section(".text.UpdatePhaseWithHitCheckB")))
void UpdatePhaseWithHitCheckB(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB48 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB48 + i8 + 4);
    }
    f0 = D_003BDB48.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cCollisionSolidManage_ChkHit(&D_00462FC0, (struct cGameObj *)s0);
    func_001B76D8(s0);
}

/* Phase-machine tick: run the handler picked by the state byte, then the shared post-update steps. */
struct Entry_func_001A5470 { short f0; short f2; short f4; short f6; };
struct Table_func_001A5470 { struct Entry_func_001A5470 e[1]; };



extern struct Table_func_001A5470 D_003BDB98;



__attribute__((section(".text.UpdatePhaseWithHitCheckC")))
void UpdatePhaseWithHitCheckC(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDB98 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDB98 + i8 + 4);
    }
    f0 = D_003BDB98.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    cCollisionSolidManage_ChkHit(&D_00462FC0, (struct cGameObj *)s0);
    func_001B76D8(s0);
}

/* Show the mesh layer picked by arg1 (0 or 1) and hide the other; arg1 == 4 plays the sound effect and spawns effect 0x298 instead. */





__attribute__((section(".text.SetMeshLayerAndPlayEffect")))
void SetMeshLayerAndPlayEffect(void *self, int arg1)
{
    cOmBase_setMeshDispFromLayer(self, 0x28, 0);
    cOmBase_setMeshDispFromLayer(self, 0x29, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(self, 0x28, 1);
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0x29, 1);
        break;
    case 4:
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x113, self, 0, 0, 0, 0);
        SetEffect(0x298, 4, self, 0, -1, 0xFFFFFFFF);
        break;
    }
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.SpawnDamageTakeVolumeC")))
int SpawnDamageTakeVolumeC(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 0.90639997f;
    cb = 2.0f;
    cc = 0.2f;
    t = &v[1];
    m = &v[2];
    v[0].x = ca;
    v[1].x = ca;
    v[0].y = cb;
    v[0].z = cc;
    v[1].z = cc;
    v[1].y = cb;
    v[0].w = one;
    t->w = one;
    v[2].x = 0.0f;
    v[2].z = 0.0f;
    v[2].y = v[0].y * -0.5f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.SpawnDamageTakeVolumeD")))
int SpawnDamageTakeVolumeD(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.6f;
    cb = 1.5f;
    cc = 0.2f;
    t = &v[1];
    m = &v[2];
    v[0].x = ca;
    v[1].x = ca;
    v[0].y = cb;
    v[0].z = cc;
    v[1].z = cc;
    v[1].y = cb;
    v[0].w = one;
    t->w = one;
    v[2].x = 0.0f;
    v[2].z = 0.0f;
    v[2].y = v[0].y * -0.5f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.SpawnDamageTakeVolumeE")))
int SpawnDamageTakeVolumeE(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 0.84f;
    cb = 1.356f;
    cc = 0.84f;
    t = &v[1];
    m = &v[2];
    v[0].x = ca;
    v[0].z = cc;
    v[0].y = cb;
    v[1].x = ca;
    v[1].z = cc;
    v[1].y = cb;
    v[0].w = one;
    t->w = one;
    v[2].x = 0.0f;
    v[2].z = 0.0f;
    v[2].y = v[0].y * -0.5f;
    m->w = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}
