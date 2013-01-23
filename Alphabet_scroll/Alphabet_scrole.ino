#include <LedMatrix.h>

// clock = 2
// data = 6
// latch = 4
Display leds(2, 6, 4);

void setup(){
}

int i = 0;
int k = 0;

void loop(){
  leds.setChar('A' + i, 0, Display::RED);
  leds.setChar('A' + i + 1, 1, Display::RED);	
  leds.print();
  
  if('A' + i == 'Z'){
    i = 0;
    leds.offset = 0;
    k = 0;
  }
  else if(k == 50) {
    if(leds.offset==8){
      leds.offset = 0;
      i++;
    }
    leds.offset++;
    k=0;
  }
  else {
    k++;
  }
}
