/* NON_MATCHING func_0019AA80 (NEAR-MISS): all but the final 10 field stores match; store schedule (a1=1/a2=7 materialized first, 0x5F4 in jal delay slot) not reproduced by 400+ order permutations */
#include "include_asm.h"

#ifdef NON_MATCHING
typedef struct Vec19AA80 {
    float x;
    float y;
    float z;
    float w;
} Vec19AA80;

typedef struct Obj19AA80 {
    char pad000[0x548];
    short unk548;
    short unk54A;
    char pad54C[0x5E4 - 0x54C];
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    short unk5F4;
    short unk5F6;
    char pad5F8[0x600 - 0x5F8];
    void *take;
    char pad604[4];
    void *unk608;
    unsigned char unk60C;
    char pad60D[0x620 - 0x60D];
    char unk620[4];
} Obj19AA80;

extern char D_00574380[];
extern int func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *pos, Vec19AA80 *ofs, Vec19AA80 *rot, Vec19AA80 *size);
extern void func_001C28A0(void *self);

static inline void Vec19AA80_w(Vec19AA80 *v, float w)
{
    v->w = w;
}

static inline void Vec19AA80_xyz(Vec19AA80 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Vec19AA80_set(Vec19AA80 *v, float x, float y, float z, float w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

int func_0019AA80(Obj19AA80 *self)
{
    Vec19AA80 hit;
    Vec19AA80 size;
    Vec19AA80 ofs;
    Vec19AA80 rot;

    func_001B6FB8(self);
    hit.x = 2.8f; hit.y = 0.6f; hit.z = 1.6f;
    Vec19AA80_w(&hit, 1.0f);
    size.x = 2.8f; size.y = 1.0f; size.z = 1.6f;
    Vec19AA80_w(&size, 1.0f);
    ofs.x = 0.0f; ofs.y = 0.0f; ofs.z = 0.0f;
    Vec19AA80_w(&ofs, 1.0f);
    self->take = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    if (self->take != 0) {
        rot.x = 0.0f; rot.y = 0.0f; rot.z = 0.0f;
        Vec19AA80_w(&rot, 1.0f);
        func_001FD9D8(self->take, (char *)self + 0x80, &ofs, &rot, &size);
    }
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    self->unk54A = 1;
    self->unk608 = self->unk620;
    self->unk5EC = 7;
    self->unk548 = 1;
    self->unk60C = 7;
    self->unk5F4 = -1;
    func_001C28A0(self);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_0019AA80);
#endif
