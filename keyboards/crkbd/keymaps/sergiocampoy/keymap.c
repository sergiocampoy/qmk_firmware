#include QMK_KEYBOARD_H
#include <stdio.h>

// Tap Dance declarations
enum {
    TD_MO_SPACE,
    TD_MO_ENTER
};

// Layer declarations
enum layers {
    _COLEMAK_DH, // Colemak-DH layer
    _SYMBOL,     // Symbol/Number layer
    _FUNCTION,   // Function/Navigation layer
    _HUB,        // Layer for navigating other layers
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap to use space, hold to activate Symbol layer
    [TD_MO_SPACE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_SPACE, _SYMBOL),

    // Tap to use enter, hold to activate Function layer
    [TD_MO_ENTER] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ENTER, _FUNCTION),
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *    |-Colemak-DH Layer-------------------------------------------------|
 *    |  Q  |  W  |  F  |  P  |  B  |      |  J  |  L  |  U  |  Y  |  ;  |
 *    |  A  |  R  |  S  |  T  |  G  |      |  M  |  N  |  E  |  I  |  O  |
 *    |  Z  |  X  |  C  |  D  |  V  |      |  K  |  H  |  ,  |  .  |  /  |
 *    |-Alternate Bot---| SPC | ESC |      | DEL | RET |-----------------|
 *                      |-----------|      |-----------|
 * SPC & RET act as layer modifiers when held
 */
[_COLEMAK_DH] = LAYOUT_split_3x6_3(
KC_NO,       KC_Q,        KC_W,       KC_F,       KC_P,  KC_B,   KC_J,       KC_L,        KC_U,        KC_Y,        KC_SCLN, KC_NO,
KC_NO,RGUI_T(KC_A),LALT_T(KC_R),CTL_T(KC_S),SFT_T(KC_T), KC_G,   KC_M,RSFT_T(KC_N),RCTL_T(KC_E),RALT_T(KC_I),RGUI_T(KC_O),   KC_NO,
KC_NO,       KC_Z,        KC_X,       KC_C,       KC_D,  KC_V,   KC_K,       KC_H,        KC_COMM,     KC_DOT,      KC_SLSH, KC_NO,

// KC_NO, MO(_SYMBOL), KC_SPACE,   KC_RETURN, MO(_FUNCTION), KC_NO
KC_NO, TD(TD_MO_SPACE), KC_ESC,   KC_BSPC, TD(TD_MO_ENTER), KC_NO
),

/*
 *    |-Symbol Layer-----------------------------------------------------|
 *    |  1  |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |  0  |
 *    |  '  |  \  |  (  |  )  |  -  |      |  +  |  {  |  }  |  _  |  =  |
 *    |  !  |  @  |  #  |  $  |  %  |      |  ^  |  [  |  ]  |  &  |  *  |
 *    |-----------------| SPC | ESC |      | DEL | RET |-----------------|
 *                      |-----------|      |-----------|
 * SPC & RET act as layer modifiers when held
 */
[_SYMBOL] = LAYOUT_split_3x6_3(
KC_NO,       KC_1,        KC_2,       KC_3,       KC_4,  KC_5,   KC_6,       KC_7,        KC_8,        KC_9,        KC_0,    KC_NO,
KC_NO,RGUI_T(KC_A),LALT_T(KC_R),CTL_T(KC_S),SFT_T(KC_T), KC_G,   KC_M,RSFT_T(KC_N),RCTL_T(KC_E),RALT_T(KC_I),RGUI_T(KC_O),   KC_NO,
KC_NO,       KC_Z,        KC_X,       KC_C,       KC_D,  KC_V,   KC_K,       KC_H,        KC_COMM,     KC_DOT,      KC_SLSH, KC_NO,

// KC_NO, MO(_SYMBOL), KC_SPACE,   KC_RETURN, MO(_FUNCTION), KC_NO
KC_NO, TD(TD_MO_SPACE), KC_ESC,   KC_BSPC, TD(TD_MO_ENTER), KC_NO
)
};