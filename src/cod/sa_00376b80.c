/* sn-2.95.3-136: func_00376B80, note on: unless the tone is disabled, take a free voice node and fill it from the sequence track, the note and the tone. */
#define TONE_F_OFF      0x8000
#define VOICE_KIND_NOTE 3

typedef struct SndTone {
    char pad00[4];
    unsigned short unk04;               /* 0x04 */
    char pad06[8];
    unsigned short flags;               /* 0x0E TONE_F_OFF */
    char pad10[8];
    unsigned short unk18;               /* 0x18 */
    unsigned short unk1A;               /* 0x1A */
    char pad1C[0x14];
} SndTone;                           /* 0x30 */

typedef struct SndToneBank {
    char pad00[4];
    SndTone *tone;                   /* 0x04 */
    char pad08[0x18];
} SndToneBank;                           /* 0x20 */

typedef struct SndTrack {
    char pad00[2];
    unsigned short unk02;               /* 0x02 */
    int unk04;                          /* 0x04 */
    short bank;                         /* 0x08 */
    char pad0A[4];
    unsigned char unk0E;                /* 0x0E */
    unsigned char keyBase;              /* 0x0F */
    char pad10[4];
    unsigned short unk14;               /* 0x14 */
} SndTrack;

typedef struct SndNote {
    char pad00[2];
    unsigned char key;                  /* 0x02 */
    unsigned char unk03;
    int unk04;                          /* 0x04 */
    unsigned short unk08;               /* 0x08 */
    short tone;                         /* 0x0A */
    unsigned short unk0C;               /* 0x0C */
    unsigned short unk0E;               /* 0x0E */
    unsigned short unk10;               /* 0x10 */
} SndNote;

typedef struct SndVoice {
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
    char pad16[0xA];
    unsigned short unk20;               /* 0x20 */
    unsigned short unk22;               /* 0x22 */
    unsigned short unk24;               /* 0x24 */
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
} SndVoice;

extern SndToneBank D_0076EA50[];

extern SndVoice *func_0037D170(void);
extern void func_00376CF8(SndTrack *trk, SndVoice *v);

__attribute__((section(".text.func_00376B80")))
void func_00376B80(SndTrack *trk, SndNote *note)
{
    SndTone *tone;
    SndVoice *v;
    int none;
    int prio;

    tone = D_0076EA50[trk->bank].tone;
    tone += note->tone;
    if (tone->flags & TONE_F_OFF)
        return;
    v = func_0037D170();
    if (v == 0)
        return;
    none = -1;
    prio = 0x17;
    v->kind = VOICE_KIND_NOTE;
    v->unk04 = note->unk04;
    v->unk08 = trk->unk04;
    v->unk0C = trk->unk0E;
    v->unk0D = 4;
    v->unk0E = none;
    v->unk10 = 0;
    v->unk12 = trk->unk02;
    v->unk14 = *(unsigned short *)&note->key;
    func_00376CF8(trk, v);
    v->unk20 = note->unk08;
    v->unk22 = note->tone;
    v->unk24 = tone->unk04;
    v->key = trk->keyBase + note->key;
    v->unk27 = 0;
    v->unk28 = 0x7F;
    v->unk29 = 0;
    v->unk2A = 0;
    v->unk2C = trk->unk14;
    v->unk2E = prio;
    v->unk30 = note->unk0C;
    v->unk32 = note->unk0C;
    v->unk34 = note->unk0E;
    v->unk36 = 0;
    v->unk38 = tone->unk18;
    v->unk3A = tone->unk1A;
    v->unk3C = note->unk10;
    v->unk3E = none;
    v->unk41 = 0;
    v->unk40 = 0;
    v->unk43 = 0;
    v->unk42 = 0;
}
