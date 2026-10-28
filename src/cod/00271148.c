/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/pl00.h"
#include "godhand/player.h"
#include "godhand/angle.h"

extern void func_002DC260(void *arg);
extern void func_002DC5E0(void *arg);

/* Starts the enemy's reaction to the player (func_002DC5E0 for enemy 0x20F,
 * func_002DC260 otherwise) when it is behind the player: the player is not
 * flashing from a hit, has no object at sub6A0, would turn at least 100
 * degrees to face the enemy, and is within half a unit of its height and
 * closer than 4.0. */
__attribute__((section(".text.func_00271148")))
void func_00271148(cEm00 *self)
{
    pl00 *player = (pl00 *)Getplayer();
    cVec *from;
    float turn;
    float dy;

    if (0.0f < player->base.hitFlash) {
        return;
    }
    if (player->sub6A0 != 0) {
        return;
    }
    from = Getplayer()->pos;
    turn = Turn_dest(&from->x, &self->pos->x, Getplayer()->rot[1], 3.1415927f);
    turn = absf(turn);
    if (turn < 1.7453293f) {
        return;
    }
    dy = player->base.pos->y - self->pos->y;
    dy = absf(dy);
    if (0.5f < dy) {
        return;
    }
    if (self->playerDist < 4.0f) {
        if (self->emNo != 0x20F) {
            func_002DC260(self);
        } else {
            func_002DC5E0(self);
        }
    }
}
