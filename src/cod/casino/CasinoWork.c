/* TU: CasinoWork [casino] - recovered C++ class. */
#include "godhand/cCoreSave.h"
#include "godhand/player.h"

/* The player state saved for the casino warm-up room. */
typedef struct CasinoWork {
    int flags;                  /* 0x0 bit 0 cleared once the state is restored */
    int vital;                  /* 0x4 */
    float heat;                 /* 0x8 */
    short levelPoint;           /* 0xC */
    unsigned short godItemNum;  /* 0xE */
} CasinoWork;

/* Restore the saved vital, heat, level points and god items to the player, then clear bit 0 of flags. */
__attribute__((section(".text.CasinoWork_ResetWarmUpRoom")))
void CasinoWork_ResetWarmUpRoom(CasinoWork *self)
{
    cGameObj *pl;
    int i;
    int v;

    pl = Getplayer();
    v = self->vital;
    if (v >= pl->hpMax) {
        pl->hp = pl->hpMax;
    } else {
        pl->hp = v;
    }
    cCoreSave_setVital(&D_00569B70, self->vital);
    cHeatSys_SetHeatGage(&D_005CB000, self->heat);
    cCoreSave_setLevelPoint(&D_00569B70, self->levelPoint);
    cCoreSave_clearGodItem(&D_00569B70);
    for (i = 0; i < self->godItemNum; i++) {
        cCoreSave_addGodItem(&D_00569B70, 1);
    }
    self->flags &= ~1;
}
