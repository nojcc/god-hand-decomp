/* NON_MATCHING func_00277348 (sn-2.95.3-136): enemy init, same shape as func_0027DE60.
* Retail keeps the
 * constant 1 for the 0x2F5 and 0x548/0x54A stores in $s0 across the calls (0x70 frame, extra $s3) but still loads a fresh 1
 * for the 1 < n compare; a shared local gets CSE'd into the compare and literals are not hoisted. */
#include "include_asm.h"
#include "godhand/cModel.h"

#ifdef NON_MATCHING
extern int func_00277F80(char *a0);
extern void func_0028EBF0(char *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, void *a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a0, void *a1, int a2, float f);
extern void cCollisionSolidManage_CreateSphere(void *a0, void *a1, void *a2, void *a3, float f);

extern int D_00462FC0;
extern char D_00574380[];
struct sph { int a; float b; int c; float d; };

__attribute__((section(".text.func_00277348")))
int func_00277348(char *a0, char *info, int arg)
{
    char buf[0x20];
    char *s1 = a0;
    int v0;
    int n;
    int base;
    struct sph *q;

    *(int *)(s1 + 0x564) = *(int *)(info + 0x28);
    if (func_00277F80(s1, info) == 0) {
        return 0;
    }
    func_0028EBF0(s1, info, arg);
    v0 = *(int *)(s1 + 0x304);
    *(unsigned char *)(s1 + 0x2F4) = 0;
    *(unsigned char *)(s1 + 0x2F5) = 1;
    *(unsigned char *)(s1 + 0x2F6) = 0;
    *(unsigned char *)(s1 + 0x2F7) = 0;
    func_002A8578(s1, *(int *)(v0 + 0x54) + v0, *(int *)(v0 + 0x58) + v0, 0.0f, 0, 0, 0);
    moveMotion(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    cParts_setRotationOrder(s1, 4);
    *(short *)(s1 + 0x54A) = *(short *)(s1 + 0x548) = 1;
    *(int *)(s1 + 0x670) = 0;
    if (*(int *)(s1 + 0x564) != 0x230) {
        struct sph *r;
        *(int *)(s1 + 0x670) = cDamageManage_CreateDamageTake(&D_00574380, s1, 1);
        n = *(unsigned char *)(s1 + 0x2B4);
        *(int *)(buf + 0x0) = n;
        {
            if (1 < n) {
                base = *(int *)(*(int *)(s1 + 0x278) + 4);
            } else {
                base = 0;
            }
        }
        r = (struct sph *)(buf + 0x10);
        *(int *)(buf + 0x10) = 0;
        *(int *)(buf + 0x14) = 0;
        *(int *)(buf + 0x18) = 0;
        r->d = 1.0f;
        *(int *)(s1 + 0x674) = cDamageUnit_AddDamageCollSphere(
            *(int *)(s1 + 0x670), base + 0x80, r, 0.25f);
    }
    cCollisionSolidManage_CreateUnit(&D_00462FC0, s1, 5, 0.2f);
    q = (struct sph *)(buf + 0x0);
    *(int *)(buf + 0x0) = 0;
    q->b = 0.5f;
    *(int *)(buf + 0x8) = 0;
    q->d = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, s1, s1 + 0x80, q, 0.5f);
    *(char *)(s1 + 0x617) = 1;
    *(float *)(s1 + 0x1564) = 0.02f;
    *(int *)(s1 + 0x1568) = 0;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00277348);
#endif
