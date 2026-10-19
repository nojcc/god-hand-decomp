/* sn-2.95.3-136: func_001A49A8, reverse slide gimmick step: like func_001A47F8 but moves over 0x798 - 0x794
 * and resets the gimmick when it is not armed (0x761). */
extern char D_005FEE00[];
extern void cOmSub_initMove1_ang(void *dst, void *obj, int idx, int a3, void *a4,
                                 float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *a0);
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, int key, int idA, int idB, int a5, int a6);
extern void func_001A4CF8(char *p);

__attribute__((section(".text.func_001A49A8")))
void func_001A49A8(char *p)
{
    float ang[4];
    float z;

    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x761) == 0) {
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
            break;
        }
        ang[0] = *(float *)(p + 0x798) - *(float *)(p + 0x794);
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        z = ang[1];
        cOmSub_initMove1_ang(p + 0x600, p, 0, 0xC, ang, 0.2f, z, 0);
        cOmSub_setVibration(p + 0x600, 3, 3, 4.0f, z, 4.0f);
        *(unsigned char *)(p + 0x2F5) = 1;
        *(short *)(p + 0x79C) = 7;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
        /* fallthrough */
    case 1:
        if (*(short *)(p + 0x79C) < 0) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x85, -1, -1, 0, 0);
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F5) = 2;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        *(short *)(p + 0x79C) -= 1;
        break;
    case 2:
        if (cOmSub_move(p + 0x600) == 0) {
            *(short *)(p + 0x79C) = 15;
            *(unsigned char *)(p + 0x2F5) = 3;
            *(unsigned char *)(p + 0x761) = 0;
            *(unsigned char *)(p + 0x760) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    case 3:
        if (*(short *)(p + 0x79C) < 0) {
            func_001A4CF8(p);
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        *(short *)(p + 0x79C) -= 1;
        break;
    }
}
