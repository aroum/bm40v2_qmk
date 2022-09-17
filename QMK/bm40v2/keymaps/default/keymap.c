/* Copyright 2020 tominabox1
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
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};
enum custom_keycodes
{
    LNG_SW = SAFE_RANGE,
    GRTSGN,
    SCRCUT,
    NUMDOT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case LNG_SW:
        if (record->event.pressed)
        {
            // when keycode LNG_SW is pressed
            SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)));
        }
        else
        {
            // when keycode LNG_SW is released
        }
        break;
    case GRTSGN:
        if (record->event.pressed)
        {
            // when keycode GRTSGN is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_6) SS_TAP(X_KP_2)));
        }
        else
        {
            // when keycode GRTSGN is released
        }
        break;

    case SCRCUT:
        if (record->event.pressed)
        {
            // when keycode SCRCUT is pressed
            SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
        }
        else
        {
            // when keycode SCRCUT is released
        }
        break;

    case NUMDOT:
        if (record->event.pressed)
        {
            // when keycode SCRCUT is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_4) SS_TAP(X_KP_6)));
        }
        else
        {
            // when keycode SCRCUT is released
        }
        break;
    }
    return true;
};

#define KC_LG_RBR LGUI_T(KC_RBRC)
#define KC_LC_GRV LCTL_T(KC_GRV)
#define KC_LA_BCL LALT_T(KC_BSLS)

#define KC_RG_LBR RGUI_T(KC_LBRC)
#define KC_RC_QUO RCTL_T(KC_QUOT)
#define KC_RA_MIN RALT_T(KC_MINUS)


#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L1_ENT LT(_LOWER, KC_ENT)
#define KC_L1_BSP LT(_LOWER, KC_BSPC)
#define KC_L2_DEL LT(_RAISE, KC_DEL)
#define KC_L2_ESC LT(_RAISE, KC_ESC)

#define KC_LG_CAP LGUI_T(KC_CAPS)
#define KC_LC_APP LCTL_T(KC_APP)
#define KC_LA_EQL LALT_T(KC_EQL)

#define KC_RG_F1 RGUI_T(KC_F1)
#define KC_RC_F2 RCTL_T(KC_F2)
#define KC_RA_F3 RALT_T(KC_F3)

#define KC_L3_ENT LT(_ADJUST, K,,nnn,C_ENT)
#define KC_L3_BSP LT(_ADJUST, KC_BSPC)
#define KC_L3_DEL LT(_ADJUST, KC_DEL)
#define KC_L3_ESC LT(_ADJUST, KC_ESC)

#define KC_LG_NLC LGUI_T(KC_NLCK)
#define KC_RG_SLC RGUI_T(KC_SLCK)

#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty*/
    [_QWERTY] = LAYOUT_planck_mit(
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_LG_RBR, KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     , KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_RG_LBR,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LC_GRV, KC_A     , KC_S     , KC_D     , KC_F     , KC_G     , KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_RC_QUO,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LA_BCL, KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RA_MIN,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        ADJUST   , KC_NO    , KC_TAB   , KC_L2_ESC, KC_L1_ENT, KC_LS_SPC           , KC_L1_BSP, KC_L2_DEL, KC_NO    , KC_NO    , KC_NO
    //└──────────┴──────────┴──────────┴──────────┴──────────┴─────────────────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
    ),
    /* Lower*/
    [_LOWER] = LAYOUT_planck_mit(
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_LG_CAP, KC_PAST  , KC_7     , KC_8     , KC_9     , KC_PPLS  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_RG_F1 ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LC_APP, KC_PSLS  , KC_4     , KC_5     , KC_6     , KC_PMNS  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_RC_F2 ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LA_EQL, KC_0     , KC_1     , KC_2     , KC_3     , NUMDOT   , LNG_SW   , KC_F4    , KC_F5    , KC_F6    , KC_F7    , KC_RA_F3 ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO    , KC_NO    , _______  , KC_L3_ESC, _______  , _______             , _______  , KC_L3_DEL, KC_NO    , KC_NO   , KC_NO  
    //└──────────┴──────────┴──────────┴──────────┴──────────┴─────────────────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
    ),
    /* Raise*/
    [_RAISE] = LAYOUT_planck_mit(
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_LGUI  , KC_VOLU  , KC_PGUP  , KC_MPLY  , KC_HOME  , KC_WH_U  , KC_WH_U  , KC_HOME  , KC_MPLY  , KC_PGUP  , KC_VOLU  , KC_RGUI  ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL  , KC_VOLD  , KC_LEFT  , KC_UP    , KC_DOWN  , KC_RGHT  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_VOLD  , KC_RCTL  ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LALT  , KC_MUTE  , KC_PGDN  , SCRCUT   , KC_END   , KC_WH_D  , KC_WH_D  , KC_END   , GRTSGN   , KC_PGDN  , KC_MUTE  , KC_RALT  ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO    , KC_NO    , _______  , _______  , KC_L3_ENT, _______             , KC_L3_BSP, KC_MNXT  , KC_NO    , KC_NO    , KC_NO
    //└──────────┴──────────┴──────────┴──────────┴──────────┴─────────────────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
    ),
    /* Adjust (Lower + Raise)*/
    [_ADJUST] = LAYOUT_planck_mit(
    //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
        KC_LG_NLC,  RESET   ,   KC_P7  ,   KC_P8  ,   KC_P9  , KC_INS   ,  KC_F8   ,  KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  ,KC_RG_SLC ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LCTL  ,  KC_PENT ,   KC_P4  ,   KC_P5  ,   KC_P6  , KC_PSCR  , RGB_HUI  ,  RGB_SAI , RGB_MOD  , RGB_VAI ,   KC_NO   , KC_RCTL  ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_LALT  ,  KC_P0   ,   KC_P1  ,   KC_P2  ,   KC_P3  , KC_PAUS  , RGB_HUD  ,  RGB_SAD , RGB_RMOD , RGB_VAD  ,  KC_NO   , KC_RALT  ,
    //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┴──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_NO    , KC_NO    , _______  , _______  , _______  , _______             , _______  , _______  , KC_NO    , KC_NO    , KC_NO
    //└──────────┴──────────┴──────────┴──────────┴──────────┴─────────────────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
    )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _QWERTY:
//             rgb_matrix_mode(RGB_MATRIX_CUSTOM_qwerty);
//             break;
//         case _LOWER:
//             rgb_matrix_mode(RGB_MATRIX_CUSTOM_lower);
//             break;
//         case _RAISE:
//             rgb_matrix_mode(RGB_MATRIX_CUSTOM_raise);
//             break;
//         case _ADJUST:
//             rgb_matrix_mode(RGB_MATRIX_CUSTOM_adjust);
//             break;
//     }
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
