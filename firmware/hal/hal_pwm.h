#ifndef HAL_PWM_H
#define HAL_PWM_H

#include "common.h"

typedef enum
{
    HAL_PWM_CHANNEL_BUZZER = 0,
    HAL_PWM_CHANNEL_MAX
} hal_pwm_channel_t;

typedef struct
{
    uint32_t frequency_hz;
    float    duty_cycle;   /* 0.0f .. 1.0f */
} hal_pwm_config_t;

dl_status_t hal_pwm_init(hal_pwm_channel_t ch, const hal_pwm_config_t *cfg);
dl_status_t hal_pwm_set_duty(hal_pwm_channel_t ch, float duty);

#endif /* HAL_PWM_H */
