/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmWeaponSpawn.h"

/* Creates weapon object `type` at the enemy's position (CEM00_CREATE_WEAPON). */
__attribute__((section(".text.func_0026AA30")))
cOmWeapon *func_0026AA30(cEm00 *self, int type) {
    CEM00_CREATE_WEAPON(self, type)
}
