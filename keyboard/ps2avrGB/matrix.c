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
#include "ps2avrGB.h"
#include <avr/wdt.h>
#include "suspend.h"


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

    // all outputs for rows high
    DDRB = 0xFF;
    PORTB = 0xFF;
    // all inputs for columns
    DDRA = 0x00;
    DDRC &= ~(0x111111<<2);
    DDRD &= ~(1<<PIND7);
    // all columns are pulled-up
    PORTA = 0xFF;
    PORTC |= (0b111111<<2);
    PORTD |= (1<<PIND7);

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix0[i] = 0x00;
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix1[i] = 0x00;
    matrix = _matrix0;
    matrix_prev = _matrix1;
}

void matrix_set_row_status(uint8_t row) {
	DDRB = (1 << row);
	PORTB = ~(1 << row);
}

uint8_t bit_reverse(uint8_t x) {
    x = ((x >> 1) & 0x55) | ((x << 1) & 0xaa);
    x = ((x >> 2) & 0x33) | ((x << 2) & 0xcc);
    x = ((x >> 4) & 0x0f) | ((x << 4) & 0xf0);
    return x;
}

uint8_t matrix_scan(void)
{
    matrix_row_t *tmp;

    tmp = matrix_prev;
    matrix_prev = matrix;
    matrix = tmp;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        matrix_set_row_status(row);
        _delay_us(5);

        matrix[row] = (
          // cols 0..7, PORTA 0 -> 7
          (~PINA) & 0xFF
        ) | (
          // cols 8..13, PORTC 7 -> 0
          bit_reverse((~PINC) & 0xFF) << 8
        ) | (
          // col 14, PORTD 7
          ((~PIND) & (1 << PIND7)) << 7
        );
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

// TODO: figure out how to call the bootloader from bootmapper client
// (probably by adding stuff to usbFunctionWrite, etc in
// tmk_core/protocol/vusb/vusb.c (see stuff under firmware/ps2avrGB/vusb.c)
