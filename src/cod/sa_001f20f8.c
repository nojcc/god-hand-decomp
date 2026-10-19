/* sn-2.95.3-136: NM closer handoff. */
extern void ColiseumBattle_DefeatAllEnemies(void *a0);
extern int ColiseumBattle_CountLiveEnemies(void *a0);
extern int cRoomSave_clearEmDeadFlag(void *a0, int a1);
extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(void *a0);
extern char D_00586AB0[];
extern char D_005E8658[];
extern int D_00568240;

static inline void spawnEm(char *s0, char *buf, int id)
{
    buf[0] = id;
    cEmSetParam_setEm(D_00586AB0, id);
    cEmWrap_StartAction(buf);
    *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
}

__attribute__((section(".text.func_001F20F8")))
void func_001F20F8(void *a0)
{
    char *s0 = (char *)a0;
    int st;
    char bA[0x10];
    char bB[0x10];
    char bC[0x10];
    char bD[0x10];
    char bE[0x10];
    char bF[0x10];

    st = *(int *)(s0 + 0xB94);
    switch (st) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(s0);
        D_00568240 |= 6;
        *(int *)(s0 + 0xBA0) = 45;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(s0 + 0xB88) >= *(short *)(s0 + 0xB6A))
            break;
        if (ColiseumBattle_CountLiveEnemies(s0) != 0)
            break;
        if (*(int *)(s0 + 0xBA0) == 0) {
        *(int *)(s0 + 0xBA0) = 45;
        *(int *)(s0 + 0xB90) = *(int *)(s0 + 0xB90) + 1;
        if (*(int *)(s0 + 0xB90) >= 4)
            *(int *)(s0 + 0xB90) = 0;
        switch (*(int *)(s0 + 0xB90)) {
        case 0:
            cRoomSave_clearEmDeadFlag(D_005E8658, 10);
            cRoomSave_clearEmDeadFlag(D_005E8658, 11);
            cRoomSave_clearEmDeadFlag(D_005E8658, 12);
            spawnEm(s0, bA, 10);
            spawnEm(s0, bB, 11);
            spawnEm(s0, bC, 12);
            break;
        case 1:
            cRoomSave_clearEmDeadFlag(D_005E8658, 3);
            cRoomSave_clearEmDeadFlag(D_005E8658, 4);
            cRoomSave_clearEmDeadFlag(D_005E8658, 5);
            spawnEm(s0, bA, 3);
            spawnEm(s0, bD, 4);
            spawnEm(s0, bE, 5);
            break;
        case 2:
            cRoomSave_clearEmDeadFlag(D_005E8658, 6);
            cRoomSave_clearEmDeadFlag(D_005E8658, 7);
            cRoomSave_clearEmDeadFlag(D_005E8658, 8);
            spawnEm(s0, bA, 6);
            spawnEm(s0, bB, 7);
            spawnEm(s0, bF, 8);
            break;
        case 3:
            cRoomSave_clearEmDeadFlag(D_005E8658, 9);
            spawnEm(s0, bA, 9);
            break;
        }
        } else {
            *(int *)(s0 + 0xBA0) = *(int *)(s0 + 0xBA0) - 1;
        }
        break;
    }
}
