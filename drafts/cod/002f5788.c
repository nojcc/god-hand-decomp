/* sn-2.95.3-136 */
/* func_002F5788 (ribbon effect setup, as sn): the point buffer, the strip packet loop and the
 * matrix tail match. The parameter block differs: retail loads the 0.03, 0.01 and 0.0078125
 * constants right before their multiplies and reloads self->data before the spread byte; this
 * build loads all three constants at the top of the block and reuses the cached data pointer. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"
#include "godhand/cCamera.h"
#include "godhand/heapArena.h"

extern int func_002EBD10(void *a0, int a1, int n);
extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);
extern float func_0031D108(unsigned int *seed);
extern void *StoreVecFromFieldB0_2B6160(void *a0, void *a1);
extern int CallThenReturnPlusB0_002B6420_2B61B0(int a0);
extern void MtxCopy(void *dst, void *src);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);

#define GS_REG_RGBAQ 1
#define GS_REG_ST    2

/* RGBAQ: grey 0x80 in every channel, Q 1.0. */
#define ESP_RIBBON_RGBAQ 0x3F80000080808080

/* One GS register write of an A+D packet. */
typedef struct espGsAd {
    long data;
    long addr;
} espGsAd;

/* An ST write: the texture coordinates as two floats. */
typedef struct espGsSt {
    float s;
    float t;
    long addr;
} espGsSt;

/* One column of the ribbon strip: the two edge vertices. */
typedef struct espRibbonCol {
    espGsSt st0;
    espGsAd xyz0;
    espGsSt st1;
    espGsAd xyz1;
} espRibbonCol;

typedef struct espRibbonPkt {
    char unk00[0x60];
    espGsAd rgbaq;                      /* 0x60 */
    char unk70[0xA0 - 0x70];
    espRibbonCol col[1];                /* 0xA0 one per point */
} espRibbonPkt;

/* The effect's resource record. */
typedef struct espRibbonData {
    char unk000[0x13C];
    float param[6];                     /* 0x13C */
    char unk154[0x18D - 0x154];
    signed char pointNum;               /* 0x18D 1..0x78; anything else means 0x10 */
    unsigned char kind;                 /* 0x18E */
    signed char twist;                  /* 0x18F */
    signed char spread;                 /* 0x190 */
    signed char angle[2];               /* 0x191 */
    signed char angleRand[2];           /* 0x193 */
} espRibbonData;

/* A ribbon effect: a strip of points drawn with two packets. */
typedef struct espRibbon {
    char unk000[0x110];
    espRibbonData *data;                /* 0x110 */
    char unk114[0x11C - 0x114];
    int flags;                          /* 0x11C bit 28 flips s, bit 27 flips t */
    char unk120[0x220 - 0x120];
    unsigned int seed;                  /* 0x220 */
    char unk224[0x249 - 0x224];
    signed char pointNum;               /* 0x249 */
    char unk24A[0x2BC - 0x24A];
    cVec *point;                        /* 0x2BC */
    char unk2C0[4];
    espRibbonPkt *pktA;                 /* 0x2C4 */
    espRibbonPkt *pktB;                 /* 0x2C8 */
    char unk2CC[0x2D4 - 0x2CC];
    float length;                       /* 0x2D4 */
    char unk2D8[0x2F0 - 0x2D8];
    cVec *work;                         /* 0x2F0 */
    char unk2F4[0x300 - 0x2F4];
    float param3[3];                    /* 0x300 data param[3..5] */
    char unk30C[4];
    float param0[2];                    /* 0x310 data param[0..1] */
    float param2Inv;                    /* 0x318 1 - data param[2] */
    float twist;                        /* 0x31C */
    float spread;                       /* 0x320 */
    float angle[2];                     /* 0x324 */
    signed char kind;                   /* 0x32C */
    char unk32D[3];
    float phase;                        /* 0x330 */
} espRibbon;

