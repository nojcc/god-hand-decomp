/* sn-2.95.3-136: enemy setup: flag every mesh, pick a random facing, then build the two damage-give volumes (a box on
 * the body at 0x600, a sphere on part 0 at 0x608), both inactive, with their hit kinds and hit vector. */
extern void func_001B6FB8(char *p);
extern char *cModel_getMeshPtr(char *p, unsigned int i);
extern unsigned int GetField_2B1_14B638(char *p);
extern float fRand1_1(void);
extern char *cDamageManage_CreateDamageGive(void *mgr, int kind, void *owner);
extern int func_001FD9D8(void *slot, void *mtx, float *ofs, float *rot, float *size);
extern int cDamageUnit_AddDamageCollSphere(void *slot, void *mtx, float *ofs, float r);
extern void cDamageUnit_SetDamageCollActive(void *slot, int on);
extern void cDamageGive_SetDmgGiveHitVec(void *slot, void *vec);
extern char D_00574380[];
extern char D_00747B00[];

__attribute__((section(".text.func_001B90D0")))
int func_001B90D0(char *p)
{
    float f[12];
    float *g;
    float *h;
    unsigned int i;
    char *d;
    char *e;
    char *q;
    char *part;
    int n;

    func_001B6FB8(p);
    for (i = 0; i < GetField_2B1_14B638(p); i++)
        *(int *)(cModel_getMeshPtr(p, i) + 0x380) |= 1;
    *(int *)(p + 0x580) = 0;
    *(int *)(p + 0x584) = 0;
    *(int *)(p + 0x588) = 0;
    *(float *)(p + 0x620) = fRand1_1() * 3.1415927f;
    d = cDamageManage_CreateDamageGive(D_00574380, 1, p);
    *(char **)(p + 0x600) = d;
    if (d != 0) {
        g = &f[4];
        h = &f[8];
        f[1] = -0.5f;
        f[0] = 0.0f;
        f[2] = 0.0f;
        f[3] = 1.0f;
        f[4] = 0.0f;
        f[5] = 0.0f;
        f[6] = 0.0f;
        g[3] = 1.0f;
        f[8] = 0.5f;
        h[2] = 0.5f;
        h[1] = 1.0f;
        h[3] = 1.0f;
        *(int *)(p + 0x604) = func_001FD9D8(d, p + 0x80, f, g, h);
        cDamageUnit_SetDamageCollActive(*(char **)(p + 0x600), 0);
        *(short *)(*(char **)(p + 0x600) + 0x46) = 0x41;
        *(int *)(*(char **)(p + 0x600) + 0x4C) = 0x14;
        cDamageGive_SetDmgGiveHitVec(*(char **)(p + 0x600), D_00747B00);
        q = *(char **)(p + 0x600);
        *(int *)(q + 0x40) = -1;
        *(short *)(q + 0x44) = 0;
    }
    e = cDamageManage_CreateDamageGive(D_00574380, 0, p);
    *(char **)(p + 0x608) = e;
    if (e != 0) {
        *(int *)&f[0] = n = *(unsigned char *)(p + 0x2B4);
        if (n != 0)
            part = *(char **)*(char ***)(p + 0x278);
        else
            part = 0;
        f[3] = 1.0f;
        f[0] = 0.0f;
        f[1] = 0.0f;
        f[2] = 0.0f;
        *(int *)(p + 0x60C) = cDamageUnit_AddDamageCollSphere(*(char **)(p + 0x608), part + 0x80, f, 0.4f);
        cDamageUnit_SetDamageCollActive(*(char **)(p + 0x608), 0);
        *(short *)(*(char **)(p + 0x608) + 0x46) = 0x2E;
        *(int *)(*(char **)(p + 0x608) + 0x4C) = 0x14;
        cDamageGive_SetDmgGiveHitVec(*(char **)(p + 0x608), D_00747B00);
        q = *(char **)(p + 0x608);
        *(int *)(q + 0x40) = -1;
        *(short *)(q + 0x44) = 0;
    }
    *(float *)(p + 0x624) = 210.0f;
    *(int *)(p + 0x62C) = 0;
    return 1;
}
