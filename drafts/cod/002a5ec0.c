/* sn-2.95.3-136 */
/* func_002A5EC0 (stage set-up): 498 of 500 words. Retail reaches the game work
 * block through constant addresses anchored at D_007474A0 + 0x5D8, + 0x584 and
 * + 0x58C (room as 0x2C past the flags word); this C's field reads build the
 * block's base address and add each offset, which shifts the register choice
 * throughout. Retail passes an argument the definitions of System_initPools,
 * func_00299860, cNowLoading_executeTask, cNowLoading_exitTask and
 * cEmSetParam_setEmData do not take; they are declared here as called. */
#include "include_asm.h"

#ifdef NON_MATCHING

#include "godhand/player.h"
#include "godhand/cIDManager.h"
#include "godhand/gameWork.h"
#include "godhand/cCoreSave.h"
#include "godhand/ColiseumEmSelect.h"

typedef struct PinnedEnt {
    int kind;
    int idx;
} PinnedEnt;

typedef struct StageScene {
    unsigned char state;        /* 0x00 */
    char pad01[3];
    int unk04;                  /* 0x04 */
    char pad08[0x18C - 0x08];
    char light[0x1AC - 0x18C];  /* 0x18C */
    float unk1AC;               /* 0x1AC */
    short unk1B0;               /* 0x1B0 */
} StageScene;

typedef struct OmSetBuf {
    int a;
    int b;
} OmSetBuf;

extern void *func_003A52F0(void *dst, int val, int len);
extern int cDataManager_addPinnedData(void *self, int kind, void *buf);
extern void cNowLoading_executeTask(int task);
extern void cNowLoading_exitTask(int task);
extern void func_0030D8E0(int objid);
extern void func_002D9BC8(void *a0);
extern void func_002C32F0(void *o);
extern void ForwardVtableCall_138210(char *a0);
extern void func_002CA8C8(void *a0);
extern void func_002BF150(void *a0);
extern int cMovie_isIdle(void *self);
extern void InitEspWork(void);
extern void InitEmitterWork(void);
extern void func_002A6C78(void *self);
extern void func_002A94F0(char *self);
extern void func_0031CC48(void);
extern void System_initPools(void *scene, int room);
extern void func_002BE708(void *self, int arg);
extern void ClearInputState_2C33D8(void *a0);
extern void func_002CABE8(char *p);
extern void func_002B8B50(void *p);
extern void func_00305A68(void *self);
extern void func_002993A0(void *self);
extern void func_002D6F40(void *self);
extern void func_001509A0(char *base);
extern void cHookList_callAll(char *self);
extern void func_001FDF88(void *a0);
extern void func_00134690(int *p);
extern void func_002A71B0(void);
extern void func_0031D1B0(void);
extern void func_0012E670(void *p);
extern void func_00307A60(void *p);
extern void func_0031C4E0(void);
extern void func_002BF8F8(char *a0);
extern int func_00150C10(void *c, char *str, int mode);
extern void func_0015FEE0(void *t);
extern void func_00299860(void *self);
extern void cFont_setMessageTextures(int self);
extern void cMessage_initWinList(int self);
extern void func_002C0F90(void *self);
extern void cActionButton_resetEntries(void *self);
extern void Obj0000_Set_Short_00_1FFE08(char *a0);
extern void func_00290230(void *self);
extern void cCoreSave_spawnItems(cCoreSave *self);
extern void cEmSetParam_roomInit(void *self);
extern void cEmSetParam_setEmData(void *self, void *data);
extern void func_002A7308(int a0);
extern void cOmSetParam_setOmData(OmSetBuf *self, void *data);
extern int cAreaCamManager_SetData(int a0, int a1);
extern void ResetActorState_2C3440(void *a0);
extern void func_0031BE78(void *a0);
extern void func_0031C1D0(void *dest, char *src);
extern void cWorldLight_Light_curent_set(void *wl, int a1);
extern void cSnd_BgmStageChange(void *self);

