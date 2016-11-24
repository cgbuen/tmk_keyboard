#!/usr/bin/env python
import usb

dev = usb.core.find(idVendor=0x20A0, idProduct=0x422D)
if dev is None:
    raise ValueError('Device not found')

dev.set_configuration()

request_type = usb.util.build_request_type(
        usb.util.CTRL_OUT,
        usb.util.CTRL_TYPE_CLASS,
        usb.util.CTRL_RECIPIENT_DEVICE)

USBRQ_HID_SET_REPORT = 0x09
HID_REPORT_OPTION = 0x0301

try:
    dev.ctrl_transfer(
            request_type,
            USBRQ_HID_SET_REPORT,
            HID_REPORT_OPTION,
            0,
            [0, 0, 0xFF] + [0] * 5
            )
except usb.core.USBError:
    # for some reason I keep getting USBError, but it works!
    pass
