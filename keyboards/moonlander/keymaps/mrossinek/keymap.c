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
    UNIC,  // unicode
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    S_TRUE,
    S_FALSE,
};

enum unicode_names {
    ANGEL,
    CONFUSED,
    FLUSHED,
    GRIM,
    HEART,
    JOY,
    KISS,
    LUCK,
    MUSCLE,
    NO_EVIL,
    PARTY,
    POOP,
    SCREAM,
    SHRUG,
    SLEEP,
    SMILE,
    SWEAT,
    TADA,
    THINK,
    THUMBSDN,
    THUMBSUP,
    TONGUE,
    UNAMUSED,
    UPSIDEDN,
    WINK,
    YUMMY,
};

const uint32_t PROGMEM unicode_map[] = {
    [ANGEL]    = 0x1F607, // 😇
    [CONFUSED] = 0x1F615, // 😕
    [FLUSHED]  = 0x1F633, // 😳
    [GRIM]     = 0x1F62C, // 😬
    [HEART]    = 0x1F970, // 🥰
    [JOY]      = 0x1F602, // 😂
    [KISS]     = 0x1F618, // 😘
    [LUCK]     = 0x1F340, // 🍀
    [MUSCLE]   = 0x1F4AA, // 💪
    [NO_EVIL]  = 0x1F648, // 🙈
    [PARTY]    = 0x1F973, // 🥳
    [POOP]     = 0x1F4A9, // 💩
    [SCREAM]   = 0x1F631, // 😱
    [SHRUG]    = 0x1F937, // 🤷
    [SLEEP]    = 0x1F634, // 😴
    [SMILE]    = 0x1F642, // 🙂
    [SWEAT]    = 0x1F605, // 😅
    [TADA]     = 0x1F389, // 🎉
    [THINK]    = 0x1F914, // 🤔
    [THUMBSDN] = 0x1F44E, // 👎
    [THUMBSUP] = 0x1F44D, // 👍
    [TONGUE]   = 0x1F61C, // 😜
    [UNAMUSED] = 0x1F612, // 😒
    [UPSIDEDN] = 0x1F643, // 🙃
    [WINK]     = 0x1F609, // 😉
    [YUMMY]    = 0x1F60B, // 😋
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * |  Hyper |    1   |    2   |    3   |    4   |    5   |   L3   |                                          |PrScreen|    6   |    7   |    8   |    9   |    0   |  Meh   |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |    `   |    Q   |    W   |    E   |    R   |    T   |  Del   |                                          | Insert |    Y   |    U   |    I   |    O   |    P   |   '    |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |   Tab  |    A   |    S   |    D   |    F   |    G   | PgDown |                                          |  PgUp  |    H   |    J   |    K   |    L   |    ;   | \/RAlt |
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * | LShift |    Z   |    X   |    C   |    V   |    B   |                                                            |    N   |    M   |    ,   |    .   |    /   | RShift |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * | LCtrl  |    [   |    ]   |  Left  |  Right |         ,-----------------.                      ,-----------------.         |   Up   |  Down  |    -   |    =   | RCtrl  |
 * `--------------------------------------------'         |       L2        |                      |       L4        |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        |        |        |        |    |        |        |        |
 *                                                        | Space  | Back-  |  LGUI  |    |  LAlt  |  Esc   | Enter  |
 *                                                        |        | space  |        |    |        |        |        |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[BASE] = LAYOUT_moonlander(
     KC_HYPR , KC_1   , KC_2   , KC_3   , KC_4  ,  KC_5   , TG(MDIA),                                        KC_PSCR, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MEH  ,
     KC_GRV  , KC_Q   , KC_W   , KC_E   , KC_R  ,  KC_T   , KC_DEL ,                                         KC_INS , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUOT ,
     KC_TAB  , KC_A   , KC_S   , KC_D   , KC_F  ,  KC_G   , KC_PGDN,                                         KC_PGUP, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, RALT_T(KC_BSLS),
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V  ,  KC_B   ,                                                           KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT ,
     KC_LCTRL, KC_LBRC, KC_RBRC, KC_LEFT, KC_RGHT,          OSL(SYMB)       ,                       OSL(UNIC)     ,            KC_UP  , KC_DOWN, KC_MINS, KC_EQL , KC_RCTRL,
                                                            KC_SPC , KC_BSPC, KC_LGUI,     KC_LALT, KC_ESC, KC_ENT
),

/* Keymap 1: Symbol layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * |  F12   |  F1    |  F2    |  F3    |  F4    |  F5    |        |                                          |        |  F6    |  F7    |  F8    |  F9    |  F10   |  F11   |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   !    |   ?    |   {    |   }    |   |    |        |                                          |        |   ^    |   7    |   8    |   9    |   *    |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   #    |   $    |   (    |   )    |   _    |        |                                          |        |   ~    |   4    |   5    |   6    |   +    |        |
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * |        |   @    |   &    |   [    |   ]    |   %    |                                                            |   "    |   1    |   2    |   3    |   /    |        |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |        |  true  | false  |   <    |   >    |         ,-----------------.                      ,-----------------.         |   .    |   0    |   -    |   =    |        |
 * `--------------------------------------------'         |                 |                      |                 |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        |        |        |        |    |        |        |        |
 *                                                        |        |        |        |    |        |        |        |
 *                                                        |        |        |        |    |        |        |        |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[SYMB] = LAYOUT_moonlander(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,                                       _______   , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     _______, KC_EXLM, KC_QUES, KC_LCBR, KC_RCBR, KC_PIPE, _______,                                       _______   , KC_CIRC, KC_7   , KC_8   , KC_9   , KC_ASTR, _______,
     _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_UNDS, _______,                                       _______   , KC_TILD, KC_4   , KC_5   , KC_6   , KC_PLUS, _______,
     _______, KC_AT  , KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC,                                                            KC_DQUO, KC_1   , KC_2  ,  KC_3   , KC_SLSH, _______,
     _______, S_TRUE , S_FALSE, KC_LABK, KC_RABK,          _______         ,                      _______         ,            KC_DOT , KC_0   , KC_MINS, KC_EQL , _______,
                                                           _______, _______, _______,    _______, _______, _______
),

/* Keymap 2: Media layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * |        |        |        |        |        |        |        |                                          |  RESET |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | M. Up  |        |        |        |                                          |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |        | M. Left| M. Down| M.Right|        |        |                                          |        |  Left  |  Down  |  Up    | Right  |        |PLAY TGL|
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                                                            |        |        | PL PREV| PL NEXT|        |        |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |        |        |        | M. Btn1| M. Btn2|         ,-----------------.                      ,-----------------.         | VOL UP |VOL DOWN|VOL MUTE|        |        |
 * `--------------------------------------------'         | RGB Cycle Mod   |                      |   RGB Toggle    |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        | RGB    | RGB    | Toogle |    |  RGB   |  RGB   |  RGB   |
 *                                                        | Bright | Bright | -layer |    |  Stop  |  Hue   |  Hue   |
 *                                                        | Down   | Up     | -color |    |  Anim. |  Down  |  Up    |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[MDIA] = LAYOUT_moonlander(
     _______, _______, _______, _______, _______, _______, _______,                                                      RESET  , _______, _______, _______, _______, _______, _______,
     _______, _______, _______, KC_MS_U, _______, _______, _______,                                                      _______, _______, _______, _______, _______, _______, _______,
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                                                      _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_MPLY,
     _______, _______, _______, _______, _______, _______,                                                                        _______, _______, KC_MPRV, KC_MNXT, _______, _______,
     _______, _______, _______, KC_BTN1, KC_BTN2,          RGB_MOD          ,                                 RGB_TOG          ,           KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                                           RGB_VAD , RGB_VAI, TOGGLE_LAYER_COLOR,    RGB_SLD, RGB_HUD, RGB_HUI
),

/* Keymap 3: Unicode layer
 *
 * ,--------------------------------------------------------------.                                          ,--------------------------------------------------------------.
 * |        |        |        |        |        |        |        |                                          |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   💩   |   😉   |   🙈   |   🥳   |   🎉   |        |                                          |        |   😋   |   😒   |   🙂   |   😱   |   😜   |        |
 * |--------+--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------+--------|
 * |        |   😇   |   😅   |   🙃   |   😳   |   😬   |        |                                          |        |   🥰   |   😂   |   😘   |   🍀   |        |        |
 * |--------+--------+--------+--------+--------+--------+--------'                                          `--------+--------+--------+--------+--------+--------+--------|
 * |        |   😴   |   🤷   |   😕   |   🤔   |        |                                                            |        |   💪   |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------'                                                            '--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |         ,-----------------.                      ,-----------------.         |        |        |   👎   |   👍   |        |
 * `--------------------------------------------'         |                 |                      |                 |         `--------------------------------------------'
 *                                                        |--------+-----------------.    ,--------+-----------------|
 *                                                        |        |        |        |    |        |        |        |
 *                                                        |        |        |        |    |        |        |        |
 *                                                        |        |        |        |    |        |        |        |
 *                                                        `--------------------------'    `--------------------------'
 *
 */
[UNIC] = LAYOUT_moonlander(
     _______, _______ , _______ , _______    , _______   , _______, _______,                                             _______, _______ , _______    , _______  , _______    , _______    , _______,
     _______, X(POOP) , X(WINK) , X(NO_EVIL) , X(PARTY)  , X(TADA), _______,                                             _______, X(YUMMY), X(UNAMUSED), X(SMILE) , X(SMILE)   , X(TONGUE)  , _______,
     _______, X(ANGEL), X(SWEAT), X(UPSIDEDN), X(FLUSHED), X(GRIM), _______,                                             _______, X(HEART), X(JOY)     , X(KISS)  , X(LUCK)    , _______    , _______,
     _______, X(SLEEP), X(SHRUG), X(CONFUSED), X(THINK)  , _______,                                                               _______ , X(MUSCLE)  , _______  , _______    , _______    , _______,
     _______, _______ , _______ , _______    , _______   ,           _______         ,                        _______          ,            _______    , _______  , X(THUMBSDN), X(THUMBSUP), _______,
                                                                     _______, _______, _______,      _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      break;
    case S_TRUE:
      if (record->event.pressed) {
        SEND_STRING("true");
      }
      break;
    case S_FALSE:
      if (record->event.pressed) {
        SEND_STRING("false");
      }
      break;
  }
  return true;
}
