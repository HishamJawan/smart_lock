#include "hal_gpio.h"
#include "debug_log.h"

/*
 * NOTE:
 *  - For now, these functions are mostly skeletons.
 *  - Later you will replace the TODO sections with actual BK3633 SDK calls.
 */

static void hal_gpio_hw_config(const hal_gpio_t *gpio,
                               hal_gpio_dir_t dir,
                               hal_gpio_pull_t pull,
                               hal_gpio_level_t initial_level)
{
    UNUSED(gpio);
    UNUSED(dir);
    UNUSED(pull);
    UNUSED(initial_level);

    /* TODO: Use BK3633 SDK GPIO driver here.
     *
     * Example pattern (NOT real API names):
     *   bk_gpio_config_t cfg = { ... };
     *   bk_gpio_init(gpio->port, gpio->pin, &cfg);
     */
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
    UNUSED(gpio);
    UNUSED(level);

    /* TODO: call BK3633 GPIO write function */
}

hal_gpio_level_t hal_gpio_read(const hal_gpio_t *gpio)
{
    UNUSED(gpio);

    /* TODO: call BK3633 GPIO read function and return HIGH/LOW */
    return HAL_GPIO_LEVEL_LOW;
}

void hal_gpio_toggle(const hal_gpio_t *gpio)
{
    UNUSED(gpio);

    /* TODO: read, invert, and write back using BK3633 driver */
}
