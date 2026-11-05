/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cDvd.h"
#include "godhand/cBgmData.h"

extern int D_00747A2C;
extern char D_0044CF68[];
extern char D_00603A40[];
extern char D_0044CFB8[];

/* Load bank bankId from the file named fileName; 1 when the data arrived. */
__attribute__((section(".text.cSeData_LoadFile")))
int cSeData_LoadFile(cSeData *d, int bankId, char *fileName)
{
    char name[0x40];

    if (d->state != 0) {
        if (D_00747A2C >= 0)
            return 0;
        cSeData_Release(d);
    }
    d->bankId = bankId;
    d->state = 1;
    d->owner = 0x7FFFFFFF;
    cSeData_SelectHeap(d);
    func_003A6C58(name, D_0044CF68, fileName);
    if (cDvd_FileExist(&D_00583F20, name) == 0 ||
        (d->f38 = cDvd_ReadAlloc(&D_00583F20, name, &d->buf, d->pool, 0, 0, 0, 0)) == 0 ||
        d->buf == 0) {
        cSeData_Release(d);
        return 0;
    } else {
        cSeData_AddLoadBits(d, 1);
        return 1;
    }
}

/* Both lookups of the slot's two table keys succeed. */
__attribute__((section(".text.cSeData_HasBankKeys")))
int cSeData_HasBankKeys(cSeData *d)
{
    if (BankTable_isKeyFree(D_00603A40, d->f30) == 0 || BankTable_isKeyFree(D_00603A40, d->f34) == 0)
        return 0;
    return 1;
}

/* Validate the loaded bank image and rebase its pointers once; 1 when usable. */
__attribute__((section(".text.cSeData_CheckImage")))
int cSeData_CheckImage(cSeData *d)
{
    cSeBuf *b;

    if (func_003A5BD8(d->buf, D_0044CFB8, 3) != 0)
        return 0;
    b = d->buf;
    if (b->version != 1.1f)
        return 0;
    if (b->f10 == 0)
        return 0;
    if (b->relocated == 0) {
        b->f10 += (int)b;
        d->buf->f20 += (int)b;
        d->buf->f28 += (int)b;
        if (d->buf->f18 != 0)
            d->buf->f18 += (int)b;
        d->buf->relocated = 1;
    }
    b = d->buf;
    d->f14 = b->f10;
    if (d->owner == 0x7FFFFFFF)
        d->owner = b->f08;
    d->f28 = d->bankId + 0x82;
    d->f20 = d->buf->f18;
    cSeData_AddLoadBits(d, 4);
    if (d->buf->f30 != 0) {
        if (cSeData_PrepareDecode(d) == 0)
            cSeData_AddLoadBits(d, 8);
    } else {
        cSeData_AddLoadBits(d, 8);
    }
    cSeData_AddLoadBits(d, 2);
    return 1;
}
