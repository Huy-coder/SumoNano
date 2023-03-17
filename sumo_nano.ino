#include <SharpIR.h>

//Read digital value
#define LEFT_DETECT_LINE_SENSOR 5
#define RIGHT_DETECT_LINE_SENSOR 4
#define BACK_DETECT_LINE_SENSOR 3

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
    pinMode(LEFT_DETECT_LINE_SENSOR, INPUT);
    pinMode(RIGHT_DETECT_LINE_SENSOR, INPUT);       
    pinMode(BACK_DETECT_LINE_SENSOR, INPUT);    
    
    delay(2000);
}

void loop() 
{
    // Serial.print("Cam bien sau lung: ");
    // Serial.println(Backward_IR.distance());
    // Serial.print("Cam bien ben trai: ");
    // Serial.println(Left_IR.distance());
    // Serial.print("Cam bien ben phai: ");
    // Serial.println(Right_IR.distance());
    
    // while(digitalRead(RIGHT_DETECT_LINE_SENSOR) == 0 && digitalRead(LEFT_DETECT_LINE_SENSOR) == 0 && digitalRead(BACK_DETECT_LINE_SENSOR) == 0)
    // {
    //     //findEnemy();
    // }
    avoidToDropOut();
    // delay(1500);
}

void runForward()
{
    
    analogWrite(EN_A, 80);
    analogWrite(EN_B, 80);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void runBackward()
{
    analogWrite(EN_A, 80);
    analogWrite(EN_B, 80);
    digitalWrite(IN_1, 0);
    digitalWrite(IN_2, 1);
    digitalWrite(IN_3, 1);
    digitalWrite(IN_4, 0);
}

void runLeft()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 150);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 1);
    digitalWrite(IN_4, 0);
}

void runRight()
{
    analogWrite(EN_A, 150);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 0);
    digitalWrite(IN_2, 1);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void runBackLeft()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void runBackRight()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void round360()
{
    analogWrite(EN_A, 150);
    analogWrite(EN_B, 0);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);  
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

void attackEnemy()
{
    analogWrite(EN_A, 255);
    analogWrite(EN_B, 255);
    digitalWrite(IN_1, 1);
    digitalWrite(IN_2, 0);
    digitalWrite(IN_3, 0);
    digitalWrite(IN_4, 1);
}

void findEnemy()
{
    if(Left_IR.distance() <= 10 || Right_IR.distance() <= 10)
    {
        attackEnemy();
        delay(500);
        stopMotor();
        delay(100);
        runBackward();
        delay(500);
    }
    else if (Backward_IR.distance() <= 30)
    {
        round360();
        delay(500);
        attackEnemy();
        delay(500);
        stopMotor();
        delay(100);
        runBackward();
        delay(500);        
    }
    else
    {
        if(digitalRead(RIGHT_DETECT_LINE_SENSOR) == 1 || digitalRead(LEFT_DETECT_LINE_SENSOR) == 1)
        {
            runBackward();
            delay(500);        
        }
        else if(digitalRead(BACK_DETECT_LINE_SENSOR) == 1)
        {
            runForward();
            delay(500);
        }
        else
        {
            runForward();
            delay(500);            
            round360();
            delay(500);
            runBackward();
            delay(500);
            round360();
            delay(500); 
        }
    }
}

void avoidToDropOut()
{
    if(digitalRead(RIGHT_DETECT_LINE_SENSOR) == 1 || digitalRead(LEFT_DETECT_LINE_SENSOR) == 1)
    {
        runBackward();
        delay(500);
    }
        
    else if(digitalRead(BACK_DETECT_LINE_SENSOR) == 1)
    {
        runForward();
        delay(200);
    }
    stopMotor();
    delay(100);
}

void firstStart()
{
    
}