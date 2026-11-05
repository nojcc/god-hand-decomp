/* include/godhand/devPath.h - splitting "device:path" file names (CRI libadxe, src/cod/00330*.c).
 *
 * Both parts are copied into caller buffers of DEVPATH_MAX bytes at most.
 */
#ifndef GODHAND_DEVPATH_H
#define GODHAND_DEVPATH_H

#define DEVPATH_MAX   0x129     /* copy limit, counted with the NUL */
#define DEVPATH_SEP   ':'

extern unsigned int strlen(const char *s);
extern void toUpperStr(unsigned char *str);

#endif
