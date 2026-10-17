/* NM, not registered. sn-2.95.3-136: cActionButton manager update (0x1F7360).
 * func_001F7360: the D_00747A80 anchor (flags words at [0]/[-2], work block
 *   at -0x5E0) and the whole case tree match.  Still off: retail hoists the
 *   0x2000000 constant into s6 (8 saved regs vs our 7), tests ent->next in a
 *   temp before copying it to ent, and pads the loop top with a nop (needs
 *   the TU call_loop_pad flag, which sa_register cannot set). */
#include "include_asm.h"

#ifdef NON_MATCHING

typedef struct ActBtnEnt {
    unsigned int flags;                 /* 0x00 */
    struct ActBtnEnt *next;             /* 0x04 */
    char unk08[4];
    int unk0C;                          /* 0x0C */
    void (*func)(void *arg);            /* 0x10 */
    void *arg;                          /* 0x14 */
    int priority;                       /* 0x18 */
    int life;                           /* 0x1C */
    int unk20;                          /* 0x20 */
    int kind;                           /* 0x24 */
    void *matrix;                       /* 0x28 */
    int unk2C;                          /* 0x2C */
    unsigned short unk30;               /* 0x30 */
    short unk32;                        /* 0x32 */
    unsigned char cmdNum;               /* 0x34 */
    unsigned char unk35;                /* 0x35 */
    unsigned char unk36;                /* 0x36 */
    char unk37[1];
    int *cmdTbl;                        /* 0x38 */
    unsigned short *idTbl;              /* 0x3C */
    unsigned char *argTbl;              /* 0x40 */
} ActBtnEnt;                            /* 0x44 */

typedef struct ActBtnMgr {
    char unk000[0xF4];
    char head[0x10];                    /* 0x0F4 list head, same leading layout as an entry */
    ActBtnEnt ent[8];                   /* 0x104 */
} ActBtnMgr;

typedef struct ActBtnGameWork {
    char pad000[8];
    int unk008;                         /* 0x008 */
    char pad00C[0x178 - 0x00C];
    char unk178[0x5D8 - 0x178];         /* 0x178 */
    unsigned int flags5D8;              /* 0x5D8 */
    char pad5DC[4];
    unsigned int flags5E0;              /* 0x5E0 */
} ActBtnGameWork;

typedef struct ActBtnSceObj {
    char pad00[0x36];
    unsigned short id;                  /* 0x36 */
    char pad38[3];
    unsigned char flags3B;              /* 0x3B */
    char pad3C[0x50 - 0x3C];
    unsigned int flags50;               /* 0x50 */
} ActBtnSceObj;

extern unsigned int D_00747A80[];     /* D_007474A0 + 0x5E0: flags5E0, flags5D8 at [-2] */
#define ACTBTN_GW ((ActBtnGameWork *)((char *)D_00747A80 - 0x5E0))
extern int D_005E8140;
extern unsigned char D_005FEA60[];
extern void *D_003C2F84;
extern void Obj0000_Clear_Byte_D_003BD6E8_1380_94_Bit0_1F75B0(struct ActBtnMgr *mgr);
extern void func_001F75D0(struct ActBtnMgr *mgr);
extern void func_001F7680(struct ActBtnMgr *mgr, ActBtnEnt *ent);
extern int func_001F6FA8(ActBtnEnt *ent);
extern int func_001F7050(ActBtnEnt *ent);
extern void func_0031B410(void *a0, void *a1);
extern int cScenario_taskExec_2C38D8(void *self, void *entry, void *arg, int slot);
extern int cSceAtManager_SetDisableById(void *mgr, int id);

extern int AnimNode_stepPlayback(ActBtnEnt *ent);

void func_001F7360(ActBtnMgr *mgr)
{
    ActBtnEnt *ent;
    ActBtnSceObj *obj;

    if (D_00747A80[0] & 0x100000) {
        Obj0000_Clear_Byte_D_003BD6E8_1380_94_Bit0_1F75B0(mgr);
        func_001F75D0(mgr);
        return;
    }
    if (D_00747A80[-2] & 0x400000) {
        return;
    }
    Obj0000_Clear_Byte_D_003BD6E8_1380_94_Bit0_1F75B0(mgr);
    for (ent = (ActBtnEnt *)mgr->head; ent != 0; ent = ent->next) {
        if (ent->unk0C != 1 || ent->life == 0x31 || !func_001F7050(ent)) {
            continue;
        }
        switch (ent->kind) {
        case 0:
            func_001F7680(mgr, ent);
            if (func_001F6FA8(ent) == 1 && ent->func != 0) {
                ent->func(ent->arg);
            }
            break;
        case 1:
            func_001F7680(mgr, ent);
            if (func_001F6FA8(ent) == 1 && ent->func != 0) {
                func_0031B410(&D_005E8140, ACTBTN_GW->unk178);
                ACTBTN_GW->unk008 = 0;
                cScenario_taskExec_2C38D8(D_003C2F84, ent->func, ent->arg, -1);
            }
            break;
        case 2:
            func_001F7680(mgr, ent);
            if (func_001F6FA8(ent) == 1 && ent->func != 0) {
                func_0031B410(&D_005E8140, ACTBTN_GW->unk178);
                ACTBTN_GW->unk008 = 0;
                obj = ent->arg;
                obj->flags50 |= 0x2000000;
                ent->func(ent->arg);
                if (obj->flags3B & 0x80) {
                    cSceAtManager_SetDisableById(D_005FEA60, obj->id);
                }
            }
            break;
        case 3:
            AnimNode_stepPlayback(ent);
            break;
        }
        break;
    }
    func_001F75D0(mgr);
}

#else

INCLUDE_ASM("asm/nonmatching", func_001F7360);

#endif
