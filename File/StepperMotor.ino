#include <SoftwareSerial.h>

SoftwareSerial StepMotor(0,1);
SoftwareSerial ServoMotor(10,11);

const int dirPin = 3;
const int stepPin = 4;
const int ServoKesmePin = 6;
long rastgele;
char value = ',';
int x, y, b, c, d;
int servoA, servoB;

void setup()
{
  Serial.begin(9600);
  StepMotor.begin(9600);
  ServoMotor.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ServoKesmePin, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(8), kesme, FALLING);
}
void loop()
{
  StepMotor.listen();
  while(Serial.available() > 0)
  {
    rastgele = Serial.parseInt();
    String a = Serial.readStringUntil(',');

    Serial.print(rastgele); 
    Serial.println(a);

    if(rastgele == 1){
      digitalWrite(dirPin, HIGH);
      for(x = 0; x < 90; x++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
      delay(200);
      digitalWrite(dirPin, LOW);
          for(y = 90; y > 72; y--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, LOW);
          for(d = 72; d > 54; d--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, LOW);
          for(b = 54; b > 36; b--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, LOW);
          for(c = 36; c > 18; c--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, LOW);
          for(c = 18; c > 0; c--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
    }
   
    if(rastgele == 2){
      digitalWrite(dirPin, LOW);
      for(x = 0; x < 90; x++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(y = 90; y > 72; y--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(d = 72; d > 54; d--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(b = 54; b > 36; b--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(c = 36; c > 18; c--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(c = 18; c > 0; c--) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          } 
      delay(200);
    }
  }
}

void kesme(){
  ServoMotor.listen();
  if(Serial.read()==3){
    digitalWrite(6,!digitalRead(6));
  }
}