extern char *D_003BD6E8;
extern PinnedEnt *D_003C3CC4;
extern void *D_00752C38[];
extern char D_00580D20[];
extern int D_003C2558;
extern char *D_003C2F84;
extern char *D_005CAFF0;
extern char *D_003C2648;
extern char *D_003C264C;
extern char *D_003BD930;
extern int D_003C2380;
extern int D_003C23A4;
extern char D_0061A990[];
extern char D_005FEE00[];
extern char D_005E79D0[];
extern char D_00754220[];
extern char D_005E8640[];
extern char D_005E8040[];
extern char D_007419A0[];
extern char D_00586C00[];
extern char D_00604700[];
extern char D_004664A0[];
extern char D_00574380[];
extern int D_00462FC0[];
extern char D_005CAE50[];
extern char D_00747B20[];
extern char D_005FEA60[];
extern char D_00568288[];
extern char D_00583EC0[];
extern char D_005864F0[];
extern char D_00586AB0[];
extern char D_00463050[];
extern char D_0044AD68[];
extern char D_0044AD70[];
extern char D_0044AD78[];
extern char D_0044AD80[];

/* Set up a stage: clear the per-stage flags, pin the stage data, swap the costume
 * model if it changed, reset every manager and load the room's enemy, object,
 * camera and light data. */
