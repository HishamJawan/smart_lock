# Smart Lock – BK3633 Pinout

## UART – Fingerprint (HLK-ZW0623)

- TX: P00  (DL_FP_UART_TX)
- RX: P01  (DL_FP_UART_RX)

## Motor / Relay Output

- LOCK_MOTOR_OUT: P10   (drives H-bridge/relay)

## Keypad (example 3x4)

- ROW0: P20
- ROW1: P21
- ROW2: P22
- ROW3: P23

- COL0: P24
- COL1: P25
- COL2: P26

## Sensors

- DOOR_SENSOR: P30
- LOCK_SENSOR: P31

## Indicators

- LED_STATUS: P40
- BUZZER:     P41 (PWM capable)

## Debug Interface

- DEBUG_UART_TX: P05
- DEBUG_UART_RX: P06
  - Baud: 115200 8N1
