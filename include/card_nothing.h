#ifndef GOP_CARD_NOTHING_H_
#define GOP_CARD_NOTHING_H_

#include "card.h"

class CardNothing : public Card
{
 public:
  CardNothing(const String& text);
  
  void Do(Gameboard& gameboard);
};

#endif