//Read digital value
#define LEFT_DETECT_LINE_SENSOR 5
#define RIGHT_DETECT_LINE_SENSOR 4
#define BACK_DETECT_LINE_SENSOR 3

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

unsigned long time;

void setup() {
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
  time = millis();
}

void loop() {
  checkSensor();
}

void runForward() {
  analogWrite(EN_A, 80);
  analogWrite(EN_B, 80);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void runBackward() {
  analogWrite(EN_A, 80);
  analogWrite(EN_B, 80);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
}

void runLeft() {
  analogWrite(EN_A, 255);
  analogWrite(EN_B, 150);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 1);
  digitalWrite(IN_4, 0);
}

void runRight() {
  analogWrite(EN_A, 150);
  analogWrite(EN_B, 255);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 1);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void runBackLeft() {
  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void runBackRight() {
  analogWrite(EN_A, 255);
  analogWrite(EN_B, 255);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void round360() {
  analogWrite(EN_A, 150);
  analogWrite(EN_B, 0);
  digitalWrite(IN_1, 1);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 1);
}

void stopMotor() {
  analogWrite(EN_A, 0);
  analogWrite(EN_B, 0);
  digitalWrite(IN_1, 0);
  digitalWrite(IN_2, 0);
  digitalWrite(IN_3, 0);
  digitalWrite(IN_4, 0);
}

void checkSensor() {
  boolean rightSensor = digitalRead(RIGHT_DETECT_LINE_SENSOR);
  boolean leftSensor = digitalRead(LEFT_DETECT_LINE_SENSOR);
  boolean backSensor = digitalRead(BACK_DETECT_LINE_SENSOR);
  if (rightSensor == 1 || leftSensor == 1 || backSensor == 1) {
    if (rightSensor) {
      runBackward();
      delay(500);
      runLeft();
      delay(500);
    } else if (leftSensor) {
      runBackward();
      delay(500);
      runRight();
      delay(500);
    } else if (rightSensor && leftSensor) {
      runBackward();
      delay(500);
    } else if (backSensor) {
      runForward();
      delay(500);
    }
  } else {
    randomMove();
  }
}

void randomMove() {
  int randNumber = random(1, 5);
  switch (randNumber) {
    case 1:
      runForward();
      delay(500);
      break;
    case 2:
      runLeft();
      delay(500);
      break;
    case 3:
      runRight();
      delay(500);
      break;
    case 4:
      runBackward();
      delay(500);
      break;
    case 5:
      round360();
      delay(500);
      break;
    default:
      delay(500);
      stopMotor();
      break;
  }
}
