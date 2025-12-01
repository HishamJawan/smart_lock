#include "hal_uart.h"
#include "board_config.h"
#include "debug_log.h"

/* SDK UART driver */
#include "uart.h"   // from sdk/src/driver/uart.h

static uint8_t s_uart_initialized = 0;
static uint32_t s_uart_baudrate = 0;

/* Internal helper: only one physical UART in this SDK */
static dl_status_t hal_uart_hw_init_once(uint32_t baudrate)
{
    if (!s_uart_initialized)
    {
        uart_init(baudrate);         // SDK call
        s_uart_initialized = 1;
        s_uart_baudrate = baudrate;
    }
    else
    {
        /* Already initialized – optionally check same baudrate */
        if (s_uart_baudrate != baudrate)
        {
            /* You can decide what to do here; for now, just log and ignore */
            LOG_WARN("hal_uart: requested baud %u but already init at %u",
                     (unsigned)baudrate, (unsigned)s_uart_baudrate);
        }
    }

    return DL_STATUS_OK;
}

dl_status_t hal_uart_init(hal_uart_port_t port, const hal_uart_config_t *cfg)
{
    if (port >= HAL_UART_PORT_MAX || cfg == NULL)
    {
        return DL_STATUS_INVALID_PARAM;
    }

    /* For now, all logical ports share the same physical UART. */
    return hal_uart_hw_init_once(cfg->baudrate);
}

dl_status_t hal_uart_send(hal_uart_port_t port, const uint8_t *data, uint16_t len)
{
    UNUSED(port);  /* Only one physical UART right now */

    if ((data == NULL) || (len == 0))
    {
        return DL_STATUS_INVALID_PARAM;
    }

    uart_send((void *)data, len);    // SDK call
    return DL_STATUS_OK;
}

dl_status_t hal_uart_send_byte(hal_uart_port_t port, uint8_t byte)
{
    return hal_uart_send(port, &byte, 1u);
}
