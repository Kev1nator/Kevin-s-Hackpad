#include QMK_KEYBOARD_H
#include <time.h>

// Layer Definition
enum layers {
    _BASE,
};

// Custom Keycodes
enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
    BROWSER,
    SHUTDOWN,
};

// Keymap: 3x4 Matrix
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        COPY,    PASTE,   BROWSER, SHUTDOWN,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[9];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    oled_write_ln(buffer, false);
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case COPY: tap_code16(C(KC_C)); break;
        case PASTE: tap_code16(C(KC_V)); break;
        case BROWSER: tap_code16(G(KC_B)); break;
        case SHUTDOWN: tap_code16(LALT(KC_F4)); break;
    }
    return true;
}
