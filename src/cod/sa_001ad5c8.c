extern unsigned char D_005FEE00[];
extern char D_00747B00[];
extern void cOmSub_initMove3_y(void *mv, void *p, int a2, void *a3, float f12, float f13, float f14);
extern void cOmSub_initMove1_pos(void *mv, void *p, int a2, int a3, float *pos, float f12, float f13);
extern void cOmSub_setVibration(void *mv, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *mv);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, void *f, int g, int h);

static inline void *GetPart1AD5C8(char *p, int i)
{
    int on[3];

    if (0 <= i && i < (on[0] = *(unsigned char *)(p + 0x2B4)))
        return (*(void ***)(p + 0x278))[i];
    return 0;
}

static inline void Move1AD5C8(char *p)
{
    float v[4];
    float z;

    v[0] = 0.0f;
    v[1] = *(float *)(p + 0x790);
    v[2] = 0.0f;
    v[3] = 1.0f;
    z = v[0];
    cOmSub_initMove1_pos(p + 0x630, p, -1, 0x3C, v, 0.2f, z);
    cOmSub_setVibration(p + 0x630, 0, 5, z, 1.0f, 2.0f);
}

static inline void Reset1AD5C8(char *p)
{
    *(unsigned char *)(p + 0x2F4) = 0;
    *(unsigned char *)(p + 0x2F5) = 0;
    *(unsigned char *)(p + 0x2F6) = 0;
    *(unsigned char *)(p + 0x2F7) = 0;
}

__attribute__((section(".text.func_001AD5C8")))
void func_001AD5C8(char *p)
{
    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x60D) == 0) {
            Reset1AD5C8(p);
            break;
        }
        *(unsigned char *)(p + 0x60E) = 1;
        if (*(int *)(p + 0x600) == 0) {
            cOmSub_initMove3_y(p + 0x630, p, -1, D_00747B00, -0.02f, -*(float *)(p + 0x790), 0.2f);
        } else {
            Move1AD5C8(p);
        }
        *(int *)(p + 0x5B8) |= 0x100;
        if (GetPart1AD5C8(p, 1))
            *(int *)((char *)GetPart1AD5C8(p, 1) + 0x104) = 0;
        if (GetPart1AD5C8(p, 2))
            *(int *)((char *)GetPart1AD5C8(p, 2) + 0x104) = 0;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
        *(unsigned char *)(p + 0x2F5) = 1;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x82, p, 0, 0, 0, 0);
    case 1:
        if (cOmSub_move(p + 0x630))
            return;
        *(unsigned char *)(p + 0x60D) = 0;
        *(unsigned char *)(p + 0x60E) = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x83, p, 0, 0, 0, 0);
        Reset1AD5C8(p);
        break;
    }
}
