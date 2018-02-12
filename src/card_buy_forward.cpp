#include "card_buy_forward.h"
#include "gameboard.h"

#include "screen.h"

CardBuyForward::CardBuyForward(const String& text, int steps, int price) : Card(text)
{
  steps_ = steps;
  price_ = price;
}

void CardBuyForward::Do(Gameboard& gameboard) const
{
  if(gameboard.Playing().Coins() >= price_)
    gameboard.Playing().StepForward(steps_);
  gameboard.Playing().SetCoins(0);

  screen::Wait();
}