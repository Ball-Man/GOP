#ifndef GOP_SQUARE_BACK_H_
#define GOP_SQUARE_BACK_H_

#include "square.h"

class SquareBack : public Square
{
 public:
  SquareBack(const String& text, int steps);
  
  void Do(Gameboard& gameboard);

 private:
  int steps_;

};

#endif