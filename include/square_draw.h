#ifndef GOP_SQUARE_DRAW_H_
#define GOP_SQUARE_DRAW_H_

#include "square.h"

class SquareDraw : public Square
{
 public:
  SquareDraw(const String& text);

  void Do(Gameboard& gameboard) const;
};

#endif