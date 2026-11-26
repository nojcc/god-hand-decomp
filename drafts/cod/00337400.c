/* cygnus-2.96, -freorder-blocks dropped. NON_MATCHING ps2rna_sndcbf: 206 words vs retail 202
 * (16 differing mnemonics): retail keeps 128 in one register per channel and the
 * buffer pointer in s1; this reloads 128 before four of the checks. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/adxHdr.h"

/* One IOP playback channel's EE side (0x64 bytes); each setting keeps the
 * value last sent to the IOP next to it. */
typedef struct {
    Sint8 used;
    Sint8 rsv[0x1F];
    void *iopid;           /* 0x20 */
    Sint32 rsv24[3];
    Sint32 sfreq;           /* 0x30 */
    Sint32 sfreq_old;       /* 0x34 */
    Sint32 outvol;          /* 0x38: 0.1 dB, 0 down to -999 */
    Sint32 outvol_old;      /* 0x3C */
    Sint32 outpan[2];       /* 0x40 */
    Sint32 outpan_old[2];   /* 0x48 */
    Sint8 playsw;           /* 0x50 */
    Sint8 playsw_old;       /* 0x51 */
    Sint8 nch;              /* 0x52 */
    Sint8 nch_old;          /* 0x53 */
    Sint8 bitrev;           /* 0x54 */
    Sint8 bitrev_old;       /* 0x55 */
    Sint8 mute;             /* 0x56 */
    Sint8 mute_old;         /* 0x57 */
    Sint8 rsv58[2];
    Sint8 stat_old;         /* 0x5A */
    Sint8 stat;             /* 0x5B */
    Sint32 tbl;             /* 0x5C */
    Sint32 tbl_old;         /* 0x60 */
} Ps2RnaIop;

/* One command for the IOP. */
typedef struct {
    Sint16 cmd;
    Sint16 rsv;
    void *iopid;
    Sint32 arg1;
    Sint32 arg2;
} Ps2RnaCmd;

typedef struct {
    Sint32 ncmd;
    Sint32 rsv[3];
    Ps2RnaCmd cmd[128];
} Ps2RnaCmdBuf;

extern Ps2RnaIop D_003E2B68[16];
extern Sint32 D_003DF768[]; /* output volume (0.1 dB down) to IOP level */

/* Fills buf with a command for each setting of the 16 channels that changed
 * since the last call, at most 128, and marks the settings as sent. Play off
 * goes out before the other settings and play on after them. arg is not
 * read. */
__attribute__((section(".text.ps2rna_sndcbf")))
void ps2rna_sndcbf(Sint32 arg, Ps2RnaCmdBuf *buf)
{
    Ps2RnaIop *rna;
    Sint32 n;
    Sint32 i;
    Sint32 ch;
    Ps2RnaCmd *top;
    Ps2RnaCmd *cmd;

    rna = D_003E2B68;
    n = 0;
    top = buf->cmd;
    cmd = top;
    for (i = 0; i < 16; i++, rna++) {
        if (rna->used != 1)
            continue;
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->stat != rna->stat_old) {
            cmd->cmd = 8;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->stat;
            n++;
            cmd++;
            rna->stat_old = rna->stat;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->playsw == 0 && rna->playsw_old == 1) {
            cmd->cmd = 2;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->playsw;
            n++;
            cmd++;
            rna->playsw_old = rna->playsw;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->bitrev != rna->bitrev_old) {
            cmd->cmd = 10;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->bitrev;
            n++;
            cmd++;
            rna->bitrev_old = rna->bitrev;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->mute != rna->mute_old) {
            cmd->cmd = 12;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->mute;
            n++;
            cmd++;
            rna->mute_old = rna->mute;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->nch != rna->nch_old) {
            cmd->cmd = 3;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->nch;
            n++;
            cmd++;
            rna->nch_old = rna->nch;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->sfreq != rna->sfreq_old) {
            cmd->cmd = 4;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->sfreq;
            n++;
            cmd++;
            rna->sfreq_old = rna->sfreq;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->outvol != rna->outvol_old) {
            cmd->cmd = 5;
            cmd->iopid = rna->iopid;
            cmd->arg2 = D_003DF768[-rna->outvol];
            cmd->arg1 = 0;
            n++;
            cmd++;
            rna->outvol_old = rna->outvol;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (n == 127)
        {
            buf->ncmd = n;
            return;
        }
        for (ch = 0; ch < rna->nch; ch++) {
            if (rna->outpan[ch] != rna->outpan_old[ch]) {
                top[n].cmd = 9;
                top[n].iopid = rna->iopid;
                top[n].arg1 = ch;
                top[n].arg2 = rna->outpan[ch];
                n++;
            cmd++;
                rna->outpan_old[ch] = rna->outpan[ch];
            }
        }
        if (rna->tbl != rna->tbl_old) {
            cmd->cmd = 13;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->tbl;
            n++;
            cmd++;
            rna->tbl_old = rna->tbl;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
        if (rna->playsw == 1 && rna->playsw_old == 0) {
            cmd->cmd = 2;
            cmd->iopid = rna->iopid;
            cmd->arg1 = rna->playsw;
            n++;
            cmd++;
            rna->playsw_old = rna->playsw;
        }
        if (n == 128)
        {
            buf->ncmd = n;
            return;
        }
    }
    buf->ncmd = n;
}
#else
INCLUDE_ASM("asm/nonmatching", ps2rna_sndcbf);
#endif
