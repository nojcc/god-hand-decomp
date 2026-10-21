/* NON_MATCHING func_0028A780: state byte 0x2F6.
* Zero rolls a resource pair and a sound, then falls into the countdown; one runs the countdown; anything else returns.
* The switch gives retail's beqz/beql dispatch.
* Retail keeps a dead andi after the first Rnd() (id not 0x2A7/0x2AB); every form here deletes it, so the rest is one word short. */
#include "include_asm.h"

#ifdef NON_MATCHING
extern int Rnd(void);
extern void func_002A8578(char *p, int a, int b, float z, int k, int c, int d);
extern int cSnd_SeCall_2CBA48(void *bank, int a, int id, void *obj, int t0, int t1, int t2, int t3);
extern void cGameObj_SetTgtTurn(char *p, int tgt, float ang);
extern int moveMotion(char *p);
extern void cModel_calcNullPart(char *p);
extern void Add_nullspeed(char *p);
extern char D_005FEE00[];

void func_0028A780(char *p)
{
    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int id = *(int *)(p + 0x564);
        char *base;
        int off0;
        int off1;

        int r;

        if (id != 0x2A7 && id != 0x2AB)
            Rnd();
        r = Rnd() & 1;
        base = *(char **)(p + 0x304);
        if (r) {
            off0 = *(int *)(base + 0x80);
            off1 = *(int *)(base + 0x84);
        } else {
            off0 = *(int *)(base + 0x88);
            off1 = *(int *)(base + 0x8C);
        }
        func_002A8578(p, off0 + (int)base, off1 + (int)base, 0.0f, 5, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5C, p, 0, 0, 0, 0);
        *(int *)(p + 0x5F0) = 10;
        *(unsigned char *)(p + 0x2F6) = (unsigned char)(*(unsigned char *)(p + 0x2F6) + 1);
    }
    case 1: {
        int left = *(int *)(p + 0x5F0);

        if (left != 0) {
            int *mot;

            left -= 1;
            mot = *(int **)(p + 0x670);
            *(int *)(p + 0x5F0) = left;
            if (mot[0x34 / 4] != 0)
                cGameObj_SetTgtTurn(p, *(int *)(mot[0x34 / 4] + 0xF0),
                    *(float *)(p + 0x5A8) * 0.3926991f);
        }
        if (moveMotion(p) != 0) {
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        cModel_calcNullPart(p);
        Add_nullspeed(p);
        break;
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028A780);
#endif
