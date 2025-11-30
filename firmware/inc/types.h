#ifndef TYPES_H
#define TYPES_H

#include "common.h"

/* Unlock source (FP, PIN, BLE) – used across app and logs */
typedef enum
{
    DL_UNLOCK_SRC_FINGERPRINT = 0,
    DL_UNLOCK_SRC_PIN,
    DL_UNLOCK_SRC_BLE,
} dl_unlock_source_t;

/* Door state */
typedef enum
{
    DL_DOOR_STATE_UNKNOWN = 0,
    DL_DOOR_STATE_OPEN,
    DL_DOOR_STATE_CLOSED,
} dl_door_state_t;

/* Lock state */
typedef enum
{
    DL_LOCK_STATE_UNKNOWN = 0,
    DL_LOCK_STATE_LOCKED,
    DL_LOCK_STATE_UNLOCKED,
    DL_LOCK_STATE_MOVING,
} dl_lock_state_t;

#endif /* TYPES_H */
