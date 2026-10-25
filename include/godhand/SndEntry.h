/* include/godhand/SndEntry.h - the sound voice table.
 *
 * The table holds SND_VOICE_NUM 0x40-byte entries. An entry is live while
 * `active` is nonzero. Names are ours; unnamed fields stay as padding.
 */
#ifndef GODHAND_SNDENTRY_H
#define GODHAND_SNDENTRY_H

#define SND_VOICE_NUM         0x60
#define SND_VOICE_FLAG_SKIP   0x10   /* SndVoice.flags: ignored by the id search */

typedef struct SndVoice {
    unsigned short active;              /* 0x00 */
    short unk02;
    int id;                             /* 0x04 0 matches any voice */
    unsigned char flags;                /* 0x08 */
    char unk09[0x37];
} SndVoice;                             /* 0x40 */

/* The parameters of one sound-driver entry, 0x30 bytes; the driver copies
 * them whole into its event (AddSoundEntry_374F30). */
typedef struct SndEntryParam {
    short no;                           /* 0x00 index into the driver's sound table */
    short unk02;
    char unk04[6];
    unsigned short dirty;               /* 0x0A values to resend: 0xB after a volume change, 0xF with the pan */
    unsigned short unk0C;               /* 0x0C bit 1 set when the sound starts inside the hit set */
    unsigned short fixFlags;            /* 0x0E 1 volume, 2 pitch, 4 pan kept; 0x8000 unused */
    short volL;                         /* 0x10 */
    short volR;                         /* 0x12 */
    short pitch;                        /* 0x14 */
    short pan;                          /* 0x16 angle in degrees */
    char unk18[4];
    unsigned short unk1C;               /* 0x1C */
    char unk1E[0xA];
    unsigned short unk28;               /* 0x28 counted up (to 0xFFFF) with unk0C bit 1 */
    char unk2A[6];
} SndEntryParam;                        /* 0x30 */

typedef char SndEntryParam_size_check[sizeof(SndEntryParam) == 0x30 ? 1 : -1];

/* Definitions in 003749d8.c. */
int AddSoundEntry_374F30(int a0, void *a1);
int BuildSoundNode_374DF8(void *a0, int a1);
int UpdateEntryVolume_3751B8(void *a0, short a1);
int UpdateEntryParams_3752A0(void *a0, int a1);

#endif
