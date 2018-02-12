#include "square_reroll.h"
#include "gameboard.h"

#include "screen.h"
#include "random.h"

SquareReroll::SquareReroll(const String& text) : Square(text) { }

void SquareReroll::Do(Gameboard& gameboard) const
{
  int die = rnd::RandInt(1, 6);

  screen::Wait();
  std::cout << "You rolled " << die << "\n";
  screen::Separe();

  gameboard.Playing().StepForward(die);
  screen::Wait();

  if(gameboard.Playing().Position() <= gameboard.Squares())
  {
    screen::Out(gameboard.OnSquare().Text());
    screen::Separe();
    gameboard.OnSquare().Do(gameboard);
  }
}