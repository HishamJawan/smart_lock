#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Compiler hint for unused variables */
#define UNUSED(x) ((void)(x))

/* Visibility macros (helpful later if you split libs) */
#define DL_INLINE       static inline
#define DL_WEAK         __attribute__((weak))

/* Global status codes (high-level, not BLE-specific) */
typedef enum
{
    DL_STATUS_OK = 0,
    DL_STATUS_ERROR,
    DL_STATUS_TIMEOUT,
    DL_STATUS_INVALID_PARAM,
    DL_STATUS_BUSY,
    DL_STATUS_NOT_INITIALIZED,
} dl_status_t;

#endif /* COMMON_H */
