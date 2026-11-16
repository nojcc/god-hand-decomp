/* include/godhand/sndVoiceNode.h - the sound voice node record, the base of
 * seqNode.h's voice nodes and cSnd.h's BGM node. */
#ifndef GODHAND_SNDVOICENODE_H
#define GODHAND_SNDVOICENODE_H

/* A sound voice node: its work and the method table it dispatches through. */
typedef struct SndVoiceNode {
    char unk00[0x5E];
    unsigned char started;      /* 0x5E */
    unsigned char unk5F;        /* 0x5F */
    unsigned char started60;    /* 0x60 */
    unsigned char unk61;        /* 0x61 */
    char unk62[0x1E];
    struct cVtEnt *vt;          /* 0x80 */
} SndVoiceNode;                 /* 0x84 */

#endif
