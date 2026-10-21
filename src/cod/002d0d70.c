/* sn-2.95.3-136 */
/* sn-2.95.3-136 */
#include "godhand/cSnd.h"

/* View of the game-mode object D_003BD930 (no header covers it yet). */
typedef struct BgmGameMode {
    char pad000[0x48];
    int mode;                   /* 0x48 */
    char pad04C[0xEE8 - 0x4C];
    int busy;                   /* 0xEE8 */
} BgmGameMode;

/* View of the bgm override record D_00586B28 points at. */
typedef struct BgmOverride {
    int flags;                  /* 0x00 bit 0: use bgm */
    char pad04[4];
    unsigned short bgm;         /* 0x08 */
} BgmOverride;

extern BgmGameMode *D_003BD930;
extern BgmOverride *D_00586B28;
extern unsigned short D_00583EEC;
extern unsigned char D_005CB010;

static __inline__ unsigned char bgmGameMode_isIdle(BgmGameMode *m)
{
    if (m->busy != 0) {
        return 0;
    }
    return 1;
}

/* Pick the bgm request for a stage from the override, the enemies present and the bgm state. */
__attribute__((section(".text.cSnd_GetStageBgmReq")))
int cSnd_GetStageBgmReq(cSnd *self, unsigned short stage)
{
    BgmGameMode *m = D_003BD930;
    cSndKindEnt *e;
    unsigned short id;
    int r;

    if ((m->mode == 3 || m->mode == 12) && !bgmGameMode_isIdle(m)) {
        if (D_00586B28->flags & 1) {
            id = D_00586B28->bgm;
        } else {
            id = D_00583EEC;
        }
        return func_002D0B88(stage != 0x21 ? id : 0x100)->param[0];
    }
    if (D_005CB010 != 0) {
        return 10;
    }
    e = func_002D0B88(stage);
    if (self->bgmState == 1) {
        return e->param[1];
    }
    r = cSnd_BgmReqFromEnemies(self);
    if (r != -2) {
        return r;
    }
    switch (self->bgmState) {
    case 2:
        return e->param[2];
    case 3:
        return e->param[3];
    case 4:
        return e->param[4];
    case 0:
    default:
        return e->param[0];
    }
}
