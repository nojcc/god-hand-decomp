/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageManage.h"
#include "godhand/cDamageUnit.h"

extern void func_001B6FB8(void *a0);
extern void func_001BFB28(void *a0);

__attribute__((section(".text.func_001705D0")))
int func_001705D0(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 3.1f;
    cb = 2.91f;
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
    v[2].y = v[1].y * -0.5f;
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

__attribute__((section(".text.func_00170860")))
int func_00170860(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 3.076f;
    cb = 0.774f;
    cc = 0.764f;
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
    v[2].y = v[1].y * -0.5f;
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

__attribute__((section(".text.func_00170AF0")))
int func_00170AF0(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 2.766f;
    cb = 0.774f;
    cc = 0.764f;
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
    v[2].y = v[1].y * -0.5f;
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

__attribute__((section(".text.func_00170D80")))
int func_00170D80(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 3.292f;
    cb = 0.774f;
    cc = 0.698f;
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
    v[2].y = v[1].y * -0.5f;
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

__attribute__((section(".text.func_001833E0")))
int func_001833E0(char *p)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 2.7f;
    cb = 1.7f;
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
    v[2].y = v[1].y * -0.5f;
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
