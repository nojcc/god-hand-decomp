/* sn-2.95.3-136 */
/* func_002E7750: same length as retail minus two words. What still differs:
 * the load order in the vector copies (retail loads x, y, stores both, then
 * z), the copies of v after it is filled from the colour (retail reloads v
 * from the stack), and the order of the record's first stores. */
#include "include_asm.h"
#include "godhand/vu0.h"
#include "godhand/cObjBase.h"
#include "godhand/cWorldLight.h"
#include "godhand/espSys.h"

/* The light effect's data block (EspLight.data). */
typedef struct EspLightData {
    char unk00[0x7C];
    float color[3];                     /* 0x7C */
    char unk88[0x13C - 0x88];
    float f40;                          /* 0x13C */
    float rate;                         /* 0x140 */
    float f144;                         /* 0x144 */
    cVec v20;                           /* 0x148 xyz */
    float f154;                         /* 0x154 */
    float f158;                         /* 0x158 */
    char unk15C[0x16C - 0x15C];
    unsigned short state;               /* 0x16C */
    char unk16E[2];
    unsigned short id;                  /* 0x170 */
    char unk172[2];
    int owner[2];                       /* 0x174 */
    char unk17C[0x18C - 0x17C];
    unsigned char bit31;                /* 0x18C */
    unsigned char bit30;                /* 0x18D */
    unsigned char bit29;                /* 0x18E */
    unsigned char bit28;                /* 0x18F */
    unsigned char bit27;                /* 0x190 */
    unsigned char bit26;                /* 0x191 */
    unsigned char onPart;               /* 0x192 */
    unsigned char keep;                 /* 0x193 */
    unsigned char level;                /* 0x194 */
    signed char newId;                  /* 0x195 */
    unsigned char turn;                 /* 0x196 */
    unsigned char unk197;               /* 0x197 */
} EspLightData;

/* A light effect: copies its data block into a world light record and
 * registers it with the stage lights. */
typedef struct EspLight {
    char unk000[0x110];
    EspLightData *data;                 /* 0x110 */
    cObjBase *owner;                    /* 0x114 the object the light follows */
    char unk118[0x188 - 0x118];
    float pos[3];                       /* 0x188 */
    char unk194[0x2B0 - 0x194];
    unsigned short state;               /* 0x2B0 */
    unsigned short id;                  /* 0x2B2 */
    int key;                            /* 0x2B4 */
    float f40;                          /* 0x2B8 */
    char unk2BC[0x2C4 - 0x2BC];
    unsigned char bit31;                /* 0x2C4 */
    unsigned char bit30;                /* 0x2C5 */
    unsigned char bit29;                /* 0x2C6 */
    unsigned char bit28;                /* 0x2C7 */
    unsigned char bit27;                /* 0x2C8 */
    unsigned char bit26;                /* 0x2C9 */
    unsigned char onPart;               /* 0x2CA */
    unsigned char unk2CB;               /* 0x2CB */
    unsigned char turn;                 /* 0x2CC */
    unsigned char keep;                 /* 0x2CD */
    unsigned char lit;                  /* 0x2CE */
    signed char level;                  /* 0x2CF */
    float rate;                         /* 0x2D0 */
    float f2D4;                         /* 0x2D4 */
    float f2D8;                         /* 0x2D8 */
    float f2DC;                         /* 0x2DC */
    int owner2[2];                      /* 0x2E0 */
    char unk2E8[8];
    cVec ofs;                           /* 0x2F0 */
    cVec rot;                           /* 0x300 */
    char unk310[0x350 - 0x310];
    struct cOmBase *part;               /* 0x350 */
    char unk354[0x360 - 0x354];
    cWorldLightRec rec;                 /* 0x360 */
} EspLight;

extern char D_00604700[];
extern cVec D_00747B00;
extern char D_0044E5D0[];
extern char D_0044E5E8[];
extern char D_0044E608[];
extern char D_0044E620[];
unsigned int func_002D93E8(cWorldLight *self);
int func_002B6310(int a0, int a1);
unsigned short F32toF16(float f);
void cWorldLight_Del_LightData(cWorldLight *self, unsigned short id, int key);
int cWorldLight_Set_LightData(cWorldLight *self, cWorldLightRec *src);

/* cVec's operator=: xyz of s into d, skipped when they are the same vector. */
#define REC_VEC_ASSIGN(d, s)                                    \
    {                                                           \
        cVec *d_ = (cVec *)(d);                                 \
        cVec *s_ = (cVec *)(s);                                 \
                                                                \
        if (d_ != s_) {                                         \
            d_->x = s_->x;                                      \
            d_->y = s_->y;                                      \
            d_->z = s_->z;                                      \
        }                                                       \
    }

/* cWorldLightRec's operator=: the members one by one, the vectors xyz only. */
static __inline__ void cWorldLightRec_assign(cWorldLightRec *d, cWorldLightRec *s)
{
    int *dw;
    int *sw;
    int n;

    d->state = s->state;
    d->id = s->id;
    d->unk04 = s->unk04;
    REC_VEC_ASSIGN(d->v10, s->v10);
    REC_VEC_ASSIGN(d->v20, s->v20);
    REC_VEC_ASSIGN(d->v30, s->v30);
    d->f40 = s->f40;
    d->f44 = s->f44;
    d->f48 = s->f48;
    dw = d->owner;
    sw = s->owner;
    n = 2;
    while (n--)
        *dw++ = *sw++;
    d->key = s->key;
    d->flags = s->flags;
    d->f5C = s->f5C;
    d->f5E = s->f5E;
    d->f60 = s->f60;
    d->f61 = s->f61;
    d->f62 = s->f62;
}

