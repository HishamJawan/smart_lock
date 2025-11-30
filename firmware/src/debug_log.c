#include "debug_log.h"
#include <stdarg.h>
#include <stdio.h>

/*
 * For now we just wrap the SDK's `printf` output, which normally goes to
 * the debug UART or semihosting, depending on how the BK3633 SDK is set up.
 * Later we can route this to our own hal_uart implementation.
 */

void debug_log_init(void)
{
    /* TODO: configure DEBUG UART pins using board_config.h and HAL.
     * For now, assume SDK startup already configured a debug port.
     */
}

void debug_log_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}
