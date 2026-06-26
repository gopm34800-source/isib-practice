// куда подключены провода
#define red 9
#define green 5
#define sensor A0

bool open=false;

void setup() {
  // Настраиваем пины светодиодов на выдачу сигнала
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  // запуск порта для текста
  Serial.begin(115200); 

  //с самого начала горит красный
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  Serial.println("дверь закрыта");
}

void loop() {
  // Читаем датчик освященности
  int val=analogRead(sensor);

  // Если темно (подошел человек)
  if (val>512) {
    if (open==false) {             
      digitalWrite(red,LOW);        // красный выкл
      digitalWrite(green,HIGH);     // зеленый вкл
      Serial.println("дверь открывается");
      open=true;
      delay(3000);
    }
  } 
  // Если светло (никого нет)
  else {
    if (open==true) {
      digitalWrite(green,LOW);      // зеленый выкл
      digitalWrite(red,HIGH);       // красный вкл
      Serial.println("дверь закрывается");
      open=false;
    }
  }
  
  delay(100);
}