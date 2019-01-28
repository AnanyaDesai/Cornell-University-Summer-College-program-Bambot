#include <M5Stack.h>

#include<Adafruit_MCP23008.h>
#include <BamBotMotorDriver.h>

BamBotMotorDriver motors;
Adafruit_MCP23008 mcp;

void setup() {
  // put your setup code here, to run once:
M5.begin();
mcp.begin();
//to change pins use:
motors.init(mcp, 3, 6, 1, 7 4);
}

void loop() {
  // put your main code here, to run repeatedly:
M5.update();
  delay(50);
  motors.setM1Speed(-200);
    motors.setM2Speed(-200);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Reverse");
    delay(1000);
    motors.setM1Speed(100);
    motors.setM2Speed(100);
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("Forward");
    delay(1000);
}
