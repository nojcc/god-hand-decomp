/* sn-2.95.3-136: NM closer handoff. */
#define SLOT_NUM     5
#define SLOT_F_MARK  0x4

typedef struct SlotCard1DCC30 {
    char unk000[0x604];
    int rank;                           /* 0x604 */
} SlotCard1DCC30;

typedef struct SlotRec1DCC30 {
    SlotCard1DCC30 *card;               /* 0x00 */
    int flags;                          /* 0x04 */
} SlotRec1DCC30;

typedef struct SlotObj1DCC30 {
    char unk0000[0x3004];
    SlotRec1DCC30 *slot[SLOT_NUM];      /* 0x3004 */
} SlotObj1DCC30;

extern void func_001DBFB8(SlotObj1DCC30 *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DCC30")))
int func_001DCC30(SlotObj1DCC30 *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short pair[2];
    unsigned short n;
    int i;
    int j;
    int k;
    int l;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    n = 0;
    for (j = 0; j < SLOT_NUM; j++) {
        if (y[j] == 2)
            n++;
    }
    if (n != 1)
        return 0;
    for (i = 0; i < SLOT_NUM - 1; i++) {
        k = i + 1;
        if (k < SLOT_NUM) {
            do {
                if (self->slot[i]->card->rank == self->slot[k]->card->rank) {
                    pair[0] = i;
                    pair[1] = k;
                    break;
                }
            } while (++k < SLOT_NUM);
        }
    }
    for (l = 0; l < SLOT_NUM; l++)
        self->slot[l]->flags &= ~SLOT_F_MARK;
    self->slot[pair[0]]->flags |= SLOT_F_MARK;
    self->slot[pair[1]]->flags |= SLOT_F_MARK;
    return 1;
}
