#include QMK_KEYBOARD_H
#include "zerobitsmith.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_wrapper(
                _____________________NUM_LEFT_______________________,                   _____________________NUM_RIGHT______________________,
                _____________________QWERTY_L1______________________,                   _____________________QWERTY_R1______________________,
                _____________________QWERTY_L2______________________,                   _____________________QWERTY_R2______________________,
                _____________________QWERTY_L3______________________, KC_LGUI, KC_ENT,  _____________________QWERTY_R3______________________,
                                           ________MOD_LEFT_________, KC_BSPC, KC_SPC,  ________MOD_RIGHT________
        ),
	[_RAISE] = LAYOUT_wrapper(
                _____________________FUNC_LEFT______________________,                   _____________________FUNC_RIGHT_____________________,
                ___________________________________________, KC_PSCR,                   KC_LBRC, _________________________, KC_PAUS, KC_RBRC,
                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK,                   ______________VIM_NAV_____________, KC_PGUP, XXXXXXX,
                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_APP, _______, XXXXXXX, KC_HOME,  KC_INS,  KC_DEL, KC_END,  KC_PGDN, XXXXXXX,
                                           _______, _______, _______,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),
	[_NUM] = LAYOUT_wrapper(
                ___________________________________________, _______,                   _______, KC_NLCK, __________________________________,
                ___________________________________________, _______,                   _______, _________NUMPAD_1________, _______, _______,
                ___________________________________________, _______,                   _______, _________NUMPAD_2________, _______, _______,
                ___________________________________________, _______, _______, _______, _______, _________NUMPAD_3________, KC_PCMM, _______,
                                                    ___________________________________________, KC_P0, KC_TRNS, KC_PDOT
        ),
	[_MOUSE] = LAYOUT_wrapper(
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_ADJUST),
                XXXXXXX, KC_WBAK, _____________MOUSE_1______________,                   XXXXXXX, _________MEDIA_1_________, XXXXXXX, XXXXXXX,
                XXXXXXX, KC_WFWD, _____________MOUSE_2______________,                   XXXXXXX, _________MEDIA_2_________, XXXXXXX, XXXXXXX,
                XXXXXXX, XXXXXXX, _____________MOUSE_3_____, XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                           XXXXXXX, KC_TRNS, XXXXXXX, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),
	[_ADJUST] = LAYOUT_wrapper(
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _____________________ADJUST_R1______________________,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _____________________ADJUST_R2______________________,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _____________________ADJUST_R3______________________,
                RESET,    M_FLSH,  M_VRSN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _____________________ADJUST_R4______________________,
                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        ),
};
