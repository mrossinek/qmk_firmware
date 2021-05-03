/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * |   =    |    1   |    2   |    3   |    4   |    5   |  Left  |                                          |  Right |    6   |    7   |    8   |    9   |    0   |   -    |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |   Del  |    Q   |    W   |    E   |    R   |    T   |   L1   |                                          |   L2   |    Y   |    U   |    I   |    O   |    P   |   \    |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |   Esc  |    A   |    S   |    D   |    F   |    G   |  Hyper |  <-  Do I really want to use these?  ->  |   Meh  |    H   |    J   |    K   |    L   |    ;   |   '    |
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * | LShift |    Z   |    X   |    C   |    V   |    B   |                                                            |    N   |    M   |    ,   |    .   |    /   | RShift |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |   `    |  Ctrl  |   Alt  |  Left  |  Right |         ,-----------------.                      ,-----------------.         |   Up   |  Down  |    [   |    ]   |  ~L1   |
 * `--------------------------------------------'         |       App (?)   |                      |       Esc       |         `--------------------------------------------'
 *            ^^^^^^^^^^^^^^^                             |--------+-----------------.    ,--------+-----------------|
 *         Maybe place - and = here instead               |        |        |        |    |        |        |        |
 *         Actually, place brackets here and move         | Space  | Back-  |  LGUI  |    |  RGUI  |  Tab   | Enter  |
 *         - and = over to the right (same in SYMB)       |        | space  |        |    |        |        |        |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[BASE] = LAYOUT_moonlander(
     KC_EQL , KC_1    , KC_2   , KC_3   , KC_4  ,  KC_5   , KC_LEFT,                                         KC_RGHT   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS ,
     KC_DEL , KC_Q    , KC_W   , KC_E   , KC_R  ,  KC_T   , TG(SYMB),                                        TG(MDIA)  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS ,
     KC_ESC , KC_A    , KC_S   , KC_D   , KC_F  ,  KC_G   , KC_HYPR ,                                        KC_MEH    , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT ,
     KC_LSFT, KC_Z    , KC_X   , KC_C   , KC_V  ,  KC_B   ,                                                              KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT ,
     KC_GRV , KC_LCTRL, KC_LALT, KC_LEFT, KC_RGHT,          KC_APP           ,                         KC_ESC         ,           KC_UP  , KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                                            KC_SPC  , KC_BSPC, KC_LGUI,     KC_RGUI ,  KC_TAB,  KC_ENT
),

/* Keymap 1: Symbol layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * | Escape |  F1    |  F2    |  F3    |  F4    |  F5    |        |                                          |        |  F6    |  F7    |  F8    |  F9    |  F10   |  F11   |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   !    |   @    |   {    |   }    |   |    |        |                                          |        |  Up    |   7    |   8    |   9    |   *    |  F12   |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   #    |   $    |   (    |   )    |   `    |        |                                          |        |  Down  |   4    |   5    |   6    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * |        |   %    |   ^    |   [    |   ]    |   ~    |                                                            |   &    |   1    |   2    |   3    |   \    |        |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |        |        |        |   <    |   >    |         ,-----------------.                      ,-----------------.         |   .    |   0    |   -    |   =    |        |
 * `--------------------------------------------'         | RGB Cycle Mod   |                      |   RGB Toggle    |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        | RGB    | RGB    | Toogle |    |  RGB   |  RGB   |  RGB   |
 *                                                        | Bright | Bright | -layer |    |  Stop  |  Hue   |  Hue   |
 *                                                        | Down   | Up     | -color |    |  Anim. |  Down  |  Up    |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[SYMB] = LAYOUT_moonlander(
     KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,                                                   _______   , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     _______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, _______,                                                   _______   , KC_UP  , KC_7   , KC_8   , KC_9   , KC_ASTR, KC_F12 ,
     _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV , _______,                                                   _______   , KC_DOWN, KC_4   , KC_5   , KC_6   , KC_PLUS, _______,
     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                                                        KC_AMPR, KC_1   , KC_2  ,  KC_3   , KC_BSLS, _______,
     _______, _______, _______, KC_LABK, KC_RABK,          RGB_MOD          ,                                 RGB_TOG         ,            KC_DOT , KC_0   , KC_MINS, KC_EQL , _______,
                                                           RGB_VAD , RGB_VAI, TOGGLE_LAYER_COLOR,    RGB_SLD, RGB_HUD, RGB_HUI
),

/* Keymap 2: Media layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * | AudTog |        |        |        |        |        |        |                                          |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * | MusTog |        |        | M. Up  |        |        |        |                                          |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * | MusMod |        | M. Left| M. Down| M.Right|        |        |                                          |        |        |        |        |        |        |PLAY TGL|
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                                                            |        |        | PL PREV| PL NEXT|        |        |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |        |        |        | M. Btn1| M. Btn2|         ,-----------------.                      ,-----------------.         | VOL UP |VOL DOWN|VOL MUTE|        |        |
 * `--------------------------------------------'         |                 |                      |                 |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        |        |        |        |    |        |        |  WWW   |
 *                                                        |        |        |        |    |        |        |  Back  |
 *                                                        |        |        |        |    |        |        |        |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[MDIA] = LAYOUT_moonlander(
     AU_TOG , _______, _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______, _______,  RESET ,
     MU_TOG , _______, _______, KC_MS_U, _______, _______, _______,                                                _______, _______, _______, _______, _______, _______, _______,
     MU_MOD , _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                                                _______, _______, _______, _______, _______, _______, KC_MPLY,
     _______, _______, _______, _______, _______, _______,                                                                  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
     _______, _______, _______, KC_BTN1, KC_BTN2,           _______         ,                        _______             ,           KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                                            _______, _______, _______,      _______, _______, KC_WWW_BACK
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
