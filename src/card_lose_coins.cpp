#include "card_lose_coins.h"
#include "gameboard.h"

#include "screen.h"

CardLoseCoins::CardLoseCoins(const String& text, int coins) : Card(text)
{
  coins_ = coins;
}

void CardLoseCoins::Do(Gameboard& gameboard) const
{
  gameboard.Playing().LoseCoins(coins_);
  screen::Wait();
}