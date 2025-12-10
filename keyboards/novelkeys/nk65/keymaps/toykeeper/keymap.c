/* ToyKeeper's Novelkeys NK65 QMK keymap
 * Copyright 2021-2025 Selene ToyKeeper
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "toykeeper.h"

#define MY_LAYOUT LAYOUT_65_ansi

// wrap base layers to avoid the need to keep several copies in sync
#define MY_LAYOUT_wrapper(...) MY_LAYOUT(__VA_ARGS__)
#define MY_LAYOUT_base_wrapper(...) MY_LAYOUT_base(__VA_ARGS__)
#define MY_LAYOUT_base(                             K01, K02, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
      K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A \
  ) MY_LAYOUT_wrapper( \
    QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , K01    , K02    , KC_BSLS,  TK_STAR, \
    KC_TAB , K11    , K12    , K13    , K14    , K15    , K16    , K17    , K18    , K19    , K1A    , K1B    , K1C    , KC_BSPC,  KC_PGUP, \
    TK_LCTL, K21    , K22    , K23    , K24    , K25    , K26    , K27    , K28    , K29    , K2A    , K2B    ,      KC_ENT ,      KC_PGDN, \
    SC_LSPO, K31    , K32    , K33    , K34    , K35    , K36    , K37    , K38    , K39    , K3A    ,      SC_RSPC,     KC_UP  ,  KC_END , \
    TK_MOON, TK_LGUI, TK_LALT,                   KC_SPC ,                            TK_RCTL, TK_RALT, TK_RGUI, KC_LEFT, KC_DOWN,  KC_RGHT  \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* empty, copy/paste and fill in the blanks
[L_EMPTY] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
    ), */

// base layers: qwerty, dvorak, undvorak, colemak-dh-tk
[L_QWERTY  ] = MY_LAYOUT_base_wrapper(__QWERTY__),
[L_DVORAK  ] = MY_LAYOUT_base_wrapper(__DVORAK__),
[L_UNDVORAK] = MY_LAYOUT_base_wrapper(__UNDVORAK__),
[L_COLEMAK ] = MY_LAYOUT_base_wrapper(__COLEMAK_DH_TK__),

// Number Pad(s)
[L_NUMPAD] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, KC_NUM , KC_PAST, TK_LPAR, TK_RPAR, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PAST, KC_PSLS, KC_PEQL, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PMNS,      KC_PENT,     _______,
    _______, _______, _______, _______, _______, _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PSLS,      _______,     _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
    ),

// Mouse (lower right corner)
[L_MOUSE] = MY_LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_BTN3,     KC_WH_D,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_BTN1,     KC_MS_U, KC_BTN2,
    _______, _______, _______,                   _______,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

// Fn1 / Moon (lower left corner)
[L_FN1] = MY_LAYOUT(
    TK_SESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , TK_BSTG, _______,
    KC_MPLY, KC_MNXT, KC_MPRV, TK_ANY , _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______, KC_DEL , KC_WH_U,
    _______, DM_REC1, DM_REC2, _______, _______, _______, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,      KC_BTN3,     KC_WH_D,
    KC_BTN3, DM_PLY1, DM_PLY2, _______, _______, _______, TK_WARP, KC_BTN1, KC_BTN3, KC_BTN2, _______,      KC_BTN1,     KC_MS_U, KC_BTN2,
    _______, KC_BTN1, KC_BTN2,                   KC_DEL ,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

// Fn2 / Star (upper right corner)
[L_FN2] = MY_LAYOUT(
    QK_BOOT, KC_MYCM, KC_WSCH, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , TK_SINS, _______,
    TK_INFO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS , KC_DEL , KC_F13 ,
    KC_CAPS, RGB_HUI, RGB_SAI, RGB_VAI, _______, TK_IUUI, _______, _______, _______, _______, _______, _______,      _______,     KC_WSCH,
    TK_DF_3, RGB_MOD, RGB_SPI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,      _______,     KC_PGUP, KC_MYCM,
    TK_DF_0, TK_DF_1, TK_DF_2,                   RGB_TOG,                            KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_END
    )

};


// highlight color for each layer while active
const uint8_t layer_colors[][3] = {
    [L_QWERTY  ] = {0,0,0},
    [L_DVORAK  ] = {0,0,0},
    [L_UNDVORAK] = {0,0,0},
    [L_COLEMAK ] = {0,0,0},
    [L_NUMPAD  ] = {192,0,0},    // red
    [L_MOUSE   ] = {224,0,16},   // bubble gum pink
    [L_FN1     ] = {255,0,192},  // neon purple-ish
    [L_FN2     ] = {0,200,100},  // mint green
};
const uint8_t layer_indicator_colors[][6] = {
    { L_NUMPAD  , 9,4, 192,  0,  0 },
    { L_MOUSE   ,11,4, 255, 20,255 },
    { L_FN1     , 0,4, 128,255, 32 },
    { L_FN2     ,14,0, 128,255,  0 },
    { 0         , 0,0,   0,  0,  0 },  // stop
};
const uint8_t mod_colors[] = {255,255,16};
const uint8_t mod_indicator_coords[][3] = {
    // mod, x, y
    { 1, 0, 3, },  // L Shift
    { 1,12, 3, },  // R Shift
    { 2, 0, 2, },  // L Ctrl
    { 2, 9, 4, },  // R Ctrl
    { 3, 2, 4, },  // L Alt
    { 3,10, 4, },  // R Alt
    { 4, 1, 4, },  // L GUI
    { 4,11, 4, },  // R GUI
    { 0, 0, 0, },  // stop
};

// my middle LED is broken, but top+bottom work
// values and channel info are taken from `nk65.c`
#define LED_TOP  68  // blue only, green channel
#define LED_MID  69  // blue+red, red+blue channels
#define LED_BOT  70  // red only, green channel
bool rgb_matrix_indicators_user(void) {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t g2 = 0;
    uint8_t b = 0;

    layer_state_t state = layer_state | default_layer_state;

    // top LED: blue (on green channel)
    if (IS_LAYER_ON_STATE(state, L_MOUSE)) g = 255;

    // middle LED: blue+red
    if (IS_LAYER_ON_STATE(state, L_FN1)) r = 255;

    // middle LED: blue+red
    if (IS_LAYER_ON_STATE(state, L_FN2)) b = 255;

    // bottom LED: red (on green channel)
    if (IS_LAYER_ON_STATE(state, L_NUMPAD)) g2 = 255;

    rgb_matrix_set_color(LED_TOP, 0, g, 0);
    rgb_matrix_set_color(LED_MID, r, 0, b);
    rgb_matrix_set_color(LED_BOT, 0, g2, 0);

    return false;
}

