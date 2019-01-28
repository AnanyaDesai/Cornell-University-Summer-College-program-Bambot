
#include <M5Stack.h>
#include <NewPing.h>
#include<Adafruit_MCP23008.h>
#include <BamBotMotorDriver.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 5
#define MAX_DISTANCE 500

BamBotMotorDriver motors;
Adafruit_MCP23008 mcp;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  M5.begin();
  mcp.begin();
  motors.init(mcp);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  delay(50);
  M5.Lcd.print("Ping:");
  M5.Lcd.print(sonar.ping_cm());
  M5.Lcd.print("cm");
  M5.Lcd.setCursor(0, 0, 4);
  if (sonar.ping_cm() == 0)
  {
    motors.setSpeeds(400, 400);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Forward");
  }
  else if (sonar.ping_cm() > 100)
  {
    motors.setSpeeds(400, 400);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Forward");
  }
  else if (sonar.ping_cm() < 100)
  {
    //M5.Speaker.beep();
    motors.setM1Speed(-400);
    motors.setM2Speed(-400);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Reverse");
    delay(1000);
    motors.setM1Speed(0);
    motors.setM2Speed(400);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Turning");
    delay(1000);
    motors.setSpeeds(400, 400);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Forward");
  }
}


