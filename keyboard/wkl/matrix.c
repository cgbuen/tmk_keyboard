/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

/*
 * scan matrix
 */
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "timer.h"
#include "matrix.h"
#include "hhkb_avr.h"
#include <avr/wdt.h>
#include "suspend.h"


// matrix power saving
#define MATRIX_POWER_SAVE       10000
static uint32_t matrix_last_modified = 0;

// matrix state buffer(1:on, 0:off)
static matrix_row_t *matrix;
static matrix_row_t *matrix_prev;
static matrix_row_t _matrix0[MATRIX_ROWS];
static matrix_row_t _matrix1[MATRIX_ROWS];


void matrix_init(void)
{
#ifdef DEBUG
    debug_enable = true;
    debug_keyboard = true;
#endif

    // all outputs for columns high
    DDRB = 0xFF;
    PORTB = 0xFF;
    // all inputs for rows
    DDRA = 0x00;
    DDRC &= ~(0x111111<<2);
    DDRD &= ~(1<<PIND7);
    // all rows are pulled-up
    PORTA = 0xFF;
    PORTC |= (0b111111<<2);
    PORTD |= (1<<PIND7);

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix0[i] = 0x00;
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix1[i] = 0x00;
    matrix = _matrix0;
    matrix_prev = _matrix1;
}

void matrix_set_col_status(uint8_t col) {
	DDRB = (1 << col);
	PORTB = ~(1 << col);
}

uint8_t matrix_get_row_status(uint8_t row) {
    if (row < 8) {
        // for rows 0..7, PORTA 0 -> 7
        return (~PINA) & (1 << row);
    } else if (row < 14) {
        // for rows 8..13, PORTC 7 -> 0
        return (~PINC) & (1 << (15-row));
    }else if (row == 14) {
        // for row 14
        return (~PIND) & (1 << 7);
    }

    return 0;
}

uint8_t matrix_scan(void)
{
    uint8_t *tmp;

    tmp = matrix_prev;
    matrix_prev = matrix;
    matrix = tmp;

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        matrix_set_col_status(col);
        _delay_us(5);

        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            uint8_t cur = matrix_get_row_status(row);

            if (cur) {
                matrix[row] &= ~(1 << col);
            } else {
                matrix[row] |= (1 << col);
            }

            uint8_t prev = matrix_prev[row] & (1 << col);
            if (cur != prev) {
              matrix_last_modified = timer_read32();
            }
        }
    }
    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_power_up(void) {
}
void matrix_power_down(void) {
}
