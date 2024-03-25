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

enum layer_number {
  _QWERTY = 0,
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _LAYER4,
  _LAYER5
};

enum custom_keycodes {
    NOWHITE = SAFE_RANGE,
    COLLAPSE,
    ARROW,
    ARROW2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_MINUS, TG(_LAYER3),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, TG(_LAYER5),TG(_LAYER4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_RALT,   MO(_LAYER1),  KC_SPC,     KC_ENT,   MO(_LAYER2), KC_LSFT
                                      //`--------------------------'  `--------------------------'

  ),

    [_LAYER1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_PIPE, KC_EXLM, KC_HASH, KC_LPRN, KC_RPRN,                      KC_EQL, KC_PLUS, KC_MINS, KC_PERC, KC_GRAVE, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,KC_TILDE, KC_CIRC, KC_ASTR, KC_LBRC, KC_RBRC,                    KC_COLON, KC_QUOTE,KC_SLASH,KC_AMPR,KC_DOLLAR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LABK, KC_QUES, KC_UNDS, KC_LCBR, KC_RCBR,                      KC_SCLN, KC_DQUO, KC_BSLS, KC_AT,   KC_RABK, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,   _______,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_LAYER2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_CAPS,RCS(KC_C),LCTL(KC_U),LALT(KC_M),LCTL(KC_Z),LCA_T(KC_NO),           KC_HOME,LCTL(KC_SLASH),KC_END,LALT(KC_SCLN),LALT(KC_QUOTE), LSA(KC_F),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ARROW,LCTL(KC_BSLS),RCS(KC_I),LCTL(KC_BSLS),LSA(KC_NO),         KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, NOWHITE,  COLLAPSE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,LGUI(KC_SPC),RCS(KC_P),RCS(KC_L),RCS(KC_C),RCS(KC_NO),            LCTL(KC_LBRC),LCTL(KC_RBRC), LSA(KC_L),LCTL(KC_X),LCTL(KC_DOT),LCTL(KC_GRAVE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,_______,_______,     _______,_______,_______
                                      //`--------------------------'  `--------------------------'
  ),

    [_LAYER3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,      KC_7,    KC_8,    KC_9,   KC_0,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGUI(KC_L), LCA(KC_DEL),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,_______,_______,     _______,_______,_______
                                      //`--------------------------'  `--------------------------'
  ),

    [_LAYER4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_PSCR, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLU, KC_VOLD,                       LCTL(KC_F5),KC_F10,KC_F11, XXXXXXX, XXXXXXX, KC_LEFT_GUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1,                      KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,_______,_______,     _______,_______,_______
                                      //`--------------------------'  `--------------------------'
  ),
     [_LAYER5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,_______,_______,     _______,_______,_______
                                      //`--------------------------'  `--------------------------'
  )
};

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   5

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NOWHITE:
        if (record->event.pressed) {
            // when keycode NOWHITE is pressed
            SEND_STRING(SS_LCTL("k"));
            SEND_STRING(SS_LCTL("x"));
        }
        break;
    case COLLAPSE:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("k"));
          SEND_STRING(SS_LCTL("0"));
      }
      break;
    case ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case ARROW2:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;

    // Process other keycodes normally
    default:
      return true;
  }
  return true;
}

