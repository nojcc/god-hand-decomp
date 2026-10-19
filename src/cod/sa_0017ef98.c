/* sn-2.95.3-136: func_0017EF98, timed tip-over state machine on the byte at 0x2F5: wait 7 frames, then rotate the
 * angle at 0x100 down with growing speed (ticking SE 0xE6 every 1000 frames) until it reaches -pi/2, where it lands
 * (effect, SE 0xE7) and holds 15 frames before going idle again. */
extern char D_005864F0[];
extern char D_005FEE00[];
extern float cEmManage_GetSpeedRate(void *manager);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);

__attribute__((section(".text.func_0017EF98")))
void func_0017EF98(char *p)
{
    float rate;
    float t;
    float s;
    float lim;

    rate = cEmManage_GetSpeedRate(D_005864F0);
    switch (*(unsigned char *)(p + 0x2F5)) {
    case 0:
        if (*(unsigned char *)(p + 0x600) == 1)
            return;
        *(unsigned char *)(p + 0x2F5) = 1;
        *(float *)(p + 0x604) = 7.0f;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    case 1:
        t = *(float *)(p + 0x604) - rate;
        *(float *)(p + 0x604) = t;
        if (t < 0.0f) {
            *(float *)(p + 0x604) = 25.0f;
            *(float *)(p + 0x608) = 0.01f;
            *(unsigned char *)(p + 0x2F5) = 2;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    case 2:
        s = *(float *)(p + 0x608);
        *(float *)(p + 0x604) = *(float *)(p + 0x604) - rate;
        *(float *)(p + 0x100) = *(float *)(p + 0x100) - s * rate * 0.017453292f;
        *(float *)(p + 0x608) = s + s * 0.16f * rate;
        if (*(float *)(p + 0x604) <= 0.0f) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xE6, p, 0, 0, 0, 0);
            *(float *)(p + 0x604) = 1000.0f;
        }
        t = *(float *)(p + 0x100);
        lim = -1.5707964f;
        if (t <= lim) {
            SetEffect(1, 1, 0, 0, -1, 0xFFFFFFFFU);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xE7, p, 0, 0, 0, 0);
            *(float *)(p + 0x100) = lim;
            *(unsigned char *)(p + 0x600) = 1;
            *(float *)(p + 0x604) = 15.0f;
            *(unsigned char *)(p + 0x2F5) = 3;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    case 3:
        t = *(float *)(p + 0x604) - rate;
        *(float *)(p + 0x604) = t;
        if (t <= 0.0f) {
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    }
}
