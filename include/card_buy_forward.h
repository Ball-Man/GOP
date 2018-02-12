#ifndef GOP_CARD_BUY_FORWARD_H_
#define GOP_CARD_BUY_FORWARD_H_

#include "card.h"

class CardBuyForward : public Card
{
 public:
  CardBuyForward(const String& text, int steps, int price);
  
  void Do(Gameboard& gameboard) const;

 private:
  int steps_,
      price_;
};

#endif