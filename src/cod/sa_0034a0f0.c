/* cygnus-2.96, --f=-freorder-blocks: NM closer handoff. */
extern int func_0034A6F8(void *sf, int *nch, int *ntr);
extern int func_0035A968(void *buf, int ntr);
extern int GetArrayElemA0C_35A1C8(void *sf, int idx);
extern void func_0035AA40(void *buf, int pos, int ntr);
extern int func_0035A9C8(void *buf, int ntr, int *flag);
extern int sfadxt_AdjDiscard(void *adxt, int len, int *end);
extern int ADXT_IsEndcode(void *adxt, int len, int *out);
extern void func_0035A000(void *sf, int a1, int a2);
extern int func_0034A3E0(void *sf, int nch, int len);
extern void func_0034A038(void);

__attribute__((section(".text.func_0034A0F0")))
void func_0034A0F0(char *sf, void *adxt, int len, int *out)
{
    char *buf = sf + 0xD30;
    char *work = *(char **)(sf + 0x2004);
    int nch, ntr, flag, end, tmp;
    int pos0, pos1, d, n, rem, done;

    *out = 0;
    if (func_0034A6F8(sf, &nch, &ntr) != 0) {
        *(void **)(work + 0x3C) = func_0034A038;
        return;
    }
    pos0 = func_0035A968(buf, ntr);
    if (pos0 < 0)
        return;
    if (GetArrayElemA0C_35A1C8(sf, 5) == 0) {
        func_0035AA40(buf, pos0, ntr);
        *(void **)(work + 0x3C) = func_0034A038;
        return;
    }
    pos1 = func_0035A9C8(buf, ntr, &flag);
    if (pos1 < 0)
        return;
    func_0035AA40(buf, pos1, ntr);
    done = 0;
    d = pos1 - pos0 - *(int *)(work + 0x38);
    if (d >= 0) {
        n = (d >> 5) * nch * 18;
        end = 0;
        if (n > 0) {
            int c = len / (nch * 18) * nch * 18;
            c = (c < n) ? c : n;
            done = sfadxt_AdjDiscard(adxt, c, &end);
            rem = n - c;
            *(int *)(work + 0x38) += done / (nch * 18) * 32;
            if (rem > 0)
                goto check;
        }
        if (flag) {
            *(void **)(work + 0x3C) = func_0034A038;
            end = ADXT_IsEndcode(adxt, len, &tmp);
        }
    check:
        if (end) {
            func_0035A000(sf, 6, 0);
        }
    } else {
        int nd = -d;
        if (flag) {
            int m = nd / 32 * 32;
            if (m > 0) {
                int r = func_0034A3E0(sf, nch, m);
                *(int *)(work + 0x38) -= r;
                if (m - r > 0)
                    goto out;
            }
            *(void **)(work + 0x3C) = func_0034A038;
        }
    }
out:
    *out = done;
    *(long long *)(sf + 0x9C8) += done;
}

