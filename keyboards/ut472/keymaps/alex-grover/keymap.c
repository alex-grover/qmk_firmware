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


enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _NAVIGATION,
  _FUNCTION,
  _MEDIA
};


// Left-hand home row mods
#define HRM_A LCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

// Right-hand home row mods
#define HRM_J RSFT_T(KC_J)
#define HRM_K RGUI_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_QUO RCTL_T(KC_QUOT)

// Thumb layer taps
#define THM_BSP LT(_NUMBER, KC_BSPC)
#define THM_ENT LT(_SYMBOL, KC_ENT)
#define THM_SPC LT(_NAVIGATION, KC_SPC)
#define THM_DEL LT(_FUNCTION, KC_DEL)
#define THM_ESC LT(_MEDIA, KC_ESC)

// Mac-specific commands
#define MAC_RDO SCMD(KC_Z)
#define MAC_PST LCMD(KC_V)
#define MAC_CPY LCMD(KC_C)
#define MAC_CUT LCMD(KC_X)
#define MAC_UND LCMD(KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base layer
     * ,-------------------------------------------------------------------------.
     * |     |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |       |
     * |-------------------------------------------------------------------------+
     * | Tab  |A/Ctl|S/Alt|D/Gui|F/Sft|  G  |  H  |J/Sft|K/Gui|L/Alt|'/Ctl|      |
     * |-------------------------------------------------------------------------+
     * |       |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     | Esc |Spc/L2|  Ent/L3   |Bsp/L1| Del |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_ALPHA] = LAYOUT(
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        KC_TAB,  HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,    KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_QUO, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, THM_ESC, THM_SPC,    THM_ENT,       THM_BSP, THM_DEL, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Number layer (Right function)
     * ,-------------------------------------------------------------------------.
     * |     |  [  |  7  |  8  |  9  |  ]  |     |     |     |     |     |       |
     * |-------------------------------------------------------------------------+
     * |      |  ;  |  4  |  5  |  6  |  =  |     | Sft | Gui | Alt | Ctl |      |
     * |-------------------------------------------------------------------------+
     * |       |  `  |  1  |  2  |  3  |  \  |     |     |     |     |     |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |  .  |   0  |     -     |      |     |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_NUMBER] = LAYOUT(
        XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX,
        XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_0,         KC_MINS,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Symbol layer (Enter)
     * ,-------------------------------------------------------------------------.
     * |     |  {  |  &  |  *  |  (  |  }  |     |     |     |     |     |       |
     * |-------------------------------------------------------------------------+
     * |      |  :  |  $  |  %  |  ^  |  +  |     | Sft | Gui | Alt | Ctl |      |
     * |-------------------------------------------------------------------------+
     * |       |  ~  |  !  |  @  |  #  |  |  |     |     |     |     |     |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |  )  |  _   |          |       |     |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_SYMBOL] = LAYOUT(
        XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX,
        XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_UNDS,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Navigation layer (Left function)
     * ,-------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |       |
     * |-------------------------------------------------------------------------+
     * |      | Ctl | Alt | Gui | Sft |     |Capsl|Left |Down | Up  |Right|      |
     * |-------------------------------------------------------------------------+
     * |       |     |     |     |     |     |     |Home |PgDn |PgUp | End |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          |       |     |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_NAVIGATION] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAC_RDO, MAC_PST, MAC_CPY, MAC_CUT, MAC_UND, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Function layer (Right secondary)
     * ,-------------------------------------------------------------------------.
     * |     | F12 | F7  | F8  | F9  |     |     |     |     |     |     |       |
     * |-------------------------------------------------------------------------+
     * |      | F11 | F4  | F5  | F6  |     |     | Sft | Gui | Alt | Ctl |      |
     * |-------------------------------------------------------------------------+
     * |       | F10 | F1  | F2  | F3  |     |     |     |     |     |     |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          |       |     |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_FUNCTION] = LAYOUT(
        XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX,
        XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Media layer (Left secondary)
     * ,-------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |       |
     * |-------------------------------------------------------------------------+
     * |      | Ctl | Alt | Gui | Sft |     |     |Prev |Vol- |Vol+ |Next |      |
     * |-------------------------------------------------------------------------+
     * |       |     |     |     |     |     |     |     |     |     |     |     |
     * |-------------------------------------------------------------------------+
     * |     |     |     |     |      |          | Play  |Mute |     |     |     |
     * `-------------------------------------------------------------------------'
     */
    [_MEDIA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX
    )

};
