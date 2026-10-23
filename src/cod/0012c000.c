/* sn-2.95.3-136 */
#include "include_asm.h"
#include "godhand/cCoreSave.h"

/* The combo state of the object running combos (the same fields as ComboObj in 00126918.c). */
typedef struct ComboHolder {
    char unk000[0x5E0];
    unsigned short slot;                /* 0x5E0 combo slot being run */
    unsigned short set;                 /* 0x5E2 combo set */
} ComboHolder;

extern unsigned char D_005CB010;

/* Whether combo set `set` is used up: it is the holder's current set and the slot has reached the set's size. Set 0 (and any unknown set) also needs D_005CB010 clear. */
__attribute__((section(".text.func_0012C000")))
int func_0012C000(ComboHolder *self, unsigned int set)
{
    switch (set) {
    case 0:
    default:
        if (D_005CB010 != 0)
            return 0;
        if (self->set == 0 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 1:
        if (self->set == 1 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 2:
        if (self->set == 2 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 3:
        if (self->set == 3 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 4:
        if (self->set == 4 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    case 5:
        if (self->set == 5 && self->slot >= cCoreSave_getComboMax(&D_00569B70, self->set))
            return 1;
        return 0;
    }
}
