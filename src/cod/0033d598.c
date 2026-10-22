/* cygnus-2.96 */

/* Decode parameters of an ADXB object (at 0x48 in it). */
typedef struct AdxbDecodePrm {
    char pad00[0x8];
    int nch;                            /* 0x08 */
    int blkSmpl;                        /* 0x0C */
    int blkLen;                         /* 0x10 */
    short *obuf;                        /* 0x14 */
    char pad18[0x8];
    int wpos;                           /* 0x20 */
    char pad24[0x4];
    int total;                          /* 0x28 */
} AdxbDecodePrm;

/* View of the ADXB object fields the end-of-decode step reads and writes. */
typedef struct AdxbDecodeView {
    char pad00[0x8];
    char *dec;                          /* 0x08 */
    char pad0C[0x34];
    int obsize;                         /* 0x40 */
    int obdist;                         /* 0x44 */
    AdxbDecodePrm prm;                  /* 0x48 */
    char pad74[0x1C];
    int nsmpl;                          /* 0x90 */
    int ndata;                          /* 0x94 */
    char pad98[0x50];
    int replay;                         /* 0xE8 */
} AdxbDecodeView;

extern int Obj33F8_GetWord_10_FB60(char *a0);
extern void ADXB_CopyExtraBufSte(short *obuf, int obsize, int obdist, int nxsmpl);
extern void Forward33D4D8_33D578(short *a0, int a1, int a2, int a3);

/* After a decode pass: count the samples produced (the last block only up to the data's end), and when
 * the write position runs past the output buffer, copy the overflow back to its start. */
__attribute__((section(".text.func_0033D598")))
void func_0033D598(AdxbDecodeView *adx)
{
    AdxbDecodePrm *prm;
    int blkLen;
    int nblk;
    int rest;
    int obdist;
    int obsize;
    short *obuf;
    int blkSmpl;
    int wpos;
    int ndec;
    int nch;
    int last;
    int nsmpl;
    int pad;

    prm = &adx->prm;
    blkLen = prm->blkLen;
    last = prm->total + blkLen - 1;
    obsize = adx->obsize;
    nblk = last / blkLen;
    rest = last % blkLen;
    pad = blkLen - rest - 1;
    obuf = prm->obuf;
    obdist = adx->obdist;
    blkSmpl = prm->blkSmpl;
    wpos = prm->wpos;
    ndec = Obj33F8_GetWord_10_FB60(adx->dec);
    nch = prm->nch;
    nsmpl = ndec * blkLen / nch;
    adx->ndata = ndec * blkSmpl;
    if (ndec >= nblk * nch) {
        nsmpl -= pad;
    }
    adx->nsmpl = nsmpl;
    wpos += nsmpl;
    if (wpos >= obsize) {
        wpos -= obsize;
        if (prm->nch == 2 || adx->replay != 0) {
            ADXB_CopyExtraBufSte(obuf, obsize, obdist, wpos);
        } else {
            Forward33D4D8_33D578(obuf, obsize, obdist, wpos);
        }
    }
}
