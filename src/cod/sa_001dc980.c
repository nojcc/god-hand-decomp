/* sn-2.95.3-136: func_001DC980, when a slot shows kind 3, mark the first card pair group (two matches of one rank) and report it. */
#define SLOT_NUM     5
#define SLOT_F_MARK  0x4

typedef struct SlotCard1DC980 {
    char unk000[0x604];
    int rank;                           /* 0x604 */
} SlotCard1DC980;

typedef struct SlotRec1DC980 {
    SlotCard1DC980 *card;               /* 0x00 */
    int flags;                          /* 0x04 */
} SlotRec1DC980;

typedef struct SlotObj1DC980 {
    char unk0000[0x3004];
    SlotRec1DC980 *slot[SLOT_NUM];      /* 0x3004 */
} SlotObj1DC980;

extern void func_001DBFB8(SlotObj1DC980 *self, unsigned short *x0, unsigned short *y0, unsigned short *x1, unsigned short *y1,
                          unsigned short *x2, unsigned short *y2, unsigned short *x3, unsigned short *y3,
                          unsigned short *x4, unsigned short *y4);

__attribute__((section(".text.func_001DC980")))
int func_001DC980(SlotObj1DC980 *self)
{
    unsigned short x[8];
    unsigned short y[8];
    unsigned short n;
    int i;
    int j;
    int k;

    func_001DBFB8(self, &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3], &x[4], &y[4]);
    for (j = 0; j < SLOT_NUM; j++) {
        if (y[j] == 3) {
            for (i = 0; i < SLOT_NUM - 1; i++) {
                int l;

                for (l = 0; l < SLOT_NUM; l++)
                    self->slot[l]->flags &= ~SLOT_F_MARK;
                n = 0;
                for (k = i + 1; k < SLOT_NUM; k++) {
                    if (self->slot[i]->card->rank == self->slot[k]->card->rank) {
                        n++;
                        self->slot[i]->flags |= SLOT_F_MARK;
                        self->slot[k]->flags |= SLOT_F_MARK;
                    }
                }
                if (n == 2)
                    break;
            }
            return 1;
        }
    }
    return 0;
}
