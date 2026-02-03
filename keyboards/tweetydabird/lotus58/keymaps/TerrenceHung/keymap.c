// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MPLY,             KC_MUTE, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
        KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,             KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                     KC_LGUI, KC_LALT, MO(1),   KC_SPC,              KC_ENT,  MO(2),   KC_BSPC, KC_RALT
    ),

    [1] = LAYOUT(
        KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,             RGB_TOG, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        LALT(KC_GRV), KC_1, KC_2,  KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
        KC_CAPS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3),LSFT(KC_4), LSFT(KC_5),                   LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
        CW_TOGG, _______, _______, _______, _______, _______, KC_INS,                KC_SCRL, _______, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), _______,
                                   _______, _______, _______, _______,               _______, TG(3),   KC_DEL,  _______
    ),

    [2] = LAYOUT(
        LSFT(KC_GRV), _______, _______, _______, _______, _______, _______,          _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
        _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______,                                 _______, _______, KC_UP,   _______, _______, _______,
        _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______,                                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, KC_INS,                KC_SCRL, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,               _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        TG(3),   _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
        _______, _______, TO(4),   _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
        _______, TO(5),   _______, _______, _______, _______,                                 QK_LOCK, _______, _______, _______, _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, QK_BOOT,
                                   _______, _______, _______, _______,               _______, TG(3),   _______, _______
    ),

    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, TG(4),                 _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, KC_SPC,  KC_SPC,                _______, _______, _______, _______
    ),

    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_UP,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,               _______, TG(5),   _______, _______
    ),
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_LOCK:
            if (!record->event.pressed) {
                layer_invert(3);
            }
            break;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

#ifdef OLED_ENABLE
static void print_status_narrow(void) {
    oled_clear();
    if (get_highest_layer(layer_state) < 3) {
        // Create OLED content
        oled_write_ln_P(PSTR("Lotus -58-"), false);
        oled_write_ln_P(PSTR(""), false);

        // Print current layer
        oled_write_P(PSTR("Layer"), false);
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_ln_P(PSTR("-Base"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("-Smbl"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("-Nav "), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undef"), false);
        }

        oled_write_ln_P(PSTR(""), false);
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR("Caps- lock"), led_usb_state.caps_lock);
        oled_write_ln_P(PSTR("Caps- word"), is_caps_word_on());
    } else {
        oled_write_ln_P(PSTR("Game"), false);
        oled_write_ln_P(PSTR("Layer"), false);
        oled_write_ln_P(PSTR(""), false);

        switch (get_highest_layer(layer_state)) {
            case 3:
                oled_write_ln_P(PSTR("W"), false);
                oled_write_ln_P(PSTR("WASD"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("A"), false);
                oled_write_ln_P(PSTR("ArrowKeys"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("H"), false);
                oled_write_ln_P(PSTR("Hold"), false);
                break;
            case 4:
                oled_write_ln_P(PSTR("WASD"), false);
                break;
            case 5:
                oled_write_ln_P(PSTR("ArrowKeys"), false);
                break;
        }
    }
}

bool oled_task_user(void) {
    // Render the OLED
    print_status_narrow();
    return false;
}

#endif
