/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

extern void func_0032EC78(int ply, int ch, int vol);

/* Lane-local: the player handle at +0x20 of MenuSndInfo; menuCtl.h has it as padding. */
#define MENUSND_PLY(info) (*(int *)((char *)(info) + 0x20))

/* Send the picked slot's level to the player: slot 0 is the master, which first copies its level
 * and index to the four channels and then sets every unmuted channel; any other slot sets its own
 * channel unless it is muted. self is not read. */
__attribute__((section(".text.func_003820C0")))
void func_003820C0(MenuCtl *self, MenuSnd *snd)
{
    /* the sound info follows the sound settings in MenuCtl */
    MenuSndInfo *info = (MenuSndInfo *)(snd + 1);
    int i;

    if (snd->slot == 0) {
        int j;

        for (j = 0; j < 4; j++) {
            snd->index[1 + j] = snd->index[0];
            snd->level[1 + j] = snd->level[0];
        }
    }
    if (MENUSND_PLY(info) == 0)
        return;
    if (snd->slot != 0) {
        if (info->mute[snd->slot] == 0)
            func_0032EC78(MENUSND_PLY(info), snd->slot - 1, snd->level[snd->slot]);
        return;
    }
    for (i = 0; i < info->track; i++) {
        if (info->mute[i + 1] == 0)
            func_0032EC78(MENUSND_PLY(info), i, snd->level[snd->slot]);
    }
}
