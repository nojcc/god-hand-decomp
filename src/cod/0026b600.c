/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cSnd.h"
#include "godhand/player.h"
#include "godhand/rand.h"
#include "godhand/vecInline.h"

#define ROCK_KIND_A     0x3B8   /* CreateObj kinds of the three rocks */
#define ROCK_KIND_B     0x3B9
#define ROCK_KIND_C     0x3BA

extern void func_001CFD60(cOmWeapon *self, int target);

/* Enemy 0x211 only: plays sound 0x107 and creates eight rocks of random kind
 * around itself, one per compass point (5 out on the axes, 3.5 on both axes
 * on the diagonals, each with up to 0.5 of jitter) and 6 below it, unrotated.
 * Each rock is thrown with the enemy as its target (func_001CFD60) and kept
 * in its weapon slots. Stops at the first rock that can't be created. */
__attribute__((section(".text.func_0026B600")))
void func_0026B600(cEm00 *self)
{
    unsigned int i;
    int kind;
    cGameObj *rock;

    if ((self->emNo ^ EM_NO_WEAPON_HOLDER) == 0) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x107, self, 0, 0, 0, 0);
        for (i = 0; i < 8; i++) {
            switch ((unsigned int)irand() % 3) {
            default:
            case 0:
                kind = ROCK_KIND_A;
                break;
            case 1:
                kind = ROCK_KIND_B;
                break;
            case 2:
                kind = ROCK_KIND_C;
                break;
            }
            rock = CreateObj(kind, 0xFFFF);
            if (rock == 0) {
                return;
            }
            rock->vt->unk44((char *)rock + rock->vt->unk40Delta);
            cVec_copy3(rock->pos, self->pos);
            switch (i & 7) {
            default:
            case 0:
                rock->pos->x += fRand1_1() * 0.5f + 0.0f;
                rock->pos->z += fRand1_1() * 0.5f + 5.0f;
                break;
            case 1:
                rock->pos->x += fRand1_1() * 0.5f + 5.0f;
                rock->pos->z += fRand1_1() * 0.5f + 0.0f;
                break;
            case 2:
                rock->pos->x += fRand1_1() * 0.5f + -5.0f;
                rock->pos->z += fRand1_1() * 0.5f + 0.0f;
                break;
            case 3:
                rock->pos->x += fRand1_1() * 0.5f + 0.0f;
                rock->pos->z += fRand1_1() * 0.5f + -5.0f;
                break;
            case 4:
                rock->pos->x += fRand1_1() * 0.5f + 3.5f;
                rock->pos->z += fRand1_1() * 0.5f + 3.5f;
                break;
            case 5:
                rock->pos->x += fRand1_1() * 0.5f + -3.5f;
                rock->pos->z += fRand1_1() * 0.5f + 3.5f;
                break;
            case 6:
                rock->pos->x += fRand1_1() * 0.5f + 3.5f;
                rock->pos->z += fRand1_1() * 0.5f + -3.5f;
                break;
            case 7:
                rock->pos->x += fRand1_1() * 0.5f + -3.5f;
                rock->pos->z += fRand1_1() * 0.5f + -3.5f;
                break;
            }
            rock->pos->y -= 6.0f;
            cVec_copy3(&rock->posA, rock->pos);
            vec3_set(rock->rot, 0.0f, 0.0f, 0.0f);
            func_001CFD60((cOmWeapon *)rock, (int)self);
            self->weapon[i] = rock;
        }
    }
}
