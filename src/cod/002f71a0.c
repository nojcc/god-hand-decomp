#include "godhand/vu0.h"
extern void *StoreVecFromFieldB0_2B6160(void *dst, void *node);
#include "godhand/cNode.h"

extern void *func_002B6310(void *dst, void *node);

__attribute__((section(".text.func_002F71A0")))
void *func_002F71A0(void *out, void *node, void *add)
{
    char buf[0x30];
    char *work;

    func_002B6310(buf, node);
    work = buf + 0x20;
    VU0_LQC2(4, buf, 0);
    VU0_SQC2(4, buf, 0x20);
    VU0_VADD_XYZ_IP(buf, 0x20, add);
    VU0_LQC2(4, work, 0);
    VU0_SQC2(4, buf, 0x10);
    cNode_setLocalTranslation(node, (cVec *)(buf + 0x10));
    StoreVecFromFieldB0_2B6160(work, node);
    cNode_setLocalTranslation(node, (cVec *)buf);
    VU0_LQC2(4, work, 0);
    VU0_SQC2(4, out, 0);
    return out;
}

