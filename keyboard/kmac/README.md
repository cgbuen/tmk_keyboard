# KMAC

Korean custom keyboards designed by Byungho Kim and the KBDMania community.

Note: this is not the official firmware.

## Support
KMAC TKL 6.25u, KMAC TKL 7u, and KMAC Happy.

## Instructions for macOS

1. Modify `keymap_[winkey|winkeyless|happy].h` to your liking.
2. Run:
    ```
    $ brew tap osx-cross/avr && brew install avr-gcc
    $ brew install dfu-programmer
    $ cd [.. wherever tmk_keyboard is ..]/tmk_keyboard/keyboard/kmac
    $ make -f Makefile.lufa clean
    $ make -f Makefile.lufa [winkey|winkeyless|happy]
    ```
3. Connect your KMAC via USB and hold the key at the typical `Caps Lock`
   position to run the bootloader.
4. While still `cd`'d into the same directory, run [presumably with a different keyboard plugged in]:
    ```
    $ dfu-programmer atmega32u4 erase --force && dfu-programmer atmega32u4 flash kmac_lufa.hex && dfu-programmer atmega32u4 reset
    ```
