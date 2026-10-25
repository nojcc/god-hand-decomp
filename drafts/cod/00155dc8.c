/* sn-2.95.3-136 */
/* Differs from retail: retail loads every start and end address afresh, so each
 * blob had its own end symbol at the address where the next blob starts (one entry
 * is an empty blob, start == end at 0x3FD280); with one symbol per address the
 * compiler keeps the shared addresses in saved registers and folds the empty entry. */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/criStm.h"
#include "godhand/mdlPkt.h"

extern char D_003FD280[];
extern char D_003FD440[];
extern char D_003FD800[];
extern char D_003FDD40[];
extern char D_003FDD50[];
extern char D_003FF910[];
extern char D_004000C0[];
extern char D_004000D0[];
extern char D_004007E0[];
extern char D_004007F0[];
extern char D_00401580[];
extern char D_00402760[];
extern char D_00402770[];
extern char D_00403BA0[];
extern char D_00403BB0[];
extern char D_00403F40[];
extern char D_00403F50[];
extern char D_00405220[];
extern char D_00406480[];
extern char D_00406490[];
extern char D_00407690[];
extern char D_004076A0[];
extern char D_004088B0[];
extern char D_004088C0[];
extern char D_00409D40[];
extern char D_00409D50[];
extern char D_0040A0C0[];
extern char D_0040A3D0[];
extern char D_0040A3E0[];

/* An entry for the packet data from start up to end, its size in quadwords. */
#define PKT_ENT_SET(e, start, end) \
    ((e)->w0 = (unsigned int)(start), (e)->w1 = ((end) - (start)) >> 4)

/* Fills the model packet table D_004A5D80 with the prebuilt packet blobs; only
 * the full reset (mask 0xFFFF with a nonzero id) does anything. */
__attribute__((section(".text.func_00155DC8")))
void func_00155DC8(int id, int mask)
{
    GifTagEnt *e;

    if (mask != 0xFFFF || id == 0) {
        return;
    }
    e = D_004A5D80;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_003FD800, D_003FDD40);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_003FDD40, D_003FDD50);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00401580, D_00402760);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00402760, D_00402770);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00406490, D_00407690);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00407690, D_004076A0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00403BB0, D_00403F40);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00403F40, D_00403F50);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00402770, D_00403BA0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00403BA0, D_00403BB0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_0040A0C0, D_0040A3D0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_0040A3D0, D_0040A3E0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004076A0, D_004088B0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004088B0, D_004088C0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_003FD280, D_003FD280);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_003FD280, D_003FD440);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00405220, D_00406480);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00406480, D_00406490);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004000D0, D_004007E0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004007E0, D_004007F0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_003FF910, D_004000C0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004000C0, D_004000D0);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_004088C0, D_00409D40);
    e++;
    func_003A52F0(e, 0, sizeof *e);
    PKT_ENT_SET(e, D_00409D40, D_00409D50);
}
#else
INCLUDE_ASM("asm/nonmatching", func_00155DC8);
#endif
