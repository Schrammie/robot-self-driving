/*
code makes a robot move forward for 1 second
*/
#include <Servo.h>
#define trigPin 4
#define echoPin 3
#define servocon 9
#define LMF 10
#define LMR 11
#define RMF 6
#define RMR 5
#define forwardtime 1000
#define mindistance 7


Servo myservo;

int pos = 0;

int leftdis = 10;
int rightdis = 10;
long duration;       // , distance;
 long distance;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

 myservo.attach(servocon);
 
}

void loop(){
  myservo.write(65);
  moveforward();
 
  ping();
  if (distance < mindistance)
  { radar();
  }


  
}


void moveforward(){

digitalWrite(LMR, LOW);
digitalWrite(RMR,LOW);
digitalWrite(LMF, HIGH);
digitalWrite(RMF, HIGH);
delay (1000);

digitalWrite(LMF, LOW);
digitalWrite(RMF, LOW);
  
}
void radar() {
  for (pos = 0; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

ping();
rightdis = distance;
  
  for (pos = 140; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 ping ();
 leftdis = distance;

if (leftdis>rightdis)
{ Serial.println("turn left");
digitalWrite(LMR, HIGH);
digitalWrite(RMR,HIGH);
delay(1000);
digitalWrite(RMR, LOW);
delay(2000);
digitalWrite(LMR,LOW);




}
else 
{Serial.println("turn right");
digitalWrite(LMR, HIGH);
digitalWrite(RMR,HIGH);
delay(1000);
digitalWrite(LMR, LOW);
delay(2000);
digitalWrite(RMR,LOW);}
 
delay (2000);
  
}

void ping() {
  
  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
 delayMicroseconds(1000);  //Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  
    Serial.print(distance);
    Serial.println(" cm");
 
 delay(1000);
}

