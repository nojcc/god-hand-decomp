#include "include_asm.h"

typedef unsigned int u_int;
typedef struct { unsigned char data[0x60]; } sceGsLoadImage;

#define T0_COUNT (*(volatile u_int *)0x10000000)
#define T0_MODE  (*(volatile u_int *)0x10000010)
#define T0_COMP  (*(volatile u_int *)0x10000020)
#define INTC_TIM0 9

extern unsigned char D_00753DC0[0x400];
extern int sceGsSetDefLoadImage(sceGsLoadImage *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
extern void FlushCache(int op);
extern int func_00395758(sceGsLoadImage *lp, void *src);
extern int func_003950F8(int mode, int timeout);

#ifdef NON_MATCHING
/* Retail leaves the AddIntcHandler delay slot empty;
* SN fills it with the T0_MODE store. */
#else
#endif

#ifdef NON_MATCHING
/* 16 words short: retail keeps the short-argument shifts and the 0x400000>>8 block count unfolded. */
__attribute__((section(".text.func_0030D258")))
void func_0030D258(void)
{
    sceGsLoadImage li;
    int i, n;
    short dbp;

    for (i = 0; i < 0x400; i++)
        D_00753DC0[i] = 0;
    n = (long)0x400000 >> 8;
    for (i = 0, dbp = 0; i < n; i++, dbp += 4) {
        sceGsSetDefLoadImage(&li, dbp, 4, 0, 0, 0, 16, 16);
        FlushCache(0);
        func_00395758(&li, D_00753DC0);
        func_003950F8(0, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030D258);
#endif

/* The parts of the game work block at D_007474A0 this function names. */
typedef struct GameWorkBoot {
    char pad000[0x554];
    void *sysData;              /* 0x554 system data file */
    void *langData;             /* 0x558 language data file */
    char pad55C[0x56C - 0x55C];
    unsigned int language;      /* 0x56C */
    char pad570[0x584 - 0x570];
    int flags;                  /* 0x584 */
    char pad588[0x598 - 0x588];
    int flags598;               /* 0x598 */
} GameWorkBoot;

typedef struct cTaskWorkRef {
    int unk0;
    int task;                   /* 0x4 */
} cTaskWorkRef;

extern GameWorkBoot D_007474A0;
extern char *D_003C3BC8[];      /* data file paths */
extern char D_005FEE00[];
extern char D_00583F20[];       /* the DVD reader */
extern char D_00754200[];       /* the load heap */
extern int D_003C2380;
extern void *D_003C23A4;
extern void **D_003C2384;
extern void *D_003C2388;
extern char D_00450540[];
extern cTaskWorkRef D_00752C00;

extern void cSnd_LoadStartupBanks(void *a0);
extern int cDvd_ReadAlloc(void *dvd, char *path, void **out, void *heap, int t0, int t1, int t2, int t3);
extern void cDvd_CheckWaitFrame(void *dvd, int req);
extern void func_002A4970(int font);
extern void cMenu_loadDataTables(void *a0);
extern int SearchData(void *data, void *name, int a2);
extern void cIDManager_systemInit(void *mgr, int id);
extern int cTaskManager_execute(void *mgr, void (*entry)(void), int arg);
extern void cTaskWork_exit(int task);
extern void cMc_taskBody(void);
extern void func_002A5998(void);
extern void func_0030D5C8(int a0, int a1);

#ifdef NON_MATCHING
/* Retail anchors the game-work addresses at D_007474A0+0x584 (flags) and derives the rest from it; ours anchors at the base. */
__attribute__((section(".text.func_0030D358")))
void func_0030D358(void)
{
    int req;

    D_007474A0.flags |= 0x44000;
    cSnd_LoadStartupBanks(D_005FEE00);
    req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[2], &D_007474A0.sysData, D_00754200, 0, 0, 0, 0);
    cDvd_CheckWaitFrame(D_00583F20, req);
    switch (D_007474A0.language) {
    case 0:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[3], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 1:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[4], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 2:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[5], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 3:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[7], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 4:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[6], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 5:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[9], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    case 6:
        req = cDvd_ReadAlloc(D_00583F20, D_003C3BC8[8], &D_007474A0.langData, D_00754200, 0, 0, 0, 0);
        cDvd_CheckWaitFrame(D_00583F20, req);
        break;
    }
    func_002A4970(D_003C2380);
    cMenu_loadDataTables(D_003C23A4);
    *D_003C2384 = D_003C2388;
    cIDManager_systemInit(D_003C2388, SearchData(D_007474A0.langData, D_00450540, 0));
    D_007474A0.flags |= 0x80000;
    if (D_007474A0.flags598 >= 0) {
        cTaskManager_execute(&D_00752C00, cMc_taskBody, 2);
    } else {
        cTaskManager_execute(&D_00752C00, func_002A5998, 0);
        cTaskManager_execute(&D_00752C00, func_0030D5C8, 2);
    }
    cTaskWork_exit(D_00752C00.task);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030D358);
#endif
