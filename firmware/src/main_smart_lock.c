#include "common.h"
#include "board_config.h"
#include "debug_log.h"
#include "hal_gpio.h"
#include "hal_timer.h"
#include "types.h"
#include "uart.h"
#include "gpio.h"      // SDK GPIO driver

static hal_gpio_t s_led;
static uint32_t   s_blink_counter = 0;

void lock_app_init(void)
{
    uart_printf("lock_app_init() called\r\n");

    // Force LED pin HIGH using SDK directly
    uint8_t led_idx = (DL_LED_STATUS_PORT << 4) | (DL_LED_STATUS_PIN & 0x0F);
    gpio_config(led_idx, OUTPUT, PULL_NONE);
    gpio_set(led_idx, 1);
    uart_printf("LED pin 0x%02X configured and set HIGH\r\n", led_idx);

    debug_log_init();
    LOG_INFO("Smart Lock app init...");

    s_led = HAL_GPIO(DL_LED_STATUS_PORT, DL_LED_STATUS_PIN);

    hal_gpio_init(&s_led,
                  HAL_GPIO_DIR_OUTPUT,
                  HAL_GPIO_PULL_NONE,
                  HAL_GPIO_LEVEL_HIGH);
}

void lock_app_process(void)
{
    static uint32_t loop_cnt = 0;
    loop_cnt++;
    if ((loop_cnt % 2000u) == 0u)
    {
        uart_printf("lock_app_process() heartbeat, loop_cnt=%u\r\n", (unsigned)loop_cnt);
    }

    s_blink_counter++;
    if (s_blink_counter >= 20)
    {
        s_blink_counter = 0;
        hal_gpio_toggle(&s_led);
        LOG_INFO("LED toggled");
    }
}
