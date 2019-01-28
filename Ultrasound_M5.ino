// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <M5Stack.h>

#define TRIGGER_PIN  2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5// Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  M5.begin();// Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  M5.update();
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  M5.Lcd.print("Ping: ");
  M5.Lcd.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  M5.Lcd.print("cm");
  M5.Lcd.setCursor(0, 25, 4);
  M5.Lcd.print("It works!!!");
  M5.Lcd.setCursor(0, 0, 4);
 
}
