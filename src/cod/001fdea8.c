/* sn-2.95.3-136 */
#include "godhand/cDamageUnit.h"

/* A damage give record as the pool keeps it (0x60 bytes). */
typedef struct cDamagePoolGive {
    char unk00[0x49];
    unsigned char unk49;                /* 0x49 func_001FCDB8 sets 1, ResetObjectFields_1FCDE8 2, the spares get 0 */
    char unk4A[0x60 - 0x4A];
} cDamagePoolGive;

/* A damage take record as the pool keeps it (0x70 bytes). */
typedef struct cDamagePoolTake {
    char unk00[0x70];
} cDamagePoolTake;

/* The damage record pools; func_001FE1E0 hands out a spare when every give record is taken. */
typedef struct cDamagePool {
    cDamagePoolGive give[160];          /* 0x0000 */
    cDamagePoolTake take[256];          /* 0x3C00 */
    cDamagePoolGive spare[2];           /* 0xAC00 */
} cDamagePool;

extern void func_001FCDB8(char *self);
extern void ResetObjectFields_1FCDE8(void *a0);
extern void ClearFields_20_24_28_30_1FC7F8(int a0);

/* Marks a give record as a spare. */
static __inline__ void cDamagePoolGive_setSpare(cDamagePoolGive *rec)
{
    rec->unk49 = 0;
}

/* Resets every record of the damage pools and numbers the two volume node pools. */
__attribute__((section(".text.func_001FDEA8")))
void func_001FDEA8(cDamagePool *pool)
{
    cDamagePoolGive *give;
    cDamageNode *node;
    cDamageNode *bigNode;
    unsigned int i;
    unsigned int j;
    unsigned int k;

    give = pool->give;
    do {
        func_001FCDB8((char *)give);
        give++;
    } while (give < &pool->give[160]);
    for (i = 0; i < 256; i++) {
        ResetObjectFields_1FCDE8(&pool->take[i]);
    }
    cDamagePoolGive_setSpare(&pool->spare[0]);
    cDamagePoolGive_setSpare(&pool->spare[1]);
    for (j = 0, node = D_00569B80; j < 160; j++, node++) {
        ClearFields_20_24_28_30_1FC7F8((int)node);
        node->id = j;
    }
    for (k = 0, bigNode = D_0056C380; k < 512; k++, bigNode++) {
        ClearFields_20_24_28_30_1FC7F8((int)bigNode);
        bigNode->id = k;
    }
}
