/* sn-2.95.3-136 */
/* NON_MATCHING func_0028D7E8 (extern_jtbl D_0044A330): only the two mesh index
 * computations differ. Retail builds each index with a chain of conditional
 * moves (1 for bit a, then 2 for bit b, then 3 for both), starting from a
 * movz of 0 into a preset 1; ours branches. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cGameObj.h"
#include "godhand/cModel.h"
#include "godhand/cObjBase.h"

/* The enemy class of 0x28Bxxx as its mesh update reads it: cEm00.h gives
 * 0x155C..0x156C other meanings for other enemies. */
typedef struct EmMeshEnemy {
    cGameObj obj;                       /* 0x000 */
    char unk5B0[0x1534 - sizeof(cGameObj)];
    int meshFlags;                      /* 0x1534 bits 0..3 add motion flags 0x40, 0x4000, 0x80, 0x8000 */
    char unk1538[0x1550 - 0x1538];
    cModelNode *mesh[2][4];             /* 0x1550 two sets of four alternative meshes */
} __attribute__((aligned(16))) EmMeshEnemy;

extern char D_00448F50[];
extern char D_00448F70[];
extern char D_0044A2B0[];
extern char D_0044A2B8[];
extern char D_0044A2C0[];
extern char D_0044A2C8[];
extern char D_0044A2D0[];
extern char D_0044A2D8[];
extern char D_0044A2E0[];
extern char D_0044A2E8[];
extern char D_0044A2F0[];
extern char D_0044A2F8[];
extern char D_0044A300[];
extern char D_0044A308[];
extern char D_0044A310[];
extern char D_0044A318[];
extern char D_0044A320[];
extern char D_0044A328[];

static __inline__ void hideMesh(cModelNode *mesh)
{
    if (mesh != 0) {
        mesh->dispFlags |= CMODEL_NODE_HIDE;
    }
}

static __inline__ void showMesh(cModelNode *mesh)
{
    if (mesh != 0) {
        mesh->dispFlags &= ~CMODEL_NODE_HIDE;
    }
}

#define MESH(self, name) cModel_getMeshPtr_14B730((cModel *)(self), name)

/* Picks which of four alternative meshes the motion flags select. */
/* Picks which of four alternative meshes the motion flags select: 1 for
 * bit a, 2 for bit b, 3 for both. */
#define MESH_PICK(f, a, b)                                      \
    (((f) & (a)) && ((f) & (b)) ? 3 : (f) & (b) ? 2 : (f) & (a) ? 1 : 0)

/* Shows the meshes the enemy kind and its motion flags select and hides the
 * others. */
__attribute__((section(".text.func_0028D7E8")))
void func_0028D7E8(EmMeshEnemy *self)
{
    cEffectParam param;
    cModelNode *mesh;
    unsigned int n;

    /* retail builds an effect parameter block it never passes on */
    cEffectParam_init(&param);
    param.size = self->obj.scale[1];
    param.unk70 = 0;
    param.unk72 = 0;
    param.unk74 = 0;
    param.unk78 = 0;

    switch (self->obj.emNo) {
    case 0x20B:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
        return;
    }
    hideMesh(self->mesh[0][0]);
    hideMesh(self->mesh[0][1]);
    hideMesh(self->mesh[0][2]);
    hideMesh(self->mesh[1][0]);
    hideMesh(self->mesh[1][1]);
    hideMesh(self->mesh[1][2]);

    switch (self->obj.emNo) {
    case 0x276:
        mesh = MESH(self, D_0044A2B0);
        hideMesh(mesh);
        /* fall through */
    case 0x275:
        mesh = MESH(self, D_0044A2B8);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2C0);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2C8);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2D0);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2D8);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2E0);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2E8);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2F0);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2F8);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A300);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A308);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A2F0);
        showMesh(mesh);
        mesh = MESH(self, D_0044A2F8);
        showMesh(mesh);
        mesh = MESH(self, D_0044A300);
        showMesh(mesh);
        mesh = MESH(self, D_0044A308);
        showMesh(mesh);
        break;
    case 0x242:
    case 0x243:
    case 0x244:
        showMesh(self->mesh[0][1]);
        showMesh(self->mesh[1][1]);
        return;
    case 0x252:
        mesh = MESH(self, D_0044A310);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A318);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A320);
        hideMesh(mesh);
        mesh = MESH(self, D_0044A328);
        hideMesh(mesh);
        break;
    case 0x256:
        mesh = MESH(self, D_00448F50);
        hideMesh(mesh);
        mesh = MESH(self, D_00448F70);
        hideMesh(mesh);
        break;
    }

    if (self->meshFlags & 1) {
        self->obj.motionFlags |= 0x40;
    }
    if (self->meshFlags & 2) {
        self->obj.motionFlags |= 0x4000;
    }
    if (self->meshFlags & 4) {
        self->obj.motionFlags |= 0x80;
    }
    if (self->meshFlags & 8) {
        self->obj.motionFlags |= 0x8000;
    }

    if (self->obj.unk434 & 2) {
        n = MESH_PICK(self->obj.motionFlags, 0x80, 0x8000);
    } else {
        n = MESH_PICK(self->obj.motionFlags, 0x40, 0x4000);
    }
    switch (n) {
    case 0:
    default:
        showMesh(self->mesh[0][0]);
        break;
    case 1:
        showMesh(self->mesh[0][1]);
        break;
    case 2:
        showMesh(self->mesh[0][2]);
        break;
    case 3:
        showMesh(self->mesh[0][3]);
        break;
    }
    if (self->obj.emNo == 0x252) {
        switch (n) {
        case 0:
        default:
            mesh = MESH(self, D_0044A310);
            showMesh(mesh);
            break;
        case 1:
            mesh = MESH(self, D_0044A318);
            showMesh(mesh);
            break;
        case 2:
        case 3:
            break;
        }
    }

    if (self->obj.unk434 & 2) {
        n = MESH_PICK(self->obj.motionFlags, 0x40, 0x4000);
    } else {
        n = MESH_PICK(self->obj.motionFlags, 0x80, 0x8000);
    }
    switch (n) {
    case 0:
    default:
        showMesh(self->mesh[1][0]);
        break;
    case 1:
        showMesh(self->mesh[1][1]);
        break;
    case 2:
        showMesh(self->mesh[1][2]);
        break;
    case 3:
        showMesh(self->mesh[1][3]);
        break;
    }
    if (self->obj.emNo == 0x252) {
        switch (n) {
        case 0:
        default:
            mesh = MESH(self, D_0044A320);
            showMesh(mesh);
            break;
        case 1:
            mesh = MESH(self, D_0044A328);
            showMesh(mesh);
            break;
        case 2:
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0028D7E8);
#endif
