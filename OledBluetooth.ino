/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//OLED GND – Arduino GND
//OLED VCC – Arduino 5V
//OLED SCL – Arduino Uno A5
//OLED SDA – Arduino Uno A4
void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
//    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(500);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  // Display static text
  display.print("Init...");
  display.display();
  Serial.println("AT+NAMEJazComBT01");
//	Serial.println("AT+HELP");
}

#define STR_LENGTH 255
char incoming[STR_LENGTH + 1];
char current = '\0';
void loop() {
  if (Serial.available()) {
		int length = Serial.readBytesUntil('\n', incoming, STR_LENGTH);
  	incoming[length] = '\0';
  	while (length >= 0 && incoming[length - 1] == '\r') {
  		incoming[length - 1] = '\0';
  		length--;
  	}
  	if (length > 0) {
			display.clearDisplay();
		  if (length > 3) {
		  	display.setTextSize(3);
		  } else {
		  	display.setTextSize(6);
		  }
		  display.setCursor(5, 20);
		  if (length == 2) {
		  	display.print(" ");
		  }
		  display.println(incoming);
		  display.display();
  	}
	}
}
