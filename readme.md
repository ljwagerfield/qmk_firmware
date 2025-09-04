# Ferris Sweep QMK Firmware Instructions

## Setup

```
git clone git@github.com:ljwagerfield/qmk_firmware.git
cd qmk_firmware
gco lawrence
brew install avr-gcc
brew install arm-none-eabi-gcc@9
BREW_PREFIX="$(brew --prefix)"
echo '' >> ~/.zshrc
echo "export PATH=\"${BREW_PREFIX}/opt/arm-none-eabi-gcc@9/bin:${BREW_PREFIX}/opt/arm-none-eabi-binutils/bin:\$PATH\"" >> ~/.zshrc
source ~/.zshrc
brew install qmk/qmk/qmk
brew install qmk-toolbox
qmk setup -H $(pwd)
qmk config user.keyboard=ferris/sweep
qmk config user.keymap=ljwagerfield
```

## Flashing

The firmware lives on each MCU.

The MCU that is plugged into the USB is where the vast majority of the code runs. The slave MCU runs a very small part of the QMK firmware.

As such, you only need to flash both sides when very low level changes to the QMK firmware are made, such as when you are upgrading QMK versions.

Thus, you only need to flash one side (the side that's plugged into USB) for the vast majority of changes you'll make to the firmware. For example, if you make changes to the keymap, or anything like that, you only need to flash the side that's connected to the USB. You don't need to unplug the TRRS. You don't need to touch any cables whatsoever.

### Initial Flashing (or QMK version updates)

1. Keep TRRS cable connected at all times.
2. Plug USB into right side.
3. Press the reset button.
4. Flash: `qmk flash`
5. Unplug USB.
6. Plug USB into left side.
7. Press the reset button.
8. Flash: `qmk flash`qwertyui
9. Done.

### Subsequent Flashing

1. Keep all cables connected.
2. Press the bootloader button on the keyboard (the one you have mapped to a specific key).
3. Flash: `qmk flash`
4. Done.

-----------------------------------------------

## IMPORTANT

NEVER touch (plug or unplug) TRRS cable while USB cable is connected.

Doing so runs a 50% chance of frying the MCUs.

-----------------------------------------------