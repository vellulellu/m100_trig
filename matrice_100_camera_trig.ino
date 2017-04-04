
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
}

void loop() {


if(digitalRead(4) ==LOW)
{
  digitalWrite(13, HIGH);
  myservo.write(90);
  delay(60000);   //wait before starting to photograph
  
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
  delay(2500);              //CHANGE THIS NUMBER TO SET PHOTO FREQUENCY IN ms
}

}
else
{
  digitalWrite(13, LOW);
myservo.write(0);
}
}

