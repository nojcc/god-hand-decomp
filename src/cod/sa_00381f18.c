/* sn-2.95.3-136: func_00381F18, sound option input: left/right step the selected slot's level (by 10 with the
 * fast bit held, clamped to [-960, 0]) and convert it, up/down step the raw index (clamped to [0, 127]) and look
 * the level up in D_003F2060, then refresh the slots. */
typedef struct Snd381F18 {
    char pad00[2];
    unsigned char slot;                 /* 0x02 */
    char pad03;
    short level[5];                     /* 0x04 */
    short index[5];                     /* 0x0E */
} Snd381F18;

typedef struct Obj381F18 {
    char pad000[0x318];
    Snd381F18 snd;                      /* 0x318 */
} Obj381F18;

typedef struct Pad381F18 {
    char pad00[0x2C];
    int hold;                           /* 0x2C */
    char pad30[8];
    int trig;                           /* 0x38 */
} Pad381F18;

extern unsigned short D_003F2060[];
extern short func_003807E0(Obj381F18 *o, int level);
extern void func_003820C0(Obj381F18 *o, Snd381F18 *p);

__attribute__((section(".text.func_00381F18")))
void func_00381F18(Obj381F18 *o, Pad381F18 *pad)
{
    Snd381F18 *p;
    short step;
    int trig;

    p = &o->snd;
    step = 1;
    if (pad->hold & 2)
        step = 10;
    trig = pad->trig;
    if (trig < 0) {
        if (o->snd.level[p->slot] >= step - 960)
            o->snd.level[p->slot] -= step;
        else
            o->snd.level[p->slot] = -960;
    } else if (trig & 0x40000000) {
        if (o->snd.level[p->slot] <= -step)
            o->snd.level[p->slot] += step;
        else
            o->snd.level[p->slot] = 0;
    } else {
        goto index;
    }
    p->index[p->slot] = func_003807E0(o, p->level[p->slot]);
    goto done;
index:
    if (trig & 0x8000) {
        if (o->snd.index[p->slot] >= step)
            o->snd.index[p->slot] -= step;
        else
            o->snd.index[p->slot] = 0;
    } else if (trig & 0x2000) {
        if (o->snd.index[p->slot] <= 127 - step)
            o->snd.index[p->slot] += step;
        else
            o->snd.index[p->slot] = 127;
    } else {
        return;
    }
    p->level[p->slot] = D_003F2060[p->index[p->slot]];
done:
    func_003820C0(o, p);
}
