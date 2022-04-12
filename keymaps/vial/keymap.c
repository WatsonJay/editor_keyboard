#include QMK_KEYBOARD_H
// #include "print.h"
#define _LY0 0
#define _LY1 1
#define _LY2 2
// #define _LY3 3
#define _SET 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LY0] = LAYOUT(
        KC_MSTP, KC_MPLY, KC_0, TO(1), _______,
		KC_ESC,  KC_MUTE, KC_1, KC_2, KC_3,
		KC_WH_U, KC_WH_D, KC_4, KC_5, KC_6,
		_______, KC_ENT,  KC_7, KC_8, KC_9,
		_______, _______, _______, _______
    ),
    [_LY1] = LAYOUT(
        _______, _______, _______, TO(2), _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______
    ),
    [_LY2] = LAYOUT(
        _______, _______, _______, TO(3), _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______
    ),
    [_SET] = LAYOUT(
        _______, _______, _______, TO(0), _______,
		_______,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
		_______, _______,  _______, _______, _______,
		_______, _______, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

bool oled_task_user(void) {
    return false;
}
#endif
