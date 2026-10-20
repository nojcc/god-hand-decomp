#ifdef NON_MATCHING
__attribute__((section(".text.F32toF16")))
int F32toF16(float f)
{
    unsigned int bits;
    unsigned int absv;
    int sign;
    unsigned int mant;

    bits = *(unsigned int *)&f;
    absv = bits & 0x7FFFFFFF;
    sign = (bits >> 0x10) & 0x8000;
    if (absv > 0x47FFEFFFU) {
        return (sign | 0x7FFF) & 0xFFFF;
    }
    if (absv <= 0x387FFFFFU) {
        mant = (unsigned int)((absv & 0x7FFFFF) | 0x800000) >> (0x71 - (absv >> 0x17));
    } else {
        mant = absv + 0xC8000000U;
    }
    return (sign | ((unsigned int)(mant + (((mant >> 0xD) & 1) + 0xFFF)) >> 0xD)) & 0xFFFF;
}

#else
INCLUDE_ASM("nonmatching", F32toF16);
#endif
