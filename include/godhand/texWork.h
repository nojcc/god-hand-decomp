/* include/godhand/texWork.h - the texture bank work: queued image uploads and the TEX0 packets of the loaded textures.
 * Offsets are exact; unnamed fields stay as padding. */
#ifndef GODHAND_TEXWORK_H
#define GODHAND_TEXWORK_H

#include "godhand/tim2.h"

#define IMAGEUP_MAX  0x280
#define TEXWORK_PKT_MAX  450

/* The image upload list: a count, then one slot per upload holding a packet for each frame buffer. */
typedef struct ImageUpList {
    char unk00[0x3C];
    int num;                            /* 0x3C uploads queued */
    char slot[IMAGEUP_MAX][2][0xC0];    /* 0x40 */
} ImageUpList;

typedef struct TexWork {
    ImageUpList images;                 /* 0x00000 */
    char pad3C040[0x3DC88 - 0x3C040];
    GsTex0 pkt[TEXWORK_PKT_MAX][2];     /* 0x3DC88 TEX0 of each texture, per frame buffer */
    unsigned short nPkt;                /* 0x3F8A8 */
    unsigned char nImage;               /* 0x3F8AA */
    unsigned char nClut;                /* 0x3F8AB */
} TexWork;

int func_00150F68(ImageUpList *list, int src, int psm, int dbp, int dbw, int width, int height, int mode, int kind);
int func_00151168(ImageUpList *list, int src, int psm, int dbp, int unused, int width, int height, int mode, int kind);

#endif
