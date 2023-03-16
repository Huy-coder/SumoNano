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

//Motor DC
#define EN_A 6
#define IN_1 7
#define IN_2 8

#define EN_B 11
#define IN_3 9
#define IN_4 10

SharpIR Backward_IR = SharpIR(BACKWARD_SENSOR, MODEL);
SharpIR Left_IR = SharpIR(LEFT_SENSOR, MODEL);
SharpIR Right_IR = SharpIR(RIGHT_SENSOR, MODEL);

DetectSensor detectSensor;
LineSensor lineSensor;


void setup() {

    Serial.begin(9600);
    pinMode(EN_A, OUTPUT);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(EN_B, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
    
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

    analogWrite(EN_A, 256);
    analogWrite(EN_B, 256);
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    delay(2000);

    analogWrite(EN_A, 100);
    analogWrite(EN_B, 100);
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    delay(2000);
}
