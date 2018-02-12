#include "card_worst_back.h"
#include "gameboard.h"

#include "screen.h"

CardWorstBack::CardWorstBack(const String& text, int steps) : Card(text)
{
  steps_ = steps;
}

void CardWorstBack::Do(Gameboard& gameboard) const
{
  int min = gameboard.Players()[0].Coins();
  for(int i = 1; i < gameboard.Players().Length(); i++)
  {
    Player& player = gameboard.Players()[i];
    if(player.Coins() < min)
      min = player.Coins();
  }

  // Check again cause ALL the worsts(on equal merit) have to go back
  for(int i = 0; i < gameboard.Players().Length(); i++)
  {
    Player& player = gameboard.Players()[i];
    if(gameboard.Players()[i].Coins() == min)
      player.StepBack(steps_);
  }


  screen::Wait();
}