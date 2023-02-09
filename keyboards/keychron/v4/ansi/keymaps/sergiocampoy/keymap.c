/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off
enum layers {
    MAC_BASE,
    WIN_BASE,
    _COLEMAK_DH,
    _FN1,
    _FN2,
    _FN3
};
// clang-format on

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

/* Custom arrow + modifier combos */
// clang-format off
#define S_U_SFT MT(MOD_RSFT, KC_UP)
#define S_L_FN  LT(_FN2    , KC_LEFT)
#define S_D_FN1 LT(_FN2    , KC_DOWN)
#define S_R_CTL RCTL_T(KC_RIGHT)
// clang-format on

/*
 * Home row mods (MOD TAP)
 * ASDF JKL;
 */
#define S_A_MOD MT(, KC_A)
#define S_S_MOD MT(, KC_S)
#define S_D_MOD MT(, KC_D)
#define S_F_MOD MT(, KC_F)

#define S_J_MOD MT(, KC_J)
#define S_K_MOD MT(, KC_K)
#define S_L_MOD MT(, KC_L)
#define S_C_MOD MT(, KC_SCLN)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Original MAC_BASE layer
    // [MAC_BASE] = LAYOUT_ansi_61(
    //     KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    //     KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    //     KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
    //     KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
    //     KC_LCTL, KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_RCTL),

    // Original WIN_BASE layer (setup as a backup)
    [MAC_BASE] = LAYOUT_ansi_61(
        //     ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,                   KC_RSFT,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC                            , KC_RALT,MO(_FN2),MO(_FN3), KC_RCTL),

    // Custom WIN_BASE layer
    [WIN_BASE] = LAYOUT_ansi_61(
        //     ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
        QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,          KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,                   S_U_SFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC                            , KC_RALT, S_L_FN , S_D_FN1, S_R_CTL),

    // MAC_BASE layer FN key (Currently unused)
    [_FN1] = LAYOUT_ansi_61(
        //     ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
        KC_GRV , KC_BRID, KC_BRIU, KC_NO  , KC_NO  , RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_MOD,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_INS , KC_PGUP, KC_HOME, _______,
        _______,RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP  , _______, KC_PGDN, KC_END ,          _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN,KC_RIGHT, KC_DEL ,                   _______,
        _______, _______, _______,                            _______                           , _______, _______, _______, _______),

    // WIN_BASE layer FN key
    [_FN2] = LAYOUT_ansi_61(
        //     ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
        KC_GRV , KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_MOD,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP , KC_SCRL, KC_INS , KC_HOME, KC_END , _______,
        _______,RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP  , KC_PSCR, KC_PGDN, KC_PGUP,          _______,
        _______, _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN,KC_RIGHT, KC_DEL ,                   _______,
        _______, _______, _______,                            _______                           , _______, _______, _______, _______),

    // FN2 key
    [_FN3] = LAYOUT_ansi_61(
        //     ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
        KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______,                            _______                           , _______, _______, _______, _______),
};
// clang-format on