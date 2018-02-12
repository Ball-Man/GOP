#include "square_back.h"
#include "gameboard.h"

#include "screen.h"

SquareBack::SquareBack(const String& text, int steps) : Square(text)
{
  steps_ = steps;
}

void SquareBack::Do(Gameboard& gameboard) const
{
  gameboard.Playing().StepBack(steps_);
  screen::Wait();

  if(gameboard.Playing().Position() <= gameboard.Squares())
  {
    screen::Out(gameboard.OnSquare().Text());
    screen::Separe();
    gameboard.OnSquare().Do(gameboard);
  }
}