/* sn-2.95.3-136 */
/* cMessDrawFont_draw: everything matches except one spot. When the glyph height differs from the
 * line height, retail stores the pen y before it loads D_00747A0C (hi part in v0, value in v1);
 * this build schedules the load's hi part first and swaps the two registers. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cMessDrawFont.h"
#include "godhand/cFont.h"

extern void cMessDrawFont_measurePage(cMessDrawFont *self, unsigned short *text, float *maxW, float *sumH);
extern unsigned short *cMessDrawFont_measureLineHeight(cMessDrawFont *self, unsigned short *text, float *arg, float *out);
extern unsigned short *cMessDrawFont_measureText(cMessDrawFont *self, unsigned short *text, void *arg, float *width, float *height);
extern void cMessDrawFont_execCommand(cMessDrawFont *self, void *cmd);
extern float cMessDrawFont_measureCode(cMessDrawFont *self, unsigned short *text, float *arg);
extern int cMessDrawFont_isListedCode(void *unused, unsigned short *code);
extern void func_002B0480(void *a0, void *a1);
extern int func_002B04C0(void *a0, void *a1, void *a2);
extern int func_002AFC08(void *a0, int a1);
extern int func_002B12A0(unsigned short *p);
extern int func_002AF218(unsigned short *text);
extern int cMessCommon_isHighCodeEnd(unsigned short code);
extern int cMessCommon_getCodeSize(unsigned int code);
extern void func_002A4FA0(char *base);
extern void func_002A52E8(int a0, unsigned int col);
extern void func_002A58A0(char *p, int value);
extern void func_002A58D8(char *a0, unsigned int v);
extern void BuildGifPacket_2A5930(int a0);
extern int D_00747A0C;

/* Draws the current page of the message: lays it out (centred on the anchor when asked), sets up
 * the font, then walks the codes up to the draw limit, running commands, breaking lines and
 * advancing the pen. Returns the laid out size through outW and outH when they are not null. */
__attribute__((section(".text.cMessDrawFont_draw")))
void cMessDrawFont_draw(cMessDrawFont *self, float *outW, float *outH)
{
    cMessDrawFrame frame;
    cMessDrawFrame line;
    float lineH;
    float top;
    float y;
    float adv;
    float h;
    int newLine;
    int shifted;

    cMessDrawFont_measurePage(self, self->bodyStart, &self->sizeW, &self->sizeH);
    if (self->alignFlags & 1) {
        self->unk80 = self->posX - self->sizeW * 0.5f;
    } else {
        self->unk80 = self->posX;
    }
    self->cursor = self->bodyStart;
    self->rubyCursor = (self->flags & 1) ? self->rubyStart : 0;
    self->charNum = self->drawCount;
    top = self->posY;
    if (self->alignFlags & 2) {
        top -= self->sizeH * 0.5f;
    }
    self->unk84 = top;
    self->unk88 = self->unk80;
    self->unk8C = top;
    newLine = 1;
    func_002B0480(self, &frame);
    shifted = 0;
    cFont_setDrawState(D_003C2380, 0x80808080, 0x21, 6, 0xFFFFFFFF, 1.0f, 1.0f, 1.0f);
    func_002A4FA0((char *)D_003C2380);
    CFONT_STATE_RAW(D_003C2380, int, unk20) = 9;
    CFONT_STATE_RAW(D_003C2380, float, glyphW) = frame.scale * self->charW * self->zoomX;
    CFONT_STATE_RAW(D_003C2380, float, glyphH) = frame.scale * self->charH * self->zoomY;
    func_002A52E8((int)D_003C2380, frame.colour);
    func_002A58A0((char *)D_003C2380, self->unk58);
    func_002A58D8((char *)D_003C2380, self->unk5C);
    cMessDrawFont_measureLineHeight(self, self->cursor, &frame.scale, &lineH);
    y = self->unk8C;
    while (self->charNum <= self->drawLimit
           && (self->bodyEnd == 0 || (unsigned short *)self->bodyEnd >= self->cursor)
           && (*self->cursor & 0xFF00) != 0x8000) {
        if (newLine) {
            line = frame;
            cMessDrawFont_measureText(self, self->cursor, &line, &self->unk78, &self->unk7C);
            cMessDrawFont_measureLineHeight(self, self->cursor, &frame.scale, &lineH);
            newLine = 0;
        }
        if (*self->cursor >> 15) {
            if (func_002B04C0(self, self->cursor, &frame) == 0) {
                cMessDrawFont_execCommand(self, &frame);
            }
            if (cMessCommon_isHighCodeEnd(*self->cursor)) {
                newLine = 1;
                self->unk88 = self->unk80;
                self->unk8C = y + self->unk7C + self->unk2C[1] * self->zoomY;
                y = self->unk8C;
            }
        } else {
            h = frame.scale * self->charH * self->zoomY;
            if (h != lineH) {
                self->unk8C = y;
                if (D_00747A0C == 0) {
                    self->unk8C = y + (lineH * 26.0f - h * 26.0f);
                } else {
                    self->unk8C = y + (lineH * 32.0f - h * 32.0f);
                }
                shifted = 1;
            } else if (shifted == 1) {
                self->unk8C = y;
                shifted = 0;
            }
            self->rubyCursor = (char *)func_002AFC08(self, (int)&frame);
        }
        adv = cMessDrawFont_measureCode(self, self->cursor, &frame.scale);
        if (adv != 0.0f) {
            if (func_002B12A0(self->cursor) == 0) {
                if ((self->flags >> 2) & 1) {
                    if (cMessDrawFont_isListedCode(self, self->cursor)) {
                        self->unk88 += frame.scale * self->charW * self->zoomX * 16.0f;
                    } else if (D_00747A0C == 0) {
                        self->unk88 += frame.scale * self->charW * self->zoomX * 26.0f;
                    } else {
                        self->unk88 += frame.scale * self->charW * self->zoomX * 32.0f;
                    }
                } else {
                    self->unk88 += adv + self->unk2C[0] * self->zoomX;
                }
            } else if (D_00747A0C == 0) {
                self->unk88 += frame.scale * self->charH * self->zoomY * 26.0f;
            } else {
                self->unk88 += frame.scale * self->charH * self->zoomY * 32.0f;
            }
        }
        self->charNum += func_002AF218(self->cursor);
        self->cursor += cMessCommon_getCodeSize(*self->cursor);
    }
    BuildGifPacket_2A5930((int)D_003C2380);
    if (outW != 0) {
        *outW = self->sizeW;
    }
    if (outH != 0) {
        *outH = self->sizeH;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", cMessDrawFont_draw);
#endif
