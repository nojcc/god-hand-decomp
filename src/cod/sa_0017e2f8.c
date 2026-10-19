/* sn-2.95.3-136: func_0017E2F8, reverse quarter-turn gimmick step with sounds: start a 90-frame
 * rotate back with vibration, wait out the start timer, run the move and hold for 15 frames. */
extern char D_005FEE00[];
extern void cOmSub_initMove1_ang(void *dst, void *obj, int idx, int a3, void *a4,
                                 float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *a0);
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, int key, int idA, int idB, int a5, int a6);

__attribute__((section(".text.func_0017E2F8")))
void func_0017E2F8(char *p)
{
    float ang[4];

    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x601) == 1)
            break;
        ang[0] = -1.5707964f;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        cOmSub_initMove1_ang(p + 0x610, p, 0, 0x5A, ang, 0.2f, 0.0f, 0);
        cOmSub_setVibration(p + 0x610, 5, 5, 2.0f, 0.5f, 2.0f);
        *(unsigned char *)(p + 0x2F5) = 1;
        *(short *)(p + 0x602) = 7;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
        /* fallthrough */
    case 1:
        if (*(short *)(p + 0x602) < 0) {
            *(unsigned char *)(p + 0x2F5) = 2;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x1F, -1, -1, 0, 0);
        }
        *(short *)(p + 0x602) -= 1;
        break;
    case 2:
        if (cOmSub_move(p + 0x610) == 0) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x20, -1, -1, 0, 0);
            *(unsigned char *)(p + 0x601) = 1;
            *(short *)(p + 0x602) = 15;
            *(unsigned char *)(p + 0x2F5) = 3;
            *(unsigned char *)(p + 0x600) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    case 3:
        if (*(short *)(p + 0x602) < 0) {
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        *(short *)(p + 0x602) -= 1;
        break;
    }
}
