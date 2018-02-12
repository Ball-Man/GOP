#include "square_coins.h"
#include "gameboard.h"

#include "screen.h"

SquareCoins::SquareCoins(const String& text, int coins) : Square(text)
{
  coins_ = coins;
}

void SquareCoins::Do(Gameboard& gameboard) const
{
  gameboard.Playing().AddCoins(coins_);
  screen::Wait();
}