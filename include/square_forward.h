#ifndef GOP_SQUARE_FORWARD_H_
#define GOP_SQUARE_FORWARD_H_

#include "square.h"

class SquareForward : public Square
{
 public:
  SquareForward(const String& text, int steps);
  
  void Do(Gameboard& gameboard);

 private:
  int steps_;

};

#endif