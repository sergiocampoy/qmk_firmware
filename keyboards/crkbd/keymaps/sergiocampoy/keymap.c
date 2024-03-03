/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _LOL,
    _FACTORIO,
    _LEFT,
    _RIGHT,
    _SWITCH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak Mod-DH layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  s  |  d  |  f  |  g  |   |  h  |  j  |  k  |  l  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  v  |  b  |   |  n  |  m  |  ,  |  .  |  /  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 * Features:
 * Home Row Mods (GUI/ALT/CTL/SFT)
 * Space / Alt
 * Backspace / fn2
 */
[_QWERTY] = LAYOUT_split_3x6_3(
 KC_TAB,         KC_Q,         KC_W,         KC_E,         KC_R, KC_T, /**/ KC_Y,         KC_U,         KC_I,         KC_O,            KC_P, KC_BSPC,
KC_LCTL, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, /**/ KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
KC_LSFT,         KC_Z,         KC_X,         KC_C,         KC_V, KC_B, /**/ KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,  KC_ESC,

                                          KC_LGUI, MO(_LEFT), KC_SPLT, /**/ KC_ENT, LT(_RIGHT, KC_BSPC), KC_RALT
),

/* Colemak Mod-DH layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  f  |  p  |  b  |   |  j  |  l  |  u  |  y  |  ;  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  r  |  s  |  t  |  g  |   |  m  |  n  |  e  |  i  |  o  |  '  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  d  |  v  |   |  k  |  h  |  ,  |  .  |  /  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 * Features:
 * Home Row Mods (GUI/ALT/CTL/SFT)
 * Space / Alt
 * Backspace / fn2
 */
[_COLEMAK_DH] = LAYOUT_split_3x6_3(
 KC_TAB,         KC_Q,         KC_W,         KC_F,         KC_P, KC_B, /**/ KC_J,         KC_L,         KC_U,         KC_Y,      KC_SCLN, KC_BSPC,
KC_LCTL, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, /**/ KC_M, RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
KC_LSFT,         KC_Z,         KC_X,         KC_C,         KC_D, KC_V, /**/ KC_K,         KC_H,      KC_COMM,       KC_DOT,     KC_SLASH,  KC_ESC,

                                          KC_LGUI, MO(_LEFT), KC_SPLT, /**/ KC_ENT, MO(_RIGHT), KC_RALT
),

/* League of Legends layer
 * ,-----------------------------------.   ,-----------------------------------.
 * |  c  |  1  |  2  |  3  |  4  |  5  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  h  |  j  |  k  |  l  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  a  |  s  |  d  |  f  |  g  |   |  n  |  m  |  ,  |  .  |  /  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | ctl | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_LOL] = LAYOUT_split_3x6_3(
   KC_C, KC_1, KC_2, KC_3, KC_4, KC_5, /**/ KC_Y, KC_U,    KC_I,   KC_O,     KC_P, KC_BSPC,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_H, KC_J,    KC_K,   KC_L,  KC_SCLN, KC_QUOT,
KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH,  KC_ESC,

           KC_LCTL, MO(_LEFT), KC_SPC, /**/ KC_ENT,  MO(_RIGHT), KC_RALT
),

/* Factorio layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  s  |  d  |  f  |  g  |   |  h  |  j  |  k  |  l  |  ñ  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  v  |  b  |   |  n  |  m  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | alt | fn1 | spa |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_FACTORIO] = LAYOUT_split_3x6_3(
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U,    KC_I,   KC_O,     KC_P, KC_BSPC,
KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J,    KC_K,   KC_L,  KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH,  KC_ESC,

           KC_LALT, MO(_LEFT), KC_SPC, /**/ KC_ENT,MO(_RIGHT), KC_RALT
),

    [_LEFT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_SPLT,   KC_ENT,MO(_SWITCH),KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_RIGHT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,MO(_SWITCH),KC_SPLT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SWITCH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_QWER, KC_COLE,  KC_LOL, KC_FACT, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_SPLT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
