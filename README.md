# tau
uC driven audio preamplifier written in c++ using digital pot. Please observe that this project in in early stages of development.

# functionality
- volume control in 99 steps (under the hood translated to 255 levels used by digital pots) using encoder
- mute
- remote controller (RC5)
- EEPROM external memory accessed with wear leveling
- 4 input channel selector

# hardware
- Arduino Micro (Atmega 328). In future it may be changed to barebone avr platform without arduino library. 
- 24c04 EEPROM
- 4 buttons for channel selector + 1 button for mute
- encoder
- 5 LED for channel selection + mute indication
- 2x LED matrix presenting volume level
- tsop 1736 IR receiver
- separate 4 channel input selector driven with I2C
- MCP23017 as input (buttons, encoder) + output (led)  expander driven with I2C
- serial port output for debugging.
- digital potentiometer WM8816 / MAS6116AA1SA308 or PGA2320

# firmware
Firmware is based on Arduino platform. Modularized with C++ classes.


