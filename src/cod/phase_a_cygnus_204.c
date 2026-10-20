/* Three Cygnus clones of func_003258B8.
 * Without -freorder-blocks the
 * body matches except the loop reload: retail uses `ld v1` / `beqz v1`,
 * this source uses `ld v0` / `beqz v0`.
 * score 10.
 * Needs c_flags_drop of -f=-freorder-blocks if it is retried. */
extern void ChangeThreadPriority(int, int);
extern void WakeupThread(int);
extern void adxm_ResumeThread(int);
extern volatile long D_003C81A0;
extern volatile long D_003C8198;
extern volatile int D_003C814C;
extern volatile long D_003C8180;
extern volatile long D_003C8178;
extern volatile int D_003C8140;
extern volatile long D_003C8160;
extern volatile long D_003C8158;
extern volatile int D_003C8138;

#define PHASE_A_204(name, flag, ready, thread)                         \
    void name(void)                                                    \
    {                                                                  \
        if ((flag) == 0) {                                             \
            do {                                                       \
                (ready) = 1;                                           \
                ChangeThreadPriority((thread), 1);                     \
                WakeupThread((thread));                                \
                adxm_ResumeThread((thread));                           \
            } while ((flag) == 0);                                     \
        }                                                              \
        (flag) = 0;                                                    \
        (ready) = 0;                                                   \
        (thread) = 0;                                                  \
    }

PHASE_A_204(func_003258B8, D_003C81A0, D_003C8198, D_003C814C)
PHASE_A_204(func_00325988, D_003C8180, D_003C8178, D_003C8140)
PHASE_A_204(func_00325B90, D_003C8160, D_003C8158, D_003C8138)
