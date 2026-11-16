/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/Poker.h"
#include "godhand/BlackJack.h"


/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001D5C38")))
void func_001D5C38(BlackJack *self, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0xB], -0x140);
    SetFlagOnEntries7C_1D51B8(self, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xC, 0);
    SetFlagOnEntries7C_1D51B8(self, 0x23, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0xB], 0);
    SetFlagOnEntries7C_1D51B8(self, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x23, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0xB], -0x140, 0, 0xA);
    SetFlagOnEntries7C_1D51B8(self, 0xB, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xC, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x23, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0xB], 0, -0x140, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001D5D20")))
void func_001D5D20(BlackJack *self, unsigned short mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0x9], -0x140);
    SetFlagOnEntries7C_1D51B8(self, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xA, 0);
    SetFlagOnEntries7C_1D51B8(self, 0x24, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0x9], 0);
    SetFlagOnEntries7C_1D51B8(self, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x24, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x9], -0x140, 0, 0xA);
    SetFlagOnEntries7C_1D51B8(self, 0x9, 0);
    SetFlagOnEntries7C_1D51B8(self, 0xA, 1);
    SetFlagOnEntries7C_1D51B8(self, 0x24, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x9], 0, -0x140, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE088")))
void func_001DE088(Poker *self, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0x3], 0xFA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x4, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x5, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0x3], 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x4, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0x5, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x3], 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x3, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x4, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0x5, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x3], 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE170")))
void func_001DE170(Poker *self, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0x6], 0xFA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x7, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x8, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0x6], 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x7, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0x8, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x6], 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x6, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x7, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0x8, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x6], 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE258")))
void func_001DE258(Poker *self, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0x9], 0xFA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xA, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xB, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0x9], 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xA, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0xB, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x9], 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(self, 0x9, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xA, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0xB, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0x9], 0, 0xFA, 0xA);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001DE340")))
void func_001DE340(Poker *self, unsigned char mode)
{
    int m = mode;
    if (m == 1) {
        goto c1;
    }
    if (m < 2) {
        goto def;
    }
    if (m == 2) {
        goto c2;
    }
    if (m == 3) {
        goto c3;
    }
def:
    CustomIDWork_SetOffsetPosX(&self->elem[0xC], 0xFA);
    SetCustomIDDispOneOrAll_1DD258(self, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xD, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xE, 0);
    return;
c1:
    CustomIDWork_SetOffsetPosX(&self->elem[0xC], 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xD, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0xE, 0);
    return;
c2:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0xC], 0xFA, 0, 0xA);
    SetCustomIDDispOneOrAll_1DD258(self, 0xC, 0);
    SetCustomIDDispOneOrAll_1DD258(self, 0xD, 1);
    SetCustomIDDispOneOrAll_1DD258(self, 0xE, 0);
    return;
c3:
    CustomIDWork_SetMoveOffsetPosX(&self->elem[0xC], 0, 0xFA, 0xA);
}
