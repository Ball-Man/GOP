#ifndef GOP_CARD_COINS_H_
#define GOP_CARD_COINS_H_

#include "card.h"

class CardCoins : public Card
{
 public:
  CardCoins(const String& text, int coins);
  
  void Do(Gameboard& gameboard) const;

 private:
  int coins_; 
};

#endif