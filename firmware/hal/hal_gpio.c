#include "hal_gpio.h"
#include "debug_log.h"

/* SDK GPIO driver */
#include "gpio.h"   /* from SDK driver: provides gpio_config, gpio_set, gpio_get_input, gpio_set_neg */

/* Convert our HAL direction enum to SDK Dir_Type */
static Dir_Type hal_to_sdk_dir(hal_gpio_dir_t dir)
{
    switch (dir)
    {
        case HAL_GPIO_DIR_INPUT:
            return INPUT;    /* SDK enum */
        case HAL_GPIO_DIR_OUTPUT:
            return OUTPUT;   /* SDK enum */
        case HAL_GPIO_DIR_FLOAT:
            return FLOAT;    /* SDK enum */
        case HAL_GPIO_DIR_ALT_FUNC:
        default:
            return SC_FUN;   /* SDK enum */
    }
}

/* Convert our HAL pull enum to SDK Pull_Type */
static Pull_Type hal_to_sdk_pull(hal_gpio_pull_t pull)
{
    switch (pull)
    {
        case HAL_GPIO_PULL_UP:
            return PULL_HIGH;
        case HAL_GPIO_PULL_DOWN:
            return PULL_LOW;
        case HAL_GPIO_PULL_NONE:
        default:
            return PULL_NONE;
    }
}

/* Helper: convert (port, pin) to SDK's single gpio index (0xXY) */
static uint8_t hal_gpio_to_index(const hal_gpio_t *gpio)
{
    return (uint8_t)((gpio->port << 4) | (gpio->pin & 0x0F));
}

/* Internal config helper */
static void hal_gpio_hw_config(const hal_gpio_t *gpio,
                               hal_gpio_dir_t dir,
                               hal_gpio_pull_t pull,
                               hal_gpio_level_t initial_level)
{
    uint8_t gpio_idx = hal_gpio_to_index(gpio);

    /* Configure direction & pull using SDK function */
    gpio_config(gpio_idx, hal_to_sdk_dir(dir), hal_to_sdk_pull(pull));

    /* If output, set initial level */
    if (dir == HAL_GPIO_DIR_OUTPUT)
    {
        gpio_set(gpio_idx, (initial_level == HAL_GPIO_LEVEL_HIGH) ? 1 : 0);
    }
}

dl_status_t hal_gpio_init(const hal_gpio_t *gpio,
                          hal_gpio_dir_t dir,
                          hal_gpio_pull_t pull,
                          hal_gpio_level_t initial_level)
{
    if (gpio == NULL)
    {
        return DL_STATUS_INVALID_PARAM;
    }

    hal_gpio_hw_config(gpio, dir, pull, initial_level);
    return DL_STATUS_OK;
}

void hal_gpio_write(const hal_gpio_t *gpio, hal_gpio_level_t level)
{
    if (gpio == NULL)
    {
        return;
    }

    uint8_t gpio_idx = hal_gpio_to_index(gpio);
    gpio_set(gpio_idx, (level == HAL_GPIO_LEVEL_HIGH) ? 1 : 0);
}

hal_gpio_level_t hal_gpio_read(const hal_gpio_t *gpio)
{
    if (gpio == NULL)
    {
        return HAL_GPIO_LEVEL_LOW;
    }

    uint8_t gpio_idx = hal_gpio_to_index(gpio);
    uint8_t val = gpio_get_input(gpio_idx);

    return (val ? HAL_GPIO_LEVEL_HIGH : HAL_GPIO_LEVEL_LOW);
}

void hal_gpio_toggle(const hal_gpio_t *gpio)
{
    if (gpio == NULL)
    {
        return;
    }

    uint8_t gpio_idx = hal_gpio_to_index(gpio);
    gpio_set_neg(gpio_idx);
}
