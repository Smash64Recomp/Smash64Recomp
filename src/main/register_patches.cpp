#include "ovl_patches.hpp"
#include "librecomp/overlays.hpp"
#include "librecomp/game.hpp"
#include "librecomp/sections.h"

extern "C" {
    extern const char bk_patches_bin[];
    extern const size_t bk_patches_bin_size;
}

// Include the generated recomp_overlays.inl file which contains the actual section table
#include "../../RecompiledPatches/recomp_overlays.inl"

void smash64::register_patches() {
    recomp::overlays::register_patches(bk_patches_bin, bk_patches_bin_size, section_table, ARRLEN(section_table));
}
