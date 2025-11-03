#ifndef BEEB_CORE_API_H
#define BEEB_CORE_API_H

#include <stdint.h>
#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif

// Visibility macro (default visibility for exported symbols)
#if !defined(BEEB_API)
  #if defined(_WIN32)
    #define BEEB_API __declspec(dllexport)
  #else
    #define BEEB_API __attribute__((visibility("default")))
  #endif
#endif

// Status codes
enum beeb_status {
    BEEB_OK = 0,
    BEEB_ERR_GENERIC = -1,
    BEEB_ERR_BAD_ARG = -2,
    BEEB_ERR_UNSUPPORTED = -3,
    BEEB_ERR_IO = -4
};

// Minimal configuration (extend as needed)
struct beeb_config {
    uint32_t clock_hz;      // CPU clock
    uint32_t sample_rate;   // Audio sample rate
};

// Lifecycle
BEEB_API int  beeb_init(const struct beeb_config* cfg);
BEEB_API void beeb_reset(void);

// Execution
BEEB_API int  beeb_tick(uint32_t cycles);

// Media
BEEB_API int  beeb_load_tape(const uint8_t* data, size_t len);
BEEB_API int  beeb_mount_disk(const uint8_t* image, size_t len, int drive);

// Memory
BEEB_API uint8_t beeb_read_mem(uint16_t addr);
BEEB_API void    beeb_write_mem(uint16_t addr, uint8_t v);

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // BEEB_CORE_API_H
