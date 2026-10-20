/* sn-2.95.3-136 TU. */

typedef struct EffPart {
    char pad00[0x40];
    float sx;                   /* 0x40 */
    float sy;                   /* 0x44 */
    char pad48[4];
    unsigned int col;           /* 0x4C */
} EffPart;

typedef struct EffPartSlot {
    EffPart *a;            /* 0x00 */
    int pad04;
    EffPart *b;            /* 0x08 */
    EffPart *c;            /* 0x0C */
    int pad10;
} EffPartSlot;

typedef struct EffPartObj {
    char pad000[0x90];
    unsigned int flags;         /* 0x090 */
    EffPartSlot slot[5];       /* 0x094 */
    char pad0F8[0x338 - 0xF8];
    float scale;                /* 0x338 */
    char pad33C[0x364 - 0x33C];
    unsigned int col0;          /* 0x364 */
    unsigned int col1;          /* 0x368 */
    char pad36C[0x41E - 0x36C];
    short f41E;                 /* 0x41E */
    short step;                 /* 0x420 */
} EffPartObj;

extern float D_0041E880[];
extern float D_0041E884;

__attribute__((section(".text.func_00145FC8")))
void func_00145FC8(EffPartObj *ef)
{
    unsigned short i;
    float t;
    float u;

    ef->scale *= 0.7f;
    switch (ef->step) {
    case 0:
        ef->step++;
    case 1:
        ef->col0 += 0xE0000000;
        if (ef->col0 == 0x808080) {
            ef->scale = 1.0f;
            ef->step++;
        }
        for (i = 0; i < 5; i++) {
            ef->slot[i].b->sx = (t = D_0041E880[i]) * (1.0f - ef->scale + 1.0f);
            t *= ef->scale;
            ef->slot[i].b->sy = t;
            if (i != 1)
                ef->slot[i].a->col = ef->col0;
        }
        ef->slot[1].b->col = ef->col0;
        break;
    case 2:
        ef->col1 += 0xF0000000;
        if (ef->col1 == 0x808080)
            ef->step++;
        ef->slot[1].c->col = ef->col1;
        u = D_0041E884;
        ef->slot[1].c->sx = u * (1.0f - ef->scale + 1.0f);
        u *= ef->scale;
        ef->slot[1].c->sy = u;
        break;
    case 3:
        ef->flags &= ~0x40000000;
        ef->flags &= ~0x20000000;
        ef->f41E = 0;
        ef->step = 0;
        break;
    }
}
