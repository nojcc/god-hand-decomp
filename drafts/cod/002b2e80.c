/* NON_MATCHING func_002B2E80 (sn-2.95.3-136): one word short. Retail reads owner (0x18)
 * once more after the voice swap and drops the value; nothing here reads it. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cSnd.h"
#include "godhand/cIDManager.h"

#define VOICE_NONE  0xFFFF

/* A script channel run, as func_002B2580 and its restart see it. */
typedef struct ScriptVoiceRun {
    char unk00[0x18];
    char *owner;                        /* 0x18 object the channel speaks for, 0 = none */
    void *voice;                        /* 0x1C voice data of the owner */
    int voiceSlot;                      /* 0x20 se slot reserved for voice */
    char unk24[0xC];
    unsigned char runs;                 /* 0x30 times the channel restarted */
    char unk31[0x4B];
    void *loopCmd;                      /* 0x7C command the loop goes back to */
    char unk80[4];
    int loopTime;                       /* 0x84 */
    unsigned short wait;                /* 0x88 */
    char unk8A[2];
    void *cmd;                          /* 0x8C */
    int cmdTime;                        /* 0x90 */
} ScriptVoiceRun;

extern cSnd D_005FEE00;
extern char D_0044B1E0[];
extern int cSndSeVoice_CheckEnd(cSnd *self, int idx);
extern int cSnd_ReserveSeSlot(cSnd *self, int id);

/* Restart the channel: look the owner's voice up again and swap the
 * reserved se slot when it changed, then rewind to the current command. */
__attribute__((section(".text.func_002B2E80")))
void func_002B2E80(ScriptVoiceRun *self)
{
    void *voice;

    if (self->owner == 0) {
        voice = 0;
    } else {
        voice = SearchData(*(void **)(self->owner + 0x304), D_0044B1E0, 0);
    }
    if (voice != self->voice) {
        if (self->voice != 0) {
            cSndSeVoice_CheckEnd(&D_005FEE00, self->voiceSlot);
        }
        if (voice != 0) {
            self->voiceSlot = cSnd_ReserveSeSlot(&D_005FEE00, (int)voice);
        }
        self->voice = voice;
    }
    self->wait = VOICE_NONE;
    self->runs++;
    self->loopTime = self->cmdTime;
    self->loopCmd = self->cmd;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002B2E80);
#endif
