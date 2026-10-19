/* sn-2.95.3-136: arena enemy spawn step for the six-slot wave: phase 0 defeats every enemy; phase 1 starts
 * the action of each waiting enemy entry (ids 2..7) as it becomes active, counts it and clears its slot. */
extern int IsEntryActive_1C2490(int entry);
extern void ColiseumBattle_DefeatAllEnemies(void *self);
extern void cEmSetParam_setEm(void *param, int slot);
extern void cEmWrap_StartAction(void *act);
extern char D_00586AB0[];

typedef struct ColiWave6 {
    char unk000[0xB8C];
    int enemyNum;                       /* 0xB8C */
    char unkB90[4];
    int phase;                          /* 0xB94 */
    char unkB98[0xCC];
    int wait[6];                        /* 0xC64 */
} ColiWave6;

__attribute__((section(".text.func_001F1918")))
void func_001F1918(ColiWave6 *self)
{
    char buf[0x10];
    switch (self->phase) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->wait[0] != 0 && IsEntryActive_1C2490(self->wait[0]) != 0) {
            buf[0] = 2;
            cEmSetParam_setEm(D_00586AB0, 2);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[0] = 0;
        }
        if (self->wait[1] != 0 && IsEntryActive_1C2490(self->wait[1]) != 0) {
            buf[0] = 3;
            cEmSetParam_setEm(D_00586AB0, 3);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[1] = 0;
        }
        if (self->wait[2] != 0 && IsEntryActive_1C2490(self->wait[2]) != 0) {
            buf[0] = 4;
            cEmSetParam_setEm(D_00586AB0, 4);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[2] = 0;
        }
        if (self->wait[3] != 0 && IsEntryActive_1C2490(self->wait[3]) != 0) {
            buf[0] = 5;
            cEmSetParam_setEm(D_00586AB0, 5);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[3] = 0;
        }
        if (self->wait[4] != 0 && IsEntryActive_1C2490(self->wait[4]) != 0) {
            buf[0] = 6;
            cEmSetParam_setEm(D_00586AB0, 6);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[4] = 0;
        }
        if (self->wait[5] != 0 && IsEntryActive_1C2490(self->wait[5]) != 0) {
            buf[0] = 7;
            cEmSetParam_setEm(D_00586AB0, 7);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->wait[5] = 0;
        }
        break;
    }
}
