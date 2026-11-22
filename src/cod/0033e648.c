/* cygnus-2.96 matched TU. */

extern volatile int D_003EADB0;
extern int D_003EADA8;

__attribute__((section(".text.ADXCRS_Finish")))
void ADXCRS_Finish(void) {
    D_003EADB0--;
    if (D_003EADB0 == 0) {
        D_003EADA8 = 0;
    }
}
