/* sn-2.95.3-136: NM closer handoff. */
typedef struct Sys30B298 {
    char pad000[0x569];
    unsigned char b569;                 /* 0x569 */
    char pad56A[2];
    int f56C;                           /* 0x56C */
    char pad570[8];
    int pal;                            /* 0x578 1 = PAL */
    int f57C;                           /* 0x57C */
    int f580;                           /* 0x580 */
    int boot;                           /* 0x584 */
    char pad588[4];
    int e3flags;                        /* 0x58C D_00747A2C starts here */
    char pad590[8];
    int f598;                           /* 0x598 */
    int f59C;                           /* 0x59C */
    char pad5A0[0x10];
    short frameRate;                    /* 0x5B0 */
    char pad5B2[0x620 - 0x5B2];
} Sys30B298;

typedef struct E3Sys30B298 {
    char pad0[8];
    unsigned int flags;                 /* 0x8 */
} E3Sys30B298;

extern Sys30B298 D_007474A0;
extern E3Sys30B298 D_00747A2C;
extern int D_003C3CCC;
extern int D_00752D3C;
extern char D_005E8140[];
extern char D_005E8640[];
extern char D_00580D40[];
extern char D_004504D8[];

extern void func_0030D258(void);
extern void func_0030ECF8(int a0);
extern void Tramp_func_0015B0C0_0015B0A0(void);
extern void func_0031CEB8(void);
extern void func_003A52F0(void *p, int c, int n);
extern void func_002BDFF8(void *p);
extern void func_0030CB30(void);
extern int sceGsResetGraph(short mode, short inter, short omode, short ffmode);
extern int sceGsSyncV(int mode);
extern void func_0030B148(void);
extern void func_00395F68(void (*fn)(void));
extern void func_0030D1F8(void);
extern int func_001FF858(void *a0, void *a1);
extern void func_002BE6E8(void *p);

static inline int IsPal30B298(Sys30B298 *s)
{
    return s->pal == 1;
}

static inline int SysIsPal30B298(void)
{
    return D_007474A0.pal == 1;
}

__attribute__((section(".text.func_0030B298")))
void func_0030B298(void)
{
    E3Sys30B298 *e3;
    Sys30B298 *sys;
    Sys30B298 *g = &D_007474A0;

    func_0030D258();
    func_0030ECF8(0);
    Tramp_func_0015B0C0_0015B0A0();
    func_0031CEB8();
    func_003A52F0(g, 0, sizeof(Sys30B298));
    g->f56C = 1;
    g->pal = 0;
    g->f59C &= ~0x100000;
    if (!(g->f598 & 0x200000) || (g->f59C & 0x1000000))
        g->frameRate = 0x20;
    else
        g->boot |= 0x200;
    e3 = &D_00747A2C;
    if (e3->flags & 0x800)
        ((Sys30B298 *)((char *)e3 - 0x58C))->f56C = 1;
    sys = (Sys30B298 *)((char *)e3 - 0x58C);
    sys->f57C = 0;
    sys->f580 = 0;
    if (!IsPal30B298(sys))
        D_003C3CCC = 0x40;
    else
        D_003C3CCC = 0x50;
    func_002BDFF8(D_005E8140);
    func_0030CB30();
    if (SysIsPal30B298()) {
        sceGsResetGraph(0, 1, 3, 0);
        sceGsSyncV(0);
    }
    func_00395F68(func_0030B148);
    func_0030D1F8();
    func_001FF858(D_00580D40, D_004504D8);
    g->b569 = 2;
    D_00752D3C = 0;
    func_002BE6E8(D_005E8640);
}
