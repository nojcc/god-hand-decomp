/* NON_MATCHING func_001F7680 (sn-2.95.3-136, extern_jtbl D_0042C260): 57 vs 70 words. Retail keeps the view record address at 0x1380 in a register instead of folding it into the field offsets, and reloads the game object pointer in every case. */
/* sn-2.95.3-136: func_001F7680, set the game object's view for a request: flag the view record at 0x1380,
 * set the mode byte at 0x1415 and the view's pair at 0x13A0/0x13A4 from the request kind (200/330, or
 * 230/290 for kinds 16-18), and store the request id + 0x3011 at 0x1464. */
#include "include_asm.h"

#ifdef NON_MATCHING

/* The part of a view request this function reads. */
typedef struct ViewReq {
    char unk00[0x1C];
    int id;                             /* 0x1C */
    unsigned int kind;                  /* 0x20 */
} ViewReq;

/* The view record at game object + 0x1380. */
typedef struct ViewRec {
    char unk00[0x94];
    unsigned char flags;                /* 0x94 */
    char unk95[0xA0 - 0x95];
    float near;                         /* 0xA0 */
    float far;                          /* 0xA4 */
} ViewRec;

/* The part of the game object this function writes. */
typedef struct ViewGame {
    char unk0000[0x1380];
    ViewRec view;                       /* 0x1380 */
    char unk13A8[0x1415 - 0x13A8];
    unsigned char viewMode;             /* 0x1415 */
    char unk1416[0x1464 - 0x1416];
    int viewId;                         /* 0x1464 */
} ViewGame;

extern ViewGame *D_003BD6E8;            /* the game object */

__attribute__((section(".text.func_001F7680")))
void func_001F7680(void *unused, ViewReq *req)  /* callers pass the owner; it is not read */
{
    float near;
    float far;

    D_003BD6E8->view.flags |= 1;
    switch (req->kind) {
    case 0:
    default:
        near = 200.0f;
        far = 330.0f;
        D_003BD6E8->viewMode = 1;
        break;
    case 1:
        near = 200.0f;
        far = 330.0f;
        D_003BD6E8->viewMode = 0;
        break;
    case 2:
        near = 200.0f;
        far = 330.0f;
        D_003BD6E8->viewMode = 3;
        break;
    case 3:
        near = 200.0f;
        far = 330.0f;
        D_003BD6E8->viewMode = 2;
        break;
    case 16:
        near = 230.0f;
        D_003BD6E8->viewMode = 4;
        far = 290.0f;
        break;
    case 17:
        near = 230.0f;
        D_003BD6E8->viewMode = 5;
        far = 290.0f;
        break;
    case 18:
        near = 230.0f;
        D_003BD6E8->viewMode = 6;
        far = 290.0f;
        break;
    }
    D_003BD6E8->view.far = far;
    D_003BD6E8->view.near = near;
    D_003BD6E8->viewId = req->id + 0x3011;
}
#else
INCLUDE_ASM("asm/nonmatching", func_001F7680);
#endif
