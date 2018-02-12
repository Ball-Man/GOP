#include "card_best_forward.h"
#include "gameboard.h"

#include "screen.h"

CardBestForward::CardBestForward(const String& text, int steps) : Card(text)
{
  steps_ = steps;
}

void CardBestForward::Do(Gameboard& gameboard) const
{
  int max = gameboard.Players()[0].Coins();
  for(int i = 1; i < gameboard.Players().Length(); i++)
  {
    Player& player = gameboard.Players()[i];
    if(player.Coins() > max)
      max = player.Coins();
  }

  // Check again cause ALL the bests(on equal merit) have to go forward
  for(int i = 0; i < gameboard.Players().Length(); i++)
  {
    Player& player = gameboard.Players()[i];
    if(gameboard.Players()[i].Coins() == max)
      player.StepForward(steps_);
  }


  screen::Wait();
}