#include "card_everyone_to_zero.h"
#include "gameboard.h"

#include "screen.h"

CardEveryoneToZero::CardEveryoneToZero(const String& text) : Card(text) { }

void CardEveryoneToZero::Do(Gameboard& gameboard) const
{
  for(int i = 0; i < gameboard.Players().Length(); i++)
    gameboard.Players()[i].SetCoins(0);

  screen::Wait();
}