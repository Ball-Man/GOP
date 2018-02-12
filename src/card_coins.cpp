#include "card_coins.h"
#include "gameboard.h"

#include "screen.h"

CardCoins::CardCoins(const String& text, int coins) : Card(text)
{
  coins_ = coins;
}

void CardCoins::Do(Gameboard& gameboard) const
{
  gameboard.Playing().AddCoins(coins_);
  screen::Wait();
}