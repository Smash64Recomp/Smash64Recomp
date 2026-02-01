#include "patches.h"
#include "sys/dma.h"

int dummyData = 1;
int dummyBss;
int logFirstDma = 0;

RECOMP_PATCH void syDmaReadRom(uintptr_t rom_src, void *ram_dst, size_t size) {
    //log first dma that occurs as an example patch
    if (logFirstDma == 0) {
        logFirstDma = 1;
        recomp_printf("syDmaReadRom; rom:%x, ram:%x, size:%d\n", rom_src, ram_dst, size);
    }
    
    syDmaCopy(gSYDmaRomPiHandle, rom_src, (uintptr_t)ram_dst, size, OS_READ);
}