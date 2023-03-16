#include <SharpIR.h>

//Read digital value
#define FRONT_SENSOR 4
#define BACK_SENSOR 3

//Read analog value
#define BACKWARD_SENSOR A3
#define LEFT_SENSOR A1
#define RIGHT_SENSOR A2

//Model IR Sensor
#define MODEL 1080

//Motor DC
#define EN_A 6
#define IN_1 7
#define IN_2 8
#define EN_B 11
#define IN_3 9
#define IN_4 10

//Robot's Status
#define STOP 0
#define RUN 1
#define CIRCLE 2
#define ESCAPE 3

SharpIR Backward_IR = SharpIR(BACKWARD_SENSOR, MODEL);
SharpIR Left_IR = SharpIR(LEFT_SENSOR, MODEL);
SharpIR Right_IR = SharpIR(RIGHT_SENSOR, MODEL);

void setup() 
{

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

void loop() 
{
    Serial.print("Cam bien sau lung: ");
    Serial.println(Backward_IR.distance());
    Serial.print("Cam bien ben trai: ");
    Serial.println(Left_IR.distance());
    Serial.print("Cam bien ben phai: ");
    Serial.println(Right_IR.distance());
    if(digitalRead(FRONT_SENSOR) == 1)
        runBackward();
    else if(digitalRead(BACK_SENSOR) == 1)
        runForward();
    else
        stopMotor();
    delay(1000);
}

void runForward()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 0);
    digitalWrite(IN_2, 1);
    digitalWrite(IN_3, 1);
    digitalWrite(IN_4, 0);
}

void runBackward()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void runLeft()
{

}

void runRight()
{

}

void runBackLeft()
{
  
}

void runBackRight()
{

}

void stopMotor()
{
    analogWrite(EN_A, 0);
    analogWrite(EN_B, 0);
    digitalWrite(IN_1, 0);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 0);
}

void findEnemy()
{
    
}