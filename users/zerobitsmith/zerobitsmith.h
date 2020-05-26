/* Copyright 2020 @zerobitsmith
 *
 * Modified from @ninjonas's, Copyright 2019
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
#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "process_records.h"

#ifdef TAPPING_TERM
  #undef TAPPING_TERM
  #define TAPPING_TERM 300
#endif

#ifdef TAP_DANCE_ENABLE
  #include "tap_dances.h"
#endif
#if defined(KEYBOARD_lily58_rev1) & defined(PROTOCOL_LUFA)
  #include "lufa.h"
  #include "split_util.h"
#endif

#ifdef ENCODER_ENABLE
bool left_encoder_rotated;
bool right_encoder_rotated;
uint16_t encoder_rotated_timer;
#endif

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _RAISE  3
#define _LOWER 4
#define _NUM    5
#define _MOUSE  6
#define _ADJUST 7

// Layer Keys
#define LT_LOW LT(_LOWER, KC_ENT)
#define LT_RAI LT(_RAISE, KC_SPC)

// Mod-Tap Keys
#define MT_DEL MT(MOD_LALT | MOD_LSFT, KC_DEL)
#define MT_EQL MT(MOD_RSFT, KC_EQL)

// Layout blocks
#define _____________________QWERTY_L1______________________ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
#define _____________________QWERTY_L2______________________ LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G
#define _____________________QWERTY_L3______________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B

#define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL
#define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
#define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS

#define _____________________NUM_LEFT_______________________ KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
#define _____________________NUM_RIGHT______________________ KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS

#define _____________________FUNC_LEFT______________________ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _____________________FUNC_RIGHT_____________________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

#define ______________VIM_NAV_____________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define _____________________SYM_LEFT_______________________ KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC
#define _____________________SYM_RIGHT______________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS

#define _____________________LOWER_L1_______________________ M_XXX2, M_XXX3, _________MEDIA_1_________, K_CSCN
#define _____________________LOWER_L2_______________________ M_XXX4, M_XXX5, _________MEDIA_2_________, XXXXXXX
#define _____________________LOWER_L3_______________________ KC_LSFT, M_SHFT, _________MEDIA_3_________, T_LBRC

#define _____________________LOWER_R1_______________________ _______________NAV_1______________, XXXXXXX, K_MDSH
#define _____________________LOWER_R2_______________________ _______________NAV_2______________, K_LOCK, XXXXXXX
#define _____________________LOWER_R3_______________________ T_RBRC, KC_M, M_TERM, M_CODE, M_XXX1, M_PYNV


#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________ADJUST_R1______________________ RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, _______
  #define _____________________ADJUST_R2______________________ RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_SPD, XXXXXXX
  #define _____________________ADJUST_R3______________________ RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K
  #define _____________________ADJUST_R4______________________ RGB_M_X, RGB_M_G, XXXXXXX, XXXXXXX,  M_FLSH, RESET
#else
  #define _____________________ADJUST_R1______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  #define _____________________ADJUST_R2______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  #define _____________________ADJUST_R3______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  #define _____________________ADJUST_R4______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  M_FLSH, RESET
#endif


#define _________NUMPAD_0________ KC_NLCK,
#define _________NUMPAD_1________ KC_P7, KC_P8, KC_P9
#define _________NUMPAD_2________ KC_P4, KC_P5, KC_P6
#define _________NUMPAD_3________ KC_P1, KC_P2, KC_P3

#define _______________NAV_1______________ KC_PGUP, KC_HOME, KC_UP, KC_END
#define _______________NAV_2______________ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT

#define _____________MOUSE_1______________ KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define _____________MOUSE_2______________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define _____________MOUSE_3_____ KC_ACL0, KC_ACL1, KC_ACL2

#define ___________________________________________ _______, _______, _______, _______, _______
#define __________________________________ _______, _______, _______, _______
#define _________________________ _______, _______, _______

#define _____________MOD_LEFT_____________ KC_LALT, T_GUI, KC_LCTL, LT_RAI
#define _____________MOD_RIGHT____________ LT_LOW, KC_BSPC, MT_DEL, T_CPAP

#define _________MEDIA_1_________ KC_VOLD, KC_VOLU, KC_MUTE
#define _________MEDIA_2_________ KC_MPRV, KC_MPLY, KC_MNXT

#define ________MOD_LEFT_________ LALT_T(KC_ENT), TG(_MOUSE), TT(_RAISE)
#define ________MOD_RIGHT________ KC_RGUI, TG(_NUM), RCTL_T(KC_PENT)

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ergodox_wrapper(...) LAYOUT_ergodox(__VA_ARGS__)
