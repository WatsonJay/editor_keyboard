#include QMK_KEYBOARD_H
#define _LY0 0
#define _LY1 1
#define _LY2 2
#define _LY3 3
#define _RGB 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LY0] = LAYOUT(
        KC_MSTP, KC_MPLY, KC_0, TO(0), KC_RGHT,
		KC_ESC,  KC_MUTE, KC_1, KC_2, KC_3,
		KC_SLEP, KC_WAKE, KC_4, KC_5, KC_6,
		KC_LEFT, KC_ENT,  KC_7, KC_8, KC_9,
		KC_VOLD, KC_VOLU, KC_PGDN, KC_PGUP
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void keyboard_post_init_user(void) {
  debug_enable = true;
  debug_matrix = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = biton32(layer_state);
    if (index == 0) { /* First encoder */
        if (!clockwise) {
           register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 0
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 0
            }));
        } else {
           register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 1
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 1
            }));
        }
    } else if (index == 1) {
        if (!clockwise) {
           register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 2
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 2
            }));
        } else {
            register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 3
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 4, .col = 3
            }));
        }
    } else if (index == 2){
        if (!clockwise) {
            register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 0
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 3, .col = 0
            }));
        } else {
            register_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 0, .col = 4
            }));
           unregister_code(keymap_key_to_keycode(layer, (keypos_t) {.row = 0, .col = 4
            }));
        }
    }
    return true;
}
