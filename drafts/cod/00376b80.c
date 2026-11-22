/* NON_MATCHING func_00376B80 (sn-2.95.3-136): 92 words vs 94, every
 * register differs. Retail loads 0x17 (the code stored after
 * SdeSsqVexeComParaSet) into a saved register before the call, beside -1, so it
 * saves six registers; this C loads 0x17 after the call. SndMsg.h's
 * prototypes also disagree with the definitions (func_0037D170 returns a
 * char * slot of a 0x50-byte pool; SdeSsqVexeComParaSet takes void *). */
#include "include_asm.h"
#ifdef NON_MATCHING
#include "godhand/sndBank.h"
#include "godhand/SndMsg.h"

/* Queue a hit message for src: a node built from src, the request and the
 * request's row of src's bank sound table, unless that row is switched off. */
__attribute__((section(".text.func_00376B80")))
void func_00376B80(SndMsgSrc *src, SndMsgReq *req)
{
    SndMsgRow *row;
    SndMsgNode *node;

    row = (SndMsgRow *)D_0076EA50[src->bank].data + req->row;
    if (row->flags & SNDMSG_ROW_OFF) {
        return;
    }
    node = func_0037D170();
    if (node == 0) {
        return;
    }
    node->kind = SNDMSG_KIND_HIT;
    node->handle = req->handle;
    node->srcHandle = src->handle;
    node->mode = 4;
    node->prio = src->prio;
    node->ofsA = -1;
    node->ofsB = 0;
    node->srcId = src->id;
    node->reqBias = req->bias;
    SdeSsqVexeComParaSet(src, node);
    node->volL = req->volL;
    node->row = req->row;
    node->base = row->base;
    node->level = 0x7F;
    node->unk27 = 0;
    node->vol = src->vol + (unsigned char)req->bias;
    node->unk29 = 0;
    node->unk2A = 0;
    node->code = 0x17;
    node->pitch = src->pitch;
    node->vara = req->vara;
    node->varaCopy = req->vara;
    node->unk36 = 0;
    node->varb = req->varb;
    node->lo = row->lo;
    node->hi = row->hi;
    node->tail = -1;
    node->varc = req->varc;
    node->z41 = 0;
    node->z40 = 0;
    node->z43 = 0;
    node->z42 = 0;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00376B80);
#endif
