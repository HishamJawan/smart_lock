#include "hal_timer.h"
#include "debug_log.h"

/*
 * NOTE:
 *  - For now we can implement these using whatever delay the BK3633 SDK exposes,
 *    or leave them as TODOs if no obvious function exists yet.
 */

void hal_delay_ms(uint32_t ms)
{
    UNUSED(ms);

    /* TODO: call BK3633 OS/timer delay (e.g. rtos_delay_milliseconds)
     * or a busy-wait loop if nothing else is available.
     */
}

void hal_delay_us(uint32_t us)
{
    UNUSED(us);

    /* TODO: fine-grained delay if needed. */
}
