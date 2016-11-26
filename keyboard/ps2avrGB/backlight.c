/*
Copyright 2016 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "backlight.h"
#include "i2c.h"

uint8_t current_level;

uint8_t dim(uint8_t color, uint8_t opacity) {
    return ((uint16_t) color * opacity / 0xFF) & 0xFF;
}

void backlight_set_color(uint8_t alpha, uint32_t color) {
    uint8_t r = dim((color >> 16) & 0xFF, alpha);
    uint8_t g = dim((color >> 8) & 0xFF, alpha);
    uint8_t b = dim(color & 0xFF, alpha);

    uint8_t data[] = {
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b,
      g, r, b
    };

    i2c_init();
    i2c_send(0xB0, data, 48);
}

void backlight_set(uint8_t level) {
    current_level = level;
    backlight_set_color(level * 0x11, BACKLIGHT_COLOR);
}

void hook_layer_change(uint32_t layer_state) {
    uint32_t color = layer_state
        ? BACKLIGHT_COLOR ^ 0xFFFFFF
        : BACKLIGHT_COLOR;
    backlight_set_color(current_level * 0x11, color);
}
