/* NON_MATCHING func_002BF948 (sn-2.95.3-136): one-insn shift - retail spills cont/allCont and keeps &skill in fp, ours keeps cont in s8; copies need the aligned(16) typedef trick (size 0xD8, align 16) */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cCoreSave.h"

extern void *Getplayer(void);
extern void cSaveManager_getCheckPoint(void *mgr, int a);

typedef struct { short v[5]; } Kill5;
typedef struct { unsigned char v[10]; } Reel10 __attribute__((aligned(8)));
typedef struct { cCoreSaveCombo c[CORESAVE_COMBO_SETS]; } ComboBlk __attribute__((aligned(16)));
typedef struct { char s[0x80]; } SkillBlk __attribute__((aligned(16)));

static inline int ckFlag(unsigned int f, unsigned int m)
{
    return (f & m) != 0;
}

void func_002BF948(void *mgr)
{
    ComboBlk combo;
    SkillBlk skill;
    Kill5 kill;
    Kill5 allKill;
    Reel10 reel;
    short lvl;
    int gold;
    unsigned short cont;
    unsigned short allCont;
    int toggle;
    int active;
    int saved;
    int stateBits;
    unsigned int godReel;
    int flag;
    char *pl;

    lvl = cCoreSave_getGameLevelPoint(&D_00569B70);
    gold = cCoreSave_getGold(&D_00569B70);
    cont = cCoreSave_getContinueNum(&D_00569B70);
    allCont = cCoreSave_getAllContinueNum(&D_00569B70);
    flag = ckFlag(D_00569B70.data->flags, 0x10000000);
    godReel = D_00569B70.data->godReel;
    combo = *(ComboBlk *)D_00569B70.data->combo;
    skill = *(SkillBlk *)D_00569B70.data->skill;
    kill = *(Kill5 *)D_00569B70.data->killEmNum;
    allKill = *(Kill5 *)D_00569B70.data->allKillEmNum;
    reel = *(Reel10 *)D_00569B70.data->reelSlot;
    stateBits = D_00569B70.data->stateBits;
    toggle = D_00569B70.data->worldToggle;
    active = D_00569B70.data->worldActive;
    saved = D_00569B70.data->savedToggle;
    pl = Getplayer();
    {
        int paper = *(int *)(pl + 0x6A8) != 0;

        cSaveManager_getCheckPoint(mgr, 0);
        D_00569B70.data->paper = paper;
    }
    cCoreSave_setLevelPoint(&D_00569B70, lvl);
    cCoreSave_setGold(&D_00569B70, gold);
    cCoreSave_setVital(&D_00569B70, cCoreSave_getVitalMax(&D_00569B70));
    cCoreSave_setContinueNum(&D_00569B70, cont);
    D_00569B70.data->allContinueNum = allCont;
    D_00569B70.data->godReel = godReel;
    if (flag)
        D_00569B70.data->flags |= 0x10000000;
    else
        D_00569B70.data->flags &= ~0x10000000;
    if (cCoreSave_getGodItemNum(&D_00569B70) == 0)
        cCoreSave_addGodItem(&D_00569B70, 1);
    *(ComboBlk *)D_00569B70.data->combo = combo;
    *(SkillBlk *)D_00569B70.data->skill = skill;
    *(Kill5 *)D_00569B70.data->killEmNum = kill;
    *(Kill5 *)D_00569B70.data->allKillEmNum = allKill;
    *(Reel10 *)D_00569B70.data->reelSlot = reel;
    D_00569B70.data->worldToggle = toggle;
    D_00569B70.data->worldActive = active;
    D_00569B70.data->savedToggle = saved;
    D_00569B70.data->stateBits = stateBits;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002BF948);
#endif
