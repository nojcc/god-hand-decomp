/* include/godhand/typeInfo.h - g++ 2.x run-time type information records.
 *
 * A type_info starts with its name; the vtable pointer follows at 4 (g++ 2.x
 * puts it after the first class's data). The single and multiple
 * inheritance records add their base links after it. The derived records'
 * destructors only call type_info's.
 */
#ifndef GODHAND_TYPEINFO_H
#define GODHAND_TYPEINFO_H

typedef struct TypeInfo {
    const char *name;                   /* 0x0 */
    void *vtable;                       /* 0x4 */
} TypeInfo;

/* type_info's destructor: put back type_info's vtable; with bit 0 of flags set, free the record. */
void func_0031EE10(TypeInfo *self, int flags);

#endif
