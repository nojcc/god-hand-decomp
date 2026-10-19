/* sn-2.95.3-136: func_002BF568, object event reset: clear the object's state bytes and on kind 1 fade the BGM, raise the sound mute bits and start the stage-dependent player effect. */
typedef struct GameWork2BF568 {
    char pad000[0x584];
    int flags;                          /* 0x584 */
    char pad588[0x5B4 - 0x588];
    unsigned short effId;               /* 0x5B4 */
    char pad5B6[0x5E4 - 0x5B6];
    int flags5E4;                       /* 0x5E4 */
    int flags5E8;                       /* 0x5E8 */
} GameWork2BF568;

extern GameWork2BF568 D_007474A0;
extern unsigned char D_0074748C;
extern char D_005FEE00[];
extern char D_00583EC0[];
extern void *D_003C264C;

extern void func_002BF800(unsigned char *p);
extern void Obj0000_Set_D_00747A80_Field_70_2BF780(unsigned char *p);
extern void cSnd_BgmEventFade(void *snd, int reqNo, float time, float level, float weight);
extern void func_002C0840(void *self);
extern char *Getplayer(void);
extern int func_001FFF30(void *a0, unsigned short a1, float *a2, unsigned char a3, float f, int t0, unsigned char t1);

__attribute__((section(".text.func_002BF568")))
void func_002BF568(unsigned char *p)
{
    int *w;
    GameWork2BF568 *gw;
    int one;

    if (D_0074748C != 0 && !((D_0074748C >> 2) & 1))
        return;
    p[0xA] = 0;
    w = &D_007474A0.flags5E4;
    w[1] &= ~0x40000000;
    one = 1;
    func_002BF800(p);
    Obj0000_Set_D_00747A80_Field_70_2BF780(p);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    if (p[0xC] == one) {
        ((GameWork2BF568 *)((char *)w - 0x5E4))->flags |= 0x40;
        cSnd_BgmEventFade(D_005FEE00, 0, 10.0f, 0.0f, -1.0f);
        *(int *)(D_005FEE00 + 0xB0) |= 0x200000;
        *(int *)(D_005FEE00 + 0xAC) |= 0x200000;
        *w &= ~0x4000;
        gw = &D_007474A0;
        if (gw->effId == 0x100) {
            func_002C0840(D_003C264C);
            func_001FFF30(D_00583EC0, gw->effId, *(float **)(Getplayer() + 0xF0), 1,
                          *(float *)(Getplayer() + 0x104), 0x80000000, 1);
        } else {
            func_001FFF30(D_00583EC0, gw->effId, *(float **)(Getplayer() + 0xF0), 0,
                          *(float *)(Getplayer() + 0x104), 0x80000000, 0);
        }
    }
}
