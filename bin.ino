#include <Servo.h>
#include <NewPing.h>
#define TRIGGER_PIN  A0
#define ECHO_PIN     A1
#define MAX_DISTANCE 20
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;
int State = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(A4);
  myservo.write(160);
  delay(5000);
  myservo.write(0);
}
void loop() {
  int Sr = sonar.ping_cm();
  Serial.println(State);
  if (State == 0) {
    if (Sr <= 5) {
      myservo.write(0);
      delay(100);
    }
    else if (Sr >= 6) {
      myservo.write(160);
      State = 1;
    }
  }
  if (State == 1) {
    delay(3000);
    State = 0;
  }
}