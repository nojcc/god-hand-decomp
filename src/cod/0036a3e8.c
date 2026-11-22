/* cygnus-2.96: MPEG video header decode: peek the input SJ, check for a sequence end, then step
 * through the delimiters (sequence, GOP, picture, user data, extension) until a picture start or an error. */
#include "godhand/criSj.h"
typedef struct MpvHdrDec {
    char pad[0x3F4];
    int f3F4;                           /* 0x3F4 */
} MpvHdrDec;

extern int Obj0000_Set_D_00766D44_Check_Field_188_NE_2(MpvHdrDec *dec);
extern int func_00369F20(MpvHdrDec *dec, int err);
extern int mpvhdec_GetCodec(MpvHdrDec *dec, SjChunk *ck);
extern int MPVM2V_DecodePicAtr(MpvHdrDec *dec, SjObj *sj);
extern int mpvhdec_RecoverSj(MpvHdrDec *dec, int a, SjObj *sj);
extern int mpvhdec_GetCurDelim(SjObj *sj);
extern int mpvhdec_DecEscSj(MpvHdrDec *dec, SjObj *sj, int last);
extern int mpvhdec_DecUdscSj(MpvHdrDec *dec, SjObj *sj, int last);
extern void mpvhdec_DecPscSj(MpvHdrDec *dec, SjObj *sj);
extern void mpvhdec_DecGscSj(MpvHdrDec *dec, SjObj *sj);
extern void mpvhdec_DecShcSj(MpvHdrDec *dec, SjObj *sj);

__attribute__((section(".text.MPV_DecodePicAtrSj")))
int MPV_DecodePicAtrSj(MpvHdrDec *dec, SjObj *sj)
{
    SjChunk ck;
    SjChunk ck2;
    int d;
    int last;
    int r;

    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(dec) != 0)
        return func_00369F20(0, 0xFF03020C);
    dec->f3F4 = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    sj->vt->ungetChunk(sj, 1, &ck);
    ck2.data = ck.data;
    ck2.len = ck.len;
    if (mpvhdec_GetCodec(dec, &ck2) == 2)
        return MPVM2V_DecodePicAtr(dec, sj);
    last = 0;
    for (;;) {
        r = mpvhdec_RecoverSj(dec, -1, sj);
        if (r != 0)
            return func_00369F20(dec, r);
        d = mpvhdec_GetCurDelim(sj);
        if (d == 0)
            break;
        if (d & 3)
            break;
        r = -2;
        if (d & 0x80)
            break;
        switch (d) {
        case 0x40:
            last = 0x40;
            mpvhdec_DecShcSj(dec, sj);
            break;
        case 0x08:
            last = 0x08;
            mpvhdec_DecGscSj(dec, sj);
            break;
        case 0x04:
            last = 0x04;
            mpvhdec_DecPscSj(dec, sj);
            break;
        case 0x10:
            mpvhdec_DecEscSj(dec, sj, last);
            break;
        case 0x20:
            mpvhdec_DecUdscSj(dec, sj, last);
            break;
        }
    }
    return r;
}
