/* include/godhand/MpvPicAtr.h - the picture attributes of CRI libmpv (MPV).
 *
 * The 0x80-byte block an MPV handle keeps at 0x1D0. MPV_GetPicAtr copies it
 * out, and the Sofdec side keeps a copy in its work area and in each frame.
 * Field names are ours, from the Sofdec functions that read them; offsets
 * are exact.
 */
#ifndef GODHAND_MPVPICATR_H
#define GODHAND_MPVPICATR_H

typedef struct MpvPicAtr {
    int width;                  /* 0x00 */
    int height;                 /* 0x04 */
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    int rate;                   /* 0x10 */
    int ofs;                    /* 0x14 frame offset, also the channel */
    unsigned int picType;       /* 0x18 1 I, 2 P, 3 B */
    int drop;                   /* 0x1C */
    int tcHour;                 /* 0x20 GOP time code */
    int tcMin;                  /* 0x24 */
    int tcSec;                  /* 0x28 */
    int tcPic;                  /* 0x2C */
    int f30;                    /* 0x30 */
    char unk34[0x38 - 0x34];
    int f38;                    /* 0x38 */
    char unk3C[0x57 - 0x3C];
    signed char f57;            /* 0x57 */
    unsigned int picStruct;     /* 0x58 0 none, 1-2 field, 3 frame */
    char unk5C[0x68 - 0x5C];
    int unk68;                  /* 0x68 cleared by each sequence and GOP header */
    signed char progressive;    /* 0x6C */
    char unk6D[0x80 - 0x6D];
} MpvPicAtr;
typedef char MpvPicAtr_size_check[(sizeof(MpvPicAtr) == 0x80) ? 1 : -1];

#endif /* GODHAND_MPVPICATR_H */
