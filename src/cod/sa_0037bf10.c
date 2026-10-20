/* sn-2.95.3-136 (): func_0037BF10, start a voice pair for a sound request: take a channel node and a voice node,
 * link them, and when the request is sequenced find the channel's slot in D_0076CEC0 and start the sequence there. */
extern char D_0076CEC0[];
extern int D_00773250[];
extern char D_0076A600[];
extern char *func_0037CF00(void *a0);
extern char *func_0037CEE0(void *a0);
extern char *func_0037D298(int a0);
extern void func_0037C160(void *a0, void *a1);
extern void func_0037C1B8(void *a0, void *a1);
extern void func_0037C228(void *a0, void *a1);
extern void func_0037C2A8(void *a0, void *a1);
extern void func_0037C2E0(void *a0, void *a1);
extern void func_0037D558(void *a0);
extern void func_0037D148(void *a0);
extern void func_0037D3B0(void *a0);
extern int func_0037C630(void *a0);
extern int func_00373118(void *a0, int a1, int a2, int a3);
extern int UpdateSequenceEntry_373298(void *a0, int a1);
extern void func_003738A0(void *a0, int a1, float f12);
extern void UpdateSequenceNodeWeighted_373560(void *a0, int a1, float f12);
extern void func_003735E0(void *a0, int a1, float f12, float f13);
extern void func_0037C720(void *a0);

__attribute__((section(".text.func_0037BF10")))
int func_0037BF10(char *h)
{
    char *a;
    char *b;
    int i;
    int j;
    int idx;
    int *ent;
    char *seq;

    i = 0;
    if (*(unsigned char *)(h + 0xD) & 1)
        a = func_0037CF00(h + 0x20);
    else
        a = func_0037CEE0(h + 0x20);
    if (a == 0)
        return -1;
    b = func_0037D298(*(signed char *)(h + 0x26));
    if (b == 0)
        return -1;
    func_0037C160(a, h);
    func_0037C1B8(b, h);
    *(char **)(a + 8) = b;
    *(char **)(b + 8) = a;
    func_0037C228(b, h);
    func_0037C2A8(b, h);
    func_0037C2E0(b, h);
    if (*(unsigned char *)(h + 0xD) & 8) {
        for (j = 0; j < 3 && D_0076CEC0 + j * 0x20 != a; j++)
            i++;
        if (i >= 3)
            goto fail;
        *(short *)(a + 2) = i;
        *(short *)(b + 2) = i;
        idx = *(short *)(h + 0x20);
        ent = &D_00773250[idx];
        if (*ent == 0)
            return 0;
        seq = D_0076A600 + (short)i * 0x84;
        if (func_00373118(seq, idx + 0x82, *ent, func_0037C630(h)) == 0 ||
            UpdateSequenceEntry_373298(D_0076A600 + *(short *)(b + 2) * 0x84, *(unsigned short *)(h + 0x48)) == 0) {
        fail:
            func_0037D148(b);
            func_0037D3B0(b);
            return -1;
        }
        func_003738A0(D_0076A600 + *(short *)(b + 2) * 0x84, -1, (short)*(unsigned short *)(b + 0x3E) >> 8);
        UpdateSequenceNodeWeighted_373560(D_0076A600 + *(short *)(b + 2) * 0x84, -1, (short)*(unsigned short *)(b + 0x3E) >> 8);
        func_003735E0(D_0076A600 + *(short *)(b + 2) * 0x84, -1, 1.0f, 0.0f);
        func_0037C720(b);
        return 0;
    }
    func_0037D558(b);
    return 0;
}
