/* NON_MATCHING func_0030B420 (sn-2.95.3-136): matches through the last sceGsSyncV;
* retail keeps s0 = &D_007474A0+0x584 and derives the base into a2 (flags2 at 4(s0)), ours
 * rebases s0 in the call delay slot (-1412) and loses the nop. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct GameWork {
    char pad000[0x584];
    unsigned int flags;         /* 0x584 */
    unsigned int flags2;        /* 0x588 */
    char pad58C[0x5A0 - 0x58C];
    int unk5A0;                 /* 0x5A0 */
    char pad5A4[0x5B0 - 0x5A4];
    short stage;                /* 0x5B0 */
} GameWork;

extern GameWork D_007474A0;
#define GFLAGS (*(int *)((char *)&D_007474A0 + 0x584))
extern char D_004504F0[];
extern char D_00450508[];
extern char *D_00752C00;
extern char D_005E79D0[];
extern char D_005FEE00[];
extern char D_005E6900[];
extern char D_005E8640[];
extern char D_005E8040[];
extern char D_005E8140[];
extern char D_00583F20[];
extern char D_00747470[];
extern char D_00586AF0[];
extern void *D_003C2F84;
extern char D_005CAE50[];
extern char D_00574380[];
extern char D_00604700[];
extern char D_00580D40[];
extern int D_00753D80;

extern void func_003A6A20(const char *s);
extern int sceGsSyncV(int mode);
extern void func_0030F5F0(void);
extern void func_00150078(void);
extern void Forward149378_1492C8(void);
extern void Set_bg_mode(int, int, int, int);
extern void cTaskWork_kill(void *work);
extern void cMovie_stopAllTracks(void *m);
extern int cMovie_isIdle(void *m);
extern void func_002B4A30(void);
extern void classFADE_kill(void *p);
extern void func_002CA040(void *p);
extern void cDvd_cancelAll(void *dvd);
extern void cMc_DllRelease(void *self);
extern void func_002C9F58(void *);
extern void cDvd_init(void *dvd);
extern void MoviePool_init(void *res);
extern void func_002BE818(void *p);
extern void cEvent_freeData(void *p);
extern void ClearActorList_2C32C0(void *p);
extern void InitZeroAndSetup_12E800(void *p);
extern void InitPools_1FDFA8(void *p);
extern void RecPool_dispatchUsed(void *p);
extern void arrayFree(void *self);
extern void func_002D73E0(void *p);
extern void LoadAndWaitReady_1FFBF0(void *self, char *name);
extern void func_0030ECF8(int a0);
extern void func_002BE200(void *p);

__attribute__((section(".text.func_0030B420")))
void func_0030B420(void)
{
    func_003A6A20(D_004504F0);
    sceGsSyncV(0);
    sceGsSyncV(0);
    func_0030F5F0();
    func_00150078();
    Forward149378_1492C8();
    Set_bg_mode(1, 0, 0, 0);
    cTaskWork_kill(D_00752C00);
    cTaskWork_kill(D_00752C00 + 0x58);
    cTaskWork_kill(D_00752C00 + 0xB0);
    cTaskWork_kill(D_00752C00 + 0x108);
    cMovie_stopAllTracks(D_005E79D0);
    while (!cMovie_isIdle(D_005E79D0))
        sceGsSyncV(0);
    func_002B4A30(D_005E79D0);
    GFLAGS &= ~0x02000000;
    GFLAGS &= ~2;
    GFLAGS &= ~8;
    GFLAGS &= ~0x80;
    GFLAGS &= ~0x08000000;
    classFADE_kill(D_00747470);
    func_002CA040(D_005FEE00);
    cDvd_cancelAll(D_00583F20);
    sceGsSyncV(0);
    sceGsSyncV(0);
    cMc_DllRelease(D_005E6900);
    sceGsSyncV(0);
    func_002C9F58(D_005FEE00);
    cDvd_init(D_00583F20);
    MoviePool_init(D_005E79D0);
    func_002BE818(D_005E8640);
    cEvent_freeData(D_00586AF0);
    ClearActorList_2C32C0(D_003C2F84);
    InitZeroAndSetup_12E800(D_005CAE50);
    InitPools_1FDFA8(D_00574380);
    RecPool_dispatchUsed(D_005E8040);
    arrayFree(D_005E8040);
    func_002D73E0(D_00604700);
    LoadAndWaitReady_1FFBF0(D_00580D40, D_00450508);
    func_0030ECF8(1);
    D_00753D80 = 0;
    sceGsSyncV(0);
    GFLAGS &= ~0x8000;
    D_007474A0.stage = 0x20;
    *(int *)((char *)&D_007474A0 + 0x588) |= 0x800000;
    D_007474A0.unk5A0 = 0;
    func_002BE200(D_005E8140);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030B420);
#endif
