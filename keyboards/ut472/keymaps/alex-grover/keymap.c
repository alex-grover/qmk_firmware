/* Copyright 2018 Alex Grover
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


// Left-hand home row mods
#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

// Right-hand home row mods
#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SCLN RCTL_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer
 * ,-------------------------------------------------------------------------.
 * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  Bksp |
 * |-------------------------------------------------------------------------+
 * | Tab  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
 * |-------------------------------------------------------------------------+
 * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Ent |
 * |-------------------------------------------------------------------------+
 * | App | Ctrl| Alt | GUI |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
 * `-------------------------------------------------------------------------'
 */
LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  HRM_A,   HRM_S,   HRM_D,   HRM_F, KC_G, KC_H, HRM_J, HRM_K,   HRM_L,   HRM_SCLN,KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  KC_APP,  KC_LCTL, KC_LALT, KC_LGUI, MO(2),   KC_SPC,   MO(1), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Layer 1 (Right)
 * ,-------------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  Del  |
 * |-------------------------------------------------------------------------+
 * | Capsl| F1  | F2  | F3  | F4  | F5  | F6  |  -  |  =  |  [  |  ]  |  \   |
 * |-------------------------------------------------------------------------+
 * |       | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |     |     |
 * |-------------------------------------------------------------------------+
 * | RGB |     |     |     |      |          |       | Home| PgDn| PgUp| End |
 * `-------------------------------------------------------------------------'
 */
LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL ,
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______,
  RGB_TOG, _______, _______, _______, _______,     _______,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Layer 2 (Left)
 * ,-------------------------------------------------------------------------.
 * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  ) |  Del  |
 * |-------------------------------------------------------------------------+
 * | Capsl| F1  | F2  | F3  | F4  | F5  | F6  |  _  |  +  |  {  |  }  |   |  |
 * |-------------------------------------------------------------------------+
 * |       | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |     | Play|
 * |-------------------------------------------------------------------------+
 * | RGB |     |     |     |      |          |       | Prev| Vol-| Vol+| Next|
 * `-------------------------------------------------------------------------'
 */
LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_MPLY,
  RGB_TOG, _______, _______, _______, _______,      _______,     _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
)

};
