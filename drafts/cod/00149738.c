/* NON_MATCHING cModel_setupModel (sn-2.95.3-136): retail keeps a dead stack copy of the first mesh data pointer at sp+0x20 (pushing the arg spill to 0x24) and tests num >= 2 via sltiu/xori; the error tails cross-jump differently */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cModel.h"

extern unsigned int D_00747A24;
extern void cModel_removeMesh(cModel *self);
extern void func_00149E60(cModel *self);
extern int func_00149C20(cModel *self, void *data);
extern cModelNode *GetActiveState_149310(void);
extern void cBoundingBox(cBox *box);
extern int func_00148420(cModelNode *node, void *data, char *tex, int flags, int arg, cBox *box, void *arena);
extern void cModel_addMesh(cModel *self, cModelNode *node, cBox *box);
extern void func_001F8A60(cBox *box, int mode);
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern int func_0014C328(cModel *self);
extern int func_0014BFE0(cModel *self);

typedef struct {
    cBox b;
    char pad[8];
} Bb149;

int cModel_setupModel(cModel *self, cModelScript *script, char *tex, int arg, int kind)
{
    Bb149 box;
    cMeshData *d;
    cModelNode *node;
    cMeshInfo *info;
    char *data;
    int i;
    int mode;
    int found;

    {
        int *p = (int *)self->pos;

        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
    }
    D_00747A24 &= ~0x800000;
    D_00747A24 &= ~0x400000;
    D_00747A24 &= ~0x200000;
    self->drawPrio = 1;
    if (script == 0)
        return 0;
    mode = (kind == 1) ? 0x2000000 : 0;
    self->script = (char *)script;
    self->texSet = (int)tex;
    if (mode == 0 && tex[0] == 'T' && tex[2] == '3')
        mode = (*(int *)(tex + 0xC) != 0) ? 0x4000000 : 0x8000000;
    for (i = 0; i < script->meshNum; i++) {
        long t;

        info = (cMeshInfo *)(script->meshOfs[i] + (int)script);
        data = (char *)(info->dataOfs + (int)info);
        if (i == 0) {
            cModel_removeMesh(self);
            func_00149E60(self);
            if (func_00149C20(self, data) == 0) {
                D_00747A24 |= 0x800000;
                return 0;
            }
        }
        node = GetActiveState_149310();
        if (node == 0) {
            D_00747A24 |= 0x400000;
            return 0;
        }
        cBoundingBox(&box.b);
        if (func_00148420(node, data, tex, mode | 0x1080, arg, &box.b, self->arena) == 0) {
            D_00747A24 |= 0x200000;
            func_001F8A60(&box.b, 2);
            return 0;
        }
        node->info = info;
        if (info->alpha != 0) {
            node->dispFlags |= 0x20000000;
            self->texFlags |= 0x20000000;
        }
        if (info->flags & 0x2000)
            node->dispFlags |= 0x40000000;
        node->layer = info->layer;
        if (info->flags & 0x100000)
            node->dispFlags |= 0x800000;
        t = *(int *)&info->flags;
        if ((((unsigned long)t >> 3) & 1UL) == 1UL)
            node->tag |= 0x20000000;
        cModel_addMesh(self, node, &box.b);
        func_001F8A60(&box.b, 2);
    }
    {
        cModelNode *n;

        found = 0;
        for (n = cModel_getMeshPtr(self, 0); n != 0; n = n->next) {
            if (n->info->flags & 0x1000000) {
                found = 1;
                break;
            }
        }
    }
    if (!found)
        self->objFlags |= 0x400;
    d = cModel_getMeshPtr(self, 0)->data;
    if (d->num < 2) {
        if (func_0014C328(self) == 0) {
            D_00747A24 |= 0x200000;
            return 0;
        }
    } else {
        if (func_0014BFE0(self) == 0) {
            D_00747A24 |= 0x200000;
            return 0;
        }
    }
    {
        cModelNode *n;

        for (n = cModel_getMeshPtr(self, 0); n != 0; n = n->next) {
            long t = *(int *)&n->info->flags;

            if ((((unsigned long)t >> 4) & 1UL) == 1UL)
                n->dispFlags |= 1;
        }
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", cModel_setupModel);
#endif
