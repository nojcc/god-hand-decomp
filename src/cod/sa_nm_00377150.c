/* NON_MATCHING func_00377150 (sn-2.95.3-136; PARK at attempt 4, score 19): start one sound-effect channel and fill its voice node. Instruction sequence matches; channel and the per-channel data pointer have swapped s1/s2, and the tail 0x30-0x34 loads pick a1/v1/a0 differently. A `one` local fixes the s-regs but breaks the middle schedule; index locals, a data pointer local and tail reordering were tried. */
#include "include_asm.h"

#ifdef NON_MATCHING
#define VOICE_KIND_SE 1

typedef struct Seq377150 {
    char pad00[2];
    unsigned short unk02;               /* 0x02 */
    int unk04;                          /* 0x04 */
    char pad08[6];
    unsigned char unk0E;                /* 0x0E */
    char pad0F[3];
    unsigned short flags;               /* 0x12 bit 0 */
    char pad14[4];
    int data[0x11];                     /* 0x18 per-channel data */
    unsigned short unk5C;               /* 0x5C */
    unsigned short unk5E;               /* 0x5E */
    unsigned short pairA[4];            /* 0x60 indexed by channel / 2 */
    unsigned short pairB[4];            /* 0x68 indexed by channel / 2 */
    unsigned short side[2];             /* 0x70 indexed by channel & 1 */
} Seq377150;

typedef struct Req377150 {
    char pad00[7];
    unsigned char keyBase;              /* 0x07 */
} Req377150;

typedef struct Voice377150 {
    short kind;                         /* 0x00 */
    char pad02[2];
    int unk04;                          /* 0x04 */
    int unk08;                          /* 0x08 */
    unsigned char unk0C;                /* 0x0C */
    unsigned char unk0D;                /* 0x0D */
    short unk0E;                        /* 0x0E */
    short unk10;                        /* 0x10 */
    unsigned short unk12;               /* 0x12 */
    unsigned short unk14;               /* 0x14 */
    short unk16;                        /* 0x16 */
    unsigned short unk18;               /* 0x18 */
    unsigned short unk1A;               /* 0x1A */
    unsigned short unk1C;               /* 0x1C */
    short unk1E;                        /* 0x1E */
    short unk20;                        /* 0x20 */
    short unk22;                        /* 0x22 */
    short unk24;                        /* 0x24 */
    unsigned char key;                  /* 0x26 */
    unsigned char unk27;                /* 0x27 */
    unsigned char unk28;                /* 0x28 */
    unsigned char unk29;                /* 0x29 */
    short unk2A;                        /* 0x2A */
    unsigned short unk2C;               /* 0x2C */
    short unk2E;                        /* 0x2E */
    unsigned short unk30;               /* 0x30 */
    unsigned short unk32;               /* 0x32 */
    unsigned short unk34;               /* 0x34 */
    short unk36;                        /* 0x36 */
    unsigned short unk38;               /* 0x38 */
    unsigned short unk3A;               /* 0x3A */
    unsigned short unk3C;               /* 0x3C */
    signed char unk3E;                  /* 0x3E */
    char pad3F;
    unsigned char unk40;                /* 0x40 */
    unsigned char unk41;                /* 0x41 */
    unsigned char unk42;                /* 0x42 */
    unsigned char unk43;                /* 0x43 */
} Voice377150;

extern int func_00377FF8(Seq377150 *s, Req377150 *req, unsigned int ch);
extern Voice377150 *func_0037D170(void);

__attribute__((section(".text.func_00377150")))
int func_00377150(Seq377150 *s, Req377150 *req, unsigned int ch)
{
    Voice377150 *v;
    int r;

    r = func_00377FF8(s, req, ch);
    s->data[ch] = r;
    v = func_0037D170();
    if (v == 0)
        return -1;
    v->kind = VOICE_KIND_SE;
    v->unk04 = s->data[ch];
    v->unk08 = s->unk04;
    v->unk0C = s->unk0E;
    v->unk0D = 2;
    v->unk0E = -1;
    v->unk10 = 0;
    v->unk12 = s->unk02;
    v->unk14 = ch;
    v->unk16 = 0;
    v->unk18 = s->pairA[ch >> 1];
    v->unk1A = s->pairB[ch >> 1];
    v->unk1C = s->side[ch & 1];
    v->unk1E = 0;
    v->unk20 = -1;
    v->unk22 = -1;
    v->unk24 = -1;
    v->key = req->keyBase + ch;
    v->unk27 = 0;
    v->unk28 = 0x7F;
    v->unk29 = 0;
    v->unk2A = 0;
    if (s->flags & 1)
        v->unk2C = 1;
    else
        v->unk2C = 0;
    v->unk2E = 0x17;
    v->unk30 = s->unk5C;
    v->unk32 = s->unk5E;
    v->unk34 = s->side[ch & 1];
    v->unk36 = 0;
    v->unk38 = 0;
    v->unk3A = 0;
    v->unk3C = 0;
    v->unk3E = -1;
    v->unk41 = 0;
    v->unk40 = 0;
    v->unk43 = 0;
    v->unk42 = 0;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00377150);
#endif
