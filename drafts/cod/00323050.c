/* NON_MATCHING func_00323050 (cygnus-2.96, drop-reorder): 248 words vs 265. Retail re-reads the AFS
 * header bytes through buf+4/buf+5 address registers where this reuses the loaded bytes, keeps i in
 * s1, and branches differently around the error exits. D_003EB838 (ADXF handle) and D_003C5298 (read
 * buffer) are int in 00322c68.c and 00322f80.c; they need one pointer type in adxf.h. */
#include "include_asm.h"
#include "godhand/adxf.h"
#include "godhand/criSj.h"


#ifdef NON_MATCHING
extern int func_003A50B4(const void *a, const void *b, int n);
extern int func_00324500(signed char *adxf);
extern int func_00324858(int ent);
extern void func_00322F18(void);
extern int ADXF_ReadNw(signed char *adxf, int nsct, unsigned char *buf);

extern int D_003EB834;
extern signed char *D_003EB838;
extern int D_003EB83C;
extern int D_003EB840;
extern unsigned char *D_003C5298;
extern int D_003C529C;
extern char D_004514F0[];
extern char D_00451528[];
extern char D_00451530[];
extern char D_00451568[];
extern char D_004515A0[];

#define ADXF_LE32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))

/* ADXF partition load server: once the current read finishes, check the AFS header on the first
 * chunk, then copy each file's size (bytes, or 16-bit sector counts) into the partition table and
 * read the next chunk until all entries are in. Returns the load state. */
__attribute__((section(".text.func_00323050")))
int func_00323050(int ptid)
{
    AdxfPtInfo *pt;
    int *top32;
    unsigned short *top16;
    int *tbl32;
    unsigned short *tbl16;
    int nfile;
    int nword;
    int i;
    int sct;

    top32 = 0;
    top16 = 0;
    tbl16 = 0;
    tbl32 = 0;
    if (ptid != D_003EB83C) {
        func_0033F130(D_004514F0);
        return -3;
    }
    if (D_003EB838 == 0 && ptid != -1) {
        return D_003EB840;
    }
    D_003EB840 = func_00324500(D_003EB838);
    if (D_003EB840 != 3) {
        return D_003EB840;
    }
    pt = D_003EB308[ptid];
    if (pt->type == 1) {
        top32 = &pt->top;
        tbl32 = pt->tbl;
    } else {
        top16 = (unsigned short *)&pt->top;
        tbl16 = (unsigned short *)&pt->top + 1;
    }
    i = 1;
    if (pt->unk08 == 0) {
        if (func_003A50B4(D_003C5298, D_00451528, 3) != 0) {
            func_0033F130(D_00451530);
            D_003EB840 = 4;
            func_00322F18();
            return D_003EB840;
        }
        if (ADXF_LE32(D_003C5298 + 4) > 0x10000) {
            func_0033F130(D_00451568);
            D_003EB840 = 4;
            func_00322F18();
            return D_003EB840;
        }
        nfile = D_003C5298[4] | (D_003C5298[5] << 8);
        *(unsigned short *)pt->unk0C = nfile;
        pt->unk08 = nfile;
        if (pt->type == 1) {
            pt->unk04 = ADXF_PTINFO_SIZE + (nfile + 1) * sizeof(int);
        } else {
            pt->unk04 = (ADXF_PTINFO_SIZE + nfile * sizeof(short)) / 4 * 4;
        }
        if (pt->type == 1) {
            *top32 = ADXF_LE32(D_003C5298 + 8);
        } else {
            *top16 = ADXF_LE32(D_003C5298 + 8) / 2048;
        }
        i = 3;
    }
    nword = D_003C529C << 9;
    for (; i < nword; i += 2) {
        if (pt->type == 1) {
            tbl32[D_003EB834++] = ADXF_LE32(D_003C5298 + i * 4);
        } else {
            sct = func_00324858(ADXF_LE32(D_003C5298 + i * 4));
            if (sct & 0xFFFF0000) {
                func_0033F130(D_004515A0);
                D_003EB840 = 4;
                func_00322F18();
                return D_003EB840;
            }
            tbl16[D_003EB834++] = sct;
        }
        if (D_003EB834 >= pt->unk08) {
            D_003EB840 = 3;
            func_00322F18();
            break;
        }
    }
    if (i < nword) {
        return D_003EB840;
    }
    if (ADXF_ReadNw(D_003EB838, D_003C529C, D_003C5298) < 0) {
        D_003EB840 = 4;
        func_00322F18();
        return D_003EB840;
    }
    D_003EB840 = D_003EB838[1];
    return D_003EB840;
}
#else
INCLUDE_ASM("asm/nonmatching", func_00323050);
#endif
