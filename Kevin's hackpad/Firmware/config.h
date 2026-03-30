#pragma once

#define MATRIX_ROWS 3
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { 2, 3, 4 }
#define MATRIX_COL_PINS { 5, 6, 7, 8 }

#define DIODE_DIRECTION COL2ROW

// Rotary Encoder
#define ENCODERS_PAD_A { 9 }
#define ENCODERS_PAD_B { 10 }
#define ENCODER_RESOLUTION 4

// OLED
#define OLED_DRIVER_ENABLE
#define OLED_DISPLAY_128X64
#define OLED_I2C_SCL_PIN 7
#define OLED_I2C_SDA_PIN 6
