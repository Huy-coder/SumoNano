#include "Motor.h"
#include "LineSensor.h"
#include "DetectSensor.h"
#include <SharpIR.h>

//Read digital value
#define FRONT_SENSOR 3
#define BACK_SENSOR 4

//Read analog value
#define BACKWARD_SENSOR A1
#define LEFT_SENSOR A2
#define RIGHT_SENSOR A3

//Model IR Sensor
#define MODEL 1080

SharpIR Backward_IR = SharpIR(BACKWARD_SENSOR, MODEL);
SharpIR Left_IR = SharpIR(LEFT_SENSOR, MODEL);
SharpIR Right_IR = SharpIR(RIGHT_SENSOR, MODEL);

DetectSensor detectSensor;
LineSensor lineSensor;


void setup() {

    Serial.begin(9600);
    
    pinMode(FRONT_SENSOR, INPUT);
    pinMode(BACK_SENSOR, INPUT);
}

void loop() {

    Serial.print("Cam bien sau lung: ");
    Serial.println(Backward_IR.distance());
    Serial.print("Cam bien ben trai: ");
    Serial.println(Left_IR.distance());
    Serial.print("Cam bien ben phai: ");
    Serial.println(Right_IR.distance());
    Serial.print("Cam bien do line phia truoc: ");
    Serial.println(digitalRead(FRONT_SENSOR));
    Serial.print("Cam bien do line phia sau: ");
    Serial.println(digitalRead(BACK_SENSOR));
    delay(1000);
}
