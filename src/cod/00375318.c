/* sn-2.95.3-136 */
#include "godhand/sif.h"
#include "godhand/seqNode.h"
#include "godhand/sndBank.h"

void func_00377BC8(void);
void func_00375860(void);

/* Start the sound driver: bind its RPC server, clear the shared buffers, then
 * send the start-up command with the two buffer addresses and command 1. */
__attribute__((section(".text.func_00375318")))
void func_00375318(void)
{
    SndRpc *rpc = &D_0076A880;

    sceSifInitRpc(0);
    func_00377BC8();
    func_00375860();
    rpc->send.init.voiceOut = D_0076A9C0;
    rpc->send.init.ownerCtl = D_0076B1C0;
    func_003758E8(0);
    func_003758E8(1);
}
