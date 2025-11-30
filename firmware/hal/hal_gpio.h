#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "common.h"
#include "board_config.h"

/* Direction of a GPIO pin */
typedef enum
{
    HAL_GPIO_DIR_INPUT = 0,
    HAL_GPIO_DIR_OUTPUT
} hal_gpio_dir_t;

/* Pull configuration (adjust later to match BK3633 options) */
typedef enum
{
    HAL_GPIO_PULL_NONE = 0,
    HAL_GPIO_PULL_UP,
    HAL_GPIO_PULL_DOWN
} hal_gpio_pull_t;

/* Logical level */
typedef enum
{
    HAL_GPIO_LEVEL_LOW = 0,
    HAL_GPIO_LEVEL_HIGH
} hal_gpio_level_t;

/* Generic GPIO pin descriptor: (port, pin) pair as in board_config.h */
typedef struct
{
    uint8_t port;
    uint8_t pin;
} hal_gpio_t;

/* Initialize a GPIO pin */
dl_status_t hal_gpio_init(const hal_gpio_t *gpio,
                          hal_gpio_dir_t dir,
                          hal_gpio_pull_t pull,
                          hal_gpio_level_t initial_level);

/* Write / read helpers */
void          hal_gpio_write(const hal_gpio_t *gpio, hal_gpio_level_t level);
hal_gpio_level_t hal_gpio_read(const hal_gpio_t *gpio);
void          hal_gpio_toggle(const hal_gpio_t *gpio);

/* Convenience macros to build hal_gpio_t from board_config.h defines */
#define HAL_GPIO(port, pin)   ((hal_gpio_t){ (uint8_t)(port), (uint8_t)(pin) })

#endif /* HAL_GPIO_H */
