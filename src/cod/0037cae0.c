/* sn-2.95.3-136: func_0037CAE0, per-frame voice scan: step every live voice (sequenced voices poll their sequence and retire when it ends), then store the per-kind live counts. */
typedef struct SndVoiceSlot {
    unsigned short id;                  /* 0x00 */
    short seq;                          /* 0x02 */
    char pad04;
    unsigned char flags;                /* 0x05 1/2/4 kind, 8 sequenced */
    char pad06[0x50 - 0x6];
} SndVoiceSlot;

typedef struct SndSeqSlot {
    char pad[0x84];
} SndSeqSlot;

typedef struct SndVoiceStat {
    char pad00[0x24];
    unsigned char nKind1;               /* 0x24 */
    unsigned char nKind2;               /* 0x25 */
    unsigned char nKind4;               /* 0x26 */
    unsigned char nTotal;               /* 0x27 */
} SndVoiceStat;

extern SndVoiceSlot D_0076CF20[51];
extern SndSeqSlot D_0076A600[];
extern SndVoiceStat D_0076A790;

extern int GetSequenceResult_373770(SndSeqSlot *seq);
extern void UpdateSequenceNode_373430(SndSeqSlot *seq);
extern void ResetNodeData_3733C8(SndSeqSlot *seq);
extern void func_0037D148(SndVoiceSlot *v);
extern void func_0037D3B0(SndVoiceSlot *v);
extern void func_0037CC78(SndVoiceSlot *v);
extern void func_0037CCE0(SndVoiceSlot *v);

__attribute__((section(".text.func_0037CAE0")))
void func_0037CAE0(void)
{
    SndVoiceStat *st;
    SndVoiceSlot *v;
    unsigned char n1;
    unsigned char n2;
    unsigned char n4;
    int i;

    st = &D_0076A790;
    n1 = 0;
    n2 = 0;
    n4 = 0;
    for (i = 0; i < 51; i++) {
        v = &D_0076CF20[i];
        if (v->id == 0)
            continue;
        if (v->flags & 8) {
            switch (GetSequenceResult_373770(&D_0076A600[v->seq])) {
            case 6:
                UpdateSequenceNode_373430(&D_0076A600[v->seq]);
                ResetNodeData_3733C8(&D_0076A600[v->seq]);
                /* fall through */
            case 0:
                func_0037D148(v);
                func_0037D3B0(v);
                break;
            default:
                func_0037CC78(v);
                func_0037CCE0(v);
                n1++;
                break;
            }
        } else {
            func_0037CC78(v);
            func_0037CCE0(v);
            if (v->flags & 1)
                n1++;
            if (v->flags & 2)
                n2++;
            if (v->flags & 4)
                n4++;
        }
    }
    st->nKind1 = n1;
    st->nKind2 = n2;
    st->nKind4 = n4;
    st->nTotal = n1 + n2 + n4;
}
