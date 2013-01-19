#include <LedMatrix.h>

Display leds(2, 6, 4);

void setup(){
}

int i = 0;
int k = 0;
char Disp = 'A';

void loop(){
  leds.setChar(Disp + i, 0, Display::RED);
  if(i == 0){
    leds.setChar(Disp, 1, Display::RED);
  }
  else{
    leds.setChar(Disp + i + 1, 1, Display::RED);
  }
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
