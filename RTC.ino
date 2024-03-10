#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  Wire.begin();

  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

  lcd.init();
  lcd.backlight();

}

void loop() {

  lcd.clear();

  DateTime now = rtc.now();

  lcd.setCursor(0, 0);
  lcd.print("Tgl : ");
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  lcd.setCursor(0, 1);
  lcd.print("Jam : ");
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());

  delay(1000);
}