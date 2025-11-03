// Temporary stub implementation to allow the BeebCore static library to link
// before the full emulator wiring lands. Replace with real calls into the core.

extern "C" {
#include "../include/core_api.h"
}

int beeb_init(const beeb_config* /*cfg*/) {
    return BEEB_OK;
}

void beeb_reset(void) {
}

int beeb_tick(unsigned int /*cycles*/) {
    return BEEB_OK;
}

int beeb_load_tape(const unsigned char* /*data*/, size_t /*len*/) {
    return BEEB_OK;
}

int beeb_mount_disk(const unsigned char* /*image*/, size_t /*len*/, int /*drive*/) {
    return BEEB_OK;
}

unsigned char beeb_read_mem(unsigned short /*addr*/) {
    return 0;
}

void beeb_write_mem(unsigned short /*addr*/, unsigned char /*v*/) {
}
