#include <Servo.h>
#define Spoint 90
#define left 130
#define right 50
#define ESC 3
#define ENA 5
#define ENB 6

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11



#define Speed 180

Servo servo;
void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(Spoint);
  pinMode(ESC, OUTPUT);
   pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
}

void loop() {
    if (Serial.available() > 0) {
      char value = Serial.read();
  
      if (value == 'L') {
        servo.write(left);
        delay(10);
      } else if (value == 'R') {
        servo.write(right);
        delay(10);
       } else if (value == 'U') {
        analogWrite(ESC, 120);
        delay(10);
      } else if (value == 'D') {
        analogWrite(ESC, 250);
        delay(10);
      } else if (value == 'S') {
        servo.write(Spoint);
        analogWrite(ESC, 187);
        delay(10);
      }
    }
 if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.println(value);

    if (value == 'U') {
      Forward();
    } else if (value == 'D') {
      Backward();
    } else if (value == 'S') {
      Stop();
    } else if (value == 'L') {
      Left();
    } else if (value == 'R') {
      Right();
    }
  }
}





/*modified Bluetooth control car with Arduino Nano
   Home Page
*/





void Forward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Backward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Left() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}