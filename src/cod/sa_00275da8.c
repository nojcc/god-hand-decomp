/* sn-2.95.3-136: func_00275DA8, rebuild collision unit/spheres and the three damage-take spheres for enemy type 0x265. */
extern int ClearAndResetFields_1FE278(void *a0, int a1);
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern int cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);
extern int D_00462FC0;
extern char D_00574380[];
struct sph { int a; float b; float c; float d; };

__attribute__((section(".text.func_00275DA8")))
void func_00275DA8(char *s1)
{
    struct sph q;
    unsigned int i;
    int *p;
    int n;
    int base;

    if ((*(int *)(s1 + 0x564) ^ 0x265) != 0)
        return;
    if (ClearAndResetFields_1FE278(D_00574380, *(int *)(s1 + 0x698))) {
        *(int *)(s1 + 0x698) = 0;
        for (i = 0; i < 5; i++)
            ((int *)(s1 + 0x69C))[i] = -1;
    }
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, s1);
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 0, 0.2f);
    q.a = 0;
    q.b = 0.5f;
    q.c = 0.0f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, &q, 1.8f);
    q.a = 0;
    q.b = 0.5f;
    q.c = -0.8f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, &q, 1.0f);
    q.a = 0;
    q.b = 0.5f;
    q.c = -1.4f;
    q.d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, &q, 1.0f);
    *(int *)(s1 + 0x698) = cDamageManage_CreateDamageTake(D_00574380, s1, 1);

    n = *(unsigned char *)(s1 + 0x2B4);
    q.a = n;
    {
        int k = 2;
        if (k < n)
            base = *(int *)(*(int *)(s1 + 0x278) + 0x8);
        else
            base = 0;
    }
    q.a = 0;
    q.b = -0.3f;
    q.c = 0.0f;
    q.d = 1.0f;
    *(int *)(s1 + 0x69C) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x698), base + 0x80, &q,
                                                           *(float *)(s1 + 0x118) * 0.7f);

    n = *(unsigned char *)(s1 + 0x2B4);
    q.a = n;
    {
        int k = 0x13;
        if (k < n)
            base = *(int *)(*(int *)(s1 + 0x278) + 0x4C);
        else
            base = 0;
    }
    q.a = 0;
    q.b = -0.3f;
    q.c = 0.4f;
    q.d = 1.0f;
    *(int *)(s1 + 0x6A0) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x698), base + 0x80, &q,
                                                           *(float *)(s1 + 0x118) * 0.8f);

    n = *(unsigned char *)(s1 + 0x2B4);
    q.a = n;
    {
        int k = 0x20;
        if (k < n)
            base = *(int *)(*(int *)(s1 + 0x278) + 0x80);
        else
            base = 0;
    }
    q.a = 0;
    q.b = 0.0f;
    q.c = 0.0f;
    q.d = 1.0f;
    *(int *)(s1 + 0x6A4) = cDamageUnit_AddDamageCollSphere(*(int *)(s1 + 0x698), base + 0x80, &q,
                                                           *(float *)(s1 + 0x118) * 0.7f);
    *(int *)(s1 + 0x6A8) = -1;
    *(int *)(s1 + 0x6AC) = -1;
}
