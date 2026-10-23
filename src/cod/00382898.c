/* sn-2.95.3-136 */

/* The playback record of the stream on the second sound test page. */
typedef struct SndStrmInfo {
    int pos;                    /* 0x00 */
    int total;                  /* 0x04 */
    int f08;                    /* 0x08 */
    int f0C;                    /* 0x0C */
    int f10;                    /* 0x10 */
    int loopEnd;                /* 0x14 */
    unsigned char mode[5];      /* 0x18 per slot */
} SndStrmInfo;

/* The slot settings of the stream sound test (menuCtl.h's SndOptLevels covers 0x00..0x17). */
typedef struct SndStrmSlots {
    unsigned char kind;         /* 0x00 */
    unsigned char err;          /* 0x01 */
    unsigned char slot;         /* 0x02 */
    char pad03;
    short level[5];             /* 0x04 */
    short index[5];             /* 0x0E */
    short pan[5];               /* 0x18 */
    short pitch[5];             /* 0x22 */
    int state;                  /* 0x2C */
} SndStrmSlots;

/* The second sound test page. */
typedef struct SndStrmPage {
    char pad000[0x3C];
    char *name;                 /* 0x03C g++ string (length word 0x10 bytes before the text) */
    char pad040[0x318 - 0x40];
    SndStrmSlots snd;           /* 0x318 */
    SndStrmInfo info;           /* 0x348 */
} SndStrmPage;

extern void func_002E0DE8(int x, int y, int color, const char *fmt, ...);
extern void func_00380720(void *self, int a, int b, int *hh, int *mm, int *ss, int *cc);

extern char D_0045C800[];
extern char D_0045C808[];
extern char D_0045C820[];
extern char D_0045C830[];
extern char D_0045C850[];
extern char D_0045C870[];
extern char D_0045C888[];
extern char D_0045C898[];
extern char D_0045C8A0[];
extern char D_0045C8A8[];
extern char D_0045C8C8[];
extern char D_0045C8E8[];
extern char D_0045C8F8[];
extern char D_0045C908[];
extern char D_0045C918[];
extern char D_0045C928[];
extern char D_0045C948[];
extern char D_0045C960[];
extern char D_0045C970[];
extern char D_0045C980[];
extern char D_0045C990[];
extern char D_0045C9B0[];
extern char D_0045C9C0[];
extern char D_0045C9D0[];
extern char *D_003F2840[];
extern char *D_003F2858[];
extern char *D_003F2870[];

/* The g++ string's text, terminated, or "" when it is empty. */
static __inline__ char *StrText(char **s)
{
    int len = ((int *)*s)[-4];

    if (len == 0)
        return D_0045C800;
    (*s)[len] = 0;
    return *s;
}

/* Print the stream sound test page. */
__attribute__((section(".text.func_00382898")))
void func_00382898(SndStrmPage *self)
{
    int hh;
    int mm;
    int ss;
    int cc;
    SndStrmSlots *snd = &self->snd;
    SndStrmInfo *info = &self->info;
    int color;

    func_002E0DE8(0x11, 3, 0xD, D_0045C808);
    func_002E0DE8(3, 5, 8, D_0045C820, StrText(&self->name));
    switch (snd->state) {
    case -1:
        if (snd->err != 0) {
            if (snd->err == 1)
                func_002E0DE8(0xF, 0x16, 0xE, D_0045C830);
            else
                func_002E0DE8(0xF, 0x16, 0xE, D_0045C850);
            func_002E0DE8(0x13, 0x17, 8, D_0045C870);
        }
        /* fall through */
    case 0:
    case 3:
        color = 0xF;
        break;
    case 4:
        color = 0xA;
        break;
    default:
        color = 0xD;
        break;
    }
    func_002E0DE8(3, 7, 8, D_0045C888);
    if (snd->state >= 0)
        func_002E0DE8(0xC, 7, color, D_0045C898, D_003F2858[snd->state]);
    else
        func_002E0DE8(0xC, 7, color, D_0045C8A0);
    func_002E0DE8(0x14, 7, 0xE, D_003F2840[snd->kind]);
    func_00380720(self, info->total, info->pos, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 9, 8, D_0045C8A8, hh, mm, ss, cc);
    func_00380720(self, info->total, info->loopEnd, &hh, &mm, &ss, &cc);
    func_002E0DE8(3, 0xA, 8, D_0045C8C8, hh, mm, ss, cc);
    func_002E0DE8(0x20, 7, 8, D_0045C8E8, info->total);
    func_002E0DE8(0x20, 8, 8, D_0045C8F8, info->f08);
    func_002E0DE8(0x20, 9, 8, D_0045C908, info->f0C);
    func_002E0DE8(0x20, 0xA, 8, D_0045C918, info->f10);
    func_002E0DE8(3, 0xD, 0xD, D_0045C928);
    if (snd->slot == 0) {
        func_002E0DE8(3, 0xF, 8, D_0045C948, snd->level[snd->slot], snd->index[snd->slot]);
        func_002E0DE8(3, 0x10, 8, D_0045C960, snd->pan[snd->slot]);
        func_002E0DE8(3, 0x11, 8, D_0045C970, snd->pitch[snd->slot]);
        func_002E0DE8(3, 0x12, 8, D_0045C980, D_003F2870[info->mode[snd->slot]]);
    } else {
        func_002E0DE8(3, 0xF, 8, D_0045C990, snd->slot - 1, snd->level[snd->slot], snd->index[snd->slot]);
        func_002E0DE8(3, 0x10, 8, D_0045C9B0, snd->slot - 1, snd->pan[snd->slot]);
        func_002E0DE8(3, 0x11, 8, D_0045C9C0, snd->slot - 1, snd->pitch[snd->slot]);
        func_002E0DE8(3, 0x12, 8, D_0045C9D0, snd->slot - 1, D_003F2870[info->mode[snd->slot]]);
    }
}
