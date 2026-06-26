#include <Servo.h>

#define pin 3

Servo serv;
int corner=0;

void setup() {
  serv.attach(pin);
  serv.write(corner);
  
  Serial.begin(115200);
  Serial.setTimeout(5);
  
  Serial.println("введите угол 0-180");
}

void loop() {
  if (Serial.available()) {
    
    int target=Serial.parseInt(); 

    while(Serial.available()) {
      Serial.read();
    }
    if(target>=0&&target<=180) {
      if(target!=corner) {
        if(target>corner) {
          for(int i=corner;i<=target;++i) {
            serv.write(i);
            delay(15);
          }
        } 
        else {
          for (int i=corner;i>=target;--i) {
            serv.write(i);
            delay(15);
          }
        }
        
        corner=target;
        Serial.print("угол: ");
        Serial.println(corner);
      }
      
    } else {
      Serial.println("ошибка, введите от 0 до 180");
    }
  }
}