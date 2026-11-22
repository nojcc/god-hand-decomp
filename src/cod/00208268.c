/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/globals.h"

extern int GetEm00CharIndex(int a, int b);
extern void *SearchData(void *a, void *b, int c);
extern int cModel_setTextureExchange(void *self, void *tex, void *tbl, int n);
extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00208268")))
int func_00208268(cEm00 *self)
{
    void *m1;
    void *m2;
    int idx;

    idx = GetEm00CharIndex(self->actorId, self->emNo);
    m1 = SearchData(self->pack, &D_0042FD50, idx);
    m2 = SearchData(self->pack, &D_0042FD58, idx);

    switch (self->emNo) {
    case 0x200:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x44) + b), 0);
            self->emNo = 0x227;
        }
        break;
    case 0x201:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x48) + b), 0);
            self->emNo = 0x228;
        }
        break;
    case 0x202:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x4C) + b), 0);
            self->emNo = 0x229;
        }
        break;
    case 0x203:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x50) + b), 0);
            self->emNo = 0x22A;
        }
        break;
    case 0x204:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x54) + b), 0);
            self->emNo = 0x22B;
        }
        break;
    case 0x240:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x64) + b), 0);
            self->emNo = 0x24A;
        }
        break;
    case 0x21A:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x58) + b), 0);
            self->emNo = 0x22C;
        }
        break;
    case 0x21D:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x70) + b), 0);
            self->emNo = 0x22E;
        }
        break;
    case 0x21E:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x68) + b), 0);
            self->emNo = 0x22F;
        }
        break;
    case 0x248:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x74) + b), 0);
            self->emNo = 0x24C;
        }
        break;
    case 0x249:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x88) + b), 0);
            self->emNo = 0x24E;
        }
        break;
    case 0x216:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x6C) + b), 0);
            self->emNo = 0x24B;
        }
        break;
    case 0x21B:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x78) + b), 0);
            self->emNo = 0x22D;
        }
        break;
    case 0x225:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x7C) + b), 0);
            self->emNo = 0x24D;
        }
        break;
    case 0x242:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x80) + b), 0);
            self->emNo = 0x243;
        }
        break;
    case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x5C) + b), 0);
            self->emNo = 0x271;
        }
        if (*(int *)((char *)self + 0x164C) & 2) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x5C) + b), 1);
            self->emNo = 0x272;
        }
        if (*(int *)((char *)self + 0x164C) & 4) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x5C) + b), 2);
            self->emNo = 0x273;
        }
        break;
    case 0x25A:
        if (*(int *)((char *)self + 0x164C) & 1) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x94) + b), 0);
        }
        if (*(int *)((char *)self + 0x164C) & 2) {
            int b = EM_RES(self);
            self->texFlags = self->texFlags | 0x10000000;
            cModel_setTextureExchange(self, m2, (void *)(*(int *)(b + 0x94) + b), 1);
        }
        break;
    }

    if (m2 != 0) {
        return cModel_setupModel(self, m1, m2, 0, 0);
    }
    return 0;
}
