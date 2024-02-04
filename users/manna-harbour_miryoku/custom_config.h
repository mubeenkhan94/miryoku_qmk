// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define MASTER_LEFT

#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2
#define OLED_FONT_H "users/manna-harbour_miryoku/glcdfont.c"

#define MIRYOKU_ALPHAS = MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH_SWAP_SPACE
#define MIRYOKU_EXTRA = MIRYOKU_ALTERNATIVES_BASE_QWERTY_SWAP_SPACE
#define MIRYOKU_CLIPBOARD = MAC

#define SPLIT_WPM_ENABLE   // Enable WPM across split keyboards (+268).
#define SPLIT_OLED_ENABLE  // Sync on/off OLED state between halves (+100).
