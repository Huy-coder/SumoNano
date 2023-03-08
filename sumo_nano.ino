// Khai báo các chân kết nối giữa L298N và Arduino Nano
const int enA = 9;
const int in1 = 8;
const int in2 = 7;

const int enB = 12;
const int in3 = 10;
const int in4 = 11;

void setup() {
  // Các chân được sử dụng là đầu ra
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Bật đầu ra PWM trên chân enA
  analogWrite(enA, 256);
  analogWrite(enB, 256);
}

void loop() {
  // Quay về phía trước
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);

  // Dừng lại
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);

  // Quay về phía sau
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

  // Dừng lại
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}
