/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "config.h"
#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q        , KC_W        , KC_E        , KC_R        , KC_T       ,                          KC_Y         , KC_U        , KC_I        , KC_O        , KC_P           ,
    LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G       ,                          KC_H         , RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
    KC_Z        , KC_X        , KC_C        , KC_V        , KC_B       ,                          KC_N         , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH        ,
    KC_NO       , KC_NO       , KC_NO       ,LT(3,KC_TAB) ,LT(1,KC_SPC),LT(4,KC_ESC),LT(2,KC_ENT),LT(2,KC_BSPC), KC_NO       , KC_NO       , KC_NO       , KC_NO
  ),

  [1] = LAYOUT_universal(
    KC_F12   , KC_F7    , KC_F8    , KC_F9    , KC_NO    ,                            KC_NO    , S(KC_1)  , S(KC_2)  , S(KC_7)  , KC_PSCR    ,
    KC_F11   , KC_F4    , KC_F5    , KC_F6    , KC_DEL   ,                            S(KC_6)  , KC_BTN1  , KC_BTN2  , S(KC_4)  , S(KC_BSLS) ,
    KC_F10   , KC_F1    , KC_F2    , KC_F3    , KC_NO    ,                            KC_NO    , S(KC_8)  , KC_BTN3  , S(KC_5)  , KC_BSLS    ,
    KC_NO    , KC_NO    , KC_NO    , _______  , _______  , _______  ,      _______  , _______  , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),

  [2] = LAYOUT_universal(
    KC_MINS  , KC_7     , KC_8     , KC_9     , KC_SLSH  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_0     , KC_4     , KC_5     , KC_6     , KC_DOT   ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_NO    ,
    S(KC_EQL), KC_1     , KC_2     , KC_3     , S(KC_8)  ,                            KC_NO    , KC_F13   , KC_F14   , KC_F15   , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , _______  , _______  , _______  ,      _______  , _______  , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),

  [3] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_PSCR  ,
    KC_LGUI  , KC_LALT  , KC_LSFT  , KC_LCTL  , KC_NO    ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_MPLY  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_MPRV  , KC_VOLD  , KC_VOLU  , KC_MNXT  , KC_MUTE  ,
    KC_NO    , KC_NO    , KC_NO    , _______  , _______  , _______  ,      _______  , _______  , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),

  [4] = LAYOUT_universal(
    KC_NO    , AML_TO   , KC_NO    , KC_NO    , KC_NO    ,                            QK_BOOT  , KC_NO    , KC_NO    , KC_NO    , RGB_TOG  ,
    KC_NO    , AML_I50  , CPI_I100 , SCRL_DVI , KC_NO    ,                            KC_NO    , RGB_VAI  , RGB_SAI  , RGB_HUI  , RGB_MOD  ,
    KC_NO    , AML_D50  , CPI_D100 , SCRL_DVD , KC_NO    ,                            KC_NO    , RGB_VAD  , RGB_SAD  , RGB_HUD  , RGB_RMOD ,
    KC_NO    , KC_NO    , KC_NO    , _______  , _______  , _______  ,      _______  , _______  , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);
  // Auto enable scroll mode when the highest layer is 3
  keyball_set_scroll_mode(layer == AUTO_DARG_ON_LAYER);

  // switch (layer) {
  // case 1:
  //   keyball_set_cpi(SNIPING_CPI / 100);
  //   break;
  // case 3:
  //   // Scrolling is active, but we'll set CPI to normal as a baseline.
  //   keyball_set_cpi(SNIPING_CPI / 100);
  //   break;
  // default:
  //   // Double the CPI for all other layers.
  //   keyball_set_cpi((NORMAL_CPI) / 100);
  //   break;
  // }
  return state;
}

const uint16_t PROGMEM copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cut[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM minus[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM plus[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM equal[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lpar[] = {LSFT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM rpar[] = {RCTL_T(KC_J), RSFT_T(KC_K), COMBO_END};
const uint16_t PROGMEM lsbrc[] = {LALT_T(KC_S), LSFT_T(KC_D), COMBO_END};
const uint16_t PROGMEM rsbrc[] = {RSFT_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM lcbrc[] = {LALT_T(KC_S), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM rcbrc[] = {RCTL_T(KC_J), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM dqt[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM sqt[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM under[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM tilde[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM hash[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM grv[] = {KC_E, KC_R, COMBO_END};
#if SYSTEM_OS == 0
combo_t key_combos[] = {
    COMBO(copy, LGUI(KC_C)),     COMBO(cut, LGUI(KC_X)),
    COMBO(paste, LGUI(KC_V)),    COMBO(minus, KC_MINS),
    COMBO(plus, LSFT(KC_EQL)),   COMBO(equal, KC_EQL),
    COMBO(lpar, LSFT(KC_9)),     COMBO(rpar, LSFT(KC_0)),
    COMBO(lsbrc, KC_LBRC),       COMBO(rsbrc, KC_RBRC),
    COMBO(lcbrc, LSFT(KC_LBRC)), COMBO(rcbrc, LSFT(KC_RBRC)),
    COMBO(dqt, LSFT(KC_QUOT)),   COMBO(sqt, KC_QUOT),
    COMBO(under, LSFT(KC_MINS)), COMBO(tilde, LSFT(KC_GRV)),
    COMBO(hash, LSFT(KC_3)),     COMBO(grv, KC_GRV),
};
#else
combo_t key_combos[] = {
    COMBO(copy, LCTL(KC_C)),     COMBO(cut, LCTL(KC_X)),
    COMBO(paste, LCTL(KC_V)),    COMBO(minus, KC_MINS),
    COMBO(plus, LSFT(KC_EQL)),   COMBO(equal, KC_EQL),
    COMBO(lpar, LSFT(KC_9)),     COMBO(rpar, LSFT(KC_0)),
    COMBO(lsbrc, KC_LBRC),       COMBO(rsbrc, KC_RBRC),
    COMBO(lcbrc, LSFT(KC_LBRC)), COMBO(rcbrc, LSFT(KC_RBRC)),
    COMBO(dqt, LSFT(KC_QUOT)),   COMBO(sqt, KC_QUOT),
    COMBO(under, LSFT(KC_MINS)), COMBO(tilde, LSFT(KC_GRV)),
    COMBO(hash, LSFT(KC_3)),     COMBO(grv, KC_GRV),
};
#endif

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT(2, KC_BSPC):
  case LT(1, KC_SPC):
    return QUICK_TAP_TERM - 80;
  default:
    return QUICK_TAP_TERM;
  }
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif
