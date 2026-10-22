/* sn-2.95.3-136 */
/*
 * NON_MATCHING: 93 words against retail's 92. Retail converts the scaled
 * position and heading to shorts with cvt.w.s; every compiler emits
 * trunc.w.s for the casts. The enemy-kind test also differs: retail keeps
 * the flag in a separate register.
 */
#include "include_asm.h"

#ifdef NON_MATCHING
#include "godhand/cEmWrap.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cScenario.h"

/* View of cEmActorVt with the position and rotation getters at 0x80..0x8F. */
typedef struct cEmPoseVt {
    char unk00[0x80];
    short posDelta;                     /* 0x80 */
    short pad82;
    float *(*getPos)(void *self);       /* 0x84 */
    short rotDelta;                     /* 0x88 */
    short pad8A;
    float *(*getRot)(void *self);       /* 0x8C */
} cEmPoseVt;

/* View of cEmSetParam with its two saved records after the header. */
typedef struct cEmSetSaved {
    cEmSetParam head;
    cEmSetEntry saved[2];               /* 0x10 */
} cEmSetSaved;

/* View of cScenario with the byte at 0x14. */
typedef struct cScenarioMode {
    char unk00[0x14];
    unsigned char mode;                 /* 0x14 */
} cScenarioMode;

/* The actors (0x220 and 0x223) that keep the room record they came from. */
typedef struct cEmRoomActor {
    cEmActor base;
    char unk644[0x1620 - sizeof(cEmActor)];
    SET_EM_DATA setData;                /* 0x1620 */
} cEmRoomActor;

extern cEmSetEntry *func_00295660(cEmSetSaved *self);

static inline unsigned char isEnemyKind(int kind)
{
    if (kind < 0x200) {
        return 0;
    }
    return kind < 0x300;
}

/* Keep a live 0x220 or 0x223 actor in a free saved slot: its position, heading,
 * room flags, sound and vital, so it can be put back later. */
__attribute__((section(".text.func_002956F0")))
void func_002956F0(cEmSetSaved *self, cEmRoomActor *em)
{
    cEmSetEntry *slot;
    SET_EM_DATA *data;
    cEmPoseVt *vt;
    float *v;

    if (((cScenarioMode *)D_003C2F84)->mode == 1 || em == 0) {
        return;
    }
    if (!isEnemyKind(em->base.actorId)) {
        return;
    }
    if (em->base.vital <= 0) {
        return;
    }
    if (em->base.actorId != 0x220 && em->base.actorId != 0x223) {
        return;
    }
    slot = func_00295660(self);
    if (slot == 0) {
        return;
    }
    data = &em->setData;
    slot->objNo = em->base.actorId;
    slot->seBank = em->base.emNo;
    slot->flags = data->flags;
    slot->appPattern = 0x1E;
    slot->seNo = data->seNo;
    vt = (cEmPoseVt *)em->base.vt;
    v = vt->getPos((char *)em + vt->posDelta);
    slot->pos[0] = v[0] * 20.0f;
    slot->pos[1] = v[1] * 20.0f;
    slot->pos[2] = v[2] * 20.0f;
    vt = (cEmPoseVt *)em->base.vt;
    v = vt->getRot((char *)em + vt->rotDelta);
    slot->rot = v[1] * EMSET_ROT_PER_RAD;
    if (em->base.vital <= 0) {
        slot->vital = 0;
    } else {
        slot->vital = em->base.vital;
    }
    slot->entryNo = 0xFF;
}
#else
INCLUDE_ASM("asm/nonmatching", func_002956F0);
#endif
