#ifndef GOP_SQUARE_H_
#define GOP_SQUARE_H_

#include "sstring.h"

class Gameboard;

class Square
{
 public:
  Square(String& text);

  virtual void Do(Gameboard& gameboard) = 0;

 protected:
  String text_;
};

#endif