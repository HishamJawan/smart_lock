#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

/* ========= Fingerprint UART (HLK-ZW0623) ========= */
/* From earlier decision: P00 = TX, P01 = RX  */
#define DL_FP_UART_TX_PORT      0
#define DL_FP_UART_TX_PIN       0   // P00
#define DL_FP_UART_RX_PORT      0
#define DL_FP_UART_RX_PIN       1   // P01

/* ========= Motor / Relay ========= */
#define DL_LOCK_MOTOR_PORT      1
#define DL_LOCK_MOTOR_PIN       0   // P10

/* ========= Keypad (3x4 example) ========= */
#define DL_KP_ROW0_PORT         2
#define DL_KP_ROW0_PIN          0   // P20
#define DL_KP_ROW1_PORT         2
#define DL_KP_ROW1_PIN          1   // P21
#define DL_KP_ROW2_PORT         2
#define DL_KP_ROW2_PIN          2   // P22
#define DL_KP_ROW3_PORT         2
#define DL_KP_ROW3_PIN          3   // P23

#define DL_KP_COL0_PORT         2
#define DL_KP_COL0_PIN          4   // P24
#define DL_KP_COL1_PORT         2
#define DL_KP_COL1_PIN          5   // P25
#define DL_KP_COL2_PORT         2
#define DL_KP_COL2_PIN          6   // P26

/* ========= Sensors ========= */
#define DL_DOOR_SENSOR_PORT     3
#define DL_DOOR_SENSOR_PIN      0   // P30
#define DL_LOCK_SENSOR_PORT     3
#define DL_LOCK_SENSOR_PIN      1   // P31

/* ========= Indicators ========= */
#define DL_LED_STATUS_PORT      4
#define DL_LED_STATUS_PIN       0   // P40
#define DL_BUZZER_PORT          4
#define DL_BUZZER_PIN           1   // P41

/* ========= Debug UART ========= */
#define DL_DEBUG_UART_TX_PORT   0
#define DL_DEBUG_UART_TX_PIN    5   // P05
#define DL_DEBUG_UART_RX_PORT   0
#define DL_DEBUG_UART_RX_PIN    6   // P06

#endif /* BOARD_CONFIG_H */