__attribute__((section(".text.func_002A5EC0")))
void func_002A5EC0(StageScene *self)
{
    unsigned char no;
    int i;
    int set;
    char *light;
    unsigned long f;

    func_003A52F0(&D_007474A0.flags5D8, 0, 8);
    func_003A52F0(&D_007474A0.flags5E0, 0, 4);
    func_003A52F0(D_007474A0.unk5EC, 0, 8);
    if (D_007474A0.debugFlags & 0x800) {
        if (D_007474A0.flags & 0x200)
            *(short *)(D_003BD6E8 + 0x45E) = 0x3101;
    }
    if (!(D_007474A0.flags & 0x4000000))
        self->unk04 = 0;
    light = self->light;
    if (D_007474A0.room != 0x20) {
        f = D_007474A0.flags;
        if (((f >> 7) & 1) == 0) {
            while (!(D_007474A0.flags & 0x400))
                cTaskWork_sleep(D_00752C00.task, 1);
            cDataManager_addPinnedData(D_00580D20, 0x100, D_00752C38[0]);
            cDataManager_addPinnedData(D_00580D20, 0x101, D_00752C38[1]);
            for (i = 0; D_003C3CC4[i].kind != 0xFFFF; i++)
                cDataManager_addPinnedData(D_00580D20, D_003C3CC4[i].kind, D_00752C38[D_003C3CC4[i].idx]);
            D_007474A0.flags |= 0x80;
        }
    }
    f = D_007474A0.flags;
    if (((f >> 4) & 1) == 0)
        cNowLoading_executeTask(D_003C2558);
    no = cCoreSave_getCostumeNo(&D_00569B70);
    if (no != cCoreSave_getPrevCostumeNo(&D_00569B70) || (D_007474A0.unk588 & 0x800000)
        || (f = D_007474A0.flags, ((f >> 6) & 1) != 0)) {
        switch (no) {
        default:
            func_0030D8E0(0x100);
            break;
        case 1:
            func_0030D8E0(0x102);
            break;
        case 2:
            func_0030D8E0(0x105);
            break;
        case 3:
            func_0030D8E0(0x10F);
            break;
        case 4:
            func_0030D8E0(0x107);
            break;
        case 5:
            func_0030D8E0(0x110);
            break;
        case 6:
            func_0030D8E0(0x10E);
            break;
        case 7:
            func_0030D8E0(0x111);
            break;
        }
        cCoreSave_resetCostumeNo(&D_00569B70, no);
    }
    D_007474A0.unk5F8 = 0;
    D_007474A0.playerObj = 0;
    func_002D9BC8(D_0061A990);
    func_002C32F0(D_003C2F84);
    ForwardVtableCall_138210(D_005CAFF0);
    func_002CA8C8(D_005FEE00);
    func_002BF150(D_003C2648);
    while (!cMovie_isIdle(D_005E79D0))
        cTaskWork_sleep(D_00752C00.task, 1);
    InitEspWork();
    InitEmitterWork();
    func_002A6C78(self);
    func_002A94F0(D_00754220);
    func_0031CC48();
    System_initPools(self, D_007474A0.room);
    func_002BE708(D_005E8640, D_007474A0.room);
    ClearInputState_2C33D8(D_003C2F84);
    func_002CABE8(D_005FEE00);
    func_002B8B50(D_005E8040);
    func_00305A68(D_007419A0);
    func_002993A0(D_00586C00);
    func_002D6F40(D_00604700);
    func_001509A0(D_004664A0);
    cHookList_callAll(D_003BD6E8);
    func_001FDF88(D_00574380);
    func_00134690(D_00462FC0);
    func_002A71B0();
    func_0031D1B0();
    func_0012E670(D_005CAE50);
    func_00307A60(D_00747B20);
    func_0031C4E0();
    D_007474A0.flags598 &= ~0x40;
    D_007474A0.flags5E4 &= ~0x8000;
    func_002BF8F8(D_003C264C);
    D_007474A0.unk5D4 = 0x14;
    func_00150C10(D_004664A0, (char *)D_007474A0.effData + D_007474A0.effData->unk10, 1);
    func_0015FEE0(D_003BD930);
    func_00299860(D_00586C00);
    cFont_setMessageTextures(D_003C2380);
    cMessage_initWinList(D_003C23A4);
    func_002C0F90(D_005FEA60);
    cActionButton_resetEntries(D_00568288);
    Obj0000_Set_Short_00_1FFE08(D_00583EC0);
    if (D_007474A0.room != 0x20)
        func_00290230(D_005864F0);
    cCoreSave_spawnItems(&D_00569B70);
    if (!(D_007474A0.unk590 & 0x10000000)) {
        cEmSetParam_roomInit(D_00586AB0);
        set = 0;
        if ((D_00569B70.data->flags & 0x4000000) && D_007474A0.room - 0x4E < 2U) {
            ColiseumEmEntry e = D_00568240.entry;
            set = e.unk00 + 8;
        }
        cEmSetParam_setEmData(D_00586AB0, SearchData(D_007474A0.pack, D_0044AD68, set));
    }
    if (!(D_007474A0.unk590 & 0x8000000)) {
        OmSetBuf om;
        func_002A7308((int)&om);
        cOmSetParam_setOmData(&om, SearchData(D_007474A0.pack, D_0044AD70, 0));
    }
    cAreaCamManager_SetData((int)(D_00463050 + 0xFF4), (int)SearchData(D_007474A0.pack, D_0044AD78, 0));
    ResetActorState_2C3440(D_003C2F84);
    func_0031BE78(light);
    if (!(D_007474A0.flags598 & 0x80000))
        func_0031C1D0(light, SearchData(D_007474A0.pack, D_0044AD80, 0));
    self->unk1AC = 0.5f;
    D_007474A0.unk569 = 2;
    self->state = 4;
    f = D_007474A0.flags;
    if (((f >> 4) & 1) == 0 && !(D_007474A0.flags & 0x100))
        cNowLoading_exitTask(D_003C2558);
    D_007474A0.flags = D_007474A0.flags & ~0x10 & ~0x100;
    cWorldLight_Light_curent_set(D_00604700, 0);
    cSnd_BgmStageChange(D_005FEE00);
    self->unk1B0 = 0xF;
    if (D_007474A0.room != 0x20)
        Getplayer()->hitFlash = 30.0f;
    if ((D_007474A0.debugFlags & 0x800) && (D_007474A0.flags & 0x200))
        *(short *)(D_003BD6E8 + 0x45E) = -1;
    D_007474A0.flags = D_007474A0.flags & ~0x200 & ~0x40 & ~0x4000000 & ~0x2 & ~0x1000000;
    D_007474A0.unk588 &= ~0x800000;
    D_007474A0.flags5E0 &= ~0x2000000;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002A5EC0);
#endif
