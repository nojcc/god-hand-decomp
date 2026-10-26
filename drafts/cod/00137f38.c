/* sn-2.95.3-136 */
/* NON_MATCHING func_00137F38: matches byte for byte, but needs VU0_LQC2_SQC2_MEM, which vu0.h doesn't have.
 * Waiting on LucasPicoli (progress/decisions_needed.md, "vu0.h macros"). */
#include "include_asm.h"
#include "../vu0_pending.h"
#include "godhand/cGameObj.h"
#include "godhand/cPlCamera.h"
#include "godhand/pathRec.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

extern int func_00137BB8(PathHost *self, cVec *pos);

#ifdef NON_MATCHING
/* Pick the path area the player is in and ease the player camera's next pose toward it. */
__attribute__((section(".text.func_00137F38")))
void func_00137F38(PathHost *self, struct cPlCamera *cam)
{
    cVec ref;
    cVec rot;
    float pathTurn;
    float pathDist;
    cGameObj *player;
    PathRec *rec;
    float turn;
    float dist;

    player = Getplayer();
    func_00137BB8(self, player->pos);
    rec = self->rec;
    turn = cam->nextPose.rotOfs.x;
    dist = cam->nextPose.dist;
    if (rec != 0) {
        switch (rec->kind) {
        case 0:
            turn += (rec->coneAngle - turn) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = rec->endY;
            cam->nextPose.ofs.y = self->ofsY;
            break;
        case 1:
            VU0_LQC2_SQC2_MEM(4, &ref, player->pos);
            VU0_LQC2_SQC2_MEM(4, &rot, player->rot);
            PathHost_calcTurn(self, &pathTurn, &pathDist, &ref, &rot);
            turn += (pathTurn - turn) * rec->rate;
            dist += (pathDist - dist) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = dist;
            cam->nextPose.ofs.y = self->ofsY;
            break;
        case 2:
            turn += (rec->coneAngle - turn) * rec->rate;
            cam->nextPose.rotOfs.x = turn;
            cam->nextPose.dist = rec->endY;
            cam->nextPose.ofs.y = rec->ofsY;
            break;
        }
    } else {
        turn += (self->turn - turn) * self->rate;
        dist += (self->startY - dist) * self->rate;
        cam->nextPose.rotOfs.x = turn;
        cam->nextPose.dist = dist;
        cam->nextPose.ofs.y = self->ofsY;
    }
}
#else
INCLUDE_ASM("asm/nonmatching", func_00137F38);
#endif
