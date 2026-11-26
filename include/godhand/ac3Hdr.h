/* include/godhand/ac3Hdr.h - the AC-3 frame header constants and lookup tables (CRI libsfd, 0x3BA3D8..).
 *
 * The parser accepts a frame in either byte order (0B 77 or 77 0B), then
 * reads the sample-rate code (top two bits) and the frame-size code (low six
 * bits) of the next byte, and stores what it finds in the feed (SjFeedCtl).
 */
#ifndef GODHAND_AC3HDR_H
#define GODHAND_AC3HDR_H

#define AC3_SYNC_HI        0x0B
#define AC3_SYNC_LO        0x77
#define AC3_FSCOD_NUM      3       /* valid sample-rate codes */
#define AC3_FRMSIZ_NUM     0x26    /* valid frame-size codes */
#define AC3_FRMSIZ_STRIDE  40      /* table row length, in words */

extern int D_003FC518[AC3_FSCOD_NUM];
extern int D_003FC528[AC3_FRMSIZ_NUM];
extern int D_003FC5C8[];
extern char D_00460978[];
extern char D_004609A8[];
extern char D_004609D8[];
extern void func_003B9DE0(const char *msg);

#endif
