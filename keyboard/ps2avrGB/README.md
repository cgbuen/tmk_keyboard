ps2avrGB keyboard firmware
==========================

This is a TMK firmware for the ps2avrGB boards sold by
[Winkeyless](http://winkeyless.kr/product/ps2avrgb-parts/). Note that this
is a complete replacement for the firmware, so you won't be using
Bootmapper Client to change the keyboard settings.

## Supported Boards

Only the [B.mini X2](http://winkeyless.kr/product/b-mini-x2-pcb/) has been
tested so far. But other ps2avrGB boards should work.

## Installing

First, install the requirements (these are for OSX):

```
$ brew cask install crosspack-avr
$ brew install --HEAD https://raw.githubusercontent.com/robertgzr/homebrew-tap/master/bootloadhid.rb
```

In order to use the `./program` script, which can reboot the board into
the bootloader, you'll need Python 2 with PyUSB installed:

```
$ pip install pyusb
```

Then, with the keyboard plugged in, simply run:

```
$ make program
```

If you prefer, you can just build it and flash the firmware directly with
`bootloadHID` if you boot the board while holding down `L_Ctrl` to keep it
in the bootloader:

```
$ make
$ bootloadHID -r ps2avrGB_vusb.hex
```

## Troubleshooting

From my experience, it's really hard to brick these boards. But these
tricks have been useful when it got stuck in a weird scenario.

1. Try plugging the board in while pressing `L_Ctrl`. This will force it
   to boot only the bootloader without loading the firmware. Once this is
   done, just reflash the board with the original firmware.
2. Sometimes USB hubs can act weird, so try connecting the board directly
   to your computer or plugging/unplugging the USB hub.

## TODO

* Add support for controlling backlight
