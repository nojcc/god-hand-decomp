/* NON_MATCHING func_002CABE8 (sn-2.95.3-136): only the saved-register choice for the hit-scale array
 * pointer (s4 here, s0 in retail) and the hoisted %hi(D_0044CE38) (s0 here, s4 in retail) differ.
* Retail's copy of
 * that lui on the SeLoadNo fallback path carries no relocation in the split asm (raw 0x45), so it may not reloc-match
 * even once registers agree.
* Sound system init: look up the sound tables, load the sound group, open the root / sub
 * sound heaps, load the stage SE bank (or the default) and wait for it, then reset the volume tables. */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct SndGroupEnt {
    short bank;                         /* 0x00 */
    char pad02[0xA];
    short altBank;                      /* 0x0C */
    char pad0E[0xA];
} SndGroupEnt;

typedef struct SndSetting {
    char pad00[4];
    float version;                      /* 0x04 */
    char pad08[4];
    int subHeapSize;                    /* 0x0C */
    int group;                          /* 0x10 */
} SndSetting;

extern unsigned char D_007474A0[];
extern char D_0044CCB0[];
extern char D_0044CCB8[];
extern char D_0044CE38[];
extern SndGroupEnt D_0044CCC0[];
extern char D_00603310[];
extern char D_006036A0[];
extern void *SearchData(void *name, void *table, int which);
extern void cSnd_loadSoundGroup(void *self, int group);
extern int func_00374AE0(int bank);
extern void cSndMemHeap_OpenRoot(void *heap, int base, int size);
extern void cSndMemHeap_OpenSub(void *heap, void *parent, int size);
extern int cSnd_SeLoadNo(void *self, int slot, int no);
extern int cSnd_SeIsLoaded(void *self, int slot);
extern void cScenario_sleepFrames(int frames);
extern void func_002CB080(void *self, void *data);
extern float cSnd_GetBgmHitScale(void *self);

static inline unsigned char *game(void)
{
    return D_007474A0;
}

__attribute__((section(".text.func_002CABE8")))
void func_002CABE8(char *p)
{
    SndSetting *set;
    SndGroupEnt *ent;
    void *d;
    int group;
    int subSize;
    int rootSize;
    int i;
    float *se;
    float *bgm;
    float *hit;

    subSize = 0xC8000;
    *(void **)(p + 0x24) = SearchData(*(void **)(game() + 0x5AC), D_0044CCB8, 0);
    set = SearchData(*(void **)(game() + 0x5AC), D_0044CCB0, 0);
    *(SndSetting **)(p + 0x20) = set;
    group = 0;
    if (set != 0) {
        if (set->version == 1.1f) {
            subSize = set->subHeapSize;
            group = set->group;
        } else {
            *(SndSetting **)(p + 0x20) = 0;
        }
    }
    cSnd_loadSoundGroup(p, group);
    rootSize = 0xFFFC0;
    if (D_0044CCC0[*(int *)(p + 0x130)].altBank != 0)
        rootSize = 0xDFFC0 - func_00374AE0(D_0044CCC0[*(int *)(p + 0x130)].altBank);
    else
        rootSize -= func_00374AE0(D_0044CCC0[*(int *)(p + 0x130)].bank);
    cSndMemHeap_OpenRoot(D_00603310, 0x100000, rootSize);
    cSndMemHeap_OpenSub(D_006036A0, D_00603310, subSize);
    if (cSnd_SeLoadNo(p, 2, *(unsigned short *)(game() + 0x5B0)) == 0)
        cSnd_SeLoadNo(p, 2, 0x100);
    hit = (float *)(p + 0x88);
    se = (float *)(p + 0x60);
    bgm = (float *)(p + 0x74);
    while (cSnd_SeIsLoaded(p, 2) == 0)
        cScenario_sleepFrames(1);
    d = SearchData(*(void **)(game() + 0x5AC), D_0044CE38, 0);
    *(void **)(p + 0x28) = d;
    func_002CB080(p, d);
    *(float *)(p + 0x9C) = 1.0f;
    *(float *)(p + 0xA0) = cSnd_GetBgmHitScale(p);
    for (i = 0; i < 5; i++) {
        se[i] = bgm[i] = *(float *)(p + 0x9C);
        hit[i] = *(float *)(p + 0xA0);
    }
    *(int *)(p + 0x118) = -1;
    *(int *)(p + 0x11C) = -2;
    *(int *)(p + 0x120) = -1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002CABE8);
#endif
