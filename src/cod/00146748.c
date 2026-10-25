#include "godhand/cModel.h"
#include "godhand/cCockTutorial.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_0041DCC8[];
extern void __builtin_delete(void);

/* Start a tutorial message once the pack is loaded: remember the message
 * number, raise the flag byte and hide entries 5 and 6. */
__attribute__((section(".text.cCockTutorial_TutorialON")))
void cCockTutorial_TutorialON(cCockTutorial *self, unsigned short msg) {
    if (self->data) {
        self->curMsg = msg;
        self->unkB8 = 1;
        self->ent[5]->flags = self->ent[5]->flags | IDENT_FLAG_NO_DRAW;
        self->ent[6]->flags = self->ent[6]->flags | IDENT_FLAG_NO_DRAW;
    }
}

/* Show or hide every mesh on one layer. */
__attribute__((section(".text.cModel_setLayerDisplay")))
void cModel_setLayerDisplay(cModel *self, int layer, int show) {
    cModelNode *node = self->meshHead;
    if (node == 0) return;
    do {
        if (layer == node->layer) {
            unsigned int flags = node->dispFlags;
            if (show != 0)
                flags &= 0xFFFFFFFE;
            else
                flags |= CMODEL_NODE_HIDE;
            node->dispFlags = flags;
        }
        node = node->next;
    } while (node != 0);
}

__attribute__((section(".text.InitPtrField80AndForward_146748")))
void InitPtrField80AndForward_146748(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

/* The object behind vtable D_0041E8C0, as far as its draw reads it: two displays,
 * the second one drawn instead of the first while `alt` is set. */
typedef struct IDDualDisp {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x79 - sizeof(cIDBaseObj)];
    char state;                         /* 0x79 nothing is drawn in states 0 and 6 */
    char unk7A[0xA0 - 0x7A];
    cIDBaseObj base2;                   /* 0xA0 */
    char unkE8[0xF8 - 0xE8];
    unsigned short alt;                 /* 0xF8 */
} IDDualDisp;

/* Draw the first display, or the second one while `alt` is set; nothing in states 0 and 6. */
__attribute__((section(".text.ForwardTransBySubState_146E20")))
void ForwardTransBySubState_146E20(IDDualDisp *self) {
    char state = self->state;
    if (state == 0) return;
    if (state == 6) return;
    if (self->alt == 0) {
        cIDBase_trans(&self->base);
    } else {
        cIDBase_trans(&self->base2);
    }
}

__attribute__((section(".text.InitPtrField80AndForward_146E70")))
void InitPtrField80AndForward_146E70(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.InitPtrField80AndForward_146F98")))
void InitPtrField80AndForward_146F98(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}
