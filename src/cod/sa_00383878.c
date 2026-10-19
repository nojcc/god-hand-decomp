/* sn-2.95.3-136: func_00383878, clone of func_00381F18 for the second sound block: sound option input: left/right step the selected slot's level (by 10 with the
 * fast bit held, clamped to [-960, 0]) and convert it, up/down step the raw index (clamped to [0, 127]) and look
 * the level up in D_003F2060, then refresh the slots. */
typedef struct Snd383878 {
    char pad00[4];
    unsigned char slot;                 /* 0x04 */
    char pad05[3];
    short level[5];                     /* 0x08 */
    short index[5];                     /* 0x12 */
} Snd383878;

typedef struct Obj383878 {
    char pad000[0x370];
    Snd383878 snd;                      /* 0x370 */
} Obj383878;

typedef struct Pad383878 {
    char pad00[0x2C];
    int hold;                           /* 0x2C */
    char pad30[8];
    int trig;                           /* 0x38 */
} Pad383878;

extern unsigned short D_003F2060[];
extern short func_003807E0(Obj383878 *o, int level);
extern void func_00383A20(Obj383878 *o, Snd383878 *p);

__attribute__((section(".text.func_00383878")))
void func_00383878(Obj383878 *o, Pad383878 *pad)
{
    Snd383878 *p;
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
    func_00383A20(o, p);
}
