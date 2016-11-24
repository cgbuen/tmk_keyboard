#ifndef PS2AVRGB_AVR_H
#define PS2AVRGB_AVR_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


// Timer resolution check
#if (1000000/TIMER_RAW_FREQ > 20)
#   error "Timer resolution(>20us) is not enough for ps2avrGB matrix scan tweak on V-USB."
#endif

#endif
