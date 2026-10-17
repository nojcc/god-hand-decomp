/* Near-miss, not registered in compile_config.json and not linked.
 * Eight SN clones of func_0018EAF8. The damage-volume setup matches retail.
 * The tail is three instructions long: the pointer, 6, and 7 are each
 * materialized twice (once for the store, once for the call). */
extern void func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern void func_001C28A0(void *a0, void *a1, int a2, int a3);
extern int D_00574380;

#define PHASE_A_300(name)                                              \
    int name(char *p)                                                  \
    {                                                                  \
        float f[16];                                                   \
        float *m;                                                      \
        float *nv;                                                     \
        float *t;                                                      \
        void *slot;                                                    \
        float one, ca, cb, cc;                                         \
        float *ring;                                                   \
        int hp;                                                        \
        int six;                                                       \
        int seven;                                                     \
        int neg;                                                       \
                                                                       \
        func_001B6FB8(p);                                              \
        one = 1.0f;                                                    \
        ca = 0.4f;                                                     \
        cb = 1.2218f;                                                  \
        cc = 4.672f;                                                   \
        t = &f[4];                                                     \
        m = &f[8];                                                     \
        f[0] = ca;                                                     \
        f[1] = cb;                                                     \
        f[2] = cc;                                                     \
        f[4] = ca;                                                     \
        f[5] = cb;                                                     \
        f[6] = cc;                                                     \
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
        hp = 1;                                                        \
        ring = p + 0x620;                                              \
        six = 6;                                                       \
        seven = 7;                                                     \
        neg = -1;                                                      \
        *(int *)(p + 0x5E8) = 0;                                       \
        *(int *)(p + 0x5E4) = 0;                                       \
        *(int *)(p + 0x5F0) = 0;                                       \
        *(short *)(p + 0x5F6) = 0;                                     \
        *(short *)(p + 0x54A) = hp;                                    \
        *(int *)(p + 0x608) = (int)ring;                               \
        *(char *)(p + 0x60C) = six;                                    \
        *(int *)(p + 0x5EC) = seven;                                   \
        *(short *)(p + 0x548) = hp;                                    \
        *(short *)(p + 0x5F4) = neg;                                   \
        func_001C28A0(p, ring, six, seven);                            \
        return 1;                                                      \
    }

PHASE_A_300(func_0018EAF8)
PHASE_A_300(func_00191B98)
PHASE_A_300(func_00192A98)
PHASE_A_300(cOmHitVolume_setupBox13x19x08)
PHASE_A_300(func_00193A80)
PHASE_A_300(cOmHitVolume_setupBox24x12x02)
PHASE_A_300(func_0019DAA8)
PHASE_A_300(cOmHitVolume_setupThinBox)
