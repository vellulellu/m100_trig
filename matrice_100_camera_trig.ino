
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

int inVal = analogRead(A1);
int outVal = map(inVal, 0, 1023, 400, 5000);  //set trig. freg. between 2 last values
long previousMillis = 0; 
long interval = 10000; //wait this time before starting to photograph
void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  pinMode(3, OUTPUT);
  pinMode(A1, INPUT);
}

void loop() {
  
unsigned long currentMillis = millis();

  
if(digitalRead(4) ==LOW)
{
  
  digitalWrite(13, HIGH);
  myservo.write(90);

if(currentMillis - previousMillis > interval) {
    //Save the last time someone used interval 
    previousMillis = currentMillis;   

  while(digitalRead(4) == LOW)

{
  for (pos = 150; pos <= 0; pos += 4) { // first "pos" determines start and second end position. last pos is speed of movement 
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 100; pos -= 4) { // goes from first end pos to start pos
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(outVal);              //CHANGE THIS NUMBER TO SET PHOTO FREQUENCY IN ms
}
}
}
  digitalWrite(13, LOW);
myservo.write(0);
}

