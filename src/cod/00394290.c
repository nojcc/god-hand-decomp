/* sn-2.95.3-136 matched TU. */

#include "godhand/regTbl.h"
extern int strlen(const char *);
extern int __svfscanf(void *, const char *, void *);
extern int func_003A6CD8();
extern void *D_003FA62C;

extern int func_003A5678(int a0, int a1);
extern int func_003943D0(RegEnt *a0);

/* Apply the relocations whose entry index is key, each relative to base; 0 if one fails. */
__attribute__((section(".text.func_00394290")))
int func_00394290(RegReloc *rel, int count, int key, int base) {
    unsigned int i; unsigned int info;
    i = count - 1;
    if (count != 0) {
        do {
            info = rel->info;
            if ((info >> 8) == (unsigned)key) {
                if (patch((unsigned char *)rel->where, info & 0xFF, base + rel->addend) == 0) return 0;
            }
            rel++; i--;
        } while (i != 0xFFFFFFFFu);
    }
    return 1;
}

typedef void *va_list;
#define va_start(ap, last) (ap = (void *)((char *)__builtin_next_arg(last) - 0x30))
#define va_end(ap)

struct __sFILE {
    unsigned char *_p;
    int _r;
    int _w;
    short _flags;
    short _file;
    struct { unsigned char *_base; int _size; } _bf;
    int _lbfsize;
    void *_cookie;
    void *_read;
    void *_write;
    void *_seek;
    void *_close;
    struct { unsigned char *_base; int _size; } _ub;
    unsigned char *_up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    struct { unsigned char *_base; int _size; } _lb;
    int _blksize;
    int _offset;
    void *_data;
};






__attribute__((section(".text.func_003A6CE0")))
int func_003A6CE0(const char *str, const char *fmt, ...) {
    int ret;
    va_list ap;
    struct __sFILE f;
    f._flags = 4;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._r = strlen(str);
    f._read = (void *)func_003A6CD8;
    f._ub._base = 0;
    f._lb._base = 0;
    f._data = D_003FA62C;
    va_start(ap, fmt);
    ret = __svfscanf(&f, fmt, ap);
    va_end(ap);
    return ret;
}

/* Return 1 if an active entry with the same id and name is already registered, else run the fallback pass. */
__attribute__((section(".text.func_003945C0")))
int func_003945C0(RegEnt *ent) {
    RegTbl *node;
    RegEnt *elem;
    int cnt;
    node = D_003F852C;
    if (node != 0) {
        do {
            cnt = node->count;
            elem = node->ents;
            if (cnt != 0) {
                do {
                    if (elem->active != 0 && elem->id == ent->id &&
                        func_003A5678(elem->name, ent->name) == 0) {
                        return 1;
                    }
                    elem++;
                } while (--cnt != 0);
            }
            node = node->next;
        } while (node != 0);
    }
    return func_003943D0(ent);
}
