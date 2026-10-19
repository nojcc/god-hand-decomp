/* sn-2.95.3-136: func_001DCAD8, when two slots show kind 2, mark every card except one whose rank matches no other card. */
#define SLOT_NUM     5
#define SLOT_F_MARK  0x4

typedef struct SlotCard1DCAD8 {
    char unk000[0x604];
    int rank;                           /* 0x604 */
} SlotCard1DCAD8;

typedef struct SlotRec1DCAD8 {
    SlotCard1DCAD8 *card;               /* 0x00 */
    int flags;                          /* 0x04 */
} SlotRec1DCAD8;

typedef struct SlotObj1DCAD8 {
    char unk0000[0x3004];
    SlotRec1DCAD8 *slot[SLOT_NUM];      /* 0x3004 */
} SlotObj1DCAD8;

extern void func_001DBFB8(SlotObj1DCAD8 *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DCAD8")))
int func_001DCAD8(SlotObj1DCAD8 *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short n;
    signed char odd;
    int i;
    int j;
    int k;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    n = 0;
    for (j = 0; j < SLOT_NUM; j++) {
        if (y[j] == 2)
            n++;
    }
    if (n != 2)
        return 0;
    for (i = 0; i < SLOT_NUM; i++) {
        odd = i;
        k = 0;
        do {
            if (i != k && self->slot[i]->card->rank == self->slot[k]->card->rank) {
                odd = -1;
                break;
            }
        } while (++k < SLOT_NUM);
        if (odd != -1) {
            int l;

            for (l = 0; l < SLOT_NUM; l++) {
                if (odd == l)
                    self->slot[l]->flags &= ~SLOT_F_MARK;
                else
                    self->slot[l]->flags |= SLOT_F_MARK;
            }
        }
    }
    return 1;
}
