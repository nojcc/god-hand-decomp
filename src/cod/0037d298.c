/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

/* voice-node allocators; D_0076A7AC selects which one is used */
extern SeqNode *(*D_003F2810[])(signed char kind);
extern int D_0076A7AC;

/* func_0037D298: take a free voice node of the given kind with the selected allocator */
__attribute__((section(".text.func_0037D298")))
SeqNode *func_0037D298(int kind)
{
    return D_003F2810[D_0076A7AC](kind);
}
