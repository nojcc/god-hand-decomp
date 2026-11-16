/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/pl00.h"
#include "godhand/motion.h"
#include "godhand/cSnd.h"
#include "godhand/DogRace.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetPlSorry(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_005864F0[];
extern int irand(void);
extern int cEmManage_SetEmAnger(void *a0, void *a1, float f12, float f13, float f14);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern int D_005CB000;
extern unsigned int D_00747A78;
extern unsigned int D_00747A80;
extern int D_003C2F84;
extern char D_00747470[];
extern int D_005FEA60;
extern void cScenario_startSoftEvent(int a0, int a1);
extern void cScenario__endSoftEvent(int a0);
extern void cTaskWork_exit(int a0);
extern void classFADE_start(void *p, int b, int c, int d, int e, unsigned int f, int g);
extern void classFADE_kill(void *p);
extern void cTaskWork_sleep(void *p, int a);
extern void DogRace_Load(DogRace *self);
extern void cSceAtManager_SetEnable_2C2950(void *p, int a);

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_00113F68")))
void func_00113F68(pl00 *self)
{
    self->base.hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    switch (self->base.step) {
    case 0:
    {
        char *t;

        Obj0000_Clear_Fields_640_648_124E58(self);
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        func_00129578(self);
        cCoreSave_useGodItem(&D_00569B70);
        t = self->base.pack;
        func_002A8578(self, EM_RES_REC(t, 0x604), EM_RES_REC(t, 0x608),
                      3, 0.0f, 0, 0);
        self->unk15B0 = 1;
        (self->base.step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(self);
        if ((self->base.seqFlags & 0x200) != 0) {
            cEmManage_SetPlSorry(D_005864F0);
        }
        if (moveMotion(self) != 0) {
            pl00_clearMotionCam(self, 0, 0);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
    if ((self->base.seqFlags & 1) != 0) {
        if (self->unk15B0 != 0) {
            self->unk15B0 = 0;
            cCoreSave_setGameLevel(&D_00569B70, 0);
        }
    }
    if (func_00123938(self, 1) != 0) {
        func_00129630(self);
        pl00_clearMotionCam(self, 0, 0);
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"















__attribute__((section(".text.func_00114460")))
void func_00114460(pl00 *self)
{
    float v[4] __attribute__((aligned(16)));

    switch (self->base.step) {
    case 0: {
        int p1, p2;
        self->unk5E0 = 0;
        self->unk5E2 = 0;
        if (irand() & 1) {
            p1 = EM_RES_REC(self->base.pack, 0x230);
            p2 = EM_RES_REC(self->base.pack, 0x234);
        } else {
            p1 = EM_RES_REC(self->base.pack, 0x8A0);
            p2 = EM_RES_REC(self->base.pack, 0x8A4);
        }
        func_002A8578(self, p1, p2, 3, 0.0f, 0, 0);
        self->base.unk568 = 1;
        self->base.step = self->base.step + 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(self) != 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if ((self->base.seqFlags & 1) != 0 && self->base.unk568 != 0) {
            self->base.unk568 = 0;
            VU0_LQC2(4, self->base.pos, 0);
            VU0_SQC2(4, v, 0);
            if (cEmManage_SetEmAnger(D_005864F0, v, self->base.rot.y, 15.0f, 0.523598790f) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) != 5) {
                    cHeatSys_AddHeatGage(&D_005CB000, 0, 12.0f);
                    cCoreSave_addGameLevelPoint(&D_00569B70, 0xFA);
                } else {
                    cHeatSys_AddHeatGage(&D_005CB000, 0, 6.0f);
                }
            }
        }
        break;
    }
    func_00123938(self, 1);
}

/* sn-2.95.3-136 matched TU. */



















static __inline__ int FadeIsEnd(char *f)
{
    return (*(unsigned char *)(f + 0x1C) >> 2) & 1;
}

/* DogRace.unk54 by raw offset: the typed field lets cc1 move its load above the D_00747A80 stores. */
#define DOGRACE_UNK54(self) (*(unsigned int *)((char *)(self) + 0x54))

__attribute__((section(".text.func_001E9F68")))
void func_001E9F68(DogRace *self)
{
    cScenario_startSoftEvent(D_003C2F84, 0);
    D_00747A78 = D_00747A78 & 0xFDFFFFFF;
    classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000, 0xF);
    while (!FadeIsEnd(D_00747470)) {
        cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 1);
    }
    DogRace_Load(self);
    D_00747A80 |= 0x4000000;
    D_00747A80 |= 0x2000000;
    D_00747A80 |= 0x40000000;
    D_00747A80 |= 0x80000000;
    D_00747A80 |= 0x200000;
    D_00747A80 |= 0x10000000;
    D_00747A80 |= 0x8000000;
    {
        long v = DOGRACE_UNK54(self);
        if ((v & 1) == 0) {
            long w;
            do {
                Slot2_dispatchStep(self);
                cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 1);
                w = DOGRACE_UNK54(self);
            } while ((w & 1) == 0);
        }
    }
    D_00747A80 &= 0xFBFFFFFF;
    D_00747A80 &= 0xFDFFFFFF;
    D_00747A80 &= 0xBFFFFFFF;
    D_00747A80 &= 0x7FFFFFFF;
    D_00747A80 &= 0xFFDFFFFF;
    D_00747A80 &= 0xDFFFFFFF;
    D_00747A80 &= 0xEFFFFFFF;
    D_00747A80 &= 0xF7FFFFFF;
    DogRace_Release(self);
    classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000, 0, 0xF);
    while (!FadeIsEnd(D_00747470)) {
        cTaskWork_sleep(*(void **)(D_003C2F84 + 0x20), 1);
    }
    cSnd_BgmFlaggedNodeKick(&D_005FEE00, 20.0f);
    classFADE_kill(D_00747470);
    cSceAtManager_SetEnable_2C2950(&D_005FEA60, self->unk1B0);
    cScenario__endSoftEvent(D_003C2F84);
    cTaskWork_exit(*(int *)(D_003C2F84 + 0x20));
}
