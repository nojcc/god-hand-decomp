/* sn-2.95.3-136 */
/* NON_MATCHING: 2 instructions differ: retail computes &player->rot into $v1 (this C uses $v0) for the second quadword copy. cCamManager needs the dist/turn/height fields at 0x444/0x450/0x460 and PathHost/PathRec the rate and dist fields before this can use the headers. */
#include "godhand/cGameObj.h"
#include "godhand/pathRec.h"
#include "godhand/player.h"
#include "godhand/vu0.h"

#ifdef NON_MATCHING
/* The camera manager fields the path follower drives (cCamManager view). */
typedef struct cCamManager {
    char unk000[0x444];
    float dist;                         /* 0x444 */
    char unk448[0x8];
    float turn;                         /* 0x450 */
    char unk454[0xC];
    float height;                       /* 0x460 */
} cCamManager;

/* PathHost_calcTurn's inputs and outputs on the stack. */
typedef struct cPathTurnFrame {
    cVec ref;
    cVec rot;
    float turn;
    float height;
} cPathTurnFrame;

#define PATHTURN_FRAME_OFFSET(field) ((int)&((cPathTurnFrame *)0)->field)

#define PATHHOST_TURN(self) (*(float *)((char *)(self) + 0x14))
#define PATHHOST_RATE(self) (*(float *)((char *)(self) + 0x18))
#define PATHHOST_DIST(self) (*(float *)((char *)(self) + 0x1C))
#define PATHREC_RATE(rec)   (*(float *)((char *)(rec) + 0x34))
#define PATHREC_DIST(rec)   (*(float *)((char *)(rec) + 0x5C))

extern int func_00137BB8(PathHost *self, cVec *pos);
extern void PathHost_calcTurn(PathHost *self, float *turn, float *height, cVec *ref, cVec *target);

/* Pick the path area the player is in and ease the camera's turn and height toward it. */
__attribute__((section(".text.func_00137F38")))
void func_00137F38(PathHost *self, cCamManager *mgr)
{
    cPathTurnFrame f;
    cGameObj *player;
    PathRec *rec;
    float turn;
    float height;

    player = Getplayer();
    func_00137BB8(self, player->pos);
    rec = self->rec;
    turn = mgr->turn;
    height = mgr->height;
    if (rec != 0) {
        switch (rec->kind) {
        case 0:
            turn += (rec->coneAngle - turn) * PATHREC_RATE(rec);
            mgr->turn = turn;
            mgr->height = rec->endY;
            mgr->dist = PATHHOST_DIST(self);
            break;
        case 1:
            VU0_LQC2(4, player->pos, 0);
            VU0_SQC2(4, &f, PATHTURN_FRAME_OFFSET(ref));
            VU0_LQC2(4, player->rot, 0);
            VU0_SQC2(4, &f, PATHTURN_FRAME_OFFSET(rot));
            PathHost_calcTurn(self, &f.turn, &f.height, &f.ref, &f.rot);
            turn += (f.turn - turn) * PATHREC_RATE(rec);
            height += (f.height - height) * PATHREC_RATE(rec);
            mgr->turn = turn;
            mgr->height = height;
            mgr->dist = PATHHOST_DIST(self);
            break;
        case 2:
            turn += (rec->coneAngle - turn) * PATHREC_RATE(rec);
            mgr->turn = turn;
            mgr->height = rec->endY;
            mgr->dist = PATHREC_DIST(rec);
            break;
        }
    } else {
        turn += (PATHHOST_TURN(self) - turn) * PATHHOST_RATE(self);
        height += (self->startY - height) * PATHHOST_RATE(self);
        mgr->turn = turn;
        mgr->height = height;
        mgr->dist = PATHHOST_DIST(self);
    }
}
#else
#include "include_asm.h"
INCLUDE_ASM("nonmatching", func_00137F38);
#endif
