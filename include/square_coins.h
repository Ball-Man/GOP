#ifndef GOP_SQUARE_COINS_H_
#define GOP_SQUARE_COINS_H_

#include "square.h"

class SquareCoins : public Square
{
 public:
  SquareCoins(const String& text, int coins);
  
  void Do(Gameboard& gameboard) const;

 private:
  int coins_;

};

#endif