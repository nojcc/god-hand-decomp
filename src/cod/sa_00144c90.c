/* func_00144C90: 5x5 ID work table setup and placement (sn-2.95.3-136, as=sn) */
typedef struct { float x, y, z; } Vec3;

typedef struct E144 {
    char pad0[0x1C];
    struct E144 *link;
    char pad20[4];
    int f24;
    char pad28[4];
    unsigned int flags;
    char pad30[8];
    float x;
    float y;
    int f40;
    int f44;
    char pad48[4];
    int col;
    int f50;
    char pad54[0x14];
    float w;
} E144;

typedef struct {
    char pad0[0x1C];
    unsigned char f1C;
    char pad1D[0x33];
} IdW144;

typedef struct {
    char pad0[0x94];
    E144 *tbl[5][5];
    char padF8[8];
    IdW144 ids[5];
    Vec3 pos;
    char pad29C[8];
    int f2A4;
    int cols[5];
    char pad2BC[0x80];
    float ys[5];
    float xs[5];
    int f364;
    int f368;
    char pad36C[0xB2];
    short f41E;
    short f420;
} Obj144;

extern Vec3 D_003BD880;
extern float D_0041E880[];
extern void cIDBase_initIDWork(void *w, int id);
extern void cIDBase_restartAnim(void *w);
extern E144 *cIDBase_getIDWork(void *w, int id);
extern void cIDBase_move(void *w);

static inline void vcpy(Vec3 *d, Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

__attribute__((section(".text.func_00144C90")))
void func_00144C90(Obj144 *self)
{
    unsigned short i;
    unsigned short j;
    unsigned short k;
    E144 *e;
    float sc;

    vcpy(&self->pos, &D_003BD880);
    self->pos.x = 155.0f;
    self->pos.y = -59.0f;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cIDBase_initIDWork(&self->ids[j], i);
            cIDBase_restartAnim(&self->ids[j]);
            *((unsigned char *)self + j * 0x50 + 0x11C) = 0;
            self->tbl[j][i] = cIDBase_getIDWork(&self->ids[j], i);
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 1) {
            self->tbl[1][0]->col = self->tbl[1][0]->link->f50;
        } else {
            self->tbl[i][0]->col = 0x50808080;
        }
        sc = D_0041E880[i];
        self->tbl[i][1]->f24 = self->cols[i];
        self->tbl[i][0]->f40 = 0;
        self->tbl[i][0]->f44 = 0;
        self->tbl[i][0]->x = self->tbl[i][0]->x + self->pos.x + (self->tbl[i][0]->w * sc - self->tbl[i][0]->w) * 0.5f;
        self->tbl[i][0]->y = self->tbl[i][0]->y + self->pos.y + (float)(i * 32);
        self->tbl[i][1]->f40 = 0;
        self->tbl[i][1]->f44 = 0;
        self->ys[i] = self->tbl[i][0]->y;
        self->xs[i] = self->tbl[i][0]->x;
    }
    self->tbl[4][1]->f24 = self->cols[i];
    self->tbl[4][0]->f40 = 0;
    self->tbl[4][0]->f44 = 0;
    self->tbl[4][1]->f40 = 0;
    self->tbl[4][1]->f44 = 0;
    self->tbl[4][0]->x = self->tbl[4][0]->x + self->pos.x - self->tbl[4][0]->w * 0.5f;
    self->tbl[4][0]->y = self->tbl[3][0]->y;
    e = self->tbl[4][0];
    self->xs[4] = e->x;
    self->ys[4] = e->y;
    e->flags |= 8;
    self->f41E = 1;
    self->f420 = 0;
    self->f2A4 = 0;
    self->f364 = 0x80808080;
    self->f368 = 0x80808080;
    for (k = 0; k < 5; k++) {
        cIDBase_move(&self->ids[k]);
    }
}