#define ESP_RIBBON_FLIP_S 0x10000000
#define ESP_RIBBON_FLIP_T 0x08000000

/* Sets up a ribbon effect: its point buffer, parameters, strip packets and matrix. */
__attribute__((section(".text.func_002F5788")))
int func_002F5788(espRibbon *self, int arg)
{
    cVec pos;
    float mtx[16];
    cVec zero;
    espRibbonData *data;
    int i;
    float s;
    float t;
    float v;

    self->pointNum = self->data->pointNum;
    if (self->pointNum >= 0x79 || self->pointNum == 0)
        self->pointNum = 0x10;
    if (func_002EBD10(self, arg, self->pointNum) == 0)
        return 0;
    self->work = EnsureInitThenForward_2A9538_30EE08(self->pointNum * 16, 16, (int)&D_00754240);
    if (self->work == 0)
        return 0;
    for (i = 0; i < self->pointNum; i++)
        cVec_set4(&self->work[i], 0.0f, 0.0f, 0.0f, 1.0f);
    self->phase = func_0031D108(&self->seed) * 3.1415927f;
    data = self->data;
    self->param0[0] = data->param[0];
    self->param0[1] = data->param[1];
    self->param2Inv = 1.0f - data->param[2];
    self->param3[0] = data->param[3];
    self->param3[1] = data->param[4];
    self->param3[2] = data->param[5];
    self->kind = data->kind + 2;
    self->twist = data->twist * 0.03f;
    self->spread = self->data->spread * 0.01f;
    self->angle[0] = (self->data->angle[0] + self->data->angleRand[0] * func_0031D108(&self->seed)) * 3.1415927f * 0.0078125f;
    self->angle[1] = (self->data->angle[1] + self->data->angleRand[1] * func_0031D108(&self->seed)) * 3.1415927f * 0.0078125f;
    self->angle[0] = Adjust_theta(self->angle[0]);
    self->angle[1] = Adjust_theta(self->angle[1]);
    StoreVecFromFieldB0_2B6160(&pos, self);
    for (i = 0; i < self->pointNum; i++) {
        cVec_copy3(&self->point[i], &pos);
        s = 1.0f;
        self->pktA->rgbaq.data = ESP_RIBBON_RGBAQ;
        self->pktA->rgbaq.addr = GS_REG_RGBAQ;
        self->pktB->rgbaq.data = ESP_RIBBON_RGBAQ;
        self->pktB->rgbaq.addr = GS_REG_RGBAQ;
        if (self->flags & ESP_RIBBON_FLIP_S)
            s = -1.0f;
        t = 1.0f;
        if (self->flags & ESP_RIBBON_FLIP_T)
            t = -1.0f;
        v = t * i;
        self->pktA->col[i].st0.s = 0.0f;
        self->pktA->col[i].st0.t = v / (self->pointNum - 1) * self->length;
        self->pktA->col[i].st0.addr = GS_REG_ST;
        self->pktA->col[i].st1.s = s;
        self->pktA->col[i].st1.t = v / (self->pointNum - 1) * self->length;
        self->pktA->col[i].st1.addr = GS_REG_ST;
        self->pktB->col[i].st0.s = 0.0f;
        self->pktB->col[i].st0.t = v / (self->pointNum - 1) * self->length;
        self->pktB->col[i].st0.addr = GS_REG_ST;
        self->pktB->col[i].st1.s = s;
        self->pktB->col[i].st1.t = v / (self->pointNum - 1) * self->length;
        self->pktB->col[i].st1.addr = GS_REG_ST;
    }
    MtxCopy(mtx, (void *)CallThenReturnPlusB0_002B6420_2B61B0((int)self));
    cVec_zero(&zero);
    CopyVec3ToField30_147C40(mtx, (float *)&zero);
    return 1;
}

#else
INCLUDE_ASM("asm/nonmatching", func_002F5788);
#endif
