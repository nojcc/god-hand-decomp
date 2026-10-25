/* sn-2.95.3-136. Differs from retail in two places: retail branches for the
 * last step of the leading-digit ladder (count 2 or 1) where ours folds it
 * into a movn, and it reloads the minus flag into $v0 where ours uses $v1. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cScrSpriteDraw.h"

/* Draw value as up to digits decimal digits of the digit sheet, w wide and
 * gap apart, placed at (x, y) by anchor. Leading zeros are drawn only with
 * fill; a negative value gets a minus sign in front. */
__attribute__((section(".text.func_002C70A8")))
void func_002C70A8(cScrSpriteDraw *self, unsigned int digits, int value,
                   float x, float y, float w, float h, float gap,
                   unsigned int color, int fill, unsigned int anchor, short texNo, unsigned short slot)
{
    int max, neg;
    char d100m, d10m, d1m, d100k, d10k, d1k, d100, d10, d1;
    unsigned int n, i, count;
    float x0, y0;
    unsigned char pos;

    if (digits != 0) {
        n = digits < 10 ? digits : 9;
    } else {
        n = 1;
    }
    max = 1;
    for (i = 0; i < n; i++) {
        max *= 10;
    }
    if (value >= max) {
        value = max - 1;
    }
    neg = 0;
    if (value < 0) {
        neg = 1;
        value = -value;
    }
    count = 0;
    if (value >= 0) {
        d100m = value / 100000000;
        d10m = value % 100000000 / 10000000;
        d1m = value % 10000000 / 1000000;
        d100k = value % 1000000 / 100000;
        d10k = value % 100000 / 10000;
        d1k = value % 10000 / 1000;
        d100 = value % 1000 / 100;
        d10 = value % 100 / 10;
        d1 = value % 10;
        if (!fill) {
            if (d100m) {
                count = 9;
            } else if (d10m) {
                count = 8;
            } else if (d1m) {
                count = 7;
            } else if (d100k) {
                count = 6;
            } else if (d10k) {
                count = 5;
            } else if (d1k) {
                count = 4;
            } else if (d100) {
                count = 3;
            } else if (d10) {
                count = 2;
            } else {
                count = 1;
            }
        } else {
            count = n;
        }
    } else {
        /* Only INT_MIN gets here (-value overflows): every digit takes its low byte. */
        d10m = value;
        d100m = d10m;
        d1m = d10m;
        d100k = d10m;
        d10k = d10m;
        d1k = d10m;
        d100 = d10m;
        d10 = d10m;
        d1 = d10m;
    }

    x0 = x;
    y0 = y;
    switch (anchor) {
    case 0:
        x0 = x - w * ((float)count * 0.5f - 0.5f);
        y0 = y;
        break;
    case 4:
        x0 = x - (w + gap) * ((float)count - 0.5f);
        y0 = y - h * 0.5f;
        break;
    case 2:
        x0 = x - (w + gap) * ((float)count - 0.5f);
        y0 = y + h * 0.5f;
        break;
    case 3:
        x0 = x + w * 0.5f;
        y0 = y - h * 0.5f;
        break;
    case 1:
        x0 = x + w * 0.5f;
        y0 = y + h * 0.5f;
        break;
    }

    pos = 0;
    if (neg) {
        func_002C6D48(self, -1, x0 + (w + gap) * -1.0f, y0, w, h, color, texNo, slot);
    }
    switch (count) {
    case 9:
        if (value >= 100000000 || fill) {
            func_002C6D48(self, d100m, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 8:
        if (value >= 10000000 || fill) {
            func_002C6D48(self, d10m, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 7:
        if (value >= 1000000 || fill) {
            func_002C6D48(self, d1m, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 6:
        if (value >= 100000 || fill) {
            func_002C6D48(self, d100k, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 5:
        if (value >= 10000 || fill) {
            func_002C6D48(self, d10k, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 4:
        if (value >= 1000 || fill) {
            func_002C6D48(self, d1k, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 3:
        if (value >= 100 || fill) {
            func_002C6D48(self, d100, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 2:
        if (value >= 10 || fill) {
            func_002C6D48(self, d10, x0 + (w + gap) * (float)pos++, y0, w, h, color, texNo, slot);
        }
    case 1:
        func_002C6D48(self, d1, x0 + (w + gap) * (float)pos, y0, w, h, color, texNo, slot);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_002C70A8);
#endif
