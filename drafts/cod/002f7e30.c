/* sn-2.95.3-136 */
/* func_002F7E30 (esp ring effect setup): the record copy, the allocations and both octagons
 * match apart from the divide padding: retail pads 12 of its 20 div.s with two nops and leaves
 * the 8 that follow a cvt.s.w, an lwc1 or another div.s bare, which no fp hazard rule
 * reproduces. The owner equality test is materialised as a 0/1 value in retail, and the
 * owner part range check uses a byte flag, unlike cOmBase_childAt. */
#include "include_asm.h"
#include "godhand/cOmBase.h"

#ifdef NON_MATCHING

/* The effect record an esp ring effect is set up from. */
typedef struct espRingRec {
    char unk000[0x13C];
    float pos[3];               /* 0x13C */
    float from[3];              /* 0x148 */
    float to[3];                /* 0x154 */
    char unk160[0x16C - 0x160];
    int innerW;                 /* 0x16C hundredths */
    int innerH;                 /* 0x170 */
    int outerW;                 /* 0x174 */
    int outerH;                 /* 0x178 */
    char unk17C[0x18C - 0x17C];
    signed char use[2];         /* 0x18C follow the owner's part */
    unsigned char part[2];      /* 0x18E owner part numbers, 0xFF for none */
    signed char unk190;         /* 0x190 */
} espRingRec;

typedef struct espRing {
    char unk000[0x110];
    espRingRec *rec;            /* 0x110 */
    cOmBase *owner;             /* 0x114 */
    char unk118[0x2BC - 0x118];
    cVec *strip;                /* 0x2BC */
    char unk2C0[0x2F0 - 0x2C0];
    float innerW;               /* 0x2F0 */
    float outerW;               /* 0x2F4 */
    float innerH;               /* 0x2F8 */
    float outerH;               /* 0x2FC */
    int segNum;                 /* 0x300 */
    int unk304;                 /* 0x304 */
    int unk308;                 /* 0x308 */
    int unk30C;                 /* 0x30C */
    int stripNum;               /* 0x310 */
    signed char part[2];        /* 0x314 */
    unsigned char unk318;       /* 0x318 */
    unsigned char use[2];       /* 0x319 */
    unsigned char moved;        /* 0x31B */
    char unk31C[4];
    cVec pos;                   /* 0x320 */
    cVec from;                  /* 0x330 */
    cVec to;                    /* 0x340 */
    cVec cur;                   /* 0x350 */
    cVec *ring;                 /* 0x360 */
    void *buf0;                 /* 0x364 */
    void *buf1;                 /* 0x368 */
} espRing;

extern cVec D_00747B00;
extern char D_00754240[];
extern char D_0044F788[];
extern char D_0044F7A8[];

extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);
extern void func_002D9F68(void *a0, int a1, ...);

static __inline__ int cVec_equal(cVec *a, cVec *b)
{
    return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;
}

/* Set an esp ring effect up from its record: its points, its buffers and the two
 * octagons of its inner and outer outline; fails when an owner part is missing. */
__attribute__((section(".text.func_002F7E30")))
int func_002F7E30(espRing *self)
{
    int i;
    int frame;

    self->innerW = (float)self->rec->innerW / 100.0f;
    self->innerH = (float)self->rec->innerH / 100.0f;
    self->outerW = (float)self->rec->outerW / 100.0f;
    self->outerH = (float)self->rec->outerH / 100.0f;
    cVec_set4(&self->pos, self->rec->pos[0], self->rec->pos[1], self->rec->pos[2], 1.0f);
    cVec_set4(&self->from, self->rec->from[0], self->rec->from[1], self->rec->from[2], 1.0f);
    cVec_set4(&self->to, self->rec->to[0], self->rec->to[1], self->rec->to[2], 1.0f);
    cVec_copy3(&self->cur, &self->from);
    self->moved = 0;
    if (!cVec_equal(&self->to, &D_00747B00)) {
        self->moved = 1;
        cVec_copy3(&self->from, &self->pos);
    }
    self->use[0] = self->rec->use[0] != 0;
    self->use[1] = self->rec->use[1] != 0;
    self->part[0] = self->rec->part[0];
    self->part[1] = self->rec->part[1];
    self->stripNum = 1;
    self->segNum = 0x12;
    self->unk318 = self->rec->unk190 != 0;
    self->unk308 = 0x10;
    self->unk30C = 8;
    self->unk304 = 0x30;
    if ((self->buf0 = EnsureInitThenForward_2A9538_30EE08(0x6F0, 0x10, (int)D_00754240)) == 0)
        return 0;
    if ((self->buf1 = EnsureInitThenForward_2A9538_30EE08(0x6F0, 0x10, (int)D_00754240)) == 0)
        return 0;
    if ((self->strip = EnsureInitThenForward_2A9538_30EE08(self->segNum * self->stripNum * 0x10, 0x10, (int)D_00754240)) == 0)
        return 0;
    if ((self->ring = EnsureInitThenForward_2A9538_30EE08((self->segNum + 2) * 0x10, 0x10, (int)D_00754240)) == 0)
        return 0;
    if (self->innerH == 0.0f)
        self->innerH = 0.1f;
    if (self->innerW == 0.0f)
        self->innerW = 0.1f;
    cVec_set4(&self->ring[0], -self->innerW, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[1], -self->innerW / 1.414f, self->innerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[2], 0.0f, self->innerH, 0.0f, 1.0f);
    cVec_set4(&self->ring[3], self->innerW / 1.414f, self->innerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[4], self->innerW, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[5], self->innerW / 1.414f, -self->innerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[6], 0.0f, -self->innerH, 0.0f, 1.0f);
    cVec_set4(&self->ring[7], -self->innerW / 1.414f, -self->innerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[8], -self->innerW, 0.0f, 0.0f, 1.0f);
    if (self->outerH == 0.0f)
        self->outerH = 0.1f;
    if (self->outerW == 0.0f)
        self->outerW = 0.1f;
    cVec_set4(&self->ring[9], -self->outerW, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[10], -self->outerW / 1.414f, self->outerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[11], 0.0f, self->outerH, 0.0f, 1.0f);
    cVec_set4(&self->ring[12], self->outerW / 1.414f, self->outerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[13], self->outerW, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[14], self->outerW / 1.414f, -self->outerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[15], 0.0f, -self->outerH, 0.0f, 1.0f);
    cVec_set4(&self->ring[16], -self->outerW / 1.414f, -self->outerH / 1.414f, 0.0f, 1.0f);
    cVec_set4(&self->ring[17], -self->outerW, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[18], 0.0f, 0.0f, 0.0f, 1.0f);
    cVec_set4(&self->ring[19], 0.0f, 0.0f, 0.0f, 1.0f);
    if (self->use[0] || self->use[1]) {
        if (self->owner == 0) {
            func_002D9F68(self, (int)D_0044F788);
            return 0;
        }
        for (i = 0; i < 2; i++) {
            if (self->use[i] && self->part[i] != -1
                && cOmBase_childAt(self->owner, &frame, self->part[i]) == 0) {
                func_002D9F68(self, (int)D_0044F7A8, self->part[i]);
                return 0;
            }
        }
    }
    return 1;
}

#else
INCLUDE_ASM("asm/nonmatching", func_002F7E30);
#endif
