// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#undef SSD1306OLED
#define OLED_FONT_H "users/manna-harbour_miryoku/glcdfont.c"

#define SPLIT_WPM_ENABLE   // Enable WPM across split keyboards (+268).
#define SPLIT_OLED_ENABLE  // Sync on/off OLED state between halves (+100).

#define KC_LK   C(G(KC_Q)) // lock Mac computer
#define KC_CLP  S(G(KC_V)) // launch Alfred clipboard manager
#define KC_NAV  LT(U_NAV, KC_QUOT)
#define KC_NML  MO(U_NUM)
#define KC_SYM  MO(U_SYM)
#define KC_FUN  MO(U_FUN)

#define MIRYOKU_MAPPING( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
       N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT( \
KC_FUN, K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   KC_LK, \
KC_NML, K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   KC_NAV, \
KC_SYM, K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   KC_CLP, \
                      K32,   K33,   K34,   K35,   K36,   K37 \
)

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,             KC_F,               KC_P,              KC_B,               KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LGUI_T(KC_A),      LALT_T(KC_R),     LCTL_T(KC_S),       LSFT_T(KC_T),      KC_G,               KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),     KC_C,               KC_D,              KC_V,               KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,             LT(U_MEDIA,KC_ESC), LT(U_NAV,KC_BSPC), LT(U_MOUSE,KC_TAB), LT(U_SYM,KC_ENT),  LT(U_NUM,KC_SPC),  LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA \
KC_Q,              KC_W,             KC_E,               KC_R,              KC_T,               KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LGUI_T(KC_A),      LALT_T(KC_S),     LCTL_T(KC_D),       LSFT_T(KC_F),      KC_G,               KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),     KC_C,               KC_V,              KC_B,               KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,             LT(U_MEDIA,KC_ESC), LT(U_NAV,KC_BSPC), LT(U_MOUSE,KC_TAB), LT(U_SYM,KC_ENT),  LT(U_NUM,KC_SPC),  LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_BSPC,           KC_TAB,            KC_ENT,            KC_SPC,            KC_DEL,            U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_SPC,            KC_DEL,            U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
U_NP,              U_NP,              KC_APP,            KC_BSPC,           KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_CLIPBOARD = MAC
