#include "godhand/cTaskManager.h"
#include "godhand/cTaskWork.h"

/* sn-2.95.3-136: wait out the movie named by D_005E79D0, then queue the two boot tasks. */

extern char D_005E79D0[];
extern cTaskManager D_00752C00;

extern int cMovie_Start(char *name, int a, int b);
extern int cMovie_GetStatus(char *name, int id);
extern void cMovie_Stop(char *name, int id);
extern void cTaskWork_sleep(struct cTaskWork *w, int n);
extern void cTaskManager_execute(cTaskManager *mgr, void (*fn)(void), int pri);
extern void func_002A5998(void);
extern void func_0030D5C8(void);

__attribute__((section(".text.func_0030DA08")))
void func_0030DA08(void)
{
    int id = cMovie_Start(D_005E79D0, 0, 1);

    while (cMovie_GetStatus(D_005E79D0, id) != 0)
        cTaskWork_sleep(D_00752C00.cur, 1);
    cMovie_Stop(D_005E79D0, id);
    cTaskManager_execute(&D_00752C00, func_002A5998, 0);
    cTaskManager_execute(&D_00752C00, func_0030D5C8, 3);
    cTaskWork_exit(D_00752C00.cur);
}
