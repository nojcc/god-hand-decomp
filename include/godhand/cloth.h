/* include/godhand/cloth.h - the cloth set-up record and its collision spheres.
 *
 * A cloth is a chain of model joints described by an EmCloth record, which
 * func_001038E0 starts. The player's costumes (func_00100870) and some enemies
 * (EmClothInit) fill one. Its spheres keep the cloth off the body: a sphere
 * sits on the bone segment from boneB to boneA at blend (1.0 is on boneA),
 * moved by ofs. Field names are ours; offsets are exact.
 */
#ifndef GODHAND_CLOTH_H
#define GODHAND_CLOTH_H

#include "godhand/cVec.h"
#include "godhand/criStm.h"

typedef struct ClothSphere {
    char unk00[2];
    unsigned char boneA;                /* 0x02 */
    unsigned char boneB;                /* 0x03 */
    float blend;                        /* 0x04 */
    float radius;                       /* 0x08 */
    int unk0C;
    cVec ofs;                           /* 0x10 offset from the bone point (w is 1.0) */
    cVec unk20;                         /* 0x20 all but one table entry repeat ofs here */
} ClothSphere;

typedef char ClothSphere_chk_size[sizeof(ClothSphere) == 0x30 ? 1 : -1];

/* The cloth record an object keeps (cObjSimple.clothAnchor, an enemy's
 * 0x15B0). The joint tables have numJoints entries; parent and child hold
 * 0xFF at the ends of the chain. */
typedef struct EmCloth {
    int numJoints;                      /* 0x00 */
    unsigned char *joint;               /* 0x04 model joint numbers */
    void *unk08;
    void *unk0C;
    int unk10;
    int unk14;
    unsigned char *parent;              /* 0x18 the joint before each one */
    unsigned char *child;               /* 0x1C the joint after each one */
    int unk20;
    int unk24;
    float *unk28;
    float *unk2C;
    float *unk30;
    ClothSphere *spheres;               /* 0x34 */
    int unk38;                          /* 0x38 the sphere count in the enemy set-ups; the player's are 0 */
    float unk3C;
    float unk40;
    int unk44;
    float unk48;
    float unk4C;
    float unk50;
    int unk54;
    void *owner;                        /* 0x58 the enemy, or 0 */
    int unk5C;
    cVec drift;                         /* 0x60 sideways push, turned with the enemy */
    float unk70;
    char unk74[0x80 - 0x74];
} EmCloth;

typedef char EmCloth_chk_drift[(int)&((EmCloth *)0)->drift == 0x60 ? 1 : -1];
typedef char EmCloth_chk_size[sizeof(EmCloth) == 0x80 ? 1 : -1];

void func_001038E0(void *self, EmCloth *cloth, void *model, float arg3, float arg4);

/* The sphere tables of the four costume pairs (0/1, 2/3, 4/5, 6/7). */
extern ClothSphere D_00460E00[12];
extern ClothSphere D_00461040[11];
extern ClothSphere D_00461250[7];
extern ClothSphere D_004613A0[12];

/* The enemies' sphere tables, filled by func_002DF950. */
extern ClothSphere D_0061A9A0[2];
extern ClothSphere D_0061AA00[4];
extern ClothSphere D_0061AAC0[5];
extern ClothSphere D_0061ABB0[2];
extern ClothSphere D_0061AC10[4];
extern ClothSphere D_0061ACD0[4];
extern ClothSphere D_0061AD90[8];
extern ClothSphere D_0061AF10[6];
extern ClothSphere D_0061B030[6];
extern ClothSphere D_0061B150[6];

/* The record's constructor: cleared, then the two bones, the blend, the radius,
 * ofs and unk20. A macro for the same reason as CVEC_INIT_XYZ; s is evaluated
 * more than once. */
#define CLOTH_SPHERE_SET(s, a, b, bl, r, fx, fy, fz, ux, uy, uz)  \
    {                                                           \
        func_003A52F0((s), 0, sizeof(ClothSphere));             \
        (s)->boneA = (a);                                       \
        (s)->boneB = (b);                                       \
        (s)->blend = (bl);                                      \
        (s)->radius = (r);                                      \
        CVEC_INIT_XYZ((s)->ofs, fx, fy, fz)                     \
        CVEC_INIT_XYZ((s)->unk20, ux, uy, uz)                   \
    }

#endif /* GODHAND_CLOTH_H */
