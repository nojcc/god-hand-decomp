/* cygnus-2.96 matched TU. */
extern int D_003EE084; /* Scratchpad copy mode: zero uses DMA, nonzero uses the CPU. */
extern int MWSPR_RestoreSprMem(void *src, int size, void *sprAddr);
extern int MWSPR_RestoreSprByCpu(void *source, int byteCount, int scratchpadOffset);

/* Restore a saved memory buffer to scratchpad using the selected transfer mode. */
__attribute__((section(".text.SprMem_restore")))
int SprMem_restore(void *source, int byteCount, int scratchpadOffset)
{
    int result;

    if (D_003EE084 == 0) {
        result = MWSPR_RestoreSprMem(source, byteCount, (void *)scratchpadOffset);
    } else {
        result = MWSPR_RestoreSprByCpu(source, byteCount, scratchpadOffset);
    }
    return result;
}
