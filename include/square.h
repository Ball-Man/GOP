#ifndef GOP_SQUARE_H_
#define GOP_SQUARE_H_

#include "sstring.h"

class Gameboard;

class Square
{
 public:
  Square(const String& text);

  virtual void Do(Gameboard& gameboard) const = 0;

  const String& Text() const;

 protected:
  String text_;
};

#endif