/* sn-2.95.3-136 */
#include "include_asm.h"
/* NON_MATCHING func_0012DEF0 (437 of 438 words): retail forms each corner's
 * address as (index * 16 + self) + 0x110 and copies it a component at a time,
 * load then store; here the 0x110 is folded into the index first and the three
 * loads come before the stores. The spilled outline pointers also take other
 * slots. Needs the cGrid.h overlay. */
#include "godhand/cGrid.h"
#include "godhand/cVec.h"
#include "godhand/drawPrim.h"

/* Debug draw of a box body, face by face as the quad body's draw does it:
 * each face's outline, and with fill set the face filled too. The colour comes
 * from the face's kind (mode 0), its colour class (mode 1) or whether its
 * attributes have bit mode - 2 (modes 2..31). */

#ifdef NON_MATCHING

__attribute__((section(".text.func_0012DEF0")))
void func_0012DEF0(cCollBody *self, int mode, int fill)
{
    cVec line[5];
    cVec strip[4];
    cVec *p;
    int i;
    int j;
    unsigned int f;
    unsigned short kind;
    unsigned int lineColor;
    unsigned int fillColor;

    for (f = 0; f < 6; f++) {
        p = line;
        i = 4;
        do {
            CVEC_ZERO(*p);
            p++;
        } while (--i != -1);
        CVEC_ASSIGN(line[0], &self->u.box.corner[D_0041D640[f][0]]);
        CVEC_ASSIGN(line[1], &self->u.box.corner[D_0041D640[f][1]]);
        CVEC_ASSIGN(line[2], &self->u.box.corner[D_0041D640[f][2]]);
        CVEC_ASSIGN(line[3], &self->u.box.corner[D_0041D640[f][3]]);
        CVEC_ASSIGN(line[4], &self->u.box.corner[D_0041D640[f][0]]);
        p = strip;
        j = 3;
        do {
            CVEC_ZERO(*p);
            p++;
        } while (--j != -1);
        CVEC_ASSIGN(strip[0], &self->u.box.corner[D_0041D640[f][0]]);
        CVEC_ASSIGN(strip[1], &self->u.box.corner[D_0041D640[f][3]]);
        CVEC_ASSIGN(strip[2], &self->u.box.corner[D_0041D640[f][1]]);
        CVEC_ASSIGN(strip[3], &self->u.box.corner[D_0041D640[f][2]]);

        switch (mode) {
        case 0:
            kind = self->u.box.face[f].kind;
            if (kind & 1) {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x80FF0000, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x20FF0000);
                }
            } else if (kind & 2) {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x20FFFFFF);
                }
            } else if (kind & 4) {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x8000FFFF, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x2000FFFF);
                }
            } else {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x80808080, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x80808080);
                }
            }
            break;
        case 1:
            if (fill == 0) {
                switch (self->u.box.face[f].unk0) {
                case 1: lineColor = 0x8000FFFF; break;
                case 2: lineColor = 0x80FF0000; break;
                case 3: lineColor = 0x80808080; break;
                case 4: lineColor = 0x8000FF00; break;
                case 5: lineColor = 0x80FFFFFF; break;
                case 0: case 6: case 7: case 8: case 9: /* retail's table covers 0..9 */
                default: lineColor = 0x800000FF; break;
                }
                Draw_Line2(line, 5, lineColor, 1);
            } else if (fill == 1) {
                switch (self->u.box.face[f].unk0) {
                case 1: fillColor = 0x2000FFFF; break;
                case 2: fillColor = 0x20FF0000; break;
                case 3: fillColor = 0x20808080; break;
                case 4: fillColor = 0x2000FF00; break;
                case 5: fillColor = 0x20FFFFFF; break;
                case 0: case 6: case 7: case 8: case 9:
                default: fillColor = 0x200000FF; break;
                }
                Draw_Line2(line, 5, 0x80FFFFFF, 1);
                func_001334A8(strip, 1, fillColor);
            }
            break;
        case 2 ... 31: {
            int n = mode - 2;
            cBitMasks bits = D_0041D2E0; /* retail copies the table to the stack before indexing it */

            if (self->u.box.face[f].attr & bits.bit[n]) {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x20FFFFFF);
                }
            } else {
                if (fill == 0) {
                    Draw_Line2(line, 5, 0x800000FF, 1);
                } else if (fill == 1) {
                    Draw_Line2(line, 5, 0x80FFFFFF, 1);
                    func_001334A8(strip, 1, 0x200000FF);
                }
            }
            break;
        }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_0012DEF0);
#endif
