/*
Copyright 2015 Ralf Schmitt <ralf@bunkertor.net>

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

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "backlight.h"


#ifndef DEBOUNCE
#   define DEBOUNCE 0
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static uint8_t read_rows(uint8_t col);
static void init_rows(void);
static void unselect_cols(void);
static void select_col(uint8_t col);

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    backlight_init_ports();
    unselect_cols();
    init_rows();
    for (uint8_t i=0; i < MATRIX_ROWS; i++)  {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);
        _delay_us(3);
        uint8_t rows = read_rows(col);
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t)1<<col);
            bool curr_bit = rows & (1<<row);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t)1<<col);
                if (debouncing) {
                    dprint("bounce!: "); dprintf("%02X", debouncing); dprintln();
                }
                debouncing = DEBOUNCE;
            }
        }
        unselect_cols();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        xprintf("%02X: %032lb\n", row, bitrev32(matrix_get_row(row)));
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop32(matrix[i]);
    }
    return count;
}

static void init_rows(void)
{
    DDRD  &= ~0b00101111; // PD0, PD1, PD2, PD3, PD5 input
    PORTD &= ~0b00101111; // PD0, PD1, PD2, PD3, PD5 low
    DDRB  &= ~0b10000000; // PB7 input
    PORTB &= ~0b10000000; // PB7 low
    DDRE  &= ~0b00000100; // PE2 input
    PORTE |=  0b00000100; // PE2 high
}

static uint8_t read_rows(uint8_t col)
{
    if (col == 14) {
        return PINE&(1<<2) ? 0 : (1<<1);     // PE2 (Row 0)
    } else {
        return (PIND&(1<<0) ? (1<<0) : 0) |  // PD0 (Row 0)
               (PIND&(1<<1) ? (1<<1) : 0) |  // PD1 (Row 1)
               (PIND&(1<<2) ? (1<<2) : 0) |  // PD2 (Row 2)
               (PIND&(1<<3) ? (1<<3) : 0) |  // PD3 (Row 3)
               (PIND&(1<<5) ? (1<<4) : 0) |  // PD5 (Row 4)
               (PINB&(1<<7) ? (1<<5) : 0);   // PB7 (Row 5)
    }
}

static void unselect_cols(void)
{
    DDRB |= (1<<5) | (1<<6);
    PORTB &= ~((1<<5) | (1<<6));
    
    DDRC |= (1<<6) | (1<<7);
    PORTC &= ~((1<<6) | (1<<7));

    DDRF |= (1<<0) | (1<<1);
    PORTF &= ~((1<<0) | (1<<1));
}

static void select_col(uint8_t col)
{
    switch (col) {
        case 0:
            PORTC |= (1<<6);
            break;
        case 1:
            PORTC |= (1<<6);
            PORTF |= (1<<0);
            break;
        case 2:
            PORTC |= (1<<6);
            PORTF |= (1<<1);
            break;
        case 3:
            PORTC |= (1<<6);
            PORTF |= (1<<0) | (1<<1);
            break;
        case 4:
            PORTC |= (1<<6);
            PORTC |= (1<<7);
            break;
        case 5:
            PORTC |= (1<<6);
            PORTF |= (1<<0);
            PORTC |= (1<<7);
            break;
        case 6:
                PORTC |= (1<<6);
                PORTF |= (1<<1);
                PORTC |= (1<<7);
            break;
        case 7:
                PORTC |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
                PORTC |= (1<<7);
            break;
        case 8:
                PORTB |= (1<<6);
            break;
        case 9:
                PORTB |= (1<<6);
                PORTF |= (1<<0);
            break;
        case 10:
                PORTB |= (1<<6);
                PORTF |= (1<<1);
            break;
        case 11:
                PORTB |= (1<<6);
                PORTF |= (1<<0) | (1<<1);
            break;
        case 12:
                PORTB |= (1<<6);
                PORTC |= (1<<7);
            break;
        case 13:
            PORTB |= (1<<6);
            PORTF |= (1<<0);
            PORTC |= (1<<7);
            break;
        case 15:
            PORTB |= (1<<6);
            PORTF |= (1<<1);
            PORTC |= (1<<7);
            break;
        case 16:
            PORTB |= (1<<6);
            PORTF |= (1<<0) | (1<<1);
            PORTC |= (1<<7);
            break;
        case 17:
            PORTB |= (1<<5);
            break;

    }
}