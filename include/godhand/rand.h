/* include/godhand/rand.h - the game's random number source. */
#ifndef GODHAND_RAND_H
#define GODHAND_RAND_H

/* The next random number (func_0030F348's generator). */
int irand(void);

/* A byte from the small LCG in D_00747B10 (definition in 001fd308.c). */
int Rnd(void);

/* A random float between minimum and maximum (definition in 0031d050.c). */
float frand(float minimum, float maximum);

/* A random float in [0, 1) and in [-1, 1). */
float fRand0_1(void);
float fRand1_1(void);

#endif
