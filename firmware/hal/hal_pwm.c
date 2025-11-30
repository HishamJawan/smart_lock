#include "hal_pwm.h"
#include "board_config.h"
#include "debug_log.h"

dl_status_t hal_pwm_init(hal_pwm_channel_t ch, const hal_pwm_config_t *cfg)
{
    UNUSED(ch);
    UNUSED(cfg);

    /* TODO: map to BK3633 PWM/timer peripheral and configure pins. */
    return DL_STATUS_OK;
}

dl_status_t hal_pwm_set_duty(hal_pwm_channel_t ch, float duty)
{
    UNUSED(ch);
    UNUSED(duty);

    /* TODO: write duty cycle to BK3633 PWM channel. */
    return DL_STATUS_OK;
}
