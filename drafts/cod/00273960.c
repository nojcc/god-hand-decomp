/* NON_MATCHING func_00273960 (sn-2.95.3-136): same instructions as retail apart from register choice;
 * retail keeps self in s0 and &from in s2, here they are swapped (20 instructions differ). */
#include "include_asm.h"
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
#define RAY_HEIGHT      0.5f
#define RAY_MARGIN      0.5f
#define EMFLAG2_BLOCKED 0x800
#define EM_GOTO_STATE   0xE

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void MtxInitRotY(void *a0, float angle);
extern void cEm00_setGoto(cEm00 *self, cVec *pos, int a2, int a3, float f);

/* Cast three rays from the player at half height in its heading frame (ahead, ahead-right, ahead-left,
 * reach + 0.5 long); if any is blocked, flag it and send the enemy towards the end of that ray. */
__attribute__((section(".text.func_00273960")))
int func_00273960(cEm00 *self, float reach)
{
    float m[16];
    cVec from;
    cVec to;
    float len;

    VU0_SQC2_VF0_MEM(&from, 0);
    VU0_SQC2_VF0_MEM(&to, 0);
    MtxInitRotY(m, Getplayer()->rot[1]);
    from.x = 0;
    from.y = RAY_HEIGHT;
    from.z = 0;
    cVec_applyMatrix(&from, m);
    VU0_VADD_XYZ_IP(&from, 0, Getplayer()->pos);
    len = reach + RAY_MARGIN;
    to.x = 0;
    to.y = RAY_HEIGHT;
    to.z = len;
    cVec_applyMatrix(&to, m);
    VU0_VADD_XYZ_IP(&to, 0, Getplayer()->pos);
    if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
        from.x = 0;
        from.y = RAY_HEIGHT;
        from.z = 0;
        cVec_applyMatrix(&from, m);
        VU0_VADD_XYZ_IP(&from, 0, Getplayer()->pos);
        to.x = len;
        to.y = RAY_HEIGHT;
        to.z = len;
        cVec_applyMatrix(&to, m);
        VU0_VADD_XYZ_IP(&to, 0, Getplayer()->pos);
        if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
            from.x = 0;
            from.y = RAY_HEIGHT;
            from.z = 0;
            cVec_applyMatrix(&from, m);
            VU0_VADD_XYZ_IP(&from, 0, Getplayer()->pos);
            to.x = -reach - RAY_MARGIN;
            to.y = RAY_HEIGHT;
            to.z = len;
            cVec_applyMatrix(&to, m);
            VU0_VADD_XYZ_IP(&to, 0, Getplayer()->pos);
            if (ChkLine(&from, &to, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
                return 0;
            }
        }
    }
    self->emFlags2 |= EMFLAG2_BLOCKED;
    self->unk16E0 = 0;
    cEm00_setGoto(self, &to, EM_GOTO_STATE, 1, 120.0f);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00273960);
#endif
