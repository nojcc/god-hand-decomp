/* NON_MATCHING func_00148420 (sn-2.95.3-136): one word short. This copies the mesh data
 * argument to another register before its stack home is written, and the small-mesh arm
 * keeps the new buffer in a register where retail reads pktBuf back. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cModel.h"
#include "godhand/heapArena.h"

#define NODE_PKT_ALIGN  0x10

struct node;
extern int func_00155138(cModelNode *node);
extern int func_00155248(cModelNode *node);
extern void func_00154A90(cModelNode *node, int buf, int c);
extern void func_00155358(cModelNode *node, int buf, int c);
extern void func_00148F50(cModelNode *node, cMeshData **data, void *box);
extern void func_001490B0(cModelNode *node, cMeshData **data, void *box);
extern void cHeap_free(int heap, struct node *p);
extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);

/* Set the node up like func_001485A0, but give it a packet buffer of its own
 * from `heap` (the default arena when 0), freeing the old one. Returns 0 when
 * the buffer can't be allocated. */
__attribute__((section(".text.func_00148420")))
int func_00148420(cModelNode *node, cMeshData *data, int b, int flags, int n, void *box, HeapArena *heap)
{
    int big;
    unsigned short num;

    node->unk400 = b;
    node->unk384 = 0;
    node->dispFlags = flags;
    node->tag = 0;
    node->data = data;
    num = data->num;
    node->meshNum = num;
    if (node->pktBuf != 0) {
        cHeap_free(*(int *)(node->pktBuf - 0x20), (struct node *)node->pktBuf);
    }
    big = data->num >= 2;
    if (big) {
        int size = func_00155138(node);

        if (heap == 0) {
            node->pktBuf = (int)EnsureInitThenForward_2A9538_30EE08(size, NODE_PKT_ALIGN, (int)D_003C3CF0);
            if (node->pktBuf == 0) {
                return 0;
            }
            func_00154A90(node, node->pktBuf, 0);
        } else {
            node->pktBuf = (int)EnsureInitThenForward_2A9538_30EE08(size, NODE_PKT_ALIGN, (int)heap);
            if (node->pktBuf == 0) {
                return 0;
            }
            func_00154A90(node, node->pktBuf, (int)heap);
        }
    } else {
        int size = func_00155248(node);

        node->pktBuf = (int)EnsureInitThenForward_2A9538_30EE08(size, NODE_PKT_ALIGN,
                                                               heap != 0 ? (int)heap : (int)D_003C3CF0);
        if (node->pktBuf == 0) {
            return 0;
        }
        func_00155358(node, node->pktBuf, 0);
    }
    if (flags & 0x01000000) {
        func_00148F50(node, &data, box);
    } else {
        func_001490B0(node, &data, box);
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00148420);
#endif
