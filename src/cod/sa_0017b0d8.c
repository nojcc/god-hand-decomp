/* sn-2.95.3-136: func_0017B0D8, double swing gimmick step: start two 90-frame rotations (movers at 0x610 and
 * 0x770) with vibration, wait out the start timer, run both moves and hold for 15 frames, then finish. */
extern void cOmSub_initMove1_ang(void *dst, void *obj, int idx, int a3, void *a4,
                                 float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *a0);

__attribute__((section(".text.func_0017B0D8")))
void func_0017B0D8(char *p)
{
    float ang[4];
    float z;
    int r;
    int r2;

    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x601) == 1)
            break;
        ang[0] = -1.3962634f;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        z = ang[1];
        cOmSub_initMove1_ang(p + 0x610, p, 0, 0x5A, ang, 0.2f, z, 0);
        cOmSub_setVibration(p + 0x610, 5, 5, 2.0f, 0.5f, 2.0f);
        cOmSub_initMove1_ang(p + 0x770, p, 2, 0x5A, ang, 0.2f, z, 0);
        cOmSub_setVibration(p + 0x770, 5, 5, 2.0f, 0.5f, 2.0f);
        *(unsigned char *)(p + 0x2F5) = 1;
        *(short *)(p + 0x604) = 7;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
        /* fallthrough */
    case 1:
        if (*(short *)(p + 0x604) < 0) {
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F5) = 2;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        *(short *)(p + 0x604) -= 1;
        break;
    case 2:
        r = cOmSub_move(p + 0x610);
        r2 = cOmSub_move(p + 0x770);
        if (r == 0 && r2 == 0) {
            *(unsigned char *)(p + 0x601) = 1;
            *(short *)(p + 0x604) = 15;
            *(unsigned char *)(p + 0x2F5) = 3;
            *(unsigned char *)(p + 0x600) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    case 3:
        if (*(short *)(p + 0x604) < 0) {
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        *(short *)(p + 0x604) -= 1;
        break;
    }
}
