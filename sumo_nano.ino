// Khai báo các chân kết nối giữa L298N và Arduino Nano
#include "Motor.h"
#include "LineSensor.h"
#include "DetectSensor.h"

#define FRONT_SENSOR 3
#define BACK_SENSOR 4
LineSensor lineSensor;

void setup() {

    Serial.begin(9600);
    
    pinMode(FRONT_SENSOR, INPUT);
    pinMode(BACK_SENSOR, INPUT);
}

void loop() {
    Serial.println("**********");
    lineSensor.setValue(digitalRead(FRONT_SENSOR));
    Serial.println(lineSensor.getValue());
    lineSensor.setValue(digitalRead(BACK_SENSOR));
    Serial.println(lineSensor.getValue());
    Serial.println("**********");
    delay(1000);
}
