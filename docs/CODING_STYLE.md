\# Coding Style – ARAIB Smart Lock Firmware



\## General



\- Language: C99

\- Indent: 4 spaces, no tabs.

\- Line length: target 100 columns.

\- Braces:

&nbsp; - Functions:

&nbsp;   ```c

&nbsp;   void foo(void)

&nbsp;   {

&nbsp;       ...

&nbsp;   }

&nbsp;   ```

&nbsp; - `if/else`, `while`, `for` always use braces, even for single statements.



\## Files \& Naming



\- File names: `module\_name.c/h`, all lowercase with underscores.

\- HAL: `hal\_gpio.c`, `hal\_uart.c`, `hal\_timer.c`, `hal\_pwm.c`.

\- Drivers: `fingerprint\_driver.c`, `keypad.c`, `lock\_motor.c`, `sensors.c`, `indicators.c`.

\- App: `lock\_app.c`, `ble\_lock\_service.c`, `user\_db.c`, `event\_log.c`.



\### Types



\- `typedef` enums end with `\_t` (e.g., `dl\_status\_t`).

\- Global structs: `dl\_...\_t`.



\### Functions



\- Prefix by layer:

&nbsp; - HAL: `hal\_gpio\_...`, `hal\_uart\_...`

&nbsp; - Drivers: `fp\_...`, `keypad\_...`, `lock\_motor\_...`

&nbsp; - App: `lock\_app\_...`, `ble\_lock\_...`, `user\_db\_...`

\- Functions and variables: `snake\_case`.



\### Constants \& Macros



\- Macros: `DL\_...` uppercase, e.g. `DL\_FP\_UART\_TX\_PIN`.

\- Enums: `DL\_...` upper snake case for values.



\### Comments



\- Use `//` for short comments, `/\* ... \*/` for block/API docs.

\- File header at top of each `.c`:



&nbsp; ```c

&nbsp; /\*\*

&nbsp;  \* @file    hal\_gpio.c

&nbsp;  \* @brief   GPIO abstraction for BK3633 smart lock board.

&nbsp;  \*/



