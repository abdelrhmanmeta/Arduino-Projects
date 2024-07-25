#include "DHT.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(34, 4, 3, 33, 2, 32);

#define DHTPIN 2 // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
lcd.begin(16,2);
dht.begin();
}

void loop() {
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
float t = dht.readTemperature();

// check if returns are valid, if they are NaN (not a number) then something went wrong!
if (isnan(t) || isnan(h)) {
lcd.setCursor(5,1);
lcd.println("Failed to read from DHT");
} else {
lcd.setCursor(5,1);
lcd.print(h);
lcd.print(" %");
lcd.setCursor(5,0);
lcd.print(t);
lcd.print(" *C");
}
}
