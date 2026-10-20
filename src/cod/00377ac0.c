/* NON_MATCHING func_00377AC0: sn: the owner/track-id loads issue in the opposite order */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/seqNode.h"

typedef struct {
    unsigned short flags; /* 0x00 */
    short pad02;
    int id;               /* 0x04 */
    char pad08[0x60 - 0x08];
    unsigned short pan[4];   /* 0x60 */
    unsigned short vol[4];   /* 0x68 */
    unsigned short pitch[2]; /* 0x70 */
} SeqTrackView;

typedef struct {
    char unk00[0x14];
    int owner;              /* 0x14 */
    char unk18[2];
    short ch;               /* 0x1A */
    char unk1C[0x26 - 0x1C];
    unsigned short pan;     /* 0x26 */
    unsigned short vol;     /* 0x28 */
    char unk2A[2];
    unsigned short pitch;   /* 0x2C */
} SeqNodeVoice;

void func_00377AC0(SeqTrackView *t, unsigned short what)
{
    SeqNode *n = D_0076CF20;

    do {
        if (n->flags != 0 && (n->kind & 2) && t->id == ((SeqNodeVoice *)n)->owner) {
            SeqNodeVoice *v = (SeqNodeVoice *)n;

            switch (what) {
            case 1:
                v->pan = t->pan[v->ch / 2];
                v->vol = t->vol[v->ch / 2];
                n->sub |= 9;
                break;
            case 2:
                v->pitch = t->pitch[(short)(v->ch % 2)];
                n->sub |= 0xA;
                break;
            }
        }
        n++;
    } while ((int)n < (int)(D_0076CF20 + 48));
}
#else
INCLUDE_ASM("asm/nonmatching", func_00377AC0);
#endif
