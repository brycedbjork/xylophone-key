/*
Creative Embedded Systems
Motor Project
Bryce Bjork
10/31/2019

Solenoid hits a key from below when switch-like button changes state.
This is an attempt to use linear activation to create resonance in a zylophone key.

MIT License.

*/

int solenoidPin = 27;
int buttonPin = 33;
int buttonVal;

void setup() {
  pinMode(solenoidPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // init button value
  buttonVal = digitalRead(buttonPin);
  // init solenoid to down position
  digitalWrite(solenoidPin, HIGH);
}

void strike() {
  // move the solenoid to its up position and then back down
  digitalWrite(solenoidPin, LOW);
  delay(50);
  digitalWrite(solenoidPin, HIGH);
}

void loop(){
  // when the button value has changed, strike the key
  int newButtonVal = digitalRead(buttonPin);
  if (newButtonVal != buttonVal) {
   strike();
   buttonVal = newButtonVal;
   delay(1000);
  }
  
}
