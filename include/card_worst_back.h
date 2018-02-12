#ifndef GOP_CARD_WORST_BACK_H_
#define GOP_CARD_WORST_BACK_H_

#include "card.h"

class CardWorstBack : public Card
{
 public:
  CardWorstBack(const String& text, int steps);
  
  void Do(Gameboard& gameboard) const;

 private:
  int steps_;
};

#endif