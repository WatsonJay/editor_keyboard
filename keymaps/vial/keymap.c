#include QMK_KEYBOARD_H
// #include "print.h"
#define _LY0 0
#define _LY1 1
#define _LY2 2
// #define _LY3 3
#define _SET 3

uint16_t type_count = 0 ;

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
    type_count = 0;
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        type_count ++;
    }
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

static void render_info(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _LY0:
            oled_write_ln_P(PSTR("layer1"), false);
            break;
        case _LY1:
            oled_write_ln_P(PSTR("layer2"), false);
            break;
        case _LY2:
            oled_write_ln_P(PSTR("layer3"), false);
            break;
        case _SET:
            oled_write_ln_P(PSTR("layer4(set)"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

static void render_timer(void) {
    uint32_t uptime_millsec = timer_read32 ();
    uint32_t uptime_sec = uptime_millsec / 1000 ;
    char string[8];
    string[7] = '0' + uptime_sec % 10;
    string[6] = (uptime_sec /= 10) % 6 ? '0' + (uptime_sec) % 6 : '0';
    string[5] = ':';
    string[4] = (uptime_sec /= 60) % 10 ? '0' + (uptime_sec) % 10 : '0';
    string[3] = (uptime_sec /= 600) % 6 ? '0' + (uptime_sec) % 6 : '0';
    string[2] = ':';
    string[1] = (uptime_sec /= 3600) % 10 ? '0' + (uptime_sec) % 10 : '0';
    string[0] = (uptime_sec /= 36000) % 6 ? '0' + (uptime_sec) % 6 : '0';
    oled_write_P(PSTR("onTime: "), false);
    oled_write(string, false);
    oled_write_ln_P(PSTR(" "), false);
}

static void render_count(void) {
    oled_write_P(PSTR("tapcount: "), false);
    oled_write(get_u8_str(type_count, ' '), false);
    oled_write_ln_P(PSTR(" "), false);
}

bool oled_task_user(void) {
    render_info();
    render_timer();
    render_count();
    return false;
}
#endif
