/* cygnus-2.96, -freorder-blocks dropped */
#include "include_asm.h"
#include "godhand/ADXStm.h"
#include "godhand/criAix.h"
#include "godhand/globals.h"

extern void Obj3290_Tramp_0033E678_9028(void);
extern void Obj3290_Tramp_0033E690_9040(void);
extern int func_00330BB0(int *fd, int ofst, int whence);
extern int func_00330C18(int *fd, int nsct, Sint8 *buf);
extern int func_00330CF0(int *fd);

/* One step of a stream's read: when the pending read is done, hand its sectors to the SJ
 * (or count the error), then start the next read while the SJ has room. When the stream is
 * already in error and idle, retail returns with the lock still held.
 * Still differs from retail (12 instructions): retail loads the constant 1 into s1 before the
 * unlock and compares unk44 with it, the D_003D1400 block stores the loaded word instead of s1,
 * and the end-of-stream compare takes its operands in the other order. */
#ifdef NON_MATCHING
__attribute__((section(".text.adxstmf_stat_exec")))
void adxstmf_stat_exec(ADXStm *stm)
{
    SjObj *sj = stm->sj;
    int fsstat = func_00330CF0(stm->fd);
    SjChunk ck;
    SjChunk rest;

    Obj3290_Tramp_0033E678_9028();
    if (stm->reading == 1) {
        if (fsstat == 1) {
            int len;
            int nsct;

            stm->reading = 0;
            Obj3290_Tramp_0033E690_9040();
            len = stm->reqsct << ADXSTM_SECTOR_SHIFT;
            SJ_SplitChunk(&stm->ck, len, &ck, &rest);
            sj->vt->putChunk(sj, 1, &ck);
            sj->vt->ungetChunk(sj, 0, &rest);
            stm->cursct += stm->reqsct;
            stm->rdbytes += len;
            stm->ck.data = 0;
            stm->ck.len = 0;
            nsct = stm->nsct;
            if (stm->nsct2 == stm->cursct && stm->eosfn != 0)
                stm->eosfn(stm->eosobj, stm->nsct2);
            if (stm->cursct >= nsct
                || (stm->rdbytes >> ADXSTM_SECTOR_SHIFT >= stm->limit && stm->limit <= ADXSTM_NO_LIMIT - 1))
                stm->stat = ADXSTM_STAT_EOF;
            stm->retry = 0;
        } else if (fsstat == 3) {
            stm->reading = 0;
            Obj3290_Tramp_0033E690_9040();
            sj->vt->ungetChunk(sj, 0, &stm->ck);
            stm->ck.data = 0;
            stm->ck.len = 0;
            if (D_003D04C8 >= 0 && stm->retry >= D_003D04C8)
                stm->stat = ADXSTM_STAT_ERR;
            else if (stm->retry < 0x7FFFFFFF)
                stm->retry++;
        } else {
            Obj3290_Tramp_0033E690_9040();
        }
    }
    if (stm->stat != ADXSTM_STAT_ERR && stm->reading == 0) {
        stm->ck.data = 0;
        stm->reading = 1;
        stm->ck.len = 0;
        Obj3290_Tramp_0033E690_9040();
        if (stm->unk44 == 1) {
            stm->reading = 0;
        } else if (stm->unk48 == 1) {
            stm->reading = 0;
        } else if (stm->nsct == 0) {
            stm->reading = 0;
            stm->reqsct = 0;
            stm->stat = ADXSTM_STAT_EOF;
        } else if (sj == 0 || sj->vt == 0) {
            stm->reading = 0;
            Obj0000_PostInc_D_003D04CC_3284A0();
        } else if (stm->ndata2 - sj->vt->getNumData(sj, 0) >= stm->ndata1) {
            stm->reading = 0;
        } else {
            int n;
            int left;

            sj->vt->getChunk(sj, 0, stm->ndata0, &rest);
            n = rest.len / ADXSTM_SECTOR_SIZE;
            if (n >= stm->nsct2 - stm->cursct)
                n = stm->nsct2 - stm->cursct;
            if (n >= stm->nsct - stm->cursct)
                n = stm->nsct - stm->cursct;
            if (n >= stm->sctsize)
                n = stm->sctsize;
            func_00330BB0(stm->fd, stm->ofst + stm->cursct, 0);
            if (D_003D1400 == 1) {
                D_003D8498 = 1;
                if (stm->unk03 == 1)
                    D_003D849C = 0;
                else
                    D_003D849C = 1;
            }
            if (stm->limit != ADXSTM_NO_LIMIT) {
                left = stm->limit - (int)stm->rdbytes / ADXSTM_SECTOR_SIZE;
                if (n >= left)
                    n = left;
            }
            stm->reqsct = func_00330C18(stm->fd, n, rest.data);
            stm->ck.data = rest.data;
            stm->ck.len = rest.len;
            if (stm->reqsct <= 0) {
                sj->vt->ungetChunk(sj, 0, &stm->ck);
                stm->ck.data = 0;
                stm->ck.len = 0;
                stm->reading = 0;
                if (func_00330CF0(stm->fd) == 3) {
                    if (D_003D04C8 >= 0 && stm->retry >= D_003D04C8)
                        stm->stat = ADXSTM_STAT_ERR;
                    else if (stm->retry < 0x7FFFFFFF)
                        stm->retry++;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatching", adxstmf_stat_exec);
#endif
