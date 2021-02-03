/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include "zerobitsmith.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |            | Knob 2: Page Dn/Up |
        | Press: Mute       | Leave Meet | Press: Play/Pause  |
        | Activate Meet     | Raise Hand | Layer Up           |
        | Mic Toggle        | Cam Toggle | RGB Mode           |
     */
    [0] = LAYOUT(
        KC_MUTE, LCTL(LGUI(KC_G)), KC_MPLY,
        LCTL(LGUI(KC_G)), LGUI(LSA(KC_G)), TG(1),
        LGUI(KC_G), SGUI(KC_G), RGB_MOD
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | F19  | (Passthrough)|
        | Media Previous | Media Play/pause | Media Next |
     */
    [1] = LAYOUT(
        RESET  , KC_17, KC_STOP,
        KC_18, KC_19, _______,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
