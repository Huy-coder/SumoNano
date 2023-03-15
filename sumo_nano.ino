// Khai báo các chân kết nối giữa L298N và Arduino Nano

int value1, value2;

void setup() {

    Serial.begin(9600);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
}

void loop() {
    value1 = digitalRead(3);
    Serial.println(value1);
    Serial.println("**********");
    value2 = digitalRead(4);
    Serial.println(value2);
    delay(1000);
}
