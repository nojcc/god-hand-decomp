/* sn-2.95.3-136: walk-to-target step: start the walk motion and turn to the target, then advance
 * until the object stalls or reaches the target, and push the null speed. */
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern void moveMotion(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);

__attribute__((section(".text.func_00114AC0")))
void func_00114AC0(char *s)
{
    char *m;
    float *src;
    float *dst;
    float r;
    float d;

    switch (*(unsigned char *)(s + 0x2F6)) {
    case 0:
        *(short *)(s + 0x5E0) = 0;
        *(short *)(s + 0x5E2) = 0;
        m = *(char **)(s + 0x304);
        func_002A8578(s, *(int *)(m + 0x48) + (int)m, *(int *)(m + 0x4C) + (int)m, 3, 0.0f, 0, 0);
        cGameObj_SetTgtTurn(s, s + 0x580, 3.1415927f);
        *(int *)(s + 0x15B4) = 0;
        *(float *)(s + 0x1590) = 99999.9f;
        *(float *)(s + 0x1594) = 99999.9f;
        *(float *)(s + 0x1598) = 99999.9f;
        *(unsigned char *)(s + 0x2F6) += 1;
    case 1:
        *(unsigned short *)(s + 0x434) |= 8;
        moveMotion(s);
        d = capVu0MagnitudeSqXZ(s + 0x1590, s + 0x490);
        r = *(float *)(s + 0x1588) * 0.5f;
        if (d < r * r) {
            if (++*(int *)(s + 0x15B4) >= 2) {
                *(unsigned char *)(s + 0x2F4) = 0;
                *(unsigned char *)(s + 0x2F5) = 0;
                *(unsigned char *)(s + 0x2F6) = 0;
                *(unsigned char *)(s + 0x2F7) = 0;
            }
        } else {
            *(int *)(s + 0x15B4) = 0;
        }
        dst = (float *)(s + 0x1590);
        src = (float *)(s + 0x490);
        if (dst != src) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
        }
        d = capVu0MagnitudeSqXZ(*(void **)(s + 0xF0), s + 0x580);
        if (d < 4.0f) {
            *(unsigned char *)(s + 0x2F4) = 0;
            *(unsigned char *)(s + 0x2F5) = 0;
            *(unsigned char *)(s + 0x2F6) = 0;
            *(unsigned char *)(s + 0x2F7) = 0;
        }
        *(float *)(s + 0x330) = 0.0f;
        *(float *)(s + 0x334) = 0.0f;
        *(float *)(s + 0x338) = d > 6.25f ? 2.0f : 1.0f;
        *(float *)(s + 0x338) = 2.0f;
        cObjBase_addNullSpeed_Rotation(s, 1.0f);
        cObjBase_addNullSpeed(s, 1.0f);
        break;
    }
}
