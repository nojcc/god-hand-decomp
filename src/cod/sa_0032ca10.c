/* cygnus-2.96 | drop-freorder-blocks: func_0032CA10, ADX stream server step: end the decode when the output has no room or the input ran dry, then pad every channel with silence once the input has finished. */
#include "godhand/criSj.h"

#define ADX_BLK_MAX      0x2000
#define ADX_STAT_FLUSH   3
#define SJ_STAT_END      3

typedef struct Adx32CA10 {
    char unk0;
    char stat;                          /* 0x01 */
    char unk02[2];
    void *sji;                          /* 0x04 */
    char unk08[4];
    void *dec;                          /* 0x0C */
    char unk10[8];
    SjObj *sjo[4];                      /* 0x18 */
    char unk28[0x20];
    int blk;                            /* 0x48 */
    char unk4C[0x24];
    signed char eos;                    /* 0x70 */
    signed char ended;                  /* 0x71 */
    signed char noStop;                 /* 0x72 */
    char unk73[0x29];
    int unk9C;                          /* 0x9C */
    int endTime;                        /* 0xA0 */
} Adx32CA10;

extern volatile int D_003C7418;

extern int Obj3260_Tramp_003383B0_D358(void *dec);
extern int func_00326370(void *dec);
extern int Obj3270_GetVia4_Obj33C8_10_77D0(void *sj);
extern int Obj3260_GetByte_1_D778(void *sj);
extern void Obj3260_Tramp_00338338_D338(void *dec, int id);
extern int func_0032A5B8(Adx32CA10 *adx);
extern void func_003A52F0(void *dst, int c, int n);

__attribute__((section(".text.func_0032CA10")))
void func_0032CA10(Adx32CA10 *adx)
{
    void *dec;
    void *sji;
    int room;
    int need;
    int blk;
    int nch;
    int len;
    int i;
    SjChunk ck;

    dec = adx->dec;
    sji = adx->sji;
    room = Obj3260_Tramp_003383B0_D358(dec);
    need = func_00326370(dec);
    blk = adx->blk;
    if (blk > ADX_BLK_MAX)
        blk = ADX_BLK_MAX;
    if (room < blk && Obj3270_GetVia4_Obj33C8_10_77D0(sji) < need
        && Obj3260_GetByte_1_D778(adx->sji) != SJ_STAT_END)
        goto pad;
    if (adx->eos == 0) {
        if (adx->noStop == 0) {
            Obj3260_Tramp_00338338_D338(dec, 1);
            adx->unk9C = 0;
            adx->endTime = D_003C7418;
        }
        adx->stat = ADX_STAT_FLUSH;
    }
    adx->ended = 1;
pad:
    if (Obj3260_GetByte_1_D778(adx->sji) != SJ_STAT_END)
        return;
    nch = func_0032A5B8(adx);
    len = adx->blk * nch * 2;
    for (i = 0; i < nch; i++) {
        SjObj *o = adx->sjo[i];

        o->vt->getChunk(o, 0, len, &ck);
        func_003A52F0(ck.data, 0, ck.len);
        o->vt->putChunk(o, 1, &ck);
    }
}
