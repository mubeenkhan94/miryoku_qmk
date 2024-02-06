// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
  PHONE,
  ADDRESS,
  DISCORD
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("me@email.fake");
      }
      return false;

    case PHONE:
      if (record->event.pressed) {
        SEND_STRING("(555) 555-5555");
      }
      return false;

    case ADDRESS:
      if (record->event.pressed) {
        SEND_STRING("123 Main St\nNew York City, New York 10024");
      }
      return false;

    case DISCORD:
      if (record->event.pressed) {
        SEND_STRING("username");
      }
      return false;
  }
  return true;
}

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

#include "manna-harbour_miryoku.h"

#include "oled.c"

// Additional Features double tap guard

enum {
    U_TD_BOOT,
    LT_PRSNL_MAC_LOCK,
    LT_MOUSE_CLIPBOARD_MANAGER,
    LT_FUN_SHOTTR_AREA_SCREENSHOT,
    LT_NUM_SHOTTR_OCR,
    LT_SYM_ITERM_HOTKEY,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void lpml_finished(tap_dance_state_t *state, void *user_data);
void lpml_reset(tap_dance_state_t *state, void *user_data);

void lmcm_finished(tap_dance_state_t *state, void *user_data);
void lmcm_reset(tap_dance_state_t *state, void *user_data);

void lfsas_finished(tap_dance_state_t *state, void *user_data);
void lfsas_reset(tap_dance_state_t *state, void *user_data);

void lnso_finished(tap_dance_state_t *state, void *user_data);
void lnso_reset(tap_dance_state_t *state, void *user_data);

void lsih_finished(tap_dance_state_t *state, void *user_data);
void lsih_reset(tap_dance_state_t *state, void *user_data);

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t lpml_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t lmcm_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t lfsas_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t lnso_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

static td_tap_t lsih_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void lpml_finished(tap_dance_state_t *state, void *user_data) {
    lpml_tap_state.state = cur_dance(state);
    switch (lpml_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);
            register_code16(KC_Q);
            break;
        case TD_SINGLE_HOLD:
            layer_on(U_PRSNL);
            break;
        default:
            break;
    }
}

void lmcm_finished(tap_dance_state_t *state, void *user_data) {
    lmcm_tap_state.state = cur_dance(state);
    switch (lmcm_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LGUI);
            register_code16(KC_LSFT);
            register_code16(KC_V);
            break;
        case TD_SINGLE_HOLD:
            layer_on(U_MOUSE);
            break;
        default:
            break;
    }
}

void lfsas_finished(tap_dance_state_t *state, void *user_data) {
    lfsas_tap_state.state = cur_dance(state);
    switch (lfsas_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LGUI);
            register_code16(KC_LSFT);
            register_code16(KC_2);
            break;
        case TD_SINGLE_HOLD:
            layer_on(U_FUN);
            break;
        default:
            break;
    }
}

void lnso_finished(tap_dance_state_t *state, void *user_data) {
    lnso_tap_state.state = cur_dance(state);
    switch (lnso_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LGUI);
            register_code16(KC_LCTL);
            register_code16(KC_LALT);
            register_code16(KC_O);
            break;
        case TD_SINGLE_HOLD:
            layer_on(U_NUM);
            break;
        default:
            break;
    }
}

void lsih_finished(tap_dance_state_t *state, void *user_data) {
    lsih_tap_state.state = cur_dance(state);
    switch (lsih_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_LALT);
            register_code16(KC_SLSH);
            break;
        case TD_SINGLE_HOLD:
            layer_on(U_SYM);
            break;
        default:
            break;
    }
}

void lpml_reset(tap_dance_state_t *state, void *user_data) {
    switch (lpml_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LGUI);
            unregister_code16(KC_LCTL);
            unregister_code16(KC_Q);;
            break;
        case TD_SINGLE_HOLD:
            layer_off(U_PRSNL);
            break;
        default:
            break;
    }
}

void lmcm_reset(tap_dance_state_t *state, void *user_data) {
    switch (lmcm_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LGUI);
            unregister_code16(KC_LSFT);
            unregister_code16(KC_V);;
            break;
        case TD_SINGLE_HOLD:
            layer_off(U_MOUSE);
            break;
        default:
            break;
    }
}

void lfsas_reset(tap_dance_state_t *state, void *user_data) {
    switch (lfsas_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LGUI);
            unregister_code16(KC_LSFT);
            unregister_code16(KC_2);;
            break;
        case TD_SINGLE_HOLD:
            layer_off(U_FUN);
            break;
        default:
            break;
    }
}

void lnso_reset(tap_dance_state_t *state, void *user_data) {
    switch (lnso_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LGUI);
            unregister_code16(KC_LCTL);
            unregister_code16(KC_LALT);
            unregister_code16(KC_O);;
            break;
        case TD_SINGLE_HOLD:
            layer_off(U_NUM);
            break;
        default:
            break;
    }
}

void lsih_reset(tap_dance_state_t *state, void *user_data) {
    switch (lsih_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_LALT);
            unregister_code16(KC_SLSH);;
            break;
        case TD_SINGLE_HOLD:
            layer_off(U_SYM);
            break;
        default:
            break;
    }
}

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define MIRYOKU_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [LT_PRSNL_MAC_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lpml_finished, lpml_reset),
    [LT_MOUSE_CLIPBOARD_MANAGER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lmcm_finished, lmcm_reset),
    [LT_FUN_SHOTTR_AREA_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lfsas_finished, lfsas_reset),
    [LT_NUM_SHOTTR_OCR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lnso_finished, lnso_reset),
    [LT_SYM_ITERM_HOTKEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsih_finished, lsih_reset),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};


// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){
    &capsword_key_override,
    NULL
};


// thumb combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
