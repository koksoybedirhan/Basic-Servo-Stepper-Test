const int dirPin = 3;
const int stepPin = 4;
long rastgele;
char value = ',';
int x, y;

void durdurma(){
  int xdurdurma = 0;
  
}
void setup()
{
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{
  while(Serial.available() > 0)
  {
    rastgele = Serial.parseInt();
    String a = Serial.readStringUntil(',');

    Serial.print(rastgele); 
    Serial.println(a);

    if(rastgele == 1){
      digitalWrite(dirPin, HIGH);
      for(x = 0; x < 18; x++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
      delay(200);
      digitalWrite(dirPin, LOW);
          for(y = 0; y < 18; y++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
       } 
      delay(1000);
    }
   
    if(rastgele == 2){
      digitalWrite(dirPin, LOW);
      for(x = 0; x < 18; x++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
      delay(200);
      digitalWrite(dirPin, HIGH);
          for(y = 0; y < 18; y++) 
          {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(2000);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(2000);
          }
       delay(1000);
       } 
}
