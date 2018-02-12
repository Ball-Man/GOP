#ifndef GOP_SQUARE_REROLL_H_
#define GOP_SQUARE_REROLL_H_

#include "square.h"

class SquareReroll : public Square
{
 public:
  SquareReroll(const String& text);
  
  void Do(Gameboard& gameboard);
};

#endif