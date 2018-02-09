#ifndef GOP_SQUARE_H_
#define GOP_SQUARE_H_

#include "sstring.h"

class Square
{
 public:
  Square(String& text);

  virtual void Do(/* TODO: Add Game class parameter */) = 0;

 protected:
  String text_;
};

#endif