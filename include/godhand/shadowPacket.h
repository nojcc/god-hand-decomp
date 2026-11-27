/* include/godhand/shadowPacket.h - the GS words of an object's shadow quad.
 *
 * func_0015EC60 fills them from the projected corners; func_0015EEE0 sets
 * a quad that draws nothing. */
#ifndef GODHAND_SHADOWPACKET_H
#define GODHAND_SHADOWPACKET_H

/* A float read as its bit pattern (the Q of RGBAQ). */
typedef union {
    float f;
    unsigned int u;
} FloatBits;

typedef struct ShadowPacket {
    long rgbaq;                         /* 0x00 RGBAQ: colour, alpha, Q */
    char unk08[0x18];
    struct {
        long xyz;                       /* 0x00 XYZ2 of the corner */
        char unk08[0x18];
    } vtx[4];                           /* 0x20 */
} ShadowPacket;

/* p = a quad with all four corners at 0 and Q = 1.0. */
void func_0015EEE0(ShadowPacket *p);

#endif /* GODHAND_SHADOWPACKET_H */
