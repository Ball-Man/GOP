#ifndef GOP_CARD_LOSE_COINS_H_
#define GOP_CARD_LOSE_COINS_H_

#include "card.h"

class CardLoseCoins : public Card
{
 public:
  CardLoseCoins(const String& text, int coins);
  
  void Do(Gameboard& gameboard) const;

 private:
  int coins_; 
};

#endif