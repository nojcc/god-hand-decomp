/* NON_MATCHING func_0030D358 (sn-2.95.3-136, extern_jtbl D_00450550): register use around D_007474A0 differs. Retail keeps &D_007474A0.flags in s1 and reaches sysData and language from it (s1 - 0x30, s1 - 0x584), and each language arm builds &D_007474A0 in full before the shared +0x558; ours keeps &D_007474A0 in s0 from the start and folds 0x558 into the low half. 148 of 155 words. */
/* sn-2.95.3-136 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/gameWork.h"
#include "godhand/cSnd.h"
#include "godhand/cDvd.h"
#include "godhand/cTaskWork.h"
#include "godhand/cIDManager.h"

struct FontWork;
struct MenuObj;

extern void cSnd_LoadStartupBanks(cSnd *self);
extern int cDvd_ReadAlloc(cDvd *self, char *name, int *outBuf, int a3, int id, int t1, int arg70, int arg6C);
extern void cDvd_CheckWaitFrame(int a0, int a1);
extern void func_002A4970(struct FontWork *font);
extern void cMenu_loadDataTables(struct MenuObj *self);
extern void cIDManager_systemInit(int a0, int a1);
extern int cTaskManager_execute(int a0, int a1, int a2);
extern void cTaskWork_exit(cTaskWork *self);
extern void cMc_taskBody(void);
extern void func_002A5998(void);
extern void func_0030D5C8(void);

extern cSnd D_005FEE00;
extern cDvd D_00583F20;
extern char D_00754200[];
extern char *D_003C3BC8[];          /* data file names: [2] system, [3..9] one language file each */
extern int D_003C2380;
extern int D_003C23A4;
extern int *D_003C2384;
extern int D_003C2388;
extern char D_00450540[];

/* Boot step: load the sound banks, the system data and the data file for the current language, set up the
 * font, menus and resource ids, then start the memory card check (or the title tasks when no save slot is set). */
__attribute__((section(".text.func_0030D358")))
void func_0030D358(void)
{
    int handle;

    D_007474A0.flags |= 0x44000;
    cSnd_LoadStartupBanks(&D_005FEE00);
    handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[2], (int *)&D_007474A0.sysData, (int)D_00754200, 0, 0, 0, 0);
    cDvd_CheckWaitFrame((int)&D_00583F20, handle);
    switch (D_007474A0.language) {
    case 0:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[3], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 1:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[4], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 2:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[5], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 3:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[7], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 4:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[6], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 5:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[9], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    case 6:
        handle = cDvd_ReadAlloc(&D_00583F20, D_003C3BC8[8], (int *)&D_007474A0.langData, (int)D_00754200, 0, 0, 0, 0);
        break;
    }
    cDvd_CheckWaitFrame((int)&D_00583F20, handle);
    func_002A4970((struct FontWork *)D_003C2380);
    cMenu_loadDataTables((struct MenuObj *)D_003C23A4);
    *D_003C2384 = D_003C2388;
    cIDManager_systemInit(D_003C2388, (int)SearchData(D_007474A0.langData, D_00450540, 0));
    D_007474A0.flags |= 0x80000;
    if (D_007474A0.flags598 >= 0) {
        cTaskManager_execute((int)&D_00752C00, (int)cMc_taskBody, 2);
    } else {
        cTaskManager_execute((int)&D_00752C00, (int)func_002A5998, 0);
        cTaskManager_execute((int)&D_00752C00, (int)func_0030D5C8, 2);
    }
    cTaskWork_exit(D_00752C00.task);
}
#else
INCLUDE_ASM("asm/nonmatching", func_0030D358);
#endif
