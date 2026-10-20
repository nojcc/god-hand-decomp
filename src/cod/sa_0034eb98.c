/* cygnus-2.96: SFD video time marks, tail call into func_0034F200 (0x34EB98). */

typedef struct {
    char pad0[0x10];
    long tmin0;
    long tmin1;
    char pad20[8];
    int last;
    char pad2C[4];
    int first;
    char pad34[4];
    int mark;
} Tm34EB98;

typedef struct {
    char pad0[8];
    Tm34EB98 *tm;
    char padC[0xC];
    int video;
} Ch34EB98;

typedef struct {
    char pad0[0x1F74];
    Ch34EB98 ch;
} Sfd34EB98;

extern int GetArrayElemA0C_35A1C8(void *hn, int id);
extern int func_0034F200(void *w, int ch, char *src, int len, long pts);

__attribute__((section(".text.func_0034EB98")))
int func_0034EB98(Sfd34EB98 *s, int t, char *src, int len, long pts)
{
    Ch34EB98 *ch;
    Tm34EB98 *tm;
    int v;

    if (GetArrayElemA0C_35A1C8(s, 6) == 0) {
        return 1;
    }
    ch = &s->ch;
    tm = ch->tm;
    if (tm->mark == -1) {
        tm->mark = t;
    }
    if (tm->first == -1) {
        tm->first = t;
    }
    v = GetArrayElemA0C_35A1C8(s, 0x1E);
    if (v != -1) {
        if (GetArrayElemA0C_35A1C8(s, 0x37) != 0 ? t < tm->last : t == tm->first) {
            tm->mark = v;
        }
    }
    tm->last = t;
    if (tm->mark != t) {
        return 1;
    }
    if (pts >= 0) {
        tm->tmin0 = (pts < tm->tmin0) ? pts : tm->tmin0;
        tm->tmin1 = (pts < tm->tmin1) ? pts : tm->tmin1;
    }
    return func_0034F200(s, ch->video, src, len, pts);
}