/* Sets the light effect up from its data block: the light's settings, its
 * colour and position, the part it follows, then registers the light. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_002E7750")))
int func_002E7750(EspLight *self)
{
    cWorldLightRec rec;
    cVec v;
    EspLightData *d;
    cObjBase *owner;
    int frame[3];

    VU0_SQC2_VF0_MEM(rec.v10, 0);
    VU0_SQC2_VF0_MEM(rec.v20, 0);
    VU0_SQC2_VF0_MEM(rec.v30, 0);
    d = self->data;
    self->state = d->state;
    self->id = d->id;
    self->owner2[0] = d->owner[0];
    self->owner2[1] = d->owner[1];
    self->f40 = d->f40;
    self->rate = d->rate;
    self->f2D4 = d->f144;
    self->f2D8 = d->f154;
    self->f2DC = d->f158;
    self->bit31 = d->bit31;
    self->bit30 = d->bit30;
    self->bit29 = d->bit29;
    self->bit28 = d->bit28;
    self->bit27 = d->bit27;
    self->bit26 = d->bit26;
    self->onPart = d->onPart;
    self->keep = d->keep;
    self->level = d->level - 1;
    self->turn = d->turn;
    self->unk2CB = d->unk197;
    if (!self->bit31 && !self->bit30 && !self->bit29 && !self->bit28
        && !self->onPart && !self->keep) {
        func_002D9F68(self, (int)D_0044E5D0);
        return 0;
    }
    if (self->data->newId != 0)
        self->id = func_002D93E8((cWorldLight *)D_00604700);
    if (self->level >= 0)
        self->lit = 1;
    else
        self->lit = 0;
    if (self->id == 0) {
        func_002D9F68(self, (int)D_0044E5E8);
        return 0;
    }
    owner = self->owner;
    if ((self->onPart || self->keep) && owner == 0) {
        func_002D9F68(self, (int)D_0044E608);
        return 0;
    }
    rec.state = self->state;
    rec.id = self->id;
    self->key = (int)owner;
    rec.v30[0] = self->pos[0];
    rec.v30[1] = self->pos[1];
    rec.v30[2] = self->pos[2];
    rec.f40 = self->f40;
    rec.unk04 = 0;
    rec.key = (int)owner;
    rec.f44 = 0.0f;
    rec.f48 = 0.0f;
    func_002B6310((int)&v, (int)self);
    rec.v10[0] = v.x;
    rec.v10[1] = v.y;
    rec.v10[2] = v.z;
    rec.v20[0] = self->data->v20.x;
    rec.v20[1] = self->data->v20.y;
    rec.v20[2] = self->data->v20.z;
    REC_VEC_ASSIGN(&self->ofs.x, &D_00747B00.x);
    if (self->onPart) {
        rec.state = 1;
        rec.key = self->key;
        self->bit26 = 0;
        v.x = self->data->color[0];
        v.y = self->data->color[1];
        v.z = self->data->color[2];
        v.w = 1.0f;
        REC_VEC_ASSIGN(&self->ofs.x, &v.x);
        self->part = cObjBase_childAt(owner, frame, 0);
        if (self->part == 0) {
            func_002D9F68(self, (int)D_0044E620);
            return 0;
        }
        if (self->turn == 0)
            self->turn = 1;
    } else if (self->keep == 0) {
        self->key = 0;
        rec.key = 0;
    }
    if (self->bit26) {
        v.x = self->data->color[0];
        v.y = self->data->color[1];
        v.z = self->data->color[2];
        v.w = 1.0f;
        rec.v10[0] = v.x;
        rec.v10[1] = v.y;
        rec.v10[2] = v.z;
    }
    rec.f5E = (int)(self->rate * 100.0f);
    rec.owner[WORLDLIGHT_OWNER_IDX] = self->owner2[0];
    rec.owner[WORLDLIGHT_OWNER_USE] = self->owner2[1];
    rec.f5C = F32toF16(self->f2D4);
    rec.f61 = (int)(self->f2D8 * 100.0f);
    rec.f62 = F32toF16(self->f2DC);
    rec.flags = 0;
    if (self->bit31)
        rec.flags |= 0x80000000;
    if (self->bit30)
        rec.flags |= 0x40000000;
    else
        rec.flags &= ~0x40000000;
    if (self->bit29)
        rec.flags |= 0x20000000;
    else
        rec.flags &= ~0x20000000;
    if (self->bit28)
        rec.flags |= 0x10000000;
    else
        rec.flags &= ~0x10000000;
    if (self->bit27)
        rec.flags |= 0x08000000;
    else
        rec.flags &= ~0x08000000;
    if (self->onPart)
        rec.flags |= 0x00040000;
    else
        rec.flags &= ~0x00040000;
    if (self->bit26)
        rec.flags |= 0x04000000;
    else
        rec.flags &= ~0x04000000;
    if (self->bit26)
        rec.flags |= 0x01000000;
    else
        rec.flags &= ~0x01000000;
    if (self->lit)
        rec.flags |= 0x00100000;
    else
        rec.flags &= ~0x00100000;
    REC_VEC_ASSIGN(&self->rot.x, &D_00747B00.x);
    cWorldLightRec_assign(&self->rec, &rec);
    cWorldLight_Del_LightData((cWorldLight *)D_00604700, self->id, self->key);
    cWorldLight_Set_LightData((cWorldLight *)D_00604700, &rec);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002E7750);
#endif
