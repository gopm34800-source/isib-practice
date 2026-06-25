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
  // 1) Красная змейка
  for(int i=0; i<leds; ++i) {
    line.setPixelColor(i, 255, 0, 0);
    line.show();                    
    delay(70);                      
  }

  // 2) Все зеленое
  for(int i=0; i<leds; ++i) {
    line.setPixelColor(i, 0, 255, 0);
  }
  line.show();
  delay(1000);

  for(long c=0;c<5*65536;c+=256) {
    for(int i=0;i<leds;++i) {
      int color=c+(i*65536L/leds);
      line.setPixelColor(i,line.gamma32(line.ColorHSV(color)));
    }
    line.show();
    delay(10); 
  }

  line.clear();
  line.show();
  delay(500);
}