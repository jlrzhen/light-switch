#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int upper = 140;
int lower = 90;
int mid = (upper+lower)/2;

void setup() {
  myservo.attach(8);  // attaches the servo on pin 8 to the servo object
  resetServo();
  Serial.begin(9600);
}

void lightOn() {
  for (pos = mid; pos <= upper; pos += 1) {
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void lightOff() {
  for (pos = mid; pos >= lower; pos -= 1) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void resetServo() {
  if(pos > mid) {
    for (pos = upper; pos >= mid; pos -= 1) {
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println(pos);
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  } else {
    for (pos = lower; pos <= mid; pos += 1) {
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println(pos);
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
}

void loop() {
  if (Serial.available()>0){
    char input = Serial.read();
    // y -> light on
    if (input == 'y'){
      lightOn(); 
      resetServo();
    }
    // n -> light off
    if (input == 'n'){
      lightOff();
      resetServo();
    }
  }
}
