/* sn-2.95.3-136: func_001B67D0, enemy setup with a three-sphere (radius 0.25) damage-give volume along z, the give attributes 0x41/0x14/0xF0 and a forward direction. */
extern void func_001B6FB8(char *p);
extern void *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int cDamageUnit_AddDamageCollSphere(void *unit, void *mtx, float *ofs, float r);
extern int cDamageUnit_SetDamageCollActive(void *unit, int on);
extern char D_00574380[];

static inline void Copy3_1B67D0(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

__attribute__((section(".text.func_001B67D0")))
int func_001B67D0(char *p)
{
    float f[16];
    float *t;
    float *a;
    float *b;
    void *give;
    float r;
    char *u;

    func_001B6FB8(p);
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.5f;
    f[3] = 1.0f;
    t = &f[4];
    a = t;
    f[4] = 0.0f;
    a[1] = 0.0f;
    a[2] = 0.0f;
    a[3] = 1.0f;
    t = &f[8];
    b = t;
    f[8] = 0.0f;
    b[1] = 0.0f;
    b[2] = -0.5f;
    b[3] = 1.0f;
    t = &f[12];
    f[12] = 0.0f;
    f[13] = 0.0f;
    t[2] = 1.0f;
    t[3] = 1.0f;
    give = cDamageManage_CreateDamageGive(D_00574380, 2, p);
    *(void **)(p + 0x620) = give;
    if (give != 0) {
        r = 0.25f;
        cDamageUnit_AddDamageCollSphere(give, p + 0x80, f, r);
        cDamageUnit_AddDamageCollSphere(*(void **)(p + 0x620), p + 0x80, a, r);
        cDamageUnit_AddDamageCollSphere(*(void **)(p + 0x620), p + 0x80, b, r);
        cDamageUnit_SetDamageCollActive(*(void **)(p + 0x620), 0);
        **(unsigned int **)(p + 0x620) |= 1;
        *(short *)(*(char **)(p + 0x620) + 0x46) = 0x41;
        *(int *)(*(char **)(p + 0x620) + 0x4C) = 0x14;
        u = *(char **)(p + 0x620);
        *(short *)(u + 0x44) = 0xF0;
        *(int *)(u + 0x40) = 0;
        Copy3_1B67D0((float *)(*(char **)(p + 0x620) + 0x10), &f[12]);
    }
    *(int *)(p + 0x5B8) &= ~1;
    return 1;
}
