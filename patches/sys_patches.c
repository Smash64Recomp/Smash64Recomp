#include "patches.h"

// Patch out syMainSetImemStatus - this function tries to read from RSP IMEM hardware register
// which doesn't exist in the recompiled environment
RECOMP_PATCH void syMainSetImemStatus(void) {
    // Just return - the game doesn't actually need this hardware check
    // The original code would read from 0xA4001000 (SP_IMEM_START) which causes crashes
    return;
}

// Patch out syMainSetDmemStatus - similar issue with RSP DMEM hardware register  
RECOMP_PATCH void syMainSetDmemStatus(void) {
    // Just return - the game doesn't actually need this hardware check
    // The original code would read from 0xA4000000 (SP_DMEM_START) which causes crashes
    return;
}