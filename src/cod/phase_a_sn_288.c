/* Four SN clones of cOmHitVolume_setupBox08x17x08.
 * Float setup is one store-swap from retail.
 * The tail is the same three-instruction miss as func_0018EAF8: the ring
 * pointer, the byte, and 7 are each materialized twice. */
extern void func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern void func_001C28A0(void *a0, void *a1, char a2, int a3);
extern int D_00574380;

#define PHASE_A_288(name, ca_lit, cb_lit, n6)                          \
    __attribute__((section(".text." #name)))                           \
    int name(char *p)                                                  \
    {                                                                  \
        float f[16];                                                   \
        float *m;                                                      \
        float *nv;                                                     \
        float *t;                                                      \
        void *slot;                                                    \
        float one, ca, cb;                                             \
        char *ring;                                                    \
        char six;                                                      \
        int seven;                                                     \
                                                                       \
        func_001B6FB8(p);                                              \
        one = 1.0f;                                                    \
        ca = (ca_lit);                                                 \
        cb = (cb_lit);                                                 \
        t = &f[4];                                                     \
        m = &f[8];                                                     \
        f[0] = ca;                                                     \
        f[1] = cb;                                                     \
        f[2] = ca;                                                     \
        f[4] = ca;                                                     \
        f[5] = cb;                                                     \
        f[6] = ca;                                                     \
        f[3] = one;                                                    \
        t[3] = one;                                                    \
        *(int *)&f[8] = 0;                                             \
        *(int *)&f[9] = 0;                                             \
        *(int *)&f[10] = 0;                                            \
        m[3] = one;                                                    \
        slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);     \
        *(void **)(p + 0x600) = slot;                                  \
        if (slot != 0) {                                               \
            nv = &f[12];                                               \
            *(int *)&f[12] = 0;                                        \
            *(int *)&f[13] = 0;                                        \
            *(int *)&f[14] = 0;                                        \
            nv[3] = one;                                               \
            func_001FD9D8(slot, p + 0x80, m, nv, t);                   \
        }                                                              \
        *(int *)(p + 0x5E8) = 0;                                       \
        *(int *)(p + 0x5E4) = 0;                                       \
        *(int *)(p + 0x5F0) = 0;                                       \
        *(short *)(p + 0x5F6) = 0;                                     \
        *(short *)(p + 0x54A) = 1;                                     \
        *(short *)(p + 0x548) = 1;                                     \
        *(short *)(p + 0x5F4) = -1;                                    \
        func_001C28A0(p,                                               \
            (ring = p + 0x620, *(int *)(p + 0x608) = (int)ring, ring), \
            (six = (n6), *(char *)(p + 0x60C) = six, six),             \
            (seven = 7, *(int *)(p + 0x5EC) = seven, seven));          \
        return 1;                                                      \
    }

PHASE_A_288(cOmHitVolume_setupBox08x17x08, 0.8f, 1.7f, 4)
PHASE_A_288(func_0019BF10, 1.4f, 2.2f, 8)
PHASE_A_288(func_0019E7A8, 0.8f, 1.15f, 6)
PHASE_A_288(func_0019EF18, 0.6f, 0.7f, 6)
