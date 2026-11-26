/* cygnus-2.96 matched TU. */

#include "godhand/sjFeedCtl.h"
#include "godhand/criStm.h"
#include "godhand/ac3Hdr.h"
#include "godhand/globals.h"

/* Copy the whole src block into the out joint, in up to two chunks. Returns 0, or -1 when the joint
 * could not take all of it. */
__attribute__((section(".text.SjFeed_writeAll")))
int SjFeed_writeAll(SjFeedCtl *feed)
{
    SjChunk ck;
    int left = SJFEED_BLOCK;
    int done;

    feed->out->vt->getChunk(feed->out, SJ_LANE_FREE, SJFEED_BLOCK, &ck);
    func_003A5148(ck.data, feed->src, ck.len);
    done = ck.len;
    feed->out->vt->putChunk(feed->out, SJ_LANE_FULL, &ck);
    left -= done;
    if (left > 0) {
        feed->out->vt->getChunk(feed->out, SJ_LANE_FREE, left, &ck);
        func_003A5148(ck.data, feed->src + done, ck.len);
        left -= ck.len;
        feed->out->vt->putChunk(feed->out, SJ_LANE_FULL, &ck);
    }
    if (left != 0) {
        func_003B9DE0(D_00460A70);
        return -1;
    }
    return 0;
}
