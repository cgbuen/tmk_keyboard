#
# Makefile for V-USB
#


# Target file name (without extension).
TARGET = ps2avrGB_vusb

# Directory common source filess exist
TMK_DIR = ../../tmk_core

# Directory keyboard dependent files exist
TARGET_DIR = .

# keyboard dependent files
SRC =	\
	keymap_ps2avrGB.c \
	matrix.c \
	led.c

CONFIG_H = config_vusb.h


# V-USB debug level: To use ps2_usart.c level must be 0
# ps2_usart.c requires USART to receive PS/2 signal.
OPT_DEFS = -DDEBUG_LEVEL=0
OPT_DEFS += -DBOOTLOADER_SIZE=2048


# MCU name, you MUST set this to match the board you are using
# type "make clean" after changing this, so all files will be rebuilt
MCU = atmega32a
AVRDUDE_MCU = $(MCU)
# disable UART since atmega32a apparently doesn't have it
NO_UART = 1
# this simplifies things for now
NO_SUSPEND_POWER_DOWN = 1


# Processor frequency.
#   Normally the first thing your program should do is set the clock prescaler,
#   so your program will run at the correct speed.  You should also set this
#   variable to same clock speed.  The _delay_ms() macro uses this, and many
#   examples use this variable to calculate timings.  Do not add a "UL" here.
F_CPU = 12000000


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
NKRO_ENABLE = yes	# USB Nkey Rollover



#---------------- Programming Options --------------------------
PROGRAM_CMD = ./program $(TARGET).hex



# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/vusb.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk

debug-on: EXTRAFLAGS += -DDEBUG
debug-on: all
