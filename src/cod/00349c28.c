/* cygnus-2.96 */
#include "godhand/mwsfd.h"

extern float func_003A1DF0(float x);

/* Set the movie's audio volume: 1000 is full volume, anything else becomes decibels (whole and hundredths) relative to it. */
__attribute__((section(".text.func_00349C28")))
void func_00349C28(SfdHn *hn, int vol)
{
    void *adxt;
    float db;
    int whole;
    int frac;

    adxt = *hn->adxt;
    if (adxt == 0) {
        return;
    }
    if (vol == 1000) {
        whole = 0;
        frac = 0;
    } else {
        db = (func_003A1DF0(vol) - 6.907755f) * 1731.2341f;
        whole = db * 0.01f;
        frac = (int)db - whole * 100;
    }
    func_0032B488(adxt, whole, frac);
}
