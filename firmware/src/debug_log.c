#include "debug_log.h"
#include "hal_uart.h"
#include <stdarg.h>
#include <stdio.h>

#ifndef DEBUG_LOG_BUFFER_SIZE
#define DEBUG_LOG_BUFFER_SIZE    128
#endif

static char s_log_buffer[DEBUG_LOG_BUFFER_SIZE];

/* Choose a default log UART config */
static const hal_uart_config_t s_debug_uart_cfg = {
    .baudrate     = 115200,
    .hw_flow_ctrl = false,
};

void debug_log_init(void)
{
    /* Initialize logical DEBUG UART (maps to SDK uart_init) */
    (void)hal_uart_init(HAL_UART_PORT_DEBUG, &s_debug_uart_cfg);
}

void debug_log_printf(const char *fmt, ...)
{
    va_list args;
    int n;

    va_start(args, fmt);
    n = vsnprintf(s_log_buffer, DEBUG_LOG_BUFFER_SIZE, fmt, args);
    va_end(args);

    if (n < 0)
    {
        return;
    }

    if (n > DEBUG_LOG_BUFFER_SIZE)
    {
        n = DEBUG_LOG_BUFFER_SIZE;
    }

    (void)hal_uart_send(HAL_UART_PORT_DEBUG, (const uint8_t *)s_log_buffer, (uint16_t)n);
}
