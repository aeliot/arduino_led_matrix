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
  byte imageArray[2][2][8];
  void clear(int frame);
  void nextFrame();
  int offset;
 private:
  int clockPin;
  int dataPin;
  int latchPin;
};


#endif
