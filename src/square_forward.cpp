#include "square_forward.h"
#include "gameboard.h"

#include "screen.h"

SquareForward::SquareForward(const String& text, int steps) : Square(text)
{
  steps_ = steps;
}

void SquareForward::Do(Gameboard& gameboard) const
{
  gameboard.Playing().StepForward(steps_);
  screen::Wait();

  if(gameboard.Playing().Position() <= gameboard.Squares())
  {
    screen::Out(gameboard.OnSquare().Text());
    screen::Separe();
    gameboard.OnSquare().Do(gameboard);
  }
}