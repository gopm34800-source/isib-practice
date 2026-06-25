#include <Adafruit_NeoPixel.h>

#define pin 3
#define leds 64
#define brightness 100

Adafruit_NeoPixel line(leds, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  line.begin();
  line.setBrightness(brightness);
  line.show();
}

void loop() {
  //красная змейка
  for(int i=0;i<leds;++i) {
    line.setPixelColor(i,255,0,0);
    line.show();                    
    delay(70);                      
  }

  //  все зеленое
  for(int i=0;i<leds;++i) {
    line.setPixelColor(i,0,255,0);
  }
  line.show();
  delay(1000);

  line.clear();
  line.show();
  delay(500);
}