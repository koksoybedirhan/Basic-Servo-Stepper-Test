#include <Servo.h>
Servo servoM;
int pos = 0;
int a = 45;

int sonuc;
char value = ',';

void setup() {
  Serial.begin(9600);
  servoM.attach(9);
  servoM.write(a);
}
void loop() {
  while(Serial.available() > 0)
  {
    sonuc = Serial.parseInt();
    String x = Serial.readStringUntil(',');

    Serial.println(sonuc); 
    Serial.println(x);

    if(sonuc == 1){      
      for (pos = 45; pos >= 0; pos -= 1) { 
        servoM.write(pos);             
        delay(15); 
      }    
      delay(500);
      for(pos = 0; pos <= 45; pos += 1) {
        servoM.write(pos);           
        delay(15);                     
      }
      
    }
    if(sonuc == 2){
      for(pos = 45; pos <= 90; pos += 1) {
        servoM.write(pos);           
        delay(15);                     
      } 
      delay(500);       
      for (pos = 90; pos >= 45; pos -= 1) { 
        servoM.write(pos);             
        delay(15); 
      }                    
    }
  }
}
