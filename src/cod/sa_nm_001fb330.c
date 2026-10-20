/* NON_MATCHING cCoreSave_spawnItems (sn-2.95.3-136 "as": "sn", 104 vs 106 words: retail keeps only %hi(D_007474A0) in s4 and redoes the %lo add each iteration, adds (i << 4) + data with the shift first, and loads obj->pos after the multiply) */
#include "include_asm.h"

#ifdef NON_MATCHING
/* cCoreSave_spawnItems, spawns the saved items placed on the current stage: each of the
 * 128 item records (16 bytes at 0x28A of the save data) whose stage matches gets an object with its id, flags,
 * position (decimetres), heading (half degrees) and kind. */
typedef struct VtEnt1FB330 {
    short delta;
    short index;
    void (*pfn)(void *self);
} VtEnt1FB330;

typedef struct Item1FB330 {
    unsigned short stage;               /* 0x00 */
    unsigned short id;                  /* 0x02 */
    unsigned char kind;                 /* 0x04 */
    signed char heading;                /* 0x05 */
    unsigned short flags;               /* 0x06 */
    short pos[3];                       /* 0x08 */
    unsigned short param;               /* 0x0E */
} Item1FB330;

typedef struct SaveData1FB330 {
    char pad000[0x28A];
    Item1FB330 item[128];               /* 0x28A */
} SaveData1FB330;

typedef struct CoreSave1FB330 {
    SaveData1FB330 *data;               /* 0x00 */
} CoreSave1FB330;

typedef struct ItemObj1FB330 {
    char pad000[0xF0];
    float *pos;                         /* 0x0F0 */
    char pad0F4[0x104 - 0xF4];
    float heading;                      /* 0x104 */
    char pad108[0x214 - 0x108];
    VtEnt1FB330 *vt;                    /* 0x214 */
    char pad218[0x560 - 0x218];
    int param;                          /* 0x560 */
    char pad564[0x662 - 0x564];
    unsigned short flags;               /* 0x662 */
    char pad664[0x676 - 0x664];
    unsigned char kind;                 /* 0x676 */
} ItemObj1FB330;

extern char D_007474A0[];

static inline char *gw1FB330(void) { return D_007474A0; }
#define GW_STAGE (*(unsigned short *)(gw1FB330() + 0x5B0))
#define GW_AREA  (*(unsigned char *)(gw1FB330() + 0x5B1))
extern ItemObj1FB330 *CreateObj(int id, int a1);

#define VT_ITEM_INIT 8

__attribute__((section(".text.cCoreSave_spawnItems")))
void cCoreSave_spawnItems(CoreSave1FB330 *self)
{
    unsigned int i;
    ItemObj1FB330 *obj;
    VtEnt1FB330 *ent;

    if (GW_AREA == 0)
        return;
    if (self->data == 0)
        return;
    for (i = 0; i < 128; i++) {
        if (self->data->item[i].stage != GW_STAGE)
            continue;
        obj = CreateObj(self->data->item[i].id, 0xFFFF);
        if (obj == 0)
            continue;
        obj->flags = self->data->item[i].flags;
        ent = &obj->vt[VT_ITEM_INIT];
        ent->pfn((char *)obj + ent->delta);
        obj->param = self->data->item[i].param;
        obj->pos[0] = (float)self->data->item[i].pos[0] * 0.1f;
        obj->pos[1] = (float)self->data->item[i].pos[1] * 0.1f;
        obj->pos[2] = (float)self->data->item[i].pos[2] * 0.1f;
        obj->heading = (float)self->data->item[i].heading * 2.0f * 0.017453292f;
        obj->kind = self->data->item[i].kind;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cCoreSave_spawnItems);
#endif
