#ifndef GOP_SQUARE_STOP_H_
#define GOP_SQUARE_STOP_H_

#include "square.h"

class SquareStop : public Square
{
 public:
  SquareStop(const String& text);

  void Do(Gameboard& gameboard) const;
};

#endif