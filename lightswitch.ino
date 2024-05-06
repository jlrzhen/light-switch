/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int upper = 140;
int lower = 90;
int mid = (upper+lower)/2;

void setup() {
  resetServo();
  Serial.begin(9600);
}

void lightOn() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  for (pos = mid; pos <= upper; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  myservo.detach();
}

void lightOff() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  for (pos = mid; pos >= lower; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  myservo.detach();
}

void resetServo() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  if(pos > mid) {
    for (pos = upper; pos >= mid; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println(pos);
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  } else {
    for (pos = lower; pos <= mid; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Serial.println(pos);
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
  }
  myservo.detach();
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
