/* NON_MATCHING cSnd_GetStageBgmReq (PARK): C++ bool idiom: retail 'v0=0; bnez busy; v0=1; andi 0xFF; bnez' (QImode store-flag fallback); C folds to a direct branch, shifting the rest */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSnd.h"

typedef struct Mode2D0D70 {
    char pad000[0x48];
    int mode;
    char pad04C[0xEE8 - 0x4C];
    int busy;
} Mode2D0D70;

typedef struct Ovr2D0D70 {
    int flags;
    char pad04[4];
    unsigned short bgm;
} Ovr2D0D70;

typedef struct Req2D0D70 {
    char pad000[0x13C];
    int kind;
} Req2D0D70;

extern Mode2D0D70 *D_003BD930;
extern Ovr2D0D70 *D_00586B28;
extern unsigned short D_00583EEC;
extern unsigned char D_005CB010;
extern cSndKindEnt *func_002D0B88(int id);
extern int cSnd_BgmReqFromEnemies(Req2D0D70 *self);

static inline unsigned char Mode2D0D70_idle(Mode2D0D70 *m)
{
    unsigned char r = 0;

    if (m->busy == 0) {
        r = 1;
    }
    return r;
}

int cSnd_GetStageBgmReq(Req2D0D70 *self, unsigned short stage)
{
    Mode2D0D70 *m = D_003BD930;
    cSndKindEnt *e;
    unsigned short id;
    int r;

    if ((m->mode == 3 || m->mode == 12) && !Mode2D0D70_idle(m)) {
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
    if (self->kind == 1) {
        return e->param[1];
    }
    r = cSnd_BgmReqFromEnemies(self);
    if (r != -2) {
        return r;
    }
    switch (self->kind) {
    case 2:
        return e->param[2];
    case 3:
        return e->param[3];
    case 4:
        return e->param[4];
    default:
        return e->param[0];
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cSnd_GetStageBgmReq);
#endif
