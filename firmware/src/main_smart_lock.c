#include "common.h"
#include "board_config.h"
#include "debug_log.h"
#include "types.h"

/**
 * Initialize smart lock application modules.
 * This will be called later from the SDK app init.
 */
void smart_lock_init(void)
{
    debug_log_init();
    LOG_INFO("Smart Lock firmware starting...");

    // TODO: init HAL, drivers, app state machine, etc.
}

/**
 * Optional periodic task; we can call this from a timer or main loop.
 */
void smart_lock_process(void)
{
    // TODO: handle state machine, events, etc.
}
