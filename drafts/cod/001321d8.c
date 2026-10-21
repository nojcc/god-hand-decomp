/* NON_MATCHING func_001321D8 (sn-2.95.3-136): collision grid sphere probe. Retail keeps the
 * &result pointer at 0x38 and y + 1 at 0x40 where ours swaps them, adds list + count with the
 * operands the other way round, and loads &pos before the colour select in the debug draw. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cOmBase.h"
#include "godhand/gameWork.h"

#define GAMESYS_FLAG_COLL_DEBUG  0x8000000  /* draw the collision probes */

#define CGRID_TEST_FLOOR  0x1
#define CGRID_TEST_WALL   0x2
#define CGRID_TEST_CEIL   0x4

/* One grid cell: first entry in the triangle index list and the count of each kind. */
typedef struct cCollCell {
    unsigned int first;                 /* 0x0 0xFFFFFFFF when empty */
    unsigned char count[3];             /* 0x4 floor, wall, ceiling */
    char unk7;
} cCollCell;

/* The stage collision grid and its sphere probe state. */
typedef struct cCollGrid {
    int enabled;                        /* 0x000 */
    char unk04[0x14];
    cCollCell *cells;                   /* 0x018 */
    unsigned short *index;              /* 0x01C */
    char unk20[0x44];
    unsigned int dimX;                  /* 0x064 */
    unsigned int dimZ;                  /* 0x068 */
    unsigned int y0;                    /* 0x06C probe cell range */
    unsigned int z0;                    /* 0x070 */
    unsigned int x0;                    /* 0x074 */
    unsigned int y1;                    /* 0x078 */
    unsigned int z1;                    /* 0x07C */
    unsigned int x1;                    /* 0x080 */
    char unk84[0x7C];
    cVec pos;                           /* 0x100 probe centre */
    float radius;                       /* 0x110 */
    char unk114[0xC];
    cVec result;                        /* 0x120 centre after the push-out */
    int unk130[4];
    int unk140;                         /* 0x140 */
    char unk144[0x30];
    int mask;                           /* 0x174 CGRID_TEST_* */
    int unk178;                         /* 0x178 */
    int hitInfo;                        /* 0x17C */
    unsigned char hit;                  /* 0x180 */
    char unk181[0xB];
    int unk18C;                         /* 0x18C */
} cCollGrid;

extern int func_0012F288(cCollGrid *self, cVec *lo, cVec *hi);
extern void func_0012F4C8(cCollGrid *self, unsigned int y0, unsigned int y1, unsigned int z0,
                          unsigned int z1, unsigned int x0, unsigned int x1, int arg);
extern void func_0012FC20(cCollGrid *self, unsigned short tri);
extern void func_001311A0(cCollGrid *self, void *arg);
extern int Circle_line2(char *a0, int x, float f1, int a2, int a3);

/* Run the triangle tests for n entries of the list from start on. */
static __inline__ void cCollGrid_testList(cCollGrid *self, unsigned short *list, unsigned int start,
                                          unsigned int n)
{
    unsigned short *tri = list + start;

    while (n-- != 0) {
        func_0012FC20(self, *tri++);
    }
}

/* Probe the grid with a sphere at pos; the pushed-out centre and hit info go to outPos and outInfo. */
int func_001321D8(cCollGrid *self, void *arg, cVec *pos, cVec *outPos, int mask, int a5, int a6,
                  int a7, float radius, int *outInfo)
{
    cVec lo;
    cVec hi;
    cVec *top;
    unsigned int y;
    unsigned int z;
    unsigned int x;
    unsigned int row[2];
    cCollCell *cell;
    unsigned short *list;

    if (self->enabled == 0) {
        return 0;
    }
    self->mask = mask;
    self->unk178 = a5;
    self->unk18C = a6;
    self->unk140 = a7;
    self->hitInfo = 0;
    self->hit = 0;
    cVec_copy3(&self->pos, pos);
    cVec_copy3(&self->result, &self->pos);
    self->radius = radius;
    top = &hi;
    lo.x = self->pos.x - radius;
    lo.y = self->pos.y - radius;
    lo.z = self->pos.z - radius;
    hi.x = self->pos.x + radius;
    hi.y = self->pos.y + radius;
    hi.z = self->pos.z + radius;
    lo.w = 1.0f;
    top->w = 1.0f;
    if (func_0012F288(self, &lo, top) == 0) {
        return 0;
    }
    func_0012F4C8(self, self->y0, self->y1, self->z0, self->z1, self->x0, self->x1, self->mask);
    for (y = self->y0; y <= self->y1; y++) {
        row[0] = y * self->dimX * self->dimZ;
        for (z = self->z0; z <= self->z1; z++) {
            row[1] = z * self->dimZ;
            for (x = self->x0; x <= self->x1; x++) {
                cell = &self->cells[row[0] + row[1] + x];
                if (cell->first == 0xFFFFFFFF) {
                    continue;
                }
                list = &self->index[cell->first];
                if (self->mask & CGRID_TEST_FLOOR) {
                    cCollGrid_testList(self, list, 0, cell->count[0]);
                }
                if (self->mask & CGRID_TEST_WALL) {
                    cCollGrid_testList(self, list, cell->count[0], cell->count[1]);
                }
                if (self->mask & CGRID_TEST_CEIL) {
                    cCollGrid_testList(self, list + cell->count[0], cell->count[1], cell->count[2]);
                }
            }
        }
    }
    func_001311A0(self, arg);
    if (self->hit != 0) {
        if (outPos != 0) {
            cVec_copy3(outPos, &self->result);
        }
        if (outInfo != 0) {
            *outInfo = self->hitInfo;
        }
    }
    if (D_00747A2C.flags & GAMESYS_FLAG_COLL_DEBUG) {
        Circle_line2((char *)&self->pos, self->hit ? 0x800000FF : 0x80FF0000, self->radius, 1, 1);
    }
    return self->hit;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001321D8);
#endif
