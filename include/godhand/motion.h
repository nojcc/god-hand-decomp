/* include/godhand/motion.h - per-motion parameter lists.
 *
 * A motion carries nParam 12-byte parameter entries. The first word of each
 * packs the parameter kind, a sub id and the index of the handler in
 * D_003BD910 that evaluates it.
 */
#ifndef GODHAND_MOTION_H
#define GODHAND_MOTION_H

typedef struct MotionParam {
    int kind : 8;               /* 0x00 */
    unsigned int sub : 4;       /* bits 8..11, -1 matches any */
    unsigned int func : 4;      /* bits 12..15, index into D_003BD910 */
    unsigned int pad : 16;
    int unk04[2];
} MotionParam;                  /* 0x0C */

typedef struct MotionData {
    char pad00[6];
    unsigned char nParam;       /* 0x06 */
    char pad07;
    MotionParam param[1];       /* 0x08 */
} MotionData;

typedef float (*MotionParamFn)(MotionData *mot, MotionParam *prm);

extern MotionParamFn D_003BD910[];

int MotionIsHaveParam(MotionData *mot, int kind, int sub);
float MotionGetParam(MotionData *mot, int kind, int sub);

/* Steps the object's motion; nonzero when it ended this frame. */
int moveMotion(void *obj);
/* Starts motion motA/motB on the object (both addresses in its resource blob). */
void func_002A8578(int obj, int motA, int motB, int mode, float start, unsigned short sel, unsigned short keep);

/* Sets the motion step of obj (negated for a mirrored motion). */
void SetMotionStep(void *obj, float step);

/* Starts motion on self with its sequence data, blending in over blendLen
 * frames, at frame start (frameNum - 1 - start when the rate is negative). */
struct cObjBase;
struct SEQ_DATA_HEADER_1;
int setMotionInfo(struct cObjBase *self, char *motion, struct SEQ_DATA_HEADER_1 *seqData, unsigned int blendLen,
                  float rate, float start, int flags);

#endif
