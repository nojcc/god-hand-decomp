/* NON_MATCHING func_002AD2B8 (sn-2.95.3-136, fp_hazard_rules fdiv,mtc1,fpfence): 179 words vs 181.
 * Retail counts the point loop down with bnez rather than bgtz, keeps &tmp in a saved register across
 * the spring loop and loads the two spring constants just before their stores; register numbering
 * differs from there on. */
#include "include_asm.h"
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
/* One point of a spring mesh. */
typedef struct SpringNode {
    cVec pos;                           /* 0x00 */
    cVec vel;                           /* 0x10 */
    cVec force;                         /* 0x20 */
    cVec accel;                         /* 0x30 */
    float mass;                         /* 0x40 */
    float invMass;                      /* 0x44 */
    unsigned char pinned;               /* 0x48 */
    char pad49[0x7];
} SpringNode;

/* A spring between two mesh points. */
typedef struct SpringLink {
    SpringNode *a;                      /* 0x00 */
    SpringNode *b;                      /* 0x04 */
    float stiffness;                    /* 0x08 */
    float damping;                      /* 0x0C */
    float rest;                         /* 0x10 */
    unsigned char active;               /* 0x14 */
    char pad15[0x3];
} SpringLink;

/* A grid of (cols + 1) by (rows + 1) points joined by springs. */
typedef struct SpringMesh {
    int cols;                           /* 0x00 */
    int rows;                           /* 0x04 */
    char pad08[0x8];
    SpringNode *nodes;                  /* 0x10 */
    SpringLink *links;                  /* 0x14 */
} SpringMesh;

/* Mass description of one grid point: column, row, weight, pinned flag. */
typedef struct SpringNodeDef {
    unsigned char col;
    unsigned char row;
    unsigned char weight;
    unsigned char pinned;
} SpringNodeDef;

/* Spring description: the two points' column and row, and an active flag. */
typedef struct SpringLinkDef {
    unsigned char col0;
    unsigned char row0;
    unsigned char col1;
    unsigned char row1;
    unsigned char active;
} SpringLinkDef;

/* Clear x, y and z. */
static __inline__ void cVec_clear3(cVec *v)
{
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}

extern float D_003C2390;
extern float D_003C2394;
extern float capVu0Length(void *a0);

/* Set up a spring mesh: weight the listed points (mass scaled by total / count), reset every point's motion,
 * and join the listed springs with default stiffness and damping at their current length. */
__attribute__((section(".text.func_002AD2B8")))
void func_002AD2B8(SpringMesh *self, unsigned int count, SpringNodeDef *nodeDefs, int nodeCount,
                   SpringLinkDef *linkDefs, int linkCount, float total)
{
    SpringNode *n;
    cVec d;
    cVec tmp;
    int i;
    int x;
    int y;

    total = total / count;
    for (; nodeCount > 0; nodeCount--, nodeDefs++) {
        n = &self->nodes[nodeDefs->row * (self->cols + 1) + nodeDefs->col];
        n->mass = nodeDefs->weight * total;
        n->invMass = 1.0f / n->mass;
        if (nodeDefs->pinned == 1) {
            n->pinned = 1;
        } else {
            n->pinned = 0;
        }
    }
    for (y = 0; y <= self->rows; y++) {
        for (x = 0; x <= self->cols; x++) {
            n = &self->nodes[self->cols * y + y + x];
            n->invMass = 1.0f / n->mass;
            cVec_clear3(&n->vel);
            cVec_clear3(&n->force);
            cVec_clear3(&n->accel);
        }
    }
    for (i = 0; i < linkCount; i++, linkDefs++) {
        self->links[i].a = &self->nodes[linkDefs->row0 * (self->cols + 1) + linkDefs->col0];
        self->links[i].b = &self->nodes[linkDefs->row1 * (self->cols + 1) + linkDefs->col1];
        self->links[i].stiffness = D_003C2390;
        self->links[i].damping = D_003C2394;
        self->links[i].active = linkDefs->active == 1;
        VU0_ZERO_VSUB_XYZ_MEM(&tmp, 0, self->links[i].a, self->links[i].b);
        VU0_LQC2_SQC2_MEM(4, &d, &tmp);
        self->links[i].rest = capVu0Length(&d);
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002AD2B8);
#endif
