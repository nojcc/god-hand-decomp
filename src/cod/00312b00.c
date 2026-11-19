/* sn-2.95.3-136: object factory: construct by id, assign serial/id, bind or load its data, flag the meshes (0x312B00). */
#include "godhand/heapArena.h"
#include "godhand/cDataManager.h"
#include "godhand/cObj.h"
#include "godhand/FileLoadRec.h"
#include "godhand/objFactory.h"
extern void *func_00318138(void);
extern char *func_003181A8(void);
extern cModelNode *cModel_getMeshPtr(cModel *self, int n);
extern int cModel_getMeshNum(char *);

__attribute__((section(".text.func_00312B00")))
char *func_00312B00(int id, int dataId)
{
    char *obj;
    void *d;
    void *r;
    int i;

    switch (id) {
    case 0:
    case 0x1100:
    case 0x1200:
    case 0xFF01:
    case 0xFF02:
    case 0xFFFF:
        obj = 0;
        break;
    case 0x101:
        obj = func_00312F70();
        break;
    case 0x212:
        obj = func_00313210();
        break;
    case 0x253:
        obj = func_003132D0();
        break;
    case 0x257:
    case 0x628:
        obj = func_00313390();
        break;
    case 0x36E:
        obj = func_00318138();
        break;
    case 0x374:
        obj = func_00318138();
        break;
    default:
        obj = func_003181A8();
        break;
    }
    if (!obj)
        return 0;
    obj[0x2FC] = D_003C3D18;
    D_003C3D18++;
    cObj_setId((cObj *)obj, id);
    *(short *)(obj + 0x300) = id;
    if (func_003078E0(id) != -1) {
        d = cDataManager_useDataAddress(&D_005864E0, id);
        if (d) {
            *(void **)(obj + 0x304) = d;
            *(void **)(obj + 0x2C8) = &D_00754220;
        } else {
            r = cDataManager_loadWait(&D_00580D20, *(unsigned short *)(obj + 0x2FE), &D_00754220, 1);
            *(void **)(obj + 0x2C8) = &D_00754220;
            *(int *)(obj + 0x250) |= 0x2000000;
            *(void **)(obj + 0x304) = r;
            if (!r) {
                delObj(obj);
                obj = 0;
            }
        }
    } else if (validId(dataId)) {
        d = cDataManager_useDataAddress(&D_005864E0, dataId);
        if (d) {
            *(void **)(obj + 0x304) = d;
            *(void **)(obj + 0x2C8) = &D_00754220;
        } else {
            r = cDataManager_loadWait(&D_00580D20, dataId, &D_00754220, 1);
            *(void **)(obj + 0x2C8) = &D_00754220;
            *(int *)(obj + 0x250) |= 0x2000000;
            *(void **)(obj + 0x304) = r;
            if (!r) {
                delObj(obj);
                obj = 0;
            }
        }
    }
    if (obj) {
        /* i steps twice per pass, so only the even meshes get the flag. Retail does the same. */
        for (i = 0; i < cModel_getMeshNum(obj); i++)
            *(int *)((char *)cModel_getMeshPtr((cModel *)obj, i++) + 0x380) |= 0x2000;
        *(int *)(obj + 0x250) |= 0x10000;
    }
    return obj;
}
