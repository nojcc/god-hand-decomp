/* sn-2.95.3-136: event movie play step: pause bgm and lock game flags, start the movie, wait for it to end, then restore and fade in (0x160FF0). */
extern int D_007474A0;
extern char D_005FEE00[];
extern char D_005E79D0[];
extern char D_00747470[];
extern int D_00566E40;
extern int D_00566E44;

extern void KeyStop(void);
extern void cSnd_BattleBgmAllPause(void *, float);
extern void cSnd_BgmFlaggedNodeKick(void *, float);
extern int cMovie_Start(void *, int, int);
extern void cMovie_haltActive(void *, int);
extern int cMovie_GetStatus(void *, int);
extern void cMovie_Stop(void *, int);
extern void classFADE_start(void *, int, int, int, unsigned int, unsigned int, int);

#define GF5D8 (*(int *)((char *)&D_007474A0 + 0x5D8))
#define GF5E0 (*(int *)((char *)&D_007474A0 + 0x5E0))

__attribute__((section(".text.func_00160FF0")))
int func_00160FF0(char *self)
{
    int id;
    int *hp;

    switch (*(short *)(self + 0x52)) {
    case 0:
        id = *(signed char *)(self + 0xB9C) + 2;
        hp = &D_00566E40;
        KeyStop();
        cSnd_BattleBgmAllPause(D_005FEE00, 1.0f);
        GF5E0 |= 0x4000000;
        GF5E0 |= 0x2000000;
        GF5E0 |= 0x40000000;
        GF5E0 |= 0x80000000;
        GF5E0 |= 0x200000;
        GF5E0 |= 0x20000000;
        GF5E0 |= 0x10000000;
        GF5E0 |= 0x8000000;
        GF5D8 |= 0x80000000;
        GF5D8 |= 0x40000000;
        GF5D8 |= 0x20000000;
        GF5D8 |= 0x10000000;
        GF5D8 |= 0x80000;
        GF5D8 |= 0x40000;
        *hp = cMovie_Start(D_005E79D0, id, 0);
        D_00566E44 = 5;
        GF5E0 |= 0x2000000;
        (*(short *)(self + 0x52))++;
    case 1:
        if (--D_00566E44 > 0)
            return 0;
        cMovie_haltActive(D_005E79D0, D_00566E40);
        (*(short *)(self + 0x52))++;
    case 2:
        if (cMovie_GetStatus(D_005E79D0, D_00566E40))
            return 0;
        cMovie_Stop(D_005E79D0, D_00566E40);
        cSnd_BgmFlaggedNodeKick(D_005FEE00, 20.0f);
        GF5E0 &= ~0x4000000;
        GF5E0 &= ~0x2000000;
        GF5E0 &= ~0x40000000;
        GF5E0 &= ~0x80000000;
        GF5E0 &= ~0x200000;
        GF5E0 &= ~0x20000000;
        GF5E0 &= ~0x10000000;
        GF5E0 &= ~0x8000000;
        GF5D8 &= ~0x80000000;
        GF5D8 &= ~0x40000000;
        GF5D8 &= ~0x20000000;
        GF5D8 &= ~0x10000000;
        GF5D8 &= ~0x80000;
        GF5D8 &= ~0x40000;
        GF5D8 &= ~0x2000000;
        classFADE_start(D_00747470, 0, 10, 0, 0xFF000000, 0xFF000000, 0);
        *(short *)(self + 0x52) = 0;
    }
    return 1;
}
