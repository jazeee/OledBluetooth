== OLED Bluetooth messager

This displays messages from Bluetooth module HC06 on a 0.96" I2C display.
Arduino Nano or Uno code.

== Wiring
* OLED GND – Arduino GND
* OLED VCC – Arduino 5V
* OLED SCL – Arduino Uno A5
* OLED SDA – Arduino Uno A4

* HC06 TX - Arduino RX (Pin 0)
* HX06 RX - using voltage divider (1K, 2K) Arduino TX (Pin 1). Must feed 3.3V to HC06
* HC06 VCC - Arduino 5V
* HC06 GND - Arduino GND

Note - When programming the Arduino, must disconnect Serial Pins to HC06.

