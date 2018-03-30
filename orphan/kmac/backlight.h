#ifndef BACKLIGHT_H
#define BACKLIGHT_H

enum backlight_level {
    BACKLIGHT_SWITCH = 0b0000001,
    BACKLIGHT_OFF = 0b0000000,
    BACKLIGHT_PCB    = 0b0000010,
};

void backlight_init_ports(void);


void backlight_pcb_enable(void);
void backlight_pcb_disable(void);


#endif // BACKLIGHT_H
