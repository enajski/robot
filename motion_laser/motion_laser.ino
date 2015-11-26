#include <Servo.h> 

Servo servo;

int pos = 0; 
int movementDelay = 300;
int movementSteps = 16;
int calibrationTime = 10;        

boolean sensorActive = false;
boolean previousSensorState = false;

int pirPin = 4;    //the digital pin connected to the PIR sensor's output
int ledPin = 12;


// setup phase
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  for(int i = 0; i < calibrationTime; i++){
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
  delay(50);
  sensorActive = false;
  previousSensorState = false;

  myservo.attach(9);
}

// loop sequence
void loop()
{
  if(digitalRead(pirPin) == HIGH)
  {
    sensorActive = true;
    digitalWrite(ledPin, HIGH);

    for(int count = 0; count < movementSteps; count++) {
      servo.write(random(60));
      delay(movementDelay);
    }
  }
  if(digitalRead(pirPin) == LOW)
  {
    sensorActive = false;
    digitalWrite(ledPin, LOW);
  }
}




