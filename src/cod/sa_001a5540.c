extern char D_005864F0[];
extern char D_00747B00[];
extern float cEmManage_GetSpeedRate(void *a0);
extern void SetMotionStep(void *a0, float f12);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int cDamageUnit_SetDamageCollActive(void *unit, int on);
extern int moveMotion(void *a0);
extern void VecRotVec(float *out, float *in, float *rot, int order);
extern int cOmBase_checkDamage(void *self, void *take);

typedef struct {
    short delta;
    short idx;
    void (*fn)(void *, void *);
} VEntry;

static inline void VCall(char *o, int slot, void *arg)
{
    VEntry *e = &(*(VEntry **)(o + 0x214))[slot];
    e->fn(o + e->delta, arg);
}

static inline void SetV3(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}

static inline void SetV4(float *d, float x, float y, float z, float w)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = w;
}

__attribute__((section(".text.func_001A5540")))
void func_001A5540(char *self)
{
    float rate;
    float rot[4];
    char *mot;

    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(self + 0x5A8) = rate;
    SetMotionStep(self, rate);
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0:
        VCall(self, 14, D_00747B00);
        VCall(self, 15, D_00747B00);
        mot = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(mot + 0xC) + (int)mot, *(int *)(mot + 0x10) + (int)mot, 0.0f, 0, 0, 0);
        SetEffect(1, 2, self, 0, -1, 0xFFFFFFFF);
        if (*(void **)(self + 0x620))
            cDamageUnit_SetDamageCollActive(*(void **)(self + 0x620), 1);
        *(unsigned char *)(self + 0x2F5) = 1;
        *(short *)(self + 0x628) = 12;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
        /* fallthrough */
    case 1:
        moveMotion(self);
        if (--*(short *)(self + 0x628) < 0) {
            if (*(void **)(self + 0x620))
                cDamageUnit_SetDamageCollActive(*(void **)(self + 0x620), 0);
            *(short *)(self + 0x628) = 0x3A;
            *(unsigned char *)(self + 0x2F5) = 2;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        break;
    case 2:
        moveMotion(self);
        if (--*(short *)(self + 0x628) < 0) {
            if (*(void **)(self + 0x620))
                cDamageUnit_SetDamageCollActive(*(void **)(self + 0x620), 1);
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F5) = 3;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        break;
    case 3:
        if (moveMotion(self)) {
            SetV3((float *)(self + 0x5C0), 0.0f, 0.0f, 10.0f);
            SetV4(rot, 0.0f, 0.86f, 0.0f, 1.0f);
            VecRotVec((float *)(self + 0x5C0), (float *)(self + 0x5C0), rot, 0);
            *(unsigned char *)(self + 0x2F4) = 1;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        break;
    }
    if (cOmBase_checkDamage(self, *(void **)(self + 0x624)) == 1 && *(short *)(self + 0x54A) <= 0) {
        *(unsigned char *)(self + 0x2F4) = 1;
        *(int *)(self + 0x5B0) |= 1;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
    }
}
