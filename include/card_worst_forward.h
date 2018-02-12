#ifndef GOP_CARD_WORST_FORWARD_H_
#define GOP_CARD_WORST_FORWARD_H_

#include "card.h"

class CardWorstForward : public Card
{
 public:
  CardWorstForward(const String& text, int steps);
  
  void Do(Gameboard& gameboard) const;

 private:
  int steps_;
};

#endif