/* sn-2.95.3-136: func_001AB730, gimmick open/close step: play the open motion with the solid
 * collision off, flash its damage collision when the motion ends, then close it again. */
extern char D_00569B70[];
extern char D_00462FC0[];
extern int cCoreSave_getGameLevel(void *save);
extern void cCollisionSolidManage_SetActive(void *mgr, void *obj, int on);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cDamageUnit_SetDamageCollFlashActiveById(void *unit, int id, int on, int time);

__attribute__((section(".text.func_001AB730")))
void func_001AB730(char *p)
{
    char *d;
    int mot;

    cCoreSave_getGameLevel(D_00569B70);
    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0:
        *(int *)(p + 0x9D0) |= 0x40000000;
        cCollisionSolidManage_SetActive(D_00462FC0, p, 0);
        {
            int v0 = *(int *)(p + 0x304);

            func_002A8578(p, *(int *)(v0 + 0x34) + v0, 0, 0.0f, 0xA, 0, 0);
        }
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    case 1:
        if (moveMotion(p) != 0) {
            *(int *)(p + 0x9D0) &= ~0x40000000;
            {
                int v0 = *(int *)(p + 0x304);

                mot = *(int *)(v0 + 0x38) + v0;
            }
            d = *(char **)(p + 0x608);
            if (d != 0) {
                *(int *)(d + 0x4C) = 0x3C;
                cDamageUnit_SetDamageCollFlashActiveById(*(void **)(p + 0x608), *(int *)(p + 0x620), 1, 0x3C);
            }
            func_002A8578(p, mot, 0, 0.0f, 0xA, 0, 0);
            *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
        }
        cObjBase_addNullSpeed_Rotation(p, 1.0f);
        cObjBase_addNullSpeed(p, 1.0f);
        break;
    case 2:
        moveMotion(p);
        cObjBase_addNullSpeed_Rotation(p, 1.0f);
        cObjBase_addNullSpeed(p, 1.0f);
        break;
    case 3:
        if (moveMotion(p) != 0) {
            *(int *)(p + 0x9D4) = 0x1E;
            cCollisionSolidManage_SetActive(D_00462FC0, p, 1);
            *(unsigned char *)(p + 0x2F4) = 0;
            *(unsigned char *)(p + 0x2F5) = 0;
            *(unsigned char *)(p + 0x2F6) = 0;
            *(unsigned char *)(p + 0x2F7) = 0;
        }
        break;
    }
}
