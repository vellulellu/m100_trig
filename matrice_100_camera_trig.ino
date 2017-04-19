#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int inVal = analogRead(A2);
int outVal = map(inVal, 0, 1023, 400, 4000);  //set trig. freg. between 2 last values
long previousMillis = 0; 
long interval = 10000; //wait this time before starting to photograph


void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  pinMode(3, OUTPUT);
  pinMode(A2, INPUT);
}

void loop() {
  
unsigned long currentMillis = millis();
previousMillis = currentMillis;
  
while(digitalRead(4) ==LOW)
{
  unsigned long currentMillis = millis();
  digitalWrite(13, HIGH);
  myservo.write(90);

if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    

  while(digitalRead(4) == LOW)

{
  digitalWrite(13, LOW);  //turns the led off
  int inVal = analogRead(A2);            
 int outVal = map(inVal, 0, 1023, 300, 4000);  //set trig. freg. between 2 last values
  myservo.write(130);
  
  delay(outVal);

  myservo.write(90);
  digitalWrite(13, HIGH);  //turns the led on. blinks the led in same order as servo triggers
  
  delay(200);             //delay that the servo stays off the button
}
}
}
  digitalWrite(13, LOW);  //turns the led off
myservo.write(0);         //turns the servo to "unarmed" state

}
