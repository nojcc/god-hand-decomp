/* sn-2.95.3-136 */
/* func_00376438: 48 of 52 words, 42 differ. Retail jumps into the wait test
 * from the entry and repeats the test, with its decrement, after a command
 * loads (testing the loaded wait in a register); this C reaches the same block
 * order but falls back into the one test and reloads the wait. */
#include "include_asm.h"

typedef struct SndScriptCmd {
    int wait;                           /* 0x00 frames before the next command */
    signed char sel;                    /* 0x04 argument block */
    signed char op;                     /* 0x05 handler */
    char unk06[0x10 - 0x06];
} SndScriptCmd;

typedef struct SndScriptArg {
    char unk00[0x14];
} SndScriptArg;

typedef struct SndScript {
    unsigned short flags;               /* 0x00 */
    char unk02[0x30 - 0x02];
    SndScriptCmd *pc;                   /* 0x30 */
    SndScriptCmd *start;                /* 0x34 */
    int wait;                           /* 0x38 */
    signed char sel;                    /* 0x3C */
    signed char op;                     /* 0x3D */
    char unk3E[2];
    SndScriptArg arg[1];                /* 0x40 */
} SndScript;

#define SNDSCRIPT_END 0x1000

extern int (*D_003F2188[])(SndScript *s, SndScriptArg *arg);

/* Step the script one frame: count down the current wait, and once it runs
 * out run commands until one asks to wait or the script ends. A handler that
 * returns 0 moves on to the next command; nonzero reloads the current one. */
#ifdef NON_MATCHING
__attribute__((section(".text.func_00376438")))
void func_00376438(SndScript *s)
{
    int next;

    for (;;) {
        if (s->wait != 0) {
            s->wait--;
            break;
        }
        next = D_003F2188[s->op](s, &s->arg[s->sel]);
        if (s->flags & SNDSCRIPT_END) {
            break;
        }
        if (next == 0) {
            s->pc++;
        }
        s->wait = s->pc->wait;
        s->sel = s->pc->sel;
        s->op = s->pc->op;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00376438);
#endif
