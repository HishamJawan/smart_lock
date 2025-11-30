#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include "common.h"

/* Initialize debug logging (UART or SWD printf) */
void debug_log_init(void);

/* Low-level printf-like function */
void debug_log_printf(const char *fmt, ...);

/* Logging macros */
#define LOG_INFO(fmt, ...)  debug_log_printf("[I] " fmt "\r\n", ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  debug_log_printf("[W] " fmt "\r\n", ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) debug_log_printf("[E] " fmt "\r\n", ##__VA_ARGS__)

#endif /* DEBUG_LOG_H */
