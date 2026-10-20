/* func_001EC088: swing paired parts toward +-pi/2 or 0 by flag bits (sn-2.95.3-136) */
typedef struct {
    char pad0[0x100];
    char pos[4];
    float rot;
} SwingPart;

typedef struct {
    char pad0[0x54];
    unsigned int flags;
    char pad58[0x1C4 - 0x58];
    SwingPart *parts[10];
} SwingObj;

extern char D_005FEE00[];
extern void cModel_calcParts(SwingPart *p);
extern void cSnd_SeCall(void *s, int a, int b, void *pos, int c, int d);

static inline unsigned char flagGet(SwingObj *o, unsigned int n)
{
    if (n >= 32)
        return 0;
    return ((long)o->flags >> n) & 1;
}

static inline void flagSet(SwingObj *o, unsigned int n)
{
    if (n < 32)
        o->flags |= 1L << n;
}

static inline void flagClr(SwingObj *o, unsigned int n)
{
    if (n < 32)
        o->flags &= ~(1L << n);
}

__attribute__((section(".text.func_001EC088")))
void func_001EC088(SwingObj *o)
{
    int i;
    int a;
    int b;
    unsigned char cnt;
    unsigned char cnt2;
    unsigned int na;
    unsigned int nb;
    float step;
    float half;

    step = 0.3141592741012573f;
    half = 1.5707963705062866f;
    for (i = 0; i < 5; i++) {
        a = i * 2;
        b = a + 1;
        na = i + 1;
        nb = i + 6;
        if (!flagGet(o, nb))
            continue;
        if (o->parts[a] == 0)
            continue;
        if (o->parts[b] == 0)
            continue;
        if (!flagGet(o, na)) {
            o->parts[a]->rot += step;
            cnt = 0;
            if (half <= o->parts[a]->rot) {
                o->parts[a]->rot = half;
                cnt = 1;
            }
            cModel_calcParts(o->parts[a]);
            o->parts[b]->rot -= step;
            if (o->parts[b]->rot <= -half) {
                o->parts[b]->rot = -half;
                cnt++;
            }
            cModel_calcParts(o->parts[b]);
            if (cnt == 2) {
                flagSet(o, na);
                flagClr(o, nb);
                cSnd_SeCall(D_005FEE00, 2, 0, o->parts[a]->pos, 0, 0);
            }
        } else {
            o->parts[a]->rot -= step;
            cnt2 = 0;
            if (o->parts[a]->rot <= 0.0f) {
                o->parts[a]->rot = 0.0f;
                cnt2 = 1;
            }
            cModel_calcParts(o->parts[a]);
            o->parts[b]->rot += step;
            if (0.0f <= o->parts[b]->rot) {
                o->parts[b]->rot = 0.0f;
                cnt2++;
            }
            cModel_calcParts(o->parts[b]);
            if (cnt2 == 2) {
                flagClr(o, na);
                flagClr(o, nb);
            }
        }
    }
}
