#ifndef HAL_UART_H
#define HAL_UART_H

#include "common.h"

/* Logical UART ports for our firmware */
typedef enum
{
    HAL_UART_PORT_DEBUG = 0,
    HAL_UART_PORT_FP,          /* Fingerprint module */
    HAL_UART_PORT_MAX
} hal_uart_port_t;

/* UART configuration */
typedef struct
{
    uint32_t baudrate;
    bool     hw_flow_ctrl;     /* CTS/RTS if used */
} hal_uart_config_t;

/* Initialize a UART port */
dl_status_t hal_uart_init(hal_uart_port_t port, const hal_uart_config_t *cfg);

/* Blocking send (simple for now) */
dl_status_t hal_uart_send(hal_uart_port_t port, const uint8_t *data, uint16_t len);

/* Optional helpers */
dl_status_t hal_uart_send_byte(hal_uart_port_t port, uint8_t byte);

#endif /* HAL_UART_H */
