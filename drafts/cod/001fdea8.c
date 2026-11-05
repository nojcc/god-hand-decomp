/* sn-2.95.3-136 */
#include "godhand/cDamageManage.h"

extern void ClearFields_20_24_28_30_1FC7F8(int a0);

/* Resets every record of the damage pools and numbers the two volume node pools. */
__attribute__((section(".text.func_001FDEA8")))
void func_001FDEA8(cDamageManage *pool)
{
    cDamageGive *give;
    cDamageNode *node;
    cDamageNode *bigNode;
    unsigned int i;
    unsigned int j;
    unsigned int k;

    give = pool->give;
    do {
        func_001FCDB8(give);
        give++;
    } while (give < &pool->give[CDAMAGE_GIVE_MAX]);
    for (i = 0; i < CDAMAGE_TAKE_MAX; i++) {
        ResetObjectFields_1FCDE8(&pool->take[i]);
    }
    pool->giveSpare.type = CDAMAGE_TYPE_SPARE;
    pool->takeSpare.type = CDAMAGE_TYPE_SPARE;
    for (j = 0, node = D_00569B80; j < 160; j++, node++) {
        ClearFields_20_24_28_30_1FC7F8((int)node);
        node->id = j;
    }
    for (k = 0, bigNode = D_0056C380; k < 512; k++, bigNode++) {
        ClearFields_20_24_28_30_1FC7F8((int)bigNode);
        bigNode->id = k;
    }
}
