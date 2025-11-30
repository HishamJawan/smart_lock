#include "hal_uart.h"
#include "board_config.h"
#include "debug_log.h"

/*
 * NOTE:
 *  - These are skeletons that you will later wire to the BK3633 UART driver.
 *  - For now they just mark parameters as unused and return OK so code links.
 */

static dl_status_t hal_uart_hw_init(hal_uart_port_t port,
                                    const hal_uart_config_t *cfg)
{
    UNUSED(port);
    UNUSED(cfg);

    /* TODO: Map HAL_UART_PORT_DEBUG and HAL_UART_PORT_FP to the
     * actual BK3633 UART instances and configure pins using board_config.h.
     */

    return DL_STATUS_OK;
}

dl_status_t hal_uart_init(hal_uart_port_t port, const hal_uart_config_t *cfg)
{
    if (port >= HAL_UART_PORT_MAX || cfg == NULL)
    {
        return DL_STATUS_INVALID_PARAM;
    }

    return hal_uart_hw_init(port, cfg);
}

dl_status_t hal_uart_send(hal_uart_port_t port, const uint8_t *data, uint16_t len)
{
    UNUSED(port);
    UNUSED(data);
    UNUSED(len);

    /* TODO: call BK3633 UART send function */
    return DL_STATUS_OK;
}

dl_status_t hal_uart_send_byte(hal_uart_port_t port, uint8_t byte)
{
    return hal_uart_send(port, &byte, 1u);
}
