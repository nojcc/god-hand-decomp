/* cygnus-2.96 matched TU. */
#include "godhand/sjFeedCtl.h"
#include "godhand/criStm.h"
#include "godhand/ac3Hdr.h"
#include "godhand/globals.h"

/* Copy `step` bytes from the in joint into src after its IEC header, in up to two chunks, and clear
 * the rest of src. Returns 0, or -1 when the joint could not give all of them. */
__attribute__((section(".text.func_003BA5A0")))
int func_003BA5A0(SjFeedCtl *feed)
{
    SjChunk ck;
    int left = feed->step;
    int pos = SJFEED_IEC_HDR_LEN;
    int rest;

    feed->in->vt->getChunk(feed->in, SJ_LANE_FULL, left, &ck);
    func_003A5148(feed->src + pos, ck.data, ck.len);
    left -= ck.len;
    pos += ck.len;
    feed->in->vt->putChunk(feed->in, SJ_LANE_FREE, &ck);
    if (left > 0) {
        feed->in->vt->getChunk(feed->in, SJ_LANE_FULL, left, &ck);
        func_003A5148(feed->src + pos, ck.data, ck.len);
        left -= ck.len;
        pos += ck.len;
        feed->in->vt->putChunk(feed->in, SJ_LANE_FREE, &ck);
    }
    if (left != 0) {
        func_003B9DE0(D_00460A38);
        return -1;
    }
    rest = feed->srcLen - pos;
    func_003A52F0(feed->src + pos, 0, rest);
    return 0;
}
