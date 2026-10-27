/* sn-2.95.3-136 */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/cModel.h"
#include "godhand/heapArena.h"
#include "godhand/mdlPkt.h"

extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);
extern cModelNode *cModel_getMeshPtr(cModel *self, int n);
extern void func_00155BE8(char *arg0, int arg1, int arg2);
extern void func_00155AE8(MdlPktBuf *pkt, int id, int buf);
extern unsigned char D_00604700[];

/* Parts a model's matrix buffer has room for. */
#define MODEL_PART_MAX 42
/* Quadwords of a matrix buffer for n parts: four per part and one tag. */
#define MODEL_PART_QWC(n) ((MODEL_PART_MAX * 4 + 1) - (MODEL_PART_MAX - (n)) * 4)

/* The head of a model's draw packet (packet[parity], 0x80 bytes). */
typedef struct cModelPacketHead {
    unsigned long tailRef;              /* 0x00 DMA ref to the tail packet */
    unsigned int pad08[2];
    unsigned long cnt10;                /* 0x10 DMA cnt, 2 qwords */
    unsigned int flush;                 /* 0x18 VIF FLUSH */
    unsigned int direct;                /* 0x1C VIF DIRECT, 2 qwords */
    unsigned long giftag;               /* 0x20 GIF tag: one A+D register */
    unsigned int regs;                  /* 0x28 */
    unsigned int pad2C;
    unsigned long rgb;                  /* 0x30 */
    unsigned long reg;                  /* 0x38 */
    unsigned long partRef;              /* 0x40 DMA ref to the matrix buffer */
    unsigned int pad48[2];
    unsigned long cnt50;                /* 0x50 DMA cnt */
    unsigned int pad58[2];
    unsigned long cnt60;                /* 0x60 DMA cnt */
    unsigned int pad68[2];
    unsigned long end;                  /* 0x70 DMA end */
    unsigned int pad78;
    unsigned int flush7C;               /* 0x7C VIF FLUSH */
} cModelPacketHead;

/* A 64-bit DMA ref tag: qwc and id in the low word, the address (28 bits) in the high word. */
#define DMA_REF_TAG(tag, addr) ((unsigned long)((unsigned int)(addr) & 0x0FFFFFFF) << 32 | (tag))

/* Allocate a model's packet block (both frames' draw packets, tail packets,
 * matrix buffers and the child list), list the parts as children and build
 * the two draw packets. Returns 0 when the block can't be allocated.
 * Still differs from retail: retail keeps the block size in a temporary that
 * each arm of the arena choice moves into the first argument, where ours
 * computes it straight into that register; the register numbering of the
 * rest follows from that. */
__attribute__((section(".text.func_0014BFE0")))
int func_0014BFE0(cModel *self)
{
    unsigned long partTag;
    char **heads;
    char **tails;
    char *p;
    cParts *part;
    int frame = 0;
    int i;
    int n = self->partNum;
    int size = MODEL_PART_QWC(n) * 32 + 0x3A0 + n * 4;

    if (self->arena != 0)
        p = EnsureInitThenForward_2A9538_30EE08(size, 0x40, (int)self->arena);
    else
        p = EnsureInitThenForward_2A9538_30EE08(size, 0x40, (int)D_003C3CF0);
    if (p == 0)
        return 0;
    self->alloc = p;
    self->packet[0] = p;
    p += 0x80;
    self->packet[1] = p;
    p += 0x80;
    self->tailPacket[0] = p;
    p += 0x150;
    self->tailPacket[1] = p;
    p += 0x150;
    heads = self->packet;
    tails = self->tailPacket;
    self->partPacket[0] = p;
    p += MODEL_PART_QWC(n) * 16;
    self->partPacket[1] = p;
    p += MODEL_PART_QWC(n) * 16;
    self->children = (struct cOmBase **)p;
    part = self->next;
    i = 0;
    do {
        if (i >= self->partNum)
            break;
        self->children[i] = (struct cOmBase *)part;
        part = part->next;
        i++;
    } while (part != 0);
    partTag = (unsigned int)(MODEL_PART_QWC(n) | 0x30000000);
    for (; frame != 2; frame++) {
        cModelPacketHead *head = (cModelPacketHead *)heads[frame];
        unsigned int *tail = (unsigned int *)tails[frame];
        cModelNode *mesh;

        if (head == 0 || tail == 0)
            return 0;
        head->tailRef = DMA_REF_TAG(0x30000015, tail);
        head->pad08[0] = 0;
        head->pad08[1] = 0;
        tail[3] = 0x6C1400C0;
        tail[0] = 0;
        tail[1] = 0;
        tail[2] = 0x01000404;
        head->cnt10 = 0x10000002;
        head->direct = 0x50000002;
        head->giftag = 0x1000000000008001;
        head->regs = 0xE;
        head->flush = 0x11000000;
        head->pad2C = 0;
        head->reg = 0x3D;
        head->rgb = D_00604700[4] | (unsigned long)D_00604700[5] << 8 | (unsigned long)D_00604700[6] << 16;
        if (self->partPacket[frame] == 0)
            return 0;
        ((unsigned int *)self->partPacket[frame])[0] = 0;
        ((unsigned int *)self->partPacket[frame])[1] = 0;
        ((unsigned int *)self->partPacket[frame])[2] = 0x01000404;
        ((unsigned int *)self->partPacket[frame])[3] = 0x6C000000 | (MODEL_PART_QWC(n) - 1) << 16;
        head->pad48[0] = 0;
        head->pad48[1] = 0;
        head->cnt50 = 0x10000000;
        head->partRef = DMA_REF_TAG(partTag, self->partPacket[frame]);
        head->pad58[0] = 0;
        head->pad58[1] = 0;
        head->cnt60 = 0x10000000;
        head->pad68[0] = 0;
        head->pad68[1] = 0;
        func_00155BE8((char *)self, 2, frame);
        for (mesh = cModel_getMeshPtr(self, 0); mesh != 0; mesh = mesh->next)
            func_00155AE8((MdlPktBuf *)mesh, 0x80000002, frame);
        head->flush7C = 0x11000000;
        head->end = 0x70000000;
        head->pad78 = 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0014BFE0);
#endif
