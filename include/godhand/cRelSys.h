/* include/godhand/cRelSys.h - the relocatable-module slots.
 *
 * A slot holds a module file read into the heap; linking it registers the
 * module's table with the registry (regTbl.h). D_005E8640 is the game's slot
 * array; the functions that take `slots` and an index work on slots[idx]. */
#ifndef GODHAND_CRELSYS_H
#define GODHAND_CRELSYS_H

typedef struct cRelSlot {
    void *data;                         /* 0x00 file contents, 0 when none */
    unsigned char ok;                   /* 0x04 link result, 1 while linked */
    char pad05[3];
} cRelSlot;                             /* 0x08 */

typedef char cRelSlot_size_check[(sizeof(cRelSlot) == 8) ? 1 : -1];

extern cRelSlot D_005E8640[];

/* Clear the slot. */
cRelSlot *func_002BE550(cRelSlot *self);
/* Read the file name into the slot and link it; on failure free it again. Returns ok. */
unsigned char cRelSys_loadSlot(cRelSlot *slot, const char *name);
/* Unlink the slot, free its data and clear it. */
void HeapBuf_release(cRelSlot *slot);
/* Link data, already in memory, into the slot; returns ok. */
unsigned char SetValueAndValidate_2BE630(cRelSlot *slot, void *data);
/* Unlink the slot and clear it without freeing the data. */
void func_002BE670(cRelSlot *slot);
/* Register the slot's module (func_00394DD8); 1 when that succeeded. */
int func_002BE6A0(cRelSlot *slot);
/* Unregister the slot's module (func_00394F20). */
int func_002BE6C8(cRelSlot *slot);
/* Reset the registry (func_00394D58(0)); slots is not read. */
void func_002BE6E8(cRelSlot *slots);
/* Load the module for room id into slots[0]. */
void func_002BE708(cRelSlot *slots, int id);
/* Release slots[0]. */
void func_002BE818(cRelSlot *slots);
/* Load the file name into slots[idx]. */
void func_002BE838(cRelSlot *slots, const char *name, int idx);
/* Release slots[idx] if it is linked. */
void func_002BE858(cRelSlot *slots, int idx);
/* Link data into slots[idx] and return ok; unused is not read. */
unsigned char cRelSys_linkNoAlloc(cRelSlot *slots, void *data, void *unused, int idx);
/* Unlink slots[idx] without freeing its data, if it is linked. */
void cRelSys_unlinkNoFree(cRelSlot *slots, int idx);

#endif /* GODHAND_CRELSYS_H */
