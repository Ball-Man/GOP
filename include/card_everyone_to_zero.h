#ifndef GOP_CARD_EVERYONE_TO_ZERO_H_
#define GOP_CARD_EVERYONE_TO_ZERO_H_

#include "card.h"

class CardEveryoneToZero : public Card
{
 public:
  CardEveryoneToZero(const String& text);

  void Do(Gameboard& gameboard) const;
};

#endif