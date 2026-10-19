/* sn-2.95.3-136 (SETTING: -fno-gcse, like 0018a680.c): func_001B57E8, spawn two 0x3B6 helper objects, damage-take volume, flag parts 1..5 with 0x8/0x10. */
extern void func_001B6FB8(void *a0);
extern char *CreateObj(int a0, int a1);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern int cDamageUnit_SetDamageCollActive(void *unit, int on);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00574380;

static inline void Wake(char *o)
{
    char *v1 = *(char **)(o + 0x214);
    int (*fn)(char *) = *(int (**)(char *))(v1 + 0x44);
    short off = *(short *)(v1 + 0x40);
    fn(o + off);
}

__attribute__((section(".text.func_001B57E8")))
int func_001B57E8(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, two;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    *(char **)(p + 0x604) = CreateObj(0x3B6, 0xFFFF);
    *(char **)(p + 0x608) = CreateObj(0x3B6, 0xFFFF);
    if (*(char **)(p + 0x604)) {
        Wake(*(char **)(p + 0x604));
        *(unsigned int *)(*(char **)(p + 0x604) + 0x62C) &= 0x7FFFFFFF;
    }
    if (*(char **)(p + 0x608)) {
        Wake(*(char **)(p + 0x608));
        *(unsigned int *)(*(char **)(p + 0x608) + 0x62C) &= 0x7FFFFFFF;
    }
    one = 1.0f;
    two = 2.0f;
    t = &f[4];
    m = &f[8];
    f[0] = one;
    f[1] = two;
    f[5] = two;
    f[2] = one;
    f[3] = one;
    f[4] = one;
    f[6] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
        cDamageUnit_SetDamageCollActive(*(void **)(p + 0x600), 1);
    }
    *(short *)(p + 0x54A) = *(short *)(p + 0x548) = 10;
    cOmBase_setMeshDispFromLayer(p, 0, 1);
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (!(i < 6 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    *(int *)(p + 0x5B8) = (*(int *)(p + 0x5B8) & ~1) | 0x80;
    return 1;
}
