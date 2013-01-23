#ifndef LedMatrix_h
#define LedMatrix_h

#include "Arduino.h"


class Display
{
 public:
  typedef enum Color { RED, GREEN, YELLOW };
  Display(int clock, int data, int latch);
  void print();
  void setChar(char dispChar, int frame, Color color);
  
  //imageArray[frame][color][row]
  byte imageArray[2][2][8];
  
  void clear(int frame);
  
  // offset=0, first frame
  // offset=8, second frame
  int offset;
 private:
  int clockPin;
  int dataPin;
  int latchPin;
};


#endif
