#ifndef GOP_CARD_BEST_FORWARD_H_
#define GOP_CARD_BEST_FORWARD_H_

#include "card.h"

class CardBestForward : public Card
{
 public:
  CardBestForward(const String& text, int steps);
  
  void Do(Gameboard& gameboard) const;

 private:
  int steps_;
};

#endif