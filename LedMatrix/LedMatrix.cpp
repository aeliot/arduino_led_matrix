#include "LedMatrix.h"
#include "Arduino.h"

Display::Display(int clock, int data, int latch)
{
  
  clockPin = clock;
  dataPin = data;
  latchPin = latch;

  offset = 0;

  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  clear(0);
  clear(1);
}

void Display::print()
{
  int k;
  int i;
  int j;

  byte data;

  for(k = 0; k < 8; k++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, (1 << k));
    for (i = 0; i < 2; i++){
      data = ((imageArray[0][i][k] << offset) |
	      (imageArray[1][i][k] >> (8 - offset)));
      shiftOut(dataPin, clockPin, MSBFIRST, data);
    }
    digitalWrite(latchPin, HIGH);
  }
}

void Display::clear(int frame){
  int k;
  int i;

  for(k = 0; k < 8; k++){
    for(i = 0; i < 2; i++){
      imageArray[frame][i][k] = 0;
    }
  }
}

void Display::setChar(char dispChar, int frame, Color color){
  clear(frame);

  int layer;

  if(color == Display::GREEN){
    layer = 0;
  }
  else if(color == Display::RED){
    layer = 1;
  }
  else{
    setChar(dispChar, frame, Display::GREEN);
    layer = 1;
  }

  switch(dispChar){
  case 'A':
    imageArray[frame][layer][0] = 0x30;
    imageArray[frame][layer][1] = 0x78;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xfc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'B':
    imageArray[frame][layer][0] = 0xf8;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xf8;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0xf8;
    break;
  case 'C':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0xc0;
    imageArray[frame][layer][4] = 0xc0;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'D':
    imageArray[frame][layer][0] = 0xf0;
    imageArray[frame][layer][1] = 0xd8;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xcc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xd8;
    imageArray[frame][layer][6] = 0xf0;
    break;
  case 'E':
    imageArray[frame][layer][0] = 0xfc;
    imageArray[frame][layer][1] = 0xc0;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0xf0;
    imageArray[frame][layer][4] = 0xc0;
    imageArray[frame][layer][5] = 0xc0;
    imageArray[frame][layer][6] = 0xfc;
    break;
  case 'F':
    imageArray[frame][layer][0] = 0xfc;
    imageArray[frame][layer][1] = 0xc0;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0xf0;
    imageArray[frame][layer][4] = 0xc0;
    imageArray[frame][layer][5] = 0xc0;
    imageArray[frame][layer][6] = 0xc0;
    break;
  case 'G':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0xdc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'H':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xfc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'I':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0x30;
    imageArray[frame][layer][2] = 0x30;
    imageArray[frame][layer][3] = 0x30;
    imageArray[frame][layer][4] = 0x30;
    imageArray[frame][layer][5] = 0x30;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'J':
    imageArray[frame][layer][0] = 0x3c;
    imageArray[frame][layer][1] = 0x18;
    imageArray[frame][layer][2] = 0x18;
    imageArray[frame][layer][3] = 0x18;
    imageArray[frame][layer][4] = 0x18;
    imageArray[frame][layer][5] = 0xd8;
    imageArray[frame][layer][6] = 0x70;
    break;
  case 'K':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xd8;
    imageArray[frame][layer][2] = 0xf0;
    imageArray[frame][layer][3] = 0xe0;
    imageArray[frame][layer][4] = 0xf0;
    imageArray[frame][layer][5] = 0xd8;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'L':
    imageArray[frame][layer][0] = 0xc0;
    imageArray[frame][layer][1] = 0xc0;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0xc0;
    imageArray[frame][layer][4] = 0xc0;
    imageArray[frame][layer][5] = 0xc0;
    imageArray[frame][layer][6] = 0xfc;
    break;
  case 'M':
    imageArray[frame][layer][0] = 0xc6;
    imageArray[frame][layer][1] = 0xee;
    imageArray[frame][layer][2] = 0xfe;
    imageArray[frame][layer][3] = 0xd6;
    imageArray[frame][layer][4] = 0xc6;
    imageArray[frame][layer][5] = 0xc6;
    imageArray[frame][layer][6] = 0xc6;
    break;
  case 'N':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xec;
    imageArray[frame][layer][2] = 0xfc;
    imageArray[frame][layer][3] = 0xfc;
    imageArray[frame][layer][4] = 0xdc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'O':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xcc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'P':
    imageArray[frame][layer][0] = 0xf8;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xf8;
    imageArray[frame][layer][4] = 0xc0;
    imageArray[frame][layer][5] = 0xc0;
    imageArray[frame][layer][6] = 0xc0;
    break;
  case 'Q':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xcc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0x78;
    imageArray[frame][layer][6] = 0x0c;
    break;
  case 'R':
    imageArray[frame][layer][0] = 0xf8;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xf8;
    imageArray[frame][layer][4] = 0xf0;
    imageArray[frame][layer][5] = 0xd8;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'S':
    imageArray[frame][layer][0] = 0x78;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xc0;
    imageArray[frame][layer][3] = 0x78;
    imageArray[frame][layer][4] = 0x0c;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'T':
    imageArray[frame][layer][0] = 0xfc;
    imageArray[frame][layer][1] = 0x30;
    imageArray[frame][layer][2] = 0x30;
    imageArray[frame][layer][3] = 0x30;
    imageArray[frame][layer][4] = 0x30;
    imageArray[frame][layer][5] = 0x30;
    imageArray[frame][layer][6] = 0x30;
    break;
  case 'U':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xcc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0x78;
    break;
  case 'V':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0xcc;
    imageArray[frame][layer][4] = 0xcc;
    imageArray[frame][layer][5] = 0x78;
    imageArray[frame][layer][6] = 0x30;
    break;
  case 'W':
    imageArray[frame][layer][0] = 0xc6;
    imageArray[frame][layer][1] = 0xc6;
    imageArray[frame][layer][2] = 0xc6;
    imageArray[frame][layer][3] = 0xd6;
    imageArray[frame][layer][4] = 0xfe;
    imageArray[frame][layer][5] = 0xde;
    imageArray[frame][layer][6] = 0xc6;
    break;
  case 'X':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0x78;
    imageArray[frame][layer][3] = 0x30;
    imageArray[frame][layer][4] = 0x78;
    imageArray[frame][layer][5] = 0xcc;
    imageArray[frame][layer][6] = 0xcc;
    break;
  case 'Y':
    imageArray[frame][layer][0] = 0xcc;
    imageArray[frame][layer][1] = 0xcc;
    imageArray[frame][layer][2] = 0xcc;
    imageArray[frame][layer][3] = 0x78;
    imageArray[frame][layer][4] = 0x30;
    imageArray[frame][layer][5] = 0x30;
    imageArray[frame][layer][6] = 0x30;
    break;
  case 'Z':
    imageArray[frame][layer][0] = 0xfc;
    imageArray[frame][layer][1] = 0x0c;
    imageArray[frame][layer][2] = 0x18;
    imageArray[frame][layer][3] = 0x30;
    imageArray[frame][layer][4] = 0x60;
    imageArray[frame][layer][5] = 0xc0;
    imageArray[frame][layer][6] = 0xfc;
    break;
  }
}
