/* include/godhand/libpad.h - the EE pad library: per-port state, DMA frames and the RPC buffer (0x397BC8-0x3984xx). */
#ifndef GODHAND_LIBPAD_H
#define GODHAND_LIBPAD_H

/* One of a pad's two DMA frames (0x80 bytes); the IOP fills them alternately, the larger frame count is current. */
typedef struct PadData {
    unsigned char data[0x50];           /* 0x00 button data and actuator settings */
    unsigned short modeTable[4];        /* 0x50 */
    int frame;                          /* 0x58 */
    int unk5C;
    int length;                         /* 0x60 bytes of button data */
    unsigned char modeConfig;           /* 0x64 */
    unsigned char modeCurId;            /* 0x65 */
    unsigned char model;                /* 0x66 */
    unsigned char unk67;
    unsigned char nrOfModes;            /* 0x68 */
    unsigned char modeCurOffs;          /* 0x69 */
    unsigned char unk6A[6];
    unsigned char state;                /* 0x70 */
    unsigned char reqState;             /* 0x71 */
    unsigned char ok;                   /* 0x72 */
    unsigned char unk73[0xD];
} PadData;

/* A slot's command block (0x20 bytes), sent to one of two IOP buffers chosen by count's low bit. */
typedef struct PadCmd {
    int count;                          /* 0x00 */
    int unk04;
    int len;                            /* 0x08 bytes in data */
    unsigned char data[0x14];           /* 0x0C */
} PadCmd;

/* One port and slot's state (0x1C bytes; D_0077C110[port][slot]). */
typedef struct {
    PadData *buf;                       /* 0x00 the two DMA frames */
    PadCmd *cmd;                        /* 0x04 */
    unsigned int iopCmd;                /* 0x08 IOP address of the two command buffers */
    int dmaid;                          /* 0x0C last command DMA */
    int open;                           /* 0x10 */
    int unk14;
    int unk18;
} PadInfoT;

/* The RPC buffer (D_0077C300, 128 bytes): command, port, slot, then arguments and results. */
typedef struct {
    int cmd;
    int port;
    int slot;
    int a;
    int b;
    int c;
    int rest[26];
} PadSif;

extern PadInfoT D_0077C110[2][4];
extern PadSif D_0077C300;
extern char D_0077C0C0[];               /* the pad RPC client */

/* Copy the current DMA frame into buf (if not null); returns the current frame. */
PadData *func_00397BC8(int port, int slot, PadData *buf);
/* Set the frame's requested state. */
int func_00397E18(int port, int slot, int state);
/* Send the slot's command block to the IOP. */
int func_003978C8(int port, int slot);
int scePadSetButtonInfo(int port, int slot, int mask);

#endif
