#include <SPI.h> //i2c and the ssd1306Scherm libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"


#define SCREEN_WIDTH 128 // OLED ssd1306Scherm width, in pixels
#define SCREEN_HEIGHT 32 // OLED ssd1306Scherm height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 ssd1306Scherm(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

RTC_DS3231 rtc;
char dagenVanDeWeek[7][12] = {"Zondag", "Maandag", "Dinsdag", "Woensdag", "Donderdag", "Vrijdag", "Zaterdag"};

void setup() {
  ssd1306Scherm.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  rtc.begin();
  delay(1000);
  ssd1306Scherm.clearDisplay();
  ssd1306Scherm.display();
// Onderstaande code mag maar 1 keer uitgevoerd worden. Daarna moet het programma opnieuw ge-upload worden met deze code gedeactiveerd (met de // ervoor)
// rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
// rtc.adjust(DateTime(2021, 3, 22, 10, 42, 0));
}

void loop() {
    DateTime now = rtc.now();

    ssd1306Scherm.setCursor(0, 0);
    ssd1306Scherm.setRotation(2);
    ssd1306Scherm.clearDisplay();

    ////////////////////////////////////////// Toon dag van de week ////////////////
    ssd1306Scherm.setTextSize(1);
    ssd1306Scherm.setTextColor(WHITE);
    ssd1306Scherm.setCursor(2, 1);
    ssd1306Scherm.print(dagenVanDeWeek[now.dayOfTheWeek()]);

    ////////////////////////////////////////// Toon datum ///////////////////////////
    ssd1306Scherm.setTextSize(1);
    ssd1306Scherm.setTextColor(WHITE);
    ssd1306Scherm.setCursor(60, 1);
    ssd1306Scherm.print(now.day(), DEC);
    ssd1306Scherm.print("/");
    ssd1306Scherm.print(now.month(), DEC);

    ////////////////////////////////////////// Toon tijd ///////////////////////////
    ssd1306Scherm.setTextSize(2);
    ssd1306Scherm.setTextColor(WHITE);
    ssd1306Scherm.setCursor(17, 11);
    ssd1306Scherm.print(now.hour(), DEC);
    ssd1306Scherm.print(":");
    ssd1306Scherm.print(now.minute(), DEC);
    ssd1306Scherm.print(":");
    ssd1306Scherm.print(now.second(), DEC);
    ssd1306Scherm.display();

    delay(100);
}
