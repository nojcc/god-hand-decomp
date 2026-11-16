/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cWorldLight.h"

extern unsigned char D_0061B289;
extern int D_003C118C;

__attribute__((section(".text.func_002C7F88")))
int func_002C7F88(unsigned char *p){unsigned int v;if(p==0)return 0;v=p[0]|(p[1]<<8)|(p[2]<<16)|(p[3]<<24);return (v^0x514553)==0;}

/* Finds the first block with at least this many free bytes behind it. */
__attribute__((section(".text.cSndMemHeap_FindFitBlk")))
cSndMemBlk *cSndMemHeap_FindFitBlk(cSndMemHeap *heap, unsigned int size) {
    cSndMemBlk *p = heap->self;

    while (p != 0) {
        if ((unsigned int)p->freeSize >= size) {
            return p;
        }
        p = p->prev;
    }
    return 0;
}

__attribute__((section(".text.cSnd_FindBgmNode")))
cSndBgmNode *cSnd_FindBgmNode(cSnd *self, int bank, int reqNo)
{
    cSndBgmNode *node = self->bgmHead;
    while (node != 0) {
        if (node->bank - 0x80 == bank && node->reqNo == reqNo)
            return node;
        node = node->next;
    }
    return 0;
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002D42B0")))
int func_002D42B0(char *p)
{
    if (*(int *)p == 0) {
        return 0;
    }
    return *(int *)(*(char **)(p + 0x8) + 0x24);
}

__attribute__((section(".text.func_002D65F8")))
void func_002D65F8(CustomIDWork *self, float x, float y, float z, float w) {
    if (self->obj != 0) {
        self->obj->f70[0] = x;
        self->obj->f70[1] = y;
        self->obj->f70[2] = z;
        self->obj->f70[3] = w;
    }
}

__attribute__((section(".text.func_002D69A8")))
void func_002D69A8(CustomIDWork *self, unsigned short frames, float from, float to)
{
    cIDBaseEnt *obj = self->obj;

    if (obj == 0)
        return;
    self->scaleFlags = CIDW_ANIM_ON | CIDW_ANIM_LINEAR;
    self->scaleX[0] = from;
    self->scaleX[1] = to;
    self->scaleY[0] = obj->sclY;
    self->scaleY[1] = obj->sclY;
    self->scaleTotal = frames;
    if (frames == 0)
        self->scaleTotal = 1;
    self->scaleCount = 0;
}

/* Returns light idx. */
__attribute__((section(".text.cWorldLight_Get_LightData")))
cWorldLightRec *cWorldLight_Get_LightData(cWorldLight *self, int idx)
{
    return &self->light[idx];
}

__attribute__((section(".text.func_002E0AE0")))
int func_002E0AE0(int x) {
    int m = D_0061B289;

    if (x < -m) {
        return 1;
    }
    return (D_003C118C * 2 + m) < x;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002E16D8")))
int func_002E16D8(char *this) {
    char *p = *(char **)(this + 0x110);

    *(float *)(this + 0x2B0) = *(float *)(p + 0x13C);
    *(float *)(this + 0x2B4) = *(float *)(p + 0x140);
    *(float *)(this + 0x2B8) = *(float *)(p + 0x144);
    *(float *)(this + 0x2BC) = *(float *)(p + 0x148);
    *(int *)(this + 0x2C0) = *(int *)(p + 0x16C);
    return 1;
}
